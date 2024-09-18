class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> result;
        int N = nums.size();
        vector<int> negatives;
        vector<int> positives;
        result.reserve(N);
        negatives.reserve(N);
        positives.reserve(N);
        for (int x : nums)
            if (x > 0)
                positives.push_back(x);
            else
                negatives.push_back(x);
        for (int i = 0; i < N / 2; ++i)
        {
            result.push_back(positives[i]);
            result.push_back(negatives[i]);
        }
        return result;
    }
};
