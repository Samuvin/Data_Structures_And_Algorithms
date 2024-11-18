#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
using ll = long long;


void Sweap_Line(vector<pair<ll, ll>>& points)
{
	int len = points.size();
	vector<pair<ll, ll>> events;
	for (int i = 0; i < len; i++)
	{
		events.push_back({points[i].first, +1});
		events.push_back({points[i].second, -1});
	}
	sort(events.begin(), events.end());

	ll lenCovered[len + 1];
	memset(lenCovered, 0, sizeof(lenCovered));
	int cnt = 0;

	for (int i = 0; i < events.size(); i++)
	{
		int j = i;
		while (j < events.size() && events[j].first == events[i].first)
		{
			cnt += events[j].second;
			j++;
		}
		if (j < events.size())
		{
			ll segLen = events[j].first - events[i].first;
			lenCovered[cnt] += segLen;
		}
		i = j - 1;
	}

	for (int i = len - 1; i >= 1; i--)
		lenCovered[i] += lenCovered[i + 1];
	for (int i = 1; i <= len; i++)
		cout << lenCovered[i] << " ";
}


int main()
{
	int n;
	cin >> n;
	vector<pair<ll, ll>>points(n);
	for (int i = 0; i < n; i++)
	{
		cin >> points[i].first >> points[i].second;
	}
	Sweap_Line(points);
}
