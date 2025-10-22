class Solution {
public:
    string filterCharacters(string s, int k) {
        int const N = s.size();
        string result;
        result.reserve(N);
        unordered_map<char, int> M;
        for(char c : s)
            ++M[c];
        for(auto it = M.begin(); it != M.end(); )
            if (it->second >= k)
                it = M.erase(it);
            else
                ++it;
        for(char c : s)
            if (M.find(c) != M.end())
                result += c;
        return result;
    }
};