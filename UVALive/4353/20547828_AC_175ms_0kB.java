import java.math.*;
import java.util.*;

public class Main {
    public static BigInteger sqrt(BigInteger x) {
        BigInteger div=BigInteger.ZERO.setBit(x.bitLength()/2);
        BigInteger div2=div;
        while (true) {
            BigInteger y=div.add(x.divide(div)).shiftRight(1);
            if (y.equals(div) || y.equals(div2)) {
                if (y.multiply(y).equals(x)) return y;
                else return BigInteger.valueOf(-1);
            }
            div2=div;
            div=y;
        }
    }
    public static void main(String[] args) {
        Scanner cin=new Scanner(System.in);
        int kase=0;
        while (cin.hasNext()) {
            BigInteger n,d,e,t,b,delta,p,q;
            n=cin.nextBigInteger();
            d=cin.nextBigInteger();
            e=cin.nextBigInteger();
            if (e.equals(BigInteger.ZERO)) break;
            d=d.multiply(e).subtract(BigInteger.ONE);
            for (int i=1; ; i++) {
                if (d.mod(BigInteger.valueOf(i)).signum()>0) continue;
                t=d.divide(BigInteger.valueOf(i));
                b=n.add(BigInteger.ONE).subtract(t);
                delta=b.multiply(b).subtract(n.shiftLeft(2));
                if (delta.signum()<0) continue;
                delta=sqrt(delta);
                if (delta.signum()<0) continue;
                p=b.subtract(delta).shiftRight(1);
                q=b.add(delta).shiftRight(1);
                if (p.multiply(q).equals(n)) {
                    System.out.println("Case #"+ ++kase+": "+p+" "+q);
                    break;
                }
            }
        }
    }
}