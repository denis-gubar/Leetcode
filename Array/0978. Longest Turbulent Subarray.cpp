class Solution {
public:
	int maxTurbulenceSize(vector<int>& A) {
		int result = 1;
        for (int z = 0; z < 2; ++z)
        {
            int current = 1;
            for (int i = 0; i + 1 < A.size(); ++i)
                if (i % 2 == z)
                {
                    if (A[i] > A[i + 1])
                        result = max(result, ++current);
                    else
                        current = 1;
                }
                else
                {
                    if (A[i] < A[i + 1])
                        result = max(result, ++current);
                    else
                        current = 1;
                }
		}
		return result;
	}
};