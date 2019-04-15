//
//  main.cpp
//  BuySellStock_EPI#5.6
//
//  Created by Dinesh Ravilla on 4/14/19.
//  Copyright © 2019 Dinesh Ravilla. All rights reserved.
//


#include <iostream>
#include "array.h"
#include <vector>



/*
 
 Say you have an array for which the ith element is the price of a given stock on day i.
 
 If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 
 Note that you cannot sell a stock before you buy one.
 
 Example 1:
 
 Input: [7,1,5,3,6,4]
 Output: 5
 Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
 Not 7-1 = 6, as selling price needs to be larger than buying price.
 Example 2:
 
 Input: [7,6,4,3,1]
 Output: 0
 Explanation: In this case, no transaction is done, i.e. max profit = 0.
 
 */


//Time complexity - O(n^2)
//n(n-1)/2
int TwoLoopSolution(const vector<int>& prices) {
    int maxProfit = 0;
    for(int i = 0; i < prices.size()-1; i++) {
        for(int j = i+1; j < prices.size(); j++) {
            int profit = prices[j] - prices[i];
            if(profit > maxProfit) {
                maxProfit = profit;
            }
        }
    }
    return maxProfit;
}

//Time complexity - O(n)
int OnePassSolution(const vector<int>& prices) {
    int maxProfit = 0;
    int minPrice = INT_MAX;
    for(int i = 0; i < prices.size(); i++) {
        if(prices[i] < minPrice) {
            minPrice = prices[i];
        } else if(prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice;
        }
    }
    
    return maxProfit;
}

int main(int argc, const char * argv[]) {
    
    vector<int> prices;
    prices.push_back(7);
    prices.push_back(1);
    prices.push_back(5);
    prices.push_back(3);
    prices.push_back(6);
    prices.push_back(4);
    
    //cout << "Max Profit: " << TwoLoopSolution(prices) << endl;
    
    cout << "Max Profit: " << OnePassSolution(prices) << endl;
    
    return 0;
}
