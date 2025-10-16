class Solution {
public:    
    int shortestSequence(vector<int>& rolls, int k) {
        int result = 1;
        unordered_set<int> S;
        for (int x : rolls)
        {
            S.insert(x);
            if (S.size() == k)
            {
                S.clear();
                ++result;
            }
        }
        return result;
    }
};
