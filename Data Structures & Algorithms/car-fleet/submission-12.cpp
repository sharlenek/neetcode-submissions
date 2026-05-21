class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector <pair<int, int>> car;
        for (int i = 0; i < n; ++i){
            car.push_back({position[i], speed[i]});
        }
        sort(car.begin(), car.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first; 
        });

        stack<double> stk;
        double arrivaltime = 0;
        for (int i = 0; i < n; ++i){
            arrivaltime = (double)(target - car[i].first) / car[i].second;
            if (stk.empty()){
                stk.push(arrivaltime);
            } else {
                if (arrivaltime > stk.top()){
                    stk.push(arrivaltime);
                }
            }
        }
        return stk.size();
    }
};
