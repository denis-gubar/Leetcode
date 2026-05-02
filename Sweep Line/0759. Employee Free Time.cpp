/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> employeeFreeTime( vector<vector<Interval>>& avails ) {
        vector<Interval> result;
        set<int> S;
        S.insert( -1 );
        S.insert( 100011000 );
        for(const auto& i: avails)
            for (const auto& j : i)
            {
                S.insert( j.start ); S.insert( j.end );
            }
        map<int, int> M;
        vector<int> R;
        int k = 0;
        for (int x : S)
        {
            M[x] = k++;
            R.push_back( x );
        }
        vector<int> A(k);
        for (const auto& i : avails)
            for (const auto& j : i)
                for (int start = M[j.start]; start != M[j.end]; ++start)
                    A[start] = 1;
        int start = 0;
        for(int i = 1; i < k; ++i)
            if (A[i])
            {
                if (start)
                    result.push_back( Interval( R[start], R[i] ) );
                start = 0;
            }
            else if (!start)
            {
                start = i;
            }
        return result;
    }
};