#include <iostream>
#include <vector>
using namespace std;

class Article {
public:
    string name;
    int publish_year;
    int quality;

    Article() {}

    Article(string name, int publish_year, int quality): name(name), publish_year(publish_year), quality(quality) {}

};

void swap(Article &a, Article &b) {
    Article temp = a;
    a = b;
    b = temp;
}

int partition(vector<Article> &articles, int low, int high) {
    Article pivot = articles[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if ((articles[j].quality > pivot.quality) or (articles[j].quality == pivot.quality && articles[j].publish_year > pivot.publish_year)) {
            i++;
            swap(articles[i], articles[j]);
        }
    }
    swap(articles[i + 1], articles[high]);
    return i + 1;
}

void quickSort(vector<Article> &articles, int low, int high) {
    if (low < high) {
        int pi = partition(articles, low, high);
        quickSort(articles, low, pi - 1);
        quickSort(articles, pi + 1, high);
    }
}

int main() {
    cout << "Nhập số lượng bài báo: ";
    int n;
    cin >> n;
    vector<Article> articles(n);

    for (int i = 0; i < n; ++i) {
        cout << "Nhập thông tin bài báo " << i + 1 << ":\n";
        cout << "Tên bài báo: ";
        cin.ignore();
        getline(cin, articles[i].name);
        cout << "Năm xuất bản: ";
        cin >> articles[i].publish_year;
        cout << "Số tham khảo: ";
        cin >> articles[i].quality;
    }

    quickSort(articles, 0, n - 1);
    cout << "\nDanh sách bài báo sau khi sắp xếp:\n";

    for (const Article &article: articles) {
        cout << "Tên bài báo: " << article.name << ", Năm xuất bản: " << article.publish_year << ", Số tham khảo: " << article.quality << '\n';
    }
    return 0;
}
