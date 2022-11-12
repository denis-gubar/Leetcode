class Solution {
public:
    string similarRGB(string const& color) {
        string digits{ "0123456789abcdef" };
        auto calc = [&color, &digits](int pos)
        {
            vector<int> A(16);
            iota(A.begin(), A.end(), 0);
            return *min_element(A.begin(), A.end(), [&digits, &color, pos](int a, int b)
                {
                    return abs(static_cast<int>(digits.find(color[pos * 2 + 1])) * 16 +
                               static_cast<int>(digits.find(color[pos * 2 + 2])) - a * 17) <
                        abs(static_cast<int>(digits.find(color[pos * 2 + 1])) * 16 +
                            static_cast<int>(digits.find(color[pos * 2 + 2])) - b * 17);
                });
        };
        int x = calc(0), y = calc(1), z = calc(2);
        return "#" + string(2, digits[x]) + string(2, digits[y]) + string(2, digits[z]);
    }
};
