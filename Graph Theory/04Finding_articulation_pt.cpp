
vector<int>adjList[1001];
int visited[1001];
int low[1001];
int tin[1001];
int articulation[1001];
int timer = 1;

void findArticulation(int node, int parent) {
    visited[node] = 1;
    low[node] = tin[node] = timer++;

    int childCnt = 0;
    for (int child : adjList[node]) {
        if (child == parent)continue;
        if (visited[child])
            low[node] = min(low[node] , tin[child]);
        else {
            findArticulation(child, node);
            low[node] = min(low[node], low[child]);
            if (tin[node] <= low[child] && parent != -1)
                articulation[node]  = 1;
            childCnt++;
        }
    }
    if (childCnt > 1 && parent == -1)
        articulation[node] = 1;
}



int  main() {
    fast_io;
    file();

    memset(visited, 0, sizeof(visited));
    memset(low, 0, sizeof(low));
    memset(tin, 0, sizeof(tin));
    memset(articulation, 0, sizeof(articulation));

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
            findArticulation(i, -1);
        }
    }

    cout << "Articulation Points -> \n" ;
    for (int i = 1; i <= nodes; i++) {
        if (articulation[i])
            cout << i << " , ";
    }
    return 0;
}
