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
        StringBuilder sb=new StringBuilder();
        for(int testcase= 0; testcase<test;testcase++)
        {
            long x=0;
            long y=0;
            long prevmax=0;
            long prevmin=0;
            boolean res= false;
            
            int n= br.readInt();
            for(int i=0;i<n;i++)
            {
                int alpha= br.readInt();
                long a= br.readInt();
                long b= br.readInt();
                long max= (long)Math.max(a,b);
                long min= (long)Math.min(a,b);
                
                if(a==b)
                {
                    System.out.println("YES");
                    res= true;
                    prevmax= a;
                    prevmin= a;
                    continue;
                }
                
                if(alpha==1)
                {
                    System.out.println("YES");
                    prevmax= max;
                    prevmin= min;
                    res= true;
                    continue;
                }
                
                if(min>prevmax)
                {
                    System.out.println("NO");
                    prevmax= max;
                    prevmin= min;
                    res= false;
                    continue;
                }
                
                if((max>prevmax)&&(min<prevmax))
                {
                    if(res==false)
                    {System.out.println("NO");}
                    else
                    {System.out.println("YES");}
                    prevmax= max;
                    prevmin= min;
                    continue;
                
                }
                
                if((max==prevmax)&&(min<prevmax))
                {
                 if(res==false)
                    {System.out.println("NO");}
                    else
                    {System.out.println("YES");}
                    prevmax= max;
                    prevmin= min;
                    continue;
                
                }
                
                if((max>prevmax)&&(min==prevmax))
                {
                
                System.out.println("NO");
                res= false;
                prevmax= max;
                prevmin= min;
                continue;
                
                }
            }
        }
    }
}