static short int M[26];
class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        memset(M, 0, sizeof(M));
        for (char c : s)
            ++M[c - 'a'];
        int oddCount = 0, oddC = -1;
        for (int c = 0; c < 26; ++c)
        {
            if (M[c] % 2 == 1)
                ++oddCount, oddC = c + 'a';
            M[c] /= 2;
        }
        if (oddCount > 1)
            return {};
        int const N = s.size();        
        string result;
        result.reserve(N + 2);
        auto dfs = [&](this const auto& self, bool isB) -> bool
            {
                if (result.size() == N / 2)
                {
                    if (oddCount)
                        result += oddC;
                    for (int i = N / 2 - 1; i >= 0; --i)
                        result += result[i];
                    if (!isB || result > target)
                        return true;
                    result.resize(N / 2);
                    return false;
                }
                int x = target[result.size()] - 'a';
                if (isB)
                {
                    if (M[x])
                    {
                        --M[x];
                        result += x + 'a';
                        if (self(isB))
                            return true;
                        result.pop_back();
                        ++M[x];
                    }
                    ++x;
                    for (; x < 26; ++x)
                        if (M[x])
                        {
                            --M[x];
                            result += x + 'a';
                            if (self(false))
                                return true;
                            result.pop_back();
                            ++M[x];
                            break;
                        }
                }
                else
                {
                    for (int x = 0; x < 26; ++x)
                        if (M[x])
                        {
                            --M[x];
                            result += x + 'a';
                            if (self(isB))
                                return true;
                            result.pop_back();
                            ++M[x];
                            break;
                        }
                }
                return false;
            };
        dfs(true);
        return result;
    }
};
