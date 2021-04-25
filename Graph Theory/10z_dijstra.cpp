
vector<pair<ll,ll>> adjList[1001];
ll dist[1001];
priority_queue<pair<ll,ll> , vector<pair<ll,ll>> , greater<pair<ll,ll>>> pq;


void dijstra(ll node,ll n)
{
    for(ll i=1;i<=n;i++)
        dist[i] = INT_MAX;
    dist[node] = 0;
    pq.push({0,node});
    while(!pq.empty())
    {
        ll cur_node = pq.top().s;
        ll cur_wt = pq.top().f;
        pq.pop(); 
        if(cur_wt == dist[cur_node] )
        {
            for(pair<ll,ll> child : adjList[cur_node])
            {
                if( child.s + cur_wt < dist[child.f] )
                {
                    pq.push({child.s + cur_wt , child.f});
                    dist[child.f] = child.s + cur_wt;
                }
            }
        }
    }
    for(ll i=1;i<=n;i++)
        cout<<dist[i]<<" ";
}
