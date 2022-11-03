#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum mois {jan=1, fev, mars, avr, mai, juin, juil, aou, sep, oct, nov, dec};
enum jour {dim, lun, mar, mer, jeu, ven, sam};

int main(int argc, char* argv[])
{
    int doomday, jour;
    int namj[3];
    int len;
    int i, temp, indexnamj;
    int siecle, ansiecle, bissextile;
    char str[12];

    if (argc == 1) {
      printf("veuillez entrer la date voulue selon le format aaaa/mm/jj (ou aa-m-j ou un mélange des deux)\n");
      fgets(str, 11, stdin); //On considere que la date ne sera jamais plus longue que 11 charactere
    } else {
      strcpy(str, argv[1]);
    }

    len = strlen(str);
    indexnamj = 0;
    temp = 0;

    for (i = 0; i< len; i++) {

        switch (str[i]) {
            case '/' :namj[indexnamj] = temp; indexnamj++;temp = 0;break;
            case '-' :namj[indexnamj] = temp; indexnamj++;temp = 0;break;
            case '0' : temp = 10 * temp + str[i] - '0'; break; //la boucle va lire tout les caractere de la chaine donnée, si c'est un chiffre elle va concatener celui
            case '1' : temp = 10 * temp + str[i] - '0'; break; //là à la valeur temporaire, si c'est un / ou un -, elle enregistre le nombre temporaire dans l'index adéquat
            case '2' : temp = 10 * temp + str[i] - '0'; break;
            case '3' : temp = 10 * temp + str[i] - '0'; break;
            case '4' : temp = 10 * temp + str[i] - '0'; break;
            case '5' : temp = 10 * temp + str[i] - '0'; break;
            case '6' : temp = 10 * temp + str[i] - '0'; break;
            case '7' : temp = 10 * temp + str[i] - '0'; break;
            case '8' : temp = 10 * temp + str[i] - '0'; break;
            case '9' : temp = 10 * temp + str[i] - '0'; break;
        }
    }
    //Ce for sert à interprete la date donné, en stockant l'annee dans namj[0] et ainsi de suite

    namj[2] = temp;

    if (namj[0]<100 && namj>=0) {
        namj[0] += 2000;
    }

    /* printf("la saisie a été interpreté en tant que %04d-%02d-%02d\n", namj[0], namj[1], namj[2]); */

    siecle = namj[0]/100;
    ansiecle = namj[0]- 100 * siecle;
    doomday = 0;

    if (siecle%4 == 0) {
        doomday += 2;
    }
    if (siecle%4 == 3) {
        doomday += 3;
    }
    if (siecle%4 == 1) {
        doomday +=0;
    }
    if (siecle%4 == 2) {
        doomday += 5;
    }

    doomday += ansiecle/12;

    doomday += ansiecle%12;

    doomday += (ansiecle%12)/4;

    doomday = doomday%7;

    //printf("le doomday est %d", doomday);

    if (namj[0]%4==0 && (namj[0]%100 != 0 || namj[0]%400 == 0) ) {
        bissextile = 1;
    } else {
        bissextile = 0;
    }

    switch (namj[1]) {
        case jan : jour = namj[2] - (3 + bissextile);break;
        case fev : jour = namj[2] - (28 + bissextile);break;
        case mars : jour = namj[2] - (14);break;
        case avr : jour = namj[2] - (4);break;
        case mai : jour = namj[2] - (9);break;
        case juin : jour = namj[2] - (6);break;
        case juil : jour = namj[2] - (11);break;
        case aou : jour = namj[2] - (8);break;
        case sep : jour = namj[2] - (5);break;
        case oct: jour = namj[2] - (10);break;
        case nov: jour = namj[2] - (7);break;
        case dec: jour = namj[2] - (12);break;
    }

    //printf("le jour est %d", jour);

    jour += doomday;
    jour = jour%7;

    if (jour < 0) {
        jour = 7+jour;
    }

    switch (jour) {
        case lun : printf("lundi\n"); break;
        case mar : printf("mardi\n"); break;
        case mer : printf("mercredi\n"); break;
        case jeu : printf("jeudi\n"); break;
        case ven : printf("vendredi\n"); break;
        case sam : printf("samedi\n"); break;
        case dim : printf("dimanche\n"); break;
    }

    return 0;
}
