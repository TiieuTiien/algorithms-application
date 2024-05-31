#include<iostream>
#include<map>
#include<string>

using namespace std;

// Bai toan 1
int countDistinct(string str){
    map<char, int> count;
    
    for(int i = 0; i < str.size(); i++){
        count[str[i]]++;
    }
    
    for (const auto item : count){
    	cout << item.first << ": " << item.second << endl;
	}
	cout << "\n";
	return 0;
}

//Bai toan 2
int indexOf(char p[], char t[]) {
    int m = strlen(p);
    int n = strlen(t) - m;
    for (int i = 0; i <= n; i++) {
        int j = 0;
        while (j < m && t[i + j] == p[j]) {
            j++;
        }
        if (j == m)
            return i;
    }
    return -1;
}

//Bai toan 3: Boyer Moore Horspool
int char_in_string(char t, char P[]){
	int length = sizeof(P)/sizeof(char);
	for (int i = 0; i < length; i++){
		if (P[i] == t) return i;
	}
	return -1;
}


bool Boyer_Moore_Horspool(char P[], char T[]) {
    int v = strlen(P), i = v - 1, k, x;
    while (i < strlen(T)) {
        k = v - 1;
        while (T[i] == P[k] && k > -1) {
            i--;
            k--;
        }
        if (k < 0) { return true; }
		else {
            x = char_in_string(T[i], P);
            if (x < 0) i = i + v;
            else i = i + v - x - 1;
        }
    }
    return false;
}

//Thuat toan Z
void z_algo(const char * s, int * z) {
    int n = strlen(s), left = 0, right = 0;
    for (int i = 1; i < n; i++) {
        if (i > right) {
            left = right = i;
            while (right < n && s[right - left] == s[right])
                right++;
            z[i] = right - left;
            right--;
        } else if (z[i - left] < right– i + 1)
            z[i] = z[i - left];
        else {
            left = i;
            while (right < n && s[right - left] == s[right])
                right++;
            z[i] = right - left;
            right--;
        }
    }
}

int main(){
	string s = "abccabdad123";
	char P[] = "daddyissue";
	char T[] = "ihavedaddyissue";
	
	cout << "Dem so lan xuat hien cac ky tu trong sau ky tu:\n";
	countDistinct(s);
	
	cout << "P co phai xau con cua T khong?\n";
	if (indexOf(P, T) == -1) cout << "Khong\n";
	else cout << "Co\n";
	
	if (Boyer_Moore_Horspool(P, T)) cout << "Co\n";
	else cout << "Khong\n";
	
	return 0;
}