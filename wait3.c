// #include <readline/history.h>
// #include <readline/readline.h>
// #include <unistd.h>
// #include <stdlib.h>

// int main(int argc, char **argv, char **envp) {
// 	(void)argc;
// 	(void)argv;
// 	(void)envp;

// 	char *line;
// 	char *args[] = {"arg[0]", NULL};
// 	char str[100];
//     while (1)
// 	{
// 		line =  readline("Minishell$: ");
// 		if (chdir(line) == 0) {
// 			printf("Current working directory changed successfully.\n");
// 			getcwd(str, sizeof(str));
// 			printf("%s\n", str);
// 		} else {
// 			perror("chdir");
// 			return 1;
// 		}
// 		free(line);
// 	}
// 	return (0);
// }
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>

int main() {
    const char *filename = "file.txt";
    int fd = open(filename, O_RDONLY);
	int new_fd = 0;
    if (fd == -1) {
        perror("open");
        return 1;
    }
    struct stat fileStat;
    if (fstat(fd, &fileStat) == 0) {
		printf("The file descriptor number is %i\n", fd);
        printf("File Size: %lld bytes\n", (long long)fileStat.st_size);
        printf("Permissions: %o\n", fileStat.st_mode & 0777);
        printf("Last Modified Time: %s", ctime(&fileStat.st_mtime));
    } else {
        perror("fstat");
        return 1;
    }

    close(fd);

    return 0;
}
