#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <libintl.h>
#include <locale.h>
#include <string.h>
#include "config.h"

#define _(STRING) gettext(STRING)
#define LOCALE_PATH "po"

int main(int argc, char **argv) {
    setlocale(LC_ALL, "");
    bindtextdomain(PACKAGE, LOCALE_PATH);
    textdomain(PACKAGE);

    printf(_("Guess a number from 0 to 100.\n"));
    int lower = 1;
    int upper = 100;
    int middle = (lower + upper) / 2;
    char *yes_answer = _("yes");
    char *no_answer = _("no");
    char answer[64];
    while (lower < upper) {
        printf(_("Is the number greater than %d (yes or no)?\n"), middle);
        scanf("%s", answer);
        if (!strcmp(answer, yes_answer)) {
            lower = middle + 1;
            middle = (lower + upper) / 2;
        }
        else if (!strcmp(answer, no_answer)) {
            upper = middle;
            middle = (lower + upper) / 2;
        }
        else {
            printf(_("Wrong answer\n"));
            continue;
        }
    }
    printf(_("The correct number is %d\n"), upper);
    return 0;
}
