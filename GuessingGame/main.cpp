#include<iostream>
#include<cstdlib>

//Function Declarations
void RunGame(unsigned int &UserInput, unsigned int &Answer);
int RandomNumberGenerator(unsigned int& Answer);
int UserInputGuess(unsigned int UserInput);
void CompareGuess(unsigned int &UserInput,unsigned int &Answer);
void WinOrLose(unsigned int &UserInput, unsigned int &Answer);
void PlayAgain(unsigned int &UserInput, unsigned int &Answer);


//variables of type integer
unsigned int UserInput = 0, Answer= 0;

int main()
{
	//print to screen 
	std::cout << "Hello Welcome to number guessing game!!" << std::endl;
	std::cout << "\nYou have 10 guess " << std::endl;

	Answer = RandomNumberGenerator(Answer);

	//call function 
	RunGame(Answer, UserInput);

	return 0;

}
// function to runs the game
void RunGame(unsigned int &Answer, unsigned int &UserInput)
{
	//count set to how may guesses 
	unsigned int Guesscount = 10;

	//loop through all 10 guesses 
	for (int i = 0; i < 9; i++)
	{

		//user enter there guess
		UserInput = UserInputGuess(Answer);
		
		//compare user input to game number
		CompareGuess(Answer,UserInput);

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
int RandomNumberGenerator(unsigned int &Answer)
{

	//providing a seed value
	srand((unsigned)time(NULL));

	// fetch a random number between 1 and 10
	Answer = 1 + (rand() % 10);

	// test to see the number generated is correct
	
	//std::cout<<"number to guess " << Answer;

	return Answer;
}

// user to input number guess
int UserInputGuess(unsigned int UserIput)
{
	//print to screen
	std::cout << "\nplease enter your guess from 1 to 10 must be a whole number: ";


	//check Input is a integer and that the number is within the scope of the game
	while (!(std::cin >> UserInput) || std::cin.get() != '\n' || UserInput <= 0 || UserInput > 10)
	{
		//informs user of there incorrect entire
		std::cout << "\ninvalid input press enter and then enter your number ";
	
		// Clears the error flag
		std::cin.clear();

		std::cin.ignore(256, '\n');
	}


	//return the value
	return UserInput;

}

// function to compare the answer to the users input 
void CompareGuess(unsigned int &Answer, unsigned int &UserInput)
{

	// check if the plays answer matches number
	if (Answer == UserInput)
	{

		//print to screen
		std::cout << "\n" << UserInput << " is the correct answer" << std::endl;
		// break out of the for loop

	}
	//check if the plays answer is lower then random number
	if (UserInput < Answer && UserInput > 0)
	{

		//print to screen
		std::cout << "your answer is close but " << UserInput << " is too low" << std::endl;

	}
	//check if the plays answer is higher then random number
	if (UserInput > Answer && UserInput < 10)
	{

		//print to screen
		std::cout << "your answer is close but " << UserInput << " is too high" << std::endl;

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

	PlayAgain(UserInput,Answer);
}

// Function to ask the user to play the game again
void PlayAgain(unsigned int& UserInput, unsigned int& Answer)
{
	char answer;
	char yes = 'y';
	char Yes = 'Y';

	std::cout << "Do you want to play again? " << std::endl;
	std::cout << " Answer y for yes or any other letter for no  " << std::endl;


	//input from user stored in num1
	std::cin >> answer;

	if (answer == yes || answer == Yes)
	{
		Answer = RandomNumberGenerator(Answer);

		RunGame(Answer, UserInput);
	}
	else
	{
		std::cout << "GoodBye!  " << std::endl;
	}

}