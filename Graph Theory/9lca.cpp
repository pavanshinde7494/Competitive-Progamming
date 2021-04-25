Problem Link : https://www.spoj.com/problems/LCA/

// Novice Approch

#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define mod 1000000007
#define f first
#define s second
#define pb push_back
#define mk make_pair
 
ll visited[1000001];
ll level[1000001];
ll parent[1000001];
vector<ll>adjList[1000001];
 
 
ll lca(ll m,ll n)
{
    ll lev_m = level[m];
    ll lev_n = level[n];
    while(lev_m>lev_n)
    {
        m = parent[m];
        lev_m--;
    }
    while(lev_n>lev_m)
    {
        n = parent[n];
        lev_n--;
    }
    if( m == n )
        return m;
    while(parent[m] != parent[n])
    {
        m = parent[m];
        n = parent[n];
    }
    return parent[m];
}
 
 
void dfs(ll node,ll curLevel)
{
    visited[node] = 1;
    level[node] = curLevel;
    for(ll child : adjList[node])
    {
        if(!visited[child])
            dfs(child,curLevel+1);
    }
}
 
void pavan_coder(ll c)
{
    ll n;
    cin>>n;
 
    memset(parent,0,sizeof(parent));
    memset(level,0,sizeof(level));
    memset(visited,0,sizeof(visited));
 
    for(ll i=1;i<=n;i++)
    {
        adjList[i].clear();
        ll m;
        cin>>m;
        for(ll j=0;j<m;j++)
        {
            ll dest;
            cin>>dest;
            adjList[i].pb(dest);
            parent[dest] = i;
        }
    }
    dfs(1,1);
    ll query;
    cin>>query;
    cout<<"Case "<<c<<":\n";
    while(query--)
    {
        ll m,n;
        cin>>m>>n;
        cout<<lca(m,n)<<"\n";
    }
}
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
    ll tc;
    cin>>tc;
    for(ll c = 1;c<=tc;c++)
    {
        pavan_coder(c);
    }
}




//Efficient Approch


#include<bits/stdc++.h>

#define ll long long
#define f first
#define s second
#define pb push_back
#define mk make_pair

using namespace std;


vector<ll> adjList[1001];
ll visited[1001];
ll parent[1001][1001];
ll level[1001];

void dfs(ll node,ll par,ll curLevel)
{
    visited[node] = 1;
    parent[node][0] = par;
    level[node]  = curLevel;
    for(ll child : adjList[node])
    {
        if(!visited[child])
            dfs(child,node,curLevel+1);
    }
}

ll lca(ll m,ll n,ll maxLog)
{
    ll lev_m = level[m];
    ll lev_n = level[n];
    if(lev_m < lev_n)
    {
        swap(m,n);
        swap(lev_m,lev_n);
    }
    ll diff = lev_m - lev_n;
    while(diff)
    {
        ll power = log2(diff);
        m = parent[m][power];
        diff-= pow(2,power);
    }
    if(m == n)
        return m;
    for(ll i=maxLog;i>=0;i--)
    {
        if(parent[m][i] != -1 && parent[m][i] != parent[n][i])
        {
            m = parent[m][i];
            n = parent[n][i];
        }
    }
    return parent[m][0];
}

void pavan_coder(ll c)
{
    memset(visited,0,sizeof(visited));
    memset(parent,-1,sizeof(parent));
    memset(level,0,sizeof(level));

    ll nodes;
    cin>>nodes;
    for(ll i=1;i<=nodes;i++)
    {
        ll m;
        cin>>m;
        adjList[i].clear();
        for(ll j=0;j<m;j++)
        {
            ll dest;
            cin>>dest;
            adjList[i].pb(dest);
        }
    }
    dfs(1,-1,1);
    ll maxLog = log2(nodes);
    for(ll i=1;i<=maxLog;i++)
    {
        for(ll j=1;j<=nodes;j++)
        {
            ll interPar = parent[j][i-1];
            if(interPar != -1)
            {
                parent[j][i] = parent[interPar][i-1];
            }
        }
    }
    ll query;
    cin>>query;
    cout<<"Case "<<c<<":\n";
    while(query--)
    {
        ll m,n;
        cin>>m>>n;
        cout<<lca(m,n,maxLog)<<"\n";
    }
}

int main()
{
   ll tc;
   cin>>tc;
   for(ll c = 1;c<=tc;c++)
   {
       pavan_coder(c);
   }
}