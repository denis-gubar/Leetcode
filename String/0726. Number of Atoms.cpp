class Solution {
public:
    struct Data
    {
        unordered_map<string, int> M;
        Data& operator*=(int x)
        {
            for (auto& [key, value] : M)
                value *= x;
            return *this;
        }
        Data& operator+=(Data const& other)
        {
            for (auto [key, value] : other.M)
                M[key] += value;
            return *this;
        }
        string print()
        {
            map<string, int> SM(M.begin(), M.end());
            string result;
            for (auto [key, value] : SM)
            {
                result += key;
                if (value > 1)
                    result += to_string(value);
            }
            return result;
        }
    };
    string countOfAtoms(string formula) {
        stack<Data> S;
        S.push({});
        int count = 0;
        string atom;
        int const N = formula.size();
        for (int i = 0; i < N; ++i)
        {
            auto readAtom = [&formula, N, &i, &atom]()
                {
                    int j = i;
                    atom += formula[j];
                    while (j < N - 1 && islower(formula[j + 1]))
                        ++j, atom += formula[j];
                    i = j;
                };
            auto readCount = [&formula, N, &i, &count]()
                {
                    int j = i;
                    count = 0;
                    while (j < N - 1 && isdigit(formula[j + 1]))
                        ++j, count = count * 10 + (formula[j] - '0');
                    i = j;
                };
            if (isupper(formula[i]))
            {
                readAtom();
                readCount();
                Data current;
                if (count < 2)
                    current.M[atom] = 1;
                else
                    current.M[atom] = count;
                S.top() += current;
                atom.clear();
                continue;
            }
            if (formula[i] == '(')
            {
                S.push({});
                continue;
            }
            if (formula[i] == ')')
            {
                readCount();
                if (count > 1)
                    S.top() *= count;
                Data current = move(S.top()); S.pop();
                S.top() += current;
            }
        }
        return S.top().print();
    }
};
