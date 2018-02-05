#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define over LONG_LONG_MAX
ll inf = 1LL << 60;
ll mod = 1000000007;
double pi = acos(-1.0);

using namespace std;

char g[60][60];
int seen[60][60][2][4];
int s[60][60];
int in,n,m;

void check(int x, int y, int c, int dir){
  if(seen[x][y][c][dir] || g[x][y] == 'W') return;
  seen[x][y][c][dir]++;
  if(s[x][y] == 0) in++;
  s[x][y] = 1;
  if(dir == 0){
    if(x) check(x-1,y,c,dir);
    if(!c && y) check(x,y-1,c+1,2);
    if(!c && y<m-1) check(x,y+1,c+1,3);
  }
  if(dir == 1){
    if(x<n-1) check(x+1,y,c,dir);
    if(!c && y) check(x,y-1,c+1,2);
    if(!c && y<m-1) check(x,y+1,c+1,3);
  }
  if(dir == 2){
    if(y) check(x,y-1,c,dir);
    if(!c && x) check(x-1,y,c+1,0);
    if(!c && x<n-1) check(x+1,y,c+1,1);
  }
  if(dir == 3){
    if(y<m-1) check(x,y+1,c,dir);
    if(!c && x) check(x-1,y,c+1,0);
    if(!c && x<n-1) check(x+1,y,c+1,1);
  }
}
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  int cnt = 0, x, y;
  for(int i=0 ; i<n ; i++){
    for(int j=0 ; j<m ; j++){
      cin >> g[i][j];
      if(g[i][j] == 'B') cnt++;
    }
  }
  for(int i=0 ; i<n ; i++){
    for(int j=0 ; j<m ; j++){
      if(g[i][j] == 'B'){
        in = 0;
        memset(s,0,sizeof(s));
        memset(seen,0,sizeof(seen));
        check(i,j,0,0);
        check(i,j,0,1);
        check(i,j,0,2);
        check(i,j,0,3);
        if(in != cnt){
          cout << "NO";
          return 0;
        }
      }
    }
  }
  cout << "YES";
  return 0;
}
