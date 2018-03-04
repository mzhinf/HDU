import java.io.*;
import java.util.*;//Scanner
import java.math.*;
class Main{
    public static void main(String[] args){
		BigInteger[] out = new BigInteger[10005];
		out[0] = new BigInteger("1");
		for(int i=1;i<10001;i++){
			BigInteger t = new BigInteger(String.valueOf(i));
			out[i]=out[i-1].multiply(t);
		}
		Scanner cin=new Scanner(System.in);
		while(cin.hasNext()){
			int a=cin.nextInt();
			System.out.println(out[a]);
		}
    }
}