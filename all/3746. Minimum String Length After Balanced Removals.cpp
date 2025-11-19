class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int const N = s.size();
        vector<int> A;
        A.reserve(N + 1);
        A.push_back(0);
        int balance = 0;
        unordered_map<int, int> M;
        ++M[0];
        for (int i = 0; i < N; ++i)
        {
            balance += (s[i] == 'a') - (s[i] == 'b');
            if (M[balance] != 0)
            {
                while (A.back() != balance)
                {
                    int x = A.back();
                    --M[x];
                    A.pop_back();
                }
                int x = A.back();
                --M[x];
                A.pop_back();
            }
            A.push_back(balance);
            ++M[balance];
        }
        return A.size() - 1;
    }
};
