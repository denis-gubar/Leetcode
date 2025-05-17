class Solution {
public:
    int minFlips(int a, int b, int c) {
        auto count = [](int x) -> int
            {
                int result = 0;
                while (x > 0)
                {
                    x &= x - 1;
                    ++result;
                }
                return result;
            };
        return count(~(a | b) & c) + count(a & ~c) + count(b & ~c);
    }
};
