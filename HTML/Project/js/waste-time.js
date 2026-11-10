// index：选择预设时长后，把秒数写进 sessionStorage 再跳到倒计时页
(function () {
    const STORAGE_KEY = 'waste-time:seconds';
    const MAX_SECONDS = 23 * 3600 + 59 * 60 + 59;   // 与倒计时页一致：最大 23:59:59
    const presets = document.querySelectorAll('.preset-btn[data-seconds]');
    let leaving = false;

    presets.forEach(function (link) {
        link.addEventListener('click', function (event) {
            // 组合键 / 非左键点击保留浏览器默认行为（比如在新标签打开）
            if (event.metaKey || event.ctrlKey || event.shiftKey || event.altKey || event.button !== 0) {
                return;
            }

            event.preventDefault();

            // 防止双击产生两次跳转
            if (leaving) {
                return;
            }

            const seconds = Number(link.dataset.seconds);
            if (!Number.isInteger(seconds) || seconds < 1 || seconds > MAX_SECONDS) {
                return;
            }

            try {
                window.sessionStorage.setItem(STORAGE_KEY, String(seconds));
            } catch (error) {
                // 存储不可用时仍然跳转，倒计时页会使用默认时长
            }

            leaving = true;
            window.location.assign('waste-time.html');
        });
    });
})();
