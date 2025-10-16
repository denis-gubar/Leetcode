class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        long long result = 0;
        int const N = maximumHeight.size();
        sort(maximumHeight.begin(), maximumHeight.end());
        int HWM = 1 << 30;
        while (!maximumHeight.empty())
        {
            int x = maximumHeight.back();
            maximumHeight.pop_back();
            if (x >= HWM)
                --HWM, result += HWM;
            else
                result += x, HWM = x;
        }
        if (HWM < 1)
            return -1;
        return result;
    }
};
