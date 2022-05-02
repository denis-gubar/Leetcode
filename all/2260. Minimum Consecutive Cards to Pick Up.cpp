class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int N = cards.size();
        int result = N + 1;
        vector<int> M(1'000'001, -1'000'000);
        for (int i = 0; i < N; ++i)
        {
            result = min(result, i - M[cards[i]] + 1);
            M[cards[i]] = i;
        }
        if (result > N)
            result = -1;
        return result;
    }
};
