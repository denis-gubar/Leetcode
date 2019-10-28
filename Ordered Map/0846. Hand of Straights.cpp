class Solution {
public:
	bool isNStraightHand(vector<int>& hand, int W) {
		int N = hand.size();
		if (N % W)
			return false;
		multiset<int> S;
		for (int i : hand)
			S.insert(i);
		for (int k = 0; k < N / W; ++k)
		{
			for (int j = 0, i = *S.begin(); j < W; ++j, ++i)
				if (S.find(i) == S.end())
					return false;
				else
					S.erase(S.find(i));
		}
		return true;
	}
};