#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 1000000007
#define f first
#define s second
#define pb push_back
#define mk make_pair

vector<ll>adjList[10001];
ll visited[10001];
ll indeg[10001];
vector<ll>res;

void kahn(ll n)
{
    queue<ll>q;
    for(ll i=1;i<=n;i++)
    {
        if(indeg[i] == 0)
            q.push(i);
    }
    while(!q.empty())
    {
        ll cur = q.front();
        res.pb(cur);
        q.pop();
        for(ll child : adjList[cur])
        {
            indeg[child]--;
            if(indeg[child] == 0)
                q.push(child);
        }
    }
    cout<<"\nTopological Sort: ";
    for(ll i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
}

int main()
{
    memset(visited,0,sizeof(visited));
    memset(indeg,0,sizeof(indeg));
    ll nodes,edges;
    cin>>nodes>>edges;
    for(ll i=0;i<edges;i++)
    {
        ll x,y;
        cin>>x>>y;
        adjList[x].pb(y);
        indeg[y]++;
    }
    kahn(nodes);
}
