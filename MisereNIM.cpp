#include <bits/stdc++.h>
using namespace std;

int nimSum(vector<int>& piles) {
    int s = 0;
    for (int x : piles)
        s ^= x;
    return s;
}

bool gameOver(vector<int>& piles) {
    for (int x : piles)
        if (x > 0) return false;
    return true;
}

void printPiles(vector<int>& piles) {
    cout << "\nGomile:\n";
    for (int i = 0; i < piles.size(); i++)
        cout << i + 1 << ": " << piles[i] << endl;
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
        cin >> pile >> take;

        piles[pile - 1] -= take;

        if (gameOver(piles)) {
            cout << "\nIzgubio si (uzeo si poslednji element).\n";
            break;
        }

        int ones = 0;
        int big = 0;

        for (int x : piles) {
            if (x == 1) ones++;
            if (x > 1) big++;
        }

        if (big == 0) {

            int nonzero = ones;

            int remove = (nonzero % 2 == 0) ? 1 : 0;

            if (remove == 0) {
                for (int i = 0; i < n; i++)
                    if (piles[i]) {
                        piles[i] = 0;
                        cout << "\nRacunar uzima celu gomilu "
                             << i + 1 << endl;
                        break;
                    }
            } else {
                for (int i = 0; i < n; i++)
                    if (piles[i]) {
                        piles[i] = 0;
                        cout << "\nRacunar uzima celu gomilu "
                             << i + 1 << endl;
                        break;
                    }
            }
        }
        else {

            int x = nimSum(piles);

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
            cout << "\nRacunar je izgubio.\n";
            cout << "Pobedio si!\n";
            break;
        }
    }
}
