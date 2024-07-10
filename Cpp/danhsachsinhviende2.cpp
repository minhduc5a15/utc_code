#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DiemSinhVien {
public:
    string maSV;
    string hoTen;
    float diem{};

    void nhapThongTin() {
        cin >> maSV;
        cin.ignore();
        getline(cin, hoTen);
        cin >> diem;
    }

    void xuatThongTin() const {
        cout << maSV << " - " << hoTen << " - " << diem << '\n';
    }
};

class SinhVien: public DiemSinhVien {
public:
    bool operator<(const SinhVien &other) const {
        return hoTen == other.hoTen ? maSV < other.maSV : hoTen < other.hoTen;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a, b, n;
    cin >> a >> b >> n;
    vector<SinhVien> danhSachSV;
    danhSachSV.reserve(n);
    for (int i = 0; i < n; ++i) {
        SinhVien sv;
        sv.nhapThongTin();
        danhSachSV.emplace_back(sv);
    }
    if (a) {
        string hoTenCanTim;
        cin.ignore();
        getline(cin, hoTenCanTim);
        vector<string> danhSachMaSV;
        for (const SinhVien &sv: danhSachSV) {
            if (sv.hoTen == hoTenCanTim) {
                danhSachMaSV.push_back(sv.maSV);
            }
        }

        if (danhSachMaSV.empty()) {
            cout << "Khong tim thay sinh vien" << '\n';
        }
        else {
            for (const string &maSV: danhSachMaSV) {
                cout << maSV << ' ';
            }
            cout << '\n';
        }
    }
    if (b) {
        sort(danhSachSV.rbegin(), danhSachSV.rend());
        for (const SinhVien &sv: danhSachSV) {
            sv.xuatThongTin();
        }
    }

    return 0;
}

