#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

static constexpr unsigned M = 1000 + 1;

static vector<bool> winning(M * M);

static bool testcase(unsigned n, unsigned m) {
    return winning[n + m * M];
}

static void testcase() {
    unsigned n, m, p, q;
    cin >> n >> m >> p >> q;
    cout << (testcase(n - p, m - q) ? "YES\n" : "NO\n");
}

static void mark_line(unsigned n, unsigned m, unsigned dn, unsigned dm) {
    const unsigned dp = dn + M * dm;
    for(unsigned p = n + m * M; (n += dn) != M && (m += dm) != M;)
        winning[p += dp] = true;
}

static void mark_winning(unsigned n, unsigned m) {
    mark_line(n, m, 1, 0);
    mark_line(n, m, 1, 1);
    mark_line(n, m, 0, 1);
}

static void init() {
    for(unsigned md = 0; md != M; ++md)
        for(unsigned m = md, n = 0; n != md + 1; --m, ++n)
            if(!winning[n + m * M])
                mark_winning(n, m);
    for(unsigned nd = 1; nd != M; ++nd)
        for(unsigned n = nd, m = M - 1; m != nd - 1; ++n, --m)
            if(!winning[n + m * M])
                mark_winning(n, m);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    unsigned T;
    cin >> T;
    while(T--)
        testcase();
} 