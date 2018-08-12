
#include <bits/stdc++.h>
#define mem(ar,num) memset(ar,num,sizeof(ar))
#define me(ar) memset(ar,0,sizeof(ar))
#define lowbit(x) (x&(-x))
#define Pb push_back
#define  FI first
#define  SE second
#define For(i,a,b) for(int i = a; i < b; ++i)
#define IOS ios::sync_with_stdio(false)
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
int n,m;
const int maxn = 30;
string s[maxn];
bool call[maxn][maxn];
bool vis[maxn];
bool con[maxn][maxn];
vector<int> v;
void dfs(int node){
	for(int i = 1;i <= n; ++i)
	  if(!vis[i] && con[node][i]){
	  	vis[i] = 1;
	  	v.Pb(i);
	  	dfs(i);
	  }
}
int main(void)
{
//	IOS;
   int kase = 0;
   while(cin>>n>>m&&n){
   	if(kase) puts(""); 
   	me(vis),me(con),me(call); 
   	
   	string s1,s2;

   	unordered_map<string,int> ma;
   	int cnt = 0;
   	while(m--){
   		int u,v;
   		cin>>s1>>s2;
		if(ma[s1]) u = ma[s1];
		else {
			u = ma[s1] = ++cnt;
			s[cnt] = s1;
		}
		if(ma[s2]) v = ma[s2];
		else {
			v = ma[s2] = ++cnt;
			s[cnt] = s2;
		}
		call[u][v] = true; 
	   }
    for(int k = 1; k <= n; ++k)
      for(int i = 1;i <= n; ++i)
        for(int j = 1; j <= n; ++j)
		   call[i][j] = call[i][j]||(call[i][k]&&call[k][j]);
    for(int i = 1;i <= n; ++i)
	   for(int j = 1;j <= n; ++j)
	      if(call[i][j]&&call[j][i])
		     con[i][j] = con[j][i] = 1;
	vector<vector<int>> ans;
	for(int i = 1;i <= n; ++i){
		if(!vis[i]){
			v.clear();
			vis[i] = 1;
			v.Pb(i);
			dfs(i);
			ans.Pb(v);
		}
	} 
	printf("Calling circles for data set %d:\n",++kase);
    for(auto v:ans)
    {
        for(int i = 0;i < v.size(); ++i){
        	int t = v[i]; 
        	printf("%s%s",s[t].c_str(),i==v.size()-1?"\n":", ");
		}
	}
   	
   }	


   return 0;
}

