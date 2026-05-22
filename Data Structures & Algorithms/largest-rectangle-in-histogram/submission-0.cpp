#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> stk; // Stores {index, height}
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; ++i) {
            // Use 0 as the height at the end to force-pop everything from the stack
            int currentHeight = (i == n) ? 0 : heights[i];

            while (!stk.empty() && currentHeight < stk.top().second) {
                int h = stk.top().second;
                stk.pop();
                
                // Width = distance between current index i and the new top's index
                // If stack is empty, it means h was the smallest so far, so width = i
                int w = stk.empty() ? i : (i - stk.top().first - 1);
                
                maxArea = max(maxArea, h * w);
            }
            stk.push({i, currentHeight});
        }
        
        return maxArea;
    }
};