// Baekjoon17396_Backdoor.cpp
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

struct Node {
    int node;
    ll weight;
    Node(): node(0), weight(0ll) { }
    Node(int n, ll w): node(n), weight(w) { }

    bool operator<(const Node& n2) const {
        return weight > n2.weight;
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    bool notGo[100'000] = {false, };
    for (int i = 0; i < n; i++)
        cin >> notGo[i];
    notGo[n - 1] = 0;

    vector<Node> adjList[100'000];
    for (int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;

        if (!notGo[a] && !notGo[b]) {
            adjList[b].push_back(Node(a, (ll)t));
            adjList[a].push_back(Node(b, (ll)t));
        }
    }

    priority_queue<Node> pq;
    bool visited[100'000] = {false, };

    pq.push({0, 0});
    
    ll ans = -1;
    while (!pq.empty()) {
        Node currNode = pq.top(); pq.pop();
        if (currNode.node == n - 1) {
            ans = currNode.weight;
            break;
        }

        if (!visited[currNode.node]) {
            visited[currNode.node] = true;
            for (Node adj : adjList[currNode.node])
                if (!visited[adj.node])
                    pq.push(Node(adj.node, currNode.weight + adj.weight));
        }
    }

    cout << ans << '\n';

    return 0;
}