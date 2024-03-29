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
#include <ctype.h>
#include "analyse_ip.h"

int isValidIPAddress(char *ip)
{
    int num, dots = 0;
    char *ptr;
    char segment[MAX_LENGTH];

    if (ip == NULL || strlen(ip) == 0)
    {
        return 0;
    }

    if (strlen(ip) >= MAX_LENGTH)
    {
        return 0;
    }

    ptr = strtok(ip, ".");

    if (ptr == NULL)
    {
        return 0;
    }

    while (ptr)
    {
        for (int i = 0; i < strlen(ptr); i++)
        {
            if (!isdigit(ptr[i]))
            {
                return 0;
            }
        }
        num = atoi(ptr);
        if (num < 0 || num > 255)
        {
            return 0;
        }
        if (strlen(ptr) > 1 && ptr[0] == '0')
        {
            return 0;
        }

        dots++;
        ptr = strtok(NULL, ".");
    }
    if (dots != 4)
    {
        return 0;
    }
    return 1;
}

int isValidIPMask(char *mask)
{
    int num, dots = 0;
    char *ptr;

    if (mask == NULL || strlen(mask) == 0)
    {
        return 0;
    }

    if (strlen(mask) >= MAX_LENGTH)
    {
        return 0;
    }

    ptr = strtok(mask, ".");

    if (ptr == NULL)
    {
        return 0;
    }

    while (ptr)
    {
        for (int i = 0; i < strlen(ptr); i++)
        {
            if (!isdigit(ptr[i]))
            {
                return 0;
            }
        }

        num = atoi(ptr);

        if (dots < 3 && (num != 255 || strlen(ptr) > 3 || (strlen(ptr) > 1 && ptr[0] == '0')))
        {
            return 0;
        }

        if (dots == 3 && (num == 255 || num == 0 || strlen(ptr) > 2 || (strlen(ptr) > 1 && ptr[0] == '0')))
        {
            return 0;
        }

        dots++;
        ptr = strtok(NULL, ".");
    }

    if (dots != 4)
    {
        return 0;
    }

    return 1;
}