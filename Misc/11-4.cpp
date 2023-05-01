#include <iostream>
#include <vector>
using namespace std;
//wrong

string findWinner(vector<int>& a) {
    int n = a.size();
    int vidya_score = 0;
    int hom_score = 0;
    int turn = 1; // 1 for Vidyateja, -1 for Hom
    int i = 0;
    int j = n - 1;
    while (i <= j) {
        if (turn == 1) {
            if (a[i] >= a[j]) {
                vidya_score += a[i];
                i++;
            } else {
                vidya_score += a[j];
                j--;
            }
        } else {
            if (a[i] >= a[j]) {
                hom_score += a[i];
                i++;
            } else {
                hom_score += a[j];
                j--;
            }
        }
        turn *= -1;
    }

    if (vidya_score >= hom_score) {
        return "Vidyateja";
    } else {
        return "Hom";
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << findWinner(a) << endl;

    return 0;
}