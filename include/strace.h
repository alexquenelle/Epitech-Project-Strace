/*
** EPITECH PROJECT, 2021
** B-PSU-402-BDX-4-1-strace-alexandre.quenelle
** File description:
** test
*/

#ifndef TEST_H_
#define TEST_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ptrace.h>
#include <errno.h>
#include <sys/user.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/stat.h>

char *args_manager(int pid, int argc, char **argv);
void display_usage(void);
void print_sys_call_params(struct user_regs_struct regs, int pid, bool flag_s);
int get_regs(int pid, char **argv, char *file_path, char **envp);
void check_file(char *file_path);
void print_registers(struct user_regs_struct regs, int i, int pid);
void print_char_regs(struct user_regs_struct regs, int pid, long addr);
void check_registers(struct user_regs_struct regs, int i, int pid);
void print_registers_flag_s(struct user_regs_struct regs, int i, int pid);
void check_registers_bis(struct user_regs_struct regs, int i, int pid);
void print_execve(char *file_path, char **envp);
void print_exit_group(int status, char **argv);

#endif /* !TEST_H_ */