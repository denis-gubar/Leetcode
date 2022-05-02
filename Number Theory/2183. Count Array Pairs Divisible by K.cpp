class Solution {
public:
    long long coutPairs(vector<int>& nums, int k) {
        long long result = 0;
        int N = nums.size();
        vector<vector<int>> M(k + 1);
        vector<int> divs;
        for (int div = 1; div <= k; ++div)
            if (k % div == 0)
            {
                divs.push_back(div);
                M[div].assign(N + 1, 0);
                for (int i = 0; i < N; ++i)
                    M[div][i + 1] = M[div][i] + (nums[i] % div == 0);
            }
        int divCount = divs.size();
        for (int i = 0; i < N; ++i)
            for (int j = divCount - 1; j >= 0; --j)
                if (nums[i] % divs[j] == 0)
                {
                    result += M[k / divs[j]][i];
                    break;
                }
        return result;
    }
};
