/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
public:
	int countShips(Sea& sea, vector<int> topRight, vector<int> bottomLeft, bool hasShip = false) {
		int width = topRight[0] - bottomLeft[0];
		int length = topRight[1] - bottomLeft[1];
		if (width == 0 && length == 0)
			if (hasShip)
				return 1;
			else
				return sea.hasShips(topRight, bottomLeft);
		int result = 0;
		if (sea.hasShips({ bottomLeft[0] + width / 2, bottomLeft[1] + length / 2 },
			{ bottomLeft[0], bottomLeft[1] }))
		{
			result += countShips(sea,
				{ bottomLeft[0] + width / 2, bottomLeft[1] + length / 2 },
				{ bottomLeft[0], bottomLeft[1] },
				true);
		}
		if (width > 0 && sea.hasShips({ bottomLeft[0] + width, bottomLeft[1] + length / 2 },
			{ bottomLeft[0] + width / 2 + 1, bottomLeft[1] }))
		{
			result += countShips(sea,
				{ bottomLeft[0] + width, bottomLeft[1] + length / 2 },
				{ bottomLeft[0] + width / 2 + 1, bottomLeft[1] },
				true);
		}
		if (length > 0 && sea.hasShips({ bottomLeft[0] + width / 2, bottomLeft[1] + length },
			{ bottomLeft[0], bottomLeft[1] + length / 2 + 1 }))
		{
			result += countShips(sea,
				{ bottomLeft[0] + width / 2, bottomLeft[1] + length },
				{ bottomLeft[0], bottomLeft[1] + length / 2 + 1 },
				true);
		}
		if (width > 0 && length > 0 && sea.hasShips({ bottomLeft[0] + width, bottomLeft[1] + length },
			{ bottomLeft[0] + width / 2 + 1, bottomLeft[1] + length / 2 + 1 }))
		{
			result += countShips(sea,
				{ bottomLeft[0] + width, bottomLeft[1] + length },
				{ bottomLeft[0] + width / 2 + 1, bottomLeft[1] + length / 2 + 1 },
				true);
		}
		return result;
	}
};