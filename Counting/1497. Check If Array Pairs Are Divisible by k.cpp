class Solution {
public:
	bool canArrange(vector<int>& arr, int k) {
		unique_ptr<int[]> A = make_unique<int[]>(k);
		for (int x : arr)
			++A[(x % k + k) % k];
		if (A[0] % 2 == 1) return false;
		for (int a = 1, b = k - 1; a <= b; ++a, --b)
		{
			if (A[a] != A[b])
				return false;
			if (a == b && A[a] % 2 == 1)
				return false;
		}
		return true;
	}
};