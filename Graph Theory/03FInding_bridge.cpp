
vector<int>adjList[1001];
int visited[1001];
int low[1001];
int tin[1001];
int timer = 1;

void findBridge(int node, int parent) {
    visited[node] = 1;
    low[node] = tin[node] = timer++;

    for (int child : adjList[node]) {
        if (child == parent)continue;
        if (visited[child])
            low[node] = min(low[node] , tin[child]);
        else {
            findBridge(child, node);
            low[node] = min(low[node], low[child]);
            if (tin[node] < low[child])
                cout << "bridge : " << node << " " << child << "\n";
        }
    }
}



int  main() {
    fast_io;
    file();

    memset(visited, 0, sizeof(visited));
    memset(low, 0, sizeof(low));
    memset(tin, 0, sizeof(tin));

    int nodes, edges;
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for (int i = 1; i <= nodes; i++) {
        if (!visited[i]) {
            findBridge(i, -1);
        }
    }
    return 0;
}
