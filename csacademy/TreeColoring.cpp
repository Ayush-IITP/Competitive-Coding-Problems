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
ll n,k;
vector <ll> g[100005];
ll col[100005];
ll parent[100005];
ll mod = 1e9+7;
void dfs(ll node,ll par)
{
  parent[node]=par;
  ll x;
  if(par==0)
    x=k-1;
  else
    x = k-2;
  for(int i=0;i<g[node].size();i++)
  {
    if(g[node][i]==par) continue;
    col[g[node][i]]=(x--);
    dfs(g[node][i],node);
  }
}

int main()
{
  sync;
  cin >> n >> k;
  for(ll i=1;i<n;i++)
  {
    ll a,b;
    cin >> a >> b;
    g[a].pb(b);
    g[b].pb(a);
  }
  col[1]=k;
  col[0]=k;
  parent[1]=0;
  dfs(1,0);
  ll ans=1;
  for(int i=1;i<=n;i++)
  {
    //cout << col[i] << endl;
    ans = ans*col[i];
    if(col[i]<0)
      ans=0;
    ans%=mod;
  }
  cout << ans << endl;
}

