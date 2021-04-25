#include<bits/stdc++.h>

#define ll long long
#define f first
#define s second
#define pb push_back
#define mk make_pair

using namespace std;

vector<ll>adjList[100001];
ll visited[100001];
ll low[100001];
ll inTime[100001];
ll timer = 0;

void dfs(ll node , ll parent)
{
    visited[node] = 1;
    low[node] = timer;
    inTime[node] = timer;
    timer++;
    for(ll i=0;i<adjList[node].size();i++)
    {
        if(adjList[node][i] == parent)
            continue;
        if(!visited[adjList[node][i]])
        {
            // checking for forward edge
            dfs(adjList[node][i],node);
	    low[node] = min(low[node],low[adjList[node][i]]);
            if( low[adjList[node][i]] >= inTime[node] )
                cout<<"Edge "<<node<<"->"<<adjList[node][i]<<" is a bridge\n";
        }
        else
        {
            // checking for back edge
            low[node]  = min(low[node] , inTime[adjList[node][i]]);
        }
    }
}


int main()
{
   memset(visited,0,sizeof(visited));
    memset(low,0,sizeof(low));
    memset(inTime,0,sizeof(inTime));

   ll nodes,edges;
   cin>>nodes>>edges;

   for(ll i=0;i<edges;i++)
   {
       ll u,v;
       cin>>u>>v;
       adjList[u].pb(v);
       adjList[v].pb(u);
   }

   dfs(1,0);
}