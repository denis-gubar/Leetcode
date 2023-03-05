class Solution {
public:
    int minimumScore(string s, string t) {
        int result = t.size();
        int A = s.size(), N = t.size();
        vector<int> left(N, A), right(N, -1);
        size_t pos = 0;
        for (int i = 0; i < N; ++i)
        {
            size_t next_pos = s.find(t[i], pos);
            if (next_pos == string::npos)
                break;
            left[i] = next_pos;
            pos = ++next_pos;
            if (pos == A)
                break;
        }
        if (left.back() < A)
            return 0;
        pos = A - 1;
        for (int i = N - 1; i >= 0; --i)
        {
            size_t next_pos = s.rfind(t[i], pos);
            if (next_pos == string::npos)
                break;
            right[i] = next_pos;
            if (next_pos == 0)
                break;
            pos = next_pos - 1;
        }
        result = min(result,  N - static_cast<int>(right.end() - upper_bound(right.begin(), right.end(), -1)));
        for (int i = 0; i < N; ++i)
        {
            if (left[i] == A)
                break;
            auto it = upper_bound(right.begin() + i, right.end(), left[i]);
            result = min(result, N - static_cast<int>(right.end() - it) - i - 1);
        }
        return result;
    }
};
