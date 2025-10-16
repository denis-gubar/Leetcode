class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int N = nums.size();
        vector<int> result(nums);
        for (int i = 0; i < N - 1; ++i)
            if (result[i] == result[i + 1])
            {
                result[i] *= 2;
                result[i + 1] = 0;
            }
        result.erase(remove(result.begin(), result.end(), 0), result.end());
        result.resize(N);
        return result;
    }
};
