# Knuth-Morris-Pratt (KMP) Algorithm

## What is KMP?

KMP is a smart way to search for a pattern in a string. Instead of checking every position from scratch, it remembers what it has already matched, so it can skip unnecessary work.

## Overview (How LPS Works)

Imagine each character in the pattern has a "bro" to its left. When you reach a character, you ask your left bro:
"Hey, how much did you match so far?"
Your bro tells you the length of the match (the LPS value).
This helps you decide which character to try matching next.

- If your bro matched 3 characters, you know you should try matching the 4th character next.
- If the match fails, you ask your bro's bro (go further left) how much they matched, and so on, until you find a match or reach zero.

## Example

**String:** `aabaab`
**Pattern:** `aaba`

### LPS Table Example

| Index | 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   | 10  |
| ----- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Char  | a   | a   | b   | a   | #   | a   | a   | b   | a   | a   | b   |
| LPS   | 0   | 1   | 0   | 1   | 0   | 1   | 2   | 3   | 4   | 0   | 0   |

- LPS tells you how much of the pattern matches as both a prefix and a suffix up to that point.
- When matching, you use the LPS value to know which character to try next, instead of starting over.

## Step-by-Step

1. At each index, ask your left bro how much they matched (LPS value).
2. If your bro matched 3, you try matching the 4th character.
3. If it matches, increase LPS by 1 (your bro says "good job, keep going!").
4. If it doesn't match, ask your bro's bro how much they matched, and try again.
5. Repeat until you find a match or reach zero.

Suppose at index 9, your bro says "I matched 4!" So you check index 4. If the character doesn't match, ask your bro's bro (previous LPS value) and keep going.

This process continues until you find a match or LPS is zero.

## Time and Space Complexity

- **Time Complexity:** O(n + m), where n is the length of the string and m is the length of the pattern.
- **Space Complexity:** O(n + m)

### Complexity Analysis

- LPS increases gradually (always +1), but decreases can be abrupt (can be 0).
- The total increase is bounded by n, and the total decrease is also bounded by n.
- Thus, the total operations are at most 2n in the worst case.

## Summary

- KMP efficiently finds pattern matches in a string using the LPS array.
- It avoids redundant comparisons, making it faster than naive approaches.
- The algorithm is optimal for pattern matching with linear time complexity.
