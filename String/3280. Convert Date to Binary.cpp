class Solution {
public:
    string convertDateToBinary(string date) {
        auto calc = [](string x)
            {
                string result;
                int n = stoi(x);
                while (n)
                {
                    result += (n % 2) + '0';
                    n /= 2;
                }
                reverse(result.begin(), result.end());
                return result;
            };
        return calc(date.substr(0, 4)) + "-" + calc(date.substr(5, 2)) + "-" + calc(date.substr(8, 2));
    }
};
