#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <iomanip>
using namespace std;

const char* fi = "input.txt";
const char* fo = "output.txt";
const double oo = 1e9;
int n;
double a[100], b[100];
int H[100][100];
double L[100][100]; // L[i][j] tổng độ dài các đường chéo khi xét từ đỉnh i đến đỉnh j
double d[100][100]; // d là độ dài đường chéo giữa đỉnh i và j

void Nhap() {
    ifstream f(fi);
    if (!f) {
        cerr << "Error opening file " << fi << endl;
        exit(1);
    }
    f >> n;
    for (int i = 1; i <= n; i++) {
        f >> a[i] >> b[i];
    }
    f.close();
}

double DoDai(int i, int j) {
    return sqrt(pow((a[i] - a[j]), 2) + pow((b[i] - b[j]), 2));
}

void DoDaiDuongCheo() {
    memset(d, 0, sizeof(d));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (i != j && abs(i - j) != 1) {
                d[i][j] = DoDai(i, j);
                d[j][i] = d[i][j];
            }
        }
    }
}

void QHD() {
    memset(L, 0, sizeof(L));
    for (int m = 2; m <= n - 1; m++) {
        for (int i = 1; i <= n - m; i++) {
            int j = i + m;
            L[i][j] = +oo;
            for (int k = i + 1; k < j; k++) {
                double tong = L[i][k] + L[k][j] + d[i][k] + d[k][j];
                if (L[i][j] > tong) {
                    L[i][j] = tong;
                    H[i][j] = k;
                }
            }
        }
    }
}

void TruyVet(int i, int j, ofstream& f) {
    if (j - i >= 2) {
        int k = H[i][j];
        f << "Noi dinh " << i << " voi dinh " << k << endl;
        f << "Noi dinh " << k << " voi dinh " << j << endl;
        TruyVet(i, k, f);
        TruyVet(k, j, f);
    }
}

int main() {
    Nhap();
    DoDaiDuongCheo();
    QHD();
    ofstream f(fo);
    f << "Do dai ngan nhat: ";
    f /*<< fixed << setprecision(2) */<< L[1][n] << endl;
    TruyVet(1, n, f);
    f.close();
    return 0;
}
