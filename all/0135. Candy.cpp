class Solution {
public:
	int candy(vector<int>& ratings) {
        int const N = ratings.size();
		vector<int> A{ 1 };
        A.reserve(N);
		for (int i = 1; i < N; ++i)
			A.push_back((ratings[i] > ratings[i - 1]) ? A.back() + 1 : 1);
		for (int i = N - 1; i > 0; --i)
			if (ratings[i] < ratings[i - 1] && A[i] >= A[i - 1])
				A[i - 1] = A[i] + 1;
		return accumulate(A.begin(), A.end(), 0);
	}
};