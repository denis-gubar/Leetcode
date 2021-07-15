class MovieRentingSystem {
public:
	MovieRentingSystem(int n, vector<vector<int>>& entries) {
		unrented = vector<set<pair<int, int>>>(10'001);
		inverted = vector<set<pair<int, int>>>(10'001);
		for (int i = 0; i < entries.size(); ++i)
		{
			int const& shop  = entries[i][0];
			int const& movie = entries[i][1];
			int const& price = entries[i][2];
			unrented[movie].insert({ price, shop });
			inverted[movie].insert({ shop, price });
		}
	}

	vector<int> search(int movie) {
		vector<int> result;
		for (auto it = unrented[movie].begin(); result.size() < 5 && it != unrented[movie].end(); ++it)
			result.push_back(it->second);
		return result;
	}

	void rent(int shop, int movie) {
		auto it = inverted[movie].lower_bound({ shop, 0 });
		int price = it->second;
		unrented[movie].erase(unrented[movie].find({ price, shop }));
		R.insert({{ price, shop}, movie });
	}

	void drop(int shop, int movie) {
		auto it = inverted[movie].lower_bound({ shop, 0 });
		int price = it->second;
		R.erase(R.find({ {price, shop}, movie }));
        unrented[movie].insert({ price, shop });
	}

	vector<vector<int>> report() {
		vector<vector<int>> result;
		for (auto it = R.begin(); result.size() < 5 && it != R.end(); ++it)
		{
			int shop = (*it).first.second;
			int movie = (*it).second;
			vector<int>	current{ shop, movie };
			result.push_back(current);
		}
		return result;
	}
	vector<set<pair<int, int>>> unrented;
	vector<set<pair<int, int>>> inverted;
	set<pair<pair<int, int>, int>> R;	
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */