#include "stm32f10x.h"

void foo () {
	//static char text [175] = "XFZDYKTLUHUQGBJDVCVBEJOEOUYUSLOFRCUVETHLBTEOUYSKRYQEXCELRCGMBJDHMOTRSTQRDUQEWUVFEHLLWDDTBPFDGEFSXCSMVHMEWQMZSJZYKYOVEVQMQJEOIYLDKKHMUFLVZTEUOJBFSCGVUYWWIEBDWAXGMKEKRNORGGACWDO";
	static char text [175] = "MYPXGQWTEZOJOCGQRDTZVMBNQFZYBDXALADSZOCGDGDCVTOQLIYFKVGULHEWPAFJTXNEHNURCZDIVJEAUKHEOVUSLDPVYETRJXXDQEXXRWABNQDEDROSQHTFCWFDTBALCSNYHKXBCSFOLTJPQMUZSUZAQZTGMTVSQBPGOSKTDTCSHGN";
	static unsigned int i = 1;
	static char * buforp [4] = {0};
	char bufor [4] = "";
	if(i == 1) {
		buforp [0] = & text [13];
		buforp [1] = & text [01];
		buforp [2] = & text [19];
		buforp [3] = & text [90];
	} else {
		buforp [0] += 1;
		buforp [1] += 2;
		buforp [2] += 3;
		buforp [3] += 4;
	}
	bufor [0] = * buforp [0];
	bufor [1] = * buforp [1];
	bufor [2] = * buforp [2];
	bufor [3] = * buforp [3];
	++i; // tutaj warto postawic pulapke
}
	
int main ( void ) {
	while(1)
		foo();
	return 0;
}