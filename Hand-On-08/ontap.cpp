#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Laptop {
    string brand;
    string config;
    int price;
};

vector<Laptop> initializeLaptops() {
    return {
        {"HP", "CPU 2.5GHz upto 3.5GHz-RAM 16GB-SSD 512GB", 15000000},
        {"ACER", "CPU 2.5GHz upto 3.5GHz-RAM 8GB-HDD 2TB", 12000000},
        {"DELL", "CPU 3.0GHz upto 4.0GHz-RAM 16GB-SSD 1TB", 20000000},
        {"ASUS", "CPU 2.8GHz upto 3.8GHz-RAM 16GB-HDD 1TB", 17000000}
    };
}

// Boyer-Moore-Horspool algorithm
bool Boyer_Moore_Horspool(const string& P, const string& T) {
    int v = P.size(); // Độ dài của chuỗi P
    int i = v - 1; // Vị trí bắt đầu kiểm tra trong T
    int k, x;

    while (i < T.size()) { // Lặp lại cho đến khi hết chuỗi T
        k = v - 1; // Bắt đầu từ ký tự cuối cùng của chuỗi P
        while (T[i] == P[k] && k > -1) { // So sánh các ký tự từ cuối về đầu
            i--; // Giảm i để kiểm tra ký tự trước đó trong T
            k--; // Giảm k để kiểm tra ký tự trước đó trong P
        }
        if (k < 0) { // Nếu k < 0, nghĩa là toàn bộ chuỗi P khớp với một phần của chuỗi T
            return true; // Chuỗi P được tìm thấy trong chuỗi T
        } else {
            x = P.find(T[i]); // Tìm vị trí của ký tự T[i] trong chuỗi P
            if (x < 0) {
                i = i + v; // Nếu không tìm thấy ký tự T[i] trong P, nhảy qua đoạn dài bằng độ dài của P
            } else {
                i = i + v - x - 1; // Nếu tìm thấy, nhảy qua đoạn phù hợp
            }
        }
    }
    return false; // Nếu hết chuỗi T mà không tìm thấy P, trả về false
}

bool ZSearch(const string & P, const string & T){
	string concat = P + "$" + T;
	int l = concat.size();
	vector<int> Z(l, -1);
	int left = 0, right = 0;
	
	for(int i = 0; i < l; i++){
		if(i > left){
			left=right=i;
			while(right<l&&concat[right]==concat[right-left])
				right++;
			Z[i]=right-left;
			right++;
		}else if(Z[i-left]<right-i+1){
			Z[i]=Z[i-left];
		}else{
			left=i;
			while(right<l&&concat[right]==concat[right-left])
				right++;
			Z[i]=right-left;
			right++;
		}
	}
	
	for(int i=0; i<l; i++){
		if (Z[i]==P.size()) return true;
	}
	
	return false;
}


int F3(const vector<Laptop>& laptops) {
    int count = 0;
    for (const auto& laptop : laptops) {
        if (Boyer_Moore_Horspool("RAM 16GB", laptop.config)) {
            count++;
        }
    }
    return count;
}

pair<int, vector<string>> F4(const vector<Laptop>& laptops) {
    vector<string> ssdLaptops;
    for (const auto& laptop : laptops) {
        if (ZSearch("SSD", laptop.config)) {
            ssdLaptops.push_back(laptop.brand);
        }
    }
    return {ssdLaptops.size(), ssdLaptops};
}

int main() {
    vector<Laptop> laptops = initializeLaptops();

    // Sử dụng hàm F3 để tính và thông báo kết quả r
    int r = F3(laptops);
    cout << "So luong may tinh co RAM 16GB: " << r << endl;

    // Sử dụng hàm F4 để tính và thông báo kết quả s và t
    pair<int, vector<string>> ssdResult = F4(laptops);
    int s = ssdResult.first;
    vector<string> t = ssdResult.second;
    
    cout << "So luong may tinh su dung SSD: " << s << endl;
    cout << "Danh sach may tinh su dung SSD: ";
    for (const string& brand : t) {
        cout << brand << " ";
    }
    cout << endl;

    return 0;
}
