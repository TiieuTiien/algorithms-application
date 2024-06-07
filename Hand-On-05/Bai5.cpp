#include<bits/stdc++.h>

using namespace std;
void sort(float * m, float * k, int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        float tmp = m[mid];
        int i = l, j = r;
        do {
            while (m[i] < tmp) i++;
            while (m[j] > tmp) j--;
            if (i <= j) {
                swap(m[i], m[j]);
                swap(k[i], k[j]);
                i++;
                j--;
            }
        } while (i <= j);
        sort(m, k, l, j);
        sort(m, k, i, r);
    }
}
void transport(float * m, float * k, int n, float K, int & u, float * v) {
    int i = n - 1;
    while (K > 0 && i >= 0) {
        if (K >= k[i]) {
            v[u++] = m[i];
            K -= k[i];
        }
        i--;
    }
}
int main() {
    float K = 12;
    int n = 7;
    float m[n] = { 3.4, 3.2, 2.4, 1.7, 2.6, 1.2, 4.5};
    float k[n] = { 4.5, 2.3, 1.8, 1.5, 2.7, 3.2, 3.6};
    sort(m, k, 0, n - 1);
    int u = 0;
    cout << "KL  -  KT\n";
    for (int i = 0; i < n; i++) {
        cout << m[i] << " - " << k[i] << endl;
    }
    float v[n];
    transport(m, k, n, K, u, v);
    for (int i = 0; i < u; i++) {
        cout << v[i] << " ";
    }
    cout << "\nSo hang " << u;
    return 0;
}