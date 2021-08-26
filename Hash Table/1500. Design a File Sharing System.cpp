class FileSharing {
public:
	FileSharing(int m): max_user_id(0), m(m), users_for_chunks(vector<set<int>>(m + 1)) {
		chunks_for_users.push_back({});
	}

	int join(vector<int> const& ownedChunks) {
		int result = 0;
		if (user_ids.empty())
		{
			result = ++max_user_id;
			chunks_for_users.emplace_back(ownedChunks);
		}
		else
		{
			result = *user_ids.begin();
			user_ids.erase(user_ids.begin());
			chunks_for_users[result] = ownedChunks;
		}
		for (int chunk_id : ownedChunks)
			users_for_chunks[chunk_id].insert(result);
		return result;
	}

	void leave(int userID) {
		for (int chunk_id : chunks_for_users[userID])
			users_for_chunks[chunk_id].erase(userID);
		if (userID == max_user_id)
		{
			chunks_for_users.pop_back();
			--max_user_id;
		}
		else
		{
			user_ids.insert(userID);
			chunks_for_users[userID].clear();
		}
	}

	vector<int> request(int userID, int chunkID) {
		vector<int>	result;
		for (int x : users_for_chunks[chunkID])
			result.push_back(x);
		if (!result.empty() && users_for_chunks[chunkID].find(userID) == users_for_chunks[chunkID].end())
		{
			users_for_chunks[chunkID].insert(userID);
			chunks_for_users[userID].push_back(chunkID);
		}
		return result;
	}
	int max_user_id;
	int m;
	set<int> user_ids;
	vector<set<int>> users_for_chunks;
	vector<vector<int>> chunks_for_users;
};

/**
 * Your FileSharing object will be instantiated and called as such:
 * FileSharing* obj = new FileSharing(m);
 * int param_1 = obj->join(ownedChunks);
 * obj->leave(userID);
 * vector<int> param_3 = obj->request(userID,chunkID);
 */