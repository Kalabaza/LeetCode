#include <gtest/gtest.h>

#include "LinkedList.h"

#include <vector>

/**
 * You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
 *
 * Merge all the linked-lists into one sorted linked-list and return it.
 */

// This is basically the code used in the Problem 21, since it merges
// two sorted lists, so this can de used to sort N lists.
ListNode<>* mergeList(ListNode<>* list1, ListNode<>* list2) {
    // Using a dummy head, to insert the values and return the new head of the
    // merged LinkedLists
    ListNode<>* head = new ListNode();
    ListNode<>* tail = head;

    while(nullptr != list1 && nullptr != list2) {
        // Move the smallest value to the new list and move
        // that list one element ahead
        if(list1->val() < list2->val()) {
            tail->next(list1);
            list1 = list1->next();
        }
        else {
            tail->next(list2);
            list2 = list2->next();
        }
        // Move the tail to the new last element
        tail = tail->next();
    }
    
    // There can be remaining elements on either one list,
    // so just move them to the tail
    if(nullptr != list1)
        tail->next(list1);
    if(nullptr != list2)
        tail->next(list2);
    
    // Return the new head of the LinkedList
    return head->next();
}

ListNode<>* mergeKLists(std::vector<ListNode<>*>& lists) {
    // If the vector is empty, return an empty LinkedList
    if(lists.size() == 0)
        return nullptr;
        
    while(lists.size() > 1) {
        // Get two lists from the vector and merge them
        auto list1 = lists.back();
        lists.pop_back();
        auto list2 = lists.back();
        lists.pop_back();
        lists.push_back(mergeList(list1, list2));
    }
    // At the end there will be only one list
    return lists[0];
}

TEST(PROBLEM_23, Example_1) {
    std::vector<ListNode<>*> linkedLists{makeList({1,4,5}),makeList({1,3,4}),makeList({2,6})};
    std::vector<int32_t> expected{1,1,2,3,4,4,5,6};

    auto result = mergeKLists(linkedLists);

    ASSERT_EQ(expected, listToVector(result));
}

TEST(PROBLEM_23, Example_2) {
    std::vector<ListNode<>*> linkedLists{};
    std::vector<int32_t> expected{};
    
    auto result = mergeKLists(linkedLists);

    ASSERT_EQ(expected, listToVector(result));
}