/*************
        Author - am10
             ******************/
#include<bits/stdc++.h>
 
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
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


using namespace std;

int main()
{
  sync;
  int n;
  cin >> n;
  string s;
  cin >> s;
  int l=0,r=0,u=0,d=0;
  for(int i=0;i<s.length();i++)
  {
  	if(s[i]=='L')
  		l++;
  	if(s[i]=='R')
  		r++;
  	if(s[i]=='U')
  		u++;
  	if(s[i]=='D')
  		d++;
  }
  cout << 2*min(l,r)+2*min(u,d) << endl;
}
