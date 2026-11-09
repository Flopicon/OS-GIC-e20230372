#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>

int main() {
    char buffer[512];

    // 1. Open current directory
    DIR *dir = opendir(".");

    if (dir == NULL) {
        const char *err = "Error opening directory\n";
        write(2, err, strlen(err));
        return 1;
    }

    struct dirent *entry;
    struct stat fileStat;

    // 2. Print table header using write()
    const char *header = "Filename                       Size (bytes)\n";
    const char *separator = "------------------------------ ----------\n";

    write(1, header, strlen(header));
    write(1, separator, strlen(separator));

    // 3. Read directory entries
    while ((entry = readdir(dir)) != NULL) {

        // 4. Get file information
        if (stat(entry->d_name, &fileStat) == 0) {

            // 5. Format output and print using write()
            int len = snprintf(buffer, sizeof(buffer),
                               "%-30s %10ld\n",
                               entry->d_name,
                               (long)fileStat.st_size);

            write(1, buffer, len);
        }
    }

    // 6. Close directory
    closedir(dir);

    return 0;
}
