#include <vector>
#include <string>
using namespace std;

class BinaryCode
{
public:
	BinaryCode(){}
	~BinaryCode(){}
	vector <string> decode(string message) {
		vector <string> vs;
		string dec1, dec2;
		dec1 = reverge(message, '0');
		dec2 = reverge(message, '1');
		vs.push_back(dec1);
		vs.push_back(dec2);

		return vs;
	}

	string reverge(const string &message, char mode) {
		string dec;
		int tmp;
		dec = message;
		dec[0] = mode;
		
		tmp = mi(message[0], dec[0]);
		if (!test(tmp)) {
			return "NONE";
		}
		dec[1] = '0' + tmp;

		for (int i = 1; i < message.size() - 2; i++) {
			tmp = mi(message[i], dec[i], dec[i - 1]);
			if (!test(tmp)) {
				return "NONE";
			}
			dec[i + 1] = '0' + tmp;
		}

		tmp = mi(message[message.size() - 1], dec[message.size() - 2]);
		if (!test(tmp)) {
			return "NONE";
		}
		dec[message.size() - 1] = '0' + tmp;

		return dec;
	}

	int mi(int a, int b, int c = '0') {
		return a - b - c + '0';
	}

	bool test(int tmp) {
		if (tmp == 1 || tmp == 0)
			return true;
		return false;
	}
private:

};
