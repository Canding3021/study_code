/**
 * 校验用户注册表单
 * 依次校验每个输入框、单选框、多选框，未填写或未选择时弹出提示
 * 全部校验通过后提示注册成功
 */
function validateForm() {
    // 获取表单中各个控件的值
    const username = document.getElementById('username').value.trim();
    const password = document.getElementById('password').value;
    const gender = document.querySelector('input[name="gender"]:checked');
    const styles = document.querySelectorAll('input[name="style"]:checked');
    const phone = document.getElementById('phone').value.trim();
    const address = document.getElementById('address').value.trim();

    // 依次校验，存在没有输入或选择的情况则弹出警告框提示
    if (!username) {
        alert('请输入用户名');
        return;
    }
    if (!password) {
        alert('请输入密码');
        return;
    }
    if (!gender) {
        alert('请选择性别');
        return;
    }
    if (styles.length === 0) {
        alert('请选择风格');
        return;
    }
    if (!phone) {
        alert('请输入手机号');
        return;
    }
    if (!/^1[3-9]\d{9}$/.test(phone)) {
        alert('请输入正确的手机号');
        return;
    }
    if (!address) {
        alert('请输入收货地址');
        return;
    }

    // 校验全部通过
    alert('注册成功');
}

/**
 * 重置表单，清空所有输入信息
 */
function resetForm() {
    document.getElementById('registerForm').reset();
}
