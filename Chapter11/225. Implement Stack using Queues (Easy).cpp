class MyStack {
    queue<int> q;
public:
    MyStack() {

    }

    void push(int x) {
        int len = q.size();
        q.push(x);
        for(int i = 0; i < len; ++i){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int res = q.front();
        q.pop();
        return res;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
