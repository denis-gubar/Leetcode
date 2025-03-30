class Solution {
public:
    string convertToBase7(int num) {
        string result, t;
        if (num < 0)
            result += '-', num = -num;
        if (num == 0)
            result += '0';
        while(num > 0)
        {
            t += (num % 7) + '0';
            num /= 7;
        }
        reverse(t.begin(), t.end());
        result += t;
        return result;
    }
};