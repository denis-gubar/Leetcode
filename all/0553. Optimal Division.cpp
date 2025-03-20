class Solution {
public:
    struct Data
    {
        string a;
        string b;
        double A;
        double B;
        string fa(bool needParenthis)
        {
            if (needParenthis)
                return '(' + a + ')';
            return a;
        }
        string fb(bool needParenthis)
        {
            if (needParenthis)
                return '(' + b + ')';
            return b;
        }
    };
    vector<int> nums;
    Data calc(int a, int b)
    {
        if (a == b)
            return {to_string(nums[a]), to_string(nums[a]), static_cast<double>(nums[a]) , static_cast<double>(nums[a]) };
        Data result{};
        for (int m = a; m < b; ++m)
        {
            Data left = calc(a, m), right = calc(m + 1, b);
            if (result.a.empty() || result.A > left.A / right.B)
                result.A = left.A / right.B, result.a = left.fa(left.a.find('(') != string::npos) + '/' + right.fb(m + 1 < b);
            if (result.b.empty() || result.B < left.B / right.A)
                result.B = left.B / right.A, result.b = left.fb(left.b.find('(') != string::npos) + '/' + right.fa(m + 1 < b);
        }
        return result;
    }
    string optimalDivision(vector<int>& nums) {
        this->nums = nums;
        int const N = nums.size();
        return calc(0, N - 1).b;
    }
};
