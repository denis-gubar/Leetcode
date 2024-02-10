class Solution {
public:
    string triangleType(vector<int>& nums) {
        int const& a = nums[0];
        int const& b = nums[1];
        int const& c = nums[2];
        if (a + b <= c || b + c <= a || a + c <= b)
            return "none";
        if (a == b && b == c)
            return "equilateral";
        if (a == b || b == c || a == c)
            return "isosceles";
        return "scalene";
    }
};
