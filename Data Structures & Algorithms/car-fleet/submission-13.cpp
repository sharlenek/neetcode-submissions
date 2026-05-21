class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        //how the hell do i calculate this
        //test if the position before is faster than the position after
        //its just adding
        // while the smallest position != target
        // sort position? but then u lose the speeds
        // stack is good when u need to keep an order
        //next greater? next smaller

        int n = position.size();
        int fleets = n;
        vector <pair<int, int>> car;
        for (int i = 0; i < n; ++i){
            car.push_back({position[i], speed[i]});
        }
        sort(car.begin(), car.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first; 
        });

        // 7 4 1 0
        float fleetleader = 0;
        float carback;
        for (int i = 0; i < n; ++i){
                    //how long itll take to get to destination
                    carback = (double)(target - car[i].first) / car[i].second;
                    //if
                if (carback <= fleetleader) {
                        --fleets;
                } else {
                        fleetleader = carback;
                }
            
        }
            
        
        return fleets;
        
    }
};
