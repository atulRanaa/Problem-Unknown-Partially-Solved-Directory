#include<bits/stdc++.h>
using namespace std;


int D[105];
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
     int n, m;
     cin >> n >> m;
     for (int i = 0; i < m; ++i)
    {
       int z = -1, t = 0;
     for (int j = 0; j < n; ++j)
     {
      
      int g;
      cin >> g;
      if(z < g)
        z = g, t = j;
    }
    D[t]++;
  }
  int res = 0;
  for (int i = 0; i < n; ++i)
  {
    if(D[res] < D[i])
      res = i;
  }
  cout << res + 1;
return 0;
}