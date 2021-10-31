#include <stdio.h>
#include <string.h>
#include <sys/stat.h>


int main(int argc, char* argv[]) {
    enum errors {
        argc_error = 1,
        input_delete_error,
        output_delete_error,
        input_open_error,
        output_open_error,
        read_write_error,
    };
    if (argc != 3) {
        printf("Wrong number of arguments\n");
        return argc_error;
    }

    if (!strcmp(argv[1], argv[2]))
        return 0;

    FILE *source_file, *target_file;
    if ((source_file = fopen(argv[1], "r")) == NULL) {
        printf("The input file cannot be opened\n");
        return input_open_error;
    }

    struct stat path_stat;
    if (!stat(argv[2], &path_stat) && remove(argv[2])) {
        printf("Error deleting output file\n");
        return output_delete_error;
    }

    if ((target_file = fopen(argv[2], "w")) == NULL) {
        fclose(source_file);
        printf("The output file cannot be opened\n");
        return output_open_error;
    }

    char c, status;
    while ((c = fgetc(source_file)) != EOF)
        status = fputc(c, target_file);

    if (!feof(source_file) || fclose(target_file)) {
        printf("Read-write error\n");
        fclose(source_file);
        remove(argv[2]);
        return read_write_error;
    }
    fclose(source_file);
    if (remove(argv[1])) {
        printf("Error deleting input file\n");
        remove(argv[2]);
        return input_delete_error;
    }
    return 0;
}
