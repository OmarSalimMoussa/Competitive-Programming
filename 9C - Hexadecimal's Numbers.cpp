#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define over LONG_LONG_MAX
ll inf = 1LL << 60;
ll mod = 1000000007;
double pi = acos(-1.0);

using namespace std;
vector<ll> num;

void gen(int pos, ll acc){
  if(pos == 10) num.push_back(acc);
  else gen(pos+1, acc*10), gen(pos+1, acc*10+1);
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  ll n;
  cin >> n;
  gen(0, 0);
  sort(num.begin(), num.end());
  int ans = 0;
  for(int i=1 ; i<num.size() ; i++){
    if(n>=num[i]) ans++;
  }
  cout << ans;
  return 0;
}
