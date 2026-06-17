# NIM 
NIM je matematička igra u kojoj postoji nekoliko gomila elemenata. Dva igrača naizmenično uzimaju proizvoljan broj elemenata iz jedne izabrane gomile. Pobeđuje igrač koji uzme poslednji element.

Računar koristi NIM sumu, odnosno XOR svih veličina gomila. Ako je NIM suma različita od nule, postoji potez kojim može da se dovede na nulu. Takva pozicija je nepovoljna za protivnika. Zbog toga računar uvek bira potez kojim nakon svog poteza NIM suma postaje 0.

# Misère NIM

Misère NIM ima ista pravila kao običan NIM, osim što gubi igrač koji uzme poslednji element.

Dok postoji bar jedna gomila sa više od jednog elementa, koristi se ista strategija kao kod običnog NIM-a. Kada sve gomile sadrže po jedan element, strategija se menja kako bi protivnik bio primoran da uzme poslednji element i izgubi.
