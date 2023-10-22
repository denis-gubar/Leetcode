class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int N = nums.size();
        vector<int> result = { -1, -1 };
        if (indexDifference >= N)
            return result;
        if (indexDifference == 0)
        {
            int a = min_element(nums.begin(), nums.end()) - nums.begin();
            int b = max_element(nums.begin(), nums.end()) - nums.begin();
            if (abs(nums[a] - nums[b]) >= valueDifference)
                return { a, b };
            return result;
        }
        set<pair<int, int>> S;
        for (int i = indexDifference; i < N; ++i)
        {
            S.insert({nums[i - indexDifference], i - indexDifference});
            int a = S.begin()->first;
            int b = S.rbegin()->first;
            int const& x = nums[i];
            if (abs(x - a) >= valueDifference)
                return { S.begin()->second, i };
            if (abs(x - b) >= valueDifference)
                return { S.rbegin()->second, i };
        }
        return result;
    }
};
