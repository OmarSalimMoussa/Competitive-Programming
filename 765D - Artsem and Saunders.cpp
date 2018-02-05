#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define over LONG_LONG_MAX

const ll inf = 1LL << 60;

using namespace std;

int m, n, f[100010], g[100010], h[100010];

int main(){
  scanf("%i",&n);
  for(int i=1 ; i<=n ; i++){
    scanf("%i",&f[i]);
  }
  for(int i=1 ; i<=n ; i++){
    if(g[i]!=0 && g[f[i]] != g[i]){cout << -1; return 0;}
    else if(g[f[i]] != 0){
      g[i] = g[f[i]];
    }
    else{
      m++;
      g[i] = g[f[i]] = m;
    }
    if(h[g[i]] != 0 && h[g[i]]!=f[i]){cout << -1; return 0;}
    h[g[i]] = f[i];
  }
  printf("%i\n",m);
  for(int i=1 ; i<=n ; i++){
    printf("%i ",g[i]);
  }
  printf("\n");
  for(int i=1 ; i<=m ; i++){
    printf("%i ",h[i]);
  }
  return 0;
}
