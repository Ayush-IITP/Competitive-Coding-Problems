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
int n,q;
vector <int> v[100005];
int wt[100005];
vector <pii>mark(100005,{-1,-1});   
vector <int>dis[100005],dis1[100005];
int mun[100005];
int clock1[100005];
int anti[100005];

void init()
{
   for(int i=1;i<=n;i++)
   {
     v[i].clear();
     mark[i] = {-1,-1};
     dis[i].clear(),dis1[i].clear();
     mun[i]=0,clock1[i]=0,anti[i]=0,wt[i]=0;
   }
}
void solve(int x)
{
  /*for(int i=1;i<=v[x].size();i++)
  {
    for(int j=0;j<g[i].size();j++)
      cout<<g[i][j].first << "+" << g[i][j].SE << " ";
    cout << endl; 
  }*/
  int f = mark[x].FI;   
  int s = mark[x].SE;
  //cout << f << " " << s << endl;
  mun[f]=0;
  mun[s]=0;
  dis[x].pb(-1);
  dis1[x].pb(-1);
  for(int i=f+1;i!=f;i++)
  {
    if(i>v[x].size())
    {
      i=1;
      if(i==f) break;
    }
    mun[i] = mun[i-1==0?v[x].size():i-1]+v[x][i-2<0?v[x].size()-1:i-2];
  }
  for(int i=f-1;i!=f;i--)
  {
    if(i<1)
    {  i=v[x].size();
       if(i==f) break;
    }
    mun[i] = min(mun[i],mun[i+1>v[x].size()?1:i+1]+v[x][i-1<0?v[x].size()-1:i-1]);
  }
  for(int i=1;i<=v[x].size();i++)
    dis[x].pb(mun[i]);
  //memset(mun,0,sizeof(mun));
  mun[s]=0;
  for(int i=s+1;i!=s;i++)
  {
    if(i>v[x].size())
    {
      i=1;
      if(i==s) break;
    }
    mun[i] = mun[i-1==0?v[x].size():i-1]+v[x][i-2<0?v[x].size()-1:i-2];
  }
  //cout << mun[1] << " " << mun[2] << mun[3] << " hu " << endl;
  for(int i=s-1;i!=s;i--)
  {
    if(i<1)
    {  i=v[x].size();
       if(i==s) break;
    }
    mun[i] = min(mun[i],mun[i+1>v[x].size()?1:i+1]+v[x][i-1<0?v[x].size()-1:i-1]);
  } 
  for(int i=1;i<=v[x].size();i++)
    dis1[x].pb(mun[i]);
  //cout << endl;   */
}   

int main()
{
  sync;
  int t,m,a,b,w;
  cin >> t;
  while(t--)
  {
    cin >> n >> q;
    for(int i=1;i<=n;i++)
    {
       cin >> m;
       for(int j=0;j<m;j++)
       {
         if(m==1)
         {
           cin >> a;
           v[i].pb(0);
         }
         else
         cin >> a,v[i].pb(a);
       }
    }
    for(int i=1;i<=n;i++)
    {
      cin >> a >> b >> w;
      if(mark[i].first==-1)
        mark[i].first = a;
      else
        mark[i].SE = a;
      if(mark[i+1>n?1:i+1].first==-1)
        mark[i+1>n?1:i+1].first = b;
      else
        mark[i+1>n?1:i+1].SE = b;
      wt[i+1>n?1:i+1] = w;  
    }
    /*for(int i=1;i<=n;i++)
    {
      for(int j=0;j<v[i].size();j++)
        cout << v[i][j] << " ";
      cout << endl;
    }
    for(int i=1;i<=n;i++)
      cout << mark[i].FI << " " << mark[i].SE << endl;
    for(int i=1;i<=n;i++)
      cout << wt[i] << " " ;
    cout << endl;*/
    /*for(int i=1;i<=n;i++)
      cout << mark[i].FI << " " << mark[i].SE << endl;*/
    //cout << endl; 
    for(int i=1;i<=n;i++)
    {
      solve(i);
    }
    int curdist = 0;
    for(int i=1;i<=n;i++)
    {
      if(i==1){clock1[i]=0;continue;}
      curdist += wt[i];
      clock1[i] = curdist;
      curdist += dis[i][mark[i].SE];
    }
    curdist=0;
    anti[1]=0;
    anti[n] = wt[1];
    curdist = wt[1];
    for(int i=n-1;i>1;i--)
    {
      curdist += dis1[i+1][mark[i+1].FI];
      curdist += wt[i+1];
      anti[i] = curdist;
      
    }
    /*for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=v[i].size();j++)
        cout << dis[i][j] << " ";
      cout << endl;
    }
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=v[i].size();j++)
        cout << dis1[i][j] << " ";
      cout << endl;
    }
    /*for(int i=1;i<=n;i++)
      cout << clock1[i] << " ";
    cout << endl;
    for(int i=1;i<=n;i++)
      cout << anti[i] << " ";
    cout << endl;*/
    for(int i=0;i<q;i++)
    {
      int v1,c1,v2,c2;
      cin >> v1 >> c1 >> v2 >> c2;
      if(c1>c2)
       swap(c1,c2),swap(v1,v2);
      if(c1!=1)
      {
       int ans1 = clock1[c2]-(clock1[c1]+dis[c1][mark[c1].SE])+min(dis1[c1][v1],dis1[c1][mark[c1].FI]+dis[c1][v1])+min(dis[c2][v2],dis[c2][mark[c2].SE]+dis1[c2][v2]);
       
       int ans2 = clock1[c1]+min(dis[c1][v1],dis[c1][mark[c1].SE]+dis1[c1][v1])+dis[1][mark[1].SE]+anti[c2]+min(dis1[c2][v2],dis1[c2][mark[c2].FI]+dis[c2][v2]);
       
       cout << min(ans1,ans2) << endl;
      }
      else
      {
        int ans1 = clock1[c2]+dis[c2][v2]+dis[1][v1];
        int ans2 = dis1[1][v1]+anti[c2]+dis1[c2][v2];
        cout << min(ans1,ans2) << endl;  
      } 
    }
    init();
  }
}

