class Solution {
public:
    string stringHash(string s, int k) {
        int const N = s.size();
        int count = N / k;
        string result(count, 0);
        for (int i = 0, pos = 0; i < count; ++i)
            for (int j = 0; j < k; ++j, ++pos)
                result[i] = (result[i] + (s[pos] - 'a')) % 26;
        for (char& c : result)
            c += 'a';
        return result;
    }
};
