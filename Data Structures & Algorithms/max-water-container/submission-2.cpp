class Solution {
public:
    int maxArea(vector<int>& heights) {
        //need to keep track of the max area
        // i think its two pointer? not sliding window
        //i have to decide the condition for moving a side. move the lower one

        int area;
        int maxarea = 0;
        int left = 0;
        int right = heights.size()-1;

        while (left < right){
            area = min(heights[left], heights[right])*(right-left);
            if (area > maxarea){
                maxarea = area;
            }

            if (heights[left] <= heights[right]){
                left++;
            } else {
                right--;
            }
        }
        return maxarea;
    }
};
