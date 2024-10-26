#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


// hàm kiểm tra số nguyên tố
bool isPrime(int n) {
    if (n < 2) // nếu số n đầu vào < 2 thì cúc
        return false; // return không phải là số nt
    for (int i = 2; i <= sqrt(n); ++i) { // chạy từ 2 - căn bậc hai số n
        if (n % i == 0)  // nếu số n chia hết một trong các số từ 2 - căn bậc hai số n thì cúc
            return false; // return không phải là số nt
    }
    return true; // nếu không lọt vào các trường hợp trên thì passed
}

void findSubsets(vector<int>& A, int K, int start, vector<int>& currentSubset, vector<vector<int>>& result) { 
    // Đầu vào nhận vào mảng A là mảng lưu trữ các phần tử 
    // Biến K là số lượng phần tử trong tập con 
    // start là index của phần tử
    // currentSubset là mảng lưu trữ các phần tử cần xét {1,2; 1,3; 1,4; ...}
    // result là mảng hai chiều lưu trữ các phần tử pass điều kiện có tổng là số nguyên tố
    if (currentSubset.size() == K) // Điều kiện dừng currentSubset == 2 thì thực hiện các khối lệnh trong
    {
        int sum = 0; // biến tạm [sum] tính tổng các phần tử trong currentSubset
        for (int num : currentSubset)  // vòng for tính tổng các phần tử trong currentSubset
            sum += num; // cộng dồng các phần tử
        if (isPrime(sum)) // nếu tổng các phần tử là số nguyên tố => return true
            result.push_back(currentSubset); // nếu là số nt thì đẩy vào mảng result lưu giá trị
        return; // thoát if
    }

    for (int i = start; i < A.size(); ++i) // start = 0, A.size() = 3; i++
    {
        currentSubset.push_back(A[i]); // currentSubset thêm các phần tử theo từng vòng for và số lần đệ quy
        findSubsets(A, K, i + 1, currentSubset, result); // tiến vào đệ quy lần hai để kiểm tra các phần tử đầu ghép với các phần tử còn lại
        currentSubset.pop_back(); // xóa phần tử cuối khi thoát đệ quy lần 2 , xóa phần tử đầu khi thoát đệ quy 1
    }
}

int main() {
    vector<int> A = { 1, 2, 3, 4 }; // Mảng A gồm 4 phần tử 
    int K = 2; // số lượng phần tử trong tập con
    vector<vector<int>> result; // mảng hai chiều result lưu trữ các phần tử pass cái điều kiện
    vector<int> currentSubset; // currentSubset lưu trữ các phần tử cần xét 

    findSubsets(A, K, 0, currentSubset, result); // Gọi hàm

    cout << "Cac tap con co " << K << " phan tu va tong so nguyen to:\n"; 

    // Vòng for định dạng kiểu in ra màn hình 
    //Source: ChatGPT.com
    //for (const auto& items : result)  // duyệt các phần tử trong result với biến kiểu tự động
    //{
    //    cout << "{";
    //    for (int i = 0; i < items.size(); ++i)
    //    {
    //        cout << items[i] << (i < items.size() - 1 ? ", " : "");
    //    }
    //    cout << "}\n";
    //}

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
}