class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while (x > 0)
        {
            result = result * 10 + x % 10;
            x /= 10;
        }
        return result;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int result = -1;
        int const N = nums.size();
        unordered_map<int, vector<int>> M;
        for (int i = 0; i < N; ++i)
            M[nums[i]].push_back(i);
        for (int i = 0; i < N; ++i)
        {
            int const R = reverse(nums[i]);
            if (M.find(R) != M.end())
            {
                int best = N;
                vector<int> const& V = M[R];
                auto it = lower_bound(V.begin(), V.end(), i);
                if (it == V.end() || *it != i)
                {
                    if (it != V.end())
                    {
                        best = min(best, abs(*it - i));
                        if (next(it) != V.end())
                            best = min(best, abs(*next(it) - i));
                    }
                }
                else
                {
                    if (next(it) != V.end())
                        best = min(best, abs(*next(it) - i));
                }
                if (best < N && (best < result || result == -1))
                    result = best;
            }
        }
        return result;
    }
};
