class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int N = pref.size();
        vector<int> result(N);
        int balance = 0;
        for (int i = 0; i < N; ++i)
        {
            result[i] = pref[i] ^ balance;
            balance ^= result[i];
        }
        return result;
    }
};
