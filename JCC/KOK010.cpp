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
ll arr[10000007];
ll temp[10000007];
int main()
{
  sync;
  int n,m;
  cin >> n >> m;
  for(int i=1;i<=n;i++)
    arr[i] = (ll)min(i,n-i);
  ll a,b,k,q;
  for(int i=0;i<m;i++)
  {
    cin >> q >> a >> b >> k;
    if(!q) temp[a]+=k,temp[b+1]-=k;
    else temp[a]-=k,temp[b+1]+=k;
  }
  ll mux = LLONG_MIN;
  ll mun = LLONG_MAX;
  for(int i=1;i<=n;i++)
  {
     temp[i]+=temp[i-1],arr[i]+=temp[i];
     mux = max(mux,arr[i]);
     mun = min(mun,arr[i]);
  }
  cout << mun << " " << mux << endl;
  
}

