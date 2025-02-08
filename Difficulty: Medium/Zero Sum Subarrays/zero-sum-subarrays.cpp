//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        // code here.
        
        int total=0;
        unordered_map<int,int> mpp;
        
        mpp[0]=1;int prefixSum=0;
        
        
        for(int i=0;i<arr.size();i++)
        {
            prefixSum+=arr[i];
            if(mpp.count(prefixSum))
            {
                total+=mpp[prefixSum];
                mpp[prefixSum]++;
            }
            else mpp[prefixSum]=1;
        }
        
        return total;
        
        
        
        
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        cout << ob.findSubarray(arr) << endl;
        cout << "~\n";
    }
}

// } Driver Code Ends