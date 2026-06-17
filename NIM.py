def prikazi(gomile):
    print("\nGomile:")
    for i, x in enumerate(gomile):
        print(f"{i+1}: {'|' * x} ({x})")


def nim_sum(gomile):
    s = 0
    for x in gomile:
        s ^= x
    return s


while True:

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
            print("\nPobedio si!")
            break

        x = nim_sum(gomile)

        if x == 0:
            for i in range(n):
                if gomile[i] > 0:
                    gomile[i] -= 1
                    print(
                        f"\nRacunar uzima 1 iz gomile {i+1}"
                    )
                    break
        else:
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
            print("\nRacunar je pobedio!")
            break

    break
