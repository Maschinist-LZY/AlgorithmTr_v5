/*
Q232
思路：双栈模拟队列
*/
class MyQueue {
private:
    stack<int> S_a,S_b;

    void move(){
        while(!S_a.empty()){
            S_b.push(S_a.top());
            S_a.pop();
        }
    }
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        S_a.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(S_b.empty())
        {
            move();
        }
        int x = S_b.top();
        S_b.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        if(S_b.empty())
        {
            move();
        }
        return S_b.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return S_b.empty() && S_a.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */