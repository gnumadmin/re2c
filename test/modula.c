
#line 1 "modula.re"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef unsigned int uint;
typedef unsigned char uchar;

#define	BSIZE	8192

#define	YYCTYPE		uchar
#define	YYCURSOR	cursor
#define	YYLIMIT		s->lim
#define	YYMARKER	s->ptr
#define	YYFILL		{cursor = fill(s, cursor);}

#define	RETURN(i)	{s->cur = cursor; return i;}

typedef struct Scanner {
    int			fd;
    uchar		*bot, *tok, *ptr, *cur, *pos, *lim, *top, *eof;
    uint		line;
} Scanner;

uchar *fill(Scanner *s, uchar *cursor){
    if(!s->eof){
	uint cnt = s->tok - s->bot;
	if(cnt){
	    memcpy(s->bot, s->tok, s->lim - s->tok);
	    s->tok = s->bot;
	    s->ptr -= cnt;
	    cursor -= cnt;
	    s->pos -= cnt;
	    s->lim -= cnt;
	}
	if((s->top - s->lim) < BSIZE){
	    uchar *buf = (uchar*) malloc(((s->lim - s->bot) + BSIZE)*sizeof(uchar));
	    memcpy(buf, s->tok, s->lim - s->tok);
	    s->tok = buf;
	    s->ptr = &buf[s->ptr - s->bot];
	    cursor = &buf[cursor - s->bot];
	    s->pos = &buf[s->pos - s->bot];
	    s->lim = &buf[s->lim - s->bot];
	    s->top = &s->lim[BSIZE];
	    free(s->bot);
	    s->bot = buf;
	}
	if((cnt = read(s->fd, (char*) s->lim, BSIZE)) != BSIZE){
	    s->eof = &s->lim[cnt]; *(s->eof)++ = '\n';
	}
	s->lim += cnt;
    }
    return cursor;
}

int scan(Scanner *s){
	uchar *cursor = s->cur;
	uint depth;
std:
	s->tok = cursor;
#line 64 "modula.re"



#line 7 "<stdout>"
{
	YYCTYPE yych;
	unsigned int yyaccept;
	goto yy0;
	++YYCURSOR;
yy0:
	if((YYLIMIT - YYCURSOR) < 15) YYFILL(15);
	yych = *YYCURSOR;
	switch(yych){
	case 0x09:	case ' ':	goto yy73;
	case 0x0A:	goto yy75;
	case '"':	goto yy9;
	case '#':	goto yy10;
	case '&':	goto yy12;
	case '\'':	goto yy7;
	case '(':	goto yy2;
	case ')':	goto yy14;
	case '*':	goto yy16;
	case '+':	goto yy18;
	case ',':	goto yy20;
	case '-':	goto yy22;
	case '.':	goto yy24;
	case '/':	goto yy26;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':	goto yy4;
	case '8':
	case '9':	goto yy6;
	case ':':	goto yy28;
	case ';':	goto yy30;
	case '<':	goto yy32;
	case '=':	goto yy34;
	case '>':	goto yy36;
	case 'A':	goto yy52;
	case 'B':	goto yy54;
	case 'C':	goto yy55;
	case 'D':	goto yy56;
	case 'E':	goto yy57;
	case 'F':	goto yy58;
	case 'G':
	case 'H':	case 'J':
	case 'K':	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy72;
	case 'I':	goto yy59;
	case 'L':	goto yy60;
	case 'M':	goto yy61;
	case 'N':	goto yy62;
	case 'O':	goto yy63;
	case 'P':	goto yy64;
	case 'Q':	goto yy65;
	case 'R':	goto yy66;
	case 'S':	goto yy67;
	case 'T':	goto yy68;
	case 'U':	goto yy69;
	case 'V':	goto yy70;
	case 'W':	goto yy71;
	case '[':	goto yy38;
	case ']':	goto yy40;
	case '^':	goto yy42;
	case '{':	goto yy44;
	case '|':	goto yy46;
	case '}':	goto yy48;
	case '~':	goto yy50;
	default:	goto yy77;
	}
yy2:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '*':	goto yy297;
	default:	goto yy3;
	}
yy3:
#line 79 "modula.re"
{RETURN(9);}
#line 112 "<stdout>"
yy4:	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	goto yy292;
yy5:
#line 69 "modula.re"
{RETURN(1);}
#line 119 "<stdout>"
yy6:	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	goto yy278;
yy7:	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	switch(yych){
	case 0x0A:	goto yy8;
	default:	goto yy274;
	}
yy8:
#line 158 "modula.re"
{
		printf("unexpected character: %c\n", *s->tok);
		goto std;
	    }
#line 135 "<stdout>"
yy9:	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	switch(yych){
	case 0x0A:	goto yy8;
	default:	goto yy269;
	}
yy10:	++YYCURSOR;
	goto yy11;
yy11:
#line 77 "modula.re"
{RETURN(7);}
#line 147 "<stdout>"
yy12:	++YYCURSOR;
	goto yy13;
yy13:
#line 78 "modula.re"
{RETURN(8);}
#line 153 "<stdout>"
yy14:	++YYCURSOR;
	goto yy15;
yy15:
#line 80 "modula.re"
{RETURN(10);}
#line 159 "<stdout>"
yy16:	++YYCURSOR;
	goto yy17;
yy17:
#line 81 "modula.re"
{RETURN(11);}
#line 165 "<stdout>"
yy18:	++YYCURSOR;
	goto yy19;
yy19:
#line 82 "modula.re"
{RETURN(12);}
#line 171 "<stdout>"
yy20:	++YYCURSOR;
	goto yy21;
yy21:
#line 83 "modula.re"
{RETURN(13);}
#line 177 "<stdout>"
yy22:	++YYCURSOR;
	goto yy23;
yy23:
#line 84 "modula.re"
{RETURN(14);}
#line 183 "<stdout>"
yy24:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '.':	goto yy266;
	default:	goto yy25;
	}
yy25:
#line 85 "modula.re"
{RETURN(15);}
#line 192 "<stdout>"
yy26:	++YYCURSOR;
	goto yy27;
yy27:
#line 87 "modula.re"
{RETURN(17);}
#line 198 "<stdout>"
yy28:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '=':	goto yy264;
	default:	goto yy29;
	}
yy29:
#line 88 "modula.re"
{RETURN(18);}
#line 207 "<stdout>"
yy30:	++YYCURSOR;
	goto yy31;
yy31:
#line 90 "modula.re"
{RETURN(20);}
#line 213 "<stdout>"
yy32:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '=':	goto yy262;
	case '>':	goto yy260;
	default:	goto yy33;
	}
yy33:
#line 91 "modula.re"
{RETURN(21);}
#line 223 "<stdout>"
yy34:	++YYCURSOR;
	goto yy35;
yy35:
#line 94 "modula.re"
{RETURN(24);}
#line 229 "<stdout>"
yy36:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '=':	goto yy258;
	default:	goto yy37;
	}
yy37:
#line 95 "modula.re"
{RETURN(25);}
#line 238 "<stdout>"
yy38:	++YYCURSOR;
	goto yy39;
yy39:
#line 97 "modula.re"
{RETURN(27);}
#line 244 "<stdout>"
yy40:	++YYCURSOR;
	goto yy41;
yy41:
#line 98 "modula.re"
{RETURN(28);}
#line 250 "<stdout>"
yy42:	++YYCURSOR;
	goto yy43;
yy43:
#line 99 "modula.re"
{RETURN(29);}
#line 256 "<stdout>"
yy44:	++YYCURSOR;
	goto yy45;
yy45:
#line 100 "modula.re"
{RETURN(30);}
#line 262 "<stdout>"
yy46:	++YYCURSOR;
	goto yy47;
yy47:
#line 101 "modula.re"
{RETURN(31);}
#line 268 "<stdout>"
yy48:	++YYCURSOR;
	goto yy49;
yy49:
#line 102 "modula.re"
{RETURN(32);}
#line 274 "<stdout>"
yy50:	++YYCURSOR;
	goto yy51;
yy51:
#line 103 "modula.re"
{RETURN(33);}
#line 280 "<stdout>"
yy52:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case 'N':	goto yy250;
	case 'R':	goto yy251;
	default:	goto yy81;
	}
yy53:
#line 146 "modula.re"
{RETURN(74);}
#line 290 "<stdout>"
yy54:	yych = *++YYCURSOR;
	switch(yych){
	case 'E':	goto yy243;
	case 'Y':	goto yy244;
	default:	goto yy81;
	}
yy55:	yych = *++YYCURSOR;
	switch(yych){
	case 'A':	goto yy234;
	case 'O':	goto yy235;
	default:	goto yy81;
	}
yy56:	yych = *++YYCURSOR;
	switch(yych){
	case 'E':	goto yy219;
	case 'I':	goto yy220;
	case 'O':	goto yy221;
	default:	goto yy81;
	}
yy57:	yych = *++YYCURSOR;
	switch(yych){
	case 'L':	goto yy200;
	case 'N':	goto yy201;
	case 'X':	goto yy202;
	default:	goto yy81;
	}
yy58:	yych = *++YYCURSOR;
	switch(yych){
	case 'O':	goto yy193;
	case 'R':	goto yy194;
	default:	goto yy81;
	}
yy59:	yych = *++YYCURSOR;
	switch(yych){
	case 'F':	goto yy171;
	case 'M':	goto yy173;
	case 'N':	goto yy174;
	default:	goto yy81;
	}
yy60:	yych = *++YYCURSOR;
	switch(yych){
	case 'O':	goto yy167;
	default:	goto yy81;
	}
yy61:	yych = *++YYCURSOR;
	switch(yych){
	case 'O':	goto yy160;
	default:	goto yy81;
	}
yy62:	yych = *++YYCURSOR;
	switch(yych){
	case 'O':	goto yy157;
	default:	goto yy81;
	}
yy63:	yych = *++YYCURSOR;
	switch(yych){
	case 'F':	goto yy153;
	case 'R':	goto yy155;
	default:	goto yy81;
	}
yy64:	yych = *++YYCURSOR;
	switch(yych){
	case 'O':	goto yy137;
	case 'R':	goto yy138;
	default:	goto yy81;
	}
yy65:	yych = *++YYCURSOR;
	switch(yych){
	case 'U':	goto yy128;
	default:	goto yy81;
	}
yy66:	yych = *++YYCURSOR;
	switch(yych){
	case 'E':	goto yy112;
	default:	goto yy81;
	}
yy67:	yych = *++YYCURSOR;
	switch(yych){
	case 'E':	goto yy109;
	default:	goto yy81;
	}
yy68:	yych = *++YYCURSOR;
	switch(yych){
	case 'H':	goto yy99;
	case 'O':	goto yy100;
	case 'Y':	goto yy102;
	default:	goto yy81;
	}
yy69:	yych = *++YYCURSOR;
	switch(yych){
	case 'N':	goto yy94;
	default:	goto yy81;
	}
yy70:	yych = *++YYCURSOR;
	switch(yych){
	case 'A':	goto yy91;
	default:	goto yy81;
	}
yy71:	yych = *++YYCURSOR;
	switch(yych){
	case 'H':	goto yy82;
	case 'I':	goto yy83;
	default:	goto yy81;
	}
yy72:	yych = *++YYCURSOR;
	goto yy81;
yy73:	++YYCURSOR;
	yych = *YYCURSOR;
	goto yy79;
yy74:
#line 148 "modula.re"
{ goto std; }
#line 402 "<stdout>"
yy75:	++YYCURSOR;
	goto yy76;
yy76:
#line 151 "modula.re"
{
		if(cursor == s->eof) RETURN(0);
		s->pos = cursor; s->line++;
		goto std;
	    }
#line 412 "<stdout>"
yy77:	yych = *++YYCURSOR;
	goto yy8;
yy78:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy79;
yy79:	switch(yych){
	case 0x09:	case ' ':	goto yy78;
	default:	goto yy74;
	}
yy80:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy81;
yy81:	switch(yych){
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	default:	goto yy53;
	}
yy82:	yych = *++YYCURSOR;
	switch(yych){
	case 'I':	goto yy87;
	default:	goto yy81;
	}
yy83:	yych = *++YYCURSOR;
	switch(yych){
	case 'T':	goto yy84;
	default:	goto yy81;
	}
yy84:	yych = *++YYCURSOR;
	switch(yych){
	case 'H':	goto yy85;
	default:	goto yy81;
	}
yy85:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	default:	goto yy86;
	}
yy86:
#line 144 "modula.re"
{RETURN(73);}
#line 574 "<stdout>"
yy87:	yych = *++YYCURSOR;
	switch(yych){
	case 'L':	goto yy88;
	default:	goto yy81;
	}
yy88:	yych = *++YYCURSOR;
	switch(yych){
	case 'E':	goto yy89;
	default:	goto yy81;
	}
yy89:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	default:	goto yy90;
	}
yy90:
#line 143 "modula.re"
{RETURN(72);}
#line 652 "<stdout>"
yy91:	yych = *++YYCURSOR;
	switch(yych){
	case 'R':	goto yy92;
	default:	goto yy81;
	}
yy92:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	default:	goto yy93;
	}
yy93:
#line 142 "modula.re"
{RETURN(71);}
#line 725 "<stdout>"
yy94:	yych = *++YYCURSOR;
	switch(yych){
	case 'T':	goto yy95;
	default:	goto yy81;
	}
yy95:	yych = *++YYCURSOR;
	switch(yych){
	case 'I':	goto yy96;
	default:	goto yy81;
	}
yy96:	yych = *++YYCURSOR;
	switch(yych){
	case 'L':	goto yy97;
	default:	goto yy81;
	}
yy97:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	default:	goto yy98;
	}
yy98:
#line 141 "modula.re"
{RETURN(70);}
#line 808 "<stdout>"
yy99:	yych = *++YYCURSOR;
	switch(yych){
	case 'E':	goto yy106;
	default:	goto yy81;
	}
yy100:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	default:	goto yy101;
	}
yy101:
#line 139 "modula.re"
{RETURN(68);}
#line 881 "<stdout>"
yy102:	yych = *++YYCURSOR;
	switch(yych){
	case 'P':	goto yy103;
	default:	goto yy81;
	}
yy103:	yych = *++YYCURSOR;
	switch(yych){
	case 'E':	goto yy104;
	default:	goto yy81;
	}
yy104:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	default:	goto yy105;
	}
yy105:
#line 140 "modula.re"
{RETURN(69);}
#line 959 "<stdout>"
yy106:	yych = *++YYCURSOR;
	switch(yych){
	case 'N':	goto yy107;
	default:	goto yy81;
	}
yy107:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	default:	goto yy108;
	}
yy108:
#line 138 "modula.re"
{RETURN(67);}
#line 1032 "<stdout>"
yy109:	yych = *++YYCURSOR;
	switch(yych){
	case 'T':	goto yy110;
	default:	goto yy81;
	}
yy110:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	default:	goto yy111;
	}
yy111:
#line 137 "modula.re"
{RETURN(66);}
#line 1105 "<stdout>"
yy112:	yych = *++YYCURSOR;
	switch(yych){
	case 'C':	goto yy113;
	case 'P':	goto yy114;
	case 'T':	goto yy115;
	default:	goto yy81;
	}
yy113:	yych = *++YYCURSOR;
	switch(yych){
	case 'O':	goto yy124;
	default:	goto yy81;
	}
yy114:	yych = *++YYCURSOR;
	switch(yych){
	case 'E':	goto yy120;
	default:	goto yy81;
	}
yy115:	yych = *++YYCURSOR;
	switch(yych){
	case 'U':	goto yy116;
	default:	goto yy81;
	}
yy116:	yych = *++YYCURSOR;
	switch(yych){
	case 'R':	goto yy117;
	default:	goto yy81;
	}
yy117:	yych = *++YYCURSOR;
	switch(yych){
	case 'N':	goto yy118;
	default:	goto yy81;
	}
yy118:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	default:	goto yy119;
	}
yy119:
#line 136 "modula.re"
{RETURN(65);}
#line 1205 "<stdout>"
yy120:	yych = *++YYCURSOR;
	switch(yych){
	case 'A':	goto yy121;
	default:	goto yy81;
	}
yy121:	yych = *++YYCURSOR;
	switch(yych){
	case 'T':	goto yy122;
	default:	goto yy81;
	}
yy122:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	default:	goto yy123;
	}
yy123:
#line 135 "modula.re"
{RETURN(64);}
#line 1283 "<stdout>"
yy124:	yych = *++YYCURSOR;
	switch(yych){
	case 'R':	goto yy125;
	default:	goto yy81;
	}
yy125:	yych = *++YYCURSOR;
	switch(yych){
	case 'D':	goto yy126;
	default:	goto yy81;
	}
yy126:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	default:	goto yy127;
	}
yy127:
#line 134 "modula.re"
{RETURN(63);}
#line 1361 "<stdout>"
yy128:	yych = *++YYCURSOR;
	switch(yych){
	case 'A':	goto yy129;
	default:	goto yy81;
	}
yy129:	yych = *++YYCURSOR;
	switch(yych){
	case 'L':	goto yy130;
	default:	goto yy81;
	}
yy130:	yych = *++YYCURSOR;
	switch(yych){
	case 'I':	goto yy131;
	default:	goto yy81;
	}
yy131:	yych = *++YYCURSOR;
	switch(yych){
	case 'F':	goto yy132;
	default:	goto yy81;
	}
yy132:	yych = *++YYCURSOR;
	switch(yych){
	case 'I':	goto yy133;
	default:	goto yy81;
	}
yy133:	yych = *++YYCURSOR;
	switch(yych){
	case 'E':	goto yy134;
	default:	goto yy81;
	}
yy134:	yych = *++YYCURSOR;
	switch(yych){
	case 'D':	goto yy135;
	default:	goto yy81;
	}
yy135:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	default:	goto yy136;
	}
yy136:
#line 133 "modula.re"
{RETURN(62);}
#line 1464 "<stdout>"
yy137:	yych = *++YYCURSOR;
	switch(yych){
	case 'I':	goto yy147;
	default:	goto yy81;
	}
yy138:	yych = *++YYCURSOR;
	switch(yych){
	case 'O':	goto yy139;
	default:	goto yy81;
	}
yy139:	yych = *++YYCURSOR;
	switch(yych){
	case 'C':	goto yy140;
	default:	goto yy81;
	}
yy140:	yych = *++YYCURSOR;
	switch(yych){
	case 'E':	goto yy141;
	default:	goto yy81;
	}
yy141:	yych = *++YYCURSOR;
	switch(yych){
	case 'D':	goto yy142;
	default:	goto yy81;
	}
yy142:	yych = *++YYCURSOR;
	switch(yych){
	case 'U':	goto yy143;
	default:	goto yy81;
	}
yy143:	yych = *++YYCURSOR;
	switch(yych){
	case 'R':	goto yy144;
	default:	goto yy81;
	}
yy144:	yych = *++YYCURSOR;
	switch(yych){
	case 'E':	goto yy145;
	default:	goto yy81;
	}
yy145:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	default:	goto yy146;
	}
yy146:
#line 132 "modula.re"
{RETURN(61);}
#line 1572 "<stdout>"
yy147:	yych = *++YYCURSOR;
	switch(yych){
	case 'N':	goto yy148;
	default:	goto yy81;
	}
yy148:	yych = *++YYCURSOR;
	switch(yych){
	case 'T':	goto yy149;
	default:	goto yy81;
	}
yy149:	yych = *++YYCURSOR;
	switch(yych){
	case 'E':	goto yy150;
	default:	goto yy81;
	}
yy150:	yych = *++YYCURSOR;
	switch(yych){
	case 'R':	goto yy151;
	default:	goto yy81;
	}
yy151:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	default:	goto yy152;
	}
yy152:
#line 131 "modula.re"
{RETURN(60);}
#line 1660 "<stdout>"
yy153:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	default:	goto yy154;
	}
yy154:
#line 129 "modula.re"
{RETURN(58);}
#line 1728 "<stdout>"
yy155:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	default:	goto yy156;
	}
yy156:
#line 130 "modula.re"
{RETURN(59);}
#line 1796 "<stdout>"
yy157:	yych = *++YYCURSOR;
	switch(yych){
	case 'T':	goto yy158;
	default:	goto yy81;
	}
yy158:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	default:	goto yy159;
	}
yy159:
#line 128 "modula.re"
{RETURN(57);}
#line 1869 "<stdout>"
yy160:	yych = *++YYCURSOR;
	switch(yych){
	case 'D':	goto yy161;
	default:	goto yy81;
	}
yy161:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	case 'U':	goto yy163;
	default:	goto yy162;
	}
yy162:
#line 126 "modula.re"
{RETURN(55);}
#line 1941 "<stdout>"
yy163:	yych = *++YYCURSOR;
	switch(yych){
	case 'L':	goto yy164;
	default:	goto yy81;
	}
yy164:	yych = *++YYCURSOR;
	switch(yych){
	case 'E':	goto yy165;
	default:	goto yy81;
	}
yy165:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	default:	goto yy166;
	}
yy166:
#line 127 "modula.re"
{RETURN(56);}
#line 2019 "<stdout>"
yy167:	yych = *++YYCURSOR;
	switch(yych){
	case 'O':	goto yy168;
	default:	goto yy81;
	}
yy168:	yych = *++YYCURSOR;
	switch(yych){
	case 'P':	goto yy169;
	default:	goto yy81;
	}
yy169:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	default:	goto yy170;
	}
yy170:
#line 125 "modula.re"
{RETURN(54);}
#line 2097 "<stdout>"
yy171:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	default:	goto yy172;
	}
yy172:
#line 121 "modula.re"
{RETURN(50);}
#line 2165 "<stdout>"
yy173:	yych = *++YYCURSOR;
	switch(yych){
	case 'P':	goto yy176;
	default:	goto yy81;
	}
yy174:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	default:	goto yy175;
	}
yy175:
#line 124 "modula.re"
{RETURN(53);}
#line 2238 "<stdout>"
yy176:	yych = *++YYCURSOR;
	switch(yych){
	case 'L':	goto yy177;
	case 'O':	goto yy178;
	default:	goto yy81;
	}
yy177:	yych = *++YYCURSOR;
	switch(yych){
	case 'E':	goto yy182;
	default:	goto yy81;
	}
yy178:	yych = *++YYCURSOR;
	switch(yych){
	case 'R':	goto yy179;
	default:	goto yy81;
	}
yy179:	yych = *++YYCURSOR;
	switch(yych){
	case 'T':	goto yy180;
	default:	goto yy81;
	}
yy180:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	default:	goto yy181;
	}
yy181:
#line 123 "modula.re"
{RETURN(52);}
#line 2327 "<stdout>"
yy182:	yych = *++YYCURSOR;
	switch(yych){
	case 'M':	goto yy183;
	default:	goto yy81;
	}
yy183:	yych = *++YYCURSOR;
	switch(yych){
	case 'E':	goto yy184;
	default:	goto yy81;
	}
yy184:	yych = *++YYCURSOR;
	switch(yych){
	case 'N':	goto yy185;
	default:	goto yy81;
	}
yy185:	yych = *++YYCURSOR;
	switch(yych){
	case 'T':	goto yy186;
	default:	goto yy81;
	}
yy186:	yych = *++YYCURSOR;
	switch(yych){
	case 'A':	goto yy187;
	default:	goto yy81;
	}
yy187:	yych = *++YYCURSOR;
	switch(yych){
	case 'T':	goto yy188;
	default:	goto yy81;
	}
yy188:	yych = *++YYCURSOR;
	switch(yych){
	case 'I':	goto yy189;
	default:	goto yy81;
	}
yy189:	yych = *++YYCURSOR;
	switch(yych){
	case 'O':	goto yy190;
	default:	goto yy81;
	}
yy190:	yych = *++YYCURSOR;
	switch(yych){
	case 'N':	goto yy191;
	default:	goto yy81;
	}
yy191:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	default:	goto yy192;
	}
yy192:
#line 122 "modula.re"
{RETURN(51);}
#line 2440 "<stdout>"
yy193:	yych = *++YYCURSOR;
	switch(yych){
	case 'R':	goto yy198;
	default:	goto yy81;
	}
yy194:	yych = *++YYCURSOR;
	switch(yych){
	case 'O':	goto yy195;
	default:	goto yy81;
	}
yy195:	yych = *++YYCURSOR;
	switch(yych){
	case 'M':	goto yy196;
	default:	goto yy81;
	}
yy196:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	default:	goto yy197;
	}
yy197:
#line 120 "modula.re"
{RETURN(49);}
#line 2523 "<stdout>"
yy198:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	default:	goto yy199;
	}
yy199:
#line 119 "modula.re"
{RETURN(48);}
#line 2591 "<stdout>"
yy200:	yych = *++YYCURSOR;
	switch(yych){
	case 'S':	goto yy213;
	default:	goto yy81;
	}
yy201:	yych = *++YYCURSOR;
	switch(yych){
	case 'D':	goto yy211;
	default:	goto yy81;
	}
yy202:	yych = *++YYCURSOR;
	switch(yych){
	case 'I':	goto yy203;
	case 'P':	goto yy204;
	default:	goto yy81;
	}
yy203:	yych = *++YYCURSOR;
	switch(yych){
	case 'T':	goto yy209;
	default:	goto yy81;
	}
yy204:	yych = *++YYCURSOR;
	switch(yych){
	case 'O':	goto yy205;
	default:	goto yy81;
	}
yy205:	yych = *++YYCURSOR;
	switch(yych){
	case 'R':	goto yy206;
	default:	goto yy81;
	}
yy206:	yych = *++YYCURSOR;
	switch(yych){
	case 'T':	goto yy207;
	default:	goto yy81;
	}
yy207:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	default:	goto yy208;
	}
yy208:
#line 118 "modula.re"
{RETURN(47);}
#line 2695 "<stdout>"
yy209:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	default:	goto yy210;
	}
yy210:
#line 117 "modula.re"
{RETURN(46);}
#line 2763 "<stdout>"
yy211:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	default:	goto yy212;
	}
yy212:
#line 116 "modula.re"
{RETURN(45);}
#line 2831 "<stdout>"
yy213:	yych = *++YYCURSOR;
	switch(yych){
	case 'E':	goto yy214;
	case 'I':	goto yy216;
	default:	goto yy81;
	}
yy214:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	default:	goto yy215;
	}
yy215:
#line 114 "modula.re"
{RETURN(43);}
#line 2905 "<stdout>"
yy216:	yych = *++YYCURSOR;
	switch(yych){
	case 'F':	goto yy217;
	default:	goto yy81;
	}
yy217:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	default:	goto yy218;
	}
yy218:
#line 115 "modula.re"
{RETURN(44);}
#line 2978 "<stdout>"
yy219:	yych = *++YYCURSOR;
	switch(yych){
	case 'F':	goto yy225;
	default:	goto yy81;
	}
yy220:	yych = *++YYCURSOR;
	switch(yych){
	case 'V':	goto yy223;
	default:	goto yy81;
	}
yy221:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	default:	goto yy222;
	}
yy222:
#line 113 "modula.re"
{RETURN(42);}
#line 3056 "<stdout>"
yy223:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	default:	goto yy224;
	}
yy224:
#line 112 "modula.re"
{RETURN(41);}
#line 3124 "<stdout>"
yy225:	yych = *++YYCURSOR;
	switch(yych){
	case 'I':	goto yy226;
	default:	goto yy81;
	}
yy226:	yych = *++YYCURSOR;
	switch(yych){
	case 'N':	goto yy227;
	default:	goto yy81;
	}
yy227:	yych = *++YYCURSOR;
	switch(yych){
	case 'I':	goto yy228;
	default:	goto yy81;
	}
yy228:	yych = *++YYCURSOR;
	switch(yych){
	case 'T':	goto yy229;
	default:	goto yy81;
	}
yy229:	yych = *++YYCURSOR;
	switch(yych){
	case 'I':	goto yy230;
	default:	goto yy81;
	}
yy230:	yych = *++YYCURSOR;
	switch(yych){
	case 'O':	goto yy231;
	default:	goto yy81;
	}
yy231:	yych = *++YYCURSOR;
	switch(yych){
	case 'N':	goto yy232;
	default:	goto yy81;
	}
yy232:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	default:	goto yy233;
	}
yy233:
#line 111 "modula.re"
{RETURN(40);}
#line 3227 "<stdout>"
yy234:	yych = *++YYCURSOR;
	switch(yych){
	case 'S':	goto yy240;
	default:	goto yy81;
	}
yy235:	yych = *++YYCURSOR;
	switch(yych){
	case 'N':	goto yy236;
	default:	goto yy81;
	}
yy236:	yych = *++YYCURSOR;
	switch(yych){
	case 'S':	goto yy237;
	default:	goto yy81;
	}
yy237:	yych = *++YYCURSOR;
	switch(yych){
	case 'T':	goto yy238;
	default:	goto yy81;
	}
yy238:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	default:	goto yy239;
	}
yy239:
#line 110 "modula.re"
{RETURN(39);}
#line 3315 "<stdout>"
yy240:	yych = *++YYCURSOR;
	switch(yych){
	case 'E':	goto yy241;
	default:	goto yy81;
	}
yy241:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	default:	goto yy242;
	}
yy242:
#line 109 "modula.re"
{RETURN(38);}
#line 3388 "<stdout>"
yy243:	yych = *++YYCURSOR;
	switch(yych){
	case 'G':	goto yy246;
	default:	goto yy81;
	}
yy244:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	default:	goto yy245;
	}
yy245:
#line 108 "modula.re"
{RETURN(37);}
#line 3461 "<stdout>"
yy246:	yych = *++YYCURSOR;
	switch(yych){
	case 'I':	goto yy247;
	default:	goto yy81;
	}
yy247:	yych = *++YYCURSOR;
	switch(yych){
	case 'N':	goto yy248;
	default:	goto yy81;
	}
yy248:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	default:	goto yy249;
	}
yy249:
#line 107 "modula.re"
{RETURN(36);}
#line 3539 "<stdout>"
yy250:	yych = *++YYCURSOR;
	switch(yych){
	case 'D':	goto yy256;
	default:	goto yy81;
	}
yy251:	yych = *++YYCURSOR;
	switch(yych){
	case 'R':	goto yy252;
	default:	goto yy81;
	}
yy252:	yych = *++YYCURSOR;
	switch(yych){
	case 'A':	goto yy253;
	default:	goto yy81;
	}
yy253:	yych = *++YYCURSOR;
	switch(yych){
	case 'Y':	goto yy254;
	default:	goto yy81;
	}
yy254:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	default:	goto yy255;
	}
yy255:
#line 106 "modula.re"
{RETURN(35);}
#line 3627 "<stdout>"
yy256:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy80;
	default:	goto yy257;
	}
yy257:
#line 105 "modula.re"
{RETURN(34);}
#line 3695 "<stdout>"
yy258:	++YYCURSOR;
	goto yy259;
yy259:
#line 96 "modula.re"
{RETURN(26);}
#line 3701 "<stdout>"
yy260:	++YYCURSOR;
	goto yy261;
yy261:
#line 93 "modula.re"
{RETURN(23);}
#line 3707 "<stdout>"
yy262:	++YYCURSOR;
	goto yy263;
yy263:
#line 92 "modula.re"
{RETURN(22);}
#line 3713 "<stdout>"
yy264:	++YYCURSOR;
	goto yy265;
yy265:
#line 89 "modula.re"
{RETURN(19);}
#line 3719 "<stdout>"
yy266:	++YYCURSOR;
	goto yy267;
yy267:
#line 86 "modula.re"
{RETURN(16);}
#line 3725 "<stdout>"
yy268:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy269;
yy269:	switch(yych){
	case 0x0A:	goto yy270;
	case '"':	goto yy271;
	default:	goto yy268;
	}
yy270:	YYCURSOR = YYMARKER;
	switch(yyaccept){
	case 0:	goto yy5;
	case 3:	goto yy294;
	case 4:	goto yy296;
	case 2:	goto yy276;
	case 1:	goto yy8;
	}
yy271:	++YYCURSOR;
	goto yy272;
yy272:
#line 75 "modula.re"
{RETURN(6);}
#line 3749 "<stdout>"
yy273:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy274;
yy274:	switch(yych){
	case 0x0A:	goto yy270;
	case '\'':	goto yy271;
	default:	goto yy273;
	}
yy275:	yyaccept = 2;
	yych = *(YYMARKER = ++YYCURSOR);
	switch(yych){
	case '.':	goto yy283;
	default:	goto yy286;
	}
yy276:
#line 74 "modula.re"
{RETURN(5);}
#line 3769 "<stdout>"
yy277:	yyaccept = 0;
	YYMARKER = ++YYCURSOR;
	if((YYLIMIT - YYCURSOR) < 4) YYFILL(4);
	yych = *YYCURSOR;
	goto yy278;
yy278:	switch(yych){
	case '.':	goto yy275;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy277;
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':	goto yy279;
	case 'H':	goto yy281;
	default:	goto yy5;
	}
yy279:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy280;
yy280:	switch(yych){
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':	goto yy279;
	case 'H':	goto yy281;
	default:	goto yy270;
	}
yy281:	++YYCURSOR;
	goto yy282;
yy282:
#line 73 "modula.re"
{RETURN(4);}
#line 3825 "<stdout>"
yy283:	++YYCURSOR;
	goto yy284;
yy284:	YYCURSOR -= 2;
#line 70 "modula.re"
{RETURN(1);}
#line 3831 "<stdout>"
yy285:	yyaccept = 2;
	YYMARKER = ++YYCURSOR;
	if((YYLIMIT - YYCURSOR) < 3) YYFILL(3);
	yych = *YYCURSOR;
	goto yy286;
yy286:	switch(yych){
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy285;
	case 'E':	goto yy287;
	default:	goto yy276;
	}
yy287:	yych = *++YYCURSOR;
	switch(yych){
	case '+':	case '-':	goto yy288;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy289;
	default:	goto yy270;
	}
yy288:	yych = *++YYCURSOR;
	switch(yych){
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy289;
	default:	goto yy270;
	}
yy289:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	goto yy290;
yy290:	switch(yych){
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy289;
	default:	goto yy276;
	}
yy291:	yyaccept = 0;
	YYMARKER = ++YYCURSOR;
	if((YYLIMIT - YYCURSOR) < 4) YYFILL(4);
	yych = *YYCURSOR;
	goto yy292;
yy292:	switch(yych){
	case '.':	goto yy275;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':	goto yy291;
	case '8':
	case '9':	goto yy277;
	case 'A':	case 'D':
	case 'E':
	case 'F':	goto yy279;
	case 'B':	goto yy293;
	case 'C':	goto yy295;
	case 'H':	goto yy281;
	default:	goto yy5;
	}
yy293:	yyaccept = 3;
	yych = *(YYMARKER = ++YYCURSOR);
	switch(yych){
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':	goto yy279;
	case 'H':	goto yy281;
	default:	goto yy294;
	}
yy294:
#line 71 "modula.re"
{RETURN(2);}
#line 3947 "<stdout>"
yy295:	yyaccept = 4;
	yych = *(YYMARKER = ++YYCURSOR);
	switch(yych){
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':	goto yy279;
	case 'H':	goto yy281;
	default:	goto yy296;
	}
yy296:
#line 72 "modula.re"
{RETURN(3);}
#line 3972 "<stdout>"
yy297:	++YYCURSOR;
	goto yy298;
yy298:
#line 67 "modula.re"
{ depth = 1; goto comment; }
#line 3978 "<stdout>"
}
#line 162 "modula.re"

comment:

#line 3982 "<stdout>"
{
	YYCTYPE yych;
	unsigned int yyaccept;
	goto yy299;
	++YYCURSOR;
yy299:
	if((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	switch(yych){
	case 0x0A:	goto yy304;
	case '(':	goto yy303;
	case '*':	goto yy301;
	default:	goto yy306;
	}
yy301:	++YYCURSOR;
	switch((yych = *YYCURSOR)) {
	case ')':	goto yy309;
	default:	goto yy302;
	}
yy302:
#line 179 "modula.re"
{ goto comment; }
#line 4005 "<stdout>"
yy303:	yych = *++YYCURSOR;
	switch(yych){
	case '*':	goto yy307;
	default:	goto yy302;
	}
yy304:	++YYCURSOR;
	goto yy305;
yy305:
#line 174 "modula.re"
{
		if(cursor == s->eof) RETURN(0);
		s->tok = s->pos = cursor; s->line++;
		goto comment;
	    }
#line 4020 "<stdout>"
yy306:	yych = *++YYCURSOR;
	goto yy302;
yy307:	++YYCURSOR;
	goto yy308;
yy308:
#line 172 "modula.re"
{ ++depth; goto comment; }
#line 4028 "<stdout>"
yy309:	++YYCURSOR;
	goto yy310;
yy310:
#line 166 "modula.re"
{
		if(--depth == 0)
		    goto std;
		else
		    goto comment;
	    }
#line 4039 "<stdout>"
}
#line 180 "modula.re"

}

/*
void putStr(FILE *o, char *s, uint l){
    while(l-- > 0)
	putc(*s++, o);
}
*/

main(){
    Scanner in;
    memset((char*) &in, 0, sizeof(in));
    in.fd = 0;
    while(scan(&in)){
/*
	putc('<', stdout);
	putStr(stdout, (char*) in.tok, in.cur - in.tok);
	putc('>', stdout);
	putc('\n', stdout);
*/
    }
}