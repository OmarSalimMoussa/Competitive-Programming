#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define over LONG_LONG_MAX
ll inf = 1LL << 60;
ll mod = 1000000007;
double pi = acos(-1.0);

using namespace std;

ll a[2010][2010];
ll l[4010], r[4010];

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  for(int i=0 ; i<n ; i++){
    for(int j=0 ; j<n ; j++){
      cin >> a[i][j];
    }
  }
  int cnt = 0;
  for(int i=n-1 ; i>=0 ; i--){
    int x = i;
    int y = 0;
    while(y<n && x<n) r[cnt] += a[x++][y++];
    cnt++;
  }
  for(int j=1 ; j<n ; j++){
    int x = 0;
    int y = j;
    while(y<n && x<n) r[cnt] += a[x++][y++];
    cnt++;
  }
  cnt = 0;
  for(int i=n-1 ; i>=0 ; i--){
    int x = i;
    int y = n-1;
    while(y>=0 && x<n) l[cnt] += a[x++][y--];
    cnt++;
  }
  for(int j=n-2 ; j>=0 ; j--){
    int x = 0;
    int y = j;
    while(y>=0 && x<n) l[cnt] += a[x++][y--];
    cnt++;
  }

  ll zbr = -1, hxa = -1;
  int x1, y1, x2, y2;
  for(int i=0 ; i<n ; i+=1){
    for(int j=i%2 ; j<n ; j+=2){
      int o,p;
      o = n-1-i+j;
      p = 2*(n-1)-i-j;
      if(zbr < r[o] + l[p] - a[i][j]){
        zbr = r[o] + l[p] - a[i][j];
        x1 = i, y1 = j;
      }
    }
  }
  for(int i=0 ; i<n ; i+=1){
    for(int j=1-i%2 ; j<n ; j+=2){
      int o,p;
      o = n-1-i+j;
      p = 2*(n-1)-i-j;
      if(hxa < r[o] + l[p] - a[i][j]){
        hxa = r[o] + l[p] - a[i][j];
        x2 = i, y2 = j;
      }
    }
  }
  cout << zbr + hxa << endl;
  cout << x1+1 << " " << y1+1 << " " << x2+1 << " " << y2+1;

  return 0;
}
