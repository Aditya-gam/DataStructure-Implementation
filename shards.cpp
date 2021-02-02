
#include <bits/stdc++.h>
using namespace std;
int fun(vector<int> arr, int n, int x, int c)
{
    int prev = arr[0] ;
    int temp = 1 ;
    for(int i = 1; i < n; i++)
    {
        if(arr[i] - prev >= x)
        {
            temp++;
            prev = arr[i];
        }
        if(temp == c) 
            return 1; 
    }
    return 0 ;
}
int batShard(vector<int> arr, int n, int c)
{
    int start = 0 , end = arr[n - 1],max = -1 ;
    while(start < end)
    {
        int mid = (start + end) / 2 ;
        if(fun(arr, n, mid, c))
        {
            if(mid > max) 
            {
                max = mid ;
                start = mid + 1 ;
            }
         
        }
        else end = mid ;
    }
    return max ;
}
int main() {
      
    int n, c;
    cin >> n >> c;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    int ans = batShard(arr, n, c);
    cout << ans << endl;
      
	return 0;
}