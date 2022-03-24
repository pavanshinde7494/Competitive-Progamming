int parent[1000001];


bool cmp(vector<int>&p,vector<int>&q){
  return (p[2] < q[2]);
}

int findPar(int a){
  if(parent[a] < 0)return a;
  int tmp = findPar(parent[a]);
  return tmp;
}

void makeUnion(int a ,int b){
  parent[b] = a;
}

void krushkal(vector<vector<int>>edges){
  // [
  //   [x,y,w],
  //   [x,y,w]
  // ]
  memset(parent,-1,sizeof(parent));
  sort(edges.begin(),edges.end(),cmp); 

  int mst = 0;
  for(int i=0;i<edges.size();i++){
      int x = edges[i][0];
      int y = edges[i][1];
      int x_par = findPar(x);
      int y_par = findPar(y);
      if(x_par != y_par){
          mst += edges[i][2];
          makeUnion(x_par,y_par);
      }
  }
  cout<<mst<<"\n";
}
