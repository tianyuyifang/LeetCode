class LinkedList {
public:
    int val;
    LinkedList* next;
    LinkedList(int val, LinkedList* next=0):val(val), next(next){}
};

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        auto it = map.find(val);
        if(it != map.end()){
            LinkedList* p = map[val];
            map[val] = new LinkedList(vec.size());
            vec.push_back(val);
            map[val]->next = p;
            return false;
        }
        else{
            map[val] = new LinkedList(vec.size());
            vec.push_back(val);
            return true;
        }
        
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto it = map.find(val);
        if(it != map.end()){
            LinkedList* p = map[val];
            int pos = p->val;
            vec[pos] = vec.back();
            vec.pop_back();
            LinkedList* q = map[vec[pos]];
            while(q->val != vec.size()){
                q = q->next;
            }
            q->val = pos;
            
            if(p->next){
                map[val] = p->next;
                delete p;
            }
            else{
                map.erase(val);
                delete p;
            }
            return true;
        }
        return false;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        if (vec.size() == 0) return NULL;
        return vec[rand() % vec.size()];        
        
    }
private:
    vector<int> vec;
    unordered_map<int, LinkedList*> map;
    
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */