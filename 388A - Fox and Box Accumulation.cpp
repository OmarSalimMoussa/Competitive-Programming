#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define over LONG_LONG_MAX
ll inf = 1LL << 60;
ll mod = 1000000007;
double pi = acos(-1.0);

using namespace std;
int x[110];
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  for(int i=0 ; i<n ; i++) cin >> x[i];
  sort(x, x+n);
  vector<int> p;
  p.push_back(1);
  for(int i=1 ; i<n ; i++){
    bool in = true;
    for(int j=0 ; j<p.size() ; j++){
      if(x[i]>=p[j]){
        p[j]++;
        in = false;
        break;
      }
    }
    if(in)
      p.push_back(1);
  }
  cout << p.size();
  return 0;
}
