class Solution {
public:
	bool squareIsWhite(string coordinates) {
		return (coordinates[0] % 2 + coordinates[1] % 2) % 2 == 1;
	}
};