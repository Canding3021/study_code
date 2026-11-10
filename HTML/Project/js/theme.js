// 日间 / 夜间模式切换
// 夜间（默认）：html 无 data-theme；日间：html[data-theme="light"]
(function () {
    const root = document.documentElement;
    const toggle = document.getElementById('theme-toggle');
    const savedLight = localStorage.getItem('theme') === 'light';

    // 先恢复主题，即使当前页面没有开关
    if (savedLight) {
        root.dataset.theme = 'light';
    }

    // 页面没有主题开关时，只恢复主题，不绑定事件
    if (!toggle) {
        return;
    }

    toggle.checked = savedLight;

    toggle.addEventListener('change', function () {
        if (toggle.checked) {
            root.dataset.theme = 'light';
            localStorage.setItem('theme', 'light');
        } else {
            delete root.dataset.theme;
            localStorage.setItem('theme', 'dark');
        }
    });
})();
