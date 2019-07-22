import java.math.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner cin=new Scanner(System.in);
        while (cin.hasNext()) {
            BigDecimal a=cin.nextBigDecimal();
            int b=cin.nextInt();
            String ans=a.pow(b).stripTrailingZeros().toPlainString();
            if (ans.startsWith("0")) ans=ans.substring(1);
            System.out.println(ans);
        }
    }
}