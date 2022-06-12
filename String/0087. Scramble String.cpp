class Solution {
public:
    bool calc(int first1, int last1, int first2, int last2)
    {
        if (!visited[first1][last1][first2])
        {
            visited[first1][last1][first2] = true;
            if (A[first1][last1][first2])
                if (bool result = first1 == last1; !result)
                {
                    for (int pivot = first1; !result && pivot < last1; ++pivot)
                    {
                        int left = pivot - first1;
                        int right = last1 - pivot - 1;
                        result = calc(first1, first1 + left, first2, first2 + left) &&
                            calc(last1 - right, last1, last2 - right, last2) ||
                            calc(last1 - left, last1, first2, first2 + left) &&
                            calc(first1, first1 + right, last2 - right, last2);
                    }
                    A[first1][last1][first2] = result;
                }
        }
        return A[first1][last1][first2];
    }
    bool isScramble(string const& s1, string const& s2) {
        int N = s1.size();
        visited = A = vector<vector<vector<bool>>>(N, vector<vector<bool>>(N, vector<bool>(N)));
        for (int first1 = 0; first1 < N; ++first1)
            for (int last1 = first1; last1 < N; ++last1)
                for (int first2 = 0, last2 = last1 - first1; last2 < N; ++first2, ++last2)
                {
                    bool isAnagram = true;
                    for (int i = first1; isAnagram && i <= last1; ++i)
                        isAnagram = (count(s1.begin() + first1, s1.begin() + last1 + 1, s1[i]) ==
                            count(s2.begin() + first2, s2.begin() + last2 + 1, s1[i]));
                    A[first1][last1][first2] = isAnagram;
                }
        return calc(0, N - 1, 0, N - 1);
    }
    vector<vector<vector<bool>>> A, visited;
};
