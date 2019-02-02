/*
CSCI 104: Homework 2 Problem 6

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even
numbers and the other contains the odd numbers. Students
will receive no credit for non-recursive solutions.
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/
#include <cstddef>
#include <iostream>

#include "split.h"

/* Add a prototype for a helper function here if you need */
void add(Node*& from, Node*& to);

void toEnd(Node*& mov);

void split(Node*& in, Node*& odds, Node*& evens)
{
  if(in == NULL){
    return;
  } else {
    if(in->value % 2 == 0){
      add(in, evens);
    } else if (in->value % 2 == 1){
      add(in, odds);
    }
    split(in, odds, evens);
  }
}

/* If you needed a helper function, write it here */
void add(Node*& in, Node*& to){ 
  Node* temp = in->next; //temp is used to reconnect the in list after redistributing
  Node* mov = NULL;
  if (to == NULL){ //if the list being added to is empty...
    to = in;
    to->next = NULL;
  } else {
    mov = to;
    toEnd(mov); //recursively moves the moving pointer to the end of the list
    mov->next = in;
    mov = mov->next;
    mov->next = NULL;
  }
  in = temp;
}

void toEnd(Node*& mov){ //recursive function moving the item to the node to the end of the list
  if(mov->next == NULL){
    return;
  } else {
    mov = mov->next;
    toEnd(mov);
  }
}
