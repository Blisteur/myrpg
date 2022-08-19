/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** task03
*/
#include <stdio.h>

char *my_revstr(char *str)
{
    int count = 0;
    int countmax;
    int countmin = 0;
    char temp;

    for (count = 0; str[count] != '\0'; count++);
    countmax = count - 1;
    count = count / 2;
    while (count >= 0) {
        temp = str[countmin];
        str[countmin] = str[countmax];
        str[countmax] = temp;
        count--;
        countmax--;
        countmin++;
    }
    return (str);
}