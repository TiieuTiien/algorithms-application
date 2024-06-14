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

bool compareByPriceIncrease(const Fan& a, const Fan& b) {
    return a.price < b.price;
}

vector<Fan> calculate(const vector<Fan>& d, int p) {
	vector<Fan> res;
	vector<Fan> copy = d;

    // Sort by price increase
    sort(copy.begin(), copy.end(), compareByPriceIncrease);
    
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

// Bai tap 2

bool compareByPriceDecrease(const Fan& a, const Fan& b) {
    return a.price > b.price;
}

vector<Fan> minFan(const vector<Fan>& d, int p) {
	vector<Fan> res;
	vector<Fan> copy = d;

    // Sort by price decrease
    sort(copy.begin(), copy.end(), compareByPriceDecrease);
    
    for (const Fan& fan : d) {
        if (fan.price <= p) {
            res.push_back(fan);
            p -= fan.price;
        }
    }
    if (p == 0)
	    return res;
	else
		return {};
}

// Bai tap 3
vector<Fan> minFanLargerThanP(const vector<Fan>& d, int p) {
	vector<Fan> res;
	vector<Fan> copy = d;

    // Sort by price decrease
    sort(copy.begin(), copy.end(), compareByPriceDecrease);
    
    for (const Fan& fan : copy) {
        res.push_back(fan);
        p -= fan.price;
        if (p < 0) return res;
    }
    return {};
}

int main() {
    int p; // Số tiền
    int n; // Số lượng chiếc quạt
    vector<Fan> d = {
        {"Hatari", "Do", 100000},
        {"Senko", "Vang", 200000},
        {"Mitsubisi", "Xanh", 300000},
        {"Panasonic", "Cam", 500000},
        {"Asia", "Tim", 400000}
    };

    // input
    cout << "Nhap so tien p: ";
    cin >> p;

    vector<Fan> s = calculate(d, p);
    int c = s.size();
    
    if (c == 0){
    	cout << "Khong mua duoc chiec quat nao voi so tien vua nhap!\n\n";
	}else{
		cout << "So luong quat nhieu nhat co the mua duoc la: " << c
		<< "\n\nDanh sach quat:\n";
    	printVector(s);		
	}

    vector<Fan> v = minFan(d, p);
    int u = v.size();
    
    if (c == 0){
    	cout << "Khong the tim duoc so quat phai ban de co so tien dung bang p!\n\n";
	}else{
		cout << "So quat it nhat phai ban de co so tien dung bang p la: " << u
		<< "\n\nDanh sach quat:\n";
    	printVector(v);		
	}

    vector<Fan> t = minFanLargerThanP(d, p);
    int q = t.size();
    
    if (c == 0){
    	cout << "Khong the tim duoc so quat phai ban de co so tien dung bang p!\n\n";
	}else{
		cout << "So quat it nhat phai ban de co so tien nhieu hon p la: " << q
		<< "\n\nDanh sach quat:\n";
    	printVector(t);
	}

    return 0;
}
