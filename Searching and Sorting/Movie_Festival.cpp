#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define I_am_speed() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
#define vec vector<ll> 
#define int long long
typedef vector<int> vi;
typedef vector<vi> vvi;
#define loop(x, start, end) for(int x = start; x < end; ++x) 
#define all(v) v.begin() , v.end() 
#define here(i) cout << " here " << i << endl ; 


class DSU{
 vector<int> parent;
vector<int> subtree_size;
int N;
public:
DSU(int n){
N = n;
parent = vector<int>(n+1, 0);
subtree_size = vector<int>(n+1, 1);
for(int i=1; i<=n; i++) parent[i] = i;
}
int findRoot(int u){
while(u != parent[u]){
parent[u] = parent[parent[u]]; //Path compression
u = parent[u];
}
return u;
}
void combine(int u, int v){
int ru = findRoot(u);
int rv = findRoot(v);
if(ru == rv) return;
if(subtree_size[ru] > subtree_size[rv]){
parent[rv] = ru;
subtree_size[ru] += subtree_size[rv];
} else{
parent[ru] = rv;
subtree_size[rv] += subtree_size[ru];
}
}
};
void print(vi & v){ 
   int n = v.size(); 
    for(int i =0; i<v.size(); i++){ 
       cout<<v[i]<<" "; 
    }
    cout <<endl ;
    return ; 
} 
void print(vvi & v)
{
   for (int i = 0; i < v.size(); i++)
   {
   for (int j = 0; j < v[i].size(); j++)
   {
   cout << v[i][j] <<" ";
   }
    cout << endl;
   }
   return;
}

void solve() {
    int n ; cin >>n; 
    vvi v(n , vi (2)) ;
    int x , y ;
    loop (i, 0 , n) {
        cin >>x>>y ;
        v[i] = {x,y} ;
    }
    sort (all(v)) ;
    // print (v) ;
    int cnt  = 1;
    int first = v[0][0] ;
    int last = v[0][1] ;
    for (int i = 1 ; i <n ; i++) {
        if (v[i][0] >= last) {
            last = v[i][1] ;
            cnt++;
        }
        else{
            last = min (last , v[i][1]) ;
        }
    }
        cout <<cnt <<endl ;

}
int32_t main(){
    I_am_speed();
    solve() ;
    return 0;
}