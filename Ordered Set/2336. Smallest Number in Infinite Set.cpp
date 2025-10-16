class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        for (int i = 1; i < 1002; ++i)
            S.insert(i);
    }
    
    int popSmallest() {
        int result = *S.begin();
        S.erase(S.begin());
        return result;
    }
    
    void addBack(int num) {
        S.insert(num);
    }
    set<int> S;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
