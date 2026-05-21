class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) return 0;

        vector<pair<int, int>> cars;
        for (int i = 0; i < n; ++i){
            cars.push_back({position[i], speed[i]});
        }
        
        // Sort by position descending (closest to target first)
        sort(cars.begin(), cars.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first; 
        });

        int fleets = 0;
        double slowest_time_seen = 0.0; // This acts as your 'fleetleader'

        for (int i = 0; i < n; ++i) {
            // Calculate time to target for the current car
            double current_time = (double)(target - cars[i].first) / cars[i].second;
            
            // If this car takes LONGER than the fleet in front, it starts a new fleet
            if (current_time > slowest_time_seen) {
                fleets++;
                slowest_time_seen = current_time;
            }
            // If current_time <= slowest_time_seen, it catches up and merges 
            // into the existing fleet; we do nothing.
        }
        
        return fleets;
    }
};