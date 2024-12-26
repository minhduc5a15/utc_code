Thành phố quy hoạch lại giao thông đường sắt cần phải tháo dỡ đường ray để chuyển thành đường bộ. Theo đặc thù nên đường ray sẽ được tháo ra thành các đoạn có độ dài theo đúng thứ tự là a1, a2,..., an từ trái sang phải. Chi phí để tháo một đoạn thành 2 bằng đúng độ dài đoạn đó. Thứ tự các đoạn ray tháo ra phải đảm bảo nhưng cách tháo tùy theo bạn. Bạn hãy tư vấn tháo ra sao cho tổng chi phí ít nhất.

Ví dụ: Đường ray dài 24 đơn vị độ dài cần tách ra thành các đoạn độ dài 4, 6, 3 và 11 đơn vị độ dài:

Tháo dỡ từ trái sang phải chi phí:

• 24 tách thành 4 và 20, chi phí 24.

• 20 tách thành 6 và 14, chi phí 20.

• 14 tách thành 3 và 11, chi phí 14.

Tổng chi phí: 58

Một cách khác

• 24 tách thành 13 và 11, chi phí 24.

• 13 tách thành 4 và 9, chi phí 13.

• 9 tách thành 6 và 3, chi phí 9.

Tổng chi phí: 46

Input
Dòng đầu chứa số nguyên dương n (1 ≤ n ≤ 100)

Dòng sau chứa n số nguyên dương a1, a2, ..., an, có tổng không vượt quá 10^5

Output:
Một số nguyên duy nhất là chi phí nhỏ nhất tìm được.

Ví dụ:
input:
4
4 6 3 11
output:
46