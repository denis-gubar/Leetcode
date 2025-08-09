class Solution {
public:
    vector<string> split(const string& s, char delimeter = ' ')
    {
        vector<string> result;
        istringstream ss(s);
        for (string token; !ss.eof(); )
        {
            getline(ss, token, delimeter);
            result.push_back(token);
        }
        return result;
    }
    vector<string> sortFeatures(vector<string>& features, vector<string>& responses) {
        int const N = features.size();
        vector<string> result(N);
        vector<int> I(N), popularity(N);
        iota(I.begin(), I.end(), 0);
        for (string const& r : responses)
        {
            vector<string> R = split(r);
            for (int i = 0; i < N; ++i)
                if (find(R.begin(), R.end(), features[i]) != R.end())
                    ++popularity[i];
        }
        sort(I.begin(), I.end(), [&popularity](int a, int b)
            {
                if (popularity[a] != popularity[b])
                    return popularity[a] > popularity[b];
                return a < b;
            });
        for (int i = 0; i < N; ++i)
            result[i] = features[I[i]];
        return result;
    }
};
