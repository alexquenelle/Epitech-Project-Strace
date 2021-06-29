/*
** EPITECH PROJECT, 2021
** B-PSU-400-BDX-4-1-malloc-alexandre.quenelle
** File description:
** main
*/

#include "strace.h"

int main(int argc, char ** argv, char **envp)
{
    pid_t pid;
    int status;
    int value;
    char *file_path = args_manager(pid, argc, argv);

    pid = fork();
    if (pid == 0) {
        ptrace(PTRACE_TRACEME, 0, 0, 0);
        execvp(file_path, argv + 1);
    } else {
        waitpid(pid, &status, 0);
        while (1) {
            if (get_regs(pid, argv, file_path, envp) != 0)
                break;
            ptrace(PTRACE_SINGLESTEP, pid, 0, 0);
            waitpid(pid, &status, 0);
        }
        print_exit_group(status, argv);
        printf("+++ exited with %d +++", WEXITSTATUS(status));
    }
    return 0;
}