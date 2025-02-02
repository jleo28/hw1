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

// simple print test function
void printTest(Node* toPrint){
    while(toPrint){
        cout << toPrint->value;
        cout << " ";
        toPrint = toPrint->next;
    }
    cout << "this is the end of the list" << endl;
}

// simple append test function
void appendTest(Node*& head, int n)
{
  // validation check where the list is empty
  if(head == nullptr){
    head = new Node(n, nullptr);
  }
  // iterates to the end of the list and attaches the new item as newNode at the end
  else{
    Node* temp = head;
    while(temp->next != nullptr){
      temp = temp->next;
    }
    temp->next = new Node(n, nullptr);
  }
}

int main(int argc, char* argv[])
{
    Node* in = nullptr;
    for(int i = 0; i < 16; i++){
        appendTest(in, i);
    }

    Node* odds = nullptr;
    Node* evens = nullptr;

    split(in, odds, evens);

    cout << "Evens: ";
    printTest(evens);
    cout << endl;

    cout << "Odds: ";
    printTest(odds);
    cout << endl;

    cout << "Ins: ";
    printTest(in);
    cout << endl;

    while(odds){
        Node* temp = odds;
        odds = odds->next;
        delete temp;
    }

    while(evens){
        Node* temp = evens;
        evens = evens->next;
        delete temp;
    }

    return 0;
}
