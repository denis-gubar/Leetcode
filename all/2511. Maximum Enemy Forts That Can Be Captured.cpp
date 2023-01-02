class Solution {
public:
    int captureForts(vector<int>& forts) {
        int result = 0;
        int N = forts.size();
        for (int i = 0; i < N; ++i)
            if (forts[i] == 1)
            {
                int left = 0, right = 0;
                int j;
                for (j = i - 1; j >= 0; --j)
                    if (forts[j] != 0)
                        break;
                    else
                        ++left;
                if (j < 0 || forts[j] != -1)
                    left = 0;
                for (j = i + 1; j < N; ++j)
                    if (forts[j] != 0)
                        break;
                    else
                        ++right;
                if (j == N || forts[j] != -1)
                    right = 0;
                result = max({ result, left, right });
            }
        return result;
    }
};
