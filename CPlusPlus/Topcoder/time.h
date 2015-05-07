#include <string>
#include <sstream>

class Time
{
public:
	Time(){}
	~Time(){}
	std::string whatTime(int seconds) {
		int h, m, s;

		h = seconds / 3600;
		seconds %= 3600;

		m = seconds / 60;
		s = seconds % 60;

		std::stringstream sstream;
		std::string str;

		sstream << h << ":" << m << ":" << s;
		sstream >> str;

		return str;
	}

private:

};
