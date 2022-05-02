class Solution {
public:
    int minimumSum(int num) {
        int result = num;
        string s = to_string(num);
        sort(s.begin(), s.end());
        int N = s.size();
        do
        {
            int current = 0;
            for (int i = 1; i < N; ++i)
            {
                int x = stoi(s.substr(0, i)) + stoi(s.substr(i));
                result = min(result, x);
            }
        } while (next_permutation(s.begin(), s.end()));
        return result;
    }
};
