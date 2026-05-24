class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 1;
        int right = numbers.size();
        while (left < right) {
            if (numbers[left-1] + numbers[right-1] > target) {
                --right;
            } else if (numbers[left-1] + numbers[right-1] < target) {
                ++left;
            } else {
                return {left, right};
            }
        }
    }
};
