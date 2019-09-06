/*
    There are N children standing in a line. Each child is assigned a rating value.
    You are giving candies to these children subjected to the following requirements:
        1. Each child must have at least one candy.
        2. Children with a higher rating get more candies than their neighbors.
        3. What is the minimum candies you must give?

    Example 1:
    Input: [1,0,2]
    Output: 5
    Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
    
    Example 2:
    Input: [1,2,2]
    Output: 4
    Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
                The third child gets 1 candy because it satisfies the above two conditions.
    
    分析：使用贪心算法。题目要求[x,y,z] y的糖果数和[x,z]有关。将题目拆分。
        [x,y,z]-->[x,y] + [y,z]
        只需要保证[x,y]或者[y,z]中值较大者获得的糖果数多即可。
        保证[x,y]：从左向右依次遍历数组,如果y>x,则candy[y]=candy[x]+1
        保证[y,z]：从右向左依次便利数组,如果z>x,则candy[z]=candy[x]+1
*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int result = 0;
        vector<int> candy(ratings.size(), 1);
        for(int i = 0; i < ratings.size() - 1; i++) {
            if (ratings[i] < ratings[i+1]) {
                candy[i+1] = candy[i] + 1;
            }
        }
        for(int i = ratings.size() - 1; i > 0; i--) {
            if (ratings[i] < ratings[i-1] && candy[i-1] <= candy[i]) {
                candy[i-1] = candy[i] + 1;
            }
        }
        
        for(auto a:candy) {
            result += a;
        }
        return result;
    }
};