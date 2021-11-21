class Solution {
public:
	int minArea(vector<vector<char>>& image, int x, int y) {
		int result = 0;
		int N = image.size(), M = image[0].size();
		int topA = -1, topB = x, bottomA = x, bottomB = N;
		int leftA = -1, leftB = y, rightA = y, rightB = M;
		while (topA + 1 < topB || bottomA + 1 < bottomB || leftA + 1 < leftB || rightA + 1 < rightB)
		{
			if (topA + 1 < topB)
			{
				int topM = (topA + topB) / 2;
				bool blackFound = false;
				for (int j = leftA + 1; !blackFound && j < rightB; ++j)
					blackFound = image[topM][j] == '1';
				if (blackFound)
					topB = topM;
				else
					topA = topM;
			}
			if (rightA + 1 < rightB)
			{
				int rightM = (rightA + rightB) / 2;
				bool blackFound = false;
				for (int i = topA + 1; !blackFound && i < bottomB; ++i)
					blackFound = image[i][rightM] == '1';
				if (blackFound)
					rightA = rightM;
				else
					rightB = rightM;
			}
			if (bottomA + 1 < bottomB)
			{
				int bottomM = (bottomA + bottomB) / 2;
				bool blackFound = false;
				for (int j = leftA + 1; !blackFound && j < rightB; ++j)
					blackFound = image[bottomM][j] == '1';
				if (blackFound)
					bottomA = bottomM;
				else
					bottomB = bottomM;
			}
			if (leftA + 1 < leftB)
			{
				int leftM = (leftA + leftB) / 2;
				bool blackFound = false;
				for (int i = topA + 1; !blackFound && i < bottomB; ++i)
					blackFound = image[i][leftM] == '1';
				if (blackFound)
					leftB = leftM;
				else
					leftA = leftM;
			}
		}
		return (bottomB - topB) * (rightB - leftB);
	}
};