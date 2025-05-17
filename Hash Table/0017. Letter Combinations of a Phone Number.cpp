class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        array<string, 10> const M{ "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        string prefix;
        int const N = digits.size();
        function<void(void)> dfs = [&]() -> void
            {
                if (prefix.size() == N)
                {
                    result.push_back(prefix);
                    return;
                }
                for (char c : M[digits[prefix.size()] - '0'])
                {
                    prefix += c;
                    dfs();
                    prefix.pop_back();
                }
            };
        if (N > 0) dfs();
        return result;
    }
};
