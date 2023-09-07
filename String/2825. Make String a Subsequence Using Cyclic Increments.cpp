class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int N = str2.size(), M = str1.size();
        int pos = 0;
        for (int i = 0; i < N; ++i)
        {
            int x = str2[i] - 'a';
            if (pos == M)
                return false;
            while (pos < M)
            {
                int y = str1[pos] - 'a';
                ++pos;
                if (x == y || y - x == -1 || y - x == 25)
                    break;
                if (pos == M)
                    return false;
            }
        }
        return true;
    }
};
