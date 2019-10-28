class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        data = vector<bool>(1000001);
    }
    
    void add(int key) {
        data[key] = true;
    }
    
    void remove(int key) {
        data[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return data[key];
    }
    vector<bool> data;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */