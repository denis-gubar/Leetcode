class Solution {
public:
	vector<string> readBinaryWatch(int num) {
		vector<string> result;
		for (unsigned int hh = 0; hh < 12; ++hh)
			for (unsigned int mm = 0, h = popcount(hh); mm < 60; ++mm)
				if (h + popcount(mm) == num)
					result.push_back(to_string(hh) + ":" + to_string(100 + mm).substr(1));
		return result;
	}
};