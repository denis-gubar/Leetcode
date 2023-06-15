static bool isVowel(char c)
{
    return "aeiou"s.find(c) != string::npos;
}
class Solution {
public:
    int maxVowels(string s, int k) {
        int result = 0;
        int sum = 0;
        int N = s.size();
        auto add = [&sum](char x)
        {
            sum += isVowel(x);
        };
        auto remove = [&sum](char x)
        {
            sum -= isVowel(x);
        };
        auto process = [&sum, &result]()
        {
            result = max(result, sum);
        };
        for (int i = 0; i < N; ++i)
        {
            add(s[i]);
            if (i >= k)
                remove(s[i - k]);
            if (i >= k - 1)
                process();
        }
        return result;
    }
};
