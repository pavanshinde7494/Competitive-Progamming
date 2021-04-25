#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 1000000007
#define f first
#define s second
#define pb push_back
#define mk make_pair


vector<ll>adjList[1001];
vector<ll>transpose[1001];
vector<ll>order;
ll visited[1001];
set<ll>storing_set;

void dfs1(ll node)
{
    visited[node] = 1;
    for(ll child : transpose[node])
    {
        if(!visited[child])
            dfs1(child);
    }
    storing_set.insert(node);
}

void dfs(ll node)
{
    visited[node] = 1;
    for(ll child : adjList[node]) 
    {
        if(!visited[child])
            dfs(child);
    }
    order.pb(node);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
    memset(visited,0,sizeof(visited));
    ll nodes,edges;
    cin>>nodes>>edges;
    for(ll i=0;i<edges;i++)
    {
        ll x,y;
        cin>>x>>y;
        adjList[x].pb(y);
        transpose[y].pb(x);
    }
    for(ll i=1;i<=nodes;i++)
    {
        if(!visited[i])
            dfs(i);
    }
    memset(visited,0,sizeof(visited));
    for(ll i=order.size()-1;i>=0;i--)
    {
        storing_set.clear();
        if(!visited[order[i]])
        {
            dfs1(order[i]);
            for(auto it = storing_set.begin();it!=storing_set.end();it++)
            {
                cout<<*it<<" ";
            }
            cout<<"\n";
        }
    }
}
