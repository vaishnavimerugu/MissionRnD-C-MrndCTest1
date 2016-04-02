/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Return Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};
void mergeNode(struct node **dest, struct node **source)
{
	struct node *current = *source;
	if (current != NULL)
	{
		*source = current->next;
		current->next = *dest;
		*dest = current;
	}
}
void make_it_circular1(struct node *head){
	struct node *temp = head;
	while (head->next != NULL){
		head = head->next;
	}
	head->next = temp;
}
struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	
	struct node temp,*curr1=head1,*curr2=head2;
	struct node *result = &temp;
	temp.next = NULL;
	while (1)
	{
		
		if (head1 == NULL)
		{
			result->next = head2;
			break;
		}
		else if (head2 == NULL)
		{
			result->next = head1;
			break;
		}
		if (head1->data <= head2->data)
		{
			mergeNode(&(result->next), &head1);
		}
		else
		{
			mergeNode(&(result->next), &head2);
		}
		result = result->next;
	}
	return(temp.next);
}

int merge_circularlists(struct node **head1, struct node **head2){
	//Returns Length of merged Sorted circular SLL and also points *head1 to final SLL .
	if (*head1==NULL&&*head2==NULL)
	return -1;
	struct node *curr1 = *head1, *curr2 = *head2;
	int len1 = 1, len2 = 1;
	while (curr1->next != *head1)
	{
		curr1 = curr1->next;
		len1++;
	}
	while (curr2->next != *head2)
	{
		curr2 = curr2->next;
		len2++;
	}
	if (*head1 == NULL)
	{
		*head1 = *head2;
		return len2;
	}
	if (head2 == NULL)
		return len1;
	curr1->next = NULL;
	curr2->next = NULL;
	int count = 0;
	*head1=merge2LinkedLists(*head1, *head2);
	make_it_circular1(*head1);
	return len1+len2;
}