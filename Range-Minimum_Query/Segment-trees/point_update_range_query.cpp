#include<iostream>
#include<climits>
#define ll long long
using namespace std;

ll conquer(ll a, ll b)
{
	return min(a, b);
}
ll surrend()
{
	return INT_MAX;
}
ll rc(ll parent)
{
	return 2 * parent + 2;
}
ll lc(ll parent)
{
	return 2 * parent + 1;
}
void build_tree(ll *tree, ll node, ll low , ll high, ll *arr)
{
	if (low == high)
	{
		tree[node] = arr[low];
		return;
	}
	ll mid = (low + high) / 2;
	ll left_child = lc(node);
	ll right_child = rc(node);
	build_tree(tree, left_child, low, mid, arr);
	build_tree(tree, right_child, mid + 1, high, arr);
	tree[node] = conquer(tree[left_child], tree[right_child]);
}

void point_update(ll *tree, ll node, ll low, ll high, ll point, ll val)
{
	if (low == high)
	{
		tree[node] = val;
		return;
	}
	else
	{
		ll mid = (low + high) / 2;
		if (mid >= point)
			point_update(tree, lc(node), low, mid, point, val);
		else
			point_update(tree, rc(node), mid + 1, high, point, val);
		tree[node] = conquer(tree[lc(node)], tree[rc(node)]);
	}
}

ll Query_Tree(ll * tree, ll node, ll low, ll high, ll l, ll r)
{
	if (low >= l && high <= r)
		return tree[node];
	if (low > r || high < l)
		return surrend();
	ll mid = (low + high) / 2;
	ll left_child = lc(node);
	ll right_child = rc(node);
	ll left = Query_Tree(tree, left_child, low, mid, l, r);
	ll right = Query_Tree(tree, right_child, mid + 1, high, l, r);
	return conquer(left, right);
}
ll query(ll * tree , ll * arr, ll l , ll r, ll n)
{
	return Query_Tree(tree, 0, 0, n - 1, l, r);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	ll arr[n] {0};
	ll tree[4 * n] {0};
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	build_tree(tree, 0, 0, n - 1, arr);
	while (m--)
	{
		ll k, l, r;
		cin >> k >> l >> r;
		if (k == 1)
		{
			point_update(tree, 0, 0, n - 1, l - 1, r);
		}
		else
		{
			cout << query(tree, arr, l - 1, r - 1, n) << "\n";
		}
	}
}
