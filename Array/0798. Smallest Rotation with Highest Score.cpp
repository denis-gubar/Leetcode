class Solution {
public:
    int bestRotation( vector<int>& A ) {
        int result = 0, best = 0;
        int N = A.size();
        vector<int> starts( N ), ends( N );
        for (int i = 0; i < N; ++i)
            if (A[i] < N)
            {
                int v = A[i];
                int start = (i + 1) % N;
                int end = N - v - 1 + start;
                if (end < N)
                {
                    ++starts[start];
                    ++ends[end];
                }
                else
                {
                    ++starts[start];
                    ++ends[N - 1];
                    ++starts[0];
                    ++ends[end % N];
                }
            }
        int points = 0;
        for (int K = 0; K < N; ++K)
        {
            points += starts[K];
            if (points > best)
            {
                best = points;
                result = K;
            }
            points -= ends[K];            
        }
        return result;
    }
};