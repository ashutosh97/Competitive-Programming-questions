import java.io.IOException;
import java.io.InputStream;
import java.util.InputMismatchException;
import java.util.Arrays;
class LCSin
{
    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private SpaceCharFilter filter;
    public LCSin(InputStream stream) {
        this.stream = stream;
    }
    public interface SpaceCharFilter {
        public boolean isSpaceChar(int ch);
    }
    public int read() {
        if (numChars == -1)
            throw new InputMismatchException();
        if (curChar >= numChars) {
            curChar = 0;
        try {
            numChars = stream.read(buf);
        } catch (IOException e) {
            throw new InputMismatchException();
        }
        if (numChars <= 0)
            return -1;
        }
        return buf[curChar++];
    }
    public int readInt() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }
    public boolean isSpaceChar(int c) {
        if (filter != null)
            return filter.isSpaceChar(c);
        return c==' '||c=='\n'|| c == '\r' || c == '\t' || c == -1;
    }
    public String readString() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        StringBuilder res = new StringBuilder();
        do {
            res.appendCodePoint(c);
            c = read();
        } 
        while (!isSpaceChar(c));
        return res.toString();
    }
    public byte readByte() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        byte res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res;
    }
    public long readLong() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-')
        {
            sgn = -1;
            c = read();
        }
        long res = 0;
        do
        {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        }
        while (!isSpaceChar(c));
        return res * sgn;
    }
}

public class Main
{
    public static void main(String args[])
    {
        LCSin br= new LCSin(System.in);
        int test= br.readInt();
        
        for(int testcase= 0; testcase<test;testcase++)
        {
           
            int n= br.readInt();
            int a[]= new int[n];
            for(int i=0;i<n;i++)
            {
                a[i]= br.readInt();
            }
          
           int good=1;
           for(int j=1;j<n;j++)
           {
               int min=j;
               for(int k=j-1;(k>=0)&&(j-k)<=5;k--)
               {
                   if(a[k]<=a[j])
                   min=k;
               }
               if(min==j)
               good++;
            }
            System.out.println(good);
        }
    }
}
               