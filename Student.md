import java.util.*;
class StudentA
{
	protected String name;
	protected int roll_no;
	void read()
	{
		Scanner reader=new Scanner(System.in);
		System.out.println("Enter Student name");
		name=reader.next();
		System.out.println("Enter Student Roll number");
		roll_no=reader.nextInt();
	}
	String display()
	{
		return name;

	}
}

public class Experiment4StudentArray {

	public static void main(String[] args) throws  ArrayIndexOutOfBoundsException
	{
		Scanner reader=new Scanner(System.in);
		try
		{
		System.out.println("Enter number of Students");
		int n=reader.nextInt();
		StudentA s[]=new StudentA[10];
		int i;
		for(i=0;i<n;i++)
		{
		    s[i]=new StudentA();
			s[i].read();

		}
		System.out.println("Enter the starting character ");
		String start=reader.next();
		start=start.toLowerCase();
		for(i=0;i<s.length;i++)
		{
			String getname=s[i].display();
			getname=getname.toLowerCase();
			if(getname.startsWith(start))
			{
			System.out.println("Student Name is "+s[i].name+" Roll number is "+s[i].roll_no);
		    }
		}
	}
		catch(ArrayIndexOutOfBoundsException e)
		{
			System.out.println("Exception "+e+" occured");
		}
	}
}


