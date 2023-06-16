#include<iostream>
#include<cstdlib>
#include"GameSettings.h"


int main()
{
	//print to screen 
	std::cout << "Hello Welcome to number guessing game!!" << std::endl;
	std::cout << "\nYou have "<< Guesscount <<" guess " << std::endl;
	// call function to create the random number 
	Answer = RandomNumberGenerator(Answer,min,max);
	//call function to start the game
	RunGame(Answer, UserInput,Guesscount);

	return 0;
}

// function to runs the game
void RunGame(unsigned int &Answer, unsigned int &UserInput, unsigned int &Guesscount)
{
	
	//loop through all 10 guesses 
	for (int i = 0; i < 9; i++)
	{
		//user enter there guess
		UserInput = UserInputGuess(Answer,min,max);
		
		//compare user input to game number
		CompareGuess(Answer,UserInput,min,max);

		//subtract one from guess count 
		Guesscount--;

		// check if user is correct
		if (UserInput == Answer)
		{
			//break out of for loop
			break;
		}
		// print the guess count to the user
		std::cout << "You have: " << Guesscount << " guesses left\n " << std::endl;
	}
	// check if the play won or lost
	WinOrLose(Answer, UserInput);
}

// random number generator 
int RandomNumberGenerator(unsigned int &Answer, unsigned int &min, unsigned int &max)
{
	//providing a seed value
	srand((unsigned)time(NULL));

	// fetch a random number between 1 and 10
	Answer = min + (rand() % max);

	// used for test the code 
	//std::cout << "number to guess " << Answer;

	return Answer;
}

// user to input number guess
int UserInputGuess(unsigned int UserIput, unsigned int& min, unsigned int& max)
{
	//print to screen
	std::cout << "\nplease enter your guess from "<<min << " to "<<max << " must be a whole number : ";

	//check Input is a integer and that the number is within the scope of the game
	while (!(std::cin >> UserInput) || std::cin.get() != '\n' || UserInput < min || UserInput > max)
	{
		//informs user of there incorrect entire
		std::cout << "\ninvalid input press enter and then enter your number ";
	
		// Clears the error flag
		std::cin.clear();
		//It will clear the buffer before taking the new input
		std::cin.ignore(256, '\n');
	}

	//return the value
	return UserInput;
}

// function to compare the answer to the users input 
void CompareGuess(unsigned int &Answer, unsigned int &UserInput, unsigned int& min, unsigned int& max)
{

	// check if the plays answer matches number
	if (Answer == UserInput)
	{
		//print to screen
		std::cout << "\n" << UserInput << " is the correct answer" << std::endl;
		// break out of the for loop
	}
	//check if the plays answer is lower then random number
	if (UserInput < Answer && UserInput >= min)
	{
		//print to screen
		std::cout << "your answer " << UserInput << " is too low" << std::endl;
	}
	//check if the plays answer is higher then random number
	if (UserInput > Answer && UserInput <= max)
	{
		//print to screen
		std::cout << "your answer " << UserInput << " is too high" << std::endl;
	}

}

//Function to check if the play won or lose and display result to screen 
void WinOrLose(unsigned int &Answer, unsigned int &UserInput)
{
	//if user won by finding the correct number
	if (Answer == UserInput)
	{
		//print to screen
		std::cout << "\n\nCongratulation You Won " << std::endl;
	}

	// user did not find correct number
	else
	{
		//print to screen
		std::cout << "\nSorry You LOSE" << std::endl;
	}

	// call the play aging function
	PlayAgain(UserInput,Answer);
}

// Function to ask the user to play the game again
void PlayAgain(unsigned int& UserInput, unsigned int& Answer)
{
	//variables of type integer
	char answer, yes = 'y',Yes = 'Y';

	std::cout << "Do you want to play again? " << std::endl;
	std::cout << " Answer y for yes or any other letter for no  " << std::endl;

	//input from user stored in num1
	std::cin >> answer;

	// if the user wish to play again 
	if (answer == yes || answer == Yes)
	{
		//call function to generate random number 
		Answer = RandomNumberGenerator(Answer,min,max);
		// call Run Game function
		RunGame(Answer, UserInput ,Guesscount);
	}
	// the user wishes to quit 
	else
	{
		// output to user 
		std::cout << "GoodBye!  " << std::endl;
	}
}