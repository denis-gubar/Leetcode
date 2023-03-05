class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int result = 0;
        int N = prizePositions.size();
        deque<int> D;
        vector<int> A(N), B(N);
        for (int i = 0; i < N; ++i)
        {
            D.push_back(prizePositions[i]);
            while (D.back() - D.front() > k)
                D.pop_front();
            A[i] = D.size();
        }
        D.clear();
        for (int i = N - 1; i >= 0; --i)
        {
            D.push_front(prizePositions[i]);
            while (D.back() - D.front() > k)
                D.pop_back();
            B[i] = D.size();
        }
        multiset<int> SA, SB;
        for (int i = 0; i < N; ++i)
            SB.insert(B[i]);
        for (int i = 0; i < N; ++i)
        {
            int prefix = 0;
            if (!SA.empty())
                prefix = *SA.rbegin();
            result = max(result, prefix + *SB.rbegin());
            SB.erase(SB.find(B[i]));
            SA.insert(A[i]);
        }
        return result;
    }
};
