/** @file number.c
 * Guesses a number from 1 to 100 with support for Roman numbers.
*/

#include <stdio.h>
#include <libintl.h>
#include <locale.h>
#include <string.h>
#include "config.h"

#define _(STRING) gettext(STRING)
#define LOCALE_PATH "po"

static char *roman_numbers[100] = {
    "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X", "XI", "XII", "XIII", "XIV", "XV",
    "XVI", "XVII", "XVIII", "XIX", "XX", "XXI", "XXII", "XXIII", "XXIV", "XXV", "XXVI", "XXVII", "XXVIII",
    "XXIX", "XXX", "XXXI", "XXXII", "XXXIII", "XXXIV", "XXXV", "XXXVI", "XXXVII", "XXXVIII", "XXXIX", "XL",
    "XLI", "XLII", "XLIII", "XLIV", "XLV", "XLVI", "XLVII", "XLVIII", "XLIX", "L", "LI", "LII", "LIII",
    "LIV", "LV", "LVI", "LVII", "LVIII", "LIX", "LX", "LXI", "LXII", "LXIII", "LXIV", "LXV", "LXVI", "LXVII",
    "LXVIII", "LXIX", "LXX", "LXXI", "LXXII", "LXXIII", "LXXIV", "LXXV", "LXXVI", "LXXVII", "LXXVIII",
    "LXXIX", "LXXX", "LXXXI", "LXXXII", "LXXXIII", "LXXXIV", "LXXXV", "LXXXVI", "LXXXVII", "LXXXVIII",
    "LXXXIX", "XC", "XCI", "XCII", "XCIII", "XCIV", "XCV", "XCVI", "XCVII", "XCVIII", "XCIX", "C"
};

/** Converts a number to the Roman numeral system
 *
 * @param number value for conversion
 */
char* number_to_roman(int number) {
    return roman_numbers[number-1];
}

/** Converts from the Roman numeral system to an integer
 *
 * @param number value for conversion
 */
char* roman_to_number(char *number) {
    for (int i = 0; i < 100; i++) {
        if (!strcmp(roman_numbers[i], number))
            return roman_numbers[i];
    }
    return NULL;
}

int main(int argc, char **argv) {
    setlocale(LC_ALL, "");
    bindtextdomain(PACKAGE, LOCALE_PATH);
    textdomain(PACKAGE);

    int roman = 0;
    if(argc == 2) {
        if (!strcmp(argv[1], "--help")) {
            printf(_("Guesses a number from 1 to 100 with support for Roman numbers.\n"));
            printf(_("usage: number [-r]\n"));
            printf(_("\t-r\tEnable Roman numbers\n"));
            return 0;
        }
        if (!strcmp(argv[1], "--version")) {
            printf("1.0\n");
            return 0;
        }
        if (!strcmp(argv[1], "-r"))
            roman = 1;
    }

    char number_str[16];
    const char * lower_str = roman ? number_to_roman(1) : "1";
    const char * upper_str = roman ? number_to_roman(100) : "100";
    printf(_("Guess a number from %s to %s.\n"), lower_str, upper_str);

    int lower = 1;
    int upper = 100;
    int middle = (lower + upper) / 2;
    char *yes_answer = _("yes");
    char *no_answer = _("no");
    char answer[64];
    while (lower < upper) {
        if (roman)
            strcpy(number_str, number_to_roman(middle));
        else
            sprintf(number_str, "%d", middle);
        printf(_("Is the number greater than %s (yes or no)?\n"), number_str);
        scanf("%s", answer);
        if (!strcmp(answer, yes_answer)) {
            lower = middle + 1;
            middle = (lower + upper) / 2;
        }
        else if (!strcmp(answer, no_answer)) {
            upper = middle;
            middle = (lower + upper) / 2;
        }
        else {printf(_("Wrong answer\n"));
            continue;
        }
    }
    if (roman)
        strcpy(number_str, number_to_roman(upper));
    else
        sprintf(number_str, "%d", upper);
    printf(_("The correct number is %s\n"), number_str);
    return 0;
}
