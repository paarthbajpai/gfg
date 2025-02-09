//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
     unordered_map<int, int> m;  // To store the prefix sums
    m[0] = -1;  // Base case for subarrays starting from index 0
    int prefixsum = 0;  // Running sum
    int maxLen = 0;  // To track the longest length

    for (int i = 0; i < arr.size(); i++) {
        prefixsum += arr[i];  // Calculate prefix sum up to current index

        // Check if (prefixsum - k) exists in the map
        if (m.count(prefixsum - k)) {
            // Calculate length of the subarray
            int len = i - m[prefixsum - k];
            maxLen = max(maxLen, len);  // Update the max length
        }

        // Store the first occurrence of the prefix sum
        if (m.count(prefixsum) == 0) {
            m[prefixsum] = i;
        }
    }

    return maxLen;  // Return the longest length found
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends