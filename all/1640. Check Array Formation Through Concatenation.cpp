class Solution {
public:
	bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
		int pos = -1, pos2 = 0;
		for (int i = 0; i < arr.size(); ++i)
		{
			if (pos == -1)
			{
				for (int k = 0; k < pieces.size(); ++k)
					if (pieces[k][0] == arr[i])
					{
						pos = k, pos2 = 0;
						break;
					}
			}
			if (pos == -1)
				return false;
			if (pieces[pos][pos2] != arr[i])
				return false;
			++pos2;
			if (pos2 == pieces[pos].size())
				pos = -1;
		}
		return true;			
	}
};