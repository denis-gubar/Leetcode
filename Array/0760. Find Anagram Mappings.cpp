class Solution {
public:
    vector<int> anagramMappings( vector<int>& A, vector<int>& B ) {
        vector<int> result( A.size() );
        map<int, int> M;
        for (int i = 0; i < A.size(); ++i)
            M[B[i]] = i;
        for (int i = 0; i < A.size(); ++i)
            result[i] = M[A[i]];
        return result;
    }
};