#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>;
#include "Stack.h";
using namespace std;
class linkedlist
{
	

public:
	struct Node
	{
		Node *next = NULL;
		Node *prev = NULL;
		double val ;

	};
	Node *head=NULL;
	Node * trav = NULL;
	Node * temp = NULL;

	
	

	void insert(double key) {

		Node *newNode = new Node();
		newNode->val = key;
		newNode->next = NULL;

		Node *forw = NULL;
		Node *back = NULL;

		if (head == NULL)
		{
			head = newNode;

		}
		else
		{
			forw = head;
			while (forw)
			{
				back = forw;
				forw = forw->next;
			}
			back->next = newNode;
		}
	}
	
	void removeDuplicate() {

		Node *prev = head;
		Node *temp = NULL;
	
			
				while (prev->next!=NULL)
				{
					
					if (prev->val==prev->next->val)
					{
						temp = prev->next;
						prev->next = temp->next;
						delete temp;
					}
					else
					{
						prev = prev->next;

					}
					
					
				}
			
		
	}

	/*void insert(double key) {

		Node *newNode = new Node();
		newNode->val = key;
		newNode->next = NULL;

		Node *forw = NULL;
		Node *back = NULL;

		if (head==NULL)
		{
			head = newNode;
			
		}
		else
		{
			forw = head;

			while (forw!=NULL&&forw->val < key)
			{
				back = forw;
				forw = forw->next;
			}

			if (back==NULL)
			{
				head = newNode;
				newNode->next = forw;
				forw->prev = newNode;
			}
			else if (forw!= NULL)
			{
				back->next = newNode;
				newNode->next = forw;
				forw->prev = newNode;
			}
			else
			{
				back->next = newNode;
			
			}


		}

		
	}*/
	

	void display() {

		Node *trav = head;
		while (trav != NULL)
		{
			std::cout << trav->val << ">>";
			trav = trav->next;
		}


	}
	void deletenode(double key) {

		Node * frwd=head;
		Node * prev = NULL;
		Node * store = NULL;


		while (frwd->val!=key &&frwd!= NULL)
		{
			prev = frwd;
			frwd = frwd->next;
		}

		if (frwd->val==head->val)
		{
			store = head;
			head = frwd->next;
			delete store;
		}
		else if (frwd->next!= NULL)
		{
			store = frwd;
			frwd = frwd->next;
			prev->next = frwd;
			frwd->prev = prev;
			delete store;
		}
		else
		{
			prev->next = NULL;
		}


	}
	Node* detectloop(Node *head) {

		Node *p = head;
		Node *q = head;

		while (p&&q&&q->next)
		{
			p = p->next;
			q = q->next->next;
			if (p==q)
			{
				cout << "loop Detected";
				return p;
			}
		}
		cout << "No loop Detected";

		return NULL;
	}


	void middleNode(Node *head) {

		Node *slow = head;
		Node *fast = head;

		while (fast!=NULL&& fast->next!=NULL)
		{
			
				fast = fast->next->next;
					slow = slow->next;
			
		
		}

		cout << "Middle Node is :" << slow->val;
	}

	void removeLoop(Node *p, Node *head) {

		Node *q = head;

		while (p->next!=q->next)
		{
			p = p->next;
			q = q->next;
		}

		p->next = NULL;

	}


	void reverseLL(Node *head) {

		
		Node *tmp = NULL;
		Node *ptr = head;
		while (ptr->val != 10) {
			tmp = ptr->next;
			ptr->next = ptr->prev;
			ptr->prev = tmp;
			if (tmp==NULL) {
				head = ptr;
				break;
			}
			
			ptr = tmp;
		}
		display();
	}
};
#endif