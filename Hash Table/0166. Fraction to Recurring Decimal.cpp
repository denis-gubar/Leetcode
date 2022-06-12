class Solution {
public:
    string fractionToDecimal(long long numerator, long long denominator) {
        if (numerator == 0)
            return "0";
        string result;
        if ((numerator > 0) != (denominator > 0))
            result += '-';
        numerator = abs(numerator);
        denominator = abs(denominator);
        result += to_string(numerator / denominator);
        long long rest = numerator % denominator;
        if (rest == 0)
            return result;
        result += '.';
        rest *= 10;
        unordered_map<long long, int> M;
        while (M.find(rest) == M.end())
        {
            M[rest] = result.size();
            result += to_string(rest / denominator);
            rest %= denominator;
            rest *= 10;
            if (rest == 0)
                return result;
        }
        result += ')';
        result.insert(result.begin() + M[rest], '(');
        return result;
    }
};
