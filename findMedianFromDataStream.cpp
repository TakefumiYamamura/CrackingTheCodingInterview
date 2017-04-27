class MedianFinder {
private:
    vector<int> st;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        auto itr = lower_bound(st.begin(), st.end(), num);
        st.insert(itr, num);
    }
    
    double findMedian() {
        if(st.size() % 2 == 1){
            return st[st.size() / 2];
        }else{
            return (st[st.size() / 2] + st[st.size() / 2 - 1]) / 2.0; 
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */