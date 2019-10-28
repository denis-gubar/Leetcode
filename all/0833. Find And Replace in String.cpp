class Solution {
public:
    string findReplaceString( string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets ) {
        string result;
        int N = S.size();
        vector<string> A( N );
        for (int i = 0; i < N; ++i)
            A[i] = string( 1, S[i] );
        for(int i = 0; i < indexes.size(); ++i)
            if (S.substr( indexes[i], sources[i].size() ) == sources[i])
            {
                for (int j = 0; j < sources[i].size(); ++j)
                    A[indexes[i] + j] = "";
                A[indexes[i]] = targets[i];
            }
        result = accumulate( A.begin(), A.end(), string() );
        return result;
    }
};