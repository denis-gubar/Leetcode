class LUPrefix {
public:
	
    LUPrefix(int n) {
        for (int i = 1; i <= n + 1; ++i)
            S.insert(i);
    }
    
    void upload(int video) {
        S.erase(video);
    }
    
    int longest() {
        return *S.begin() - 1;
    }
    set<int> S;
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */
