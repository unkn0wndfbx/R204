/******************************************************************************
 *  ASR => 4R2.04                                                              *
 *******************************************************************************
 *                                                                             *
 *  N° de Sujet :                                                              *
 *                                                                             *
 *******************************************************************************
 *                                                                             *
 *  Intitulé :                                                                 *
 *                                                                             *
 *******************************************************************************
 *                                                                             *
 *  Nom-prénom1 :                                                              *
 *                                                                             *
 *  Nom-prénom2 :                                                              *
 *                                                                             *
 *  Nom-prénom3 :                                                              *
 *                                                                             *
 *  Nom-prénom4 :                                                              *
 *                                                                             *
 *******************************************************************************
 *                                                                             *
 *  Nom du fichier :                                                           *
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

    if (isValidIPAddress(ip))
    {
        printf("L'adresse IP est au format classique.\n");
    }
    else
    {
        printf("L'adresse IP n'est pas au format classique.\n");
    }

    return 0;
}