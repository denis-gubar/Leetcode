class Solution {
public:
	vector<int> maxDepthAfterSplit(string seq) {
		vector<int> result(seq.size());
		int maxDepth = 0, depth = 0;
		for (int i = 0; i < seq.size(); ++i)
			if (seq[i] == '(')
			{
				++depth;
				maxDepth = max(maxDepth, depth);
			}
			else
				--depth;
		for (int i = 0; i < seq.size(); ++i)
		{
			if (seq[i] == '(')
			{
				++depth;
				if (depth > maxDepth / 2)
					result[i] = 1;
			}
			else
			{
				if (depth > maxDepth / 2)
					result[i] = 1;
				--depth;
			}
		}
		return result;
	}
};