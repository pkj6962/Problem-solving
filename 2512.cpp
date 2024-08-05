#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring> 

#define ll long long
#define MAX 987654321
#define MIN -987654321 

#define FOR(n) for(int i = 0; i < n; i++)
#define FOR2(n) for(int j = 0; j < n; j ++)

using namespace std; 

void solve()
{
    int n; cin >> n; 
    vector<ll> arr(n); 
    ll max = MIN, M; 
    FOR(n)
    {
        cin >> arr[i]; 
        if (arr[i] > max)
            max = arr[i]; 
    }
    cin >> M; 
    ll l = 0, r = max, mid; 
    while(l<=r)
    {
        mid = (l + r)/2; 
        ll sum = 0; 
        FOR(n)
        {
            if (arr[i] < mid)
                sum += arr[i]; 
            else
                sum += mid; 
        }
        if (sum > M)
            r = mid-1; 
        else
            l = mid+1; 
        // printf("%lld %lld %lld\n", sum, M, mid); 
    }
    cout << l-1;
    return; 
}

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false); 
    solve(); 
    return 0; 
}