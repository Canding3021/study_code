package JAVA.studywork.work10;

import java.util.HashMap;
import java.util.Scanner;

public class PhoneMapTest {
    public static void main(String[] args) {
        HashMap<String, String> phoneMap = new HashMap<>();
        phoneMap.put("iPhone 15 Pro", "A17 Pro芯片，8GB内存，钛金属边框");
        phoneMap.put("华为 Mate 60 Pro", "麒麟9000s芯片，12GB内存，卫星通话");
        phoneMap.put("小米 14 Ultra", "骁龙8 Gen3芯片，16GB内存，徕卡四摄");
        phoneMap.put("三星 S24 Ultra", "骁龙8 Gen3芯片，12GB内存，AI智控");
        phoneMap.put("OPPO Find X7", "天玑9300芯片，16GB内存，哈苏影像");
        phoneMap.put("vivo X100 Pro", "天玑9300芯片，16GB内存，蔡司影像");
        System.out.println("========== 手机配置查询系统 ==========");
        System.out.println("iPhone 15 Pro 的配置：" + phoneMap.get("iPhone 15 Pro"));
        System.out.println("华为 Mate 60 Pro 的配置：" + phoneMap.get("华为 Mate 60 Pro"));
        System.out.println("\n========== 所有手机型号列表 ==========");
        for (String model : phoneMap.keySet()) {
            System.out.println("型号：" + model);
            System.out.println("配置：" + phoneMap.get(model));
            System.out.println("------------------------");
        }
        Scanner scanner = new Scanner(System.in);
        System.out.println("\n========== 请输入要查询的手机型号 ==========");
        System.out.print("手机型号：");
        String inputModel = scanner.nextLine();

        if (phoneMap.containsKey(inputModel)) {
            System.out.println("【配置信息】" + phoneMap.get(inputModel));
        } else {
            System.out.println("未找到该型号的手机，请检查输入是否正确。");
        }
        scanner.close();
    }
}
