#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <rhash.h>

#include "config.h"

#ifdef HAVE_LIBREADLINE
    #include <readline/readline.h>
    #include <readline/history.h>
#endif

void parse_input(char**line) {
    free(*line);
#ifndef HAVE_LIBREADLINE
    printf("> ");
    size_t len = 0;
    int count = getline(line, &len, stdin);
    if (count <= 0)
        *line = NULL;
    else if ((*line)[count-1] == '\n')
        (*line)[count-1] = '\0';
#else
    *line = readline("> ");
    if (*line && **line)
        add_history(*line);
#endif
}

int main(int argc, const char **argv) {
    char* line = NULL;
    unsigned char digest[64];
    char output[130];
    rhash_library_init();
    while (1) {
        parse_input(&line);
        if (line == NULL)
            break;
        char* algorithm = strtok(line, " ");
        char* input = strtok(NULL, " ");
        if (algorithm == NULL || input == NULL) {
            fprintf(stderr, "Bad input arguments\n");
            continue;
        }
        int base64 = islower(algorithm[0]) ? RHPR_BASE64 : RHPR_HEX;
        for(int i = 0; algorithm[i]; i++) {
            algorithm[i] = tolower(algorithm[i]);
        }
        unsigned hash;
        if (!strcmp(line, "sha1"))
            hash = RHASH_SHA1;
        else if (!strcmp(line, "tth"))
            hash = RHASH_TTH;
        else if (!strcmp(line, "md5"))
            hash = RHASH_MD5;
        else {
            fprintf(stderr, "Wrong hash algorithm\n");
            continue;
        }
        int result;;
        if (input[0] == '"')
            result = rhash_msg(hash, &input[1], strlen(input)-1, digest);
        else
            result = rhash_file(hash, input, digest);
        if (result < 0) {
            fprintf(stderr, "Bad input string or file\n");
            continue;
        }
        rhash_print_bytes(output, digest, rhash_get_digest_size(hash), (base64));
        printf("%s\n", output);
    }
    free(line);
}