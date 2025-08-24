#include <bits/stdc++.h>
using namespace std;

/*
Knuth-Morris-Pratt (KMP) algorithm

LPS = longest prefix which is also suffix

we need to check how much suffix of the pattern matches with the prefix of the text

string = aabaab
pattern = aaba
Example = aaba # aabaab

combined string

index  = 0  1  2  3  4  5  6  7  8  9  10
string = a  a  b  a  #  a  a  b  a  a  b
lps    = 0  1  0  1  0  1  2  3  4  0  0

lps acts as a index of the character that i need to match
lps indicates how much length is done and what index character i need to match

Step 1

Step 2
I am in index i i ask my left neighbour bro how much you matched,
if he says i match 3 character which means


Index = 0 1 2 3

then i say ok bro you matched 3 character which ideally means
you matched 0 1 2 index character i need to match the character with index 3

so ideally my bro says how much he matches and what is the character i want to match
if i match 4th character which ideally in 3rd index then just lps[i-1]+1

else
index  = 0  1  2  3  4  5  6  7  8  9  10
string = a  a  b  a  #  a  a  b  a  a  b
lps    = 0  1  0  1  0  1  2  3  4

in index 9

bro says i matched 4
so you check index 4

# != a

it is not matching

so bro says
i matched
a a b a

But next character you did not matched which is # and a so can you ask
with my left neighbour how much he matched because

a a b a
a a b a this cannot be continued
So check is there one more occurence of aaba which is prevInd-1
he ways
hi bro i am matching 1 which can you try matching next character

this process will go on

Time complextiy - O(n+m)
Space Complexity - O(n+m)

Time complexity:

the length will increase 1 (length increase gradually 1 (always +1))
but decrease can be any (it can be 0 as well)
decrease will happen aprubplty
if we increase gradualy in future
it decreaes apruptly

i go increase gradually
for decrease we can end up doing any number of 1

if we icreased to a point 4
then we can go down by 0
and then increase again happen gradually

decrease is bounded by increase
how much we increase that much we decrease

Total increase = n
Total decrease = n
total = 2n
worst case
*/

struct KMP
{
    vector<int> lps;

    // Build LPS array for given string
    void buildLPS(const string &s)
    {
        int len = s.size();
        int prevInd = 0;
        lps.assign(len, 0);
        for (int i = 1; i < len; i++)
        {
            prevInd = lps[i - 1];
            while (prevInd > 0 && s[prevInd] != s[i])
            {
                prevInd = lps[prevInd - 1];
            }
            lps[i] = prevInd + (s[i] == s[prevInd] ? 1 : 0);
        }
    }

    // Build "pattern#text"
    string buildCombinedString(const string &text, const string &pattern)
    {
        string combined;
        combined.reserve(pattern.size() + 1 + text.size());
        combined.append(pattern).push_back('#');
        combined.append(text);
        return combined;
    }

    // Return reference instead of copying
    const vector<int> &getLPS(string &str)
    {
        buildLPS(str);
        return lps;
    }

    // Convert combined index to text index
    int toPatternIndex(int combinedIdx, int patternLen)
    {
        return combinedIdx - 2 * patternLen;
    }

    // Return first match index (or -1)
    int findFirstMatch(const string &text, const string &pattern)
    {
        string combined = buildCombinedString(text, pattern);
        int m = pattern.size();

        buildLPS(combined);

        for (int i = m; i < combined.size(); i++)
        {
            if (lps[i] == m)
            {
                return toPatternIndex(i, m);
            }
        }
        return -1;
    }

    // Return all match indices
    vector<int> findAllMatches(const string &text, const string &pattern)
    {
        string combined = buildCombinedString(text, pattern);
        int m = pattern.size();

        buildLPS(combined);

        vector<int> matches;
        for (int i = m + 1; i < (int)combined.size(); i++)
        {
            if (lps[i] == m)
            {
                matches.push_back(toPatternIndex(i, m));
            }
        }
        return matches;
    }
} KMP;