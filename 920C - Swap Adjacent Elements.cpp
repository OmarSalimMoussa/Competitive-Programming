#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define over LONG_LONG_MAX
ll inf = 1LL << 60;
ll mod = 1000000007;
double pi = acos(-1.0);

using namespace std;

int parent[200010];
int c[200010];
int a[200010];

int find(int x){
  if(x == parent[x]) return x;
  return parent[x] = find(parent[x]);
}
void unite(int x, int y){
  x = find(x);
  y = find(y);
  if(x == y) return;
  if(c[x]>c[y]){
    parent[y] = x;
    c[x]+=c[y];
  }
  else{
    parent[x] = y;
    c[y]+=c[x];
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  string s;
  cin >> n;
  for(int i=0 ; i<=n ; i++) parent[i] = i, c[i] = 1;

  for(int i=0 ; i<n ; i++) cin >> a[i];
  cin >> s;
  s+='0';
  for(int i=0 ; i<n ; i++){
    if(s[i] == '1'){
      unite(i, i+1);
    }
  }
  for(int i=0 ; i<n ; i++){
    if(find(i) != find(a[i]-1)){
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
