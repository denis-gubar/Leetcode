class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int result = -1;
        int N = edges.size();
        vector<int> visited(N);
        for(int startNode = 0; startNode < N; ++startNode)
            if (visited[startNode] == 0)
            {
                int node = startNode;
                for (; node != -1; node = edges[node])
                {
                    if (visited[node] )
                        break;
                    visited[node] = 1;
                }
                if (node != -1)
                {
                    if (visited[node] == 1)
                    {
                        int length = 1;
                        for (int nextNode = edges[node]; nextNode != node; nextNode = edges[nextNode])
                            ++length;
                        result = max(result, length);
                    }
                }                
                for (node = startNode; node != -1 && visited[node] == 1; node = edges[node])
                    visited[node] = 2;
            }
        return result;
    }
};
