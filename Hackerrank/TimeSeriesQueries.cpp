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
vector <int> t,p;
vector <pii >q1,q2;
int ans[100005];
int res[100005];
int main()
{
  sync;
  int n,q,a,b;
  cin >> n >> q;
  memset(ans,0,sizeof(ans));
  //memset(res,-1,sizeof(res));
  for(int i=0;i<n;i++)
  {
    cin >> a;
    t.pb(a);
  }
  for(int i=0;i<n;i++)
  {
    cin >> a;
    p.pb(a);
  }
  for(int i=0;i<q;i++)
  {
    cin >> a >> b;
    if(a==1)
    {
      q1.pb({b,i});
    }
    else
    {
      q2.pb({b,i});
    }
  }
  //sort(q1.begin(),q1.end());
  int mux = INT_MIN;
  for(int i=n-1;i>=0;i--)
  {
    mux = max(p[i],mux);
    res[i] = mux;
  }
  for(int i=0;i<q1.size();i++)
  {int flag = 0;
    for(int j=0;j<n;j++)
    {
      if(p[j]>=q1[i].FI)
      {
        ans[q1[i].SE]=t[j];
        flag = 1;
        break;
      }
    }
    if(flag == 0)
    {
      ans[q1[i].SE]=-1;
    }
  }
  for(int i=0;i<q2.size();i++)
  {
    if(lower_bound(t.begin(),t.end(),q2[i].FI)!=t.end()){
    int idx = lower_bound(t.begin(),t.end(),q2[i].FI)-t.begin();
    ans[q2[i].SE] = res[idx];}
    else
    {
        ans[q2[i].SE] = -1;
    }
  } 
  for(int i=0;i<n;i++)
  {
    if(ans[i]==0)
      cout <<"jkjb"<<endl;
    cout << ans[i] << endl;
  }
}

