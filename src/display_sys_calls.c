/*
** EPITECH PROJECT, 2021
** B-PSU-402-BDX-4-1-strace-alexandre.quenelle
** File description:
** display_sys_calls
*/

#include "sys_calls.h"
#include "strace.h"

void check_registers(struct user_regs_struct regs, int i, int pid)
{
    switch (i) {
        case 0:
        if (sym_table[regs.orig_rax].arg1 == CHAR_S)
            print_char_regs(regs, pid, regs.rdi);
        else
            printf("%lld", regs.rdi);
        break;
        case 1:
        if (sym_table[regs.orig_rax].arg2 == CHAR_S)
            print_char_regs(regs, pid, regs.rsi);
        else
            printf("%lld", regs.rsi);
        break;
        case 2:
        if (sym_table[regs.orig_rax].arg3 == CHAR_S)
            print_char_regs(regs, pid, regs.rdx);
        else
            printf("%lld", regs.rdx);
        break;
    }
    check_registers_bis(regs, i, pid);
}

void check_registers_bis(struct user_regs_struct regs, int i, int pid)
{
    switch (i) {
        case 3:
        if (sym_table[regs.orig_rax].arg4 == CHAR_S)
            print_char_regs(regs, pid, regs.r10);
        else
            printf("%lld", regs.r10);
        break;
        case 4:
        if (sym_table[regs.orig_rax].arg5 == CHAR_S)
            print_char_regs(regs, pid, regs.r8);
        else
            printf("%lld", regs.r8);
        break;
        case 5:
        if (sym_table[regs.orig_rax].arg6 == CHAR_S)
            print_char_regs(regs, pid, regs.r9);
        else
            printf("%lld", regs.r9);
        break;
    }
}

void print_sys_call_params(struct user_regs_struct regs, int pid, bool flag_s)
{
    for (int i = 0; i != sym_table[regs.orig_rax].nb_arg;){
        if (flag_s == false)
            print_registers(regs, i, pid);
        else
            check_registers(regs, i, pid);
        i++;
        if (i != sym_table[regs.orig_rax].nb_arg)
            printf(", ");
    }
    if (flag_s == false)
        printf(") = 0x%lx\n", regs.rax);
    else
        printf(") = %lld\n", regs.rax);
}

int get_regs(int pid, char **argv, char *file_path, char **envp)
{
    struct user_regs_struct regs;
    bool flag_s = false;

    if (strcmp(argv[1], "-s") == 0)
        flag_s = true;

    if (ptrace(PTRACE_GETREGS, pid, NULL, &regs) != 0)
        return -1;
    if (regs.orig_rax != -1){
        printf("%s(", sym_table[regs.orig_rax].str);
        if (regs.orig_rax == 59){
            print_execve(file_path, envp);
            if (strcmp(argv[1], "-s") == 0)
                printf("%lx\n", regs.rax);
            else
                printf("0x%lx\n", regs.rax);
        } else
            print_sys_call_params(regs, pid, flag_s);
    }
    return 0;
}