#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;  // Total number of days
vector<vector<int>> vacation;  // 2D vector to store scores for each activity per day
vector<vector<int>> dp;  // DP table for memoization and tabulation approaches

/*
Problem Overview:
   - Given a vacation plan spanning 'N' days, where each day has 3 activities.
   - Each activity has a score that can be earned by choosing that activity on that day.
   - Objective: Maximize the score over all days with the constraint that no activity should be repeated on consecutive days.
   - Solution uses dynamic programming with different approaches: Memoization, Tabulation, and Space Optimization.

Time Complexity (Memoization):
   Tc: #States (S) = N, #Choices (T) = 3 => O(N * M), where M = 3 (number of activities per day)
Space Complexity (Memoization):
   Sc: O(N * M) for the DP table + O(N) for recursion stack space
*/

int memo(int level, int prev) {
    /*
    Recursively computes the maximum score from [level...N-1] days,
    given that the activity chosen on the previous day was 'prev'.
    
    Parameters:
        - level: The current day
        - prev: The activity chosen on the previous day (-1 if none chosen initially)
        
    Returns:
        - Maximum achievable score from day 'level' to day 'N-1'
    */

    // Pruning: If we've reached beyond the last day, return 0 as no more scores can be added
    if (level >= N)
        return 0;

    // Cache Check: Return the cached answer if it's already computed
    int &ans = dp[level][prev + 1];  // Offset by +1 to allow 'prev = -1' index
    if (ans != -1)
        return ans;

    // Compute: Try each activity (0, 1, 2) and select the one that yields max score
    for (int Choice = 0; Choice < 3; Choice++) {
        if (Choice != prev) {  // Ensure no consecutive days have the same activity
            ans = max(ans, memo(level + 1, Choice) + vacation[level][Choice]);
        }
    }

    // Save and return the computed answer
    return ans;
}

/*
Tabulation Approach:
   - Bottom-up approach to fill the dp table iteratively.
   - Each day has a row with 3 columns representing the maximum score if a specific activity is chosen on that day.
   
Time Complexity: O(N)
Space Complexity: O(N * 3) for dp table
*/

int Tabulation() {
    // Initialize the first day's scores directly
    dp[0][0] = vacation[0][0];
    dp[0][1] = vacation[0][1];
    dp[0][2] = vacation[0][2];

    // Fill the dp table from day 1 to day N-1
    for (int i = 1; i < N; i++) {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + vacation[i][0];  // Choosing activity 0
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + vacation[i][1];  // Choosing activity 1
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + vacation[i][2];  // Choosing activity 2
    }

    // Return the maximum score from the last day (N-1) across all activities
    return max({dp[N - 1][0], dp[N - 1][1], dp[N - 1][2]});
}

/*
Space Optimized Tabulation Approach:
   - Optimizes space complexity by only keeping track of the last day's scores in a single dp vector.
   
Time Complexity: O(N)
Space Complexity: O(3) for the dp vector (constant space)
*/

int Space_Optimized() {
    vector<int> dp(3, 0);  // Initialize dp vector for first day scores
    dp[0] = vacation[0][0];
    dp[1] = vacation[0][1];
    dp[2] = vacation[0][2];

    // Iterate through each day and compute scores using only two vectors (dp and curr)
    for (int i = 1; i < N; i++) {
        vector<int> curr(3, 0);  // Temporary vector for current day
        curr[0] = max(dp[1], dp[2]) + vacation[i][0];  // Choosing activity 0
        curr[1] = max(dp[0], dp[2]) + vacation[i][1];  // Choosing activity 1
        curr[2] = max(dp[0], dp[1]) + vacation[i][2];  // Choosing activity 2
        dp = curr;  // Update dp with current day's values
    }

    // Return the maximum score on the last day
    return max({dp[0], dp[1], dp[2]});
}

int main() {
    // Input the number of days
    cin >> N;

    // Input the vacation scores for each day and each activity
    vacation = vector<vector<int>>(N, vector<int>(3, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> vacation[i][j];
        }
    }

    // Memoization approach
    // dp = vector<vector<int>>(N, vector<int>(4, -1));  // Initialize DP table with -1
    // cout << memo(0, -1);  // Start recursion from day 0 with no previous activity

    // Tabulation approach
    // dp = vector<vector<int>>(N, vector<int>(3, 0));  // Initialize DP table for tabulation
    // cout << Tabulation();

    // Space Optimized Tabulation approach
    cout << Space_Optimized();
}
