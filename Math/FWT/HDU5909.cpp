
#include <bits/stdc++.h>
#define mem(ar,num) memset(ar,num,sizeof(ar))
#define me(ar) memset(ar,0,sizeof(ar))
#define lowbit(x) (x&(-x))
#define Pb push_back
#define  FI first
#define  SE second
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define IOS ios::sync_with_stdio(false)
#define DEBUG cout<<endl<<"DEBUG"<<endl; 
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int    prime = 999983;
const int    INF = 0x7FFFFFFF;
const LL     INFF =0x7FFFFFFFFFFFFFFF;
const double pi = acos(-1.0);
const double inf = 1e18;
const double eps = 1e-6;
const LL     mod = 1e9 + 7;
LL qpow(LL a,LL b){LL s=1;while(b>0){if(b&1)s=s*a%mod;a=a*a%mod;b>>=1;}return s;}
LL gcd(LL a,LL b) {return b?gcd(b,a%b):a;}
int dr[2][4] = {1,-1,0,0,0,0,-1,1};
typedef pair<int,int> P;
const int inv2 = (mod+1)/2;
// 异或
void FWT(int *a,int N,int opt){
	
	// j是区间开始点，i是区间距离，k是具体位置，j+k,i+j+k就是在a数组中的坐标
	for(int i = 1;i < N; i <<= 1){
		for(int p = i<<1,j = 0;j < N; j += p){
			for(int k = 0;k < i; ++k){
                int X = a[j+k],Y = a[i+j+k];
                a[j+k] = (X+Y)%mod;
                a[i+j+k] = (X+mod-Y)%mod;
                if(opt == -1) a[j+k] = 1ll*a[j+k]*inv2%mod,a[i+j+k] = 1ll*a[i+j+k]*inv2%mod;


			}
		}
	}
}
void update(int *a,int *b,int n){
	FWT(a,n,1);
	FWT(b,n,1);
	rep(i,0,n) a[i] = 1ll*a[i]*b[i]%mod;
	FWT(a,n,-1);
}
const int maxn = 1300;
int dp[maxn][maxn];
vector<int> edge[maxn];
int V[maxn];
int tmp[maxn];
int ans[maxn];
int n,m;
void dfs(int node,int fa){
    dp[node][V[node]] = 1;
    int size = edge[node].size();
	for(int i = 0;i < size; ++i){
		int to = edge[node][i];
		if(to == fa) continue;
        dfs(to,node);
        rep(j,0,m) tmp[j] = dp[node][j];
        update(tmp,dp[to],m);
        rep(j,0,m) dp[node][j] = (dp[node][j]+tmp[j])%mod;
	}
	rep(i,0,m) ans[i] = (ans[i]+dp[node][i]) %mod;
}
int main(void)
{
    int T;
    cin>>T;
    while(T--){
         scanf("%d %d",&n,&m);
         me(ans),me(dp);
         rep(i,1,n+1) edge[i].clear();
         rep(i,1,n+1) scanf("%d",&V[i]); 
         rep(i,1,n) {
         	int u,v;
         	scanf("%d %d",&u,&v);
         	edge[u].Pb(v);
         	edge[v].Pb(u);
         }
        dfs(1,0);
        // LL sum = 0;
        rep(i,0,m)  printf("%d%c",ans[i]," \n"[i==m-1]);
       
    }

   return 0;
}
