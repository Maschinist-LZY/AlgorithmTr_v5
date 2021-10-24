class MonotonicQueue{
private:
    deque<int> myque;
public:
    void push(int n){
        while(myque.back()<n && !myque.empty()){
            myque.pop_back();
        }
        myque.push_back(n);
    }
    void pop(int n){
        if(!myque.empty() && myque.front() == n){
            myque.pop_front();
        }
    }
    int max(){
        return myque.front();
    }
};



class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonotonicQueue window;
        vector<int> res;
        for(int i=0;i<k;i++){
            //int temp = ;
            window.push(nums[i]);
        }
        for(int i=k;i<nums.size();i++){

            window.push(nums[i]);
            res.push_back(window.max());
            window.pop(nums[i-k+1]);
            
        }
        return res;
    }
};



