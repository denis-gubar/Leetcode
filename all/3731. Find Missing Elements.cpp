class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> result;
        set<int> S(nums.begin(), nums.end());
        int a = *min_element(nums.begin(), nums.end());
        int b = *max_element(nums.begin(), nums.end());
        for (int x = a + 1; x < b; ++x)
            if (S.find(x) == S.end())
                result.push_back(x);
        return result;
    }
};
