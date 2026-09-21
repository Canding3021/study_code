package JAVA.studywork.work10;

import java.util.HashSet;
import java.util.Objects;

public class Diary {
    String time;      // 时间
    String name;      // 姓名
    String weather;   // 天气
    String title;     // 标题
    String content;   // 内容

    // 无参构造方法
    public Diary() {
    }

    // 有参构造方法
    public Diary(String time, String name, String weather, String title, String content) {
        this.time = time;
        this.name = name;
        this.weather = weather;
        this.title = title;
        this.content = content;
    }

    // toString() 方法：输出5个属性的值
    @Override
    public String toString() {
        return "Diary{" +
                "time='" + time + '\'' +
                ", name='" + name + '\'' +
                ", weather='" + weather + '\'' +
                ", title='" + title + '\'' +
                ", content='" + content + '\'' +
                '}';
    }

    // hashCode() 方法：返回值是 time 的 hash 值与 name 的 hash 值的和
    @Override
    public int hashCode() {
        return Objects.hashCode(time) + Objects.hashCode(name);
    }

    // equals() 方法：判断对象的 time 和 name 是否相同
    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Diary diary = (Diary) obj;
        return Objects.equals(time, diary.time) &&
               Objects.equals(name, diary.name);
    }
    public static void main(String[] args) {
        HashSet<Diary> hs = new HashSet<Diary>();
        Diary d1 = new Diary("2024/11/14", "张三", "晴", "学习Java", "今天学习了HashSet，感觉很有收获");
        Diary d2 = new Diary("2024/11/15", "李四", "雨", "跑步", "今天跑了5公里，很舒服");
        Diary d3 = new Diary("2024/11/14", "张三", "阴", "复习", "晚上复习了一下今天的课程");
        Diary d4 = new Diary("2024/11/16", "王五", "多云", "购物", "买了一些日用品");
        Diary d5 = new Diary("2024/11/14", "张三", "雪", "不同的标题", "不同的内容");
        hs.add(d1);
        hs.add(d2);
        hs.add(d3);
        hs.add(d4);
        hs.add(d5);
        System.out.println("HashSet中的日记数量：" + hs.size());
        System.out.println("========== 日记列表 ==========");
        for (Diary diary : hs) {
            System.out.println(diary);
        }
    }
}
