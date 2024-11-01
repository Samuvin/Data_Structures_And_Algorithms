Structure: Form 1 - Level Choice Check Move


Forms -> Form decides state and transition 

   subset subsequence incremental building solution
   
   - - - - - - - | - - - - - 
                   i
                   it level

  _____ is going to filled based on some partital information that needs to be maintained so that we can decide what to do with the ith level 

  dp[level][____]  

In Form 1, the main idea is incremental building where each decision at index i depends on choices made previously 
(the previous "level"). Here’s how it’s structured for solving LIS:

State Definition:
The dp[level][last] represents the "best solution ending at the level index with last being the last chosen element."

In LIS, last could either represent:

The value of the last element picked in the subsequence.
The index of the last element picked (more efficient in some cases).

States:
  level: current index being evaluated.
  last: the value or index of the last element picked in the subsequence up to level.

Transition:
We have two choices at each level:
Pick the current element (Arr[level]) if it can continue the subsequence.
Not pick the current element and maintain the subsequence as is.

Transition Logic:

If we don’t pick Arr[level], then:
                                dp[level][last]=dp[level+1][last]
If we do pick Arr[level] (and Arr[level] > Arr[last] if last is an index or value check), then:

                                dp[level][Arr[level]]=dp[level+1][last]+1

This logic helps build the best possible subsequence either by extending the previous best subsequence ending at last or 
keeping the current one.

Example Walkthrough with Transition:
  For an array Arr = [3, 2, 5, 4, 5, 7, 8, 1, 11, 9]:
  We initialize dp[level][last] for all possible levels and values of last (either values or indices).
  For each level, we decide:

If we don’t pick Arr[level], maintain the previous best result ending with last.
If we pick Arr[level] (when it can continue the subsequence), we update dp[level][Arr[level]].

Complexity Analysis:

  Time Complexity:
      If last is the last picked value, O(N * max(Arr)).
      If last is the last picked index, O(N^2).
  Space Complexity:
    O(N * max(Arr)) or O(N^2) depending on how last is tracked.

Practical Application and Transition Insight
In this structure:

Incremental Building: 
    We incrementally decide to either include or exclude each element based on previous choices, preserving only the 
    best possible subsequences.

LIS Adaptation: For the LIS, this form is particularly adaptable as each choice relies on the previous “last picked” element, enabling us to maintain an efficient search for the longest subsequence ending at each position.
This approach suits problems where choices build incrementally on previous partial solutions, ensuring that each step evaluates the best possible decision given prior outcomes.
