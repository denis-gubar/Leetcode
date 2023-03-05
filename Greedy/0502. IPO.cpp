class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int N = profits.size();
        int result = w;
        vector<int> A(N);
        iota(A.begin(), A.end(), 0);
        sort(A.begin(), A.end(), [&capital](int a, int b)
            {
                return capital[a] < capital[b];
            });
        priority_queue<int> PQ;
        int pos = 0;
        while (k > 0)
        {
            while (pos < N && capital[A[pos]] <= result)
            {
                PQ.push(profits[A[pos]]);
                ++pos;
            }
            if (PQ.empty())
                break;
            result += PQ.top(); PQ.pop();
            --k;
        }
        return result;
    }
};
