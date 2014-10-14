#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ft first
#define sd second
#define VI vector<int>
#define VLL vector<long long int>
#define PII pair<int,int>
#define pb push_back
#define rsz(v,n) v.resize(n)
// input and output
#define scan(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define ll long long int
#define rep(i,x,y) for(i=x;i<y;i++)
#define print(x) printf("%d\n",x)
#define printll(x) printf("%lld\n",x)
#define all(v) v.begin(),v.end()
#define ms(v) memset(v,0,sizeof(v))
#define FOR(i,a,b)  for(i=a;i<b;i++)
#define f_in(st) freopen(st,"r",stdin)
#define f_out(st) freopen(st,"w",stdout)
#define PIE 3.14159265358979323846264338327950
#ifdef ONLINE_JUDGE
 inline void inp( int &n )
 {
    n=0;
    int ch=getchar_unlocked();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    n=n*sign;
  }
#else
inline void inp(int &n){
 cin>>n;
}
#endif
const int MAX = 200100;
char A[MAX],C[MAX];
string txt; //input
int iSA[MAX], SA[MAX]; //output
int cnt[MAX], next_gen[MAX]; //internal
bool bh[MAX], b2h[MAX],m_arr[MAX];
int len;
bool smaller_first_char(int a, int b){
  return txt[a] < txt[b];
}
 /**
 $
 $
 $  TESTER SOLUTION USES SUFFIX ARRAY APPROACH
    COMPLEXITY : o(NLOGN)
    SKEW ALGORITHM
 $
 $***/
inline void suffixSort(int n){
  for (int i=0; i<n; ++i){
    SA[i] = i;
  }
  sort(SA, SA + n, smaller_first_char);
  for (int i=0; i<n; ++i){
    bh[i] = i == 0 || txt[SA[i]] != txt[SA[i-1]];
    b2h[i] = false;
  }
  for (int h = 1; h < n; h <<= 1){
    int buckets = 0;
    for (int i=0, j; i < n; i = j){
      j = i + 1;
      while (j < n && !bh[j]) j++;
      next_gen[i] = j;
      buckets++;
    }
    if (buckets == n) break; // We are done! Lucky bastards!
    for (int i = 0; i < n; i = next_gen[i]){
      cnt[i] = 0;
      for (int j = i; j < next_gen[i]; ++j){
        iSA[SA[j]] = i;
      }
    }
    cnt[iSA[n - h]]++;
    b2h[iSA[n - h]] = true;
    for (int i = 0; i < n; i = next_gen[i]){
      for (int j = i; j < next_gen[i]; ++j){
        int s = SA[j] - h;
        if (s >= 0){
          int head = iSA[s];
          iSA[s] = head + cnt[head]++;
          b2h[iSA[s]] = true;
        }
      }
      for (int j = i; j < next_gen[i]; ++j){
        int s = SA[j] - h;
        if (s >= 0 && b2h[iSA[s]]){
          for (int k = iSA[s]+1; !bh[k] && b2h[k]; k++) b2h[k] = false;
        }
      }
    }
    for (int i=0; i<n; ++i){
      SA[iSA[i]] = i;
      bh[i] |= b2h[i];
    }
  }
  for (int i=0; i<n; ++i){
    iSA[SA[i]] = i;
  }
}
int lcp[MAX];
inline void getlcp(int n)
{
  for (int i=0; i<n; ++i)
    iSA[SA[i]] = i;
  lcp[0] = 0;
  for (int i=0, h=0; i<n; ++i)
  {
    if (iSA[i] > 0)
    {
      int j = SA[iSA[i]-1];
      while (i + h < n && j + h < n && txt[i+h] == txt[j+h])
          h++;
      lcp[iSA[i]] = h;
      if (h > 0)
        h--;
    }
  }
}
int LCP[MAX][22];
inline void initialize_lcp()
{
    for(int i = 0;i<len;++i)
    LCP[i][0] = lcp[i];
    for(int j = 1;(1<<j)<=len;++j){
        for(int i = 0;i+(1<<j)-1<len;++i){
            if(LCP[i][j-1]<=LCP[i+ ( 1<<(j-1) )][j-1])
                LCP[i][j] = LCP[i][j-1];
            else
                LCP[i][j] = LCP[i+(1<<(j-1))][j-1];
        }
    }
}
inline int lcpmain(int x, int y)
{
    if(x == y) return len-iSA[x];
    if(x > y) swap(x,y);
    int log = 0;
    while((1<<log)<=(y-x)) ++log;
    --log;
    return min(LCP[x+1][log],LCP[y-(1<<log)+1][log]);
}
int main()
{
 cin>>txt;
 len=txt.length();
 assert(len<=200000);
 reverse(all(txt));
 suffixSort(len);
 getlcp(len);
 initialize_lcp();
 int q;
 inp(q);
 assert(q<=200000);
 while(q--)
 {
     int idx;
     inp(idx);
     idx--;
     idx=len-idx;
     idx--;
     if(idx==0)
      print(len);
     else
     print(lcpmain(iSA[idx],iSA[0]));
 }
 return 0;
}
