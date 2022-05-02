class Solution {
public:
    bool calc(int x)
    {
        int digits = 0;
        while(x)
        {
            ++digits;
            x /= 10;
        }
        return digits % 2 == 0;        
    }
    int findNumbers(vector<int>& nums) {
        int result = 0;
        for(int n: nums)
            result += calc(n);
        return result;
    }
};