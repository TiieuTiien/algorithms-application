#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Bai tap 1
struct Fan {
    string brand;
    string color;
    float price;
};

bool compareByPrice(const Fan& a, const Fan& b) {
    return a.price < b.price;
}

vector<Fan> calculate(const vector<Fan>& d, int p) {
	vector<Fan> res;
    for (const Fan& fan : d) {
        if (fan.price <= p) {
            res.push_back(fan);
            p -= fan.price;
        }
    }
    return res;
}

void printVector(const vector<Fan>& res){
    for (const Fan& fan: res){
    	cout << "Hang quat: " << fan.brand << ", Gia: " << fan.price << "\n";
	}
	cout << "\n";
	return;
}

int main() {
    int p; // Số tiền
    int n; // Số lượng chiếc quạt
    vector<Fan> d = {
        {"Hatari", "Do", 100000},
        {"Senko", "Vang", 250000},
        {"Mitsubisi", "Xanh", 200000},
        {"Panasonic", "Cam", 350000},
        {"Asia", "Tim", 150000}
    };

    // input
    cout << "Nhap so tien p: ";
    cin >> p;

    // Sort by price increase
    sort(d.begin(), d.end(), compareByPrice);

    vector<Fan> res = calculate(d, p);
    int c = res.size();
    
    if (c == 0){
    	cout << "Khong mua duoc chiec quat nao voi so tien vua nhap!\n\n";
	}else{
		cout << "So luong quat nhieu nhat co the mua duoc la: " << c
		<< "\n\nDanh sach quat:\n";
    	printVector(res);		
	}

    return 0;
}
