/*
思路：
另一个数组存储增量
只有POP的时候才需要加上增量
增量也需要向栈底传递
*/
class CustomStack {
private:
    std::vector<int> mystack,inc;
    int top;
public:
    CustomStack(int maxSize) {
        mystack.resize(maxSize);
        inc.resize(maxSize);
        top = -1;
    }
    
    void push(int x) {
        if(top != mystack.size() - 1){
            top++;
            mystack[top]=x;
        }
    }
    
    int pop() {
        if(top == -1){
            return -1;
        }
        int ret = mystack[top] + inc[top];
        if(top!=0)
        {
            inc[top-1] += inc[top];
        }
        inc[top] = 0;
        top--;
        return ret;
    }
    
    void increment(int k, int val) {
        int count = min(k-1, top);
        if(count >= 0)
        {
            inc[count] += val;
        }
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */