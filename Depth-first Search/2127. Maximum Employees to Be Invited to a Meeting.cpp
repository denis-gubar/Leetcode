class Solution {
public:
    enum struct Colors
    {
        WHITE = 0,
        GREY,
        BLACK
    };
    int maximumInvitations(vector<int>& favorite) {
        int result = 0;
        int delta = 0;
        int const N = favorite.size();
        vector<Colors> A(N);
        vector<int> Neighbors(N);
        vector<bool> isNotLeaf(N), isCycle(N);
        for (int i = 0; i < N; ++i)
            isNotLeaf[favorite[i]] = true;
        for(int i = 0; i < N; ++i)
            if (A[i] == Colors::WHITE)
            {
                unordered_set<int> S;
                int V = i;
                while (A[V] == Colors::WHITE)
                    A[V] = Colors::GREY, V = favorite[V];
                if (A[V] == Colors::GREY)
                {
                    int U = i;
                    while (U != V)
                        A[U] = Colors::BLACK, U = favorite[U];
                    int count = 0;
                    while (A[U] == Colors::GREY)
                        isCycle[U] = true, A[U] = Colors::BLACK, U = favorite[U], ++count;
                    if (count > 2)
                        result = max(result, count);
                    else
                        delta += 2;
                }
                else
                {
                    int U = i;
                    while (U != V)
                        A[U] = Colors::BLACK, U = favorite[U];
                }
            }
        for (int i = 0; i < N; ++i)
            if (!isNotLeaf[i])
            {
                int V = favorite[i];
                int length = 1;
                while (!isCycle[V])
                    ++length, V = favorite[V];
                if (favorite[favorite[V]] == V && length > Neighbors[V])
                    delta += length - Neighbors[V], Neighbors[V] = length;
            }
        return max(result, delta);
    }
};
