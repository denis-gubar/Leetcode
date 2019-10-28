class Solution {
public:
	bool isStrobogrammatic(string num) {
		string good = "01689";
		string rotated = "01986";
		string rotatedNum;
		for (int c : num)
		{
			int pos = good.find(c);
			if (pos == string::npos)
				return false;
			rotatedNum += rotated[pos];
		}
		reverse(rotatedNum.begin(), rotatedNum.end());
		return num == rotatedNum;
	}
};