class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        int const Q = queries.size();
        vector<int> result(Q, -1);
        priority_queue<int> PQ;
        for (int q = 0; q < Q; ++q)
        {            
            int const& X = queries[q][0];
            int const& Y = queries[q][1];
            PQ.push(abs(X) + abs(Y));
            if (PQ.size() < k)
                continue;
            if (PQ.size() > k)
                PQ.pop();            
            result[q] = PQ.top();
        }
        return result;
    }
};
