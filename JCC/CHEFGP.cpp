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
  int t;
  cin >> t;
  while(t--)
  {
    string s;
    cin >> s;
    int a,b;
    cin >> a >> b;
    int cnta=0,cntb=0;
    for(int i=0;i<s.length();i++)
    {
      if(s[i]=='a')cnta++;
      if(s[i]=='b')cntb++;
    }
    int flag = 0;
    //cout << cnta <<cntb << endl;
    for(int i=0;i<s.length();)
    {
      if(cnta==0 || cntb==0)
        break;
      if(cnta==cntb)
      {
        //cout << flag << endl;
        if(flag==2||flag==0)
         cout << "ab";
        if(flag == 1)
         cout << "ba";
        i++;
        cnta--;
        cntb--;
        i++;
      }
      else if(cnta>cntb)
      {
        for(int j=0;j<a;j++)
        {
          cout <<"a";
          i++;
          cnta--;
          flag=1;
          if(cnta==cntb)
            break;
          
        }
        if(cnta!=cntb)
        {
          cout << "b";
          cntb--;
        }
      }
      else
      {
        for(int j=0;j<b;j++)
        {
          cout <<"b";
          i++;
          cntb--;flag=2;
          if(cnta==cntb)
            break;
          
        }
        if(cnta!=cntb)
        {
          cout << "a";
          cnta--;
        }
      }
      
    }
    int k=0;
    while(cnta!=0)
    {
      cout << "a";
      cnta--;
      if(cnta==0)
       break;
      k++;
      if(k==a)
      {
        cout << "*";
        k=0;
      }
    }
    k=0;
    while(cntb!=0)
    {
      cout << "b";
      cntb--;
      if(cntb==0)
       break;
      k++;
      if(k==b)
      {
        cout << "*";
        k=0;
      }
    }
    cout << endl;
  }
}

