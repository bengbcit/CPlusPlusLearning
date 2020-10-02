#include <stdio.h>
#include <stdlib.h>	// malloc

struct Node {
	int data;	// int or float doesnt matter
	struct Node* link;
};

/* // simply add a Node
int main() {
	struct Node* head = NULL;
	head = (struct Node*)malloc(sizeof(struct Node));

	head->data = 45;
	head->link = NULL;

	printf("%d", head->data);
	return 0;
}
 */

 /* // not effient way to add a new node (at the end)
int main() {
	struct Node* head = (struct Node*)malloc(sizeof(struct Node));
	head->data = 45;
	head->link = NULL;

	struct Node* Node_2 = (struct Node*)malloc(sizeof(struct Node));
	Node_2->data = 98;
	Node_2->link = NULL;
	head->link = Node_2;

	struct Node* Node_3 = (struct Node*)malloc(sizeof(struct Node));
	Node_3->data = 66;
	Node_3->link = NULL;
	Node_2->link = Node_3;

	return 0;
}
*/

void count_of_nodes(struct Node* head) {
	int count = 0;
	if (head == NULL) printf("Linked List is empty!");
	 
	while (head != NULL) {
		count++;
		head = head->link;
	}
	printf("%d", count);		// output 3
}

int main() {
	struct Node* head = (struct Node*)malloc(sizeof(struct Node));
	head->data = 45;
	head->link = NULL;

	struct Node* current_node = (struct Node*)malloc(sizeof(struct Node));
	current_node->data = 98;
	current_node->link = NULL;
	head->link = current_node;

	current_node = (struct Node*)malloc(sizeof(struct Node));
	current_node->data = 66;
	current_node->link = NULL;
	
	head->link->link = current_node;

	count_of_nodes(head);
	return 0;

}
 
