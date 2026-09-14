class MinStack {
public:
struct node {
        pair<int,int> data;
        node* next;

        node(pair<int,int> p) {
            data = p;
            next = nullptr;
        }
    };
        node* head = nullptr;

    MinStack() {
        
    }
    
    void push(int value) {
        int mini = value;

        if (head != nullptr) {
            mini = min(value, head->data.second);
        }

        node* temp = new node({value, mini});

        temp->next = head;
        head = temp;
    }
    
    void pop() {
        if (head == nullptr)
            return;

        node* temp = head;
        head = head->next;

        delete temp;
    }

    int top() {
        return head->data.first;
    }

    int getMin() {
        return head->data.second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */