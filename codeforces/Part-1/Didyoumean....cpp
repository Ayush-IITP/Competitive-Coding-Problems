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
int arr[26]={0};
vector <int> v;
int main()
{
  string s;
  cin >> s;
  arr['a'-'a']=1;
  arr['e'-'a']=1;
  arr['i'-'a']=1;
  arr['o'-'a']=1;
  arr['u'-'a']=1;
  int cnt=0;
  for(int i=0;i<s.length();i++)
  {
   if(arr[s[i]-'a']==1)
     cnt=0;
   else
   {
     cnt++;
           if(cnt == 3)
           {
             if(s[i]==s[i-1]&&s[i-1]==s[i-2])
             {
               cnt=2;
             }
             else
             {
               v.pb(i);
               cnt=1;
             }
           }
   }
  }
  int idx=0;
  for(int j=0;j<v.size();j++)
  {
    for(int i=idx;i<s.length();i++)
    {
      if(i==v[j])
      {
        idx = i;
        cout << " ";
        break;
      }
      cout << s[i];
    }
  }
  for(int i=idx;i<s.length();i++)
    cout << s[i];
}
