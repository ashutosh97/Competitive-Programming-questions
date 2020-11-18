#include <iostream>;
using namespace std;
#include "Stack.h"
#include "Header.h"



void function(linkedlist &l, IntStack &s) {

	IntStack store;

	int sum = 0;
	int index=0;
	bool flag = false;
	l.trav = l.head;
	int value;
	while (l.trav!=NULL)
	{
		if (l.trav->val<0)
		{
			l.trav->val = -l.trav->val;

		}
		flag = false;
		if (s.isEmpty())
		{s.push(l.trav->val);}
		else
		{
			while (!s.isEmpty())
			{
				index = s.pop();
				sum +=index ;
				
				if (sum==l.trav->val)
				{
					sum = 0;
					store.top = -1;
					flag = true;
					break;
				}
				store.push(index);
			}
			if (flag==false)
			{
				while (!store.isEmpty())
				{
					s.push(store.pop());
					sum = 0;
				}
				s.push(l.trav->val);
			}
		}
		l.trav = l.trav->next;
	}

	while (!s.isEmpty())
	{
		cout << s.pop() << endl;
	}


}


bool isPalindrome(linkedlist &l, IntStack &s)
{
	l.trav = l.head;
	int temp;
	while (l.trav != NULL)
	{
		s.push(l.trav->val);
		l.trav = l.trav->next;
	}

	l.trav = l.head;
	while (l.trav!=NULL)
	{
		temp = s.pop();
		if (temp!=l.trav->val)
		{
			return false;
		}

		l.trav = l.trav->next;

	}

	return true;
}


void mergeLL(linkedlist l, linkedlist ll) {
	
	
	ll.temp = NULL;
	l.temp = NULL;

	l.trav =l.head;
	ll.trav = ll.head;

	while (l.trav!=NULL|| ll.trav!=NULL )
	{

		ll.temp = ll.trav->next;
		ll.trav->next = l.trav->next;
		ll.trav->prev = l.trav;
		l.trav->next = ll.trav;
		if (ll.trav->next)
		{
			l.trav = ll.trav->next;
			l.trav->prev = ll.trav;
			ll.trav = ll.temp;
		}
		else
		{
			l.trav = ll.trav;
			break;
		}
		
		

		l.display();
		cout << endl;
		
	}


}
struct Node
{
	Node *next = NULL;
	Node *prev = NULL;
	double val;

};


void hashing(Node* arr[] ,int val) {
	int index = 0;
	Node *newNode = new Node();
	newNode->val = val;
	index = val % 10;
	Node *trav = arr[index];
	if (trav)
	{
		while (trav->next != NULL)
		{
			trav = trav->next;
		}
		trav->next = newNode;
	}
	else
	{
		trav = newNode;
	}


	
	
	trav= arr[index];
	while (trav!= NULL)
	{
		cout << trav->val<<"-->";
		trav = trav->next;
	}
	
}




int main() {
	


	Node* arr[10] = {};
	

	hashing(arr,1);
	hashing(arr, 1);
	hashing(arr, 1);
	hashing(arr, 1);
	hashing(arr, 1);
	hashing(arr, 1);

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i]->val;

	}


	

	/*IntStack s;
	linkedlist l;
	linkedlist ll;

	l.insert(1);
	l.insert(2);
	l.insert(3);
	l.insert(4);
	l.insert(3);
	l.insert(4); l.insert(3);
	l.insert(4);

	ll.insert(11);
	ll.insert(22);
	ll.insert(33);
	ll.insert(44);
	
	mergeLL(l, ll);
	
	*/
	//cout<<isPalindrome(l,s);
	//l.removeDuplicate();
	//function(l, s);

	//l.reverseLL(l.head);
	//l.display();
	//ll.display();


	getchar();
	return 0;
}