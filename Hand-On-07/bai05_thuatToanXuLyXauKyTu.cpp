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
void z_algo(const char *s, int *z) {
    int n = strlen(s), left = 0, right = 0;
    for (int i = 1; i < n; i++) {
        if (i > right) {
            left = right = i;
            while (right < n && s[right - left] == s[right])
                right++;
            z[i] = right - left;
            right--;
        } else if (z[i - left] < right - i + 1)
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

//Xau con chung dai nhat
int xauConChungDaiNhat(const char *L) {
    for (int i = 0; i <= len(A); i++) L[i][0] = 0;
    for (int j = 0; j <= len(B); j++) L[0][j] = 0;
    for (int i = 1; i <= len(A); i++)
        for (int j = 1; j <= len(B); j++)
            if (A[i - 1] == B[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
    return L[m][n];
}

int main(){
	string s = "abccabdad123";
	cout << "Dem so lan xuat hien cac ky tu trong sau ky tu:\n";
	countDistinct(s);
	
	char P[] = "daddyissue";
	char T[] = "ihavedaddyissue";
	cout << "P co phai xau con cua T khong?\n";
	if (indexOf(P, T) == -1) cout << "Khong\n\n";
	else cout << "Co\n\n";
	
	cout << "P co phai xau con cua T khong? (Boyer Moore Horspool)\n";
	if (Boyer_Moore_Horspool(P, T)) cout << "Co\n\n";
	else cout << "Khong\n\n";
	
	char S[] = "ACBDABACBAC";
	int length = sizeof(S)/sizeof(char);
	int z[length] = {-1};

	cout << "Z algorithm:\n";
	z_algo(S, z);
	for (int i = 0; i < length; i++){
		cout << z[i] << " ";
	}
	cout << "\n";
	
	
	
	return 0;
}