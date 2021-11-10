

vector<int>adjList[10001];
int visited[10001];


// BFS cycle detection

// bool isCycle(int node) {
//     visited[node] = 1;
//     queue<pair<int, int>>q;
//     q.push({node, -1});

//     while (!q.empty()) {
//         int size = q.size();
//         while (size--) {
//             pair<int, int>curr = q.front();
//             q.pop();
//             int currNode = curr.first;
//             int currParent = curr.second;
//             for (int child : adjList[currNode])
//             {
//                 if (visited[child]) {
//                     if (child == currParent)
//                         continue;
//                     else
//                         return true;
//                 }
//                 else {
//                     visited[child] = 1;
//                     q.push({child, currNode});
//                 }
//             }
//         }
//     }
//     return false;
// }



// DFS cycle detection

// int isCycle(int node, int parent = -1) {
//     visited[node] = 1;
//     for (int child : adjList[node]) {
//         if (visited[child]) {
//             if (child == parent)
//                 continue;
//             else
//                 return true;
//         }
//         else {
//             isCycle(child, node);
//         }
//     }
//     return false;
// }

int main() {
    fast_io;
    file();
    int nodes, edges;
    cin >> nodes >> edges;
    for (int i = 1; i <= edges; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    memset(visited, 0, sizeof(visited));

    for (int i = 1; i <= nodes; i++) {
        if (!visited[i]) {
            if (isCycle(i)) {
                cout << "Cycle detected";
                return 0;
            }
        }
    }
    cout << "No cycle detection";
    return 0;
}
