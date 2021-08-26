class Solution {
public:
	int trap(vector<int>& height) {
		int result = 0;
		int N = height.size();
		vector<int>	L(height), R(height);
		for (int i = 1; i < N; ++i)
			L[i] = max(L[i - 1], height[i]);
		for (int i = N - 2; i >= 0; --i)
			R[i] = max(R[i + 1], height[i]);
		for (int i = 0; i < N; ++i)
			result += min(L[i], R[i]) - height[i];
		return result;
	}
};