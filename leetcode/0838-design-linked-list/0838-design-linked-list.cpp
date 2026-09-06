class MyLinkedList {
     struct Node {
        int data;
        Node* next;

        Node(int val) {
            data = val;
            next = nullptr;
        }
    };

    Node* head;

public:
    MyLinkedList() {
         head=nullptr;

    }
    int get(int index) {
        Node* temp = head;
        int c = 0;

        while (temp != nullptr) {
            if (c == index) {
                return temp->data;
            }

            c++;
            temp = temp->next;
        }

        return -1;
    }
       
      void addAtHead(int val) {
        Node* temp = new Node(val);

        temp->next = head;
        head = temp;
    }

    void addAtTail(int val) {
        Node* temp = new Node(val);

        // Empty list
        if (head == nullptr) {
            head = temp;
            return;
        }

        Node* curr = head;

        while (curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = temp;
    }

    void addAtIndex(int index, int val) {

        if (index < 0) {
            return;
        }

        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* curr = head;
        int c = 0;

        // Find node at index-1
        while (curr != nullptr && c < index - 1) {
            curr = curr->next;
            c++;
        }

        // index is greater than list size
        if (curr == nullptr) {
            return;
        }

        Node* node = new Node(val);

        node->next = curr->next;
        curr->next = node;
    }

    void deleteAtIndex(int index) {

        if (index < 0 || head == nullptr) {
            return;
        }

        // Delete head
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* curr = head;
        int c = 0;

        // Find node at index-1
        while (curr != nullptr && c < index - 1) {
            curr = curr->next;
            c++;
        }

        // Invalid index
        if (curr == nullptr || curr->next == nullptr) {
            return;
        }

        Node* temp = curr->next;
        curr->next = temp->next;

        delete temp;
    }
};
    
    
    

    

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */