#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
using namespace std;
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

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}
void ULListStr::push_back(const std::string& val)
{
  if(empty())
  {
    head_ = new Item;
    tail_ = new Item;
    head_->last = 1;
    head_->val[0] = val;
    tail_ = head_;
    size_++;
  }
  else 
  {
    if(tail_->last==ARRSIZE-1)
    {
    Item* temp = new Item;
    temp->val[temp->first] = val;
    temp->last++;
    tail_->next = temp;
    temp->prev = tail_;
    temp->next = nullptr;
    tail_=temp;
    size_++;
    }
    else
    {
    tail_->val[tail_->last] = val;
    tail_->last++;
    size_++;
    }
  }
}
void ULListStr::pop_back()
{
  if(!empty())
  {
    if(size_==1)
    {
      size_=0;
      head_=nullptr;
      tail_=nullptr;
    }
    else
    {
      size_--;
      if(tail_->last==tail_->first+1)
      {
        tail_ = tail_->prev;
        delete tail_->next;
        tail_->next = nullptr;
      }
      else
      {
        tail_->val[tail_->last-1] = "";
        tail_->last-=1;
      }
    }
  }
}
void ULListStr::push_front(const std::string& val)
{
  if(!empty())
  {
    if(head_->first!=0)
    {
      size_++;
      head_->val[head_->first-1] = val;
      head_->first = head_->first-1;
    }
    else
    {
      size_++;
      Item* temp = new Item;
      temp->val[ARRSIZE-1] = val;
      temp->last = ARRSIZE;
      temp->first = ARRSIZE-1;
      head_->prev = temp;
      temp->next = head_;
      head_ = temp;
    }
  }
  else
  {
    head_ = new Item;
    tail_ = new Item;
    size_++;
    Item* temp = new Item;
    temp->val[temp->first] = val;
    temp->last++;
    head_ = temp;
    tail_ = temp;
  }
}
void ULListStr::pop_front()
{
  if(!empty())
  {
    if(size_==1)
    {
      size_=0;
      head_=nullptr;
      tail_=nullptr;
    }
    else
    {
      size_--;
      if(head_->first==head_->last-1)
      {
        head_ = head_->next;
        delete head_->prev;
        head_->prev = nullptr;
      }
      else
      {
        head_->val[head_->first] = "";
        head_->first+=1;
      }
    }
  }
}
std::string const & ULListStr::back() const
{
  return tail_->val[tail_->last-1];
}
std::string const & ULListStr::front() const
{
  return head_->val[head_->first];
}
std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}
std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if(!empty()){
  Item* temp = head_;
  size_t cnt = 0;
  while(temp!=nullptr)
  {
    if(loc>cnt+temp->last-1-temp->first)
    {
      cnt+=temp->last-temp->first;
      if(temp->next!=nullptr)
      temp = temp->next;
    }
    else
    {
      return &temp->val[temp->first+loc-cnt];
    }
  }
  }
  return NULL;

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
