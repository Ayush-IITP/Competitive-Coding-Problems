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

int arr[200005] = {0};

int main()
{
  sync;
  int n,k,q;
  cin >> n >> k >> q;
  for(int i=0;i<n;i++)
  {
    int a,b;
    cin >> a >> b;
    arr[a]++;
    arr[b+1]--;
  }
  for(int i=1;i<200004;i++)
  {
    arr[i] = arr[i]+ arr[i-1];   
  }
  for(int i=1;i<200004;i++)
  {
    if(arr[i] >= k)
      arr[i] = 1;
    else
      arr[i] = 0;
  }
  for(int i=1;i<200004;i++)
    arr[i]+=arr[i-1];
  while(q--)
  {
    int a,b;
    cin >>  a >> b;
    cout << arr[b] - arr[a-1] << endl;
  }
}

