#include<bits/stdc++.h>

using namespace std;

#define ll                          long long
#define mod                         1000000007
#define f                           first
#define s                           second
#define pb                          push_back
#define mk                          make_pair
#define fast_io                     ios_base::sync_with_stdio(false);\
                                    cin.tie(NULL)
#define PI                          3.1415926535897932384626
#define INF                         1e16
#define EPS                         1e-9

bool flg = false;

const int dir4[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int dir8[8][2] = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}, {1, 1}, {1, -1}, { -1, 1}, { -1, -1}};

vector<pair<ll,ll>>adjList[1000];

ll nodes,edges;

ll parent[1000] , key[1000] ;
bool mstSet[1000];

ll findFree()
{
    ll index = -1;
    ll val = INF;
    for(ll i=1;i<=nodes;i++)
    {
        if(key[i] < val && !mstSet[i])
        {
            val = key[i];
            index = i;
        }
    }
    return index;
}

void prims(ll src)
{
    for(ll i=1;i<1000;i++)
    {
        mstSet[i] = false;
        key[i] = INF;
    }

    

    key[src] = 0;
    parent[src] = -1;

    

    for(ll i=1;i<=nodes;i++)
    {
        ll curSrc = findFree();
        if(curSrc == -1)
        {
            cout<<"NO MST\n";
            return;
        }
        mstSet[curSrc] = true;
        for(pair<ll,ll> child : adjList[curSrc])
        {
            if(!mstSet[child.f] && child.s < key[child.f])
            {
                key[child.f] = child.s;
                parent[child.f] = curSrc;
            }
        }
    }

    ll mstValue = 0;

    for(ll i=1;i<=nodes;i++){
        cout<<parent[i]<<' ';
        mstValue += key[i];
    }
    cout<<"\n";
    cout<<mstValue;
}

void pavan_coder()
{
    cin>>nodes>>edges;
    for(ll i=0;i<edges;i++)
    {
        ll x,y,w;
        cin>>x>>y>>w;
        adjList[x].pb({y,w});
        adjList[y].pb({x,w});
    }
    prims(1);
}

int main()
{
	fast_io;
	ll tc = 1;
	// cin>>tc;
	while(tc--)
	{
		pavan_coder();
	}
}


