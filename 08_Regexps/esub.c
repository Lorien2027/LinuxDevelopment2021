#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <ctype.h>

#define PM 10

int main(int argc, const char **argv) {
    if (argc != 4) {
        printf("usage: regexp substitution string\n");
        exit(1);
    }
    const char *exp = argv[2];
    const char *string = argv[3];
    regex_t regex;
    regmatch_t match[PM];

    char msg[256];
    int status = regcomp(&regex, argv[1], REG_EXTENDED);
    if (status) {
        regerror(status, &regex, msg, sizeof(msg));
        fprintf(stderr, "Regex compilation failed: %s\n", msg);
        regfree(&regex);
        exit(1);
    }
    status = regexec(&regex, string, PM, match, 0);
    if (status) {
        if (status == REG_NOMATCH) {
            printf("%s\n", string);
            regfree(&regex);
            exit(0);
        }
        else {
            regerror(status, &regex, msg, sizeof(msg));
            fprintf(stderr, "Regex match failed: %s\n", msg);
            regfree(&regex);
            exit(1);
        }
    }
    printf("%.*s", match[0].rm_so, string);
    int last_pos = 0;
    int backslash = 0;
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '\\' && !backslash) {
            printf("%.*s", i - last_pos, exp + last_pos);
            backslash = 1;
            last_pos = i + 2;
        }
        else if (backslash) {
            backslash = 0;
            char c = '\0';
            switch (exp[i]) {
                case '\\':
                    c = '\\';
                    break;
                case 't':
                    c = '\t';
                    break;
                case 'n':
                    c = '\n';
                    break;
                case 'b':
                    c = '\b';
                    break;
                case 'r':
                    c = '\r';
                    break;
            }
            if (c == '\0') {
                if (!isdigit(exp[i])) {
                    fprintf(stderr, "Substitution string error\n");
                    regfree(&regex);
                    exit(1);
                }
                int pos = exp[i] - '0';
                if (!pos || match[pos].rm_so == -1) {
                    fprintf(stderr, "Undefined position reference\n");
                    regfree(&regex);
                    exit(1);
                }
                printf("%.*s", match[pos].rm_eo - match[pos].rm_so, string + match[pos].rm_so);
            }
            else
                putchar(c);
        }
    }
    if (backslash) {
        fprintf(stderr, "Substitution string error\n");
        regfree(&regex);
        exit(1);
    }
    printf("%s", exp + last_pos);
    printf("%s\n", string + match[0].rm_eo);
}