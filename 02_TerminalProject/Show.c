#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <locale.h>

#define DX 3

int main(int argc, char* argv[]) {
        if (argc != 2) {
            printf("The input file must be specified.\n");
            exit(1);
        }
        FILE *fp = fopen(argv[1], "r");
        if (fp == NULL) {
            printf("Couldn't open the file.\n");
            exit(1);
        }
        setlocale(LC_ALL, "");
        initscr();
        int width = COLS-2*DX;
        int height = LINES-2*DX;
        char **file_lines = NULL;
        char *line = NULL;
        size_t length = 0;
        int line_count = 0;
        while (getline(&line, &length, fp) != -1) {
            line_count += 1;
            file_lines = realloc(file_lines, line_count * sizeof(char*));
            if (file_lines == NULL) {
                printf("Memory allocation error.\n");
                free(line);
                exit(1);
            }
            if (length > width + 1) {
                line[width] = '\0';
                length = width + 1;
            }
            file_lines[line_count-1] = malloc(length);
            if (file_lines[line_count-1] == NULL) {
                printf("Memory allocation error.\n");
                for (int i = 0; i < line_count-1; i++)
                    free(file_lines[i]);
                free(file_lines);
                exit(1);
            }
            strcpy(file_lines[line_count-1], line);
        }
        fclose(fp);
        WINDOW *win;

        noecho();
        cbreak();
        printw("%s", argv[1]);
        refresh();

        win = newwin(height, width, DX, DX);
        keypad(win, TRUE);
        scrollok(win, TRUE);
        box(win, 0, 0);
        wmove(win, 1, 0);
        int c = 0;
        int idx = 0;
        int start_idx = 0;
        int end_idx = line_count < height-1 ? line_count : height-1;
        do {
            werase(win);
            for (idx = start_idx; idx < end_idx; idx++)
                mvwprintw(win, idx-start_idx, 1, "%s", file_lines[idx]);
            box(win, 0, 0);
            wmove(win, 1, 0);
            wrefresh(win);
            c = wgetch(win);
            if (c == ' ' && end_idx < line_count) {
                start_idx += 1;
                end_idx += 1;
            }
        } while (c != 27);
        endwin();
        free(line);
        for (int i = 0; i < line_count; i++)
            free(file_lines[i]);
        free(file_lines);
}