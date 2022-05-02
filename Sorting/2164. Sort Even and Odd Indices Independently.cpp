class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> result;
        int N = nums.size();
        vector<int> odd, even;
        for (int i = 0; i < N; ++i)
            if (i % 2 == 0)
                even.push_back(nums[i]);
            else
                odd.push_back(nums[i]);
        sort(even.begin(), even.end());
        reverse(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        for(int i = 0; i < N; ++i)
            if (i % 2 == 0)
            {
                result.push_back(even.back());
                even.pop_back();
            }
            else
            {
                result.push_back(odd.back());
                odd.pop_back();
            }
        return result;
    }
};
