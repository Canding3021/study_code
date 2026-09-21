using System;
using System.Data;
using System.Drawing;
using System.Windows.Forms;

namespace CSharpExercise2
{
    // ============================================
    // 上机2：C# 编程基础（语法基础 + 类型转换）
    // 一个文件里包含主窗体 FormMain 和 4 个子窗体
    // ============================================

    /// <summary>
    /// 主窗体：窗体名称(name)改为 FormMain，
    /// 放 4 个按钮，设置每个按钮的 Image 和 ImageAlign 属性，
    /// 在各按钮的 Click 事件中打开对应的子窗体。
    /// </summary>
    public class FormMain : Form
    {
        private Button btnTimu1 = new Button();
        private Button btnTimu2 = new Button();
        private Button btnTimu3 = new Button();
        private Button btnTimu4 = new Button();

        public FormMain()
        {
            this.Text = "FormMain - C# 上机2";

            Button[] btns = { btnTimu1, btnTimu2, btnTimu3, btnTimu4 };
            string[] titles = {
                "第1题：计算面积和周长",
                "第2题：计算和差商积",
                "第3题：温度转换 C->F",
                "第4题：温度转换 F->C"
            };
            // 按钮图标（与本目录下的图片文件对应）
            string[] icons = { "04.jpg", "06.jpg", "08.jpg", "11.jpg" };

            for (int i = 0; i < btns.Length; i++)
            {
                btns[i].Text = titles[i];
                btns[i].Width = 180;
                btns[i].Height = 36;
                btns[i].Left = 30;
                btns[i].Top = 20 + i * 46;
                btns[i].TextAlign = ContentAlignment.MiddleCenter;
                btns[i].ImageAlign = ContentAlignment.MiddleLeft;   // ImageAlign 属性
                try
                {
                    btns[i].Image = Image.FromFile(icons[i]);       // Image 属性
                }
                catch { /* 图片不存在时忽略，按钮仍可用 */ }
                this.Controls.Add(btns[i]);
            }

            // 知识点：从主窗体打开子窗体
            btnTimu1.Click += (s, e) => { new FormTimu1().Show(); };
            btnTimu2.Click += (s, e) => { new FormTimu2().Show(); };
            btnTimu3.Click += (s, e) => { new FormTimu3().Show(); };
            btnTimu4.Click += (s, e) => { new FormTimu4().Show(); };
        }
    }

    /// <summary>
    /// 第 1 个窗体：计算面积和周长（矩形）。
    /// 知识点：文本数据转换为整型、数据转换为文本。
    /// </summary>
    public class FormTimu1 : Form
    {
        private Label lblLength = new Label();
        private Label lblWidth = new Label();
        private TextBox txtLength = new TextBox();
        private TextBox txtWidth = new TextBox();
        private Button btnCalc = new Button();
        private Label lblResult = new Label();

        public FormTimu1()
        {
            this.Text = "FormTimu1 - 计算面积和周长";

            lblLength.Text = "长：";
            lblLength.Left = 20; lblLength.Top = 20;
            txtLength.Left = 80; txtLength.Top = 20;

            lblWidth.Text = "宽：";
            lblWidth.Left = 20; lblWidth.Top = 60;
            txtWidth.Left = 80; txtWidth.Top = 60;

            btnCalc.Text = "计算";
            btnCalc.Left = 80; btnCalc.Top = 100;

            lblResult.Left = 20; lblResult.Top = 150;
            lblResult.Width = 250;
            lblResult.Text = "面积和周长显示在这里";

            this.Controls.AddRange(new Control[] {
                lblLength, txtLength, lblWidth, txtWidth, btnCalc, lblResult
            });

            btnCalc.Click += (s, e) =>
            {
                // 文本数据转换为整型
                int length = Convert.ToInt32(txtLength.Text);
                int width = Convert.ToInt32(txtWidth.Text);

                int area = length * width;            // 面积
                int perimeter = (length + width) * 2;  // 周长

                // 数据转换为文本
                lblResult.Text = "面积 = " + area.ToString()
                              + "，周长 = " + perimeter.ToString();
            };
        }
    }

    /// <summary>
    /// 第 2 个窗体：计算和、差、商、积。
    /// 用两个 numericUpDown 数值框输入，lblResult 显示结果。
    /// </summary>
    public class FormTimu2 : Form
    {
        private NumericUpDown numericUpDown1 = new NumericUpDown();
        private NumericUpDown numericUpDown2 = new NumericUpDown();
        private Button btnAdd = new Button();
        private Button btnSub = new Button();
        private Button btnMul = new Button();
        private Button btnDiv = new Button();
        private Label lblResult = new Label();

        public FormTimu2()
        {
            this.Text = "FormTimu2 - 计算和差商积";

            numericUpDown1.Left = 20;  numericUpDown1.Top = 20;  numericUpDown1.Width = 100;
            numericUpDown2.Left = 140; numericUpDown2.Top = 20;  numericUpDown2.Width = 100;

            btnAdd.Text = "加"; btnAdd.Left = 20;  btnAdd.Top = 70; btnAdd.Width = 60;
            btnSub.Text = "减"; btnSub.Left = 90;  btnSub.Top = 70; btnSub.Width = 60;
            btnMul.Text = "乘"; btnMul.Left = 160; btnMul.Top = 70; btnMul.Width = 60;
            btnDiv.Text = "除"; btnDiv.Left = 230; btnDiv.Top = 70; btnDiv.Width = 60;

            lblResult.Left = 20; lblResult.Top = 120; lblResult.Width = 320;
            lblResult.Text = "结果显示在这里";

            this.Controls.AddRange(new Control[] {
                numericUpDown1, numericUpDown2,
                btnAdd, btnSub, btnMul, btnDiv, lblResult
            });

            // 加法按钮的 click 处理代码
            btnAdd.Click += (s, e) =>
            {
                lblResult.Text = numericUpDown1.Value.ToString() + "+"
                              + numericUpDown2.Value.ToString() + "="
                              + Convert.ToString(numericUpDown1.Value + numericUpDown2.Value);
            };

            // 减法
            btnSub.Click += (s, e) =>
            {
                lblResult.Text = numericUpDown1.Value.ToString() + "-"
                              + numericUpDown2.Value.ToString() + "="
                              + Convert.ToString(numericUpDown1.Value - numericUpDown2.Value);
            };

            // 乘法
            btnMul.Click += (s, e) =>
            {
                lblResult.Text = numericUpDown1.Value.ToString() + "*"
                              + numericUpDown2.Value.ToString() + "="
                              + Convert.ToString(numericUpDown1.Value * numericUpDown2.Value);
            };

            // 除法（商）
            btnDiv.Click += (s, e) =>
            {
                if (numericUpDown2.Value == 0)
                {
                    lblResult.Text = "除数不能为 0";
                    return;
                }
                lblResult.Text = numericUpDown1.Value.ToString() + "/"
                              + numericUpDown2.Value.ToString() + "="
                              + Convert.ToString((double)numericUpDown1.Value / (double)numericUpDown2.Value);
            };
        }
    }

    /// <summary>
    /// 第 3 个窗体：温度转换，公式 F = 1.8 * C + 32。
    /// </summary>
    public class FormTimu3 : Form
    {
        private Label lblC = new Label();
        private TextBox txtC = new TextBox();
        private Button btnConvert = new Button();
        private Label lblResult = new Label();

        public FormTimu3()
        {
            this.Text = "FormTimu3 - 温度转换 C->F";

            lblC.Text = "摄氏温度 C：";
            lblC.Left = 20; lblC.Top = 20;
            txtC.Left = 110; txtC.Top = 20; txtC.Width = 100;

            btnConvert.Text = "转换";
            btnConvert.Left = 110; btnConvert.Top = 60;

            lblResult.Left = 20; lblResult.Top = 110; lblResult.Width = 250;
            lblResult.Text = "华氏温度 F 显示在这里";

            this.Controls.AddRange(new Control[] { lblC, txtC, btnConvert, lblResult });

            btnConvert.Click += (s, e) =>
            {
                double c = double.Parse(txtC.Text);   // 文本转数值
                double f = 1.8 * c + 32;               // 转换公式
                lblResult.Text = "F = 1.8 * " + c + " + 32 = " + f.ToString();
            };
        }
    }

    /// <summary>
    /// 第 4 个窗体：温度转换（反向），C = (F - 32) / 1.8。
    /// Math.Pow(x, y) 返回 x 的 y 次幂；Math.Round(x, y) 四舍五入到 y 位小数。
    /// </summary>
    public class FormTimu4 : Form
    {
        private Label lblF = new Label();
        private TextBox txtF = new TextBox();
        private Button btnConvert = new Button();
        private Label lblResult = new Label();

        public FormTimu4()
        {
            this.Text = "FormTimu4 - 温度转换 F->C";

            lblF.Text = "华氏温度 F：";
            lblF.Left = 20; lblF.Top = 20;
            txtF.Left = 110; txtF.Top = 20; txtF.Width = 100;

            btnConvert.Text = "转换";
            btnConvert.Left = 110; btnConvert.Top = 60;

            lblResult.Left = 20; lblResult.Top = 110; lblResult.Width = 250;
            lblResult.Text = "摄氏温度 C 显示在这里";

            this.Controls.AddRange(new Control[] { lblF, txtF, btnConvert, lblResult });

            btnConvert.Click += (s, e) =>
            {
                double f = double.Parse(txtF.Text);   // 文本转数值
                // 转换公式：F = 1.8 * C + 32  =>  C = (F - 32) / 1.8
                double c = (f - 32) / 1.8;
                c = Math.Round(c, 2);                 // 四舍五入保留 2 位小数
                lblResult.Text = "C = (" + f + " - 32) / 1.8 = " + c.ToString();

                // Math.Pow(x, y)：返回 x 的 y 次幂，例如 Math.Pow(2, 3) = 8
                // Math.Round(x, y)：四舍五入到 y 位小数
            };
        }
    }

    /// <summary>
    /// 程序入口。
    /// </summary>
    static class Program
    {
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new FormMain());
        }
    }
}
