class Solution {
public:
    vector<int> splitIntoFibonacci( string S ) {
        vector<int> result;
        int n = S.size();
        const long long INTMAX = numeric_limits<int>::max();
        for (int a = 1; a <= 10 && a < n; ++a)
        {
            long long A = stoll( S.substr( 0, a ) );
            if (A > INTMAX || to_string(A) != S.substr(0, a))
                break;            
            for (int b = 1; b <= 10 && a + b < n; ++b)
            {
                long long B = stoll( S.substr( a, b ) );
                if (B > INTMAX || to_string( B ) != S.substr( a, b ))
                    break;
                result.clear();
                result.push_back( A );
                result.push_back( B );
                long long F0 = A, F1 = B;
                int f0 = a, f1 = b;
                int length = a + b;
                bool correct = true;
                while (length < n)
                {
                    long long NEXT = F0 + F1;
                    string X = to_string( NEXT );
                    if (NEXT < 0 || NEXT > INTMAX || length + X.size() > n || S.substr( length, X.size() ) != X)
                    {
                        correct = false;
                        break;
                    }
                    length += X.size();
                    F0 = F1;
                    F1 = NEXT;
                    f0 = f1;
                    f1 = X.size();
                    result.push_back( NEXT );
                }
                if (!correct)
                    continue;
                return result;
            }            
        }
        return {};
    }
};