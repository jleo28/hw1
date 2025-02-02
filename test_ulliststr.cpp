#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

using namespace std;

// use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
// creates the new unrolled linked list instance
ULListStr* list1 = new ULListStr();
cout << "push back test" << endl;
// adding to an empty list
list1->push_back("0");
cout << "push back to empty list" << endl;
cout << "current list: ";
for (int i = 0; i < list1->size(); i++) {
    cout << list1->get(i) << " ";
}
cout << endl;
cout << "last element: " << list1->back() << endl;
// adding when there is space available
for (int i = 1; i <= 9; i++) {
    list1->push_back(to_string(i));
}
cout << "push when there is space available" << endl;
cout << "current list: ";
for (int i = 0; i < list1->size(); i++) {
    cout << list1->get(i) << " ";
}
cout << endl;
cout << "last element: " << list1->back() << endl;
// adding where there is no space (should return an exception)
cout << "push when no space left" << endl;
list1->push_back("7");
cout << "current list: ";
for (int i = 0; i < list1->size(); i++) {
    cout << list1->get(i) << " ";
}
cout << endl;
cout << "last element: " << list1->back() << endl;
cout << endl;
cout << "pop back test" << endl;
// remove multiple items
for (int i = 0; i < 9; i++) {
    list1->pop_back();
}
cout << "remove while previous items" << endl;
cout << "current list: ";
for (int i = 0; i < list1->size(); i++) {
    cout << list1->get(i) << " ";
}
cout << endl;
cout << "last element: " << list1->back() << endl;
// remove the last item
list1->pop_back();
cout << "removing the last item" << endl;
cout << "current list: ";
// remove from an empty list (should return an exception)
ULListStr* list2 = new ULListStr();
cout << "remove from empty list" << endl;
list2->pop_back();
cout << "current list: ";
cout << endl;
cout << "push front test" << endl;
ULListStr* list3 = new ULListStr();
// adding to empty list
list3->push_front("3");
cout << "add to empty list" << endl;
cout << "current list: " << endl;
for (int i = 0; i < list3->size(); i++) {
    cout << list3->get(i) << " ";
}
cout << "first element: " << list3->front() << endl;
// add when there is no space before first index (should return an exception)
list3->push_front("18");
cout << "adding to front where no space" << endl;
cout << "current list: " << endl;
for (int i = 0; i < list3->size(); i++) {
    cout << list3->get(i) << " ";
}
cout << "first element: " << list3->front() << endl;
// add when space is available before first index
for (int i = 2; i <= 10; i++) {
    list3->push_front(to_string(i));
}
cout << "add to front when space is available" << endl;
cout << "current list: " << endl;
for (int i = 0; i < list3->size(); i++) {
    cout << list3->get(i) << " ";
}
cout << "first element: " << list3->front() << endl;
cout << "test pop front" << endl;
// remove when multiple items exist
for (int i = 0; i < 9; i++) {
    list3->pop_front();
}
cout << "remove items when multiple items exist" << endl;
cout << "current list: " << endl;
for (int i = 0; i < list3->size(); i++) {
    cout << list3->get(i) << " ";
}
cout << "first element: " << list3->front() << endl;
// remove the last item when it is the last node also
list3->pop_front();
cout << "removing last element in head with no next" << endl;
cout << "current list: ";
// remove from an empty list (should throw an exception)
ULListStr* list3 = new ULListStr();
cout << "removing from empty list" << endl;
list3->pop_front();
cout << "current list: ";
cout << "test front and back" << endl;
ULListStr* list4 = new ULListStr();
list4->push_back("1");
list4->push_front("2");
list4->push_back("3");
list4->push_front("4");
cout << "current list: ";
for (int i = 0; i < list4->size(); i++) {
    cout << list4->get(i) << " ";
}
cout << endl;
cout << "first element: " << list4->front() << endl;
cout << "last element: " << list4->back() << endl;
// free allocated memory
delete list1;
delete list2;
delete list3;
delete list3;
delete list4;
return 0;
}
