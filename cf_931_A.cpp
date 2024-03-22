#include <bits/stdc++.h>
#define LL long long
#define pii pair<i64, i64>
using namespace std;
const LL N = 1e6 + 5;
//#define MII multimap<i64, i64>
//#define MSI multimap<string, i64>
//#define SI multiset<i64>
//#define VI vector<i64>
using namespace std;
LL n;
LL nums[N];
void solve(){
    scanf("%lld",&n);
    LL max1 = -N,max2 = -N,min1 = N,min2 = N;
    for(int i = 0;i < n;i++) {
        scanf("%lld",&nums[i]);
        if(nums[i] > max1) {
            max2 = max(max1,max2);
            max1 = nums[i];
        }
        else if(nums[i] > max2) max2 = nums[i];
        if(nums[i] < min1) {
            min2 = min(min1,min2);
            min1 = nums[i];
        }
        else if(nums[i] < min2) min2 = nums[i];
    }
    LL ans = max1 - min1 + max1 - min2 + max2 - min2 + max2 - min1;
    printf("%lld\n",ans);
}
int main()
{
	LL _ = 1;
	scanf("%lld", &_); getchar();
	for(LL __ = 0; __ < _; __++) {
		solve();
	}
	system("pause");
	return 0;
}
