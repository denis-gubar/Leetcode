class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> result;
        int N = nums.size();
        for (int i = 0; i < N; ++i)
        {
            bool isOk = false;
            for (int j = max(0, i - k); !isOk && j < min(N, i + k + 1); ++j)
                isOk = nums[j] == key;
            if (isOk)
                result.push_back(i);
        }
        return result;
    }
};
