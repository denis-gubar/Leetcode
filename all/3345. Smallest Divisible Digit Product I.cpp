class Solution {
public:
    int smallestNumber(int n, int t) {
        int result = 0;
        for (int i = n; ; ++i)
        {
            int x = 1;
            for (char c : to_string(i))
                x *= c - '0';
            if (x % t == 0)
                return i;
        }
        return -1;
    }
};
