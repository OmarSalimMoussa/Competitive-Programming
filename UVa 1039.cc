#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll inf = 1LL << 25;
ll mod = 1000000007;

using namespace std;

struct point{
  double x, y;
};

vector<point> bts, city;
vector<vector<int> > f;

int find_closest(double x, double y){
  double min_dist = 1e9;
  int id;
  for(int i=0 ; i<bts.size() ; i++){
    double dist = hypot(bts[i].x-x, bts[i].y-y);
    if(dist<min_dist){
      min_dist = dist;
      id = i;
    }
  }
  return id;
}

pair<double, double> get_coordinates(int s, int d, double p){
  double dx = city[d].x-city[s].x;
  double dy = city[d].y-city[s].y;
  double x = city[s].x + p*dx/100.0;
  double y = city[s].y + p*dy/100.0;
  return {x, y};
}

int process(int s, int d){
  int closest = find_closest(city[s].x, city[s].y);
  double lo = 0;
  int changes = 0;
  while(true){
    double hi = 100.0, mid;
    for(int e=0 ; e<50 ; e++){
      double x, y;
      mid = (lo+hi)/2.0;
      tie(x, y) = get_coordinates(s, d, mid);
      int new_closest = find_closest(x, y);
      if(new_closest != closest) hi = mid;
      else lo = mid;
    }
    if(fabs(mid-100.0)>1e-6){
      changes++;
      double x, y;
      tie(x, y) = get_coordinates(s, d, mid+1e-6);
      closest = find_closest(x, y);
    }
    else break;
  }
  return changes;
}

int main(){
  //freopen("in.in", "r", stdin);//freopen("out.out", "w", stdout);
  int B, C, R, Q, tc = 1;
  while(scanf("%d%d%d%d", &B, &C, &R, &Q) && (B || C || R || Q)){
    bts.clear();
    bts.resize(B);
    city.clear();
    city.resize(C);
    f.assign(C, vector<int>(C, inf));
    for(int i=0 ; i<B ; i++){
      scanf("%f%f", &bts[i].x, &bts[i].y);
    }
    for(int i=0 ; i<C ; i++){
      scanf("%f%f", &city[i].x, &city[i].y);
      f[i][i] = 0;
    }
    for(int i=0 ; i<R ; i++){
      int u, v;
      scanf("%d%d", &u, &v);
      u--, v--;
      f[u][v] = f[v][u] = process(u, v);
    }
    for(int k=0 ; k<C ; k++){
      for(int i=0 ; i<C ; i++){
        for(int j=0 ; j<C ; j++){
          f[i][j] = min(f[i][j], f[i][k]+f[k][j]);
        }
      }
    }
    printf("Case %d:\n", tc++);
    for(int q=0 ; q<Q ; q++){
      int s, d;
      scanf("%d%d", &s, &d);
      s--, d--;
      f[s][d] < inf? printf("%d\n", f[s][d]):puts("Impossible");
    }
  }
  return 0;
}
