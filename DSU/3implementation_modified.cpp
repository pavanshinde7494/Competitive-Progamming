#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 1000000007
#define f first
#define s second
#define pb push_back
#define mk make_pair

ll parent[10001];

void dsu_union(ll a,ll b)
{
    parent[a] += parent[b];
    parent[b] = a;
}

ll dsu_find(ll a)
{
    vector<ll>v;
	while(parent[a]>0)
    {
        v.pb(a);
        a = parent[a];
    }
    for(ll i=0;i<v.size();i++)
    {
        parent[v[i]] = a;
    }
    return a;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
    memset(parent,-1,sizeof(parent));
    ll nodes,edges;
    cin>>nodes>>edges;
    for(ll i=0;i<nodes;i++)
    {
        ll x,y;
        cin>>x>>y;
        ll par_x = dsu_find(x);
        ll par_y = dsu_find(y);
        if( par_x != par_y)
            dsu_union(par_x,par_y);
    }
}
