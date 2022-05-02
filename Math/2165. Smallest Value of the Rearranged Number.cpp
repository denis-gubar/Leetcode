class Solution {
public:
    long long smallestNumber(long long num) {
        if (num == 0)
            return 0;
        if (num > 0)
        {
            string s = to_string(num);
            sort(s.begin(), s.end());
            int pos = 0;
            while (s[pos] == '0')
                ++pos;
            swap(s[pos], s[0]);
            return stoll(s);
        }
        long long result = num;
		string s = to_string(-num);
		sort(s.begin(), s.end());
        reverse(s.begin(), s.end());
        return -stoll(s);
    }
};
