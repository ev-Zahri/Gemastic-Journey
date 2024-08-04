#include <iostream>
#include <vector>
using namespace std;

void dfs(int v, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u, adj, visited);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N + 1);
    vector<bool> visited(N + 1, false);

    for (int i = 0; i < M; ++i) {
        int X, Y;
        cin >> X >> Y;
        adj[X].push_back(Y);
        adj[Y].push_back(X);
    }

    int vehicles = 0;
    int isolated = 0;

    for (int i = 1; i <= N; ++i) {
        if (adj[i].empty()) {
            isolated++;
        } else if (!visited[i]) {
            vehicles++;
            dfs(i, adj, visited);
        }
    }

    if (isolated > 0) {
        if (isolated == 1 && vehicles > 0) {
            // Tambahkan orang yang terisolasi ke kendaraan yang sudah ada
        } else {
            vehicles += (isolated + 1) / 2; // Jumlah kendaraan tambahan untuk peserta yang terisolasi
        }
    }

    cout << vehicles << endl;
    return 0;
}
