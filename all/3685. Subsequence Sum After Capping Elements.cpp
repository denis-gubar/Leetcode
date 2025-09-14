class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int K) {
        int const N = nums.size();
        vector<bool> result(N);
        sort(nums.begin(), nums.end());
        nums.push_back(1 << 20);
        bitset<4'001> mask;
        mask[0] = 1;
        int x = 0;
        int HWM = 0;
        for (int i = 0; i < N; ++i)
        {
            int const rest = N - i;
            while (x < N && nums[i] > x + 1)
            {
                if (mask[K])
                    result[x] = true;
                else if (HWM + rest * (x + 1) >= K)
                    for (int k = 0, e = min(K, HWM); k <= e; ++k)
                        if (mask[k])
                        {
                            if ((K - k) % (x + 1) != 0)
                                continue;
                            if ((x + 1) * rest >= K - k)
                                result[x] = true;
                        }
                ++x;
            }
            int j = i;
            while (nums[j] == nums[i])
            {
                mask |= (mask << nums[j]);
                if (HWM < K)
                    HWM += nums[j];
                ++j;
            }
            i = j - 1;
        }
        while (x < N)
        {
            if (mask[K])
                result[x] = true;
            ++x;
        }
        return result;
    }
};
