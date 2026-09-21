package JAVA.studywork.work11.Race;
public class Race {
    private double toristDistance = 0;
    private double rabbitDistance = 0;
    // 比赛是否已经结束的标志
    private volatile boolean isGameOver = false; 

    // 1. 乌龟线程类
    public class Torist extends Thread {
        @Override
        public void run() {
            while (!isGameOver && toristDistance < 800) {
                toristDistance += 1;
                
                // 每跑 100 米汇报一次数据
                if ((int)toristDistance % 100 == 0) {
                    System.out.printf("🐢 乌龟跑了 %d 米，此时兔子跑了 %d 米%n", 
                            (int)toristDistance, (int)rabbitDistance);
                }

                // 模拟跑步耗时（让比赛有来有回）
                try { Thread.sleep(10); } catch (InterruptedException e) {}
            }

            // 检查是不是自己赢了
            if (toristDistance >= 800 && !isGameOver) {
                isGameOver = true;
                System.out.println("🎉 乌龟胜利了！兔子最终停在 " + (int)rabbitDistance + " 米。");
            }
        }
    }

    // 2. 兔子线程类
    public class Rabbit extends Thread {
        @Override
        public void run() {
            while (!isGameOver && rabbitDistance < 800) {
                rabbitDistance += 1.2; // 兔子速度稍快

                // 检查是否到达 600 米需要睡觉
                if ((int)rabbitDistance == 600) {
                    System.out.println("💤 兔子骄傲了，在 600 米处开始睡觉（1.2秒）...");
                    try { Thread.sleep(1200); } catch (InterruptedException e) {}
                }

                // 每跑完约 100 米汇报一次数据
                if ((int)rabbitDistance > 0 && (int)rabbitDistance % 100 == 0) {
                    System.out.printf("🐇 兔子跑了 %d 米，此时乌龟跑了 %d 米%n", 
                            (int)rabbitDistance, (int)toristDistance);
                }

                // 模拟跑步耗时
                try { Thread.sleep(10); } catch (InterruptedException e) {}
            }

            // 检查是不是自己赢了
            if (rabbitDistance >= 800 && !isGameOver) {
                isGameOver = true;
                System.out.println("🎉 兔子胜利了！乌龟最终停在 " + (int)toristDistance + " 米。");
            }
        }
    }
}
