class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int N = queryCharacters.size(), M = s.size();
        vector<int> result(N);
        set<pair<int, int>> S, B;
        int i = 0;
        while (i < M)
        {
            int j = i;
            while (j + 1 < M && s[i] == s[j + 1])
                ++j;            
            S.insert({ i, j - i + 1 });
            B.insert({ j - i + 1, i });
            i = j + 1;
        }        
        for (int i = 0; i < N; ++i)
        {
            char c = queryCharacters[i];
            int pos = queryIndices[i];
            if (s[pos] != c)
            {
                s[pos] = c;
                auto it = prev(S.lower_bound({ pos, 200'000 }));
                int start = it->first, length = it->second;
                S.erase(it);
                B.erase({ length, start });
                if (start != pos)
                {
                    S.insert({ start, pos - start });
                    B.insert({ pos - start, start });
                }
                if (start + length - 1 != pos)
                {
					S.insert({ pos + 1, start + length - pos - 1 });
					B.insert({ start + length - pos - 1, pos + 1});
                }
                if (length == 1 && pos > 0 && pos < M - 1 && s[pos - 1] == c && s[pos + 1] == c)
                {
                    it = prev(S.lower_bound({ pos, 0 }));
                    int X = it->first, LX = it->second;
                    it = S.erase(it);
                    B.erase({ LX, X });
                    int Y = it->first, LY = it->second;
                    S.erase(it);
                    B.erase({ LY, Y });
                    S.insert({ X, LX + LY + 1 });
                    B.insert({ LX + LY + 1, X });
                    result[i] = B.rbegin()->first;
                    continue;
                }
                if (start == pos && pos > 0 && s[pos - 1] == c)
                {
                    it = prev(S.lower_bound({ pos, 0 }));
                    int A = it->first, L = it->second;
                    S.erase(it);
                    B.erase({ L, A });
                    S.insert({ A, L + 1 });
                    B.insert({ L + 1, A });
                    result[i] = B.rbegin()->first;
                    continue;
                }
                if (start + length - 1 == pos && pos < M - 1 && s[pos + 1] == c)
                {
                    it = S.lower_bound({ pos, 200'000 });
					int A = it->first, L = it->second;
					S.erase(it);
					B.erase({ L, A });
					S.insert({ A - 1, L + 1 });
					B.insert({ L + 1, A - 1 });
                    result[i] = B.rbegin()->first;
                    continue;
                }
                S.insert({ pos, 1 });
                B.insert({ 1, pos });                
            }
            result[i] = B.rbegin()->first;
        }
        return result;
    }
};
