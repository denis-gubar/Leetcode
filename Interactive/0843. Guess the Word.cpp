/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int guess( const string& secret, const string& word )
    {
        int result = 0;
        for (int i = 0; i < 6; ++i)
            result += secret[i] == word[i];
        return result;
    }
    void findSecretWord( vector<string>& wordlist, Master& master ) {
        vector<string> filtered( wordlist );
        for (int guessCount = 0; guessCount < 10; ++guessCount)
        {
            vector<int> M( filtered.size() );
            for (int i = 0; i < filtered.size(); ++i)
            {
                string f = filtered[i];
                vector<int> A( 7 );
                for (const string& o : filtered)
                    ++A[guess( f, o )];
                M[i] = *max_element( A.begin(), A.end() );
            }
            int k = distance( M.begin(), min_element( M.begin(), M.end() ) );
            int g = master.guess( filtered[k] );
            if (g == 6)
                return;
            vector<string> nextFiltered;
            for (const string& o : filtered)
                if (guess( o, filtered[k] ) == g)
                    nextFiltered.push_back( o );
            filtered = move( nextFiltered );
        }
    }
};