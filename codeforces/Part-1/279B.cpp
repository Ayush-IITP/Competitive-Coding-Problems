/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false)
#define endl '\n'
#define ll long long
#define pb push_back
#define pii pair <int,int>

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
using namespace std;

vector <ll> v;

int main()
{
  sync;
  ll n,t;
  cin >> n >> t;
  for(ll i=0;i<n;i++)
  {
    ll a;
    cin >> a;
    v.pb(a);
  }
  ll l=0,r=0;
  ll ans = -1;
  ll sum = 0;
  while(l<=r)
  {
              while( r< n && sum+v[r] <= t  )
              {
                sum = sum+v[r];
                r++;
              }
              ans = max(ans,r-l);
              if(sum == 0)
              {
                l++;
                r++;
                if(l==n)
                break;
                continue;
              }
              sum = sum-v[l];
              l++;
              if(l==n)
                break;
              
    
    
  }
  cout << ans << endl;
}

