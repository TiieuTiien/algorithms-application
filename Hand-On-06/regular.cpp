#include<iostream>
#include "funcs.h"
using namespace std;

bool quickSort(int a[], int left, int right) {
    if (left < right) {
        int k = (left + right) / 2;
        int t = a[k];
        int i = left, j = right;
        do {
            while (a[i] < t) i = i + 1;
            while (a[j] > t) j = j-1;
            if (i <= j) {
                int tg = a[i];
                a[i] = a[j];
                a[j] = tg;
                i = i + 1;
                j = j-1;
            }
        } while (i <= j);
        quickSort(a, left, j);
        quickSort(a, i, right);
    }
    return true;
}

void printArray(int a[], int n) {
    for (int i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void print2DArray(int f[][100], int n) {
    for (int i=0; i<n+1; i++) {
        for (int j=0; j<n+1; j++) {
			cout << f[i][j] << " ";
		}
		cout<<endl;
    }
    cout << endl;
}