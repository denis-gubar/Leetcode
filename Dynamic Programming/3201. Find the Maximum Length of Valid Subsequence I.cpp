class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int result = 2;
        int N = nums.size();
        int count = 0;
        for (int x : nums)
            if (x % 2 == 1)
                ++count;
        result = max(result, count);
        count = 0;
        for (int x : nums)
            if (x % 2 == 0)
                ++count;
        result = max(result, count);
        bool flag = false;
        count = 0;
        for (int x : nums)
        {
            if (x % 2 == 1 && !flag)
                ++count, flag = true;
            if (x % 2 == 0 && flag)
                ++count, flag = false;
        }
        result = max(result, count);
        flag = false;
        count = 0;
        for (int x : nums)
        {
            if (x % 2 == 0 && !flag)
                ++count, flag = true;
            if (x % 2 == 1 && flag)
                ++count, flag = false;
        }
        result = max(result, count);
        return result;
    }
};
