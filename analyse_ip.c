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
#include <ctype.h>
#include "analyse_ip.h"
#include <stdint.h>

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

    void extractIPAddress(char *ip) {
        uint8_t octet[4];
        uint32_t ip_address;

        sscanf(ip, "%hhu.%hhu.%hhu.%hhu", &octet[0], &octet[1], &octet[2], &octet[3]);
        ip_address = (octet[0] << 24) | (octet[1] << 16) | (octet[2] << 8) | octet[3];
    }