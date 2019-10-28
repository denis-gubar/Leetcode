class Solution {
public:
    int check(string const& s, int a, int b, int L)
    {
        int i = 0;
        while(b + i < s.size() && i < L)
        {
            if (s[a + i] < s[b + i])
                return 0;
            if (s[a + i] > s[b + i])
                return 1;
            ++i;
        }
        return 2;
    }
	string lastSubstring(string s) {
		int N = s.size();
		char c = *max_element(s.begin(), s.end());
		vector<int> A;
		for (int i = 0; i < N; ++i)
			if (s[i] == c)
				A.push_back(i);
		int a = 0, b = 1;
		while (b < A.size())
		{
			int L = A[b] - A[a] + 1;
            int endB = A[b] + L - 1;
            int x = check(s, A[a], A[b], L);
            if (!x)
				a = b;
			++b;
            while(x == 2 && b < A.size() && A[b] < endB)
                ++b;
		}
		return s.substr(A[a]);
	}
};