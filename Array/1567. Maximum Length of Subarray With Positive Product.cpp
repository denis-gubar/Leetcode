class Solution {
public:
	int getMaxLen(vector<int>& nums) {
		int result = 0;
		nums.push_back(0);
		vector<int>	A;
		for (int n : nums)
		{
			if (n == 0)
			{				
				int left = -1, right = -1;
                int parity = 0;
				for (int i = 0; i < A.size(); ++i)
				{
					if (A[i] && left < 0)
						left = i;
					if (A[i])
						right = i;
                    if (A[i])
                        parity = 1 - parity;
				}
				if (right < 0 || parity == 0)
					result = max<int>(result, A.size());
				else
				{
					result = max<int>(result, A.size() - left - 1);
					result = max<int>(result, right);
				}
                A.clear();
			}
			if (n < 0)
				A.push_back(1);
			if (n > 0)
				A.push_back(0);
		}
		return result;
	}
};