static short int M[26];
class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        sort(s.begin(), s.end());
        if (s > target)
            return s;
        if (string(s.rbegin(), s.rend()) <= target)
            return {};
        for (char c : s)
            ++M[c - 'a'];
        int const N = s.size();
        string result;
        result.reserve(N);
        auto dfs = [&](this const auto& self, bool isB) -> bool
            {
                if (result.size() == N)
                    return !isB;
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
                    for(; x < 26; ++x)
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
                    for(int x = 0; x < 26; ++x)
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
