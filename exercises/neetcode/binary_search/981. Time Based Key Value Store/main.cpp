// Time: O(logn)
class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>> > store;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if(store.count(key))
            store[key].push_back(make_pair(value,timestamp));
        else{
            vector<pair<string,int>> vecValue;
            vecValue.push_back(make_pair(value,timestamp));
            store[key] = vecValue;
        }
    }
    
    string get(string key, int timestamp) {
        vector<pair<string,int>> vecValue = store[key];
        string value = "";
        int l = 0, r = vecValue.size() - 1;
        while(l <= r){
            int mid = (l+r)/2;
            if(vecValue[mid].second <= timestamp){
                l = mid + 1;
                value = vecValue[mid].first;
            }else
                r = mid - 1;
        }
        return value;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
