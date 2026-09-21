package JAVA.studywork.work10;

import java.util.HashSet;
import java.util.Objects;

public class Course {
    private String id;      
    private String name;    
    private int credit;     

    public Course() {
    }

    public Course(String id, String name, int credit) {
        this.id = id;
        this.name = name;
        this.credit = credit;
    }

    @Override
    public String toString() {
        return "Course{" +
                "id='" + id + '\'' +
                ", name='" + name + '\'' +
                ", credit=" + credit +
                '}';
    }

    @Override
    public int hashCode() {
        return Objects.hashCode(id);
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Course course = (Course) obj;
        return Objects.equals(id, course.id);
    }
    public static void main(String[] args) {
        HashSet<Course> hs = new HashSet<>();

        hs.add(new Course("C001", "Java程序设计", 3));
        hs.add(new Course("C002", "数据结构", 4));
        hs.add(new Course("C003", "数据库原理", 3));
        hs.add(new Course("C001", "Java程序设计", 3));  // id 相同，不会重复添加
        hs.add(new Course("C004", "操作系统", 4));

        System.out.println("HashSet中的课程数量：" + hs.size());
        System.out.println("========== 课程列表 ==========");
        for (Course c : hs) {
            System.out.println(c);
        }
    }
}
