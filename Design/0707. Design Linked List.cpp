class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        root = nullptr;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {        
        if (index < 0 || !root)
            return -1;
        MyLinkedList* node = root;
        for(int i = 0; i < index; ++i)
            if (!node)
                return -1;
            else
                node = node->next;            
        if (!node)
            return -1;
        return node->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        MyLinkedList* node = new MyLinkedList();
        node->val = val;
        node->next = root;
        root = node;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        MyLinkedList* node = new MyLinkedList();
        node->val = val;
        node->next = nullptr;
        MyLinkedList* tail = root;
        while(tail != nullptr && tail->next != nullptr)
            tail = tail->next;
        if (!root)
            root = node;
        else
            tail->next = node;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index < 0)
            return;
        MyLinkedList* node = root;
        for(int i = 0; i + 1 < index; ++i)
            if (!node)
                return;
            else
                node = node->next;            
        MyLinkedList* temp = new MyLinkedList();
        temp->val = val;
        if (!index)
        {
            temp->next = root;
            root = temp;
        }
        else
        {
            if (node)
            {
                temp->next = node->next;
                node->next = temp;
            }
            else
                temp->next = nullptr;            
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || !root)
            return;
        MyLinkedList* node = root;
        for(int i = 0; i + 1 < index; ++i)
            if (!node)
                return;
            else
                node = node->next;
        MyLinkedList* temp;
        if (!index)
        {
            temp = root;
            root = root->next;
        }
        else
        {
            temp = node->next;
            if (temp)
                node->next = temp->next;
        }
        if (temp)
            delete temp;
    }
    MyLinkedList* next;
    MyLinkedList* root;
    int val;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */