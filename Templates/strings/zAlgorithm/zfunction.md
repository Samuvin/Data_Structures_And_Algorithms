# Z Algorithm - Optimized String Matching

## What is Z Algorithm?

Z Algorithm is an optimization of the brute force string matching algorithm. It creates a Z array that helps us find patterns efficiently by reusing previously calculated information.

## The Core Concept

The Z algorithm says: "Bro, you need to calculate a Z array!" The rule is simple:
**Find the longest substring starting from each position that matches the prefix starting from index 0.**

## Example Walkthrough

**String:** `abcdabcabc`

| Index  | 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   |
| ------ | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| String | a   | b   | c   | d   | a   | b   | c   | a   | b   | c   |
| Z      | 0   | 0   | 0   | 0   | 3   | 0   | 0   | 3   | 0   | 0   |

**What do these Z values mean?**

- Position 0: Always 0 (we don't compare with itself)
- Position 1: 0 (letter 'b' doesn't match 'a' at the start)
- Position 2: 0 (letter 'c' doesn't match 'a' at the start)
- Position 3: 0 (letter 'd' doesn't match 'a' at the start)
- Position 4: 3 (letters 'abc' match the first 3 letters 'abc')
- Position 5: 0 (letter 'b' doesn't match 'a' at the start)
- And so on...

## Naive vs Optimized Approach

### Naive Search (O(n²))

For each index i, start matching the longest prefix from index 0. Repeat for every index.

### Optimized Search (O(n))

Create a **Z-box** concept!
When we match at index 4 (matching 3 characters), we know indices 4-6 match with indices 0-2.

When calculating index 5, the Z algorithm says: "Bro, wait! Your left neighbor already matched some characters. Copy-paste that value!"

## The Z-Box Concept

Always use a box for which we have already calculated values and reuse them:

- For index 4: we calculated and matched 3 characters
- For indices 5 and 6: we don't need to match again, just reuse!
- Same for indices 7-9: already calculated, use the values

**Example:** When we found that position 4 matches 3 characters with the beginning (abc), we know:

- Position 4 = 'a' (matches position 0)
- Position 5 = 'b' (matches position 1)
- Position 6 = 'c' (matches position 2)

### Key Rule

- If we reach index i and the value is **not calculated**: brute force it
- If we reach index i and the value is **calculated**: continue from there or use the same value

## The Z-Box Formula

When inside a previously calculated range:

```
l = left boundary, r = right boundary, i = current index
z[i] = z[i - l]  // Copy from the corresponding position
```

### Important Constraint

The answer should never go beyond the current boundary:

```
z[i] = min(z[i - l], r - i)
```

## Why This Constraint?

**Example:** String = `aaabcde`

| Index  | 0   | 1   | 2   | 3   | 4   | 5   | 6   |
| ------ | --- | --- | --- | --- | --- | --- | --- |
| String | a   | a   | a   | b   | c   | d   | e   |
| Z      | 0   | 2   | ?   |     |     |     |     |

When calculating index 2:

- l = 1, r = 2 (inside the range)
- z[2-1] = z[1] = 2
- But this is wrong! "aa" ≠ "ab"
- This fails because at index 1, we only reached till index 2, not 3
- We're including a character we haven't seen yet

**Solution:** z[i] should never go beyond current r

```
z[i] = min(z[i-l], r-i)
```

## Pattern Matching with Z Algorithm

**Pattern:** `aba`
**String:** `ababadaba`
**Combined:** `aba#ababadaba`

| Index  | 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   | 10  | 11  | 12  |
| ------ | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| String | a   | b   | a   | #   | a   | b   | a   | b   | a   | d   | a   | b   | a   |
| Z      | 0   | 0   | 1   | 0   | 3   | 0   | 3   | 0   | 1   | 0   | 3   | 0   | 0   |

**Pattern found at:** positions where Z[i] = pattern_length (3)

- Position 4: Z[4] = 3 ✓
- Position 6: Z[6] = 3 ✓
- Position 10: Z[10] = 3 ✓

## Algorithm Steps

1. **Create combined string:** pattern + '#' + text
2. **Calculate Z array** using the optimized approach
3. **Find matches:** wherever Z[i] equals pattern length
4. **Use Z-box optimization** to avoid redundant calculations

## Time Complexity

- **Time:** O(n + m) where n = text length, m = pattern length
- **Space:** O(n + m) for the Z array
- **Key advantage:** Linear time due to Z-box reuse strategy

## Summary

The Z algorithm is like having a smart "bro system" that remembers what you've already calculated and helps you skip redundant work. It's perfect for pattern matching and much faster than naive approaches!
