/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>
/* Add a prototype for a helper function here if you need */
void sort(Node*& head)
{
  int temp =0;
  if(head->next==NULL) return;
  if(head->next->value < head->value)
  {
    temp = head->next->value;
    head->next->value = head->value;
     head->value = temp;
  }
  sort(head->next);
}

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
if(in==NULL) return;
if(in->value%2==0) 
{
  evens->value = in->value;
  evens->next = new Node(3,NULL);
  split(in->next,odds,evens->next);
}
if(in->value%2==1)
{
  odds->value = in->value;
  odds->next = new Node(2,NULL);
  split(in->next,odds->next,evens);
}
if(evens->next!=NULL&&evens->next->value%2!=0)
{
  delete evens->next;
  evens->next=NULL;
}
if(odds->next!=NULL&&odds->next->value%2==0)
{
  delete odds->next;
  odds->next=NULL;
}
sort(odds);
sort(evens);
delete in;
}
/* If you needed a helper function, write it here */
