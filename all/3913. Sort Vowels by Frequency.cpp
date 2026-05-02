class Solution {
public:
    string sortVowels(string s) {
        string result = s;
        string vowels = "aeiou";
        vector<int> I(5);
        iota(I.begin(), I.end(), 0);
        unordered_map<char, int> M, pos;
        int const N = s.size();
        for (int i = 0; i < N; ++i)
        {
            char const& c = s[i];
            if (vowels.find(c) != string::npos)
            {
                ++M[c];
                if (pos.find(c) == pos.end())
                    pos[c] = i;
            }
        }
        sort(I.begin(), I.end(), [&](int a, int b)
            {
                char A = vowels[a];
                char B = vowels[b];
                if (M[A] == M[B])
                    return pos[A] < pos[B];
                return M[A] > M[B];
            });
        int x = 0;
        for (int i = 0; i < N; ++i)
        {
            char& c = result[i];
            if (vowels.find(c) != string::npos)
            {
                result[i] = vowels[I[x]];
                if (--M[vowels[I[x]]] == 0)
                    ++x;
            }
        }
        return result;
    }
};
