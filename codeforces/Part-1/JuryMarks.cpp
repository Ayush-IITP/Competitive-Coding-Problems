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
set <int > s;
set <int> ans;
int dp[17000005] = {0};
vector <int> v;
int main()
{
  sync;
  int n,k,a;
  cin >> n >> k;
  int sum = 0;
  for(int i=0;i<n;i++)
  {
    cin >> a;
    sum+=a;
    s.insert(sum);
  }
  for(int i=0;i<k;i++)
  {
    cin >> a;
    v.pb(a);
  }
  sort(v.begin(),v.end());
  set <int> :: iterator itr;
  for(itr = s.begin();itr!=s.end();itr++)
  {
    for(int i=0;i<k;i++)
    {
       int x = v[i]-*itr;
       dp[x+8500000]++;     
      
    }
  }
  int cnt = 0;
  for(int i=0;i<17000005;i++)
  {
    if(dp[i] == k)
      cnt++;
  } 
  cout << cnt << endl;
}

