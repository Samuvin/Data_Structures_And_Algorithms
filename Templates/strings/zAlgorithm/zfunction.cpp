#include <bits/stdc++.h>
using namespace std;

struct ZAlgorithm
{
    vector<int> zFunc;

    // Build the Z-function for the given string
    void buildZFunction(const string &str)
    {
        int strLen = str.size();
        zFunc.assign(strLen, 0);

        int leftBox = 0;
        int rightBox = 0;
        for (int i = 1; i < strLen; i++)
        {
            // If i is inside the current Z-box, use previously computed values
            if (i < rightBox)
            {
                // Handle case of z[i] reaching character beyond what we have seen at r
                // z[i] can be at most the remaining length of the Z-box
                // or the corresponding value inside the Z-box
                zFunc[i] = min(rightBox - i, zFunc[i - leftBox]);
            }

            // Try to extend the Z-box beyond the current right boundary
            while (zFunc[i] + i < strLen && str[zFunc[i] + i] == str[zFunc[i]])
            {
                zFunc[i]++;
            }

            // Update the Z-box boundaries if it extended past the current rightBox
            if (i + zFunc[i] > rightBox)
            {
                leftBox = i;
                rightBox = i + zFunc[i];
            }
        }
    }

    vector<int> &getZfunc(const string &str)
    {
        buildZFunction(str);
        return zFunc;
    }

    string getCombinedString(const string &str, const string &pat)
    {
        return pat + '#' + str;
    }

    int getPatternIndex(int combinedIndex, int patLen)
    {
        return combinedIndex - patLen - 1;
    }

    int getFirstOccurrence(const string &str, const string &pat)
    {
        string combineString = getCombinedString(str, pat);
        int strLen = str.size();
        int patLen = pat.size();
        int combineStringLen = combineString.size();

        vector<int> z = getZfunc(combineString);
        for (int i = patLen; i < combineStringLen; i++)
        {
            if (z[i] == patLen)
            {
                return getPatternIndex(i, patLen);
            }
        }
        return -1;
    }

    vector<int> getAllOccurences(const string &str, const string &pat)
    {
        string combineString = getCombinedString(str, pat);
        int strLen = str.size();
        int patLen = pat.size();
        int combineStringLen = combineString.size();

        vector<int> patternOccurences;
        vector<int> z = getZfunc(combineString);
        for (int i = patLen; i < combineStringLen; i++)
        {
            if (z[i] == patLen)
            {
                patternOccurences.push_back(getPatternIndex(i, patLen));
            }
        }
        return patternOccurences;
    }

} zAlgo;