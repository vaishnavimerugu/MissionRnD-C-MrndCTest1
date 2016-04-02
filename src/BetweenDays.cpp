/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};

int between_days(struct node *date1head, struct node *date2head){
	if (date1head==NULL||date2head==NULL)
	return -1;
	int day1, mon1, yr1, day2, mon2, yr2;
	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	struct node *curr1 = date1head,*curr2=date2head;
	for (int i = 0; i < 8; i++)
	{
		if (i == 0)
		{
			day1 = 10*curr1->data;
			day2 = 10*curr2->data;
		}
		if (i == 1)
		{
			day1 += curr1->data;
			day2 += curr2->data;
		}
		if (i == 2)
		{
			mon1 = 10 * curr1->data;
			mon2 = 10 * curr2->data;
		}
		if (i == 3)
		{
			mon1 += curr1->data;
			mon2 += curr2->data;
		}
		if (i == 4)
		{
			yr1 = 1000 * curr1->data;
			yr2 = 1000 * curr2->data;
		}
		if (i == 5)
		{
			yr1 += 100 * curr1->data;
			yr2 += 100 * curr2->data;
		}
		if (i == 6)
		{
			yr1 += 10 * curr1->data;
			yr2 += 10 * curr2->data;
		}
		if (i == 7)
		{
			yr1 += curr1->data;
			yr2 +=curr2->data;
		}
		curr1 = curr1->next;
		curr2 = curr2->next;
	}
	printf("%d %d %d\n%d %d %d\n", day1, mon1, yr1, day2, mon2, yr2);
	if (day2 - day1 <= 1 && mon2 - mon1 == 0 && yr2 - yr1 == 0)
		return 0;
	int count1 = yr1 * 365 + day1;
	int count2 = yr2 * 365 + day2;
	for (int i = 0; i < mon1-1; i++)
		count1 += month[i];
	for (int i = 0; i < mon2 - 1;i++)
		count2 += month[i];
	if (mon1 <= 2)
		yr1--;
	if (mon2 <= 2)
		yr2--;
	count1 += (yr1 / 4 + yr1 / 400 - yr1 / 100);
	count2 += (yr2 / 4 + yr2 / 400 - yr2 / 100);
	printf("%d %d\n", count1, count2);
	return count2 - count1-1;
}