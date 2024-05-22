#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <limits>

using namespace std;

const int MAX_N = 100;
int n;
bool visited[MAX_N];
int distance[MAX_N];
int previous[MAX_N];

struct Edge {
    int destination;
    int weight;
};

vector<Edge> adjacencyList[MAX_N];

void init() {
    ifstream file("danhSachCanh.txt");
    if (!file.is_open()) {
        cerr << "Khong the mo file!" << endl;
        return;
    }
    file >> n;
    int m;
    file >> m; // Số lượng cạnh
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        file >> u >> v >> w;
        adjacencyList[u].push_back({v, w});
        adjacencyList[v].push_back({u, w}); // Nếu đồ thị vô hướng
    }
    file.close();
}

void dijkstra(int source) {
    // Khởi tạo các giá trị ban đầu
    for (int i = 0; i < n; ++i) {
        distance[i] = numeric_limits<int>::max();
        visited[i] = false;
        previous[i] = -1;
    }
    distance[source] = 0;

    // Sử dụng priority_queue để lựa chọn đỉnh có độ dài ngắn nhất
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        // Duyệt qua các đỉnh kề của u
        for (const Edge& edge : adjacencyList[u]) {
            int v = edge.destination;
            int weight = edge.weight;
            if (!visited[v] && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                previous[v] = u;
                pq.push({distance[v], v});
            }
        }
    }
}

void printShortestPath(int source, int destination) {
    cout << "Duong di ngan nhat tu " << source << " den " << destination << " la: ";
    if (distance[destination] == numeric_limits<int>::max()) {
        cout << "Khong co duong di" << endl;
        return;
    }

    vector<int> path;
    for (int v = destination; v != -1; v = previous[v]) {
        path.push_back(v);
    }

    for (int i = path.size() - 1; i >= 0; --i) {
        cout << path[i];
        if (i != 0) cout << " -> ";
    }
    cout << endl;
}

int main() {
    init();

    int source = 1;
    int destination = 2;
    dijkstra(source);
    printShortestPath(source, destination);

    return 0;
}
