class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> M(30);
        for (int x : candidates)
        {
            for (int k = 0; k < 30; ++k)
                if (x & (1 << k))
                    ++M[k];
        }
        return *max_element(M.begin(), M.end());
    }
};
