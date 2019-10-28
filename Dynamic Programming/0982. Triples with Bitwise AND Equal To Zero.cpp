class Solution {
public:
	int countTriplets(vector<int>& A) {
		vector<int> AND(1 << 16);
		int result = 0;
		for (int a : A)
			for (int b : A)
				++AND[a & b];
		for (int a : A)
			for (int b = 0; b < (1 << 16); ++b)
				if ((a & b) == 0)
					result += AND[b];
		return result;
	}
};