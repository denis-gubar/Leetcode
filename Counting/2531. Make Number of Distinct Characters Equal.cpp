class Solution {
public:
    vector<int> calc(string const& s)
    {
        vector<int> result(26);
        for (char c : s)
            ++result[c - 'a'];
        return result;
    }
    bool isItPossible(string word1, string word2) {
        vector<int> A = calc(word1);
        vector<int> B = calc(word2);
        for(char a = 'a'; a <= 'z'; ++a)
            if (A[a - 'a'] > 0)
                for(char b = 'a'; b <= 'z'; ++b)
                    if (B[b - 'a'] > 0)
                    {
                        --A[a - 'a'];
                        --B[b - 'a'];
                        ++A[b - 'a'];
                        ++B[a - 'a'];
                        int balance = 0;
                        for (int x : A)
                            if (x > 0)
                                ++balance;
                        for (int x : B)
                            if (x > 0)
                                --balance;
                        if (balance == 0)
                            return true;
                        ++A[a - 'a'];
                        ++B[b - 'a'];
                        --A[b - 'a'];
                        --B[a - 'a'];
                    }
        return false;
    }
};
