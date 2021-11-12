
vector<int>adjList[1001];


int articulation[1001];
int visited[1001];
int tin[1001];
int low[1001];
int timer = 1;

void findingArticulation(int node,int parent){
    visited[node] = 1;
    tin[node] = tin[node] = timer++;

    int childCnt = 0;
    for(int child : visited[node]){
        if(child == parent)continue;
        if(visited[node])
            low[node] = min(low[node],tin[child]);
        else{
            findingArticulation(child,node);
            low[node] = min(low[node],low[child]);
            if(low[child] >= tin[node] && parent != -1){
                articulation[node] = 1;
            }
            childCnt++;
        }
    }
    if(parent == -1 && childCnt > 1)
        articulation[node] = 1;
}

int main(){

    memset(visited,0,sizeof(visited));
    memset(articulation,0,sizeof(articulation));
    memset(low,0,sizeof(low));
    memset(tin,0,sizeof(tin));

    int nodes,edges;
    cin>>nodes>>edges;

    for(int i=1;i<=edges;i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for(int i=1;i<=nodes;i++){
        if(!visited[i])
            findingArticulation(i,-1);
    }
    cout<<"Articulation Points : ->\n";
    for(int i=1;i<=nodes;i++){
        if(articulation[i])
            cout<<i<<" , ";
    }
}
