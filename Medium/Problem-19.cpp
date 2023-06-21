#include <gtest/gtest.h>

#include <LinkedList.h>

/**
 * Given the 'head' of a linked list, remove the 'nth' node from the end of the list and return its head.
 */

ListNode* removeNthFromEnd(ListNode* head, int32_t n) {
   // A dummy node is used before the head, this helps when the head is going to be removed
   auto dummy = new ListNode(0, head);
   // The two pointers approach is used here, the first pointer uses the dummy
   // pointer and the second pointer uses the actual head, so the first pointer
   // is one step behind, which is needed to remove the right element from the list
   ListNode *first = dummy, *second = head;
   // Move the second pointer ahead as many places as n tells
   while(n-- > 0 && nullptr != second) {
      second = second->next;
   }
   // Now move the two pointers until the second pointer reaches the end
   while(nullptr != second) {
      first = first->next;
      second = second->next;
   }
   // The first pointer is behind the actual value that has to be removed, use a temp
   // pointer so that the memora can be released correctly
   ListNode* tmp = first->next;
   first->next = first->next->next;
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
