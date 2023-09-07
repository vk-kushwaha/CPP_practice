#include <iostream>
#include <vector>
using namespace std;

long long calculateTotalGames(long long teams) {
    long long gamesInElimination = teams / 2; // Sum of the first 'teams' odd numbers (1, 3, 5, ...)
    long long roundRobinGames = (teams * (teams - 1)) / 2; // Additional round-robin games
    return gamesInElimination + roundRobinGames;
}

vector<long long> findTeams(long long n) {
    vector<long long> result;

    for (long long teams = 2; teams <= n; ++teams) {
        if (calculateTotalGames(teams) == n) {
            result.push_back(teams);
        }
    }

    return result;
}

int main() {
    long long n;
    cin >> n;

    vector<long long> teams = findTeams(n);

    if (!teams.empty()) {
        for (long long team : teams) {
            cout << team << endl;
        }
    } else {
        cout << -1 << endl;
    }

    return 0;
}
