import java.math.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner cin=new Scanner(System.in);
        int T=cin.nextInt();
        for (int kase=1; kase<=T; kase++) {
            int n=cin.nextInt();
            BigInteger ans=cin.nextBigInteger();
            for (int i=1; i<n; i++) {
                BigInteger x=cin.nextBigInteger();
                ans=ans.divide(ans.gcd(x)).multiply(x);
            }
            System.out.println("Case "+kase+": "+ans);
            System.gc();
        }
    }
}