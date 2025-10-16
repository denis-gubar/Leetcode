class Solution {
public:
    bool canConvert(string str1, string str2) {
        if (str1 == str2)
            return true;
        if (unordered_set<char>(str2.begin(), str2.end()).size() == 26)
            return false;
        int N = str1.size();
        vector<unordered_set<int>> connectivity(26);
        for (int i = 0; i < N; ++i)
            connectivity[str1[i] - 'a'].insert(str2[i] - 'a');
        for (unordered_set<int> const& V : connectivity)
            if (V.size() >= 2)
                return false;
        return true;
    }
};