/**************************************************************
    Problem: 4589
    User: zzuzxy
    Language: C++
    Result: Accepted
    Time:5508 ms
    Memory:2076 kb
****************************************************************/
 
 
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
const int    mod = 1e9 + 7;
LL qpow(LL a,LL b){LL s=1;while(b>0){if(b&1)s=s*a%mod;a=a*a%mod;b>>=1;}return s;}
LL gcd(LL a,LL b) {return b?gcd(b,a%b):a;}
int dr[2][4] = {1,-1,0,0,0,0,-1,1};
typedef pair<int,int> P;
const int maxn = 1e5+100;
int  a[maxn];
int  b[maxn];
void init(){
    for(int i = 2;i < maxn; ++i) a[i] = 1;
    for(int i = 2;i < maxn; ++i ){
        if(a[i]){
          for(int j = i+i; j < maxn; j += i) a[j] = 0;
        }
    }
}
// int a[];
// const int MOD = mod;
#define check_mod(a,b) ((a) <= (b)?(a): (a-b))
void FWT(int *a,int N,int opt){
    const int inv2 = qpow(2,mod-2);
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
// void FWT(int *a,int N,int opt)
// {
//  const int MOD = mod;
//  const int inv2 = qpow(2,mod-2);
//     for(int i=1;i<N;i<<=1)
//         for(int p=i<<1,j=0;j<N;j+=p)
//             for(int k=0;k<i;++k)
//             {
//                 int X=a[j+k],Y=a[i+j+k];
//                 a[j+k]=(X+Y)%MOD;a[i+j+k]=(X+MOD-Y)%MOD;
//                 if(opt==-1)a[j+k]=1ll*a[j+k]*inv2%MOD,a[i+j+k]=1ll*a[i+j+k]*inv2%MOD;
//             }
// }
int main(void)
{
          
    init();
    int n,m;
    // while(~scanf("%d %d",&n,&m)){
    while(cin>>n>>m){
        me(b);
        for(int i = 0;i <= m; ++i) b[i] = a[i];
        LL t = 2;
        while( t <= m) t <<= 1;
 
        FWT(b,t,1);
        for(int i = 0;i < t; ++i) b[i] = qpow(b[i],n);
        FWT(b,t,-1);
        printf("%d\n",b[0]);
    }
    return 0;
}
﻿
