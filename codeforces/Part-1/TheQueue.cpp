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

ll time1[100005];

int main()
{
  sync;
  ll ts,tf,t;
  cin >> ts >> tf >> t;
  ll n;
  cin >> n;
  for(int i=0;i<n;i++)
  {
    cin >> time1[i];
  }               
  ll idx=0;
  ll res = 1e15;
  ll ans;
  ll ctime1;
  for(ll i=ts;i<tf&&idx<=n;i+=t)
  {
    ll wt;
    //cout << i << endl;
        ctime1=i;
    if(i+t >= tf)
      break;
    if(i<time1[idx])
    {
      cout << i << endl;
      return 0;
    }
    if(idx>0 && time1[idx]-1>time1[idx-1])
        wt = i-(time1[idx]-1);
    if(idx==0)
        wt = i-(time1[idx]-1);
    if(wt < res)
    {
      res = wt;
      ans = time1[idx]-1;
    }
    idx++;  
  }
  if(ctime1+t<=tf && idx>=n)
  {
    cout << ctime1 << endl;
    return 0;
  }
  cout << ans << endl;
       
}

