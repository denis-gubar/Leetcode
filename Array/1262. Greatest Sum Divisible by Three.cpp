class Solution {
public:
	int maxSumDivThree(vector<int>& nums) {
		int result = 0;
		vector<int> A1, A2;
		for (int n : nums)
			if (n % 3 == 0)
				result += n;
			else if (n % 3 == 1)
				A1.push_back(n);
			else if (n % 3 == 2)
				A2.push_back(n);
		sort(A1.begin(), A1.end());
		sort(A2.begin(), A2.end());
		while (A1.size() > 5)
		{
			result += A1.back(); A1.pop_back();
			result += A1.back(); A1.pop_back();
			result += A1.back(); A1.pop_back();
		}
		while (A2.size() > 5)
		{
			result += A2.back(); A2.pop_back();
			result += A2.back(); A2.pop_back();
			result += A2.back(); A2.pop_back();
		}
		vector<int> A(A1);
		for (int i : A2)
			A.push_back(i);
		int N = A.size();
		int best = 0;
		for (int x = 0; x < (1 << N); ++x)
		{
			int current = 0;
			for (int k = 0; k < N; ++k)
				if (x & (1 << k))
					current += A[k];
			if (current % 3 == 0 && current > best)
				best = current;
		}
		return result + best;
	}
};