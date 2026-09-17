#include "stuff.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

int main(void) {
    FILE *file;
    char  buffer[BUFFER_SIZE];

    file = fopen("./assets/Lorem ipsum.txt", "r");
    if (file == NULL) {
        perror("ERROR opening file");
        return EXIT_FAILURE;
    }

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    fclose(file);

    return EXIT_SUCCESS;
}
