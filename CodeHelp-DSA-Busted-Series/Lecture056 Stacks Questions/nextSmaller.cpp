 #include<bits/stdc++.h>
 using namespace std;
 # define int long long int
 # define rep(i,a,b) for(int i=a;i<b;i++)
 # define vi vector<int> 
 # define vvi vector<vector<int>>
 # define pi pair<int,int>
 # define vpi vector<pair<int,int>>
 # define mii map<int,int> 
 # define pb push_back
 #define __mayuk ios_base::sync_with_stdio(false);cin.tie(NULL);
                        
                         



vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    
    for(int i=n-1; i>=0 ; i--) {
        int curr = arr[i];
        while(s.top() >= curr)
        {
            s.pop();
        }
        //ans is stack ka top
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

int32_t main(){
__mayuk;

return 0;
}