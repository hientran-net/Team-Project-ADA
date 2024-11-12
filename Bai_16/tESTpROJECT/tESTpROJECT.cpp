#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <iomanip>

using namespace std;

const char* fi = "CHIADAGIAC.INP";
const char* fo = "CHIADAGIAC.OUT";
const int MAXN = 100;
const double oo = 1e9;

int dem = 0;
int n;
double a[MAXN + 1], b[MAXN + 1];
int H[MAXN + 1][MAXN + 1];
double L[MAXN + 1][MAXN + 1]; // L[i][j] tổng độ dài các đường chéo khi xét từ đỉnh i đến đỉnh j
double d[MAXN + 1][MAXN + 1]; // d là độ dài đường chéo giữa đỉnh i và j

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

double KhoangCach(int i, int j) {
    return sqrt(pow((a[i] - a[j]), 2) + pow((b[i] - b[j]), 2));
}

void TinhKhoangCachCacDuongCheo() {
    memset(d,0, sizeof(d));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (i != j && abs(i - j) != 1) {
                d[i][j] = KhoangCach(i, j);
                d[j][i] = d[i][j];
            }
        }
    }
}

void QHD() {
    memset(L, 0, sizeof(L));

    for (int m = 3; m <= n - 1; m++) {
        for (int i = 1; i <= n - m; i++) { // 1 - 4, 1 2 3 4
            int j = i + m; // 4 - 7
            L[i][j] = +oo; // + vo cung
            for (int k = i; k < j; k++) { 
                double tong = L[i][k] + L[k][j] + d[i][k] + d[k][j];
                cout << ++dem << " ";
                if (L[i][j] > tong) {
                    L[i][j] = tong;
                    H[i][j] = k;
                }
            }
        }
    }
}

void TruyVet(int i, int j, ofstream& f) {
    if (j - i >= 3) {
        int k = H[i][j];
        f << "Noi dinh " << i << " voi dinh " << k << endl;
        f << "Noi dinh " << k << " voi dinh " << j << endl;
        TruyVet(i, k, f);
        TruyVet(k, j, f);
    }
}

int main() {
    Nhap();
    TinhKhoangCachCacDuongCheo();
    QHD();

    ofstream f(fo);


    f << "Do dai ngan nhat ";
    f << fixed << setprecision(2) << L[1][n] << endl;
    TruyVet(1, n, f);
    f.close();

    cout << "\n"; cout << "\n"; cout << "\n";

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << d[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n"; cout << "\n"; cout << "\n";

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << L[i][j] << " ";
        }
        cout << "\n";
    }


    cout << "\n"; cout << "\n"; cout << "\n";


    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << H[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}
