#include "funcs.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s = "abccabdad123";
    cout << "Dem so lan xuat hien cac ky tu trong xau ky tu:\n";
    countDistinct(s);
    
    char P[] = "tiendeptrai";
    char T[] = "iamtiendeptraivl";
    cout << "P co phai xau con cua T khong?\n";
    if (indexOf(P, T) == -1) cout << "Khong\n\n";
    else cout << "Co\n\n";
    
    cout << "P co phai xau con cua T khong? (Boyer Moore Horspool)\n";
    if (Boyer_Moore_Horspool(P, T)) cout << "Co\n\n";
    else cout << "Khong\n\n";
    
    char S[] = "Viet$Ban Viet o Viet Nam";
    int length = strlen(S);
    int z[length] = {-1};
    
    cout << "Z algorithm:\n";
    z_algo(S, z);
    for (int i = 0; i < length; i++) {
        cout << z[i] << " ";
    }
    cout << "\n\n";
    
    const char A[] = "abc1def2ghi3";
    const char B[] = "abcdefghi123";
    vector<vector<int>> L(strlen(A) + 1, vector<int>(strlen(B) + 1));
    
    int lcs_length = lcs_func(L, A, B);
	string lcs = lcs_backtrack(L, A, B);
    cout << "Do dai xau con chung dai nhat co do dai la: " << lcs_length
	<< "\nXau con chung dai nhat la: " << lcs << "\n";
    
    return 0;
}
