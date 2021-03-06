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

vector <vector<int> > v(100005);
vector <vector<int> > w(100005);
int visited[100005];
int val[100005];
int flag = 0;
void check(int node)
{
  if(flag==1)
    return;
  visited[node]=1;
  for(int i=0;i<v[node].size();i++)
  {
    if(flag == 1)
      return;
    if(visited[v[node][i]]!=0)
    {
      int d = w[node][i];
      if(d==1)
      {
        if(val[node] == val[v[node][i]])
        {
          flag = 1;
          return;
        }
      }
      else
      {
         if(val[node]!=val[v[node][i]])
         {
           flag = 1;
           return;
         }
      }
    }
    else
    {
      if(w[node][i]==0)
      {
        val[v[node][i]] = val[node];
      }
      else
      {
        if(val[node]==1)
          val[v[node][i]]=0;
        else
          val[v[node][i]]=1;
      }
      check(v[node][i]);
    }
  }
}

int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
    int n,q,a,b,c;
    cin >> n >> q;
    flag = 0;
        memset(visited,0,sizeof(visited));
    for(int i=0;i<q;i++)
    {
      cin >> a >> b >> c;
      if(a==b)
      {
        if(c==1) flag = 1;
        continue;
      }
      v[a].pb(b);
      v[b].pb(a);
      w[a].pb(c);
      w[b].pb(c);
    }
    for(int i=1;i<=n;i++)
    {
       if(visited[i]==0)
       {
         val[i]=0;
         check(i);
         if(flag == 1)
           break;
       }
    }
    flag == 1 ? cout << "no" : cout << "yes";
    cout << endl;
    for(int i=1;i<=n;i++)
    {
      v[i].clear();
      w[i].clear();
    }

  }
}

