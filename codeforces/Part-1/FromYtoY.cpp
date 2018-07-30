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
  int k;
  cin >> k;
  string ans = "ab";
  int offset=1;
  while(k!=0)
  {
    int res = ceil((sqrt(8*k+1)-1)/2.0);
    if(res*(res+1)==2*k)
    {
      string s(res,'a'+offset); 
      ans = ans + s;
      break;
    }
    else
    {
      string s(res-1,'a'+offset);
      ans = ans + s;
    }
    k = k - ((res)*(res-1))/2;
    offset++;
    char c= 'a'+offset;
    ans = ans + c;
    offset++;
    c = 'a'+offset;
    ans+=c;
  }
  cout << ans << endl;
} 
