#pragma once

//Function Declarations
void RunGame(unsigned int& UserInput, unsigned int& Answer, unsigned int& Guesscount);
int RandomNumberGenerator(unsigned int& Answer, unsigned int& min, unsigned int& max);
int UserInputGuess(unsigned int UserInput, unsigned int& min, unsigned int& max);
void CompareGuess(unsigned int& UserInput, unsigned int& Answer, unsigned int& min, unsigned int& max);
void WinOrLose(unsigned int& UserInput, unsigned int& Answer);
void PlayAgain(unsigned int& UserInput, unsigned int& Answer);



//variables of type integer
unsigned int UserInput = 0, Answer = 0;

// 
// change number of guesses 
//count set to how may guesses 
unsigned int Guesscount = 5;

//change min number to lowest number range  
// set min guess range
unsigned int min = 5;

//change max number to highest number range 
// set max guess range
unsigned int max = 20;
