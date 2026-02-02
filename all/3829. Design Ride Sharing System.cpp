class RideSharingSystem {
public:
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        R.push_back(riderId);
        E.insert(riderId);
    }
    
    void addDriver(int driverId) {
        D.push_back(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        while (!R.empty() && S.find(R.front()) != S.end())
            E.erase(R.front()), S.erase(R.front()), R.pop_front();
        if (D.empty() || R.empty())
            return { -1, -1 };
        vector<int> result = { D.front(), R.front() };
        E.erase(R.front());
        D.pop_front(), R.pop_front();
        return result;
    }
    
    void cancelRider(int riderId) {
        if (E.find(riderId) != E.end())
            S.insert(riderId);
    }
    deque<int> R;
    deque<int> D;
    unordered_set<int> S;
    unordered_set<int> E;
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */
