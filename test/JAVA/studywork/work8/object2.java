package work8;

public class object2 {
    public static void main(String[] args) {
        String str = "ITcastHeiMa";
        StringBuffer sb = new StringBuffer();
        for (int i = str.length() - 1; i >= 0; i--) {
            char c = str.charAt(i);
            if (c >= 'A' && c <= 'Z') {
                sb.append(Character.toLowerCase(c));
            } else if (c >= 'a' && c <= 'z') {
                sb.append(Character.toUpperCase(c));
            } else {
                sb.append(c);
            }
        }
        String result = sb.toString();
        System.out.println("转换后的结果：" + result);
    }
}
