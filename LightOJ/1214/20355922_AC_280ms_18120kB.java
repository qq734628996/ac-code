import java.math.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner cin=new Scanner(System.in);
        int T=cin.nextInt();
        for (int kase=1; kase<=T; kase++) {
            BigInteger a=cin.nextBigInteger();
            BigInteger b=cin.nextBigInteger();
            b=b.abs();
            System.out.print("Case "+kase+": ");
            if (a.mod(b).equals(BigInteger.ZERO)) System.out.println("divisible");
            else System.out.println("not divisible");
        }
    }
}