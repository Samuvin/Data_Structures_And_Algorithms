class Solution {
public:

	const long long RADIX = 101;
	const long long MOD = 1e9 + 37;

	vector<long long> computeRollingHash(vector<int>& arr, int length) 
    {
		long long hash = 0;
		long long max_power = 1;
		for (int i = 0; i < length; i++) 
        {
			max_power = (max_power * RADIX) % MOD;
		}
		for (int i = 0; i < length; i++) 
        {
			hash = (hash * RADIX + arr[i]) % MOD;
		}
		vector<long long> hashValues;
		hashValues.push_back(hash);
		for (int i = 1; i <= (arr.size() - length); i++) 
        {
			hash = (hash * RADIX - arr[i - 1] * max_power + MOD) % MOD; 
			hash = (hash + arr[i + length - 1] + MOD) % MOD; 
			hashValues.push_back(hash);
		}
		return hashValues;
	}

	bool hasCommonSubarray(vector<int>& arrayA, vector<int>& arrayB, int length)
	{
		vector<long long> hashA = computeRollingHash(arrayA, length);
		vector<long long> hashB = computeRollingHash(arrayB, length);
		set<long long> hashSet(hashA.begin(), hashA.end());

		for (long long hashValue : hashB) 
        {
			if (hashSet.find(hashValue) != hashSet.end())
				return true;
		}

		return false;
	}

	int findLength(vector<int>& nums1, vector<int>& nums2)
	{
		int low = 1;
		int high = min(nums2.size(), nums1.size());
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (hasCommonSubarray(nums1, nums2, mid))
				low = mid + 1;
			else
				high = mid - 1;
		}
		return high;
	}
};
