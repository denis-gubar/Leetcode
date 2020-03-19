class TweetCounts {
public:
	TweetCounts() {
		M.clear();
	}

	void recordTweet(string tweetName, int time) {
		M[tweetName].insert(time);
	}

	vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
		vector<int> result;
		int delta = 0;
		if (freq == "minute") delta = 60;
		else if (freq == "hour") delta = 60 * 60;
		else if (freq == "day") delta = 60 * 60 * 24;
		for (int x = startTime; x <= endTime; x = min(x + delta, endTime + 1))
		{
			auto it = M[tweetName].lower_bound(x);
			int count = 0;
			while (it != M[tweetName].end() && *it < min(x + delta, endTime + 1))
			{
				++it;
				++count;
			}
			result.push_back(count);
		}
		return result;
	}
	map<string, multiset<int>> M;
};
/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */