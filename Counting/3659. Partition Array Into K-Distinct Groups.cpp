class Solution {
public:
    bool partitionArray(vector<int>& nums, int K) {
        int const N = nums.size();
        if (N % K != 0)
            return false;
        unordered_map<int, int> M;
        for (int x : nums)
            ++M[x];
        multiset<int> S;
        for (auto [key, value] : M)
            S.insert(-value);
        vector<int> A;
        A.reserve(K);
        while (!S.empty())
        {
            if (S.size() < K)
                return false;
            A.clear();
            auto it = S.begin();
            for (int i = 0; i < K; ++i)
            {
                if (*it < -1)
                    A.push_back(*it + 1);
                it = S.erase(it);
            }
            for (int x : A)
                S.insert(x);
        }
        return true;
    }
};
