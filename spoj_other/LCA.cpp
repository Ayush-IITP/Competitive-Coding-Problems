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

vector <int> g[1005];
int level[10005];
int par[1005][15];

void dfs(int node,int par1)
{
  level[node]=1+level[par1];
  for(int i=0;i<g[node].size();i++)
  {
    int v = g[node][i];
    //cout << v << " "; 
    if(v==par1)continue;
    else
    {
      par[v][0]=node;
      dfs(v,node);
    }
  }
}        

int lca(int u,int v)
{
  if(u==v)
    return u;
  if(level[u]<level[v]) swap(u,v);
  int x = u;
  for(int i=12;i>=0;i--)
  {
    if(level[x]==level[v])
      break;
    else
    {
      if(par[x][i]!=-1 && level[par[x][i]]>=level[v])
       x = par[x][i];
    }
  }
  if(x==v)
   return x;
  //cout << x << " " << v << endl;
  u = x;
  for(int i=12;i>=0;i--)
  {
    if(par[u][i]!=-1&&par[u][i]!=par[v][i])
       u=par[u][i],v=par[v][i];
  }
  return par[u][0];
}

int main()
{
  sync;
  int t;
  cin >> t;
  int cnt=0;
  while(t--)
  {
    cnt++;
    int n;
    cout << "Case " << cnt << ":" << endl; 
    cin >> n;
    memset(par,-1,sizeof(par));
    for(int i=1;i<=n;i++)
    {
      int m;
      cin >> m;
      for(int j=0;j<m;j++)
      {
        int x;
        cin >> x;
        g[i].pb(x);
        g[x].pb(i);
      }
    }
    par[1][0]=0;
    level[0]=-1;
    dfs(1,0);    
    /*for(int i=1;i<=n;i++)
      cout << par[i][0] << " ";
    cout << endl;
    for(int i=1;i<=n;i++)
      cout << level[i] << " ";
    cout << endl;*/
    for(int i=1;i<=12;i++)
    {
      for(int j=1;j<=n;j++)
      {
        if(par[j][i-1]!=-1)
        {
          par[j][i] = par[par[j][i-1]][i-1];
        }
      }
    }
    int q;
    cin >> q;
    for(int i=0;i<q;i++)
    {
      int u,v;
      cin >> u >> v;
      cout << lca(u,v) << endl;
    }
    for(int i=1;i<=1002;i++)
      g[i].clear();
  }
}

