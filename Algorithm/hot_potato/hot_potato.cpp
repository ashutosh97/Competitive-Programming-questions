#include<bits/stdc++.h>
using namespace std;

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
                     /*for(int i=0;i<MaxSize;i++)
                     {
                            cout << element[i] << endl;
                     }*/

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

int main()
{
  LinearList<int> a(250);
  int k,n,i,j,temp;
  cout << "Enter number of children: ";
  cin >> n;
  cout << "Enter elimination rule: ";
  cin >> i;
  for(j=0;j<n;j++)
  {
    temp=j+1;
    a.insert(j,temp);
  }
  for(j=0;j<n;j++)
  {
    cout << a[j] << " ";
  }
  cout << endl;
  j=1;
  k=0;
  while(1)
  {
    if(a.length()==1)
    {
      break;
    }
    if(j%i!=0)
    {
      a.deleteElement(1,temp);
      a.insert(a.length(),temp);
      j++;
    }
    else
    {
      /*cout << j << " " << i << endl;
      for(k=0;k<a.length();k++)
      {
        cout << a[k] << " ";
      }
      cout << endl;*/
      a.deleteElement(1,temp);
      cout << "person at position " << temp << " is removed" << endl;
      j++;
    }

  }
  cout << "Hence person at position ";
  for(j=0;j<a.length();j++)
  {
    cout << a[j] << " ";
  }
  cout << "survives." << endl;

}