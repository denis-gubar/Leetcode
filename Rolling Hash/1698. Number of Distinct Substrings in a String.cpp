static short data[1'000'000];
static int pos;
class Solution {
public:
    struct SuffixArray
    {
        template<class ForwardIterator, class ValueType, class Function>
        void count_sort(ForwardIterator const first, ForwardIterator const last, ValueType const low, ValueType const high, Function const& func)
        {
            using DereferencedIterator = typename remove_reference<decltype(first[0])>::type;
            vector<DereferencedIterator> Bucket(high - low + 1);
            for (ForwardIterator it = first; it != last; ++it)
                if (ValueType value = func(*it); value != high)
                    ++Bucket[value - low + 1];
            partial_sum(Bucket.begin(), Bucket.end(), Bucket.begin());
            unique_ptr<DereferencedIterator[]> Buffer(new DereferencedIterator[last - first]);
            for (ForwardIterator it = first; it != last; ++it)
                Buffer[Bucket[func(*it) - low]++] = *it;
            copy(&Buffer[0], &Buffer[0] + (last - first), first);
        }
        string s;
        unique_ptr<size_t[]> Array;
        unique_ptr<size_t[]> LCP;
        SuffixArray(string const& S)
        {
            size_t const N = S.size();
            s.reserve(N + 1);
            s.assign(S.begin(), S.end());
            auto P = minmax_element(s.begin(), s.end());
            s += *P.first;
            --s.back();
            Array = make_unique<size_t[]>(N + 1);
            iota(&Array[0], &Array[0] + N + 1, 0);
            count_sort(&Array[0], &Array[0] + N + 1, s.back(), *P.second, [this](int x) {return s[x]; });

            unique_ptr<size_t[]> Groups(new size_t[N + 1]);
            unique_ptr<size_t[]> newGroups(new size_t[N + 1]);

            Groups[Array[0]] = 0;
            for (size_t i = 0; i < N; ++i)
                Groups[Array[i + 1]] = Groups[Array[i]] + (s[Array[i + 1]] != s[Array[i]]);
            for (size_t prefixLength = 1; ; prefixLength <<= 1)
            {
                size_t groupMaxNo = Groups[Array[N]];
                if (groupMaxNo == N)
                    break;
                for (size_t i = 0; i < N + 1; ++i)
                    Array[i] = (Array[i] + N + 1 - prefixLength) % (N + 1);
                count_sort(&Array[0], &Array[0] + N + 1, static_cast<size_t>(0), groupMaxNo, [&Groups](int x) {return Groups[x]; });
                newGroups[Array[0]] = 0;
                for (size_t i = 0; i < N; ++i)
                    newGroups[Array[i + 1]] = newGroups[Array[i]] +
                    (tie(Groups[Array[i + 1]], Groups[(Array[i + 1] + prefixLength) % (N + 1)]) !=
                        tie(Groups[Array[i]], Groups[(Array[i] + prefixLength) % (N + 1)]));
                Groups.swap(newGroups);
            }
            LCP = make_unique<size_t[]>(N);
            for (int i = 0, commonPrefixLength = 0; i < N; ++i)
            {
                size_t posI = Groups[i];
                size_t j = Array[posI - 1];
                commonPrefixLength = max(0, commonPrefixLength - 1);
                while (s[i + commonPrefixLength] == s[j + commonPrefixLength])
                    ++commonPrefixLength;
                LCP[posI - 1] = commonPrefixLength;
            }
        }
        string_view get_suffix(int x)
        {
            return string_view(s.c_str() + x, s.size() - x);
        }
        string_view get_suffix(int x, string_view S)
        {
            if (x == -1)
                return S;
            return string_view(s.c_str() + x, min<int>(S.size(), s.size() - x));
        }
    };
	int countDistinct(string s) {
        SuffixArray SA(s);
        int const N = s.size();
		return -accumulate(&SA.LCP[0], &SA.LCP[0] + N, -1 * N * (N + 1) / 2);
    }
};
