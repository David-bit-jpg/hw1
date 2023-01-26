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
  if(head==nullptr) return;
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
if(in==nullptr) 
{
  return;
}
if(in->value%2==0)
{
  evens= new Node(3,nullptr);
  evens->value = in->value;
  split(in->next,odds,evens->next);
}
if(in->value%2!=0)
{
  odds= new Node(2,nullptr);
  odds->value = in->value;
  split(in->next,odds->next,evens);
}
sort(odds);
sort(evens);
delete in;
in = NULL;
}
/* If you needed a helper function, write it here */
