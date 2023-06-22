#pragma once

#include <iostream>
#include <vector>

template <typename T>
class ListNode {
private:
   T val_;
   ListNode *next_;
public:
   ListNode() : val_(0), next_(nullptr) {}
   ListNode(T val) : val_(val), next_(nullptr) {}
   ListNode(T val, ListNode *next) : val_(val), next_(next) {}

   void next(ListNode *next) { next_ = next; }
   ListNode *next() { return next_; }

   void val(T value) { val_ = value; }
   T val() { return val_; }
};

template <typename T>
inline ListNode<T>* makeList(std::vector<T> values) {
   if(values.empty())
      return nullptr;
   ListNode<T>* head = new ListNode<T>(values[0]);
   ListNode<T>* cur = head;
   for(size_t index = 1; index < values.size(); ++index) {
      ListNode<T>* tmp = new ListNode<T>(values[index]);
      cur->next(tmp);
      cur = tmp;
   }
   return head;
}

template <typename T>
inline void deleteList(ListNode<T>* head) {
   while(nullptr != head) {
      auto cur = head;
      head = head->next();
      delete cur;
   }
}

template <typename T>
inline std::vector<int32_t> listToVector(ListNode<T>* head) {
   std::vector<int32_t> values;
   auto cur = head;
   while(nullptr != cur) {
      values.push_back(cur->val());
      cur = cur->next();
   }
   return values;
}

template <typename T>
inline void printList(ListNode<T>* head) {
   while(nullptr != head) {
      std::cout << head->val() << "->";
      head = head->next();
   }
   std::cout << "nullptr" << std::endl;
}
