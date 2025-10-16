class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int W, int K) {
        int result = 0;
        int const N = arrivals.size();
        unordered_map<int, int> M;
        queue<int> Q;
        for (int i = 0; i < N; ++i)
        {
            bool isDiscarded = false;
            while (!Q.empty() && Q.front() == i)
                Q.pop(), isDiscarded = true;
            if (i >= W && !isDiscarded)
                --M[arrivals[i - W]];
            int const& x = arrivals[i];
            if (++M[x] > K)
                M[x] = K, Q.push(i + W), ++result;
        }
        return result;
    }
};
