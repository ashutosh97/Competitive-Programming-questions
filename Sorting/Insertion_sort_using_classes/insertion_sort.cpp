#include<bits/stdc++.h>
using namespace std;

/* Hi I am using my own class to use in insertion sort function*/

template<class Item>
class LinearList{
	private:
		int MaxSize;
		Item *element;    // 1D dynamic array
        int len;
	public:
		/* Default constructor. 
		 * Should create an empty list that not contain any elements*/
		LinearList()
		{
			element=nullptr;
			len=0;
		};

		/* This constructor should create a list containing MaxSize elements. You can intialize the elements with any values.*/
		LinearList(const int& MaxListSize)
		{
			MaxSize=MaxListSize;
			element = new Item[MaxSize];
			len=0;

		};

		/* Destructor. 
		 * Must free all the memory contained by the list */
		~LinearList(){};

		/* Indexing operator.
     		 * It should behave the same way array indexing does. i.e,
     		 * LinearList L;
     		 * L[0] should refer to the first element;
     		 * L[1] to the second element and so on.
     		 * */
		Item& operator[](const int& i)
		{
			return element[i];
		}; //return i'th element of list
		
		/* Returns true if the list is empty, false otherwise.
     		 * */
		bool isEmpty()
		{
			if(len==0)
			{
				return true;
			}
			else
			{
				return false;
			}
		};

		/* Returns the actual length (number of elements) in the list.
     		 * */
		int  length()
		{
			return len;
		};	

		/* Returns the maximum size of the list.
     		 * */
		int  maxSize()
		{
			return maxSize;
		};

		/* Returns the k-th element of the list. 
		 * */
		Item  returnListElement(const int k)
		{
			return element[k-1];
		};
		/* Set x to the k-th element and 
		 * return true if k-th element is present otherwise return false.
		 * */
		bool find(const int k, Item& x)
		{
			if(x==element[k-1])
			{
				return true;
			}
			else
			{
				
				return false;
			}
		};

		/* Search for x and 
		 * return the position if found, else return 0.
		 * */
		int  search(Item& x)
		{
			for(int i=0;i<len;i++)
			{
				if(element[i]==x)
				{
					return i+1;
				}
			}
			return 0;

		};

		/* Set x to the k-th element and delete that k-th element.
		 * */
		void  deleteElement(const int  k, Item& x)
		{
			x=element[k-1];
			for(int i=k;i<len;i++)
			{
				element[i-1]=element[i];
			}
			len=len-1;
		};

		/* Insert x after k-th element.
		 * */
		void  insert(const int  k, Item& x)
		{
			for(int i=len;i>k;i--)
			{
				element[i]=element[i-1];
			}
			element[k]=x;
			len=len+1;
		};

					
};

//insertion sort function
void insertionSort(LinearList<int>& A)
		{
			int i,j,temp,len;
			i=j=0;
			len=A.length();
			j=len;
			for(i=1;i<len;i++)
			{
				temp=A[i];
				for(j=i-1;j>-1;j--)
				{
					if(temp<A[j])
					{
						A[j+1]=A[j];
					}
					else
					{						
						break;
					}
				}
				A[j+1]=temp;

			}
		}

//Driver Function
int main()
{
	int n,temp,i;
	cin >> n;
	LinearList<int> l(100);
	
	for(i=0;i<n;i++)
	{
		cin >> temp;
		l.insert(i,temp);
	}
	insertionSort(l);
	for(i=0;i<n;i++)
	{
		cout << l[i] << " ";
	}
	cout << endl;
}
