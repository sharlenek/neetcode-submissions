class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //one for loop/while loop. it has to be one pass
        // check if num++ exists. 
        //if it does add to counter and keep going until it doesnt exist
        //i can make a hashmap, keep track of the counter and then inside keep all the
        //numbers. key = count and value = numbers
        // make new key only if its diff
        // should i remove the numbers after i add them to hash?
        //no cuz if i remove them, the indexes get messed up.
        //uhh i should prob sort it
        
        if (nums.size() == 0){
            return 0;
        }

        sort(nums.begin(), nums.end());
        // 2 3 4 4 5 10 20
        int count = 1;
        int highestcount = 1;

        for (int i = 0; i < nums.size()-1; ++i){

            if (nums[i+1] == nums[i]+1){
                count++;
            } else if (nums[i+1] == nums[i]){
                continue;
            } else {
                if (count > highestcount){
                    highestcount = count;
                }
                count = 1;
            }
        }
        if (count > highestcount){
            highestcount = count;
        }
        return highestcount;
    }
};
