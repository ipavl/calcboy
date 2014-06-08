/* CalcBoy.c
 *
 * Description: a calculator for the Nintendo Game Boy
 * Author: Ian Pavlinic
 * Date: June 7, 2014
 */

#include <gb/gb.h>
#include <gb/console.h>
#include <types.h>
#include <stdio.h>
#include <stdlib.h>

#define OP_ADD '+'
#define OP_SUB '-'
#define OP_MUL '*'
#define OP_DIV '/'

LWORD _input1 = 0;
LWORD _input2 = 0;
LWORD _answer = 0;
char _oper = OP_ADD;

void clear_disp();
void draw_screen();

int main(void) {
    draw_screen();

    waitpad(J_START);
    clear_disp();

    while (1) {
        waitpad(J_LEFT);
    }

    return 0;
}

/*
 * Clears the display.
 */
void clear_disp() {
    BYTE i;
    for (i = 0; i < 18; i++) {
        printf(" \n");
    }
}

/*
 * Draws the base game board.
 */
void draw_screen() {
    printf(" \n");
    printf(" CALCBOY   by ipavl\n");
    printf(" -------\n");
    printf(" \n");
    printf("   Input 1: %u", _input1);
    printf("\n");
    printf("   Input 2: %u", _input2);
    printf("\n");
    printf(" Operation: %c", _oper);
    printf("\n");
    printf("    Answer: %u", _answer);
    printf("\n \n");
    printf(" HELP\n");
    printf(" ----\n\n");
    printf(" Input 1: LEFT/RIGHT");
    printf(" Input 2: UP/DOWN\n\n");
    printf(" Operation: SELECT\n");
    printf(" Calculate: START");
}
