class LRUCache {
private:
    int capa;
    list<pair<int, int> > ls; //key value
    unordered_map<int, list<pair<int, int> >::iterator> um;

public:
    LRUCache(int capacity) {
        capa = capacity;
    }
    
    int get(int key) {
        if(um.find(key) == um.end()){
            return -1;
        }
        auto old_itr = um[key];
        int val = old_itr->second;
        ls.erase(old_itr);
        ls.push_back(pair<int, int>(key, val) );
        auto new_itr = ls.end();
        new_itr--;
        um[key] = new_itr;
        return val;
    }
    
    void put(int key, int value) {
        if(um.find(key) != um.end()){
            ls.erase(um[key]);
        }
        ls.push_back(pair<int, int>(key, value));
        auto itr = ls.end();
        itr--;
        um[key] = itr;

        if(ls.size() > capa){
            auto delete_itr = ls.begin();
            um.erase(delete_itr->first);
            ls.pop_front();
        }
    }
};
