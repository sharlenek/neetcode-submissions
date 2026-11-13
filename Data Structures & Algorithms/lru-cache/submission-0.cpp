class LRUCache {
public:

    list<pair<int,int>> cache;
    unordered_map<int, list<pair<int,int>>::iterator> positions;
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
        
    }
    
    int get(int key) {
        if (positions.find(key) == positions.end()){
            return -1;
        }

        cache.splice(cache.begin(), cache, positions[key]);
        return positions[key]->second;

        
    }
    
    void put(int key, int value) {
        if (positions.find(key) != positions.end()){
            positions[key]->second = value;
            cache.splice(cache.begin(), cache, positions[key]);
            return;
        }

        if (cache.size() == capacity){
            int leastrecentkey = cache.back().first;
            positions.erase(leastrecentkey);
            cache.pop_back();
        }

        cache.push_front({key,value});
        positions[key] = cache.begin();
        return;

        
    }
};
