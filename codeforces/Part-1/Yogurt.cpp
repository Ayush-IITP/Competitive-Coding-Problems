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
void merge(int x,int y){  //  x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y))     return ;
  if(par[y] < par[x]) // balancing the height of the tree
    swap(x, y);
  par[x] += par[y];
  par[y] = x;
}
*/


using namespace std;
int arr[5005];
int main()
{
  sync;
  int t;
  cin >> t;
  int tot = 0;
  while(t--)
  {
  	tot++;
  	int n,k;
  	cin >> n >> k;
  	for(int i=0;i<n;i++)
  		cin >> arr[i];
    sort(arr,arr+n);
    int curDay = 0,ans=0,idx=0;
    while(idx<n)
    {
    	for(int i=0;i<k && idx < n;)
    	{
    		if(curDay < arr[idx])
    		{
    			ans++;
    			i++;
    		}
    		idx++;
    	}
    	curDay++;
    }
    cout << "Case #"<<tot<<": " << ans << endl;
  }
}
