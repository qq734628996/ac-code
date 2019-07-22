import java.math.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner cin=new Scanner(System.in);
        BigInteger ans=new BigInteger("0");
        while (true) {
            BigInteger x=cin.nextBigInteger();
            if (x.equals(BigInteger.ZERO)) break;
            ans=ans.add(x);
        }
        System.out.println(ans);
    }
}