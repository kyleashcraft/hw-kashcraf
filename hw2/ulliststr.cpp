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

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(NULL == ptr){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(NULL == ptr){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(NULL == ptr){
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

void ULListStr::push_back(const std::string& val){
  if(size_ == 0){ //if list is empty

    head_ = new Item; //create new list item in head space
    tail_ = head_; //also make tail point there

    head_->val[0] = val; //assign string to the first item in the array
    head_->last++; //increment last to maintain indexing
    size_++; //increment size since a new item is being added

  } else if (size_ > 0 && tail_->last != ARRSIZE){ 

    //if there is a preexisting list containing a list with open spots...
    
    tail_->val[tail_->last] = val; //add item to the next available spot
    tail_->last++; //increment last to ensure indexing remains correct
    size_++; //increment size for accuracy

  } else if (size_ > 0 && tail_->last == ARRSIZE) {

    //if there is a preexisting list but the last Item's list is full...

    tail_->next = new Item; // make its tail point to a new item
    tail_->next->prev = tail_; // make sure new tail links to current before switching
    tail_ = tail_->next; // change the tail to the new item

    tail_->val[0] = val; //set the first value in the new item
    tail_->last++; //increment the 'last' index to maintain indexing
    size_++; //increment size for accuracy

  }
}

void ULListStr::pop_back(){
  if(size_ == 0){ //if the list is empty return
    return;
  } else if (size_ > 0) { //if list is not empty
    tail_->val[tail_->last-1] = ""; //clear the last value
    tail_->last--;
    size_--; //decrement size

    if(size_ == 0){ //if the list is empty return
      clear();
      return;
    }

    if(tail_->last == 0 && tail_->first == 0){ //if this clears that items list
      tail_ = tail_->prev; //move the tail to back in the list
      delete tail_->next; //delete the previous tail
      tail_->next = NULL;
    }
  }
};

void ULListStr::push_front(const std::string& val){
  if(size_ == 0){ //if list is empty
    head_ = new Item; //create new list item in head space
    tail_ = head_; //also make tail point there

    head_->val[0] = val; //assign string to the first item in the array
    head_->last++; //increment last to maintain indexing
    size_++; //increment size since a new item is being added
  } else if (size_ > 0 && head_->first > 0){ //if the head has room add it
    head_->val[head_->first-1] = val;
    head_->first--;
    size_++;
  } else if (size_ > 0 && head_->first == 0){ //if the head doesn't have room, allocate a new item and put it there
    head_->prev = new Item;
    head_->prev->next = head_;
    head_ = head_->prev;
    head_->val[ARRSIZE-1] = val;
    head_->first = ARRSIZE-1;
    head_->last = ARRSIZE;
    size_++;
  }
};

void ULListStr::pop_front(){
  if (size_ == 0){ //if pop_front() is called on an empty list just return
    return;
  } else if (size_ > 0){ //if list isn't empty clear the first item in it
    head_->val[head_->first] = ""; 
    head_->first++;
    size_--;
    
    if (size_ == 0){ //if removing that string empties the list, clear it 
      clear();
      return;
    }
    if(head_->first == ARRSIZE && size_ > 0){ //if removing that string empties the item, delete it and change the head
      head_ = head_->next;
      delete head_->prev;
    }
  }

};

std::string const & ULListStr::back() const{ //return last item
  return tail_->val[tail_->last-1];
};


std::string const & ULListStr::front() const{ //return first item
  return head_->val[head_->first];
};


std::string* ULListStr::getValAtLoc(size_t loc) const{
  if(loc >= size_ || size_ == 0) return NULL; 

  Item* mov_ = head_; //temp moving pointer
    
    while (loc > (mov_->last-mov_->first-1) ){
      loc -= (mov_->last)-(mov_->first);
      mov_=mov_->next;
    }
    
    std::string* str =  &mov_->val[loc+mov_->first];
    return str;

};


std::string* ULListStr::returnVal(size_t loc) const{ //wrapper function to access private getValAtLoc for testing
  return getValAtLoc(loc);
};