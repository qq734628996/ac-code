import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;
class Main
{
	public static void main(String[] args)
	{
		Scanner cin = new Scanner(System.in);
		BigInteger[] f = new BigInteger[10005];
		f[0] = BigInteger.valueOf(2);
		f[1] = BigInteger.valueOf(1);
		for (int i = 2; i <= 10000; i++)
			f[i] = f[i-1].add(f[i-2]);
		while (cin.hasNext()) {
			int n = cin.nextInt();
			System.out.println(f[n]);
		}
	}
}