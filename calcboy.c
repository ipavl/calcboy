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

// Operations
#define OP_ADD '+'
#define OP_SUB '-'
#define OP_MUL '*'
#define OP_DIV '/'

// Key screen coordinates (i.e. value redraw start)
#define IN1_Y 4
#define IN1_X 12
#define IN2_Y 5
#define IN2_X 12
#define OPR_Y 6
#define OPR_X 12
#define ANS_Y 7
#define ANS_X 12

BYTE i;
LWORD _input1 = 0;
LWORD _input2 = 0;
LWORD _answer = 0;
char _oper = OP_ADD;

void clear_disp();
void draw_screen();
void calc_ans();
void select_op();

void redraw_in1();
void redraw_in2();
void redraw_op();
void redraw_ans();

int main(void) {
    draw_screen();

    // Main "game" loop
    while (1) {
        switch (joypad()) {
            case J_LEFT:
                 _input1--;
                 redraw_in1();
                 break;
            case J_RIGHT:
                 _input1++;
                 redraw_in1();
                 break;
            case J_UP:
                 _input2++;
                 redraw_in2();
                 break;
            case J_DOWN:
                 _input2--;
                 redraw_in2();
                 break;
            case J_START:
                 calc_ans();
                 break;
            case J_SELECT:
                 select_op();
                 break;
        }
    }

    return 0;
}

/*
 * Clears the display.
 */
void clear_disp() {
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

/*
 * Cycles through the operations and calls the redraw_op() function to
 * redraw the symbol displayed on screen.
 */
void select_op() {
    if (_oper == OP_ADD) {
        _oper = OP_SUB;
    } else if (_oper == OP_SUB) {
        _oper = OP_MUL;
    } else if (_oper == OP_MUL) {
        _oper = OP_DIV;
    } else if (_oper == OP_DIV) {
        _oper = OP_ADD;
    }

    redraw_op();
}

/*
 * Calculates the answer using (_answer =  _input1 <_oper> _input2) and
 * calls redraw_ans() to draw the new value on the screen.
 */
void calc_ans() {
    if (_oper == OP_ADD) {
        _answer = _input1 + _input2;
    } else if (_oper == OP_SUB) {
        _answer = _input1 - _input2;
    } else if (_oper == OP_MUL) {
        _answer = _input1 * _input2;
    } else if (_oper == OP_DIV) {
        _answer = _input1 / _input2;
    }

    redraw_ans();
}

/*
 * Redraws the input 1 value.
 */
void redraw_in1() {
    gotoxy(IN1_X, IN1_Y);
    printf("%u", _input1);
}

/*
 * Redraws the input 2 value.
 */
void redraw_in2() {
    gotoxy(IN2_X, IN2_Y);
    printf("%u", _input2);
}

/*
 * Redraws the operation value.
 */
void redraw_op() {
    gotoxy(OPR_X, OPR_Y);
    printf("%c", _oper);
}

/*
 * Redraws the answer value.
 */
void redraw_ans() {
    gotoxy(ANS_X, ANS_Y);
    printf("%u", _answer);
}
