class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        int const N = target.size();
        unordered_map<int, int> I;
        I.reserve(N);
        for (int i = 0; i < N; ++i)
            I[target[i]] = i;
        vector<int> M;
        M.reserve(N);
        for (int a : arr)
        {
            if (I.find(a) == I.end())
                continue;
            int x = I[a];
            auto it = lower_bound(M.begin(), M.end(), x);
            if (it == M.end())
                M.push_back(x);
            else
                *it = x;
        }
        return N - M.size();
    }
};
