#include <gtest/gtest.h>

/**
 * You are given an array 'prices' where 'prices[i]' is the price of a given stock on the 'ith' day.
 *
 * You want to maximize your profit by choosing a 'single day' to buy one stock and choosing a 'different day in the
 * future' to sell that stock.
 *
 * Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return '0'.
 */

int32_t maxProfit(const std::vector<int32_t>& prices) {
	int32_t profit = 0;
	for (uint32_t buy = 0, sell = 1; sell < prices.size(); ++sell) {
		// If the price to buy is lower than the price for selling, maybe this is a new high profit.
		if (prices[buy] < prices[sell]) {
			profit = std::max(profit, prices[sell] - prices[buy]);
		}
		// If the price for selling is lower than the price for buying, move the buy position to this new lower price.
		else {
			buy = sell;
		}
	}
	// Return the profit found with the privided prices.
	return profit;
}

TEST(PROBLEM_121, Example1) {
	std::vector<int32_t> prices{ 7,1,5,3,6,4 };
	ASSERT_EQ(5, maxProfit(prices));
}

TEST(PROBLEM_121, Example2) {
	std::vector<int32_t> prices{ 1,2,3,4,5 };
	ASSERT_EQ(4, maxProfit(prices));
}

TEST(PROBLEM_121, Example3) {
	std::vector<int32_t> prices{ 7,6,4,3,1 };
	ASSERT_EQ(0, maxProfit(prices));
}
