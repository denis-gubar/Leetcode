class Solution {
public:
    int addDigits(int num) {
        if (!num)
            return 0;
        return (num + 8) % 9 + 1;
    }
};