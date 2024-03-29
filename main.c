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

    printf("Entrez une adresse IP : ");
    fgets(ip, sizeof(ip), stdin);
    ip[strcspn(ip, "\n")] = 0;

    printf("L'adresse IP est : %s\n", ip);

    printf("L'adresse IP : %d\n", isValidIPAddress(ip));

    if (isValidIPAddress(ip))
    {
        printf("L'adresse IP est au format classique.\n");
    }
    else
    {
        printf("L'adresse IP n'est pas au format classique.\n");
    }

    // Exemple d'une adresse IP sous forme de tableau de caractères
    char ip[] = "192.168.1.1";

    // Extraction et affichage des champs de l'adresse IP
    extractIPAddressFields(ip);

    return 0;

    return 0;
}