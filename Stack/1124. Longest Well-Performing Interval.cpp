class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int result = 0;
        int* const H = hours.data();
        int const N = hours.size();
        unique_ptr<int[]> A(new int[N + 1]);
        deque<int> Q;
        A[0] = 0;
        for (int i = 0; i < N; ++i)
        {
            A[i + 1] = A[i] + (H[i] > 8) - (H[i] <= 8);
            while (!Q.empty() && A[Q.back()] <= A[i + 1])
                Q.pop_back();
            Q.push_back(i + 1);
        }
        for (int i = 0; i <= N; ++i)
        {
            while (!Q.empty() && A[i] < A[Q.front()])
                result = max(result, Q.front() - i), Q.pop_front();
            if (Q.empty())
                break;
        }
        return result;
    }
};
