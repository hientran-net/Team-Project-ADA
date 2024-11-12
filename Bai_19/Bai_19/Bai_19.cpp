#include <iostream>
#include <vector>
using namespace std;

void divideCandiesMinDifference(vector<int>& candies) {
    // tính tổng n số nguyên
    int total = 0;
    for (int items : candies)
        total += items;

    // kích thước mảng
    int n = candies.size();
    // điểm đích để tìm ra tổng tối ưu - tổng có thể tạo thành bởi các phần tử
    int target = total / 2;

    // mảng dp khởi tạo với kiểu bool, có kích thước = target + 1, gán tất cả = false
    vector<bool> dp(target + 1, false);
    // gán cho cái trường hợp cơ sở luôn luôn đúng, tổng 0 với 0 phần tử
    dp[0] = true;

    // fill mảng
    for (int i = 0; i < n; i++) { // chạy từ đầu đến hết mảng ( 0 - cuối mảng )
        // tổng có thể tạo thành bởi các phần tử trong mảng hay 0
        for (int j = target; j >= candies[i]; j--) { // j ( duyệt từ cuối ngược lên đầu )
            if (dp[j - candies[i]]) // 
                dp[j] = dp[j - candies[i]]; // gán giá trị true tại dp[j]
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
        if (currentSum >= candies[i] && dp[currentSum - candies[i]]) {
            part1.push_back(candies[i]);
            currentSum -= candies[i];
        }
    }
    currentSum = sum2;
    for (int i = n - 1; i >= 0; i--) {
        if (find(part1.begin(), part1.end(), candies[i]) == part1.end()) {
            part2.push_back(candies[i]);
        }
    }

    // In kết quả
    cout << "Part 1: ";
    for (int items : part1)
        cout << items << " ";
    cout << "(" << total - sum2 << " candies)" << endl;

    cout << "Part 2: ";
    for (int items : part2)
        cout << items << " ";
    cout << "(" << total - sum1 << " candies)" << endl;

    cout << "Tich hai tong lon nhat: " << sum1 * sum2 << "\n";
}
 
int main() {
    vector<int> candies = { 2, 5, 4, 3, 15 }; // Ví dụ
    //vector<int> candies = { 5, 5, 4, 4, 2 }; // Ví dụ
    //vector<int> candies = { 3, 1, 16, 24, 3}; // Ví dụ
    //vector<int> candies = { 3, 1, 16, 24, 3}; // Ví dụ
    //vector<int> candies = { 1, 2, 3, 4, 5 }; // Ví dụ
    //vector<int> candies = { 51, 28, 23, 1, 2, 4, 6, 7, 8, 1, 22, 4 }; // Ví dụ
    divideCandiesMinDifference(candies);



    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";


    cout << (int)7.5;
    return 0;
}
