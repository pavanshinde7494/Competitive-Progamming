vector<ll>adjList[100001];
ll visited[100001];

void dfs(ll node)
{
    visited[node] = 1;
    for(ll i=0;i<adjList[node].size();i++)
    {
        if(!visited[adjList[node][i]])
            dfs(adjList[node][i]);
    }
}