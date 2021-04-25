#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 1000000007
#define f first
#define s second
#define pb push_back
#define mk make_pair

vector<ll>adjList[1001];
ll visited[1001];
ll inTime[1001];
ll lowTime[1001];
ll timer = 0;
ll tracking[1001];
stack<ll>st;

void tarjan(ll node)
{
    visited[node] = 1;
    inTime[node] = lowTime[node] = ++timer;
    st.push(node);
    tracking[node] = 1;
    for(ll child : adjList[node])
    {
        if(tracking[child] && visited[child])
        {
            lowTime[node] = min(inTime[child] , lowTime[node]);
        }
        else if(!visited[child])
        {
            tarjan(child);
            if(tracking[child])
                lowTime[node] = min(lowTime[node] , lowTime[child]);
        }
    }
    if(lowTime[node] == inTime[node])
    {
        while(1)
        {
            cout<<st.top()<<" ";
            if(st.top() == node)
            {
                tracking[st.top()] = 0;
                st.pop();
                break;
            }
            tracking[st.top()] = 0;
            st.pop();
        }
        cout<<"\n";
    }
}

int main()
{
    memset(inTime,0,sizeof(inTime));
    memset(lowTime,0,sizeof(lowTime));
    memset(visited,0,sizeof(visited));
    memset(tracking,0,sizeof(tracking));
	ios::sync_with_stdio(0);
	cin.tie(0);
    ll nodes,edges;
    cin>>nodes>>edges;
    for(ll i=0;i<edges;i++)
    {
        ll x,y;
        cin>>x>>y;
        adjList[x].pb(y);
    }
    for(ll i=1;i<=nodes;i++)
    {
        if(!visited[i])
            tarjan(i);
    }
}
