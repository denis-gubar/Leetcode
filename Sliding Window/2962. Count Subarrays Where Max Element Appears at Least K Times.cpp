class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long result = 0;
        int N = nums.size();
        int M = *max_element(nums.begin(), nums.end());
        deque<int> A;
        for (int i = 0; i < N; ++i)
        {
            if (nums[i] == M)
                A.push_back(i);
            if (A.size() > k)
                A.pop_front();
            if (A.size() == k)
                result += A.front() + 1;
        }
        return result;
    }
};
