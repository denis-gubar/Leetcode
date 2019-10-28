class Solution {
public:
    string pushDominoes( string dominoes ) {
        string result{ dominoes };
        int n = dominoes.size();
        queue<int> L, R;
        for (int i = 0; i < n; ++i)
            if (dominoes[i] == 'L')
                L.push( i );
            else if (dominoes[i] == 'R')
                R.push( i );
        while (!L.empty() || !R.empty())
        {
            queue<int> NL, NR;
            while (!L.empty())
            {
                int x = L.front(); L.pop();
                if (x && dominoes[x - 1] == '.' && (x == 1 || dominoes[x - 2] != 'R'))
                {
                    result[x - 1] = 'L';
                    NL.push( x - 1 );
                }
            }
            while (!R.empty())
            {
                int x = R.front(); R.pop();
                if (x + 1 < n && dominoes[x + 1] == '.' && (x + 2 == n || dominoes[x + 2] != 'L'))
                {
                    result[x + 1] = 'R';
                    NR.push( x + 1 );
                }
            }
            L = move( NL );
            R = move( NR );
            dominoes = result;
        }
        return result;
    }
};