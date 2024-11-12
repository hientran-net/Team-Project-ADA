#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>

using namespace std;

// ham in mang
void print(ofstream& f, vector<int>& a) {
    f << "[";
    for (int i = 0; i < a.size(); i++) {
        f << a[i];
        if (i < a.size() - 1) f << ", ";
    }
    f << "]";
}


void timNhomToiUu(vector<int>& a, vector<int>& nhom1, vector<int>& nhom2, int& ketQua) {

    // tinh tong cac phan tu trong mang chua N so nguyen
    int total = accumulate(a.begin(), a.end(), 0);

    // so luong phan tu trong mang
    int n = a.size();


    // khởi tạo mảng ( tổng khả dĩ - tổng có thể ) có kích thước tổng các phần tử + 1, gán tất cả bằng false
    vector<bool> possible_sums(total + 1, false);
    
    // trường hợp luôn đúng
    possible_sums[0] = true;


    for (int num : a) {
        for (int j = total; j >= num; j--) {
            if (possible_sums[j - num]) {
                possible_sums[j] = true;
            }
        }
    }
    int optimal_sum = total / 2;
    while (!possible_sums[optimal_sum]) {
        optimal_sum--;
    }

    int current_sum = 0;
    sort(a.rbegin(), a.rend());

    nhom1.clear();
    nhom2.clear();

    for (int num : a) {
        if (current_sum + num <= optimal_sum) {
            nhom1.push_back(num);
            current_sum += num;
        }
        else {
            nhom2.push_back(num);
        }
    }
    int tong1 = accumulate(nhom1.begin(), nhom1.end(), 0LL);
    int tong2 = accumulate(nhom2.begin(), nhom2.end(), 0LL);
    ketQua = tong1 * tong2;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if (!fin.is_open()) {
        cout << "error to open input.txt\n";
        return 1;
    }
    if (!fout.is_open()) {
        cout << "error to open output.txt\n";
        return 1;
    }

    int totalTestCase; // số bộ test
    fin >> totalTestCase;

    vector<int> nhom1, nhom2;
    int ketQua;

    while (totalTestCase--) {
        int n; // số phần tử của mảng
        fin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            fin >> a[i];
        }

        fout << "Day so ban dau: ";
        print(fout, a);
        fout << "\n";

        timNhomToiUu(a, nhom1, nhom2, ketQua);

        fout << "Nhom thu nhat: ";
        print(fout, nhom1);
        fout << " (tong nhom thu nhat = " << accumulate(nhom1.begin(), nhom1.end(), 0) << ")\n";

        fout << "Nhóm thu hai: ";
        print(fout, nhom2);
        fout << " (tong nhom thu hai = " << accumulate(nhom2.begin(), nhom2.end(), 0) << ")\n";

        fout << "Tich cua tong hai nhom: " << ketQua << "\n\n";
    }

    return 0;
}