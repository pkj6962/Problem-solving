#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> 

#define ll long long
#define MAX 987654321
#define MIN -987654321 

#define FOR(n) for(int i = 0; i < n; i++)
#define FOR2(n) for(int j = 0; j < n; j ++)

using namespace std; 

int ceiling(double x)
{
    return (x - (int)x == 0)? x : (int)x + 1; 
}


void solve()
{
    ll x, y; 
    int z1; 
    cin >> x >> y; 
    z1 =  y * 100 / x; 

    if (z1 >= 99)
    {
        cout << -1; 
        return; 
    }
    // ll l = 0, r = x, mid = (l + r)/2; 
    ll l = 0, r = x, mid = ceiling(((double)l + r)/2); 
    int z2; 
    while (l <= r)
    {
        z2 = (y+mid)*100/(x+mid);
        // printf("%d %d %lld %lld %lld\n", z1, z2, l,r, mid); 
        if (z1 != z2)
        {
            r = mid - 1; 
        }
        else{
            l = mid + 1; 
        }
        mid = ceiling(((double)r+l)/2); 
    }
    cout << r+1; 
    return; 
}
void test()
{


}

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false); 
    solve(); 
    // test(); 
    return 0; 
}