class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size()-1;
        
        int maxArea = 0;
        int currArea;
        while(left < right){

            currArea = (right-left)*min(heights[left], heights[right]);
            if (currArea > maxArea){
                maxArea = currArea;
            }

            if (heights[left] < heights[right]){
                left++;
            } else {
                right--;
            }


        }
        return maxArea;
    }
};
