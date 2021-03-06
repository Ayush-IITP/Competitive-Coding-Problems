/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define PI acos(-1)
#define pii pair <int,int>
#define FI first
#define SE second
 
/*
//D-S-U
int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge(int x,int y){	//	x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y))     return ;
	if(par[y] < par[x])	// balancing the height of the tree
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
}
*/
 
//**********MODULAR EXPONENTIATION******************/
/*
int power(int x, unsigned int y, int p)
{
    int res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}
*/
using namespace std;
 
vector <int> g[1000005];
ll n,m;
vector<ll> dp[1000001];
vector<map<ll,ll>> dp1(1000001);
ll cnt=0;
ll solve(int idx,int previdx)
{
  //cout << idx << " " << previdx << endl;
  ll prev = g[idx-1][previdx];
  ll ans=0;
  ll res = -1;
  if(idx>n)
    return 0;
  if(dp[idx][previdx]!=-1)
    return dp[idx][previdx];
  if(dp1[idx].find(prev)!=dp1[idx].end())
    return dp1[idx][prev];
  else
  {
    for(ll i=0;i<g[idx].size();i++)
    {
      ans = abs(g[idx][i+1==g[idx].size()?0:i+1]-prev)*(idx-1)+solve(idx+1,i);
      res = max(res,ans);
    }
  }
  dp1[idx][prev]=res;
  dp[idx][previdx]=res;
  return (res);
}
 
int main()
{
  sync;
  cin.tie(NULL  );
  ll t,a,k;
  cin >> t;     
  while(t--)
  {
    cin >> n;
    for(int i=1;i<=n;i++)
    {
      cin >> m;
      dp[i].resize(k+1);
      fill(dp[i].begin(),dp[i].end(),-1);
      g[i].clear();
      for(int j=0;j<m;j++)
        cin >> a,g[i].pb(a);
      k=m;
    }   
    int start = *min_element(g[1].begin(),g[1].end());
    int start1 = *max_element(g[1].begin(),g[1].end());
    int x1,x2;
    for(int i=0;i<g[1].size();i++)
    {
      if(g[1][i]==start)
        x1 = i;
      if(g[1][i]==start1)
        x2 = i;
    }
    ll res1 = solve(2,x1);
    cnt = 0;
    ll res2 = solve(2,x2);
    cout << max(res1,res2) << endl;
    //cout << solve(2,x1) << endl;
    /*for(int i=1;i<=3;i++)
    {
      for(int j=0;j<dp[i].size();j++)
        cout  << dp[i][j].first <<"," << dp[i][j].second << " ";
      cout << endl;
    }*/
    for(ll i=1;i<=n;i++)
       dp1[i].clear();  
  }
}
 
