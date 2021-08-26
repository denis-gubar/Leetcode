class Solution {
public:
	int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
		int result = 0;
		sort(boxes.begin(), boxes.end());
		int W = warehouse.size();
		for (int i = 1; i < W; ++i)
			warehouse[i] = min(warehouse[i], warehouse[i - 1]);
		int pos = W - 1;
		for (int i = 0; pos >= 0 && i < boxes.size(); ++i)
		{
			while (pos >= 0 && boxes[i] > warehouse[pos])
				--pos;
			if (pos >= 0)
				++result, --pos;
		}
		return result;
	}
};