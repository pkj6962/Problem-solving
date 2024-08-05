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

vector <ll> arr(100000); 
int n, M; 
ll binary_search(ll l, ll r)
{
    ll mid = (l + r)/2; 
    ll sum = 0; 
    ll new_l=l, new_r=r; 

    if (l > r)
        return l-1; 
    FOR(n)
    {
        if (mid < arr[i])
            sum += mid; 
        else
            sum += arr[i]; 
    }
    if (sum <= M)
        new_l = mid + 1; 
    else
        new_r = mid - 1; 

    return binary_search(new_l, new_r);
}


void solve()
{
    cin >> n; 
    ll max = MIN; 
    FOR(n)
    {
        cin >> arr[i]; 
        if(max < arr[i])
        {
            max = arr[i]; 
        }
    }
    cin >> M;
    ll ans = binary_search(0, max); 
    cout << ans; 
    return; 
}

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false); 
    solve(); 
    return 0; 
}