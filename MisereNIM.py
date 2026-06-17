def prikazi(gomile):
    print("\nGomile:")
    for i, x in enumerate(gomile):
        print(f"{i+1}: {'|' * x} ({x})")


def nim_sum(gomile):
    s = 0
    for x in gomile:
        s ^= x
    return s


n = int(input("Broj gomila: "))

gomile = []

for i in range(n):
    gomile.append(
        int(input(f"Gomila {i+1}: "))
    )

while sum(gomile) > 0:

    prikazi(gomile)

    g = int(input("\nIzaberi gomilu: ")) - 1
    k = int(input("Koliko uzimas: "))

    gomile[g] -= k

    if sum(gomile) == 0:
        print("\nIzgubio si! Uzeo si poslednji element.")
        break

    ones = sum(1 for x in gomile if x == 1)
    big = sum(1 for x in gomile if x > 1)

    if big == 0:

        for i in range(n):
            if gomile[i] > 0:
                gomile[i] = 0
                print(
                    f"\nRacunar uklanja gomilu {i+1}"
                )
                break

    else:

        x = nim_sum(gomile)

        for i in range(n):
            target = gomile[i] ^ x

            if target < gomile[i]:
                take = gomile[i] - target
                gomile[i] = target

                print(
                    f"\nRacunar uzima {take} iz gomile {i+1}"
                )
                break

    if sum(gomile) == 0:
        print("\nRacunar je izgubio.")
        print("Pobedio si!")
        break
