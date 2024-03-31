/******************************************************************************
 *  ASR => 4R2.04                                                              *
 *******************************************************************************
 *                                                                             *
 *  N° de Sujet :     2                                                        *
 *                                                                             *
 *******************************************************************************
 *                                                                             *
 *  Intitulé :Analyse d’adresses IP                                            *
 *                                                                             *
 *******************************************************************************
 *                                                                             *
 *  Nom-prénom1 :ROS Natalia                                                   *
 *                                                                             *
 *  Nom-prénom2 :HELBERT Titouan                                               *
 *                                                                             *
 *******************************************************************************
 *                                                                             *
 *  Nom du fichier :SAE2.04                                                    *
 *                                                                             *
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "analyse_ip.h"

int main()
{
    char ip[MAX_LENGTH];
    char mask[MAX_LENGTH];

    printf("Entrez une adresse IP : ");
    fgets(ip, sizeof(ip), stdin);
    ip[strcspn(ip, "\n")] = 0;

    if (isValidIPAddress(ip))
    {
        printf("L'adresse IP est valide.\n");
    }
    else
    {
        printf("L'adresse IP n'est pas valide.\n");
    }

    printf("Entrez un masque : ");
    fgets(mask, sizeof(mask), stdin);
    mask[strcspn(mask, "\n")] = 0;

    if (isValidIPMask(mask))
    {
        printf("Le masque est valide.\n");
    }
    else
    {
        printf("Le masque n'est pas valide.\n");
    }

    extractIPAddress(ip);

    return 0;
}