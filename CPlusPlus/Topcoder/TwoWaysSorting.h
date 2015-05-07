#include <string>
#include <vector>
using namespace std;

class TwoWaysSorting
{
public:
	TwoWaysSorting(){}
	string sortingMethod(vector<string> stringList){
		bool len = isLength(stringList);
		bool lex = isLex(stringList);

		if (lex && len)
			return "both";
		else if (lex && !len)
			return "lexicographically";
		else if (!lex && len)
			return "lengths";
		else
			return "none";
	}

private:
	bool isLength(vector<string> stringList) {
		int size = stringList.size();
		int curLen = 0;
		for (int i = 0; i < size; i++) {
			if (stringList[i].length() > curLen)
				curLen = stringList[i].length();
			else
				return false;
		}
		return true;
	}

	bool isLex(vector<string> stringList) {
		int size = stringList.size();
		for (int i = 0; i < size - 1; i++) {
			if (stringList[i] > stringList[i + 1])
				return false;
		}

		return true;
	}

};

