class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec) {
        for (vector<int> const& row : vec)
            copy(row.begin(), row.end(), back_inserter(data));
        it = data.begin();
    }
    
    int next() {
        int result = *it;
        ++it;
        return result;
    }
    
    bool hasNext() {
        return it != data.end();
    }
    vector<int> data;
    vector<int>::iterator it;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
