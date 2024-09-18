class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_set<int> S;
        for(int x : nums)
            if (!S.insert(x).second)
                S.erase(x);
        return vector<int>(S.begin(), S.end());
    }
};