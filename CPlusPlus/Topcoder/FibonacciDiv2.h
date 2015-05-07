#include <iostream>

class FibonacciDiv2
{
public:
	FibonacciDiv2(){}
	~FibonacciDiv2(){}
	int find(int n) {
		if (n < 2)
			return 0;
		int i_minus_one, i, pre;

		i_minus_one = 1;
		i = 2;
		pre = i_minus_one;
		while (i < n) {
			pre = i;
			i = i + i_minus_one;
			i_minus_one = pre;
		}

		return (i - n) < (n - pre) ? (i - n) : (n - pre);
	}
private:

};
