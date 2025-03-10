#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int t; cin >> t;
    int x1, x2, y1, y2, cnt;
    while(t--)
    {
        cnt = 0;
        cin >> x1 >> x2 >> y1 >> y2;
        
        cnt += (((x1 >= y1) && (x2 > y2)) || ((x2 >= y2) && (x1 > y1)));
        cnt += (((x1 >= y2) && (x2 > y1)) || ((x2 >= y1) && (x1 > y2)));
        
        cout << cnt * 2 << "\n";
    }
    return 0;
}