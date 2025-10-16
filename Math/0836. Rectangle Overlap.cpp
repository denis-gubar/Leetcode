class Solution {
public:
	bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
		bool result = true;
		for (int i = 0; i < 2; ++i)
			result &= !(rec1[i + 2] <= rec2[i] || rec2[i + 2] <= rec1[i]);
		return result;
	}
};