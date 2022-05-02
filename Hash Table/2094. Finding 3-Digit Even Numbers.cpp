class Solution {
public:
	vector<int> findEvenNumbers(vector<int>& digits) {
		vector<int> result;
		for (int x = 100; x < 1000; x += 2)
		{
			int count = 0;
			vector<int> A = { x % 10, x / 10 % 10, x / 100 % 10 };
			unordered_map<int, int> M1, M2;
			for (int a : A)
				++M1[a];
			for (int d : digits)
				++M2[d];
			bool isOk = true;
			for (auto [key, value] : M1)
				isOk &= M2[key] >= value;
			if (isOk)
				result.push_back(x);
		}
		return result;
	}
};