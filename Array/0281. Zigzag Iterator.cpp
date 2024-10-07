class ZigzagIterator {
public:
    vector<vector<int>::iterator> it, eit;
    int pos;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) : it({v1.begin(), v2.begin()}), eit({v1.end(), v2.end()}), pos(0) {
        if (it[pos] == eit[pos])
            pos = 1 - pos;
    }

    int next() {
        int result = *it[pos];
        ++it[pos];
        if (it[1 - pos] != eit[1 - pos])
            pos = 1 - pos;
        return result;
    }

    bool hasNext() {
        return it != eit;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
