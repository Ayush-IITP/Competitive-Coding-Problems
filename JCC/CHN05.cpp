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
int arr[105];
int main()
{
  sync;
  int t;
  cin >> t;
  while(t--)
  {
  	int n,m;
  	cin >> n >> m;
  	int k = m;
  	int ans = 2*m-1;
  	int cnt = 0;
  	arr[1] = m;
  	for(int i=2;i<=n;i++)
  	{
      if(cnt == 0)
      {
      	m--;
      	arr[i]=m;
      	cnt++;
      	continue;
      }
      arr[i]=m;
      cnt++;
      if(cnt%2 == 0)
      	cnt=0;
  	}
  	
  }
}
