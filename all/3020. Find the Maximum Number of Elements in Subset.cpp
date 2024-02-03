class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int result = 1;
        map<int, int> M;
        for (int x : nums)
            ++M[x];
        for (auto [key, value] : M)
        {
            int v = value;
            int x = key;
            if (x == 1)
            {
                result = max(result, (v - 1) / 2 * 2 + 1);
                continue;
            }
            int count = 1;
            while(v > 1)
            {
                if (1LL * x * x > 1'000'000'000)
                    break;
                auto it = M.find(x * x);
                if (it != M.end())
                {
                    count += 2;
                    v = it->second;
                    x *= x;
                }
                else
                    break;
            }
            result = max(result, count);
        }
        return result;
    }
};
