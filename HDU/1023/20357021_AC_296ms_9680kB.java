import java.math.*;
import java.util.*;

public class Main {
    private static final int MAXN=109;
    private static BigInteger[] f=new BigInteger[MAXN];
    public static void main(String[] args) {
        f[1]=BigInteger.ONE;
        for (int i=2; i<MAXN; i++) {
            f[i]=f[i-1].multiply(
                BigInteger.valueOf(4*i-2)
            ).divide(BigInteger.valueOf(i+1));
        }
        Scanner cin=new Scanner(System.in);
        while (cin.hasNext()) {
            int n=cin.nextInt();
            System.out.println(f[n]);
        }
    }
}