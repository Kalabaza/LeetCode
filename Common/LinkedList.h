#pragma once

#include <iostream>
#include <vector>

struct ListNode {
   int32_t val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int32_t x) : val(x), next(nullptr) {}
   ListNode(int32_t x, ListNode *next) : val(x), next(next) {}
};

inline ListNode* makeList(std::vector<int32_t> values) {
   if(values.empty())
      return nullptr;
   ListNode* head = new ListNode(values[0]);
   ListNode* cur = head;
   for(size_t index = 1; index < values.size(); ++index) {
      ListNode* tmp = new ListNode(values[index]);
      cur->next = tmp;
      cur = tmp;
   }
   return head;
}

inline void deleteList(ListNode* head) {
   while(nullptr != head) {
      auto cur = head;
      head = head->next;
      delete cur;
   }
}

inline std::vector<int32_t> listToVector(ListNode* head) {
   std::vector<int32_t> values;
   auto cur = head;
   while(nullptr != cur) {
      values.push_back(cur->val);
      cur = cur->next;
   }
   return values;
}

inline void printList(ListNode* head) {
   while(nullptr != head) {
      std::cout << head->val << "->";
      head = head->next;
   }
   std::cout << "nullptr" << std::endl;
}
