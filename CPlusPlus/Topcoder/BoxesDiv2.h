#include <vector>
#include <algorithm>
using namespace std;

class BoxesDiv2
{
public:
	BoxesDiv2(){}
	~BoxesDiv2(){}
	int findSize(vector <int> candyCounts) {
		/*
		* 盒子的大小必须是 2^i 中的一个值，相同糖果放在一个盒子里，此时求出该盒子的最小值
		*/
		vector<int> stand;
		int len = candyCounts.size();
		for (int i = 0; i < len; i++) {
			int tmp = 1;
			while (tmp < candyCounts[i])
				tmp <<= 1;
			stand.push_back(tmp);
		}
		
		while (stand.size() > 1) {
			sort(stand.begin(), stand.end());
			int tmp = 1;
			while (tmp < stand[0] + stand[1])
				tmp <<= 1;
			stand.push_back(tmp);
			stand.erase(stand.begin(), stand.begin() + 2);
		}

		return stand[0];
	}
private:

};

