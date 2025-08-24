# Rabin-Karp Double Hashing Algorithm

## Example Walkthrough

**Given:**
- String: `abcdef`
- Pattern: `bcde`

## Step 1: Initial Hash Calculation

### String Hash (for substring "abcde")
```
stringHash = a*(26^4) + b*(26^3) + c*(26^2) + d*(26^1) + e*(26^0)
```

### Pattern Hash
```
patternHash = b*(26^4) + c*(26^3) + d*(26^2) + e*(26^1) + f*(26^0)
```

## Step 2: Rolling Hash - Sliding the Window

To move from substring "abcde" to "bcdef":

### Current Hash
```
stringHash = a*(26^4) + b*(26^3) + c*(26^2) + d*(26^1) + e*(26^0)
```

### Rolling Hash Process

1. **Remove first character (a)** and **add new character (f)**

2. **Multiply existing hash by base (26)**
   ```
   stringHash = (a*(26^4) + b*(26^3) + c*(26^2) + d*(26^1) + e*(26^0)) * 26
   ```
   This increases the polynomial power by 1:
   ```
   stringHash = a*(26^5) + b*(26^4) + c*(26^3) + d*(26^2) + e*(26^1)
   ```

3. **Remove the first character contribution**
   ```
   Remove: a*(26^len) where len = pattern length
   ```

4. **Add the new character**
   ```
   Add: f*(26^0)
   ```

## Hash Collision Management

### The Problem
- Hash values can become very large and cause integer overflow
- Large numbers are difficult to store and compare efficiently

### Solution: Modular Arithmetic

Use modulo operation with prime numbers to keep hash values manageable:

```
MOD1 = 1e9 + 7    // First prime modulo
MOD2 = 1e9 + 33   // Second prime modulo (if first collides)

RADIX1 = 26       // First base
RADIX2 = 27       // Second base
```

## Double Hashing Benefits

### Why Use Two Hash Functions?
- **Reduced Collision Probability**: Using two different hash functions reduces spurious hits by approximately `1e^-10`
- **Better Accuracy**: If both hash values match, the probability of false positive is significantly lower

### Hash Function Combinations
1. **Primary Hash**: `MOD1 = 1e9 + 7`, `RADIX1 = 26`
2. **Secondary Hash**: `MOD2 = 1e9 + 33`, `RADIX2 = 27`

### Collision Resolution Strategy
If collisions still occur:
1. Change the radix (e.g., from 27 to 28)
2. Change the modulo to the next prime number
3. Use additional hash functions if necessary

## Key Points
- **Single Hash**: Can still have spurious hits due to collisions
- **Double Hash**: Dramatically reduces false positives
- **Modular Arithmetic**: Essential for handling large hash values
- **Prime Modulos**: Help distribute hash values more uniformly
