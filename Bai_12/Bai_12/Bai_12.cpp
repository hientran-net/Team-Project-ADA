#include <iostream>
#include <vector>
using namespace std;

void dividearrMinDifference(vector<int>& arr) {
    // tính tổng n số nguyên
    int total = 0;
    for (int items : arr)
        total += items;

    // kích thước mảng
    int n = arr.size();
    // điểm đích để tìm ra tổng tối ưu - tổng có thể tạo thành bởi các phần tử
    int target = total / 2;

    // mảng dp khởi tạo với kiểu bool, có kích thước = target + 1, gán tất cả = false
    vector<bool> dp(target + 1, false);
    // gán cho cái trường hợp cơ sở luôn luôn đúng, tổng 0 với 0 phần tử
    dp[0] = true;

    // fill mảng
    for (int i = 0; i < n; i++) { // chạy từ đầu đến hết mảng ( 0 - cuối mảng )
        // tổng có thể tạo thành bởi các phần tử trong mảng hay 0
        for (int j = target; j >= arr[i]; j--) { // j ( duyệt từ cuối ngược lên đầu )
            if (dp[j - arr[i]]) // 
                dp[j] = dp[j - arr[i]]; // gán giá trị true tại dp[j]
        }
    }

    int sum1;
    for (sum1 = target; sum1 >= 0; sum1--) {
        if (dp[sum1])
            break;
    }

    int sum2 = total - sum1;

    vector<int> part1, part2;
    int currentSum = sum1;
    for (int i = n - 1; i >= 0; i--) {
        if (currentSum >= arr[i] && dp[currentSum - arr[i]]) {
            part1.push_back(arr[i]);
            currentSum -= arr[i];
        }
    }
    currentSum = sum2;
    for (int i = n - 1; i >= 0; i--) {
        if (find(part1.begin(), part1.end(), arr[i]) == part1.end()) {
            part2.push_back(arr[i]);
        }
    }

    // In kết quả
    cout << "Part 1: ";
    for (int items : part1)
        cout << items << " ";
    cout << "(" << total - sum2 << " phan tu)" << endl;

    cout << "Part 2: ";
    for (int items : part2)
        cout << items << " ";
    cout << "(" << total - sum1 << " phan tu)" << endl;

    cout << "Tich hai tong lon nhat: " << sum1 * sum2 << "\n";
}

int main() {
    vector<int> arr = { 2, 5, 4, 3, 15 }; // Ví dụ
    //vector<int> arr = { 5, 5, 4, 4, 2 }; // Ví dụ
    //vector<int> arr = { 3, 1, 16, 24, 3}; // Ví dụ
    //vector<int> arr = { 3, 1, 16, 24, 3}; // Ví dụ
    //vector<int> arr = { 1, 2, 3, 4, 5 }; // Ví dụ
    //vector<int> arr = { 51, 28, 23, 1, 2, 4, 6, 7, 8, 1, 22, 4 }; // Ví dụ
    dividearrMinDifference(arr);
    return 0;
}
