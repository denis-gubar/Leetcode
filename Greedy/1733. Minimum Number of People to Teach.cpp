class Solution {
public:
    int minimumTeachings(int N, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int const L = languages.size(), FR = friendships.size();
        vector<vector<bool>> F(N, vector<bool>(L));
        for (int j = 0; j < L; ++j)
            for (int i : languages[j])
                F[i - 1][j] = true;
        vector<vector<int>> fr;
        fr.reserve(FR);
        for (int i = 0; i < FR; ++i)
        {
            int const V = friendships[i][0] - 1;
            int const U = friendships[i][1] - 1;
            bool isBad = true;
            for (int j = 0; isBad && j < N; ++j)
                isBad = !F[j][V] || !F[j][U];
            if (isBad)
                fr.push_back(friendships[i]);
        }
        int result = L;
        for (int i = 0; i < N; ++i)
        {
            int count = 0;
            for (vector<int> const& f : fr)
            {
                int const V = f[0] - 1;
                int const U = f[1] - 1;
                if (!F[i][V])
                    F[i][V] = true, ++count;
                if (!F[i][U])
                    F[i][U] = true, ++count;
            }
            result = min(result, count);
        }
        return result;
    }
};
