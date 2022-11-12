class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> A(26);
        for (char c : word)
            ++A[c - 'a'];
        for (int j = 0; j < 26; ++j)
            if (A[j] > 0)
            {
                vector<int> F;
                --A[j];
                for (int i = 0; i < 26; ++i)
                    if (A[i] != 0)
                        F.push_back(A[i]);
                sort(F.begin(), F.end());
                if (F[0] == F.back())
                    return true;
                ++A[j];
            }
        return false;
    }
};
