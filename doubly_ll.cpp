#include<bits/stdc++.h>
using namespace std;

int main()
{ 
    // start coding...
    #include<bits/stdc++.h>
using namespace std;

class DoublyNode
{
public:
	int data;
	DoublyNode* next;
	DoublyNode* prev;
};

void pushAtBack(DoublyNode** head, int element)
{
	DoublyNode* new_node = new DoublyNode();
	DoublyNode* current = *head;

	new_node->data = element;
	new_node->next = NULL;

	if(*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return;
	}

	while(current->next != NULL)
		current = current->next;

	current->next = new_node;
	new_node->prev = current;
	return;
}

void pushAtFront(DoublyNode** head, int element)
{
	DoublyNode* new_node = new DoublyNode();
	new_node->data = element;
	new_node->prev = NULL;
	new_node->next = *head;
	*head = new_node;
	return;
}

void pushInBetween(DoublyNode** head, int prev_element, int element)
{
	DoublyNode* new_node = new DoublyNode();
	DoublyNode* current = *head;
	new_node->data = element;

	while(current->data != prev_element)
		current = current->next;

	new_node->next = current->next;
	current->next->prev = new_node;
	current->next = new_node;
	new_node->prev = current;
	return;
}

void deleteElement(DoublyNode** head, int element)
{
	DoublyNode* current = *head;

	if(current->data == element)
	{
		current->next->prev = NULL;
		*head = current->next;
		return;
	}

	while(current->data != element)
		current = current->next;

	if(current->next == NULL)
	{
		current->prev->next = NULL;
		return;
	}

	current->prev->next = current->next;
	current->next->prev = current->prev;
	return;
}

void printList(DoublyNode* node)
{
	cout << "Doubly Linked List : ";
	while(node != NULL)
	{
		cout << node->data << " <=> ";
		node = node->next;
	}
	if(node == NULL)
		cout << "NULL";

	return;
}

int main()
{
	DoublyNode* head = NULL;

	int choice, element, prev_element;
	bool exit = false;
	do
	{
		cout << "\n\n --- MENU ---";
		cout << "\n1. Push at back";
		cout << "\n2. Push at front";
		cout << "\n3. Push in between";
		cout << "\n4. Delete an element";
		cout << "\n5. Exit";
		cout << "\n\n Enter your choice: ";
		cin >> choice;

		switch(choice)
		{
			case 1:	cout << "Enter the element to be pushed at back: ";
					cin >> element;
					pushAtBack(&head, element);
					printList(head);
					break;

			case 2:	cout << "Enter the element to be pushed at front: ";
					cin >> element;
					pushAtFront(&head, element);
					printList(head);
					break;

			case 3:	cout << "Enter the element to be pushed: ";
					cin >> element;
					cout << "Enter the element after which the above element is to be inserted: ";
					cin >> prev_element;
					pushInBetween(&head, prev_element, element);
					printList(head);
					break;

			case 4:	cout << "Enter the element to be deleted: ";
					cin >> element;
					deleteElement(&head, element);
					printList(head);
					break;

			case 5:	exit = true;
					break;

			default:cout << "Enter a valid choice" << endl;
					break;
		}
	}while(!exit);
	return 0;
}
}
