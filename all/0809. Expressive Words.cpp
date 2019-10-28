class Solution {
public:
    int expressiveWords( string S, vector<string>& words ) {
        int result = 0;
        vector<pair<int, int>> A;
        for (int i = 0; i < S.size(); ++i)
        {
            if (i && S[i] == S[i - 1])
                ++A.back().second;
            else
                A.push_back( { S[i], 1 } );
        }
        for (const string& word : words)
        {
            vector<pair<int, int>> B;
            for (int i = 0; i < word.size(); ++i)
            {
                if (i && word[i] == word[i - 1])
                    ++B.back().second;
                else
                    B.push_back( {word[i], 1} );
            }
            if (A.size() == B.size())
            {
                int flag = 1;
                for(int i = 0; i < A.size(); ++i)
                    if (A[i].first != B[i].first || A[i].second < B[i].second || (B[i].second == 1 && A[i].second == 2))
                    {
                        flag = 0; break;
                    }
                result += flag;
            }
        }

        return result;
    }
};