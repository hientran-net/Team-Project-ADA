#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    if (n < 2) 
        return false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

void findSubsets(vector<int>& A, int K, int start, vector<int>& currentSubset, vector<vector<int>>& result) { 
    if (currentSubset.size() == K)
    {
        int sum = 0;
        for (int num : currentSubset)
            sum += num;
        if (isPrime(sum))
            result.push_back(currentSubset);
        return;
    }

    for (int i = start; i < A.size(); ++i)
    {
        currentSubset.push_back(A[i]);
        findSubsets(A, K, i + 1, currentSubset, result);
        currentSubset.pop_back(); 
    }
}

int main() {
    vector<int> A = { 1, 2, 3, 4 }; 
    int K = 2; 
    vector<vector<int>> result; 
    vector<int> currentSubset;

    findSubsets(A, K, 0, currentSubset, result);

    cout << "Cac tap con co " << K << " phan tu va tong so nguyen to:\n"; 
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
}
