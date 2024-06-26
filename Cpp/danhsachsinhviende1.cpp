#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Student {
public:
    string name;
    string id;

    Student(string id, string name) {
        this->id = std::move(id);
        this->name = std::move(name);
    }
};

class Score: public Student {
public:
    double gpa;

    Score(string id, string name, double gpa): Student(std::move(id), std::move(name)) {
        this->gpa = gpa;
    }
};

string getRank(double gpa) {
    if (gpa >= 3.6) return "Xuat sac";
    if (gpa >= 3.2) return "Gioi";
    if (gpa >= 2.5) return "Kha";
    if (gpa >= 2.0) return "Trung binh";
    return "Yeu";
}

bool compare(const Student &a, const Student &b) {
    return a.name != b.name ? a.name < b.name : a.id < b.id;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a, b, n;
    cin >> a >> b >> n;
    vector<Score> students;
    students.reserve(n);
    for (int i = 0; i < n; ++i) {
        string id, name;
        double gpa;
        cin >> id;
        cin.ignore();
        getline(cin, name);
        cin >> gpa;
        students.emplace_back(Score(id, name, gpa));
    }
    string searchId;
    cin >> searchId;
    if (a) {
        bool found = false;
        for (const Score &s: students) {
            if (s.id == searchId) {
                cout << s.id << " - " << s.name << " - " << s.gpa << " - " << getRank(s.gpa) << '\n';
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Khong tim thay sinh vien\n";
        }
    }

    if (b) {
        sort(students.begin(), students.end(), compare);
        for (const Score &s: students) {
            cout << s.id << " - " << s.name << " - " << s.gpa << " - " << getRank(s.gpa) << '\n';
        }
    }
    return 0;
}
