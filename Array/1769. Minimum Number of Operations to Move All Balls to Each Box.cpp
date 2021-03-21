class Solution {
public:
	vector<int> minOperations(string boxes) {
		int N = boxes.size();
		vector<int> result;
		int left = 0, right = count(boxes.begin(), boxes.end(), '1');
		int current = 0;
		for (int i = 0; i < N; ++i)
			if (boxes[i] == '1')
				current += i;
		result.push_back(current);
		for (int i = 0; i + 1 < N; ++i)
		{
			if (boxes[i] == '1')
				--right, ++left;
			current -= right;
			current += left;
			result.push_back(current);
		}
		return result;
	}
};