class Solution {
public:
    string makeLargestSpecial( string S ) {
        string result = S;
        int n = S.size();
        vector<string> results;
        results.push_back( S );
        while (!results.empty())
        {
            results.clear();
            for (int i = 0; i + 1 < n; ++i)
                if (S[i] == '1')
                {
                    int a = 0, b = 0;
                    for (int k = 2; i + k < n; k += 2)
                    {
                        a += S[i + k - 2] == '0';
                        b += S[i + k - 2] == '1';
                        if (a > b)
                            break;
                        a += S[i + k - 1] == '0';
                        b += S[i + k - 1] == '1';
                        if (a > b)
                            break;
                        if (a == b && S[i + k] == '1')
                        {
                            int j = i + k;
                            int c = 0, d = 0;
                            for (int t = 2; j + t <= n; t += 2)
                            {
                                c += S[j + t - 2] == '0';
                                d += S[j + t - 2] == '1';
                                if (c > d)
                                    break;
                                c += S[j + t - 1] == '0';
                                d += S[j + t - 1] == '1';
                                if (c > d)
                                    break;
                                if (c == d && S.substr( i, k ) < S.substr( j, t ))
                                {
                                    string current = S.substr( 0, i ) + S.substr( j, t ) + S.substr( i, k ) + S.substr( j + t );
                                    if ( current > S )
                                        results.push_back( current );
                                }
                            }
                        }
                    }
                }
            if (!results.empty())
            {
                result = S = *max_element( results.begin(), results.end() );
                results = { result };
            }
        }
        return result;
    }
};