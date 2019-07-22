import java.math.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner cin=new Scanner(System.in);
        while (cin.hasNext()) {
            BigInteger a=cin.nextBigInteger();
            String op=cin.next();
            BigInteger b=cin.nextBigInteger();
            if (op.equals("/")) System.out.println(a.divide(b));
            else System.out.println(a.mod(b));
        }
    }
}