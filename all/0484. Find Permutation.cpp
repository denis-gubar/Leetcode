class Solution {
public:
	vector<int> findPermutation(string s) {
		s.push_back('I');
		vector<int>	result;
		int high_watermark = 0, d_count = 0;
		for(char c : s)
			if (c == 'D')
			{
				++d_count;
			}
			else
			{
				for (int k = 0; k < d_count; ++k)
					result.push_back(high_watermark + d_count - k + 1);
                result.push_back(high_watermark + 1);
				high_watermark += d_count + 1;				
				d_count = 0;
			}
		return result;
	}
};