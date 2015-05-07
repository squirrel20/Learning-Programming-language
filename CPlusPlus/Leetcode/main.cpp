/*
Leetcode的练习代码
*/

#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstring>
#include <climits>

using namespace std;

int atoi(const char *str)
{
	int len = strlen(str);
	long long out = 0;
	bool flag = true;
	char pos = '+';
	for (unsigned int i = 0; i < len; i++) {
		if (str[i] == ' ' && flag)
			continue;

		if ((str[i] == '+' || str[i] == '-') && flag) {
			flag = false;
			pos = str[i];
		}
		else if (str[i] >= '0' && str[i] <= '9') {
			flag = false;
			out = (str[i] - '0') + out * 10;
		}
		else
			break;
	}
	if (pos == '-') out = -out;
	if (out > INT_MAX) out = INT_MAX;
	if (out < INT_MIN) out = INT_MIN;
	return out;
}

void atoi()
{
	cout << atoi("2147483648") << endl;
	cout << atoi("aaa 1234aa ") << endl;
	cout << atoi("------------123") << endl;
}

int romanToInt(string s)
{
	int out = 0;
	map<char, int> stand = {
			{ 'I', 1 },
			{ 'V', 5 },
			{ 'X', 10 },
			{ 'L', 50 },
			{ 'C', 100 },
			{ 'D', 500 },
			{ 'M', 1000 } };

	for (int i = 0; i < s.size(); i++) {
		if ((i + 1) < s.size() && stand[s[i]] < stand[s[i + 1]]) {
			out += stand[s[i + 1]] - stand[s[i]];
			i++;
		}
		else
			out += stand[s[i]];
	}

	return out;
}

void romanToInt()
{
	cout << romanToInt("XLV") << endl;	// 45
	cout << romanToInt("XCIX") << endl;	// 99
}

string longestCommonPrefix(vector<string> &strs)
{
	if (strs.size() == 0) return "";

	string ret = "";

	for (size_t i = 0; i < strs[0].size(); i++)
	{
		for (size_t j = 1; j < strs.size(); j++)
		{
			if (i > strs[j].size() || strs[0][i] != strs[j][i])
				return ret;
		}

		ret += strs[0][i];
	}

	return ret;
}

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool hasPathSum(TreeNode *root, int sum)
{
	if (root == NULL) return false;
	if (root->left == NULL && root->right == NULL)	// leaf
		return root->val == sum;

	return hasPathSum(root->left, sum - root->val) ||
		hasPathSum(root->right, sum - root->val);
}

int minDepth(TreeNode *root)
{
	if (root == NULL) return 0;

	queue<TreeNode*> wd;
	wd.push(root);
	int dept = 1;
	while (1) {
		queue<TreeNode*> lu;
		while (!wd.empty()) {
			TreeNode* tmp = wd.front();
			wd.pop();

			if (tmp->left == NULL && tmp->right == NULL) return dept;
			if (tmp->left != NULL) lu.push(tmp->left);
			if (tmp->right != NULL) lu.push(tmp->right);
		}
		dept++;
		wd = lu;
	}
	return dept;
}

int getDepth(TreeNode *root, bool& isContinue)
{
	if (!isContinue) return 0;
	if (root == NULL) return 0;

	int leftDepth = getDepth(root->left, isContinue);
	int rightDepth = getDepth(root->right, isContinue);

	if (!isContinue) return 0;
	isContinue = abs(leftDepth - rightDepth) <= 1;
	return max(leftDepth, rightDepth) + 1;
}

bool isBalanced(TreeNode *root)
{
	bool isContinue = true;
	getDepth(root, isContinue);
	return isContinue;
}

int maxDepth(TreeNode *root)
{
	if (root == NULL) return 0;
	stack<TreeNode *> gray;
	stack<int> depth;
	int out = 0;

	gray.push(root);
	depth.push(1);
	while (!gray.empty()) {
		TreeNode *tmp = gray.top();
		int num = depth.top();
		gray.pop();
		depth.pop();
		if (tmp->left == NULL && tmp->right == NULL) {
			out = num > out ? num : out;
		}
		else {
			if (tmp->left != NULL) {
				gray.push(tmp->left);
				depth.push(num + 1);
			}
			if (tmp->right != NULL) {
				gray.push(tmp->right);
				depth.push(num + 1);
			}
		}
	}
	return out;
}

void maxDepth()
{
	TreeNode root(1);
	TreeNode left(2);
	root.left = &left;

	cout << maxDepth(&root) << endl;
}

vector<int> twoSum(vector<int> &numbers, int target)
{
	map<int, int> myMap;
	vector<int> output;

	for (int i = 0; i < numbers.size(); i++) {
		int tmp = target - numbers[i];

		if (myMap.find(tmp) != myMap.end()) {
			if (i < myMap[tmp]){
				output.push_back(i + 1);
				output.push_back(myMap[tmp] + 1);
			}
			else {
				output.push_back(myMap[tmp] + 1);
				output.push_back(i + 1);
			}


			return output;
		}

		myMap[numbers[i]] = i;
	}

	return output;
}

vector<int> twoSum()
{
	int numbers[] = { 2, 7, 11, 15 };
	vector<int> myvector(numbers, numbers + 4);
	vector<int> output = twoSum(myvector, 9);

	cout << output[0] << ' ' << output[1] << endl;

	return myvector;
}

int removeDuplicates(int A[], int n)
{
	int index = 0;
	for (int i = 1; i < n; ++i) {
		if (A[i] != A[index]) {
			A[index + 1] = A[i];
			++index;
		}
	}

	if (n == 0)
		index = -1;

	return index + 1;
}

int removeDuplicates()
{
	int A[] = { 1, 1, 2 };

	cout << removeDuplicates(A, 3) << endl;
}

int removeDuplicates2(int A[], int n)
{
	if (n < 3)
		return n;

	int index = 1;
	for (int i = 2; i < n; ++i) {
		if (A[i] != A[index - 1]) {
			A[index + 1] = A[i];
			++index;
		}
	}

	return index + 1;
}

int removeDuplicates2()
{
	int A[] = { 1, 1, 1, 2, 2, 3 };

	cout << removeDuplicates2(A, 6) << endl;
}

int removeElement(int A[], int n, int elem)
{
	int left, mid, right, index;
	sort(A, A + n);

	left = 0;
	right = n - 1;
	index = -1;
	while (left <= right) {
		mid = (left + right) / 2;
		if (A[mid] < elem)
			left = mid + 1;
		else if (A[mid] > elem)
			right = mid - 1;
		else {
			index = mid;
			break;
		}
	}

	if (index == -1) return n;

	left = right = index;
	while (left >= 0 && A[left] == elem) left--;
	while (right < n && A[right] == elem) right++;

	while (right < n) {
		A[left + 1] = A[right];
		left++;
		right++;
	}

	return left + 1;
}

int removeElement()
{
	int A[] = { 2, 2, 3, 1 };
	int output = removeElement(A, 4, 2);
	cout << output << endl;
	for (int i = 0; i < output; i++)
		cout << ' ' << A[i];
	cout << '\n';
	return output;
}

int singleNumber(int A[], int n)
{
	int ones = 0;
	int twos = 0;
	int threes = 0;
	for (int i = 0; i < n; i++) {
		twos = twos | (ones & A[i]);
		ones = ones ^ A[i];
		threes = ones & twos;

		ones = ones & (~threes);
		twos = twos & (~threes);
	}

	return ones;
}

void singleNumber()
{
	int A[] = { 2, 2, 3, 2 };
	cout << singleNumber(A, 4) << endl;
}

int search(int A[], int n, int target)
{
	int first = 0;
	int last = n - 1;
	int mid;

	while (first <= last) {
		mid = (first + last) / 2;

		if (A[mid] == target)
			return mid;

		if (A[first] <= A[last]) {
			// sorted arrary
			if (A[mid] < target)
				first = mid + 1;
			else
				last = mid - 1;
		}
		else {
			if (A[mid] < A[first]) {
				if (target < A[mid])
					last = mid - 1;
				else if (A[mid] < target && target <= A[last])
					first = mid + 1;
				else
					last = mid - 1; // target > A[last]
			}
			else {
				if (target > A[mid])
					first = mid + 1;
				else if (A[last] < target && target < A[mid])
					last = mid - 1;
				else
					first = mid + 1;    // target <= A[last]
			}
		}
	}

	return -1;
}

void search()
{
	int A[] = { 4, 5, 6, 7, 0, 1, 2 };
	int A2[] = { 1, 3, 5 };
	int A4[] = { 2, 1 };
	int A5[] = { 3, 1, 2 };

	cout << search(A, 7, 1) << endl;
	cout << search(A2, 3, 1) << endl;
	cout << search(A4, 2, 1) << endl;
	cout << search(A5, 3, 1) << endl;
}

bool search2(int A[], int n, int target)
{
	int first = 0;
	int last = n - 1;
	int mid;

	while (first <= last) {
		mid = (first + last) / 2;

		if (A[mid] == target)
			return true;

		if (A[first] < A[last]) {
			// sorted arrary
			if (A[mid] < target)
				first = mid + 1;
			else
				last = mid - 1;
		}
		else {
			if (A[first] == A[last] && A[mid] == A[first]) {
				int tmp = mid + 1;
				// 判断是哪一边所有数字相等
				while (A[tmp] == A[last]) tmp++;
				if (tmp > last)
					last = mid - 1;
				else
					first = mid + 1;
			}
			else if (A[mid] < A[first]) {
				if (target < A[mid])
					last = mid - 1;
				else if (A[mid] < target && target <= A[last])
					first = mid + 1;
				else
					last = mid - 1; // target > A[last]
			}
			else {
				if (target > A[mid])
					first = mid + 1;
				else if (A[last] < target && target < A[mid])
					last = mid - 1;
				else
					first = mid + 1;    // target <= A[last]
			}
		}
	}

	return false;
}

void search2()
{
	int A2[] = { 1, 3, 1, 1, 1 };
	int A4[] = { 1, 1 };
	int A5[] = { 3, 1, 1 };

	cout << search2(A2, 5, 3) << endl;
	cout << search2(A4, 2, 1) << endl;
	cout << search2(A5, 3, 1) << endl;
}

string countAndSay(int n)
{
	if (n == 0) return "";

	string say = "1";

	for (int i = 2; i <= n; i++) {
		string cursay = "";
		for (int j = 0; j < say.size();) {
			int tmp = j + 1;
			while (tmp < say.size() && say[tmp] == say[j])
				tmp++;

			cursay += (tmp - j + '0');
			cursay += say[j];

			j = tmp;
		}

		say = cursay;
	}

	return say;
}

void countAndSay()
{
	cout << countAndSay(4) << endl;
}

int reverse(int x)
{
	bool flag = x < 0 ? true : false;
	int out = 0;
	x = x < 0 ? -x : x;
	while (x) {
		out = out * 10 + x % 10;
		if (out < 0) return 0;
		x /= 10;
	}

	if (flag) out = -out;
	return out;
}

void reverse()
{
	cout << reverse(-13) << endl;
}

bool isPalindrome(int x)
{
	// 负数没有回文数？为什么
	if (x < 0) return false;

	int tmp = 0;
	int x2 = x;
	while (x) {
		tmp = tmp * 10 + x % 10;
		x /= 10;
	}

	return tmp == x2; // 这里也有考虑到溢出的情况，溢出了，自然两者就不等了
}


bool isPalindrome(string s)
{
	int low = 0;
	int high = s.size() - 1;

	while (low < high) {
		if (s[low] >= 'A' && s[low] <= 'Z')
			s[low] = s[low] - 'A' + 'a';
		else if (!((s[low] >= 'a' && s[low] <= 'z') ||
			(s[low] >= '0' && s[low] <= '9'))) {
			low++;
			continue;
		}
		if (s[high] >= 'A' && s[high] <= 'Z')
			s[high] = s[high] - 'A' + 'a';
		else if (!((s[high] >= 'a' && s[high] <= 'z') ||
			(s[high] >= '0' && s[high] <= '9'))) {
			high--;
			continue;
		}

		if (s[low] != s[high]) return false;

		low++;
		high--;
	}

	return true;
}

void isPalindrome()
{
	cout << isPalindrome(2) << endl;
	cout << isPalindrome(23) << endl;
	cout << isPalindrome(131) << endl;

	cout << "-----------------------------------" << endl;

	cout << isPalindrome("1Q") << endl;
	cout << isPalindrome("A man, a plan, a canal: Panama") << endl;
	cout << isPalindrome("race a car") << endl;
}

vector<vector<int> > generate(int numRows)
{
	vector<vector<int> > pt;
	if (numRows < 1) return pt;

	vector<int> one;
	one.push_back(1);
	pt.push_back(one);

	for (int i = 1; i < numRows; ++i) {
		vector<int> curLine;
		curLine.push_back(1);
		for (int j = 1; j < i; ++j) {
			curLine.push_back(pt[i - 1][j] + pt[i - 1][j - 1]);
		}
		curLine.push_back(1);
		pt.push_back(curLine);
	}

	return pt;
}

void generate()
{
	vector<vector<int> > pt = generate(5);

	for (int i = 0; i < pt.size(); ++i) {
		for (int j = 0; j < pt[i].size(); ++j) {
			cout << ' ' << pt[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
}

vector<int> getRow(int rowIndex)
{
	vector<int> row;
	if (rowIndex < 0) return row;

	row.push_back(1);
	double tmp;
	for (int i = 1; i <= rowIndex; ++i) {
		tmp = (double)row.back() * (double)(rowIndex - i + 1) / (double)i;
		row.push_back(tmp);
	}

	return row;
}

void getRow()
{
	vector<int> row = getRow(40);

	for (int i = 0; i < row.size(); ++i)
		cout << ' ' << row[i];
	cout << '\n';
}

vector<vector<int> > levelOrder(TreeNode *root)
{
	vector<vector<int> > level;
	if (root == NULL) return level;
	queue<TreeNode *> gray;
	gray.push(root);

	while (!gray.empty()){
		vector<int> each_level;
		int gsize = gray.size();
		while (gsize--) {
			TreeNode *tmp = gray.front();
			gray.pop();
			each_level.push_back(tmp->val);
			if (tmp->left != NULL)
				gray.push(tmp->left);
			if (tmp->right != NULL)
				gray.push(tmp->right);
		}
		level.push_back(each_level);
	}

	return level;
}

vector<vector<int> > levelOrderBottom(TreeNode *root)
{
	vector<vector<int> > out;
	stack<vector<int> > level;
	if (root == NULL) return out;
	queue<TreeNode *> gray;
	gray.push(root);

	while (!gray.empty()){
		vector<int> each_level;
		int gsize = gray.size();
		while (gsize--) {
			TreeNode *tmp = gray.front();
			gray.pop();
			each_level.push_back(tmp->val);
			if (tmp->left != NULL)
				gray.push(tmp->left);
			if (tmp->right != NULL)
				gray.push(tmp->right);
		}
		level.push(each_level);
	}

	while (!level.empty()) {
		vector<int> tmp = level.top();
		level.pop();
		out.push_back(tmp);
	}
	return out;
}

string convert(string s, int nRows)
{
	if (nRows <= 1 || nRows >= s.size()) return s;
	int t = nRows * 2 - 2;
	int t2 = t;
	string out = "";

	for (int i = 0; i < nRows; ++i) {
		for (int j = i; j < s.size();) {
			out += s[j];
			if (j + t2 < s.size() && t2 < t && t2 > 0)
				out += s[j + t2];
			j += t;
		}
		t2 -= 2;
	}
	return out;
}

void convert()
{
	cout << convert("PAYPALISHIRING", 3) << endl;
}

bool isSameTree(TreeNode *p, TreeNode *q)
{
	if (p != NULL && q != NULL && p->val == q->val)
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	else if (p == NULL && q == NULL)
		return true;
	else
		return false;
}

void merge(int A[], int m, int B[], int n)
{
	int len = m + n - 1;
	int i = m - 1;
	int j = n - 1;
	while (i >= 0 && j >= 0) {
		if (A[i] >= B[j])
			A[len--] = A[i--];
		else
			A[len--] = B[j--];
	}
	while (j >= 0) {
		A[len--] = B[j--];
	}
}

void merge()
{
	int A[] = { 2, 3, 6, 9, 11, 1, 7, 8, 15 };
	int B[] = { 1, 7, 8, 15 };
	merge(A, 5, B, 4);
	for (int i = 0; i < 9; ++i) {
		cout << ' ' << A[i];
	}
	cout << '\n';
}

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
	ListNode tmp(0);
	tmp.next = head;
	ListNode *first = &tmp;
	ListNode *second = &tmp;
	while (n--) first = first->next;
	while (first != NULL && first->next != NULL) {
		first = first->next;
		second = second->next;
	}
	second->next = second->next->next;
	return tmp.next;
}

void func()
{
	printf("hello\n");
}

char *strStr(char *haystack, char *needle)
{
	if (haystack == NULL || needle == NULL) return NULL;

	char *hstart, *hend, *nstart, *nend;
	hstart = haystack;
	nstart = needle;
	while (*hstart != '\0' && *nstart != '\0') {
		if (*hstart != *nstart)
			hstart++;
		else {
			hend = hstart + 1;
			nend = nstart + 1;
			while (*hend != '\0' && *nend != '\0' && *hend == *nend) {
				hend++;
				nend++;
			}
			if (*nend == '\0')
				return hstart;
			else if (*nend != '\0' && *hend == '\0')
				return NULL;
		}
	}
	return NULL;
}

void strStr2(char *haystack, char *needle)
{
	int n = strlen(haystack);
	int m = strlen(needle);
	int s = 0;
	while (s <= n - m) {
		if (strncmp(needle, haystack + s, m) == 0)
			printf("%d\n", s);
		s++;
	}
}

void strStr()
{
	char haystack[] = "abcdedf";
	char needle[] = "bcd";
	strStr2(haystack, needle);
}

void rabinKarpMather(char *T, char *P, int d, int q)
{
	int n = strlen(T);
	int m = strlen(P);
	int p = 0;
	int h = 1;
	int t = 0;

	for (int i = 0; i < m; i++) {
		p = (d * p + P[i]) % q;
		t = (d * t + T[i]) % q;
		if (i < m - 1)
			h = (h * d) % q;
	}

	for (int s = 0; s < n - m; s++) {
		if (p == t && strncmp(T + s, P, m) == 0)
			printf("%d\n", s);
		if (s < n - m) {
			t = (d * (t - T[s] * h) + T[s + m]) % q;
		}
	}
}

void rabinKarpMather()
{
	char T[] = "1234567890";
	char P[] = "234";
	rabinKarpMather(T, P, 10, 3793171);
}

int main(int argc, char **argv)
{
	cout << "----------start------------" << endl;
	rabinKarpMather();
	cout << "----------done------------" << endl;
	return 0;
}