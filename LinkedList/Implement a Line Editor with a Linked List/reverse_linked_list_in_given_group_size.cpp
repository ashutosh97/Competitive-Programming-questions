// C++ program to reverse a linked list in groups
// of given size
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node {
	public:
	int data;
	class Node* next;
};

/* Reverses the linked list in groups of size k
and returns the pointer to the new head node. */
class Node* Reverse(class Node* head, int k)
{
	// Create a stack of Node*
	stack<Node*> mystack;
	Node* current = head;
	Node* prev = NULL;

	while (current != NULL) {

		// Terminate the loop whichever comes first
		// either current == NULL or count >= k
		int count = 0;
		while (current != NULL && count < k) {
			mystack.push(current);
			current = current->next;
			count++;
		}

		// Now pop the elements of stack one by one
		while (mystack.size() > 0) {

			// If final list has not been started yet.
			if (prev == NULL) {
				prev = mystack.top();
				head = prev;
				mystack.pop();
			} else {
				prev->next = mystack.top();
				prev = prev->next;
				mystack.pop();
			}
		}
	}

	// Next of last element will point to NULL.
	prev->next = NULL;

	return head;
}

/* UTILITY FUNCTIONS */
/* Function to push a node */
void append( Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node = new Node();
     Node *last = *head_ref;
	/* put in the data */
	new_node->data = new_data;
    new_node->next = NULL;
	/* to add the first element */
	if( (*head_ref) == NULL)
    {
        *head_ref = new_node;
        return;
    }

    /* to append the nodes at end*/
    while(last->next != NULL)
    last = last->next;
    last->next = new_node;

    return;
}

/* Function to print linked list */
void printList(Node* node)
{
	while (node != NULL) {
		cout<<node->data<<"\t";
		node = node->next;
	}
}

/* Driver program to test above function*/
int main()
{
	/* Start with the empty list */
	 Node* head = NULL;

	/* Created Linked list is 1->2->3->4->5->6->7->8->9 */
	append(&head, 1);
	append(&head, 2);
	append(&head, 3);
	append(&head, 4);
	append(&head, 5);
	append(&head, 6);
	append(&head, 7);
	append(&head, 8);
	append&head, 9);
    append(&head, 10);
	append("\nGiven linked list \n");
	printList(head);
	head = Reverse(head, 3);

	printf("\nReversed Linked list \n");
	printList(head);

	return 0;
}
