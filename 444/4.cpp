#include <iostream>
#include <algorithm>
#include<string>
using namespace std;
 
//检查后面有多少个0
int num(string arr) {
	int nums = 0;
	for (auto i = arr.end()-1; i != arr.begin(); i--) {
		if (*i == '0') {
			nums++;
		}
		else {
			break;
		}
	}
	return nums;
}
//检查前面有多少个0
int pernum(string arr) {
	int nums = 0;
	for (auto i = arr.begin(); i != arr.end(); i++) {
		if (*i == '0') {
			nums++;
		}
		else {
			break;
		}
	}
	return nums;
}
int main() {
    cout<<"请输入你想要反转的数"<<endl;
	string arr;
	cin >> arr;
	if (arr.back() == '%') {
		reverse(arr.begin(), arr.end() - 1);
		cout << arr;
		return 0;
	}
	for (auto i = arr.begin(); i != arr.end(); i++) {
		string left, right;
		int l, r;
		if (*i == '/') {
			left = arr.substr(0, arr.find('/'));
			right = arr.substr(arr.find('/') + 1);
			l = num(left);
			r = num(right);
			left.erase(left.end() - l, left.end());//删除后面的0
			right.erase(right.end() - r, right.end());
			reverse(left.begin(), left.end());//反转
			reverse(right.begin(), right.end());
			cout << left << "/" << right;
			return 0;
		}
		if (*i == '.') {
			left = arr.substr(0, arr.find('.'));
			right = arr.substr(arr.find('.') + 1);
			l = num(left);
			r = pernum(right);
			left.erase(left.end() - l, left.end());
			if (right != "0") {
				right.erase(right.begin(), right.begin()+r);
			}
			reverse(left.begin(), left.end());
			reverse(right.begin(), right.end());
			cout << left << "." << right;
			return 0;
		}
		
	}
	int a = 0;
	a = num(arr);
	if (a != 0) {
		arr.erase(arr.end() - a, arr.end());
	}
	reverse(arr.begin(), arr.end());
	cout << arr;
	return 0;
}