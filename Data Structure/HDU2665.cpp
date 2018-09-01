
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
const int maxn = 1e5+10;
int sum[maxn<<5],L[maxn<<5],R[maxn<<5];
int rt[maxn];
int a[maxn],Hash[maxn];
int tot = 0;
int build(int l,int r){
	int rt = (++tot);
    sum[rt] = 0;
    if(l < r){
    	int m = (l+r) >> 1;
    	L[rt] = build(l,m);
    	R[rt] = build(m+1,r);
    }
    return rt;
}

int update(int pre,int l,int r,int x){
     int rt = (++tot);
     L[rt] = L[pre],R[rt] = R[pre],sum[rt] = sum[pre]+1;
     if(l < r){
     	int m = (l+r)>>1;
     	if(x <= m)
     		L[rt] = update(L[pre],l,m,x);
        else 
        	R[rt] = update(R[pre],m+1,r,x);
     }
     return rt;
}
int query(int u,int v,int l,int r,int k){
    if(l >= r) return r;
	int num = sum[L[v]]-sum[L[u]];
	int m = (l+r)>>1;
    if(num >= k)
    	return query(L[u],L[v],l,m,k);
    	return query(R[u],R[v],m+1,r,k-num);
}
// int tmp[maxn];
int main(void)
{
  
  	int T;
  	scanf("%d",&T);
  	while(T--){
  		tot = 0;
  		int n,m;
  		scanf("%d%d",&n,&m);
  		// map<int,int> ma;
  		rep(i,1,n+1){scanf("%d",&a[i]);Hash[i] =  a[i];}
  		sort(Hash+1,Hash+1+n);
  		int id = unique(Hash+1,Hash+n+1) - Hash-1;
  		// int cnt = 0;
  		rt[0] = build(1,id);
        rep(i,1,n+1){
        	// cout<<ma[a[i]]<<endl;
           int x = lower_bound(Hash+1,Hash+id+1,a[i]) - Hash;
           rt[i] = update(rt[i-1],1,id,x);
        }
        rep(i,0,m){
        	int l,r,k;
        	scanf("%d%d%d",&l,&r,&k);
        	int ans = query(rt[l-1],rt[r],1,id,k);
        	// cout<<ans<<endl;
        	printf("%d\n",Hash[ans]);
        }
  	}    

   return 0;
}
