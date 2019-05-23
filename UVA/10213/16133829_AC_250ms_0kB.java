import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;
class Main
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);
        int T = cin.nextInt();
        while(T-- > 0) {
            long n = cin.nextLong();
            BigInteger ans = BigInteger.valueOf(1);
            for (int i = 0; i < 4; i++)
                ans = ans.multiply(BigInteger.valueOf(n-i));
            ans = ans.divide(BigInteger.valueOf(24));
            ans = ans.add(BigInteger.valueOf((n*n-n+2)/2));
            System.out.println(ans);
        }
    }
}