class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> map;

    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        string result = "";
        int left = 0;
        int right = map[key].size()-1;

        // 1 3 4 5 6 9

        while (left <= right){
            int curr = left + (right - left)/2;

            if (map[key][curr].first <= timestamp){
                result = map[key][curr].second;
                left = curr + 1;
            } else {
                right = curr - 1;
            }
        }
        
        return result;



        // for (int i = 0; i < map[key].size(); i++){
        //     if (map[key][i].first <= timestamp){
        //         result = map[key][i].second;
        //     } else {
        //         break;
        //     }
        // }
    }
};
