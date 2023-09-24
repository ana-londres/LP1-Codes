#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        if (A[i] != 0) {
            for (int j = i + 1; j < N; j++) {
                if (A[i] == A[j]) {
                    A[j] = 0;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (A[i] != 0) {
            cout << A[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
