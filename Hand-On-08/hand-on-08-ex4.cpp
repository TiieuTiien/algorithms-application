#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Phone {
    string brand;
    int size;
    int price;
};

vector<vector<int>> knapsack(int s, const vector<Phone>& phones) {
    int n = phones.size();
    
    // Khởi tạo mảng 2 chiều F
    vector<vector<int>> F(n + 1, vector<int>(s + 1, 0));

    // Điền vào bảng F
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            F[i][j] = F[i - 1][j]; // Không lấy điện thoại thứ i
            if (phones[i - 1].size <= j) { // Nếu có thể lấy điện thoại thứ i
                int temp = phones[i - 1].price + F[i - 1][j - phones[i - 1].size];
                if (F[i][j] < temp) { // Lấy điện thoại thứ i
                    F[i][j] = temp;
                }
            }
        }
    }

    // Trả về ma trận F
    return F;
}

vector<string> result(int s, const vector<Phone>& phones) {
    vector<vector<int>> F = knapsack(s, phones);

    // In giá trị lớn nhất đạt được
    cout << "Max value: " << F[phones.size()][s] << endl;

    // Truy vết ngược lại để tìm danh sách điện thoại đã chọn
    int i = phones.size(), j = s;
    vector<string> selectedPhones;
    while (i > 0 && j > 0) {
        if (F[i][j] != F[i - 1][j]) {
            selectedPhones.push_back(phones[i - 1].brand);
            j -= phones[i - 1].size; // Giảm kích thước túi
        }
        i--;
    }

    // Trả về danh sách điện thoại đã chọn
    return selectedPhones;
}

int main() {
    int s = 10; // Kích thước của túi
    vector<Phone> phones = {
        {"PhoneA", 3, 50},
        {"PhoneB", 4, 60},
        {"PhoneC", 2, 40},
        {"PhoneD", 1, 30}
    };

    vector<string> selectedPhones = result(s, phones);

    // In danh sách điện thoại đã chọn
    cout << "Danh sách điện thoại: ";
    for (const string& brand : selectedPhones) {
        cout << brand << " ";
    }
    cout << endl;

    return 0;
}
