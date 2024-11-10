class Solution {
public:
    bool rotateString( string A, string B ) {
        int N = A.size();
        for (int i = 0; i < N; ++i)
        {
            rotate( B.begin(), B.begin() + 1, B.end() );
            if (A == B)
                return true;
        }
        return false;
    }
};