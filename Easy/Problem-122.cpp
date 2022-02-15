#include <gtest/gtest.h>

/**
 * Say you have an array prices for which the ith element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).
 *
 * Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
 */

#include <iostream>
int maxProfit(std::vector<int> &prices) {
    int profit = 0;
    for(uint32_t buy = 0; buy < prices.size(); ++buy) {
        // find the best time to sell, as long as there is an increment in the stock
        // price move to the next position
        uint32_t sell = buy + 1;
        while(sell < prices.size() && prices[sell - 1] < prices[sell]) ++sell;
        // NOTE: since the sell variable holds the position after the actual
        // best selling point, just decrement it by one prior to checking to usage
        --sell;
        // check that the sell price is really higher than the buy price
        if(prices[buy] < prices[sell]) {
            // save the current profit
            profit += prices[sell] - prices[buy];
            // and move the buy position
            buy = sell;
        }
    }
    return profit;
}

int _maxProfit(std::vector<int> &prices) {
    int profit = 0;
    for(uint32_t ind = 1; ind < prices.size(); ++ind) {
        if(prices[ind] > prices[ind - 1])
            profit += (prices[ind] - prices[ind - 1]);
    }
    return profit;
}

TEST(PROBLEM_122, Example1) {
    std::vector<int> prices{7,1,5,3,6,4};
    ASSERT_EQ(7, maxProfit(prices));
    ASSERT_EQ(7, _maxProfit(prices));
}

TEST(PROBLEM_122, Example2) {
    std::vector<int> prices{1,2,3,4,5};
    ASSERT_EQ(4, maxProfit(prices));
    ASSERT_EQ(4, _maxProfit(prices));
}

TEST(PROBLEM_122, Example3) {
    std::vector<int> prices{7,6,4,3,1};
    ASSERT_EQ(0, maxProfit(prices));
    ASSERT_EQ(0, _maxProfit(prices));
}
