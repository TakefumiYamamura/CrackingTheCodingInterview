struct data{
	int key;
	int value;
	int date;
};

class LRUCache {
private:
	int _capacity;
	vector<data> datas;
	unordered_map<int, int> hash;
	int timeCur;

public:
    LRUCache(int capacity) {
    	_capacity = capacity;
    	timeCur = 0;
    }

    int get(int key) {
    	if(hash.find(key) ==  hash.end()) return -1;
    	datas[hash[key]].date = timeCur;
    	timeCur++;
    	return datas[hash[key]].value;
    }
    
    void put(int key, int value){
    	data newD = data{key, value, timeCur++};

        if(hash.find(key) != hash.end()){
            datas[hash[key]] = newD;
            return;
        }

    	if(datas.size() < _capacity){
    		datas.push_back(newD);
            hash[key] = datas.size() - 1;
    		return;
    	}

    	int lruItr = 0;
    	for (int i = 0; i < datas.size(); ++i)
    	{
    		if(datas[i].date < datas[lruItr].date ) lruItr = i;
    	}
 
    	hash.erase(datas[lruItr].key);
    	datas[lruItr] = newD;
    	hash[newD.key] = lruItr;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */