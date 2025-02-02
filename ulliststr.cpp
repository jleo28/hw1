#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
std::string const & ULListStr::back() const{
  // returns the last value in the tail pointer
  return tail_->val[tail_->last-1];
}
std::string const & ULListStr::front() const{
  // returns the first value in the head pointer
  return head_->val[head_->first];
}
void ULListStr::push_back(const std::string& val){
  // validation check for if the list is empty + creates a new item
  if(empty()){
    head_ = new Item();
    // tail is head since its the only item
    tail_ = head_;
    // updates the indexes
    head_->first = 0;
    head_->last = 1;
    // stores value at 0 index
    head_->val[0] = val;
    // updates size once everything else is updated
    size_++;
  }
  // else if the list is not empty...
  else{
    // if there's space beyond the last array
    if(tail_->last < ARRSIZE){
      // adds the value of the item behind tail to the tail
      tail_->val[tail_->last] = val;
      // moves index of tail->last one backwards
      tail_->last = (tail_->last) + 1;
      // updates size once everything else is updated
      size_++;
    }
    // case where there's no space
    else{
      // creates the new item
      Item *temp = new Item();
      // updates the indexes
      temp->first = 0;
      temp->last = 1;
      // stores value at 0 index
      temp->val[0] = val;
      // updates the next iteration of temp
      temp->prev = tail_;
      tail_->next = temp;
      tail_ = temp;
      // updates size once everything else is updated
      size_++;
    }
  }
}
void ULListStr::push_front(const std::string& val){
  // validation check for if the list is empty
  if(empty()){
    head_ = new Item();
    tail_ = head_;
    // updates the indexes accordingly
    head_->first = 0;
    head_->last = 1;
    // sets the value of head at 0 index to the actual value    
    head_->val[0] = val;
    // updates size once everything else is updated
    size_++;
  }
  // case for when the list is not empty
  else{
    // if there is space (if first does not start at 0)
    if(head_->first > 0){
      // adds the value of the item before head to the head itself (and updates size accordingly)
      head_->val[(head_->first)-1] = val;
      head_->first = (head_->first)-1;
      size_++;
    }
    // case with no space
    else{
      Item* temp = new Item();
      // iterates through the array and updates the indexes starting at the end one element at a time
      temp->first = ARRSIZE-1;
      temp->last = ARRSIZE;
      temp->val[temp->first] = val;
      temp->next = head_;
      head_->prev = temp;
      // updates the head pointer and adjusts size accordingly
      head_ = temp;
      size_++;
    }
  }
}
void ULListStr::pop_back(){
  // validation check for if the list is empty
  if(empty()){
    return;
  }
  // case where list is not empty
  else{
    if(tail_->first + 1 == tail_->last){
      Item* temp = tail_;
      // if tail isn't the last item, update indexes and adjust size accordingly
      if(tail_->prev != nullptr){
        tail_ = tail_->prev;
        tail_->next = nullptr;
        size_--;
      }
      // case for when tail is the last object
      else{
        tail_ = nullptr;
        head_ = tail_;
        size_--;
      }
      delete temp; // free memory (good)
    }
    else{
      // moves the last index backwards and updates size accordingly
      tail_->last = (tail_->last) - 1;
      size_--;
    }
  }
}
void ULListStr::pop_front(){
  // validation check for if the list is empty
  if(empty()){
    return;
  }
  // case for non-empty list
  else{
    // if there's only one item in the head values
    if(head_->last - 1 == head_->first){
      // if there's another item after the head pointer
      Item* temp = head_;
      if(head_->next != nullptr){
        head_ = head_->next;
        head_->prev = nullptr;
        size_--;
      }
      // case where head is the last item
      else{
        head_ = nullptr;
        tail_ = head_;
        size_--;
      }
      // frees memory
      delete temp;
    }
    // if there's more than one item in head
    else{
      head_->first = (head_->first) + 1;
      size_--;
    }
  }
}
std::string* ULListStr::getValAtLoc(size_t loc) const{
  // edgecase for when loc exceeds the allotted size
  if(loc >= size_){
    return nullptr;
  }
  // iterates through the list
  size_t counter = 0;
  Item* temp = head_;
  while(temp != nullptr){
    // while not the last item go through the array
    for(size_t i = temp->first; i < temp->last; i++){
      // validation check to make sure the value at that address isn't empty
      if(loc == counter){
        // returns the value at the counter
        return &(temp->val[i]);
      }
      // updates the counter
      counter++;
    }
    // traverses the list
    temp = temp->next;
  }
  return nullptr;
}
void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
