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
	if(par[y] < par[x])	// balancing the height of the tree        /*************
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

int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
    int n,m,s,p,q;
    cin >> n >> m >> s >> p >> q;
    int ttime = 2*s;
    int pv =1,pr=1;
    int cnt=0,ans=0;   
    while(ttime--)
    {
      cnt++;
      if(cnt%2)
      {
        pv+=p;
        if(pv>n)
        {
          pv = m-1+pv%n;
        }
        //cout << cnt << " " << pv << endl;
      }
      else
      {
        pr+=q;
        if(pr>n)
        {
          pr = m-1+pr%n;
        }
        //cout << cnt << " " << pr << endl;
      }
      if(pv == pr)
      {ans++;}
      //cout << ans << endl;
    }
    cout << ans << endl;
  }
}
