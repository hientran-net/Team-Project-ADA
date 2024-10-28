#include <iostream>
#include <vector>
using namespace std;

void divideCandiesMinDifference(vector<int>& candies) {
    int total = 0;

    for (int items : candies)
        total += items;

    int n = candies.size();
    int target = total / 2;

    vector<bool> dp(target + 1, false);
    dp[0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = target; j >= candies[i]; j--) {
            //dp[j] = dp[j] || dp[j - candies[i]];
            if (dp[j - candies[i]])
                dp[j] = dp[j - candies[i]];
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
}

int main() {
    //vector<int> candies = { 2, 5, 4, 3, 15 }; // Ví dụ
    //vector<int> candies = { 3, 1, 16, 24, 3}; // Ví dụ
    //vector<int> candies = { 3, 1, 16, 24, 3}; // Ví dụ
    vector<int> candies = { 51, 28, 23, 1, 2, 4, 6, 7, 8, 1, 22, 4 }; // Ví dụ
    divideCandiesMinDifference(candies);
    return 0;
}
