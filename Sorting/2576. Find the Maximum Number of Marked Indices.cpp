class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int N = nums.size();
        sort(nums.begin(), nums.end());
        int result = 0;
        int a = 0, b = N + 1;
        auto check = [&nums, N](int m)
        {
            if (m > N / 2)
                return false;
            for (int i = m - 1, j = N - 1; i >= 0; --i, --j)
                if (nums[i] * 2 > nums[j])
                    return false;
            return true;
        };
        while (a + 1 < b)
        {
            int m = (a + b) / 2;
            if (check(m))
                a = m;
            else
                b = m;
        }
        return a * 2;
    }
};

