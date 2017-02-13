#include <stack>

class PhoneDirectory {
    vector<bool> checkNumbers;
    int maxNumbers;
    stack<int> aNums;

public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        this->maxNumbers = maxNumbers;
        checkNumbers = vector<bool>(maxNumbers, false);
        for (int i = 0; i < maxNumbers; ++i)
        {
            aNums.push(i);
        }
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if(aNums.empty()){
            return -1;
        }
        int ans = aNums.top();
        aNums.pop();
        checkNumbers[ans] = true;
        return ans;

        for (int i = 0; i < maxNumbers; ++i)
        {
            if(checkNumbers[i] == false){
                checkNumbers[i] = true;
                return i;
            }
        }
        return -1;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        if(checkNumbers[number] == false) return true;
        return false;
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        checkNumbers[number] = false;
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */