class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a = numeric_limits<int>::max();
        int b = numeric_limits<int>::max();
        for (int x : nums)
            if (x < a)
                a = x;
            else if (x > a && x < b)
                b = x;
            else if (x > b)
                return true;
        return false;
    }
};
