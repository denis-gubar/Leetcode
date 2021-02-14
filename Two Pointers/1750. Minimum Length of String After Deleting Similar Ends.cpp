class Solution {
public:
	int minimumLength(string s) {
		deque<char> A(s.begin(), s.end());
		while (A.size() > 1 && A.front() == A.back())
		{
			char x = A.back();
			while (!A.empty() && A.front() == x)
				A.pop_front();
			while (!A.empty() && A.back() == x)
				A.pop_back();
		}
		return A.size();
	}
};