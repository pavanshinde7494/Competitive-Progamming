vector<ll>adjList[100001];
ll visited[100001];

void bfs(ll node)
{
    queue<ll> q;
    q.push(node);
    visited[node] = 1;
    while(!q.empty())
    {
        ll cur_node = q.front();
        q.pop();
        for(ll i=0;i<adjList[cur_node].size();i++)
        {
            if(!visited[adjList[cur_node][i]])
            {
                visited[adjList[cur_node][i]] = 1;
                q.push(adjList[cur_node][i]);
            }
        }
    }
}
