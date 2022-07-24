class FoodRatings {
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings): N(foods.size()),
        F(foods), R(ratings)
    {
        for (int i = 0; i < N; ++i)
        {
            types[foods[i]] = cuisines[i];
            M[cuisines[i]].emplace(-ratings[i], foods[i]);
            I[foods[i]] = i;
        }
    }
    
    void changeRating(string food, int newRating) {
        string C = types[food];
        int i = I[food];
        M[C].erase(M[C].find(pair<int, string>{ -R[i], food }));
        R[i] = newRating;
        M[C].emplace(-newRating, food);
    }
    
    string highestRated(string cuisine) {
        return M[cuisine].begin()->second;
    }
    unordered_map<string, string> types;
    unordered_map<string, int> I;
    unordered_map<string, set<pair<int, string>>> M;
    vector<string> F;
    vector<int> R;
    int N;
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
