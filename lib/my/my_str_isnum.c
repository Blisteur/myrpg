/*
** EPITECH PROJECT, 2020
** my_str_isnum
** File description:
** task13
*/

int my_str_isnum(char const *str)
{
    for (int count = 0; str[count] != '\0'; count++) {
        if (str[count] > '9' || str[count] < '0')
            return (0);
    }
    return (1);
}