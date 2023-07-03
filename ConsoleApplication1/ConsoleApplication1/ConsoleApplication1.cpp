#include <iostream>
using namespace std;

int CountCows(int n, int k) {
    if (k == 0) {
        return n; // Số lượng bò sau 0 lượt là số bò ban đầu
    }
    int count_k_minus_1 = CountCows(n, k - 1);
    int count_k_minus_3 = (k >= 3) ? CountCows(n, k - 3) : 0;
    int count_k = count_k_minus_1 + count_k_minus_1 / 2 - count_k_minus_3 / 2;
    return count_k;
}

int main() {
    int n, k;
    cout << "Enter the number of adult cows: ";
    cin >> n;
    cout << "Enter the number of turns: ";
    cin >> k;

    int result = CountCows(n, k);
    cout << "The number of cows after " << k << " turns: " << result << endl;

    return 0;
}
