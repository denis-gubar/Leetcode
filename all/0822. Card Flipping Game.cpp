class Solution {
public:
    int flipgame( vector<int>& fronts, vector<int>& backs ) {
        int N = fronts.size();
        set<int> S;
        for (int i : fronts)
            S.insert(i);
        for (int i : backs)
            S.insert(i);
        vector<int> M( 2001, 1 );
        for (int i = 0; i < N; ++i)
            if (fronts[i] == backs[i])
                M[fronts[i]] = 0;            
        for (int k : S)
        {
            if (M[k])
                return k;
        }
        return 0;
    }
};