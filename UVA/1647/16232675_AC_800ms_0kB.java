import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;
class Main
{
	public static void main(String[] args)
	{
		BigInteger[] f = new BigInteger[1005];
		BigInteger t = BigInteger.valueOf(2);
		f[1] = BigInteger.valueOf(0);
		f[2] = f[3] = BigInteger.valueOf(1);
		for (int i = 4; i <= 1000; i++) {
			f[i] = f[i-2].add(t);
			t = t.multiply(BigInteger.valueOf(2));
		}
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()) {
			int n = cin.nextInt();
			System.out.println(f[n]);
		}
	}
}