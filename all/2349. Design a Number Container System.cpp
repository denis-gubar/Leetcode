class NumberContainers {
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if (auto it = A.find(index); it != A.end())
        {
            int old_number = it->second;
            M[old_number].erase(M[old_number].find(index));
            A.erase(it);
        }
        A[index] = number;
        M[number].insert(index);
    }
    
    int find(int number) {
        if (auto it = M.find(number); it != M.end())
        {
            auto it2 = it->second.begin();
            if (it2 != it->second.end())
                return *it2;
        }
        return -1;
    }
    unordered_map<int, int> A;
    unordered_map<int, set<int>> M;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
