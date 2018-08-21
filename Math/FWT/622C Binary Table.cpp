
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
// const LL     mod = 1e9 + 7;
// LL qpow(LL a,LL b){LL s=1;while(b>0){if(b&1)s=s*a*1;a=a*a*1;b>>=1;}return s;}
LL gcd(LL a,LL b) {return b?gcd(b,a%b):a;}
int dr[2][4] = {1,-1,0,0,0,0,-1,1};
typedef pair<int,int> P;

// 异或
void FWT(LL *a,int N,int opt){
	
	// j是区间开始点，i是区间距离，k是具体位置，j+k,i+j+k就是在a数组中的坐标
	for(int i = 1;i < N; i <<= 1){
		for(int p = i<<1,j = 0;j < N; j += p){
			for(int k = 0;k < i; ++k){
                LL X = a[j+k],Y = a[i+j+k];
                a[j+k] = (X+Y);
                a[i+j+k] = (X-Y);
                if(opt == -1) a[j+k] = a[j+k]/2,a[i+j+k] = a[i+j+k]/2;
			}
		}
	}
}
void update(LL *a,LL *b,int n){
	FWT(a,n,1);
	FWT(b,n,1);
	rep(i,0,n) a[i] = 1ll*a[i]*b[i];
	FWT(a,n,-1);
}
int n,m;
const int maxn = 22;
const int maxm = 1e5+100;
char ar[maxn][maxm];
const int MAXN = (1<<20);
LL a[MAXN+10],b[MAXN+10];
int main(void){
    
     cin>>n>>m;
     int N = 1<<n;
     rep(i,0,n) scanf("%s",ar[i]);
     rep(j,0,m){
     	int x = 0;
     	rep(i,0,n){
              x = (x<<1)+ar[i][j]-'0';
     	}
     	a[x]++;
     }
     // DEBUG;
     // rep(i,0,N)
     //   cout<<i<<" "<<a[i]<<endl;
     rep(i,0,N) b[i] = b[i>>1]+(i&1);
     rep(i,0,N) b[i] = min(b[i],n-b[i]);
     // DEBUG;
     // rep(i,0,N) cout<<i<<" "<<b[i]<<endl;
     update(a,b,N);
     LL ans = a[0];
     rep(i,1,N) ans = min(ans,(LL)a[i]);
     
     cout<<ans<<endl;
    // DEBUG;
    // rep(i,0,N)cout<<a[i]<<" ";
	return 0;
}
