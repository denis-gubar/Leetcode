class Solution {
public:
	vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
		vector<string> result;
		vector<int> friendLevel{ id };
		vector<int> visited(friends.size());
		visited[id] = 1;
		for (int lvl = 0; lvl < level; ++lvl)
		{
			vector<int> nextLevel;
			for(int fr: friendLevel)
				for(int next: friends[fr])
					if (!visited[next])
					{
						visited[next] = 1;
						nextLevel.push_back(next);
					}
			friendLevel = move(nextLevel);
		}
		map<string, int> videos;
		for (int fr : friendLevel)
			for (string const& video : watchedVideos[fr])
				++videos[video];
		vector<pair<int, string>> A;
		for (auto& v : videos)
			A.push_back({ v.second, v.first });
		sort(A.begin(), A.end());
		for (auto& a : A)
			result.push_back(a.second);
		return result;
	}
};