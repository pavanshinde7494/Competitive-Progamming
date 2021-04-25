#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 1000000007
#define f first
#define s second
#define pb push_back
#define mk make_pair

ll parent[10001];
ll R[10001];

void dsu_union(ll a,ll b)
{   
    if(R[a]>R[b])
    {
        // a will be parent
        parent[a] += parent[b];
        parent[b] = a;
        R[a] += R[b];
    }
    else
    {
        // b will be parent
        parent[b] += parent[a];
        parent[a] = b;
        R[b] += a;
    }
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

    for(ll i=0;i<10001;i++)
        R[i] = 1;

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
