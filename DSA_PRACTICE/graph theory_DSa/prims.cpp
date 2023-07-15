 #include<bits/stdc++.h>
 using namespace std;

 # define rep(i,a,b) for(int i=a;i<b;i++)
 # define vi vector<int> 
 # define vvi vector<vector<int>>
 # define pi pair<int,int>
 # define vpi vector<pair<int,int>>
 # define mii map<int,int> 
 # define pb push_back
 
                        
                         
int main(){
int n,m;
cin>>n>>m;

vector<pair<int,int>> adj[n];

rep(i,0,m){
   int u,v,w;
   cin>>u>>v>>w;
   adj[u].pb(make_pair(v,w));
   adj[v].pb(make_pair(u,w));
}

int parent[n];
int key[n];
bool mst[n];
 
 rep(i,0,n){
   parent[i]=-1;
   mst[i]=false;
   key[i]=INT_MAX;
 }

// key[0]=0;
// parent[0]=-1;

// for(int cnt=0; cnt<n-1;cnt++){
//    int mini=INT_MAX;
//    int a;
//     for(int i=0;i<n;i++){
//        if(mst[i]==false and key[i]< mini){
//          mini=key[i];
//          a=i;
//        }
//     }
//     mst[a]=true;
   
//     for(auto it : adj[a]){
//       int b=it.first;
//       int weight=it.second;
//       if(mst[b]==false and weight<key[b]){
//          parent[b]=a;
//          key[b]=weight;
//       }
//     }

// }

// rep(i,1,n){
//    cout<<parent[i]<<" -> "<<i<<endl;
// }


priority_queue<pi, vpi ,greater<pi> >pq;

key[0]=0;
parent[0]=-1;
pq.push({0,0});

for(int cnt=0; cnt<n-1;cnt++){
   int a=pq.top().second;
   pq.pop();
   mst[a]=true;

   for(auto id : adj[a]){
      int b=id.first;
      int weight=id.second;
      if(mst[b]==false and key[b]>weight){
          key[b]=weight;
          parent[b]=a;
          pq.push({key[b],b});
      }
   }
}

 rep(i,1,n){
   cout<<parent[i]<<" -> "<<i<<endl;
}


return 0;
}