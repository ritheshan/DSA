#include <bits/stdc++.h>
using namespace std;

int findminmax(vector<int>& arr, int dist, int cntcow) {
    int last = arr[0];  
    cntcow--;  

    for (int i = 1; i < arr.size(); i++) {
        if ((arr[i] - last) >= dist) { 
            last = arr[i];
            cntcow--;
            if (cntcow == 0) return true;  
        }
    }
    return false;  
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, c;
        cin >> n >> c;
        vector<int> stalls(n);
        
        for (int i = 0; i < n; i++) cin >> stalls[i];

        sort(stalls.begin(), stalls.end()); 
        
        int low = 1, high = stalls[n - 1] - stalls[0], ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (findminmax(stalls, mid, c)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}