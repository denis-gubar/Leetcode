class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int result = 0;
        map<int, int> M;
        for (int x : nums)
            ++M[x];
        while (M.size() > 1)
        {
            auto it = prev(prev(M.end()));
            int h = it->first;
            int last = prev(M.end())->first;
            ++result;
            M.erase(prev(M.end()));
        }
        if (M.begin()->first < k)
            return -1;
        if (M.begin()->first > k)
            ++result;
        return result;
    }
};
