import java.math.*;
import java.util.*;

public class Main {
    private static final int MAXN=10009;
    private static BigInteger[] fac=new BigInteger[MAXN];
    public static void main(String[] args) {
        fac[0]=BigInteger.ONE;
        for (int i=1; i<MAXN; i++) {
            fac[i]=fac[i-1].multiply(BigInteger.valueOf(i));
        }
        Scanner cin=new Scanner(System.in);
        while (cin.hasNext()) {
            int n=cin.nextInt();
            System.out.println(fac[n]);
        }
    }
}