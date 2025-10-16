class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        int N = nums.size();
        vector<int> result = nums;
        sort(result.begin(), result.end());
        for (int i = 0; i < N; i += 2)
            swap(result[i], result[i + 1]);
        return result;
    }
};
