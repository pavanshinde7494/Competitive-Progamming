vector<ll>adjList[100001];
ll visited[100001];
ll intTime[100001];
ll lowTime[100001];
ll timer = 0;

void dfs(ll node,ll parent)
{
    visited[node] = 1;
    intTime[node] = lowTime[node] = timer++;
    ll children = 0;
    for(ll child : adjList[node])
    {
        if(child == parent)
            continue;
        if(visited[child])
            lowTime[node] = min(intTime[child] , lowTime[node]);
        else
        {
            dfs(child,node);
            lowTime[node] = min(lowTime[node] , lowTime[child]);
            if( lowTime[child] >= intTime[node] && parent != -1)
                cout<<node<<" is the articulation point\n";
            children++;
        }
    }
    if(parent == -1 && children>1)
        cout<<node<<" is the articulation point\n";
}