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

int arr[55];
int n;
int dp[51][2][500005];
int solve(int cur,int chance,int t)
{
  int sum=0,sum1=0;
  if(cur >=n)
    return 0;
  if(dp[cur][chance][t]!=-1)
    return dp[cur][chance][t];
  if(chance == 0)
  {
    sum = max(arr[cur]+(t-arr[cur]-solve(cur+1,1,t-arr[cur])),solve(cur+1,0,t-arr[cur]));
    dp[cur][chance][t] = sum;
    return sum;
  }
  else
  {
    sum1 =max(arr[cur]+(t-arr[cur]-solve(cur+1,0,t-arr[cur])),solve(cur+1,1,t-arr[cur]));
    dp[cur][chance][t] = sum1;
    return sum1;
  }
  
}

int main()
{
  sync;         
  memset(dp,-1,sizeof(dp));
  cin >> n;
  int t=0;
  for(int i=0;i<n;i++)
  {
    cin >> arr[i];
    t=t+arr[i];
  }
  int k = solve(0,0,t);
  cout << t-k << " " << k << endl;
}

