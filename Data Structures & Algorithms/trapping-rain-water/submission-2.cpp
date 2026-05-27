class Solution {
public:
    int trap(vector<int>& height) {
        //two pointer now that i actually understand th eprobem
        int left = 0;
        int right = height.size()-1;
        int lmax = height[left];
        int rmax = height[right];

        int maxarea = 0;
        while (left < right){
            if (height[right] < height[left]){
                --right;
                if (height[right] >= rmax){
                    rmax = height[right];
                } else {
                    maxarea += rmax - height[right];
                }
            } else {
                ++left;
                if (height[left] >= lmax){
                    lmax = height[left];
                } else {
                    maxarea += lmax - height[left];
                }
            }

        }
        return maxarea;
    }
};
