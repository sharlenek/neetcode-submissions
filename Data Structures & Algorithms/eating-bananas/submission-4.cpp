class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        if (piles.size() == h){
            return right;
        }

        int rate;
        int minrate = right;
        int hours;

        while (left <=right) {
            hours = 0;
            rate = (right-left)/2 + left;

            for (int i = 0; i < piles.size(); ++i){
                hours += (piles[i] + rate - 1)/rate;
            }

            if (hours > h){
                left = rate+1;
            } else if (hours <= h){
                if (rate < minrate){
                    minrate = rate;
                }
                right = rate-1;
            }
        }
        return minrate;

    }
};
// could sort the pile
// 4, 10, 15, 23

//35+23=58+4=62 62-4 = 58 
// 4- 4 = 0


// piles = [1, 1, 16, 3, 20]  h = 10
// bananas = 31 - 5 = 26 / 5 = 5 r 1
// 2 per hour = 1, 1, 8, 2, 10
// 4 per hour = 1, 2, 4, 1, 5 = 13

// 10 - 5 = 5. 5 extra hours to divide up
//5 per hour = 1, 1, 4, 1, 4
// 6 per hour = 1, 1, 3, 1, 4