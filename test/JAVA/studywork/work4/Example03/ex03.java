package work4.Example03;
class BankAccount {
    private String accountNumber;
    private double balance;
    public BankAccount(String accountNumber,double initialBalance){
        this.accountNumber=accountNumber;
        if(initialBalance>=0){
            this.balance=initialBalance;
        }else{
            System.out.println("input error.");
            this.balance=0;
        }
    }
    public String getAccountNumber(){
        return accountNumber;
    }
    public double getbalance(){
        return balance;
    }
    public void setAccountNumber(String accoutNumber){
        if (accoutNumber != null && accoutNumber.length()==6) {
            this.accountNumber=accoutNumber;
        }else{
            System.out.println("the account must be six byte.");
        }
    }
    public void deposit(double amount){
        if(amount>0){
            this.balance+=amount;
            System.out.println("存入成功！余额+"+amount);
        }else{
            System.out.println("input error.");
        }
    }
    public void withdraw(double amount) {
        if(amount > 0 && amount <= balance) {
            balance -= amount;
            System.out.println("取款成功！取出：" + amount);
        } else if(amount <= 0) {
            System.out.println("取款金额必须大于0!");
        } else {
            System.out.println("余额不足！当前余额：" + balance);
        }
    }
    public void displayInfo() {
        System.out.println("账户：" + accountNumber);
        System.out.println("余额：" + balance);
    }
}
public class ex03 {
    public static void main(String[] args){
        BankAccount account=new BankAccount("123456",1000);
        account.displayInfo();
        account.deposit(500);
        account.displayInfo();
        account.withdraw(300);
        account.displayInfo();
        account.withdraw(2000);  
        account.deposit(-100);
        System.out.println("\n当前账号:" + account.getAccountNumber());
        System.out.println("当前余额：" + account.getbalance());
    }
}
