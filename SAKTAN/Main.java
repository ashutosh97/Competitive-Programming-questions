import java.io.IOException;
import java.io.InputStream;
import java.util.*;
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
            StringBuilder sb= new StringBuilder();
            int n= br.readInt();
            int m= br.readInt();
            int q= br.readInt();
            
            int row[]= new int[n];
            int col[]= new int[m];
            
            for(int i=0;(i<n)&&(i<m);i++)
            {row[i]=0; col[i]=0;}
            if(n<m)
            {
                for(int i=n;i<m;i++)
                {col[i]=0;}
            }
            else
            {
                for(int i=m;i<n;i++)
                {row[i]=0;}
            }
            long rodd=0;
            long codd=0;
            //System.out.println(Arrays.toString(row));
            //System.out.println(Arrays.toString(col));
            int xx=0;
            int yy=0;
            int valx=0;
            int valy=0;
            for(int i=0;i<q;i++)
            {
                xx=br.readInt();
                yy= br.readInt();
                xx-=1;
                yy-=1;
                valx=row[xx];
                valy=col[yy];
                valx++;
                valy++;
                if(valx%2==0)
                {rodd--;}
                else
                {rodd++;}
                
                if(valy%2==0)
                {codd--;}
                else
                {codd++;}
                
                row[xx]=valx;
                col[yy]=valy;
                //System.out.println(rodd);
                //System.out.println(codd);
                //System.out.println(Arrays.toString(row));
                //System.out.println(Arrays.toString(col));
            }
            long reven= n-rodd;
            long ceven= m-codd;
            
            long odd= (codd*reven)+(ceven*rodd);
            System.out.println(odd);
            
        }
    }
}
            
                
                
           