/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
    Node* head = new Node(0,NULL);
    head->value = 123;
    Node* No1two = new Node(0,NULL);
    No1two->value = 313;
    head->next = No1two;
    Node* No1three = new Node(0,NULL);
    No1three->value = 43;
    No1two->next = No1three;
    Node* No1four = new Node(0,NULL);
    No1four->value = 2;
    No1three->next = No1four;
    Node* No1five = new Node(0,NULL);
    No1five->value = 1;
    No1four->next = No1five;
    Node* No1six = new Node(0,NULL);
    No1six->value = 33;
    No1five->next = No1six;
    Node* odds = new Node(0,NULL);
    Node* evens = new Node(0,NULL);
    split(head,odds,evens);
    // while(odds!=NULL)
    // {
    //     cout<<odds->value<<" ";
    //     odds = odds->next;
    // }
    // cout<<endl;
    // while(evens!=NULL)
    // {
    //     cout<<evens->value<<" ";
    //     evens = evens->next;
    // }
    // cout<<endl;
    Node* next_evens;
    while(evens->next!=NULL)
    {
      cout<<evens->value<<" ";
      next_evens=evens;
      evens=evens->next;
      delete next_evens;
    }
    cout<<evens->value<<" ";
    delete evens;
    cout<<endl;
    Node* next_odds;
    while(odds->next!=NULL)
    {
      cout<<odds->value<<" ";
      next_odds=odds;
      odds=odds->next;
      delete next_odds;
    }
    cout<<odds->value<<" ";
    cout<<endl;
    delete odds;
}
