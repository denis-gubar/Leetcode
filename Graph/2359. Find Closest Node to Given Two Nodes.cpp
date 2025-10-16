class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int N = edges.size();
        vector<int> visited1(N, -1), visited2(N, -1);
        for (int node = node1, length = 0; node != -1; node = edges[node], ++length)
        {
            if (visited1[node] >= 0)
                break;
            visited1[node] = length;
        }
        for (int node = node2, length = 0; node != -1; node = edges[node], ++length)
        {
            if (visited2[node] >= 0)
                break;
            visited2[node] = length;
        }
        int result = -1;
        for (int i = 0; i < N; ++i)
            if (visited1[i] >= 0 && visited2[i] >= 0)
            {
                if (result == -1 || max(visited1[result], visited2[result]) > max(visited1[i], visited2[i]))
                    result = i;
            }
        return result;
    }
};
