/*
Do Read All questions carefully ,before writing any Code .
Make sure you submit the Code you have written through tool ,
before the submit window Closes .

*****************

Note : Make sure your MSBuild Suceeds before you submit ,or else It will lead to 0 marks .
->If you are stuck on a question or a particular Test case
is failing , Do Solve the Next question .As long as you click on submit at correct time,
your submissions are safe .

**************
There are only Sample Test Cases provided .Your code will also be graded
using Test cases on our end ,So Do think about testcases in all possible ways .

Your score will totally be based on the number of TestCases your programs
have passed on our end ,so if your code just passes sample cases
and fails all testcases at our end ,you will get you 0 marks .

******************
You can fill in the Helper Functions and make use of it
if you want to test from MainMrndCTest1.cpp
******************
All the Best .
*/

#include "FunctionHeadersMrndCTest1.h"
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};
//Start of Helper Functions

struct node * createNode(int num) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = num;
	newNode->next = NULL;
	return newNode;
}

void addNode(struct node **head, int data){
    //Adds a node to head ,Modifies *head if SLL is null
	struct node * cur = createNode(data);
	if (*head == NULL){
		*head = cur;
	}
	else{
		struct node *temp = *head;
		cur->next = temp;
		*head = cur;
	}
}

void printSll(struct node *head,int len){
	int i = 0;
	while (head != NULL){
		printf("%2d ",head->data);
		head = head->next;
		i++;
		if (i >= len){
			break;
		}
	}
}

void make_it_circular(struct node *head){
	struct node *temp = head;
	while (head->next != NULL){
		head = head->next;
	}
	head->next = temp;
}
int is_correct(struct node *head, int *arr, int len){
	int i = 0;
	while (head != NULL){
		int data = head->data;
		if (arr[i] != data){
			return 0;
		}
		else{
			i++;
			head = head->next;
		}

		if (head == NULL){
			return 0;
		}
		if (i == len){
			return 1;
		}
	}
}
//End of Helper Functions

int main(){

	//Test Sequences
	/*int arr[10] = { 1, 2, 3, 5, 10, 15, 30, 60 };
	int *res = find_sequences(&arr[0], 8);
	for (int i = 0; i < 6; i++)
		printf("%d\n", res[i]);*/
	/*int dates[2][8] = { { 2, 2, 0, 5, 1,9,9,6 }, { 0, 9,0,8,1,9,9,6 } };

	struct node *date1head = NULL, *date2head = NULL;
	for (int i = 7; i >= 0; i--){
		addNode(&date1head, dates[0][i]);
		addNode(&date2head, dates[1][i]);
	}

	int days = between_days(date1head, date2head);
	printf("count %d\n", days);*/
	int nums[5] = { 1, 3, 5 };
	int nums2[5] = { 2, 4, 6 };
	//Last 1 is for checking whether A is circular or not .6 should again point to 1
	int ans[10] = { 1, 2, 3, 4, 5, 6, 1 };

	int l1 = 3, l2 = 3, i;
	struct node *head1 = NULL;
	struct node *head2 = NULL;
	for (i = l1 - 1; i >= 0; i--){
		addNode(&head1, nums[i]);
	}
	for (i = l2 - 1; i >= 0; i--){
		addNode(&head2, nums2[i]);
	}
	make_it_circular(head1);
	make_it_circular(head2);

	int len = merge_circularlists(&head1, &head2);
	printf("%d\n", len);
	int check = is_correct(head1, ans, len + 1);
	getchar();

	//Test Circular Linked Lists

    //Test Between Days
	/*
	int dates[2][8] = { { 0, 2, 0, 4, 2, 0, 1, 6 }, { 0, 4, 0, 4, 2, 0, 1, 6 } };

	struct node *date1head = NULL, *date2head = NULL;
	for (int i = 7; i >= 0; i--){
	addNode(&date1head, dates[0][i]);
	addNode(&date2head, dates[1][i]);
	}

	int days = between_days(date1head, date2head);
	printf("Total Days - %d\n",days);
	*/
	//Test Concat4 Strings
}
