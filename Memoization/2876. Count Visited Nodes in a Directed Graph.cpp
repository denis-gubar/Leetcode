class Solution {
public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        int N = edges.size();
        vector<int> result(N);
        vector<int> color(N);
        for (int V = 0; V < N; ++V)
            if (color[V] == 0)
            {
                int X = V;
                while (color[X] == 0)
                {
                    color[X] = 1;
                    X = edges[X];
                }
                if (color[X] == 1)
                {
                    int Y = X;
                    int count = 0;
                    while (color[Y] == 1)
                    {
                        color[Y] = 2;
                        ++count;
                        Y = edges[Y];
                    }
                    while (result[Y] == 0)
                    {
                        result[Y] = count;
                        Y = edges[Y];
                    }
                }
                int prefix = 0;
                X = V;
                while (color[X] == 1)
                {
                    ++prefix;
                    X = edges[X];
                }
                int cycle = result[X];
                X = V;
                while (color[X] == 1)
                {
                    result[X] = prefix + cycle;
                    --prefix;
                    color[X] = 2;
                    X = edges[X];
                }
            }
        return result;
    }
};
