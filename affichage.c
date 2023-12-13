#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT "\x1B[0m"
#define RED "\x1B[31m"
#define YELLOW "\x1B[1;33m"
#define BOLD "1"
#define PLANE "\u2708"
#define VIDE " "
#define BWHITE "\x1B[47m"

char anim0 [161] = "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$||$$$$$$$$$$$$$$$$$$";
char anim1 [161] = "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|||$$$$$$$$$$$$$$$$$";
char anim2 [161] = "$$$#####$$$$$$##$$$########$$$####$$$$$$$$##$$$##$$$$$$$$$$$$$$$##$$$########$$$####$$$$$$$$##$$$##$$$$$$$$$##$$$#######$$$$$$$||$$$$$$$$$$$$||||$$$$$$$$$$$$$$$";
char anim3 [161] = "$$$#######$$$$$$$$$########$$$##$##$$$$$$$##$$$$##$$$$$$$$$$$$$##$$$$########$$$##$##$$$$$$$##$$$##$$$$$$$$$##$$$#######$$$$$$$||||$$$$$$$$$$$||||$$$$$$$$$$$$$$";
char anim4 [161] = "$$$##   ##$$$$##$$$##$$$$$$$$$##$$##$$$$$$##$$$$$##$$$$$$$$$$$##$$$$$##$$$$$$$$$##$$##$$$$$$##$$$##$$$$$$$$$##$$$##$$$$$$$$$$$$$$||||$$$$$$$$$$||||$$$$$$$$$$$$$";
char anim5 [161] = "$$$##   #$$$$$##$$$##$$$$$$$$$##$$$##$$$$$##$$$$$$##$$$$$$$$$##$$$$$$##$$$$$$$$$##$$$##$$$$$##$$$##$$$$$$$$$##$$$##$$$$$$$$$$$$$||||||||||||||||||||||||||||||$$";
char anim6 [161] = "$$$######$$$$$##$$$########$$$##$$$$##$$$$##$$$$$$$##$$$$$$$##$$$$$$$########$$$##$$$$##$$$$##$$$##$$$$$$$$$##$$$#######$$$$$$$|||||||||||||||||||||||||||||||||";
char anim7 [161] = "$$$##   #$$$$$##$$$##$$$$$$$$$##$$$$$##$$$##$$$$$$$$##$$$$$##$$$$$$$$##$$$$$$$$$##$$$$$##$$$##$$$##$$$$$$$$$##$$$##$$$$$$$$$$$$$||||||||||||||||||||||||||||||$$";
char anim8 [161] = "$$$##   ##$$$$##$$$##$$$$$$$$$##$$$$$$##$$##$$$$$$$$$##$$$##$$$$$$$$$##$$$$$$$$$##$$$$$$##$$##$$$##$$$$$$$$$##$$$##$$$$$$$$$$$$$$||||$$$$$$$$$$||||$$$$$$$$$$$$$";
char anim9 [161] = "$$$#######$$$$##$$$########$$$##$$$$$$$##$##$$$$$$$$$$##$##$$$$$$$$$$########$$$##$$$$$$$##$##$$$##$$$$$$$$$##$$$#######$$$$$$$$||||$$$$$$$$$$||||$$$$$$$$$$$$$$";
char anim10[161] = "$$$#####$$$$$$##$$$########$$$##$$$$$$$$####$$$$$$$$$$$###$$$$$$$$$$$########$$$##$$$$$$$$####$$$#############$$$#######$$$$$$$||$$$$$$$$$$$$||||$$$$$$$$$$$$$$$";
char anim11[161] = "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|||$$$$$$$$$$$$$$$$$";
char anim12[161] = "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$||$$$$$$$$$$$$$$$$$$$";

void dessinAeroport(int numParkG, int numParkM, int numParkP, int numTaxiG, int numTaxiM, int numTaxiP, int etatGPiste, int etatMPiste, int etatPPiste)
{

    const char *bordGpiste = "                    +-----------------------------------------------------------------------------------+\n";
    const char *milieuGPiste = "                    |                                                                                   |\n";
    char *pointillerGPiste = " %s      %s      %s    |%s%s-   -   -   -   -%s  -   -   -   -  %s-   -   -   -   -%s  -   -   -   -  %s-   -   - %s|\n"; // 23 saut 18

    char *GParking = "                      %s[%s]     [%s]     [%s]     [%s]     [%s]     [%s]     [%s]%s                               \n"; // id 25 saut 8
    char *MParking = "                      %s[%s]     [%s]     [%s]     [%s]     [%s]     [%s]     [%s]%s                               \n";
    char *PParking = "                      %s[%s]     [%s]     [%s]     [%s]     [%s]     [%s]     [%s]%s                               \n";

    const char *bordPpiste = "                                                             +------------------------------------------+\n";
    char *pointillePPiste = "     %s       %s       %s       %s       %s       %s       %s       |%s%s-   -   -%s  -   -  %s-   -   -%s  -   -  %s-%s|\n"; // 64 saut 10

    const char *BordMPiste = "                                         +--------------------------------------------------------------+\n";
    const char *milieuMPiste = "                                         |                                                              |\n";
    char *pointilleMPiste = "   %s      %s      %s      %s      %s         |%s%s-   -   -   - %s -   -   -   -%s  -   -   -  %s-   -   -   -%s  -%s|\n"; //  44  saut av 14

    for (int i = 0; i < 5; i++)
    {
        system("clear");

        char BufferParkG[117 + 15];
        char BufferParkM[117 + 15];
        char BufferParkP[117 + 15];

        char BufferGPiste[119 + 19];
        char BufferMPiste[116 + 21];
        char BufferPPiste[116 + 21];

        sprintf(BufferParkG, GParking, BWHITE,
                ((numParkG >= 7) ? PLANE : VIDE), 
                ((numParkG >= 6) ? PLANE : VIDE), 
                ((numParkG >= 5) ? PLANE : VIDE), 
                ((numParkG >= 4) ? PLANE : VIDE), 
                ((numParkG >= 3) ? PLANE : VIDE), 
                ((numParkG >= 2) ? PLANE : VIDE), 
                ((numParkG >= 1) ? PLANE : VIDE), 
                DEFAULT);

        sprintf(BufferParkM, MParking, BWHITE,
                ((numParkM >= 7) ? PLANE : VIDE), 
                ((numParkM >= 6) ? PLANE : VIDE), 
                ((numParkM >= 5) ? PLANE : VIDE), 
                ((numParkM >= 4) ? PLANE : VIDE), 
                ((numParkM >= 3) ? PLANE : VIDE), 
                ((numParkM >= 2) ? PLANE : VIDE), 
                ((numParkM >= 1) ? PLANE : VIDE), 
                DEFAULT);

        sprintf(BufferParkP, PParking, BWHITE,
                ((numParkP >= 7) ? PLANE : VIDE), 
                ((numParkP >= 6) ? PLANE : VIDE), 
                ((numParkP >= 5) ? PLANE : VIDE), 
                ((numParkP >= 4) ? PLANE : VIDE), 
                ((numParkP >= 3) ? PLANE : VIDE), 
                ((numParkP >= 2) ? PLANE : VIDE), 
                ((numParkP >= 1) ? PLANE : VIDE), 
                DEFAULT);

        if (etatGPiste == 1){
            sprintf(BufferGPiste, pointillerGPiste,
                ((numTaxiG >= 3) ? PLANE : "_"), 
                ((numTaxiG >= 2) ? PLANE : "_"), 
                ((numTaxiG >= 1) ? PLANE : "_"), 
                YELLOW, 
                ((i == 0) ? PLANE : VIDE), 
                ((i == 1) ? PLANE : VIDE), 
                ((i == 2) ? PLANE : VIDE), 
                ((i == 3) ? PLANE : VIDE), 
                ((i == 4) ? PLANE : VIDE), 
                DEFAULT);
        }
        else {
            sprintf(BufferGPiste, pointillerGPiste,
                ((numTaxiG >= 3) ? PLANE : "_"), 
                ((numTaxiG >= 2) ? PLANE : "_"), 
                ((numTaxiG >= 1) ? PLANE : "_"), 
                YELLOW, 
                VIDE, 
                VIDE, 
                VIDE, 
                VIDE, 
                VIDE, 
                DEFAULT);
        }
        
        if (etatMPiste == 1){
            sprintf(BufferMPiste, pointilleMPiste,
                ((numTaxiM >= 5) ? PLANE : "_"), 
                ((numTaxiM >= 4) ? PLANE : "_"), 
                ((numTaxiM >= 3) ? PLANE : "_"), 
                ((numTaxiM >= 2) ? PLANE : "_"), 
                ((numTaxiM >= 1) ? PLANE : "_"), 
                YELLOW, ((i == 0) ? PLANE : VIDE), 
                ((i == 1) ? PLANE : VIDE), 
                ((i == 2) ? PLANE : VIDE), 
                ((i == 3) ? PLANE : VIDE), 
                ((i == 4) ? PLANE : VIDE), 
                DEFAULT);
        }
        else {
            sprintf(BufferMPiste, pointilleMPiste,
                ((numTaxiM >= 5) ? PLANE : "_"), 
                ((numTaxiM >= 4) ? PLANE : "_"), 
                ((numTaxiM >= 3) ? PLANE : "_"), 
                ((numTaxiM >= 2) ? PLANE : "_"), 
                ((numTaxiM >= 1) ? PLANE : "_"), 
                YELLOW, ((i == 0) ? PLANE : VIDE), 
                VIDE, 
                VIDE, 
                VIDE, 
                VIDE, 
                DEFAULT);
        }
        
        if(etatPPiste == 1){
            sprintf(BufferPPiste, pointillePPiste,
                ((numTaxiP >= 7) ? PLANE : "_"), 
                ((numTaxiP >= 6) ? PLANE : "_"), 
                ((numTaxiP >= 5) ? PLANE : "_"), 
                ((numTaxiP >= 4) ? PLANE : "_"), 
                ((numTaxiP >= 3) ? PLANE : "_"), 
                ((numTaxiP >= 2) ? PLANE : "_"), 
                ((numTaxiP >= 1) ? PLANE : "_"), 
                YELLOW, 
                ((i == 0) ? PLANE : VIDE), 
                ((i == 1) ? PLANE : VIDE), 
                ((i == 2) ? PLANE : VIDE), 
                ((i == 3) ? PLANE : VIDE), 
                ((i == 4) ? PLANE : VIDE), 
                DEFAULT);
        }
        else{
            sprintf(BufferPPiste, pointillePPiste,
                ((numTaxiP >= 7) ? PLANE : "_"), 
                ((numTaxiP >= 6) ? PLANE : "_"), 
                ((numTaxiP >= 5) ? PLANE : "_"), 
                ((numTaxiP >= 4) ? PLANE : "_"), 
                ((numTaxiP >= 3) ? PLANE : "_"), 
                ((numTaxiP >= 2) ? PLANE : "_"), 
                ((numTaxiP >= 1) ? PLANE : "_"), 
                YELLOW, 
                VIDE, 
                VIDE, 
                VIDE, 
                VIDE, 
                VIDE, 
                DEFAULT);
        }
        

        printf("%s", BordMPiste);
        printf("%s", milieuMPiste);
        printf("%s", BufferMPiste);
        printf("%s", milieuMPiste);
        printf("%s", BordMPiste);
        printf("\n");
        printf("%s", bordPpiste);
        printf("%s", BufferPPiste);
        printf("%s", bordPpiste);
        printf("\n");
        printf("%s", BufferParkG);
        printf("%s", BufferParkM);
        printf("%s", BufferParkP);
        printf("\n");
        printf("%s", bordGpiste);
        printf("%s", milieuGPiste);
        printf("%s", milieuGPiste);
        printf("%s", BufferGPiste);
        printf("%s", milieuGPiste);
        printf("%s", milieuGPiste);
        printf("%s", bordGpiste);

        usleep(800000);
    }
}

void animBegining()
{
    
    char anim0 [160] = "                                                                                                                                            ||                  ";
    char anim1 [160] = "                                                                                                                                            |||                 ";
    char anim2 [160] = "   #####      ##   ########   ####        ##   ##               ##   ########   ####        ##   ##         ##   #######       ||            ||||               ";
    char anim3 [160] = "   #######         ########   ## ##       ##    ##             ##    ########   ## ##       ##   ##         ##   #######       ||||           ||||              ";
    char anim4 [160] = "   ##   ##    ##   ##         ##  ##      ##     ##           ##     ##         ##  ##      ##   ##         ##   ##              ||||          ||||             ";
    char anim5 [160] = "   ##   #     ##   ##         ##   ##     ##      ##         ##      ##         ##   ##     ##   ##         ##   ##             ||||||||||||||||||||||||||||||  ";
    char anim6 [160] = "   ######     ##   ########   ##    ##    ##       ##       ##       ########   ##    ##    ##   ##         ##   #######       |||||||||||||||||||||||||||||||||";
    char anim7 [160] = "   ##   #     ##   ##         ##     ##   ##        ##     ##        ##         ##     ##   ##   ##         ##   ##             ||||||||||||||||||||||||||||||  ";
    char anim8 [160] = "   ##   ##    ##   ##         ##      ##  ##         ##   ##         ##         ##      ##  ##   ##         ##   ##              ||||          ||||             ";
    char anim9 [160] = "   #######    ##   ########   ##       ## ##          ## ##          ########   ##       ## ##   ##         ##   #######        ||||          ||||              ";
    char anim10[160] = "   #####      ##   ########   ##        ####           ###           ########   ##        ####   #############   #######       ||            ||||               ";
    char anim11[160] = "                                                                                                                                            |||                 ";
    char anim12[160] = "                                                                                                                                           ||                   ";

    char buff0[161] = "",buff1[161] = "",buff2[161] = "",buff3[161] = "",buff4[161] = "",buff5[161] = "",buff6[161] = "",buff7[161] = "",buff8[161] = "",buff9[161] = "",buff10[161] = "",buff11[161] = "",buff12[161] = "";
    
    for (int i = 0;i < 160 ; i++){
        char buff0_0[161] = "",buff1_1[161] = "",buff2_2[161] = "",buff3_3[161] = "",buff4_4[161] = "",buff5_5[161] = "",buff6_6[161] = "",buff7_7[161] = "",buff8_8[161] = "",buff9_9[161] = "",buff10_10[161] = "",buff11_11[161] = "",buff12_12[161] = "";

        system("clear");
        
        buff0_0[0] = anim0[160-i];
        strcat(buff0_0,buff0);
        strcpy(buff0,buff0_0);
        
        buff1_1[0] = anim1[160-i];
        strcat(buff1_1,buff1);
        strcpy(buff1,buff1_1);

        buff2_2[0] = anim2[160-i];
        strcat(buff2_2,buff2);
        strcpy(buff2,buff2_2);

        buff3_3[0] = anim3[160-i];
        strcat(buff3_3,buff3);
        strcpy(buff3,buff3_3);

        buff4_4[0] = anim4[160-i];
        strcat(buff4_4,buff4);
        strcpy(buff4,buff4_4);

        buff5_5[0] = anim5[160-i];
        strcat(buff5_5,buff5);
        strcpy(buff5,buff5_5);

        buff6_6[0] = anim6[160-i];
        strcat(buff6_6,buff6);
        strcpy(buff6,buff6_6);

        buff7_7[0] = anim7[160-i];
        strcat(buff7_7,buff7);
        strcpy(buff7,buff7_7);

        buff8_8[0] = anim8[160-i];
        strcat(buff8_8,buff8);
        strcpy(buff8,buff8_8);

        buff9_9[0] = anim9[160-i];
        strcat(buff9_9,buff9);
        strcpy(buff9,buff9_9);

        buff10_10[0] = anim10[160-i];
        strcat(buff10_10,buff10);
        strcpy(buff10,buff10_10);

        buff11_11[0] = anim11[160-i];
        strcat(buff11_11,buff11);
        strcpy(buff11,buff11_11);

        buff12_12[0] = anim12[160-i];
        strcat(buff12_12,buff12);
        strcpy(buff12,buff12_12);

        printf("%s\n",buff0);
        printf("%s\n",buff1);
        printf("%s\n",buff2);
        printf("%s\n",buff3);
        printf("%s\n",buff4);
        printf("%s\n",buff5);
        printf("%s\n",buff6);
        printf("%s\n",buff7);
        printf("%s\n",buff8);
        printf("%s\n",buff9);
        printf("%s\n",buff10);
        printf("%s\n",buff11);
        printf("%s\n",buff12);
        usleep(30000);
    }
}

int menu()
{
    int choix = 0;
    while (choix < 1 || choix > 3)
    {
        system("clear");
        printf("____________________________________________________\n");
        printf("1. Charger une nouvelle base de donnée aléatoire\n");
        printf("2. Charger la base de donnée déjà existante\n");
        printf("3. Quitter\n");
        printf("____________________________________________________\n");
        printf("Votre choix: ");
        scanf("%d", &choix);
    }
    system("clear");
    return choix;
}
