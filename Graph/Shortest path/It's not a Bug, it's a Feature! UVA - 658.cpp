#include <bits/stdc++.h>
#define mem(ar,num) memset(ar,num,sizeof(ar))
#define me(ar) memset(ar,0,sizeof(ar))
#define lowbit(x) (x&(-x))
#define Pb push_back
#define  FI first
#define  SE second
#define DEBUG cout<<endl<<"DEBUG"<<endl;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define IOS ios::sync_with_stdio(false)
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int    prime = 999983;
const int    INF = 1e8;
const LL     INFF =0x7FFFFFFFFFFFFFFF;
const double pi = acos(-1.0);
const double inf = 1e18;
const double eps = 1e-6;
const LL     mod = 1e9 + 7;
LL qpow(LL a,LL b){LL s=1;while(b>0){if(b&1)s=s*a%mod;a=a*a%mod;b>>=1;}return s;}
LL gcd(LL a,LL b) {return b?gcd(b,a%b):a;}
int dr[2][4] = {1,-1,0,0,0,0,-1,1};
typedef pair<int,int> P;
const int maxn = 300;
int Time[maxn]; 
int dis[(1<<20)+10];
bool vis[(1<<20)+10];
int N,M;
int  Have[maxn], Nothave[maxn];
int have[maxn], nothave[maxn];
// void print(int n){
//   char b[100];
//   itoa(n,b,2);
//     printf("%*0s ",N,b);
// }
void init(){
  me(Have),me(have);
    me(Nothave),me(nothave);me(vis);
    char ar[maxn],br[maxn];
    for(int i = 1;i <= M; ++i){
      scanf("%d%s%s",&Time[i],ar,br);
        for(int j = 0;j < N; ++j) {
          if(ar[j] == '-') Nothave[i] |= (1<<j);
          else if(ar[j] == '+') Have[i] |= 1<<j;
            if(br[j] == '-') nothave[i] |= (1<<j);
            else if(br[j] == '+') have[i] |= 1<<j;
    }
  }
 // for(int i = 1;i <= M; ++i) {
 //   print(Have[i]),print(Nothave[i]);
 
 //   print(have[i]),print(nothave[i]);
 //   printf("\n");
   
 // }
  
}
void Dij(){
    int S = (1<<N)-1;
    int T = 0;
    priority_queue<P,vector<P>,greater<P> > q;
    fill(dis,dis+(1<<N),INF);
    dis[S] = 0;
  q.push(P(0,S)); 
  while(!q.empty()){
    P p = q.top(); q.pop();
    if(p.SE == T)  break;
    int u = p.SE;
    if(vis[u]) continue;
    vis[u] = 1;
    for(int i = 1;i <= M; ++i){
      // if(i == 2){
      //   cout<<i<<" ";
      // cout<<(u&Have[i])<<" ";
      // cout<<(u&Nothave[i])<<endl;
      // }
      if((u &Have[i]) == Have[i] &&(u &Nothave[i]) == 0){
        int v = (u|have[i])&(~nothave[i]);
        // DEBUG
        //  print(v);
        //  cout<<endl;
        // DEBUG
        if(!vis[v]&&dis[v] > dis[u]+Time[i]){
          dis[v] = dis[u]+Time[i];
          // cout<<dis[v]<<endl;
          q.push(P(dis[v],v));
        }
      }
    }
    
  } 
  if(dis[T] == INF) printf("Bugs cannot be fixed.\n");
  else printf("Fastest sequence takes %d seconds.\n",dis[T]);
}
int main(void)
{
  int kase = 0;
  while(cin>>N>>M&&N){
    init();
    printf("Product %d\n",++kase);
    Dij();
    puts("");
  }

   return 0;
}


