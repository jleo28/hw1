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

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
  // validation check where list is empty
  if(in == nullptr){
    return;
  }
  // sets nextNode to come after the node to be inserted (in)
  Node* nextNode = in->next;

  // if node's value isn't even, adds to odds' list
  if(in->value % 2 != 0){
    in->next = odds;
    odds = in;
  }
  
  // else, it has to be even, adds to evens' list
  else{
    in->next = evens;
    evens = in;
  }
  
  // resets in to nullptr
  in = nullptr;
  
  // recursive call to go through the next node
  split(nextNode, odds, evens);
}

/* If you needed a helper function, write it here */
