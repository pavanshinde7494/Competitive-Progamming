
int parent[1000001];
int key[1000001];
int mst[1000001];



void prims(vector<pair<int,int>>adjList[],int N){
    int mstCost = 0;
    for(int i=0;i<N;i++){ 
      key[i] = INT_MAX;
      parent[i] = -1;
      mst[i] = 0;
    }
    key[0] = 0;


  for(int itr = 0;itr < N-1;itr++){
    int  minCost = INT_MAX , u;
    for(int i=0;i<N;i++){
      if(key[i] < minCost && mst[i] == false ){
        minCost = key[i];
        u = i;
      }   
    }

    mstCost += key[u];
    mst[u] = true;
    for(pair<int,int> child : adjList[u]){
      int v = child.first;
      int costToReach = child.second;
      if(mst[v] == false && costToReach < key[v]){
        key[v] = costToReach;
        parent[v] = u;
      }
    }
  }

  for(int i=1;i<N;i++)cout<<parent[i]<<" ";

  cout<<mstCost<<"\n";
}
