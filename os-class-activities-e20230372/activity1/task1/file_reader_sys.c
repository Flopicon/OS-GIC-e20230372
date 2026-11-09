#include <fcntl.h>
#include <unistd.h>

int main() {
    char buffer[256];

    // 1. Open the file for reading
    int fd = open("output.txt", O_RDONLY);

    if (fd < 0) {
        const char *err = "Error opening file\n";
        write(2, err, 20);
        return 1;
    }

    // 2. Read and display the file contents
    ssize_t bytesRead;

    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
        write(1, buffer, bytesRead);
    }

    // 3. Close the file
    close(fd);

    return 0;
}
