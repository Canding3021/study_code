package work6.object1.model;

public abstract class Person {
    private String name;
    private String job;
    public Person(String name,String job){
        this.name=name;
        this.job=job;
    }
    public void setJob(String job) {
        this.job = job;
    }
    public void setName(String name) {
        this.name = name;
    }
    public String getJob() {
        return job;
    }
    public String getName() {
        return name;
    }
    public abstract void introduction();
}
