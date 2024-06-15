static int F[101];
class Solution {
public:
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        vector<int> result;
        int N = arrays.size();
        memset(F, 0, sizeof(F));
        result.reserve(arrays[0].size());
        for (vector<int> const& arr : arrays)
            for (int x : arr)
                if (++F[x] == N)
                    result.push_back(x);
        return result;
    }
};
