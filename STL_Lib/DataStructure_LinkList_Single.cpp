#include<iostream>
using namespace std; 

/************* Linked List Insertion ******************/
//class Node {
//public:
//	int Value;
//	Node* Next;
//};
//
//void print(Node* ptr) {
//	//way 1
//	/*cout << ptr->Value<<endl;
//	cout << ptr->Next->Value << endl;
//	cout << ptr->Next->Next->Value << endl;*/
//
//	//way 2
//	while (ptr != NULL) {
//		cout << ptr->Value << endl;
//		ptr= ptr->Next;
//	}
//}
///* Insertion of at the begin of Linked List */
//void pushFront(Node** head_ref,int val) {// recieve a pointer of pointer and int
//	// prep a new node
//	Node* newNode = new Node();
//	newNode->Value = val;
//	// put in front of current head
//	newNode->Next = *head_ref;
//	 // move head of the list to point to the val
//	*head_ref = newNode;
//}
///* Insertion of at given node of Linked List */
//void pushAfter(Node* previous, int val) {
//	// check if its NULL 
//	if (previous == NULL) {
//		cout << "Previous can't be NULL! '\n'";
//	}
//	
//	// prepare a new node
//	Node* newNode = new Node();
//	newNode->Value = val;
//	// insert after previous
//	newNode->Next= previous->Next;
//	previous->Next = newNode;
//}
///* Insertion of at the end of Linked List */
//void pushEnd(Node** head_ref, int val) {
//	// prep a new node
//	Node* newNode = new Node();
//	newNode->Value = val;
//	newNode->Next = NULL; // bcuz last node points to null
//	// If linked list is empty, new node will be the head node
//	if (*head_ref == NULL) {
//		*head_ref = newNode;
//	}
//	// find the last node
//	Node* last = *head_ref;// assign head to first and iterating until  the last is null
//	while (last->Next != NULL) {
//		last = last->Next;
//	}
//	// insert after last node
//	last->Next = newNode;
//}
//int main() {
//	// create new object 
//	Node* head = new Node();
//	Node* second = new Node();
//	Node* third = new Node();
//
//	head->Value = 10;
//	head->Next = second;
//	second->Value = 15;
//	second->Next = third;
//	third->Value = 20;
//	third->Next = NULL;
//
//	
//	// uncomment it and test each case 
//	//pushFront(&head,5);// passing addr of a pointer and its value
//	//pushEnd(&head, 5);
//	pushAfter(second, 5);
//	print(head);
//	return 0;
//}

/************* Linked List Deletion  ******************/
/*  deletion at given value/key */
//// A linked list node
//class Node {
//public:
//    int data;
//    Node* next;
//};
//
//// Given a reference (pointer to pointer)
//// to the head of a list and an int,
//// inserts a new node on the front of the
//// list.
//void push(Node** head_ref, int new_data)
//{
//    Node* new_node = new Node();
//    new_node->data = new_data;
//    new_node->next = (*head_ref);
//    (*head_ref) = new_node;
//}
//
//// Given a reference (pointer to pointer)
//// to the head of a list and a key, deletes
//// the first occurrence of key in linked list
//void deleteNode(Node** head_ref, int key)
//{
//
//    // Store head node
//    Node* temp = *head_ref;
//    Node* prev = NULL;
//
//    // If head node itself holds
//    // the key to be deleted
//    if (temp != NULL && temp->data == key)
//    {
//        *head_ref = temp->next; // Changed head
//        delete temp;            // free old head
//        return;
//    }
//
//    // Else Search for the key to be deleted,
//    // keep track of the previous node as we
//    // need to change 'prev->next' */
//    else
//    {
//        while (temp != NULL && temp->data != key)
//        {
//            prev = temp;
//            temp = temp->next;
//        }
//
//        // If key was not present in linked list
//        if (temp == NULL)
//            return;
//
//        // Unlink the node from linked list
//        prev->next = temp->next;
//
//        // Free memory
//        delete temp;
//    }
//}
//
//// This function prints contents of
//// linked list starting from the
//// given node
//void printList(Node* node)
//{
//    while (node != NULL)
//    {
//        cout << node->data << " ";
//        node = node->next;
//    }
//}
// Driver code
//int main()
//{
//    // Start with the empty list
//    Node* head = NULL;
//
//    // Add elements in linked list
//    push(&head, 7);
//    push(&head, 1);
//    push(&head, 3);
//    push(&head, 2);
//
//    puts("Created Linked List: ");
//    printList(head);
//
//    deleteNode(&head, 1);
//    puts("\nLinked List after Deletion of 1: ");
//
//    printList(head);
//
//    return 0;
//}
/*  deletion at given position */

// A linked list node
class Node
{
public:
    int data;
    Node* next;
};

// Given a reference (pointer to pointer) to
// the head of a list and an int inserts a
// new node on the front of the list.
void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Given a reference (pointer to pointer) to
// the head of a list and a position, deletes
// the node at the given position
void deleteNode(Node** head_ref, int position)
{

    // If linked list is empty
    if (*head_ref == NULL)
        return;

    // Store head node
    Node* temp = *head_ref;

    // If head needs to be removed
    if (position == 0)
    {

        // Change head
        *head_ref = temp->next;

        // Free old head
        free(temp);
        return;
    }

    // Find previous node of the node to be deleted
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    // If position is more than number of nodes
    if (temp == NULL || temp->next == NULL)
        return;

    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    Node* next = temp->next->next;

    // Unlink the node from linked list
    free(temp->next); // Free memory

    // Unlink the deleted node from list
    temp->next = next;
}

// This function prints contents of linked
// list starting from the given node
void printList(Node* node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

// Driver code
int main()
{

    // Start with the empty list
    Node* head = NULL;

    push(&head, 7);
    push(&head, 1);
 /*   push(&head, 3);
    push(&head, 2);
    push(&head, 8);*/

    cout << "Created Linked List: ";
    printList(head);
    deleteNode(&head, 1);
    cout << "\nLinked List after Deletion : ";
    printList(head);
    return 0;
}