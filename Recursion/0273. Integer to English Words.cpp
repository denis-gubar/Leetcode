static vector<string> const numbers1{"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
                        "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
                        "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
static vector<string> const numbers2{ "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
static vector<string> const numbers3{ "", "Thousand", "Million", "Billion" };
class Solution {
public:
    void add(string& result, string const& s)
    {
        if (!s.empty())
        {
            if (!result.empty())
                result += ' ';
            result += s;
        }
    }
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";
        string result;
        auto block = [&](string const& s) -> string
            {
                int num = stoi(s);
                if (num < numbers1.size())
                    return numbers1[num];
                string result;
                if (num > 99)
                {
                    result += numbers1[num / 100];
                    result += ' ';
                    result += "Hundred";
                }
                num %= 100;
                if (num > 19)
                {
                    add(result, numbers2[num / 10]);
                    num %= 10;
                }
                add(result, numbers1[num]);
                return result;
            };
        string s = to_string(num), r;
        copy(s.rbegin(), s.rend(), back_inserter(r));
        int const N = s.size();
        vector<string> groups;
        for (int i = 0, g = 0; i < N; i += 3, ++g)
        {
            groups.push_back({});
            for (int k = 0; k < 3 && i + k < N; ++k)
                groups.back() += r[i + k];
            reverse(groups.back().begin(), groups.back().end());
            groups.back() = block(groups.back());
            if (!groups.back().empty() && g > 0)
                groups.back() += ' ', groups.back() += numbers3[g];
        }
        reverse(groups.begin(), groups.end());
        for (string const& g : groups)
            add(result, g);
        return result;
    }
};
