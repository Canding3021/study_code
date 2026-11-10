// 浪费时间 · 翻牌倒计时
(function () {
    const MIN_SECONDS = 1;
    const MAX_SECONDS = 23 * 3600 + 59 * 60 + 59;   // 最大 23:59:59
    const DEFAULT_SECONDS = 25 * 60;                // 直接打开页面时默认 25 分钟
    const STORAGE_KEY = 'waste-time:seconds';       // 由 index 写入的时长（秒）
    const TICK_MS = 200;   // 刷新间隔（显示精度到秒，200ms 足够跟手）
    const FLIP_MS = 620;   // 与 CSS 的 300ms + 300ms 两段翻牌动画对应，留一点缓冲

    // ---------- 读取并校验时长（sessionStorage，不走 URL） ----------
    let totalSeconds = DEFAULT_SECONDS;
    try {
        const raw = window.sessionStorage.getItem(STORAGE_KEY);
        if (raw !== null && raw.trim() !== '') {
            const parsed = Number(raw);
            if (Number.isFinite(parsed)) {
                totalSeconds = Math.trunc(parsed);
            }
        }
    } catch (error) {
        // 隐私模式等存储不可用时使用默认时长
    }
    totalSeconds = Math.min(MAX_SECONDS, Math.max(MIN_SECONDS, totalSeconds));

    // ---------- DOM ----------
    const cards = Array.from(document.querySelectorAll('.flip-card'));
    const pauseBtn = document.getElementById('pause-btn');
    const pauseLabel = document.getElementById('pause-label');
    const resetBtn = document.getElementById('reset-btn');
    const endBtn = document.getElementById('end-btn');
    const statusEl = document.getElementById('timer-status');
    const finishOverlay = document.getElementById('finish-overlay');
    const finishMessage = document.getElementById('finish-message');
    const finishHome = document.querySelector('.finish-home');

    // ---------- 状态 ----------
    let state = 'paused';   // paused | running | finished
    let remainingMs = totalSeconds * 1000;
    let deadline = 0;       // 运行中：Date.now() 抵达此时间点即归零
    let tickId = null;

    const reducedMotion = window.matchMedia('(prefers-reduced-motion: reduce)');

    // ---------- 读屏播报（只在开始/暂停/重置/结束时更新） ----------
    function announce(text) {
        if (statusEl) {
            statusEl.textContent = text;
        }
    }

    // ---------- 翻牌渲染 ----------
    // 直接把四层数字全部换成目标值，用于初始化、重置和减少动态模式
    function paintCard(card, digit) {
        if (card.flipTimer) {
            window.clearTimeout(card.flipTimer);
            card.flipTimer = null;
        }
        card.pendingDigit = null;
        card.dataset.value = digit;
        card.classList.remove('is-flipping');
        card.querySelectorAll('.flip-digit').forEach(function (el) {
            el.textContent = digit;
        });
    }

    function setCard(card, digit, animate) {
        const next = String(digit);

        if (card.dataset.value === next) {
            return; // 数字没变，不翻
        }

        if (!animate || reducedMotion.matches) {
            paintCard(card, next);
            return;
        }

        // 上一轮翻牌还没结束：先记下最新目标，结束后补播
        if (card.flipTimer) {
            card.pendingDigit = next;
            return;
        }

        const previous = card.dataset.value;
        const top = card.querySelector('.flip-half-top .flip-digit');
        const bottom = card.querySelector('.flip-half-bottom .flip-digit');
        const flapTop = card.querySelector('.flip-flap-top .flip-digit');
        const flapBottom = card.querySelector('.flip-flap-bottom .flip-digit');

        top.textContent = next;            // 静止上半层先换成新数字（旧上半翻走后露出来）
        flapTop.textContent = previous;    // 旧数字的上半向下翻
        flapBottom.textContent = next;     // 新数字的下半从上方翻下来
        card.dataset.value = next;

        card.classList.remove('is-flipping');
        void card.offsetWidth;             // 强制重排，保证动画能重复触发
        card.classList.add('is-flipping');

        card.flipTimer = window.setTimeout(function () {
            bottom.textContent = next;     // 动画结束后静止下半层才更新
            flapTop.textContent = next;
            flapBottom.textContent = next;
            card.classList.remove('is-flipping');
            card.flipTimer = null;

            if (card.pendingDigit != null) {
                const pending = card.pendingDigit;
                card.pendingDigit = null;
                setCard(card, pending, true);
            }
        }, FLIP_MS);
    }

    // 秒数 → 六位数字（时时分分秒秒）
    function toDigits(total) {
        const safe = Math.max(0, Math.floor(total));
        const h = String(Math.floor(safe / 3600)).padStart(2, '0');
        const m = String(Math.floor((safe % 3600) / 60)).padStart(2, '0');
        const s = String(safe % 60).padStart(2, '0');
        return (h + m + s).split('');
    }

    function render(seconds, animate) {
        const digits = toDigits(seconds);
        cards.forEach(function (card, index) {
            if (digits[index] !== undefined) {
                setCard(card, digits[index], animate);
            }
        });
    }

    // 秒数 → 可读文案，例如 3661 → “1 小时 1 分钟 1 秒”
    function formatDuration(total) {
        const h = Math.floor(total / 3600);
        const m = Math.floor((total % 3600) / 60);
        const s = total % 60;
        const parts = [];
        if (h > 0) {
            parts.push(h + ' 小时');
        }
        if (m > 0) {
            parts.push(m + ' 分钟');
        }
        if (s > 0 || parts.length === 0) {
            parts.push(s + ' 秒');
        }
        return parts.join(' ');
    }

    // ---------- 计时 ----------
    function stopTicker() {
        if (tickId !== null) {
            window.clearInterval(tickId);
            tickId = null;
        }
    }

    function tick() {
        if (state !== 'running') {
            return;
        }

        // 始终用绝对时间点重算，后台标签页被节流也不会漂移
        remainingMs = Math.max(0, deadline - Date.now());
        render(Math.ceil(remainingMs / 1000), true);

        if (remainingMs <= 0) {
            finish();
        }
    }

    function updateControls() {
        const paused = state === 'paused';
        pauseBtn.classList.toggle('is-paused', paused);
        pauseBtn.setAttribute('aria-label', paused ? '开始倒计时' : '暂停倒计时');
        pauseLabel.textContent = paused ? '开始' : '暂停';
        pauseBtn.disabled = state === 'finished';
    }

    function start() {
        if (state === 'running' || state === 'finished') {
            return;
        }
        state = 'running';
        deadline = Date.now() + remainingMs;
        stopTicker();
        tickId = window.setInterval(tick, TICK_MS);
        updateControls();
        announce('倒计时开始');
    }

    function pause() {
        if (state !== 'running') {
            return;
        }

        remainingMs = Math.max(0, deadline - Date.now());
        stopTicker();

        if (remainingMs <= 0) {
            finish();
            return;
        }

        state = 'paused';
        render(Math.ceil(remainingMs / 1000), true);
        updateControls();
        announce('倒计时已暂停');
    }

    function reset() {
        stopTicker();
        state = 'paused';
        remainingMs = totalSeconds * 1000;
        finishOverlay.hidden = true;
        render(totalSeconds, false);   // 静默恢复，不播放翻牌
        updateControls();
        announce('倒计时已重置');
    }

    function finish() {
        if (state === 'finished') {
            return;
        }
        stopTicker();
        state = 'finished';
        remainingMs = 0;
        render(0, true);
        updateControls();

        finishMessage.textContent = '你刚刚浪费了 ' + formatDuration(totalSeconds) + '。';
        finishOverlay.hidden = false;
        finishHome.focus();
        announce('倒计时结束，你刚刚浪费了 ' + formatDuration(totalSeconds) + '。');
    }

    function end() {
        stopTicker();
        window.location.assign('index.html');
    }

    // ---------- 事件绑定 ----------
    pauseBtn.addEventListener('click', function () {
        if (state === 'running') {
            pause();
        } else {
            start();
        }
    });
    resetBtn.addEventListener('click', reset);
    endBtn.addEventListener('click', end);

    window.addEventListener('pagehide', stopTicker);

    // 从后台切回来时立即按真实时间校正一次
    document.addEventListener('visibilitychange', function () {
        if (!document.hidden) {
            tick();
        }
    });

    // ---------- 启动：先静默显示总时长，再自动开始 ----------
    render(totalSeconds, false);
    start();
})();
