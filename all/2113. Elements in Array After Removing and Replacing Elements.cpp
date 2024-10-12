class Solution {
public:
    vector<int> elementInNums(vector<int>& nums, vector<vector<int>>& queries) {
        int const N = nums.size(), Q = queries.size();
        vector<int> result(Q, -1);
        for (int i = 0; i < Q; ++i)
        {
            int time = queries[i][0];
            int const& index = queries[i][1];
            time %= 2 * N;
            if (time < N && N - time > index)
                result[i] = nums[index + time];
            if (time - N > index)
                result[i] = nums[index];
        }
        return result;
    }
};
