//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(int n, int arr[]) {
        // Code here
        
           vector<int> leadersList;
        int maxFromRight = arr[n - 1];
        
        // The rightmost element is always a leader
        leadersList.push_back(maxFromRight);
        
        // Traverse the array from the second last element to the first
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] >= maxFromRight) {
                maxFromRight = arr[i];
                leadersList.push_back(maxFromRight);
            }
        }
        
        // The list is in reverse order, so we reverse it to maintain the correct order
        reverse(leadersList.begin(), leadersList.end());
        return leadersList;
    }
        
        
        
        
    
};

//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t; // testcases
    while (t--) {
        long long n;
        cin >> n; // total size of array

        int arr[n];

        // inserting elements in the array
        for (long long i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution obj;
        // calling leaders() function
        vector<int> v = obj.leaders(n, arr);

        // printing elements of the vector
        for (auto it = v.begin(); it != v.end(); it++) {
            cout << *it << " ";
        }

        cout << endl;
    }
}

// } Driver Code Ends