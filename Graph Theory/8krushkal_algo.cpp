#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 1000000007
#define f first
#define s second
#define pb push_back
#define mk make_pair

struct edge{
    ll x;
    ll y;
    ll w;
};

edge e[100001];
ll parent[10001];

bool cmp(edge a,edge b)
{
    return a.w<b.w;
}

void dsu_union(ll a,ll b)
{
    parent[b] = a;
}

ll dsu_find(ll a)
{
    if(parent[a]<0)
        return a;
    ll tmp = dsu_find(parent[a]);
    parent[a] = tmp;
    return tmp;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
    memset(parent,-1,sizeof(parent));
    ll nodes,edges;
    cin>>nodes>>edges;
    for(ll i=0;i<edges;i++)
    {
        cin>>e[i].x>>e[i].y>>e[i].w;
    }
    sort(e,e+edges,cmp);
    ll sum = 0;
    for(ll i=0;i<edges;i++)
    {
        ll x_par = dsu_find(e[i].x);
        ll y_par = dsu_find(e[i].y);
        if(x_par != y_par)
        {
            sum += e[i].w;
            dsu_union(x_par,y_par);
        }
    }
    cout<<sum<<"\n";
}
