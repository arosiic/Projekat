#include <bits/stdc++.h>
using namespace std;

int nimSum(vector<int>& piles) {
    int s = 0;
    for (int x : piles)
        s ^= x;
    return s;
}

void printPiles(vector<int>& piles) {
    cout << "\nGomile:\n";
    for (int i = 0; i < piles.size(); i++)
        cout << i + 1 << ": " << piles[i] << endl;
}

bool gameOver(vector<int>& piles) {
    for (int x : piles)
        if (x > 0) return false;
    return true;
}

int main() {
    int n;
    cout << "Broj gomila: ";
    cin >> n;

    vector<int> piles(n);

    for (int i = 0; i < n; i++) {
        cout << "Elementi u gomili " << i + 1 << ": ";
        cin >> piles[i];
    }

    while (true) {

        printPiles(piles);

        int pile, take;
        cout << "\nTvoj potez\n";
        cout << "Gomila: ";
        cin >> pile;

        cout << "Koliko uzimas: ";
        cin >> take;

        piles[pile - 1] -= take;

        if (gameOver(piles)) {
            cout << "\nPobedio si!\n";
            break;
        }

        int x = nimSum(piles);

        if (x == 0) {
            for (int i = 0; i < n; i++) {
                if (piles[i] > 0) {
                    piles[i]--;
                    cout << "\nRacunar uzima 1 iz gomile "
                         << i + 1 << endl;
                    break;
                }
            }
        }
        else {
            for (int i = 0; i < n; i++) {
                int target = piles[i] ^ x;

                if (target < piles[i]) {
                    int take = piles[i] - target;
                    piles[i] = target;

                    cout << "\nRacunar uzima "
                         << take
                         << " iz gomile "
                         << i + 1 << endl;
                    break;
                }
            }
        }

        if (gameOver(piles)) {
            cout << "\nRacunar je pobedio!\n";
            break;
        }
    }
}
