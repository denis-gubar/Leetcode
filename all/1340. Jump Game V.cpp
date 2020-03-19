class Solution {
public:
	int maxJumps(vector<int>& arr, int d) {
		int N = arr.size();
		vector<int> F(N), index(N);
		for (int i = 0; i < N; ++i)
			index[i] = i;
		sort(index.begin(), index.end(), [&arr](int a, int b)
			{
				return arr[a] < arr[b];
			});
		for (int i : index)
		{
			int a = i;
			int b = i;
			for (int k = 1; k <= d && i + k < N; ++k)
				if (arr[i] > arr[i + k])
					b = i + k;
                else
                    break;
			for (int k = 1; k <= d && i - k >= 0; ++k)
				if (arr[i] > arr[i - k])
					a = i - k;
                else
                    break;
			F[i] = 1 + *max_element(F.begin() + a, F.begin() + b + 1);
		}
		return *max_element(F.begin(), F.end());
	}
};