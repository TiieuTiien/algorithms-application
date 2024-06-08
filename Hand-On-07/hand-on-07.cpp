#include <iostream>
#include <cstring>

using namespace std;

bool palindrome(string s){
	
	int length = s.length();
	int mid = (length+1)/2;
	
	for(int i = mid; i >= 0; i--){
		if (s[i] != s[length-i-1])
			return false;
	}
	return true;
}

int longestPalindrome(string s, int k){
	if(s == "" || k<1) return 0;
	
	int left = k, right = k;
	
	while (left >= 0 && right < s.length() && s[left] == s[right]){
		left--;
		right++;
	}
	
	return right-left-1;
}

string xauConDaiNhat(string s){
	int k;
	cout << "Xau khong doi xung\nHay nhap vao k: ";
	cin >> k;
	
	int len = longestPalindrome(s, k);
	int start = k - ((len-1)/2);
	
	return s.substr(start, len);
}

int main(){
	string s = "daa";
	
	if(palindrome(s))
		cout << "Xau la xau doi xung!";
	else{
		string substring = xauConDaiNhat(s);
		cout << "Xau con doi xung dai nhat: " << substring;
	}
	cout << "\n";
	
	return 0;
}