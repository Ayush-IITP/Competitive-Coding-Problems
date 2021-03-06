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
int temp[1000005];
int dp[1000005];
vector <int> ans;
vector <int> v;
int level[1000005];
int par[1000005];
void dfs(int node,int par)
{
  dp[node]=temp[node];
  level[node]=1+level[par];
  for(int v : g[node])
  {
    if(v==par)continue;
    dfs(v,node);
    dp[node]+=dp[v];
  }
}

bool check(int u,int v)
{
  if(level[u]<=level[v])
    return false;
  while(level[u]>level[v])
  {
    u = par[u];
  }
  if(u==v)
    return true;
  else
    return false;
}

int main()
{
  sync;
  int n,a,b,root,sum=0;
  cin >> n;
  for(int i=1;i<=n;i++)
  {
    cin >> a >> b;
    if(a==0)
    {
      root = i;
    }
    else
    {
      g[i].pb(a);
      g[a].pb(i);
    }
    temp[i]=b;
    par[i]=a;
    sum+=b;
  }
  level[0]=-1;
  dfs(root,0);
  if(sum%3!=0)
  {
    cout << "-1" << endl;
    return 0;
  }
  else
  {
    int req = sum/3;
    int cnt = 0;
    for(int i=1;i<=n;i++)
    {
      if(dp[i]==req)
      {
         cnt++;
         ans.pb(i);
      }
      else if(dp[i]==2*req)
         v.pb(i);
    }
    if(cnt>1)
    {
      cout << ans[0] << " " << ans[1] << endl;
    }
    else
    {
      for(int i=0;i<ans.size();i++)
      {
        for(int j=0;j<v.size();j++)
        {
          if(check(ans[i],v[j]))
          {
            cout << ans[i] << " " << v[j] << endl;
            return 0;
          }
        }
      } 
      cout << "-1" << endl;
    }
  } 
}

