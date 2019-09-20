/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

    Example:
    Input:
        [
        ["1","0","1","0","0"],
        ["1","0","1","1","1"],
        ["1","1","1","1","1"],
        ["1","0","0","1","0"]
        ]
    Output: 6

*/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> heights(matrix[0].size(), 0);
        int maxArea = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '0') {
                    heights[j] = 0;
                } else {
                    heights[j]++;
                }
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }
    int largestRectangleArea(vector<int>& heights) {
        int area = 0;
        int hei = 0;
        stack<int> s;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i++) {
            while (!s.empty() && (heights[s.top()]) > heights[i]) {
                hei = heights[s.top()];
                s.pop();
                area = max(area, hei * (s.empty() ? i : i - s.top() - 1));
            }
            s.push(i);
        }
        return area;
    }
};