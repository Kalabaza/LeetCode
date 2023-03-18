#include <gtest/gtest.h>

#include <LinkedList.h>

/**
 * Given the 'head' of a linked list, remove the 'nth' node from the end of the list and return its head.
 */

ListNode* removeNthFromEnd(ListNode* head, int32_t n) {
   // A dummy node is used before the head
   auto dummy = new ListNode(0, head);
   // The two pointers approach is used here
   ListNode *left = dummy, *right = head;
   // Move one pointer ahead as many places as n tells
   while(n-- > 0 && nullptr != right) {
      right = right->next;
   }
   // Now move the two pointers until the further pointer reaches the end
   while(nullptr != right) {
      left = left->next;
      right = right->next;
   }
   // The first pointer is behind the actual value that has to be removed
   ListNode* tmp = left->next;
   left->next = tmp->next;
   delete tmp;
   return dummy->next;
}

TEST(PROBLEM_19, Example_1) {
   auto input = makeList({1,2,3,4,5});
   constexpr int32_t n = 2;
   const std::vector<int32_t> output{1,2,3,5};
   input = removeNthFromEnd(input, n);
   ASSERT_EQ(listToVector(input), output);
   deleteList(input);
}

TEST(PROBLEM_19, Example_2) {
   auto input = makeList({1});
   constexpr int32_t n = 1;
   const std::vector<int32_t> output{};
   input = removeNthFromEnd(input, n);
   ASSERT_EQ(listToVector(input), output);
   deleteList(input);
}

TEST(PROBLEM_19, Example_3) {
   auto input = makeList({1,2});
   constexpr int32_t n = 1;
   const std::vector<int32_t> output{1};
   input = removeNthFromEnd(input, n);
   ASSERT_EQ(listToVector(input), output);
   deleteList(input);
}
