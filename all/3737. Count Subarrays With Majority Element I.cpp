static short A[1'001];
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int result = 0;
        int const N = nums.size();
        A[0] = 0;
        for (int i = 0; i < N; ++i)
            A[i + 1] = A[i] + (nums[i] == target);
        for(int start = 0; start < N; ++start)
            for (int finish = start; finish < N; ++finish)
            {
                int const targetCount = A[finish + 1] - A[start];
                int const length = finish - start + 1;
                result += targetCount * 2 > length;
            }
        return result;
    }
};
