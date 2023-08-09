#include <stdio.h>
#include<conio.h>
#include <graphics.h>
#include <string.h>
#include<dos.h>

#define MAX_TRIES 6
#define MAX_WORD_LEN 20

void drawHangman(int attempt) {

    line(250, 400, 550, 400);
    line(350, 400, 350, 100);
    line(350, 100, 450, 100);

     switch (attempt) {
        case 6:
            line(450, 300, 500, 350);
        case 5:
            line(450, 300, 400, 350);
        case 4:
            line(450, 220, 500, 250);
        case 3:
            line(450, 220, 400, 250);
        case 2:
	    line(450, 200, 450, 300);
	case 1:
	    circle(450, 150, 50);
	    break;
	default:
	    break;
    }
}


int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    char word[MAX_WORD_LEN];
    char guessedWord[MAX_WORD_LEN * 2]; 
    int wordLen, i, incorrectGuesses = 0;
    int isWordGuessed = 0;

    printf("Enter the word: ");
    scanf("%s", word);
    wordLen = strlen(word);

    for (i = 0; i < wordLen; i++) {
	guessedWord[i * 2] = '_';
	guessedWord[i * 2 + 1] = ' '; 
    }
    guessedWord[i * 2] = '\0';

    while (incorrectGuesses < MAX_TRIES && !isWordGuessed) {
	cleardevice();
	drawHangman(incorrectGuesses);

	outtextxy(100, 300, guessedWord);

	char guess;
	printf("Enter your guess: ");
	fflush(stdin);
	scanf(" %c", &guess);

	int found = 0;
	for (i = 0; i < wordLen; i++) {
	    if (word[i] == guess) {
		guessedWord[i * 2] = guess;
		found = 1;
	    }
	}

	if (!found) {
	    incorrectGuesses++;
	}

	isWordGuessed = 1;
    for (i = 0; i < wordLen; i++) {
	if (word[i] != guessedWord[i * 2]) {
	    isWordGuessed = 0;
	    break;
	}
    }

	delay(1000);
    }

    cleardevice();

    drawHangman(incorrectGuesses);

    int resultX = getmaxx() / 2 - textheight(guessedWord) / 2;
    int resultY = getmaxy() / 2 - textheight(guessedWord) / 2;
    if (isWordGuessed) {
	outtextxy(resultX, resultY, "Congratulations! You won.");
    } else {
	outtextxy(resultX, resultY, "Game Over. You ran out of attempts.");
    }

    getch();
    closegraph();
    return 0;
}
