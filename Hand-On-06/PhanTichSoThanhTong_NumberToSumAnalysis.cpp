#include <iostream>
#include <time.h>
#include "funcs.h"
using namespace std;

int analys01(int f[][100], int m, int n){
	for (int i = 1; i <= m; i++){
		for (int j = 0; j <= n; j++){
			if(i > j){
				f[i][j] = f[i-1][j];
			}
			else{
				f[i][j] = f[i-1][j] + f[i][j-i];
			}
		}
	}
	return f[m][n];
}

//Dùng 2 mảng một chiều
int analys02(int next[], int cur[], int m, int n) {
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i > j) {
                next[j] = cur[j];
            } else {
                next[j] = cur[j] + next[j-i];
            }
        }
        copy(next, next+n+1, cur);
    }
    return cur[n];
}

//Dùng 1 mảng một chiều
int analys03(int cur[], int m, int n) {
    for (int i = 1; i <= m; i++) {
        for (int j = i; j <= n; j++) {
            if (j >= i) {
                cur[j] = cur[j] + cur[j-i];
            }
        }
    }
    return cur[n];
}

//Dùng đệ quy (chậm)
int recursion_analys(int m, int n) {
    if (m == 0) {
        if (n == 0)
            return 1;
        else return 0;
    } else {
        if (m > n) 
			return recursion_analys(m-1, n);
        else 
			return recursion_analys(m-1, n) + recursion_analys(m, n-m);
    }
}

int a[][100] = {0,0};
//Dùng kỹ thuật đệ quy có nhớ
int recursion_with_memory_analys(int m, int n) { 
    if (m == 0) {
        if (n == 0)
            a[m][n] = 1;
        else
            a[m][n] = 0;
    } else {
        if (m > n)
            a[m][n] = recursion_with_memory_analys(m-1, n);
        else
            a[m][n] = recursion_with_memory_analys(m-1, n) + recursion_with_memory_analys(m, n-m);
    }
    return a[m][n];
}

int main()
{
	int m = 8, n = 6;
	cout<<"Dung 1 mang 2 chieu:"<<endl;
	int f[m+1][100] = {0,0};
	f[0][0] = 1;
	cout << analys01(f, m, n) << "\n\n";
	
	cout<<"Dung 2 mang 1 chieu:"<<endl;
	int next[m+1] = {0}, cur[n+1] = {0};
	cur[0] = 1;
	cout << analys02(next, cur, m, n) << "\n\n";
	
	cout<<"Dung 1 mang 1 chieu:"<< endl;
	for (int i =0; i< n+1; i++) cur[i] = 0;
	cur[0] = 1;
	cout << analys03(cur, m, n) << "\n\n";
	
	cout<<"Dung de quy (cham):"<< endl;
	cout << recursion_analys(m, n) << "\n\n";
	
	cout<<"Dung de quy co nho:"<< endl;
	cout << recursion_with_memory_analys(m, n) << "\n\n";
	
    return 0;
}