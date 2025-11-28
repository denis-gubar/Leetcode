class Solution {
public:
    long long sumAndMultiply(int n) {
        long long result = 0, sum = 0;
        string x = to_string(n);
        for (char c : x)
            if (c != '0')
            {
                sum += c - '0';
                result = result * 10 + (c - '0');
            }
        return sum * result;
    }
}; 
