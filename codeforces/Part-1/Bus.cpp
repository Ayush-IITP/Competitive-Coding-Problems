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

int main()
{
  sync;
  ll a,b,f,k;
  cin >> a >> b >> f >> k;
  ll fin = b;
  ll tot = a*k;
  ll cur = 0;
  ll cunt =0;
  ll cnt=0;
  if(f>b)
  {
    cout << "-1" << endl;
    return 0;
  }
  cur = f;
  b-=f;
  for(ll i=f;i<tot;)
  {
    cnt++;
    if(cnt%2)
    {
      i+=(a-f);
      i+=(a-f);
    }
    else
    {
      i+=f;
      i+=f;
    }
    if(i>=tot)
      i=tot;
    //cout << i << endl;
    if(i-cur>b)
    {
      cunt++;
      b=fin;
      if(i-cur>b)
      {
        cout << "-1" << endl;
        return 0;
      }
      b-=(i-cur);
      cur=i;
    }
    else
    {
      b-=(i-cur);
      cur=i;
    }
  }
  cout << cunt << endl;
  
}

