static int D[100][100];
class Graph {
public:
    int const INF = 100'000'001;
    Graph(int N, vector<vector<int>>& edges) : N(N) {
        for (int V = 0; V < N; ++V)
        {
            for (int U = 0; U < N; ++U)
                D[V][U] = INF;
            D[V][V] = 0;
        }
        for (vector<int> const& e : edges)
        {
            int const& V = e[0];
            int const& U = e[1];
			int const& X = e[2];
            D[V][U] = X;
        }
        for (int i = 0; i < N; ++i)
            for (int V = 0; V < N; ++V)
                for (int U = 0; U < N; ++U)
                    D[V][U] = min(D[V][U], D[V][i] + D[i][U]);
    }
    
    void addEdge(vector<int> const& edge) {
		int const& V = edge[0];
		int const& U = edge[1];
		int const& X = edge[2];
        if (D[V][U] > X)
            D[V][U] = X;
        for (int i = 0; i < N; ++i)
            for (int V = 0; V < N; ++V)
                for (int U = 0; U < N; ++U)
                    D[V][U] = min(D[V][U], D[V][i] + D[i][U]);
    }
    
    int shortestPath(int node1, int node2) {
        if (D[node1][node2] >= INF)
            return -1;
        return D[node1][node2];
    }
    int N;
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
