class Solution {
public:
	long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long K) {
		if (nums1.size() > nums2.size())
			nums1.swap(nums2);
		int const S1 = nums1.size(), S2 = nums2.size();
		vector<long long> negative1, negative2, positive1, positive2;
		negative1.reserve(S1);
		negative2.reserve(S2);
		positive1.reserve(S1);
		positive2.reserve(S2);
		for (int x : nums1)
			if (x < 0)
				negative1.push_back(-x);
			else
				positive1.push_back(x);
		for (int x : nums2)
			if (x < 0)
				negative2.push_back(-x);
			else
				positive2.push_back(x);
		reverse(negative2.begin(), negative2.end());
		int const N1 = negative1.size();
		int const N2 = negative2.size();
		int const P1 = positive1.size();
		int const P2 = positive2.size();
		long long a = -10'000'000'001LL;
		long long b = 10'000'000'001LL;
		auto calc = [&](long long m) -> long long
			{
				long long result = 0;
				if (m < 0)
				{
					for (int x : negative1)
					{
						int count = 0;
						auto it = lower_bound(positive2.begin(), positive2.end(), (-m + x - 1) / x);
						count += positive2.end() - it;
						result += count;
					}										
					for (int x : positive1)
					{
						int count = 0;
						if (x == 0)
						{
							if (m >= 0)
								count += N2;
						}
						else
						{
							auto it = lower_bound(negative2.begin(), negative2.end(), (-m + x - 1) / x);
							count += negative2.end() - it;
						}
						result += count;
					}
					return result;
				}
				result += 1LL * N1 * P2;
				result += 1LL * N2 * P1;
				for (int x : negative1)
				{
					int count = 0;
					auto it = upper_bound(negative2.begin(), negative2.end(), m / x);
                    if (it != negative2.end() && 1LL * *it * x <= m)
				        ++it;
					count += it - negative2.begin();
					result += count;
				}
				for (int x : positive1)
				{
					int count = 0;
					if (x == 0)
					{
						if (m >= 0)
							count += P2;
					}
					else
					{
						auto it = upper_bound(positive2.begin(), positive2.end(), m / x);
						if (it != positive2.end() && 1LL * *it * x <= m)
							++it;
						count += it - positive2.begin();
					}
					result += count;
				}
				return result;
			};
		while (a + 1 < b)
		{
			long long m = (a + b) / 2;
			if (calc(m) >= K)
				b = m;
			else
				a = m;
		}
		return b;
	}
};
