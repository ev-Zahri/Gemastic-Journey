
// Url https://tlx.toki.id/problems/find-it-2024-cp-penyisihan/A

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge {
    int to, weight;
};

struct Bomb {
    int city, time;
};

const int INF = 1e9;
const int MAXN = 5005;

vector<Edge> adj[MAXN];
vector<Bomb> bombs;
int dist[MAXN];
bool visited[MAXN];

void dijkstra(int start, int N) {
    fill(dist, dist + N + 1, INF);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (Edge &e : adj[u]) {
            int v = e.to;
            int weight = e.weight;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int N, K, T;
    cin >> N >> K >> T;

    bombs.resize(K);
    for (int i = 0; i < K; ++i) {
        cin >> bombs[i].city >> bombs[i].time;
    }

    for (int i = 1; i < N; ++i) {
        int U, V, W;
        cin >> U >> V >> W;
        adj[U].push_back({V, W});
        adj[V].push_back({U, W});
    }

    dijkstra(1, N);

    vector<int> defuse_times;
    for (const Bomb &bomb : bombs) {
        if (dist[bomb.city] < INF) {
            defuse_times.push_back(dist[bomb.city] + bomb.time);
        }
    }

    sort(defuse_times.begin(), defuse_times.end());

    int current_time = 0;
    int max_bombs = 0;
    for (int time : defuse_times) {
        if (current_time + time <= T) {
            current_time += time;
            max_bombs++;
        } else {
            break;
        }
    }

    cout << max_bombs << endl;

    return 0;
}
