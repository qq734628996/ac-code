import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    private static final int MAXN=10009;
    private static BigInteger[] f=new BigInteger[MAXN];
    private static BigInteger MOD;
    public static void main(String[] args) {
        StringBuilder sb=new StringBuilder();
        sb.append("1");
        for (int i=0; i<100; i++) sb.append("0");
        MOD=new BigInteger(sb.toString());
        f[0]=f[1]=BigInteger.ONE;
        for (int i=2; i<=10000; i++) {
            f[i]=BigInteger.valueOf(2*i+1).multiply(f[i-1]).add(
                BigInteger.valueOf(3*i-3).multiply(f[i-2])
            ).divide(BigInteger.valueOf(i+2));
        }
        Scanner cin=new Scanner(System.in);
        while (cin.hasNext()) {
            int n=cin.nextInt();
            System.out.println(f[n].mod(MOD));
        }
    }
}