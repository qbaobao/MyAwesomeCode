/*
638. Shopping Offers
In LeetCode Store, there are some kinds of items to sell. Each item has a price.
However, there are some special offers, and a special offer consists of one or more different kinds of items with a sale price.
You are given the each item's price, a set of special offers, and the number we need to buy for each item. The job is to output the lowest price you have to pay for exactly certain items as given, where you could make optimal use of the special offers.
Each special offer is represented in the form of an array, the last number represents the price you need to pay for this special offer, other numbers represents how many specific items you could get if you buy this offer.
You could use any of special offers as many times as you want.
    Example 1:
        Input: [2,5], [[3,0,5],[1,2,10]], [3,2]
        Output: 14
        Explanation: 
            There are two kinds of items, A and B. Their prices are $2 and $5 respectively. 
            In special offer 1, you can pay $5 for 3A and 0B
            In special offer 2, you can pay $10 for 1A and 2B. 
            You need to buy 3A and 2B, so you may pay $10 for 1A and 2B (special offer #2), and $4 for 2A.
    Example 2:
        Input: [2,3,4], [[1,1,0,4],[2,2,1,9]], [1,2,1]
        Output: 11
        Explanation: 
            The price of A is $2, and $3 for B, $4 for C. 
            You may pay $4 for 1A and 1B, and $9 for 2A ,2B and 1C. 
            You need to buy 1A ,2B and 1C, so you may pay $4 for 1A and 1B (special offer #1), and $3 for 1B, $4 for 1C. 
            You cannot add more items, though only $9 for 2A ,2B and 1C.
Note:
There are at most 6 kinds of items, 100 special offers.
For each item, you need to buy at most 6 of them.
You are not allowed to buy more items than you want, even if that would lower the overall price.

分析：采用动态规划。
    因为题目中说明最多6中物品，每种物品最多购买6个。所以数据的规模并不大，可以采用暴力枚举的方式完成。
    dp[j][k][l][m][n][p] 表示第0中物品购买j个,[第1中物品购买k个,第2中物品购买l个,第3中物品购买m个,第4中物品购买n个,第5中物品购买p个]需要花费的价钱
    初始化：dp[j][k][l][m][n][p] = j * price[0] +  k * price[1] + l * price[2] +  m * price[3] + n * price[4] + p * price[5]
    遍历所有的specials, i:1-->special.size()：
        dp[j][k][l][m][n][p] = min(dp[j][k][l][m][n][p], dp[j-special[i][0]][k-special[i][1]][l-special[i][2]][m-special[i][3]][n-special[i][4]][p-special[i][5]] + special.price)
*/
class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        for (int i = price.size(); i < 6; i++) {
            price.push_back(0);
            needs.push_back(0);
        }
        for (int i = 0; i < special.size(); i++) {
            int specialTotalPrice = special[i][special[i].size() - 1];
            special[i][special[i].size() - 1] = 0;
            for (int j = special[i].size(); j < 7; j++) {
                special[i].push_back(0);
            }
            special[i][6] = specialTotalPrice;
        }
        
        int dp[7][7][7][7][7][7] = {0};
        for (int j = 0; j < 7; j++) {
            for (int k = 0; k < 7; k++) {
                for (int l = 0; l < 7; l++) {
                    for (int m = 0; m < 7; m++) {
                        for (int n = 0; n < 7; n++) {
                            for (int p = 0; p < 7; p++) {
                                dp[j][k][l][m][n][p] = j * price[0] + 
                                    k * price[1] + l * price[2] + 
                                    m * price[3] + n * price[4] +
                                    p * price[5];
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < special.size(); i++) {
            for (int j = 0; j <= needs[0]; j++) {
                for (int k = 0; k <= needs[1]; k++) {
                    for (int l = 0; l <= needs[2]; l++) {
                        for (int m = 0; m <= needs[3]; m++) {
                            for (int n = 0; n <= needs[4]; n++) {
                                for (int p = 0; p <= needs[5]; p++) {
                                    if (j >= special[i][0] && k >= special[i][1] && l >= special[i][2] &&
                                       m >= special[i][3] && n >= special[i][4] && p >= special[i][5]) {
                                        dp[j][k][l][m][n][p] = min(dp[j][k][l][m][n][p],
                                                                  dp[j - special[i][0]][k - special[i][1]][l - special[i][2]][m - special[i][3]][n - special[i][4]][p - special[i][5]] + special[i][6]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        
        return dp[needs[0]][needs[1]][needs[2]][needs[3]][needs[4]][needs[5]];
    }
};