/*
** EPITECH PROJECT, 2021
** B-PSU-402-BDX-4-1-strace-alexandre.quenelle
** File description:
** test
*/

#include <unistd.h>

int main()
{
    write(2, "Hello World\n", 13);
    return (98);
}