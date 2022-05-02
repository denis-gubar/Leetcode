class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int result = original;
        int N = nums.size();
        while (true)
        {
            auto it = find(nums.begin(), nums.end(), result);
            if (it != nums.end())
                result *= 2;
            else
                break;
        }
        return result;
    }
};
