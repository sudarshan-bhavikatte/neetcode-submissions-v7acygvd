class LRUCache {
    int c;
    unordered_map<int,vector<int>> cache;
public:
    LRUCache(int capacity) {
        this->c = capacity;
    }
    
    int get(int key) {
        int res = -1;

        for(auto it = cache.begin(); it != cache.end(); it++){
            if(it->first == key){
                res = it->second[0];
                it->second[1] = 0;
            }
            it->second[1]++;
        }

        return res;
    }
    
    void put(int key, int value) {
        for(auto it = cache.begin(); it != cache.end(); it++){
            it->second[1]++;
        }

        cache[key] = {value, 0};
        if(cache.size() > c){
            int max_key = INT_MIN;
            for(auto it = cache.begin(); it != cache.end(); it++){
                if(max_key == INT_MIN){
                    max_key = it->first;
                    continue;
                }
                max_key = (it->second[1] > cache[max_key][1]) ? it->first : max_key;
            }
            cache.erase(max_key);
        }
    }
};
