class Leaderboard {
public:
	Leaderboard() {
		M.clear();
		S.clear();
	}

	void addScore(int playerId, int score) {
		auto it = M.find(playerId);
		if (it == M.end())
		{
			M[playerId] = score;
			S.insert({ -score, playerId });
		}
		else
		{
			S.erase({ -it->second, playerId });
			S.insert({ -it->second - score, playerId });
			M[playerId] += score;
		}
	}

	int top(int K) {
		int result = 0;
		auto it = S.begin();
		for (int k = 0; k < K; ++k, ++it)
			result -= it->first;
		return result;
	}

	void reset(int playerId) {		
		addScore(playerId, -M[playerId]);
	}
	map<int, int> M;
	set<pair<int, int>> S;
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */