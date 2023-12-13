#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#define WIDTH 80
#define HEIGHT 20

#define DEFAULT "\x1B[0m"
#define RED "\x1B[31m"
#define YELLOW "\x1B[1;33m"
#define BOLD "1"
#define PLANE "\x1B[1;37m \u2708 \x1B[0m"
#define BWHITE "\x1B[47m"

enum categorie
{
    ligne = 1,
    affaire,
    leger
};
enum etat
{
    vol,
    sol
};
enum categoriePiste
{
    petite = 1,
    moyenne,
    grande
};

void dessinAeroport(int numParkG, int numParkM, int numParkP, int numTaxiG, int numTaxiM, int numTaxiP, int etatGPiste, int etatMPiste, int etatPPiste);
void animBegining();
int menu();

#endif
