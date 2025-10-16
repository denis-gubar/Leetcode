class AuthenticationManager {
public:
	AuthenticationManager(int timeToLive): timeToLive(timeToLive) {

	}

	void flush(int currentTime)
	{
		while (!PQ.empty() && -PQ.top().first <= currentTime)
		{
			auto const& [t, tokenId] = PQ.top();
			if (renewList[tokenId] > currentTime)
			{				
				PQ.push({ -renewList[tokenId], tokenId });
                PQ.pop();
			}
			else
			{
				renewList.erase(renewList.find(tokenId));
				PQ.pop();
			}
		}
	}

	void generate(string tokenId, int currentTime) {
		PQ.push(pair<int, string>{ -currentTime - timeToLive, tokenId });
		renewList[tokenId] = currentTime + timeToLive;
	}

	void renew(string tokenId, int currentTime) {
		flush(currentTime);
		auto it = renewList.find(tokenId);
		if (it == renewList.end())
			return;
        it->second = currentTime + timeToLive;
	}

	int countUnexpiredTokens(int currentTime) {
		flush(currentTime);
		return renewList.size();
	}
	priority_queue<pair<int, string>> PQ;
	unordered_map<string, int> renewList;
	int timeToLive;
};
