#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	string s;
	cin >> s;

	auto st1 = stack<char>{};
	auto st2 = stack<char>{};

	for (const auto& x : s) {
		st1.push(x);
	}

	int m;
	cin >> m;
	while (0 < (m--)) {
		string x;
		cin >> x;

		if ("L" == x) {
			if (!st1.empty()) {
				const auto t = st1.top();
				st1.pop();
				st2.push(t);
			}
		}
		else if ("D" == x) {
			if (!st2.empty()) {
				const auto t = st2.top();
				st2.pop();
				st1.push(t);
			}
		}
		else if ("B" == x) {
			if (!st1.empty()) {
				st1.pop();
			}
		}
		else if ("P" == x) {
			string v;
			cin >> v;
			st1.push(v[0]);
		}
	}

	while (!st1.empty()) {
		const auto t = st1.top();
		st1.pop();
		st2.push(t);
	}

	while (!st2.empty()) {
		cout << st2.top();
		st2.pop();
	}

	return 0;
}