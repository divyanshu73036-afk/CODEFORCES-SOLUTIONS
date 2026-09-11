class MyQueue {
    stack<int> s1, s2;

public:

    void push(int x) {
        s1.push(x);
    }

    int pop(void) {
        if (!s2.empty()) {
            int ans = s2.top();
            s2.pop();
            return ans;
        }
        else {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }

            int ans = s2.top();
            s2.pop();
            return ans;
        }
    }

    int peek(void) {
        if (!s2.empty())
            return s2.top();

        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        return s2.top();
    }

    bool empty(void) {
        return s1.empty() && s2.empty();
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