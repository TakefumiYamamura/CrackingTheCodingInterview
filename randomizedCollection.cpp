class RandomizedCollection {
private:
    vector<int> arr;
    unordered_map<int, unordered_set<int> > um;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool flag = false;
        if(um.find(val) == um.end() || um[val].empty()){
            flag = true;
        }
        arr.push_back(val);
        um[val].insert(arr.size() - 1);
        return flag;
        
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(um.find(val) == um.end() || um[val].empty()){
            return false;
        }
        int idx = *(um[val].begin());
        um[val].erase(idx);
        int last = arr[arr.size() - 1];
        um[last].insert(idx);
        um[last].erase(arr.size() - 1);
        swap(arr[idx], arr[arr.size() - 1]);
        arr.pop_back();
        return true;
        
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return arr.size() == 0 ? 0 : arr[rand() % arr.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */