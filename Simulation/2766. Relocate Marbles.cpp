class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        int N = nums.size();
        vector<int> result;
        result.reserve(N);
        map<int, int> M;
        for (int x : nums)
            ++M[x];
        int K = moveFrom.size();
        for (int i = 0; i < K; ++i)
        {
            if (moveFrom[i] == moveTo[i])
                continue;
            auto it = M.find(moveFrom[i]);
            if (it != M.end())
            { 
                M[moveTo[i]] += it->second;
                M.erase(M.find(moveFrom[i]));
            }
        }
        for (auto [key, value] : M)
            result.push_back(key);
        return result;
    }
};
