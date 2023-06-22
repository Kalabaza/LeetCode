#include <gtest/gtest.h>

#include "LinkedList.h"

#include <vector>

/**
 * You are given the heads of two sorted linked lists list1 and list2.
 *
 * Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
 * 
 * Return the head of the merged linked list.
 */

template <typename T>
void moveValue(ListNode<T>** head, ListNode<T>** cur, ListNode<T>** list) {
    if(nullptr == *head) {
        *head = *cur = *list;
        *list = (*list)->next();
        (*cur)->next(nullptr);
    }
    else {
        (*cur)->next(*list);
        *cur = (*cur)->next();
        *list = (*list)->next();
        (*cur)->next(nullptr);
    }
}

template <typename T>
ListNode<T>* mergeTwoLists(ListNode<T>* list1, ListNode<T>* list2) {
    ListNode<T> *head = nullptr, *cur = nullptr;

    while(nullptr != list1 && nullptr != list2) {
        if (list1->val() < list2->val()) {
            moveValue(&head, &cur, &list1);
        }
        else {
            moveValue(&head, &cur, &list2);
        }
    }

    if(nullptr != list1) {
        if(nullptr == head) {
            head = list1;
        }
        else {
            cur->next(list1);
        }
    }
    else if(nullptr != list2) {
        if(nullptr == head) {
            head = list2;
        }
        else {
            cur->next(list2);
        }
    }

    return head;
}

TEST(PROBLEM_21, Example1) {
    ListNode<int32_t>* L1 = makeList<int32_t>({1,2,4});
    ListNode<int32_t>* L2 = makeList<int32_t>({1,3,4});

    ListNode<int32_t>* expected = makeList<int32_t>({1,1,2,3,4,4});
    ListNode<int32_t>* result = mergeTwoLists(L1, L2);

    ASSERT_EQ(listToVector(expected), listToVector(result));

    deleteList(expected);
    deleteList(result);
}

TEST(PROBLEM_21, Example2) {
    ListNode<int32_t>* L1 = makeList<int32_t>({});
    ListNode<int32_t>* L2 = makeList<int32_t>({});

    ListNode<int32_t>* expected = makeList<int32_t>({});
    ListNode<int32_t>* result = mergeTwoLists(L1, L2);

    ASSERT_EQ(listToVector(expected), listToVector(result));

    deleteList(expected);
    deleteList(result);
}

TEST(PROBLEM_21, Example3) {
    ListNode<int32_t>* L1 = makeList<int32_t>({});
    ListNode<int32_t>* L2 = makeList<int32_t>({0});

    ListNode<int32_t>* expected = makeList<int32_t>({0});
    ListNode<int32_t>* result = mergeTwoLists(L1, L2);

    ASSERT_EQ(listToVector(expected), listToVector(result));

    deleteList(expected);
    deleteList(result);
}