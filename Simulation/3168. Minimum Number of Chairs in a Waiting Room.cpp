class Solution {
public:
    int minimumChairs(string s) {
        int result = 0, balance = 0;
        for (char c : s)
            if (c == 'E')
                result = max(result, ++balance);
            else
                --balance;
        return result;
    }
};

