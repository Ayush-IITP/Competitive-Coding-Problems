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
  int a[6],tsum = 0;
  for(int i=0;i<6;i++)
  	cin >> a[i],tsum+=a[i];

  for(int i=1;i<=63;i++)
  {
  	int cnt = 0,sum=0;
  	for(int j=0;j<6;j++)
  	{
  		if((1<<j)&i)
  		{
  			sum+=a[j];
  			cnt++;
  		}
    }
    if(cnt == 3 && sum == (tsum/2.0))
    {
    	cout << "yes" << endl;
    	return 0;
    }
  }
  cout << "no" << endl;
}
