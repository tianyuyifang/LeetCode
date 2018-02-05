class MapSum {
public:
    /** Initialize your data structure here. */
    void insert(string key, int val) {
        map[key] = val;
    }
    
    int sum(string prefix) {
        int sum = 0;
        int size = prefix.size();
        for(auto it=map.begin(); it!=map.end(); ++it){
            string key = it->first;
            if(key.size()>=size && prefix==key.substr(0,size)){
                sum += it->second;
            }
        }
        return sum;
    }
private:
    unordered_map<string, int> map; 
};