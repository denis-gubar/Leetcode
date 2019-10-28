class Solution {
public:
	int smallestCommonElement(vector<vector<int>>& mat) {
		int result = -1;
		for (int i = 0; i < mat[0].size(); ++i)
		{
			bool flag = true;
			for (int j = 1; flag && j < mat.size(); ++j)
				flag &= binary_search(mat[j].begin(), mat[j].end(), mat[0][i]);
			if (flag)
			{
				result = mat[0][i];
				break;
			}
		}
		return result;
	}
};