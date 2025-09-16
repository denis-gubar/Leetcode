class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int result = 0;
        int const N = nums.size();
        vector<int> I(N), D(N);
        iota(I.begin(), I.end(), 0);
        for (int i = 0; i < N; ++i)
        {
            int x = nums[i];
            while (x > 0)
                D[i] += x % 10, x /= 10;
        }
        sort(I.begin(), I.end(), [&nums, &D](int a, int b)
            {
                if (D[a] != D[b])
                    return D[a] < D[b];
                return nums[a] < nums[b];
            });
        vector<bool> visited(N);
        for(int i = 0; i < N; ++i)
            if (!visited[I[i]])
            {
                for (int j = i; !visited[I[j]]; j = I[j])
                    visited[I[j]] = true, result += j != i;
            }
        return result;
    }
};
