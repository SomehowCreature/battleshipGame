//BATTLESHIP GAME BY MIKE BACA ***July 2026***
//Copyright (c) 2026 [Mike Baca]
//ALL CODE IN THIS FILE WAS WRITTEN BY MIKE THOMAS BACA JR
//OR COPIED FROM SUPPORT FORUMS

//Play a computer controlled enemy in a game of classic Battleship.
//Enemy randomly selects targets until he hits a ship.
//Then he searches to sink it.
//He does not have any knowledge of your ships' positions.

//Include libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <wchar.h>
#include <ctype.h>
#include <locale.h>

int main()
{
	//Seed the random number generator with the current time
	srand(time(NULL));

	//Declare arrays
	char playerABoard[10][10][10];
	char playerBBoard[10][10][10];
	char playerCBoard[10][10][10];
	char playerDBoard[10][10][10];
	char rows[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
	
	//Declare variables	
	int oneOrTwoPlayerChoice = 1;
	int twoPlayerKey = 0;
	int shipPlacementChoice = 0;
	
	int xRandom = 0;
	int yRandom = 0;
	int seagullX = 0;
	int seagullY = 0;
	int seagullGuess = 0;
	int seagullMatch = 0;
	int xRandomCheck = 0;
	int yRandomCheck = 0;
	int zRandom = 0;
	int random_num = 0;
	
	int playerOneFire = 0;
	int playerTwoFire = 0;
	int enemyFire = 0;
	char fireX = 'A';
	int fireY = 0;
	
	int key = 0;
	int passOrFailKey = 0;
	int once = 0;
	int once2 = 0;
	int miss = 0;
	int enemyMissMe = 0;
	int hit = 0;
	int enemyHitMe = 0;
	int enemyHitWater = 0;
	int hitCounter = 0;
	int notSunkYet = 0;
	int chooseAgain = 0;
	int direction = 0;

	char x = 'x';
	int y = 0;
	int a = 0;
	//Reach numOfTotalHits = 17 to defeat all enemy ships
	//and win the game
	int numOfTotalHits = 0;
	//Reach numOfTotalDamage = 17 to have all your ships destroyed
	//and lose the game
	int numOfTotalDamage = 0;
	
	int myWins = 0;
	int enemyWins = 0;
	int totalGames = 0;
	
	int numOfCARHits = 0;
	int numOfBATHits = 0;
	int numOfDESHits = 0;
	int numOfSUBHits = 0;
	int numOfPATHits = 0;
	
	int numOfCARHits2 = 0;
	int numOfBATHits2 = 0;
	int numOfDESHits2 = 0;
	int numOfSUBHits2 = 0;
	int numOfPATHits2 = 0;
	
	int numOfCARDamage = 0;
	int numOfBATDamage = 0;
	int numOfDESDamage = 0;
	int numOfSUBDamage = 0;
	int numOfPATDamage = 0;
	
	int numOfCARHealth = 5;
	int numOfBATHealth = 4;
	int numOfDESHealth = 3;
	int numOfSUBHealth = 3;
	int numOfPATHealth = 2;
	
	int fire = 1;
	int fire2 = 0;
	int counter = 0;
	
	int xOriginalGuess = 0;
	int yOriginalGuess = 0;
	int xFirstGuess = 0;
	int yFirstGuess = 0;
	int myCARSunk = 0;
	int myBATSunk = 0;
	int myDESSunk = 0;
	int mySUBSunk = 0;
	int myPATSunk = 0;
	int myCARSunkKey = 0;
	int myBATSunkKey = 0;
	int myDESSunkKey = 0;
	int mySUBSunkKey = 0;
	int myPATSunkKey = 0;
	int enemyCARSunk = 0;
	int enemyBATSunk = 0;
	int enemyDESSunk = 0;
	int enemySUBSunk = 0;
	int enemyPATSunk = 0;
	
	int healthPercentageCounter = 0;
	const char *percentFLEETCharacter = " -------100%";
	const char *FLEETHealth = "null";
	
	
	//Declare Strings
	const char *enemyHitWhich = "Submarine";
	
	char proceed = "e";
	const char *shipAbb = "JLB";
	const char *statusCAR = "Unlocalized          ";
	const char *statusBAT = "Unlocalized";
	const char *statusDES = "Unlocalized          ";
	const char *statusSUB = "Unlocalized";
	const char *statusPAT = "Unlocalized          ";
	
	const char *radCAR = "<10km         ";
	const char *radBAT = "<10km";
	const char *radDES = "<10km         ";
	const char *radSUB = "<10km";
	const char *radPAT = "<10km         ";
	
	const char *hitMissShipCAR = "       <o o o o o]";
	const char *hitMissShipBAT = "         <o o o o}";
	const char *hitMissShipDES = "           <o o o>";
	const char *hitMissShipSUB = "           (o o o)";
	const char *hitMissShipPAT = "             [o o]";
	
	const char *spacesDamage = "";
	const char *spacesHits = "";
	const char *spacesMyWins = "";
	const char *spacesEnemyWins = "";
	const char *spacesTotalGames = "";

	int createRandomX()
	{
		// C program to illustrate how to generate random number
		// withing a range
		// Set the upper bound for random numbers
		int upper_bound = 9;
		// Set the lower bound for random numbers
		int lower_bound = 0;
		// Generate a random number within the specified bounds
      xRandom = rand() % (upper_bound - lower_bound + 1) + lower_bound;
	}
	
	int createRandomY()
	{
		int upper_bound = 9;
		int lower_bound = 0;
      yRandom = rand() % (upper_bound - lower_bound + 1) + lower_bound;
	}
	
	int createRandomZ()
	{
		int upper_bound = 3;
		int lower_bound = 0;
		zRandom = rand() % (upper_bound - lower_bound + 1) + lower_bound;
	}

char convertXLowercaseToUppercase(char xVal)
	{
		if(xVal == 'a')
		{
			xVal = 'A';
			return xVal;
		}
		if(xVal == 'b')
		{
			xVal = 'B';
			return xVal;
		}
		if(xVal == 'c')
		{
			xVal = 'C';
			return xVal;
		}
		if(xVal == 'd')
		{
			xVal = 'D';
			return xVal;
		}
		if(xVal == 'e')
		{
			xVal = 'E';
			return xVal;
		}
		if(xVal == 'f')
		{
			xVal = 'F';
			return xVal;
		}
		if(xVal == 'g')
		{
			xVal = 'G';
			return xVal;
		}
		if(xVal == 'h')
		{
			xVal = 'H';
			return xVal;
		}
		if(xVal == 'i')
		{
			xVal = 'I';
			return xVal;
		}
		if(xVal == 'j')
		{
			xVal = 'J';
			return xVal;
		}
	}
	
	char convertXNumberToLetter(int xVal)
	{
		if(xVal == 0)
		{
			xVal = 'A';
			return xVal;
		}
		if(xVal == 1)
		{
			xVal = 'B';
			return xVal;
		}
		if(xVal == 2)
		{
			xVal = 'C';
			return xVal;
		}
		if(xVal == 3)
		{
			xVal = 'D';
			return xVal;
		}
		if(xVal == 4)
		{
			xVal = 'E';
			return xVal;
		}
		if(xVal == 5)
		{
			xVal = 'F';
			return xVal;
		}
		if(xVal == 6)
		{
			xVal = 'G';
			return xVal;
		}
		if(xVal == 7)
		{
			xVal = 'H';
			return xVal;
		}
		if(xVal == 8)
		{
			xVal = 'I';
			return xVal;
		}
		if(xVal == 9)
		{
			xVal = 'J';
			return xVal;
		}
	}
	
void printPlayerOneMessage()
{ 
	if(playerOneFire == 0)
	{
		printf("                               ---------------------\n");
		printf("                               Player One\n");
		printf("                               Fire Tomahawk missile\n");
		printf("                               ---------------------\n\n");
	}
	
	if(playerOneFire == 1)
	{
		printf("                               ----------------------------------\n");
		printf("                               Player One's missile landed at %c%d\n", fireX, fireY);
		printf("                               ----------------------------------\n\n\n");
	}
	
	if(playerOneFire == 2)
	{
		printf("                               --------------\n");
		printf("                               You Won!\n");
		printf("                               The Enemy Lost\n");
		printf("                               --------------\n\n");
	}
	
	if(playerOneFire == 3)
	{
		printf("                               ---------------\n");
		printf("                               Player One Won!\n");
		printf("                               Player Two Lost\n");
		printf("                               ---------------\n\n");
	}
		
	playerOneFire = 0;
	playerTwoFire = 0;
	enemyFire = 0;
}

void printPlayerTwoMessage()
{
	if(playerTwoFire == 0 && enemyFire != 1 && enemyFire != 2)
	{
		printf("                               ---------------------\n");
		printf("                               Player Two\n");
		printf("                               Fire Tomahawk missile\n");
		printf("                               ---------------------\n\n");
	}
	
	if(playerTwoFire == 1)
	{
		printf("                               ----------------------------------\n");
		printf("                               Player Two's missile landed at %c%d\n", fireX, fireY);
		printf("                               ----------------------------------\n\n\n");
	}
	
	if(playerTwoFire == 3)
	{
		printf("                               ---------------\n");
		printf("                               Player Two Won!\n");
		printf("                               Player One Lost\n");
		printf("                               ---------------\n\n");
	}
	
	if(enemyFire == 1)
	{
		printf("                               ---------------------------------\n");
		printf("                               The Enemy's missile landed at %c%d\n", fireX, fireY);
		printf("                               ---------------------------------\n\n\n");
	}
	
	if(enemyFire == 2)
	{
		printf("                               --------------\n");
		printf("                               The Enemy Won!\n");
		printf("                               You Lost\n");
		printf("                               --------------\n\n");
	}
	
	playerOneFire = 0;
	playerTwoFire = 0;
	enemyFire = 0;
}
	
// **********************************printStatus*************************************************************************************
void printStatus()
{
if(fire == 1)
{
                  
printf("                       ______________________________________________________________\n");
printf("                      |+                                                            +|\n");
printf("                      | ░░░░░░       ░░░        ░░░      ░░░       ░░░  ░░░░  ░░░░░░ |\n");
printf("                      | ▒▒▒▒▒▒  ▒▒▒▒  ▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒  ▒▒▒▒  ▒▒▒  ▒▒  ▒▒▒▒▒▒▒ |\n");
printf("                      | ▓▓▓▓▓▓       ▓▓▓      ▓▓▓▓  ▓▓▓▓  ▓▓  ▓▓▓▓  ▓▓▓▓    ▓▓▓▓▓▓▓▓ |\n");
printf("                      | ▒▒▒▒▒▒  ▒▒▒  ▒▒▒  ▒▒▒▒▒▒▒▒        ▒▒  ▒▒▒▒  ▒▒▒▒▒  ▒▒▒▒▒▒▒▒▒ |\n");
printf("                      | ░░░░░░  ░░░░  ░░        ░░  ░░░░  ░░       ░░░░░░  ░░░░░░░░░ |\n");
printf("                      |                                                              |\n");
printf("                      | ┏┓┳┓┏┓┏┓┏┓┳┓┏┓     ┳┓┏┓┏┳┓┏┳┓┓ ┏┓╻  Your Total Damage: %s%d/17 |\n", spacesDamage, numOfTotalDamage);
printf("                      | ┃┃┣┫┣ ┃┃┣┫┣┫┣  for ┣┫┣┫ ┃  ┃ ┃ ┣ ┃ Enemy Total Damage: %s%d/17 |\n", spacesHits, numOfTotalHits);
printf("                      | ┣┛┛┗┗┛┣┛┛┗┛┗┗┛     ┻┛┛┗ ┻  ┻ ┗┛┗┛•                           |\n");
printf("                      |        |--------------------------COMMANDER'S LOG---|        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | You just say exactly where to fire and     |        |\n");
printf("                      |        | your Gunner's Mate will launch a BGM-109   |        |\n");
printf("                      |        | Tomahawk Anti-Ship Missile straight into   |        |\n");
printf("                      |        | the fog never to be seen again...          |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | Hopefully, you hear it though.             |        |\n");
printf("                      |        | Completely obliterating the enemy!         |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |----Enter a coordinate to fire a Tomahawk---|        |\n");
printf("                      |                                                              |\n");
printf("                      |+____________________________[++]____________________________+|\n");
printf(" \n");
}

if(fire2 == 1)
{                                            

printf("                       ______________________________________________________________\n");
printf("                      |+                                                            +|\n");
printf("                      | ░░░░░░       ░░░        ░░░      ░░░       ░░░  ░░░░  ░░░░░░ |\n");
printf("                      | ▒▒▒▒▒▒  ▒▒▒▒  ▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒  ▒▒▒▒  ▒▒▒  ▒▒  ▒▒▒▒▒▒▒ |\n");
printf("                      | ▓▓▓▓▓▓       ▓▓▓      ▓▓▓▓  ▓▓▓▓  ▓▓  ▓▓▓▓  ▓▓▓▓    ▓▓▓▓▓▓▓▓ |\n");
printf("                      | ▒▒▒▒▒▒  ▒▒▒  ▒▒▒  ▒▒▒▒▒▒▒▒        ▒▒  ▒▒▒▒  ▒▒▒▒▒  ▒▒▒▒▒▒▒▒▒ |\n");
printf("                      | ░░░░░░  ░░░░  ░░        ░░  ░░░░  ░░       ░░░░░░  ░░░░░░░░░ |\n");
printf("                      |                                                              |\n");
printf("                      |      ┏┓┳┳┓┏┓  ┳┳┓┳┏┓┏┓┳┓ ┏┓╻        Your Total Damage: %s%d/17 |\n", spacesDamage, numOfTotalDamage);
printf("                      |      ┣ ┃┣┫┣   ┃┃┃┃┗┓┗┓┃┃ ┣ ┃       Enemy Total Damage: %s%d/17 |\n", spacesHits, numOfTotalHits);
printf("                      |      ┻ ┻┛┗┗┛  ┛ ┗┻┗┛┗┛┻┗┛┗┛•                                 |\n");
printf("                      |        |--------------------------COMMANDER'S LOG---|        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | You just say exactly where to fire and     |        |\n");
printf("                      |        | your Gunner's Mate will launch a BGM-109   |        |\n");
printf("                      |        | Tomahawk Anti-Ship Missile straight into   |        |\n");
printf("                      |        | the fog never to be seen again...          |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | Hopefully, you hear it though.             |        |\n");
printf("                      |        | Completely obliterating the enemy!         |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |----Enter a coordinate to fire a Tomahawk---|        |\n");
printf("                      |                                                              |\n");
printf("                      |+____________________________[++]____________________________+|\n");
printf(" \n");
} 
		
//If you missed the enemy
if(miss == 1 && seagullGuess == 0)
{
printf("                       ______________________________________________________________\n");
printf("                      |+                                                            +|\n");
printf("                      | ░  ░░░░  ░░        ░░░      ░░░░      ░░░        ░░       ░░ |\n");
printf("                      | ▒   ▒▒   ▒▒▒▒▒  ▒▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒ |\n");
printf("                      | ▓        ▓▓▓▓▓  ▓▓▓▓▓▓      ▓▓▓▓      ▓▓▓      ▓▓▓▓  ▓▓▓▓  ▓ |\n");
printf("                      | ▒  ▒  ▒  ▒▒▒▒▒  ▒▒▒▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒ |\n");
printf("                      | ░  ░░░░  ░░        ░░░      ░░░░      ░░░        ░░       ░░ |\n");
printf("                      |                                                              |\n");
printf("                      |     ┳┳┓┳┏┓┏┓┏┓┳┓     ┏┓┳┓┏┓┳┳┓┓┏╻   Your Total Damage: %s%d/17 |\n", spacesDamage, numOfTotalDamage);
printf("                      | You ┃┃┃┃┗┓┗┓┣ ┃┃ the ┣ ┃┃┣ ┃┃┃┗┫┃  Enemy Total Damage: %s%d/17 |\n", spacesHits, numOfTotalHits);
printf("                      |     ┛ ┗┻┗┛┗┛┗┛┻┛     ┗┛┛┗┗┛┛ ┗┗┛•                            |\n");
printf("                      |        |--------------------------COMMANDER'S LOG---|        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | Using your binoculars you scan the horizon |        |\n");
printf("                      |        | but see nothing that would give you the    |        |\n");
printf("                      |        | indication that you hit anything.          |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | You return to the bridge hearing multiple  |        |\n");
printf("                      |        | alarms. Radars are detecting an incoming   |        |\n");
printf("                      |        | missile. Countermeasures must be taken.    |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |-----------Press [E]nter to deploy flares---|        |\n");
printf("                      |                                                              |\n");
printf("                      |+____________________________[++]____________________________+|\n");
printf(" \n");
}

//If you didn't listen to the seagull and missed the enemy
if(seagullGuess == 1 && seagullMatch == 0 && miss == 1)
{
printf("                       ______________________________________________________________\n");
printf("                      |+                                                            +|\n");
printf("                      | ░  ░░░░  ░░        ░░░      ░░░░      ░░░        ░░       ░░ |\n");
printf("                      | ▒   ▒▒   ▒▒▒▒▒  ▒▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒ |\n");
printf("                      | ▓        ▓▓▓▓▓  ▓▓▓▓▓▓      ▓▓▓▓      ▓▓▓      ▓▓▓▓  ▓▓▓▓  ▓ |\n");
printf("                      | ▒  ▒  ▒  ▒▒▒▒▒  ▒▒▒▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒ |\n");
printf("                      | ░  ░░░░  ░░        ░░░      ░░░░      ░░░        ░░       ░░ |\n");
printf("                      |                                                              |\n");
printf("                      |     ┳┳┓┳┏┓┏┓┏┓┳┓     ┏┓┳┓┏┓┳┳┓┓┏╻   Your Total Damage: %s%d/17 |\n", spacesDamage, numOfTotalDamage);
printf("                      | You ┃┃┃┃┗┓┗┓┣ ┃┃ the ┣ ┃┃┣ ┃┃┃┗┫┃  Enemy Total Damage: %s%d/17 |\n", spacesHits, numOfTotalHits);
printf("                      |     ┛ ┗┻┗┛┗┛┗┛┻┛     ┗┛┛┗┗┛┛ ┗┗┛•                            |\n");
printf("                      |        |--------------------------COMMANDER'S LOG---|        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | Maybe you should have listened to that seagull. |        |\n");
printf("                      |        | but see nothing that would give you the    |        |\n");
printf("                      |        | indication that you hit anything.          |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | You return to the bridge hearing multiple  |        |\n");
printf("                      |        | alarms. Radars are detecting an incoming   |        |\n");
printf("                      |        | missile. Countermeasures must be taken.    |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |-----------Press [E]nter to deploy flares---|        |\n");
printf("                      |                                                              |\n");
printf("                      |+____________________________[++]____________________________+|\n");
printf(" \n");
}

//If you did listen to the seagull and missed the enemy
if(seagullGuess == 1 && seagullMatch == 1 && miss == 1)
{
printf("                       ______________________________________________________________\n");
printf("                      |+                                                            +|\n");
printf("                      | ░  ░░░░  ░░        ░░░      ░░░░      ░░░        ░░       ░░ |\n");
printf("                      | ▒   ▒▒   ▒▒▒▒▒  ▒▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒ |\n");
printf("                      | ▓        ▓▓▓▓▓  ▓▓▓▓▓▓      ▓▓▓▓      ▓▓▓      ▓▓▓▓  ▓▓▓▓  ▓ |\n");
printf("                      | ▒  ▒  ▒  ▒▒▒▒▒  ▒▒▒▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒ |\n");
printf("                      | ░  ░░░░  ░░        ░░░      ░░░░      ░░░        ░░       ░░ |\n");
printf("                      |                                                              |\n");
printf("                      |     ┳┳┓┳┏┓┏┓┏┓┳┓     ┏┓┳┓┏┓┳┳┓┓┏╻   Your Total Damage: %s%d/17 |\n", spacesDamage, numOfTotalDamage);
printf("                      | You ┃┃┃┃┗┓┗┓┣ ┃┃ the ┣ ┃┃┣ ┃┃┃┗┫┃  Enemy Total Damage: %s%d/17 |\n", spacesHits, numOfTotalHits);
printf("                      |     ┛ ┗┻┗┛┗┛┗┛┻┛     ┗┛┛┗┗┛┛ ┗┗┛•                            |\n");
printf("                      |        |--------------------------COMMANDER'S LOG---|        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | You definitely should not have listened to that seagull. |        |\n");
printf("                      |        | but see nothing that would give you the    |        |\n");
printf("                      |        | indication that you hit anything.          |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | You return to the bridge hearing multiple  |        |\n");
printf("                      |        | alarms. Radars are detecting an incoming   |        |\n");
printf("                      |        | missile. Countermeasures must be taken.    |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |-----------Press [E]nter to deploy flares---|        |\n");
printf("                      |                                                              |\n");
printf("                      |+____________________________[++]____________________________+|\n");
printf(" \n");
} 
		
//If enemy missed you
if(enemyMissMe == 1)
{
printf("                       ______________________________________________________________\n");
printf("                      |+                                                            +|\n");
printf("                      | ░  ░░░░  ░░        ░░░      ░░░░      ░░░        ░░       ░░ |\n");
printf("                      | ▒   ▒▒   ▒▒▒▒▒  ▒▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒ |\n");
printf("                      | ▓        ▓▓▓▓▓  ▓▓▓▓▓▓      ▓▓▓▓      ▓▓▓      ▓▓▓▓  ▓▓▓▓  ▓ |\n");
printf("                      | ▒  ▒  ▒  ▒▒▒▒▒  ▒▒▒▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒ |\n");
printf("                      | ░  ░░░░  ░░        ░░░      ░░░░      ░░░        ░░       ░░ |\n");
printf("                      |                                                              |\n");
printf("                      |           ┳┳┓┳┏┓┏┓┏┓┳┓ ┓┏┏┓┳┳╻      Your Total Damage: %s%d/17 |\n", spacesDamage, numOfTotalDamage);
printf("                      | The Enemy ┃┃┃┃┗┓┗┓┣ ┃┃ ┗┫┃┃┃┃┃     Enemy Total Damage: %s%d/17 |\n", spacesHits, numOfTotalHits);
printf("                      |           ┛ ┗┻┗┛┗┛┗┛┻┛ ┗┛┗┛┗┛•                               |\n");
printf("                      |        |--------------------------COMMANDER'S LOG---|        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | After the smoke from the flares clears you |        |\n");
printf("                      |        | realize that it is unsettlingly quiet. You |        |\n");
printf("                      |        | demand a damage report and come to the     |        |\n");
printf("                      |        | conclusion that your fleet has not been    |        |\n");
printf("                      |        | hit.                                       |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | You count your blessings and quickly load  |        |\n");
printf("                      |        | another Tomahawk missile.                  |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |----------Press [E]nter to load a missile---|        |\n");
printf("                      |                                                              |\n");
printf("                      |+____________________________[++]____________________________+|\n");
printf(" \n");
} 
		
//If you hit enemy but dont sink anything
if(hit == 1 && seagullGuess == 0)
{
printf("                       ______________________________________________________________\n");
printf("                      |+                                                            +|\n");
printf("                      | ░░░░░░░░░░░░░░░░  ░░░░  ░░        ░░        ░░░░░░░░░░░░░░░░ |\n");
printf("                      |   ▒▒▒▒▒▒▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒   |\n");
printf("                      |     ▓▓▓▓▓▓▓▓▓▓▓▓        ▓▓▓▓▓  ▓▓▓▓▓▓▓▓  ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓     |\n");
printf("                      |       ▒▒▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒▒▒▒▒▒       |\n");
printf("                      |         ░░░░░░░░  ░░░░  ░░        ░░░░░  ░░░░░░░░░░░         |\n");
printf("                      |                                                              |\n");
printf("                      |     ┓┏┳┏┳┓     ┏┓┳┓┏┓┳┳┓┓┏╻         Your Total Damage: %s%d/17 |\n", spacesDamage, numOfTotalDamage);
printf("                      | You ┣┫┃ ┃  the ┣ ┃┃┣ ┃┃┃┗┫┃        Enemy Total Damage: %s%d/17 |\n", spacesHits, numOfTotalHits);
printf("                      |     ┛┗┻ ┻      ┗┛┛┗┗┛┛ ┗┗┛•                                  |\n");
printf("                      |        |--------------------------COMMANDER'S LOG---|        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | An unidentified ship smolders on the       |        |\n");
printf("                      |        | horizon. You have hit one of the enemy's   |        |\n");
printf("                      |        | fleet.                                     |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | Suddenly, multiple warnings begin          |        |\n");
printf("                      |        | sounding. Radars are detecting an incoming |        |\n");
printf("                      |        | missile. Take countermeasures or risk      |        |\n");
printf("                      |        | damage to your fleet.                      |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |-----------Press [E]nter to deploy flares---|        |\n");
printf("                      |                                                              |\n");
printf("                      |+____________________________[++]____________________________+|\n");
printf(" \n");
}

//If you didn't listen to the seagull and hit the enemy but dont sink anything
if(seagullGuess == 1 && seagullMatch == 0 && hit == 1)
{
printf("                       ______________________________________________________________\n");
printf("                      |+                                                            +|\n");
printf("                      | ░░░░░░░░░░░░░░░░  ░░░░  ░░        ░░        ░░░░░░░░░░░░░░░░ |\n");
printf("                      |   ▒▒▒▒▒▒▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒   |\n");
printf("                      |     ▓▓▓▓▓▓▓▓▓▓▓▓        ▓▓▓▓▓  ▓▓▓▓▓▓▓▓  ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓     |\n");
printf("                      |       ▒▒▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒▒▒▒▒▒       |\n");
printf("                      |         ░░░░░░░░  ░░░░  ░░        ░░░░░  ░░░░░░░░░░░         |\n");
printf("                      |                                                              |\n");
printf("                      |     ┓┏┳┏┳┓     ┏┓┳┓┏┓┳┳┓┓┏╻         Your Total Damage: %s%d/17 |\n", spacesDamage, numOfTotalDamage);
printf("                      | You ┣┫┃ ┃  the ┣ ┃┃┣ ┃┃┃┗┫┃        Enemy Total Damage: %s%d/17 |\n", spacesHits, numOfTotalHits);
printf("                      |     ┛┗┻ ┻      ┗┛┛┗┗┛┛ ┗┗┛•                                  |\n");
printf("                      |        |--------------------------COMMANDER'S LOG---|        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | You decided to go with your own gut and it pays off.       |        |\n");
printf("                      |        | horizon. You have hit one of the enemy's   |        |\n");
printf("                      |        | fleet.                                     |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | Suddenly, multiple warnings begin          |        |\n");
printf("                      |        | sounding. Radars are detecting an incoming |        |\n");
printf("                      |        | missile. Take countermeasures or risk      |        |\n");
printf("                      |        | damage to your fleet.                      |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |-----------Press [E]nter to deploy flares---|        |\n");
printf("                      |                                                              |\n");
printf("                      |+____________________________[++]____________________________+|\n");
printf(" \n");
}

//If you did listen to the seagull and hit the enemy but dont sink anything
if(seagullGuess == 1 && seagullMatch == 1 && hit == 1)
{
printf("                       ______________________________________________________________\n");
printf("                      |+                                                            +|\n");
printf("                      | ░░░░░░░░░░░░░░░░  ░░░░  ░░        ░░        ░░░░░░░░░░░░░░░░ |\n");
printf("                      |   ▒▒▒▒▒▒▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒   |\n");
printf("                      |     ▓▓▓▓▓▓▓▓▓▓▓▓        ▓▓▓▓▓  ▓▓▓▓▓▓▓▓  ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓     |\n");
printf("                      |       ▒▒▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒▒▒▒▒▒       |\n");
printf("                      |         ░░░░░░░░  ░░░░  ░░        ░░░░░  ░░░░░░░░░░░         |\n");
printf("                      |                                                              |\n");
printf("                      |     ┓┏┳┏┳┓     ┏┓┳┓┏┓┳┳┓┓┏╻         Your Total Damage: %s%d/17 |\n", spacesDamage, numOfTotalDamage);
printf("                      | You ┣┫┃ ┃  the ┣ ┃┃┣ ┃┃┃┗┫┃        Enemy Total Damage: %s%d/17 |\n", spacesHits, numOfTotalHits);
printf("                      |     ┛┗┻ ┻      ┗┛┛┗┗┛┛ ┗┗┛•                                  |\n");
printf("                      |        |--------------------------COMMANDER'S LOG---|        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | Fire your therapist and send out a crew to find that bird!       |        |\n");
printf("                      |        | horizon. You have hit one of the enemy's   |        |\n");
printf("                      |        | fleet.                                     |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | Suddenly, multiple warnings begin          |        |\n");
printf("                      |        | sounding. Radars are detecting an incoming |        |\n");
printf("                      |        | missile. Take countermeasures or risk      |        |\n");
printf("                      |        | damage to your fleet.                      |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |-----------Press [E]nter to deploy flares---|        |\n");
printf("                      |                                                              |\n");
printf("                      |+____________________________[++]____________________________+|\n");
printf(" \n");
}

//If you hit the enemy and sink the Carrier
if(enemyCARSunk == 1)
{
printf("                       ______________________________________________________________\n");
printf("                      |+                                                            +|\n");
printf("                      |         ░░░░      ░░░  ░░░░  ░░   ░░░  ░░  ░░░░  ░░░         |\n");
printf("                      |       ░░░░░  ░░░░░░░░  ░░░░  ░░    ░░  ░░  ░░░  ░░░░░░       |\n");
printf("                      |     ▒▒▒▒▒▒▒▒      ▒▒▒  ▒▒▒▒  ▒▒  ▒  ▒  ▒▒     ▒▒▒▒▒▒▒▒▒▒     |\n");
printf("                      |   ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒  ▒▒  ▒▒▒▒  ▒▒  ▒▒    ▒▒  ▒▒▒  ▒▒▒▒▒▒▒▒▒▒   |\n");
printf("                      | ▓▓▓▓▓▓▓▓▓▓▓▓      ▓▓▓▓      ▓▓▓  ▓▓▓   ▓▓  ▓▓▓▓  ▓▓▓▓▓▓▓▓▓▓▓ |\n");
printf("                      |                                                              |\n");
printf("                      |           ┏┓ ┏┓ ┳┓ ┓┏┓           ┏┓ ┏┓ ┳┓ ┳┓ ┳ ┏┓ ┳┓ ╻       |\n");
printf("                      |       You ┗┓ ┣┫ ┃┃ ┃┫  the Enemy ┃  ┣┫ ┣┫ ┣┫ ┃ ┣  ┣┫ ┃       |\n");
printf("                      |           ┗┛ ┛┗ ┛┗ ┛┗┛           ┗┛ ┛┗ ┛┗ ┛┗ ┻ ┗┛ ┛┗ •       |\n");
printf("                      |        |--------------------------COMMANDER'S LOG---|        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | The Aircraft Carrier is sinking rather     |        |\n");
printf("                      |        | quickly for its size. Physics truly has no |        |\n");
printf("                      |        | master at sea.                             |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | The sight holds you for a moment but your  |        |\n");
printf("                      |        | thoughts are soon interrupted by the       |        |\n");
printf("                      |        | familiar and distant sound of a missile    |        |\n");
printf("                      |        | being fired.                               |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | Your fleet demands your attention.         |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |---------------Press [E] to deploy flares---|        |\n");
printf("                      |                                                              |\n");
printf("                      |+____________________________[++]____________________________+|\n");
printf(" \n");
}

if(enemyBATSunk == 1)
{
printf("                       ______________________________________________________________\n");
printf("                      |+                                                            +|\n");
printf("                      |         ░░░░      ░░░  ░░░░  ░░   ░░░  ░░  ░░░░  ░░░         |\n");
printf("                      |       ░░░░░  ░░░░░░░░  ░░░░  ░░    ░░  ░░  ░░░  ░░░░░░       |\n");
printf("                      |     ▒▒▒▒▒▒▒▒      ▒▒▒  ▒▒▒▒  ▒▒  ▒  ▒  ▒▒     ▒▒▒▒▒▒▒▒▒▒     |\n");
printf("                      |   ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒  ▒▒  ▒▒▒▒  ▒▒  ▒▒    ▒▒  ▒▒▒  ▒▒▒▒▒▒▒▒▒▒   |\n");
printf("                      | ▓▓▓▓▓▓▓▓▓▓▓▓      ▓▓▓▓      ▓▓▓  ▓▓▓   ▓▓  ▓▓▓▓  ▓▓▓▓▓▓▓▓▓▓▓ |\n");
printf("                      |                                                              |\n");
printf("                      |     ┏┓ ┏┓ ┳┓ ┓┏┓           ┳┓ ┏┓ ┏┳┓ ┏┳┓ ┓  ┏┓ ┏┓ ┓┏ ┳ ┏┓ ╻  |\n");
printf("                      | You ┗┓ ┣┫ ┃┃ ┃┫  the Enemy ┣┫ ┣┫  ┃   ┃  ┃  ┣  ┗┓ ┣┫ ┃ ┃┃ ┃  |\n");
printf("                      |     ┗┛ ┛┗ ┛┗ ┛┗┛           ┻┛ ┛┗  ┻   ┻  ┗┛ ┗┛ ┗┛ ┛┗ ┻ ┣┛ •  |\n");
printf("                      |        |--------------------------COMMANDER'S LOG---|        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | The Battleship no longer resembles a ship, |        |\n");
printf("                      |        | and thus, no longer floats! It definitely  |        |\n");
printf("                      |        | loses its foreboading presence when half   |        |\n");
printf("                      |        | of its armaments are submerged.            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | Faintly, you hear a seagull and can swear  |        |\n");
printf("                      |        | it just said \"Deploy flares.\" in a         |        |\n");
printf("                      |        | squawky voice... Good idea, buddy.         |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |-----------Press [E]nter to deploy flares---|        |\n");
printf("                      |                                                              |\n");
printf("                      |+____________________________[++]____________________________+|\n");
printf(" \n");
}
                    
if(enemyDESSunk == 1)
{
printf("                       ______________________________________________________________\n");
printf("                      |+                                                            +|\n");
printf("                      |         ░░░░      ░░░  ░░░░  ░░   ░░░  ░░  ░░░░  ░░░         |\n");
printf("                      |       ░░░░░  ░░░░░░░░  ░░░░  ░░    ░░  ░░  ░░░  ░░░░░░       |\n");
printf("                      |     ▒▒▒▒▒▒▒▒      ▒▒▒  ▒▒▒▒  ▒▒  ▒  ▒  ▒▒     ▒▒▒▒▒▒▒▒▒▒     |\n");
printf("                      |   ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒  ▒▒  ▒▒▒▒  ▒▒  ▒▒    ▒▒  ▒▒▒  ▒▒▒▒▒▒▒▒▒▒   |\n");
printf("                      | ▓▓▓▓▓▓▓▓▓▓▓▓      ▓▓▓▓      ▓▓▓  ▓▓▓   ▓▓  ▓▓▓▓  ▓▓▓▓▓▓▓▓▓▓▓ |\n");
printf("                      |                                                              |\n");
printf("                      |       ┏┓ ┏┓ ┳┓ ┓┏┓           ┳┓ ┏┓ ┏┓ ┏┳┓ ┳┓ ┏┓ ┓┏ ┏┓ ┳┓ ╻   |\n");
printf("                      |   You ┗┓ ┣┫ ┃┃ ┃┫  the Enemy ┃┃ ┣  ┗┓  ┃  ┣┫ ┃┃ ┗┫ ┣  ┣┫ ┃   |\n");
printf("                      |       ┗┛ ┛┗ ┛┗ ┛┗┛           ┻┛ ┗┛ ┗┛  ┻  ┛┗ ┗┛ ┗┛ ┗┛ ┛┗ •   |\n");
printf("                      |        |--------------------------COMMANDER'S LOG---|        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | The Destroyer is set ablaze and            |        |\n");
printf("                      |        | unsurvivable! The unquenchable flames on   |        |\n");
printf("                      |        | top of the waves make you think of light   |        |\n");
printf("                      |        | and dark, good and evil, right and         |        |\n");
printf("                      |        | wrong...                                   |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | You don't have long to contemplate the     |        |\n");
printf("                      |        | existence of objective morality.           |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | Flares are ready. Time to choose...        |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |-----------Press [E]nter to deploy flares---|        |\n");
printf("                      |                                                              |\n");
printf("                      |+____________________________[++]____________________________+|\n");
printf(" \n");
}
                   
if(enemySUBSunk == 1)
{
printf("                       ______________________________________________________________\n");
printf("                      |+                                                            +|\n");
printf("                      |         ░░░░      ░░░  ░░░░  ░░   ░░░  ░░  ░░░░  ░░░         |\n");
printf("                      |       ░░░░░  ░░░░░░░░  ░░░░  ░░    ░░  ░░  ░░░  ░░░░░░       |\n");
printf("                      |     ▒▒▒▒▒▒▒▒      ▒▒▒  ▒▒▒▒  ▒▒  ▒  ▒  ▒▒     ▒▒▒▒▒▒▒▒▒▒     |\n");
printf("                      |   ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒  ▒▒  ▒▒▒▒  ▒▒  ▒▒    ▒▒  ▒▒▒  ▒▒▒▒▒▒▒▒▒▒   |\n");
printf("                      | ▓▓▓▓▓▓▓▓▓▓▓▓      ▓▓▓▓      ▓▓▓  ▓▓▓   ▓▓  ▓▓▓▓  ▓▓▓▓▓▓▓▓▓▓▓ |\n");
printf("                      |                                                              |\n");
printf("                      |       ┏┓ ┏┓ ┳┓ ┓┏┓           ┏┓ ┳┳ ┳┓ ┳┳┓ ┏┓ ┳┓ ┳ ┳┓ ┏┓ ╻    |\n");
printf("                      |   You ┗┓ ┣┫ ┃┃ ┃┫  the Enemy ┗┓ ┃┃ ┣┫ ┃┃┃ ┣┫ ┣┫ ┃ ┃┃ ┣  ┃    |\n");
printf("                      |       ┗┛ ┛┗ ┛┗ ┛┗┛           ┗┛ ┗┛ ┻┛ ┛ ┗ ┛┗ ┛┗ ┻ ┛┗ ┗┛ •    |\n");
printf("                      |        |--------------------------COMMANDER'S LOG---|        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | The Submarine fades from your radar and    |        |\n");
printf("                      |        | will surface no more! The depths, and the  |        |\n");
printf("                      |        | depths alone, speak for those souls now.   |        |\n");
printf("                      |        | May the Father have mercy on them all.     |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | You and your men on board have a bad       |        |\n");
printf("                      |        | feeling about this.                        |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | Eyes open. Guard up. Flares ready.         |        |\n");
printf("                      |        | May the force be with you.                 |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |-----------Press [E]nter to deploy flares---|        |\n");
printf("                      |                                                              |\n");
printf("                      |+____________________________[++]____________________________+|\n");
printf(" \n");
}
  
if(enemyPATSunk == 1)
{
printf("                       ______________________________________________________________\n");
printf("                      |+                                                            +|\n");
printf("                      |         ░░░░      ░░░  ░░░░  ░░   ░░░  ░░  ░░░░  ░░░         |\n");
printf("                      |       ░░░░░  ░░░░░░░░  ░░░░  ░░    ░░  ░░  ░░░  ░░░░░░       |\n");
printf("                      |     ▒▒▒▒▒▒▒▒      ▒▒▒  ▒▒▒▒  ▒▒  ▒  ▒  ▒▒     ▒▒▒▒▒▒▒▒▒▒     |\n");
printf("                      |   ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒  ▒▒  ▒▒▒▒  ▒▒  ▒▒    ▒▒  ▒▒▒  ▒▒▒▒▒▒▒▒▒▒   |\n");
printf("                      | ▓▓▓▓▓▓▓▓▓▓▓▓      ▓▓▓▓      ▓▓▓  ▓▓▓   ▓▓  ▓▓▓▓  ▓▓▓▓▓▓▓▓▓▓▓ |\n");
printf("                      |                                                              |\n");
printf("                      |    ┏┓ ┏┓ ┳┓ ┓┏┓           ┏┓ ┏┓ ┏┳┓ ┳┓ ┏┓ ┓   ┳┓ ┏┓ ┏┓ ┏┳┓ ╻ |\n");
printf("                      |You ┗┓ ┣┫ ┃┃ ┃┫  the Enemy ┃┃ ┣┫  ┃  ┣┫ ┃┃ ┃   ┣┫ ┃┃ ┣┫  ┃  ┃ |\n");
printf("                      |    ┗┛ ┛┗ ┛┗ ┛┗┛           ┣┛ ┛┗  ┻  ┛┗ ┗┛ ┗┛  ┻┛ ┗┛ ┛┗  ┻  • |\n");
printf("                      |        |--------------------------COMMANDER'S LOG---|        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | The Patrol Boat is smoldering and          |        |\n");
printf("                      |        | unrecognizable! It's almost as if it never |        |\n");
printf("                      |        | existed.                                   |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | Suddenly, you almost remember that your    |        |\n");
printf("                      |        | own patrol boat is due for mandatory hull  |        |\n");
printf("                      |        | integrity maintenance. Or MHIM for short.  |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | Now, where did you set those binoculars?   |        |\n");
printf("                      |        | You sense trouble on the horizon.          |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |-----------Press [E]nter to deploy flares---|        |\n");
printf("                      |                                                              |\n");
printf("                      |+____________________________[++]____________________________+|\n");
printf(" \n");
}
		
//If enemy hits you
if(enemyHitMe == 1)
{
printf("                       ______________________________________________________________\n");
printf("                      |+                                                            +|\n");
printf("                      | ░░░░░░░░░░░░░░░░  ░░░░  ░░        ░░        ░░░░░░░░░░░░░░░░ |\n");
printf("                      |   ▒▒▒▒▒▒▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒   |\n");
printf("                      |     ▓▓▓▓▓▓▓▓▓▓▓▓        ▓▓▓▓▓  ▓▓▓▓▓▓▓▓  ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓     |\n");
printf("                      |       ▒▒▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒▒▒▒▒▒       |\n");
printf("                      |         ░░░░░░░░  ░░░░  ░░        ░░░░░  ░░░░░░░░░░░         |\n");
printf("                      |                                                              |\n");
printf("                      |           ┓┏ ┳ ┏┳┓  ┓┏ ┏┓ ┳┳ ╻      Your Total Damage: %s%d/17 |\n", spacesDamage, numOfTotalDamage);
printf("                      | The Enemy ┣┫ ┃  ┃   ┗┫ ┃┃ ┃┃ ┃     Enemy Total Damage: %s%d/17 |\n", spacesHits, numOfTotalHits);
printf("                      |           ┛┗ ┻  ┻   ┗┛ ┗┛ ┗┛ •                               |\n");
printf("                      |        |--------------------------COMMANDER'S LOG---|        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | The enemy hit our %s|        |\n", enemyHitWhich);
printf("                      |        |                                            |        |\n");
printf("                      |        | Pray...                                    |        |\n");
printf("                      |        | Pray...                                    |        |\n");
printf("                      |        | Pray...                                    |        |\n");
printf("                      |        | Amen.                                      |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |----------Press [E]nter to load a missile---|        |\n");
printf("                      |                                                              |\n");
printf("                      |+____________________________[++]____________________________+|\n");
printf(" \n");
}

//If the enemy hits your Carrier and sinks it
if(myCARSunk == 1)
{
printf("                       ______________________________________________________________\n");
printf("                      |+                                                            +|\n");
printf("                      |         ░░░░      ░░░  ░░░░  ░░   ░░░  ░░  ░░░░  ░░░         |\n");
printf("                      |       ░░░░░  ░░░░░░░░  ░░░░  ░░    ░░  ░░  ░░░  ░░░░░░       |\n");
printf("                      |     ▒▒▒▒▒▒▒▒      ▒▒▒  ▒▒▒▒  ▒▒  ▒  ▒  ▒▒     ▒▒▒▒▒▒▒▒▒▒     |\n");
printf("                      |   ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒  ▒▒  ▒▒▒▒  ▒▒  ▒▒    ▒▒  ▒▒▒  ▒▒▒▒▒▒▒▒▒▒   |\n");
printf("                      | ▓▓▓▓▓▓▓▓▓▓▓▓      ▓▓▓▓      ▓▓▓  ▓▓▓   ▓▓  ▓▓▓▓  ▓▓▓▓▓▓▓▓▓▓▓ |\n");
printf("                      |                                                              |\n");
printf("                      |                ┏┓ ┏┓ ┳┓ ┓┏┓      ┏┓ ┏┓ ┳┓ ┳┓ ┳ ┏┓ ┳┓ ╻       |\n");
printf("                      |      The Enemy ┗┓ ┣┫ ┃┃ ┃┫  Your ┃  ┣┫ ┣┫ ┣┫ ┃ ┣  ┣┫ ┃       |\n");
printf("                      |                ┗┛ ┛┗ ┛┗ ┛┗┛      ┗┛ ┛┗ ┛┗ ┛┗ ┻ ┗┛ ┛┗ •       |\n");
printf("                      |        |--------------------------COMMANDER'S LOG---|        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | You have lost all communications with your |        |\n");
printf("                      |        | Aircraft Carrier. It no longer broadcasts  |        |\n");
printf("                      |        | a radio signal to the fleet or shore base. |        |\n");
printf("                      |        | It's deck lights are not illuminated. Your |        |\n");
printf("                      |        | Carrier's Signalman is nowhere to be found |        |\n");
printf("                      |        | on deck. And all his signal flags are      |        |\n");
printf("                      |        | currently on fire and unable to be         |        |\n");
printf("                      |        | translated. Zero communications.           |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | Just as you are about to order a scout     |        |\n");
printf("                      |        | ship to investigate further, a massive     |        |\n");
printf("                      |        | explosion erupts at your Carrier's last    |        |\n");
printf("                      |        | known coordinates... your heart sinks.     |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |----------Press [E]nter to load a missile---|        |\n");
printf("                      |                                                              |\n");
printf("                      |+____________________________[++]____________________________+|\n");
printf(" \n");
}

if(myBATSunk == 1)
{
	createRandomX();
	createRandomY();
			
	//Make sure it's not a spot we already picked
	while(strcmp(" ~ ", playerCBoard[xRandom][yRandom]) != 0)
	{
		printf("Seagull already picked this spot x %d y %d\n", xRandom, yRandom);
		createRandomX();
		createRandomY();
	}
	printf("Seagull picks this spot x %d y %d\n", xRandom, yRandom);
	
	seagullGuess = 1;
	seagullX = xRandom;
	seagullY = yRandom;
	fireX = convertXNumberToLetter(xRandom);
	fireY = yRandom + 1;
				
printf("                       ______________________________________________________________\n");
printf("                      |+                                                            +|\n");
printf("                      |         ░░░░      ░░░  ░░░░  ░░   ░░░  ░░  ░░░░  ░░░         |\n");
printf("                      |       ░░░░░  ░░░░░░░░  ░░░░  ░░    ░░  ░░  ░░░  ░░░░░░       |\n");
printf("                      |     ▒▒▒▒▒▒▒▒      ▒▒▒  ▒▒▒▒  ▒▒  ▒  ▒  ▒▒     ▒▒▒▒▒▒▒▒▒▒     |\n");
printf("                      |   ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒  ▒▒  ▒▒▒▒  ▒▒  ▒▒    ▒▒  ▒▒▒  ▒▒▒▒▒▒▒▒▒▒   |\n");
printf("                      | ▓▓▓▓▓▓▓▓▓▓▓▓      ▓▓▓▓      ▓▓▓  ▓▓▓   ▓▓  ▓▓▓▓  ▓▓▓▓▓▓▓▓▓▓▓ |\n");
printf("                      |                                                              |\n");
printf("                      |           ┏┓ ┏┓ ┳┓ ┓┏┓      ┳┓ ┏┓ ┏┳┓ ┏┳┓ ┓  ┏┓ ┏┓ ┓┏ ┳ ┏┓ ╻ |\n");
printf("                      | The Enemy ┗┓ ┣┫ ┃┃ ┃┫  Your ┣┫ ┣┫  ┃   ┃  ┃  ┣  ┗┓ ┣┫ ┃ ┃┃ ┃ |\n");
printf("                      |           ┗┛ ┛┗ ┛┗ ┛┗┛      ┻┛ ┛┗  ┻   ┻  ┗┛ ┗┛ ┗┛ ┛┗ ┻ ┣┛ • |\n");
printf("                      |        |--------------------------COMMANDER'S LOG---|        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | On the wing, emerging towards you from the |        |\n");
printf("                      |        | rising ash of your annihilated Battleship  |        |\n");
printf("                      |        | is a seagull. You're not sure why but you  |        |\n");
printf("                      |        | can tell this is no ordinary bird.         |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | It perches on the handrail in front of you |        |\n");
printf("                      |        | and looks at you with it's only eye. After |        |\n");
printf("                      |        | a moment it squawks:                       |        |\n");
printf("                      |        |   \"Battleship sunk. Fire missile at %c%d.\"   |        |\n", fireX, fireY);
printf("                      |        | It poops, then flies away.                 |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | Now what did your therapist say about      |        |\n");
printf("                      |        | listening to seagulls that give you        |        |\n");
printf("                      |        | unsolicited advice during battle?          |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |----------Press [E]nter to load a missile---|        |\n");
printf("                      |                                                              |\n");
printf("                      |+____________________________[++]____________________________+|\n");
printf(" \n");
}

if(myDESSunk == 1)
{
printf("                       ______________________________________________________________\n");
printf("                      |+                                                            +|\n");
printf("                      |         ░░░░      ░░░  ░░░░  ░░   ░░░  ░░  ░░░░  ░░░         |\n");
printf("                      |       ░░░░░  ░░░░░░░░  ░░░░  ░░    ░░  ░░  ░░░  ░░░░░░       |\n");
printf("                      |     ▒▒▒▒▒▒▒▒      ▒▒▒  ▒▒▒▒  ▒▒  ▒  ▒  ▒▒     ▒▒▒▒▒▒▒▒▒▒     |\n");
printf("                      |   ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒  ▒▒  ▒▒▒▒  ▒▒  ▒▒    ▒▒  ▒▒▒  ▒▒▒▒▒▒▒▒▒▒   |\n");
printf("                      | ▓▓▓▓▓▓▓▓▓▓▓▓      ▓▓▓▓      ▓▓▓  ▓▓▓   ▓▓  ▓▓▓▓  ▓▓▓▓▓▓▓▓▓▓▓ |\n");
printf("                      |                                                              |\n");
printf("                      |            ┏┓ ┏┓ ┳┓ ┓┏┓      ┳┓ ┏┓ ┏┓ ┏┳┓ ┳┓ ┏┓ ┓┏ ┏┓ ┳┓ ╻   |\n");
printf("                      |  The Enemy ┗┓ ┣┫ ┃┃ ┃┫  Your ┃┃ ┣  ┗┓  ┃  ┣┫ ┃┃ ┗┫ ┣  ┣┫ ┃   |\n");
printf("                      |            ┗┛ ┛┗ ┛┗ ┛┗┛      ┻┛ ┗┛ ┗┛  ┻  ┛┗ ┗┛ ┗┛ ┗┛ ┛┗ •   |\n");
printf("                      |        |--------------------------COMMANDER'S LOG---|        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | After the carnage subsides, your Destroyer |        |\n");
printf("                      |        | is nowhere to be seen. You snatch your     |        |\n");
printf("                      |        | binoculars and frantically search the 360  |        |\n");
printf("                      |        | degrees of ocean around you...             |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | Nothing. Not even the wreckage. Not even   |        |\n");
printf("                      |        | survivors. Not even smoke.                 |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | What kind of technological weaponry        |        |\n");
printf("                      |        | capable of making a 15,000 ton Destroyer   |        |\n");
printf("                      |        | disappear does that guy have over there?   |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | Time to increase the R&D budget.           |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |----------Press [E]nter to load a missile---|        |\n");
printf("                      |                                                              |\n");
printf("                      |+____________________________[++]____________________________+|\n");
printf(" \n");
}

if(mySUBSunk == 1)
{
printf("                       ______________________________________________________________\n");
printf("                      |+                                                            +|\n");
printf("                      |         ░░░░      ░░░  ░░░░  ░░   ░░░  ░░  ░░░░  ░░░         |\n");
printf("                      |       ░░░░░  ░░░░░░░░  ░░░░  ░░    ░░  ░░  ░░░  ░░░░░░       |\n");
printf("                      |     ▒▒▒▒▒▒▒▒      ▒▒▒  ▒▒▒▒  ▒▒  ▒  ▒  ▒▒     ▒▒▒▒▒▒▒▒▒▒     |\n");
printf("                      |   ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒  ▒▒  ▒▒▒▒  ▒▒  ▒▒    ▒▒  ▒▒▒  ▒▒▒▒▒▒▒▒▒▒   |\n");
printf("                      | ▓▓▓▓▓▓▓▓▓▓▓▓      ▓▓▓▓      ▓▓▓  ▓▓▓   ▓▓  ▓▓▓▓  ▓▓▓▓▓▓▓▓▓▓▓ |\n");
printf("                      |                                                              |\n");
printf("                      |             ┏┓ ┏┓ ┳┓ ┓┏┓      ┏┓ ┳┳ ┳┓ ┳┳┓ ┏┓ ┳┓ ┳ ┳┓ ┏┓ ╻   |\n");
printf("                      |   The Enemy ┗┓ ┣┫ ┃┃ ┃┫  Your ┗┓ ┃┃ ┣┫ ┃┃┃ ┣┫ ┣┫ ┃ ┃┃ ┣  ┃   |\n");
printf("                      |             ┗┛ ┛┗ ┛┗ ┛┗┛      ┗┛ ┗┛ ┻┛ ┛ ┗ ┛┗ ┛┗ ┻ ┛┗ ┗┛ •   |\n");
printf("                      |        |--------------------------COMMANDER'S LOG---|        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | Your Submarine no longer shows on your     |        |\n");
printf("                      |        | radars. With a pit in your stomache so     |        |\n");
printf("                      |        | deep it could swallow black holes, you ask |        |\n");
printf("                      |        | your Operations Specialist if it's a       |        |\n");
printf("                      |        | glitch, but he only confirms your worst    |        |\n");
printf("                      |        | fears.                                     |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | You've lost 156 of your best men in the    |        |\n");
printf("                      |        | blink of an eye. There will be time to     |        |\n");
printf("                      |        | remember all of their names when this      |        |\n");
printf("                      |        | battle is over...                          |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | Gibbs... Jackson... Opie... Sugarts...     |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |----------Press [E]nter to load a missile---|        |\n");
printf("                      |                                                              |\n");
printf("                      |+____________________________[++]____________________________+|\n");
printf(" \n");
}

if(myPATSunk == 1)
{
printf("                       ______________________________________________________________\n");
printf("                      |+                                                            +|\n");
printf("                      |         ░░░░      ░░░  ░░░░  ░░   ░░░  ░░  ░░░░  ░░░         |\n");
printf("                      |       ░░░░░  ░░░░░░░░  ░░░░  ░░    ░░  ░░  ░░░  ░░░░░░       |\n");
printf("                      |     ▒▒▒▒▒▒▒▒      ▒▒▒  ▒▒▒▒  ▒▒  ▒  ▒  ▒▒     ▒▒▒▒▒▒▒▒▒▒     |\n");
printf("                      |   ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒  ▒▒  ▒▒▒▒  ▒▒  ▒▒    ▒▒  ▒▒▒  ▒▒▒▒▒▒▒▒▒▒   |\n");
printf("                      | ▓▓▓▓▓▓▓▓▓▓▓▓      ▓▓▓▓      ▓▓▓  ▓▓▓   ▓▓  ▓▓▓▓  ▓▓▓▓▓▓▓▓▓▓▓ |\n");
printf("                      |                                                              |\n");
printf("                      |          ┏┓ ┏┓ ┳┓ ┓┏┓      ┏┓ ┏┓ ┏┳┓ ┳┓ ┏┓ ┓   ┳┓ ┏┓ ┏┓ ┏┳┓ ╻|\n");
printf("                      |The Enemy ┗┓ ┣┫ ┃┃ ┃┫  Your ┃┃ ┣┫  ┃  ┣┫ ┃┃ ┃   ┣┫ ┃┃ ┣┫  ┃  ┃|\n");
printf("                      |          ┗┛ ┛┗ ┛┗ ┛┗┛      ┣┛ ┛┗  ┻  ┛┗ ┗┛ ┗┛  ┻┛ ┗┛ ┛┗  ┻  •|\n");
printf("                      |        |--------------------------COMMANDER'S LOG---|        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | \"You can cancel that MHIM.\"                |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |----------Press [E]nter to load a missile---|        |\n");
printf("                      |                                                              |\n");
printf("                      |+____________________________[++]____________________________+|\n");
printf(" \n");
}

if(playerOneFire == 2)
{
printf("                       ______________________________________________________________\n");
printf("                      |+                                                            +|\n");
printf("                      | ░  ░░░░  ░░        ░░   ░░░  ░░   ░░░  ░░        ░░       ░░ |\n");
printf("                      | ▒  ▒  ▒  ▒▒▒▒▒  ▒▒▒▒▒    ▒▒  ▒▒    ▒▒  ▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒ |\n");
printf("                      | ▓        ▓▓▓▓▓  ▓▓▓▓▓  ▓  ▓  ▓▓  ▓  ▓  ▓▓      ▓▓▓▓       ▓▓ |\n");
printf("                      | ▒   ▒▒   ▒▒▒▒▒  ▒▒▒▒▒  ▒▒    ▒▒  ▒▒    ▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒  ▒▒ |\n");
printf("                      | ░  ░░░░  ░░        ░░  ░░░   ░░  ░░░   ░░        ░░  ░░░░  ░ |\n");
printf("                      |                                                              |\n");
printf("                      | ┏┓┳┓┏┓┏┓┏┓┳┓┏┓     ┳┓┏┓┏┳┓┏┳┓┓ ┏┓╻            My Wins: %s%d/%s%d |\n", spacesMyWins, myWins, spacesTotalGames, totalGames);
printf("                      | ┃┃┣┫┣ ┃┃┣┫┣┫┣  for ┣┫┣┫ ┃  ┃ ┃ ┣ ┃       Enemy's Wins: %s%d/%s%d |\n", spacesEnemyWins, enemyWins, spacesTotalGames, totalGames);
printf("                      | ┣┛┛┗┗┛┣┛┛┗┛┗┗┛     ┻┛┛┗ ┻  ┻ ┗┛┗┛•                           |\n");
printf("                      |        |--------------------------COMMANDER'S LOG---|        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | You just say exactly where to fire and     |        |\n");
printf("                      |        | your Gunner's Mate will launch a BGM-109   |        |\n");
printf("                      |        | Tomahawk Anti-Ship Missile straight into   |        |\n");
printf("                      |        | the fog never to be seen again...          |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | Hopefully, you hear it though.             |        |\n");
printf("                      |        | Completely obliterating the enemy!         |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |----Enter a coordinate to fire a Tomahawk---|        |\n");
printf("                      |                                                              |\n");
printf("                      |+____________________________[++]____________________________+|\n");
printf(" \n");
}

if(enemyFire == 2)
{
printf("                       ______________________________________________________________\n");
printf("                      |+                                                            +|\n");
printf("                      | ░░░░░░░  ░░░░░░░░      ░░░░      ░░░        ░░       ░░░░░░░ |\n");
printf("                      | ▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒▒ |\n");
printf("                      | ▓▓▓▓▓▓▓  ▓▓▓▓▓▓▓  ▓▓▓▓  ▓▓▓      ▓▓▓      ▓▓▓▓       ▓▓▓▓▓▓▓ |\n");
printf("                      | ▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒  ▒▒▒▒▒▒▒ |\n");
printf("                      | ░░░░░░░       ░░░      ░░░░      ░░░        ░░  ░░░░  ░░░░░░ |\n");
printf("                      |                                                              |\n");
printf("                      | ┏┓┳┓┏┓┏┓┏┓┳┓┏┓     ┳┓┏┓┏┳┓┏┳┓┓ ┏┓╻            My Wins: %s%d/%s%d |\n", spacesMyWins, myWins, spacesTotalGames, totalGames);
printf("                      | ┃┃┣┫┣ ┃┃┣┫┣┫┣  for ┣┫┣┫ ┃  ┃ ┃ ┣ ┃       Enemy's Wins: %s%d/%s%d |\n", spacesEnemyWins, enemyWins, spacesTotalGames, totalGames);
printf("                      | ┣┛┛┗┗┛┣┛┛┗┛┗┗┛     ┻┛┛┗ ┻  ┻ ┗┛┗┛•                           |\n");
printf("                      |        |--------------------------COMMANDER'S LOG---|        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | You just say exactly where to fire and     |        |\n");
printf("                      |        | your Gunner's Mate will launch a BGM-109   |        |\n");
printf("                      |        | Tomahawk Anti-Ship Missile straight into   |        |\n");
printf("                      |        | the fog never to be seen again...          |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        | Hopefully, you hear it though.             |        |\n");
printf("                      |        | Completely obliterating the enemy!         |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |                                            |        |\n");
printf("                      |        |----Enter a coordinate to fire a Tomahawk---|        |\n");
printf("                      |                                                              |\n");
printf("                      |+____________________________[++]____________________________+|\n");
printf(" \n");
}

		key = 0;
		fire = 0;
		miss = 0;
		enemyMissMe = 0;
		hit = 0;
		enemyHitMe = 0;
		myCARSunk = 0;
		myBATSunk = 0;
		myDESSunk = 0;
		mySUBSunk = 0;
		myPATSunk = 0;
		enemyCARSunk = 0;
		enemyBATSunk = 0;
		enemyDESSunk = 0;
		enemySUBSunk = 0;
		enemyPATSunk = 0;
		seagullMatch = 0;
		
}//Closes printStatus
		
		//printf("Radar Standby (STBY)...\n");
		//printf("No of Hits: %d  No of Damage: %d \n", numOfTotalHits, numOfTotalDamage);
		//printf("Entering EMCON Alpha...\n");
		//printf("Awaiting orders for next missile launch coordinate, sir...\n\n\n\n");
	
	void getSpaces()
	{
		if(numOfTotalDamage < 10)
		{
			spacesDamage = " ";
		}
		else if(numOfTotalDamage >= 10)
		{
			spacesDamage = "";
		}
		
		if(numOfTotalHits < 10)
		{
			spacesHits = " ";
		}
		else if(numOfTotalHits >= 10)
		{
			spacesHits = "";
		}
	}
	
	void getSpacesForWins()
	{
		if(myWins < 10)
		{
			spacesMyWins = " ";
		}
		else if(myWins >= 10)
		{
			spacesMyWins = "";
		}
		
		if(enemyWins < 10)
		{
			spacesEnemyWins = " ";
		}
		else if(enemyWins >= 10)
		{
			spacesEnemyWins = "";
		}
		
		if(totalGames < 10)
		{
			spacesTotalGames = " ";
		}
		else if(totalGames >= 10)
		{
			spacesTotalGames = "";
		}
	}
		//If enemys first shot hits me get a random direction from first guess
		//Also, if enemy second shot misses me get random direction from first guess
		int getRandomDirectionFromFirstGuess()
		{
			xRandomCheck = xFirstGuess;
			yRandomCheck = yFirstGuess;
			//printf("xFirstGuess %d yFirstGuess %d\n", xFirstGuess, yFirstGuess);
			
			if(zRandom == 0)
			{
				xRandomCheck = xFirstGuess - 1;
			}
			if(zRandom == 1)
			{
				xRandomCheck = xFirstGuess + 1;
			}
			if(zRandom == 2)
			{
				yRandomCheck = yFirstGuess - 1;
			}
			if(zRandom == 3)
			{
				yRandomCheck = yFirstGuess + 1;
			}
			//printf("Before getRandomDirectionFromFirstGuess check x %d y %d\n", xRandomCheck, yRandomCheck);
			if(xRandomCheck < 0 || xRandomCheck > 9 || yRandomCheck < 0 || yRandomCheck > 9 || strcmp(" X ", playerABoard[xRandomCheck][yRandomCheck]) == 0 || strcmp("HTC", playerABoard[xRandomCheck][yRandomCheck]) == 0 || strcmp("HTB", playerABoard[xRandomCheck][yRandomCheck]) == 0 || strcmp("HTD", playerABoard[xRandomCheck][yRandomCheck]) == 0 || strcmp("HTS", playerABoard[xRandomCheck][yRandomCheck]) == 0 || strcmp("HTP", playerABoard[xRandomCheck][yRandomCheck]) == 0 || strcmp("SAC", playerABoard[xRandomCheck][yRandomCheck]) == 0 || strcmp("SAB", playerABoard[xRandomCheck][yRandomCheck]) == 0 || strcmp("SAD", playerABoard[xRandomCheck][yRandomCheck]) == 0 || strcmp("SAS", playerABoard[xRandomCheck][yRandomCheck]) == 0 || strcmp("SAP", playerABoard[xRandomCheck][yRandomCheck]) == 0)
			{
				struct timespec ts;

				// 1. Get the current time using the monotonic clock
				if (clock_gettime(CLOCK_MONOTONIC, &ts) != 0) {
				perror("clock_gettime failed");
				return EXIT_FAILURE;
				}

				// 2. Seed the random number generator using nanoseconds
				srand((unsigned int)ts.tv_nsec);

				// 3. Generate a random number (e.g., between 1 and 100)
				zRandom = (rand() % 4) + 1;
				zRandom = zRandom - 1;

				//printf("Seed (Nanoseconds): %ld\n", ts.tv_nsec);
				//printf("Random Number: %d\n", zRandom);
				getRandomDirectionFromFirstGuess();
			}
			
			xRandom = xRandomCheck;
			yRandom = yRandomCheck;
			
			//printf("Before getRandomDirectionFromFirstGuess exit x %d y %d\n", xRandom, yRandom);
			//printf("Before getRandomDirectionFromFirstGuess exit z %d\n", zRandom);
		}
		
		//If enemy third shot hits water get opposite direction from first guess
		int getOppositeDirectionFromFirstGuess()
		{
			xRandomCheck = xFirstGuess;
			yRandomCheck = yFirstGuess;
			//printf("xFirstGuess %d yFirstGuess %d\n", xFirstGuess, yFirstGuess);
			//printf("z before getting opposite in getOppositeDirectionFromFirstGuess %d\n", zRandom);
			if(zRandom == 0)
			{
				zRandom = 1;
			}
			else if(zRandom == 1)
			{
				zRandom = 0;
			}
			else if(zRandom == 2)
			{
				zRandom = 3;
			}
			else if(zRandom == 3)
			{
				zRandom = 2;
			}
			
			if(zRandom == 0)
			{
				xRandomCheck = xFirstGuess - 1;
			}
			else if(zRandom == 1)
			{
				xRandomCheck = xFirstGuess + 1;
			}
			else if(zRandom == 2)
			{
				yRandomCheck = yFirstGuess - 1;
			}
			else if(zRandom == 3)
			{
				yRandomCheck = yFirstGuess + 1;
			}
			//printf("Before getOppositeDirectionFromFirstGuess check x %d y %d\n", xRandomCheck, yRandomCheck);
			if(xRandomCheck < 0 || xRandomCheck > 9 || yRandomCheck < 0 || yRandomCheck > 9 || strcmp(" X ", playerABoard[xRandomCheck][yRandomCheck]) == 0 || strcmp("HTC", playerABoard[xRandomCheck][yRandomCheck]) == 0 || strcmp("HTB", playerABoard[xRandomCheck][yRandomCheck]) == 0 || strcmp("HTD", playerABoard[xRandomCheck][yRandomCheck]) == 0 || strcmp("HTS", playerABoard[xRandomCheck][yRandomCheck]) == 0 || strcmp("HTP", playerABoard[xRandomCheck][yRandomCheck]) == 0 || strcmp("SAC", playerABoard[xRandomCheck][yRandomCheck]) == 0 || strcmp("SAB", playerABoard[xRandomCheck][yRandomCheck]) == 0 || strcmp("SAD", playerABoard[xRandomCheck][yRandomCheck]) == 0 || strcmp("SAS", playerABoard[xRandomCheck][yRandomCheck]) == 0 || strcmp("SAP", playerABoard[xRandomCheck][yRandomCheck]) == 0)
			{
				//Search board for any HT*
				//When found get random direction from there
				for(int i = 0; i < 10; i++)
						{
							for(int j = 0; j < 10; j++)
							{
								if(strcmp("HTC", playerABoard[i][j]) == 0 || strcmp("HTB", playerABoard[i][j]) == 0 || strcmp("HTD", playerABoard[i][j]) == 0 || strcmp("HTS", playerABoard[i][j]) == 0 || strcmp("HTP", playerABoard[i][j]) == 0)
								{
									//printf("i %d j %d\n", i, j);
									xRandom = i;
									yRandom = j;
									xFirstGuess = xRandom;
									yFirstGuess = yRandom;
									//printf("xFirstGuess %d yFirstGuess %d\n", xFirstGuess, yFirstGuess);
									getRandomDirectionFromFirstGuess();
									i = 10;
									j = 10;
								}
							}
						}
			}
			if(zRandom == 0 || zRandom == 1)
			{
				xRandom = xRandomCheck;
			}
			if(zRandom == 2 || zRandom == 3)
			{
				yRandom = yRandomCheck;
			}
			//printf("z inside getOppositeDirectionFromFirstGuess %d\n", zRandom);
		}
		
		//If enemy third shot hits me continue down direction
		int getSameDirection()
		{
			xRandomCheck = xRandom;
			yRandomCheck = yRandom;
			
			if(zRandom == 0)
			{
				xRandomCheck = xRandom - 1;
			}
			if(zRandom == 1)
			{
				xRandomCheck = xRandom + 1;
			}
			if(zRandom == 2)
			{
				yRandomCheck = yRandom - 1;
			}
			if(zRandom == 3)
			{
				yRandomCheck = yRandom + 1;
			}
			//printf("Before getSameDirection check x %d y %d\n", xRandomCheck, yRandomCheck);
			if(xRandomCheck < 0 || xRandomCheck > 9 || yRandomCheck < 0 || yRandomCheck > 9 || strcmp(" X ", playerABoard[xRandomCheck][yRandomCheck]) == 0 || strcmp("HTC", playerABoard[xRandomCheck][yRandomCheck]) == 0 || strcmp("HTB", playerABoard[xRandomCheck][yRandomCheck]) == 0 || strcmp("HTD", playerABoard[xRandomCheck][yRandomCheck]) == 0 || strcmp("HTS", playerABoard[xRandomCheck][yRandomCheck]) == 0 || strcmp("HTP", playerABoard[xRandomCheck][yRandomCheck]) == 0 || strcmp("SAC", playerABoard[xRandomCheck][yRandomCheck]) == 0 || strcmp("SAB", playerABoard[xRandomCheck][yRandomCheck]) == 0 || strcmp("SAD", playerABoard[xRandomCheck][yRandomCheck]) == 0 || strcmp("SAS", playerABoard[xRandomCheck][yRandomCheck]) == 0 || strcmp("SAP", playerABoard[xRandomCheck][yRandomCheck]) == 0)
			{
					//If enemy third shot hits invalid go in opposite direction from first guess
					getOppositeDirectionFromFirstGuess();
			}
			if(zRandom == 0 || zRandom == 1)
			{
				xRandom = xRandomCheck;
			}
			if(zRandom == 2 || zRandom == 3)
			{
				yRandom = yRandomCheck;
			}
			//printf("z inside getSameDirection %d\n", zRandom);
		}
		
	int convertXLetterToNumber(char xVal)
	{
		if(xVal == 'a')
		{
			xVal = 1;
			return xVal;
		}
		if(xVal == 'b')
		{
			xVal = 2;
			return xVal;
		}
		if(xVal == 'c')
		{
			xVal = 3;
			return xVal;
		}
		if(xVal == 'd')
		{
			xVal = 4;
			return xVal;
		}
		if(xVal == 'e')
		{
			xVal = 5;
			return xVal;
		}
		if(xVal == 'f')
		{
			xVal = 6;
			return xVal;
		}
		if(xVal == 'g')
		{
			xVal = 7;
			return xVal;
		}
		if(xVal == 'h')
		{
			xVal = 8;
			return xVal;
		}
		if(xVal == 'i')
		{
			xVal = 9;
			return xVal;
		}
		if(xVal == 'j')
		{
			xVal = 10;
			return xVal;
		}
	}
	
//***************************************************************printRadar*************************************************
	void printRadar()
	{
		printf("                      ----------==========++++[*ENEMY CONTACT*]++++==========----------\n\n");
		printf("                            |Carrier Class (CAR)          |Battleship Class (BAT)\n");
		printf("                            |Hull Strength: 5             |Hull Strength: 4\n");
		printf("                            |Status: %s|Status: %s\n\n", statusCAR, statusBAT);
		printf("                            |Destroyer Class (DES)        |Submarine Class (SUB)\n");
		printf("                            |Hull Strength: 3             |Hull Strength: 3\n");
		printf("                            |Status: %s|Status: %s\n\n", statusDES, statusSUB);
		printf("                            |Patrol Boat Class (PAT)      |Fleet Status:%s|\n", percentFLEETCharacter);
		printf("                            |Hull Strength: 2             |CAR[%d]:%s|\n", numOfCARHealth, hitMissShipCAR);
		printf("                            |Status: %s|BAT[%d]:%s|\n", statusPAT, numOfBATHealth, hitMissShipBAT);
		printf("                                                          |DES[%d]:%s|\n", numOfDESHealth, hitMissShipDES);
		printf("                                                          |SUB[%d]:%s|\n", numOfSUBHealth, hitMissShipSUB);
		printf("                                                          |PAT[%d]:%s|\n", numOfPATHealth, hitMissShipPAT);
		printf("\n");
		printf("                      --------------============++++[***]++++============--------------\n");
	}//Closes printRadar
	
	const char *printFLEETStatus(int healthPercentageCounter)
	{
		if(healthPercentageCounter == 0)
		{
			percentFLEETCharacter = " --------94%";
		}
		if(healthPercentageCounter == 1)
		{
			percentFLEETCharacter = " -------88% ";
		}
		if(healthPercentageCounter == 2)
		{
			percentFLEETCharacter = " -------82% ";
		}
		if(healthPercentageCounter == 3)
		{
			percentFLEETCharacter = " ------76%  ";
		}
		if(healthPercentageCounter == 4)
		{
			percentFLEETCharacter = " ------70%  ";
		}
		if(healthPercentageCounter == 5)
		{
			percentFLEETCharacter = " -----64%   ";
		}
		if(healthPercentageCounter == 6)
		{
			percentFLEETCharacter = " -----58%   ";
		}
		if(healthPercentageCounter == 7)
		{
			percentFLEETCharacter = " ----52%    ";
		}
		if(healthPercentageCounter == 8)
		{
			percentFLEETCharacter = " ----46%    ";
		}
		if(healthPercentageCounter == 9)
		{
			percentFLEETCharacter = " ---40%     ";
		}
		if(healthPercentageCounter == 10)
		{
			percentFLEETCharacter = " ---34%     ";
		}
		if(healthPercentageCounter == 11)
		{
			percentFLEETCharacter = " --28%      ";
		}
		if(healthPercentageCounter == 12)
		{
			percentFLEETCharacter = " --22%      ";
		}
		if(healthPercentageCounter == 13)
		{
			percentFLEETCharacter = " -16%       ";
		}
		if(healthPercentageCounter == 14)
		{
			percentFLEETCharacter = " -10%       ";
		}
		if(healthPercentageCounter == 15)
		{
			percentFLEETCharacter = " -4%        ";
		}
		if(healthPercentageCounter == 16)
		{
			percentFLEETCharacter = " 0%         ";
		}
		return percentFLEETCharacter;
	}	
	
	void hitShipCheck()
	{
			if(strcmp("CAR", playerABoard[xRandom][yRandom]) == 0)
				{
					enemyHitMe = 1;
					strcpy(playerABoard[xRandom][yRandom], "HTC");
					if(numOfCARDamage == 0)
					{
						hitMissShipCAR = "      <o o o o x] ";
					}
					else if(numOfCARDamage == 1)
					{
						hitMissShipCAR = "     <o o o x x]  ";
					}
					else if(numOfCARDamage == 2)
					{
						hitMissShipCAR = "    <o o x x x]   ";
					}
					else if(numOfCARDamage == 3) 
					{
						hitMissShipCAR = "   <o x x x x]    ";
					}
					else if(numOfCARDamage == 4)
					{
						hitMissShipCAR = " <x x x x x]*SUNK*";
						enemyHitMe = 0;
						myCARSunk = 1;
						myCARSunkKey = 1;
						hitCounter = 0;
						
						for(int i = 0; i < 10; i++)
						{
							for(int j = 0; j < 10; j++)
							{
								if(strcmp("HTC", playerABoard[i][j]) == 0)
								{
									strcpy(playerABoard[i][j], "SAC");
								}
							}
						}
						
						for(int i = 0; i < 10; i++)
						{
							for(int j = 0; j < 10; j++)
							{
								if(strcmp("HTC", playerABoard[i][j]) == 0 || strcmp("HTB", playerABoard[i][j]) == 0 || strcmp("HTD", playerABoard[i][j]) == 0 || strcmp("HTS", playerABoard[i][j]) == 0 || strcmp("HTP", playerABoard[i][j]) == 0)
								{
									xRandom = i;
									yRandom = j;
									hitCounter = 1;
									xFirstGuess = xRandom;
                          yFirstGuess = yRandom;
									i = 10;
									j = 10;
								}
							}
						}
					}
					
					numOfCARDamage++;
					numOfCARHealth--;
					enemyHitWhich = "Aircraft Carrier!        ";
				}
				else if(strcmp("BAT", playerABoard[xRandom][yRandom]) == 0)
				{
					enemyHitMe = 1;
					strcpy(playerABoard[xRandom][yRandom], "HTB");
					if(numOfBATDamage == 0)
					{
						hitMissShipBAT = "       <o o o x}  ";
					}
					else if(numOfBATDamage == 1)
					{
						hitMissShipBAT = "     <o o x x}    ";
					}
					else if(numOfBATDamage == 2)
					{
						hitMissShipBAT = "   <o x x x}      ";
					}
					else if(numOfBATDamage == 3)
					{
						hitMissShipBAT = " <x x x x}  *SUNK*";
						enemyHitMe = 0;
						myBATSunk = 1;
						myBATSunkKey = 1;
						hitCounter = 0;
						
						for(int i = 0; i < 10; i++)
						{
							for(int j = 0; j < 10; j++)
							{
								if(strcmp("HTB", playerABoard[i][j]) == 0)
								{
									strcpy(playerABoard[i][j], "SAB");
								}
							}
						}
						
						for(int i = 0; i < 10; i++)
						{
							for(int j = 0; j < 10; j++)
							{
								if(strcmp("HTC", playerABoard[i][j]) == 0 || strcmp("HTB", playerABoard[i][j]) == 0 || strcmp("HTD", playerABoard[i][j]) == 0 || strcmp("HTS", playerABoard[i][j]) == 0 || strcmp("HTP", playerABoard[i][j]) == 0)
								{
									xRandom = i;
									yRandom = j;
									hitCounter = 1;
									xFirstGuess = xRandom;
                          yFirstGuess = yRandom;
									i = 10;
									j = 10;
								}
							}
						}
					}
					
					numOfBATDamage++;
					numOfBATHealth--;
					enemyHitWhich = "Battleship!              ";
				}
				else if(strcmp("DES", playerABoard[xRandom][yRandom]) == 0)
				{	
					enemyHitMe = 1;
					strcpy(playerABoard[xRandom][yRandom], "HTD");
					if(numOfDESDamage == 0)
					{
						hitMissShipDES = "        <o o x>   ";
					}
					else if(numOfDESDamage == 1)
					{
						hitMissShipDES = "     <o x x>      ";
					}
					else if(numOfDESDamage == 2)
					{
						hitMissShipDES = " <x x x>    *SUNK*";
						enemyHitMe = 0;
						myDESSunk = 1;
						myDESSunkKey = 1;
						hitCounter = 0;
						
						for(int i = 0; i < 10; i++)
						{
							for(int j = 0; j < 10; j++)
							{
								if(strcmp("HTD", playerABoard[i][j]) == 0)
								{
									strcpy(playerABoard[i][j], "SAD");
								}
							}
						}
						
						for(int i = 0; i < 10; i++)
						{
							for(int j = 0; j < 10; j++)
							{
								if(strcmp("HTC", playerABoard[i][j]) == 0 || strcmp("HTB", playerABoard[i][j]) == 0 || strcmp("HTD", playerABoard[i][j]) == 0 || strcmp("HTS", playerABoard[i][j]) == 0 || strcmp("HTP", playerABoard[i][j]) == 0)
								{
									xRandom = i;
									yRandom = j;
									hitCounter = 1;
									xFirstGuess = xRandom;
                          yFirstGuess = yRandom;
									i = 10;
									j = 10;
								}
							}
						}
					}
					
					numOfDESDamage++;
					numOfDESHealth--;
					enemyHitWhich = "Destroyer!               ";
				}
				else if(strcmp("SUB", playerABoard[xRandom][yRandom]) == 0)
				{
					enemyHitMe = 1;
					strcpy(playerABoard[xRandom][yRandom], "HTS");
					if(numOfSUBDamage == 0)
					{
						hitMissShipSUB = "        (o o x)   ";
					}
					else if(numOfSUBDamage == 1)
					{
						hitMissShipSUB = "     (o x x)      ";
					}
					else if(numOfSUBDamage == 2)
					{
						hitMissShipSUB = " (x x x)    *SUNK*";
						enemyHitMe = 0;
						mySUBSunk = 1;
						mySUBSunkKey = 1;
						hitCounter = 0;
						
						for(int i = 0; i < 10; i++)
						{
							for(int j = 0; j < 10; j++)
							{
								if(strcmp("HTS", playerABoard[i][j]) == 0)
								{
									strcpy(playerABoard[i][j], "SAS");
								}
							}
						}
						
						for(int i = 0; i < 10; i++)
						{
							for(int j = 0; j < 10; j++)
							{
								if(strcmp("HTC", playerABoard[i][j]) == 0 || strcmp("HTB", playerABoard[i][j]) == 0 || strcmp("HTD", playerABoard[i][j]) == 0 || strcmp("HTS", playerABoard[i][j]) == 0 || strcmp("HTP", playerABoard[i][j]) == 0)
								{
									xRandom = i;
									yRandom = j;
									hitCounter = 1;
									xFirstGuess = xRandom;
                          yFirstGuess = yRandom;
									i = 10;
									j = 10;
								}
							}
						}
					}
					
					numOfSUBDamage++;
					numOfSUBHealth--;
					enemyHitWhich = "Submarine!               ";
				}
				else if(strcmp("PAT", playerABoard[xRandom][yRandom]) == 0)
				{
					enemyHitMe = 1;
					strcpy(playerABoard[xRandom][yRandom], "HTP");
					if(numOfPATDamage == 0)
					{
						hitMissShipPAT = "       [o x]      ";
					}
					else if(numOfPATDamage == 1)
					{
						hitMissShipPAT = " [x x]      *SUNK*";
						enemyHitMe = 0;
						myPATSunk = 1;
						myPATSunkKey = 1;
						hitCounter = 0;
						
						for(int i = 0; i < 10; i++)
						{
							for(int j = 0; j < 10; j++)
							{
								if(strcmp("HTP", playerABoard[i][j]) == 0)
								{
									strcpy(playerABoard[i][j], "SAP");
								}
							}
						}
						
						for(int i = 0; i < 10; i++)
						{
							for(int j = 0; j < 10; j++)
							{
								if(strcmp("HTC", playerABoard[i][j]) == 0 || strcmp("HTB", playerABoard[i][j]) == 0 || strcmp("HTD", playerABoard[i][j]) == 0 || strcmp("HTS", playerABoard[i][j]) == 0 || strcmp("HTP", playerABoard[i][j]) == 0)
								{
									xRandom = i;
									yRandom = j;
									hitCounter = 1;
									xFirstGuess = xRandom;
                          yFirstGuess = yRandom;
									i = 10;
									j = 10;
								}
							}
						}
						
					}
					
					numOfPATDamage++;
					numOfPATHealth--;
					enemyHitWhich = "Patrol Boat!             ";
				}//Closes PAT if statement
				
				numOfTotalDamage++;
				key = 1;
				percentFLEETCharacter = printFLEETStatus(healthPercentageCounter);
				healthPercentageCounter++;
	}//Closes hitShip()
	
	void hitWaterCheck()
	{
			strcpy(playerABoard[xRandom][yRandom], " X ");
			enemyHitWater = 1;
			enemyMissMe = 1;
			key = 1;
	}
	
	int createPassKeyLengthCheck(int xRandom, int yRandom, int shipLength)
		{
			passOrFailKey = 0;
			
			//Search up, down, left, and right looking for
			//all water in at least one direction
			//Four for loops. One for each direction
			
			//Check UP
			for(int i = 1; i < shipLength; i++)
			{
				if(strcmp(" ~ ", playerABoard[xRandom - i][yRandom]) != 0 && strcmp("CAR", playerABoard[xRandom - i][yRandom]) != 0 && strcmp("BAT", playerABoard[xRandom - i][yRandom]) != 0 && strcmp("DES", playerABoard[xRandom - i][yRandom]) != 0 && strcmp("SUB", playerABoard[xRandom - i][yRandom]) != 0 && strcmp("PAT", playerABoard[xRandom - i][yRandom]) != 0 || xRandom - i < 0)
				{
					printf("UP failed x %d y %d\n", xRandom, yRandom);
					passOrFailKey = 0;
					break;
				}
				else
				{
					printf("UP passed x %d y %d\n", xRandom, yRandom);
					passOrFailKey = 1;
				}
			}
			 
			//If UP failed then check DOWN
			if(passOrFailKey == 0)
			{
				for(int i = 1; i < shipLength; i++)
				{
					if(strcmp(" ~ ", playerABoard[xRandom + i][yRandom]) != 0 && strcmp("CAR", playerABoard[xRandom + i][yRandom]) != 0 && strcmp("BAT", playerABoard[xRandom + i][yRandom]) != 0 && strcmp("DES", playerABoard[xRandom + i][yRandom]) != 0 && strcmp("SUB", playerABoard[xRandom + i][yRandom]) != 0 && strcmp("PAT", playerABoard[xRandom + i][yRandom]) != 0 || xRandom + i > 9)
					{
						printf("DOWN failed x %d y %d\n", xRandom, yRandom);
						passOrFailKey = 0;
						break;
					}
					else
					{
						printf("DOWN passed x %d y %d\n", xRandom, yRandom);
						passOrFailKey = 1;
					}
				}
			}
			
			//If DOWN failed then check LEFT
			if(passOrFailKey == 0)
			{
				for(int i = 1; i < shipLength; i++)
				{
					if(strcmp(" ~ ", playerABoard[xRandom][yRandom - i]) != 0 && strcmp("CAR", playerABoard[xRandom][yRandom - i]) != 0 && strcmp("BAT", playerABoard[xRandom][yRandom - i]) != 0 && strcmp("DES", playerABoard[xRandom][yRandom - i]) != 0 && strcmp("SUB", playerABoard[xRandom][yRandom - i]) != 0 && strcmp("PAT", playerABoard[xRandom][yRandom - i]) != 0 || yRandom - i < 0)
					{
						printf("LEFT failed x %d y %d\n", xRandom, yRandom);
						passOrFailKey = 0;
						break;
					}
					else
					{
						printf("LEFT passed x %d y %d\n", xRandom, yRandom);
						passOrFailKey = 1;
					}
				}
			}
			
			//If LEFT failed then check RIGHT
			if(passOrFailKey == 0)
			{
				for(int i = 1; i < shipLength; i++)
				{
					if(strcmp(" ~ ", playerABoard[xRandom][yRandom + i]) != 0 && strcmp("CAR", playerABoard[xRandom][yRandom + i]) != 0 && strcmp("BAT", playerABoard[xRandom][yRandom + i]) != 0 && strcmp("DES", playerABoard[xRandom][yRandom + i]) != 0 && strcmp("SUB", playerABoard[xRandom][yRandom + i]) != 0 && strcmp("PAT", playerABoard[xRandom][yRandom + i]) != 0 || yRandom + i > 9)
					{
						printf("RIGHT failed x %d y %d\n", xRandom, yRandom);
						passOrFailKey = 0;
						break;
					}
					else
					{
						printf("RIGHT passed x %d y %d\n", xRandom, yRandom);
						passOrFailKey = 1;
					}
				}
			}//Ends the last if statement for each direction check
			//If all directions fail then passOrFailKey will return 0
			//If one of the directions passes then passOrFailKey will return 1
			return passOrFailKey;
		}//Closes createPassKeyLengthCheck function
	
//	**********************************enemyFires*******************************************************************************

	void enemyFires()
	{
		scanf(" %c", &proceed);
		if(proceed == 'x')
		{
			exit(0);
		}
		
		passOrFailKey = 0;
		
		//If you want a new random coordinate because it's first shot
		//or a ship was just sunk
		if(hitCounter == 0)
		{	
			while(passOrFailKey == 0)
			{	
				createRandomX();
				createRandomY();
				xFirstGuess = xRandom;
				yFirstGuess = yRandom;
				
				//Make sure it's not a spot we already picked
				while(strcmp(" X ", playerABoard[xRandom][yRandom]) == 0 || strcmp("SAC", playerABoard[xRandom][yRandom]) == 0 || strcmp("SAB", playerABoard[xRandom][yRandom]) == 0 || strcmp("SAD", playerABoard[xRandom][yRandom]) == 0 || strcmp("SAS", playerABoard[xRandom][yRandom]) == 0 || strcmp("SAP", playerABoard[xRandom][yRandom]) == 0)
				{
					printf("Already picked this spot x %d y %d\n", xRandom, yRandom);
					createRandomX();
					createRandomY();
					xFirstGuess = xRandom;
					yFirstGuess = yRandom;
				}
				
				//If we hit a ship then we are good and can exit loop
				if(strcmp("CAR", playerABoard[xRandom][yRandom]) == 0 || strcmp("BAT", playerABoard[xRandom][yRandom]) == 0 || strcmp("DES", playerABoard[xRandom][yRandom]) == 0 || strcmp("SUB", playerABoard[xRandom][yRandom]) == 0 || strcmp("PAT", playerABoard[xRandom][yRandom]) == 0)
				{
					printf("We hit a ship and can exit loop x %d y %d\n", xRandom, yRandom);
					passOrFailKey = 1;
				}
				//If we hit water do all of this
				else if(strcmp(" ~ ", playerABoard[xRandom][yRandom]) == 0)
				{
					if(myPATSunkKey == 0)
					{
						printf("PAT is still up x %d y %d\n", xRandom, yRandom);
						createPassKeyLengthCheck(xRandom, yRandom, 2);
					}
					else if(myPATSunkKey == 1)
					{
						printf("PAT is sunk x %d y %d\n", xRandom, yRandom);
						if(myDESSunkKey == 0 || mySUBSunkKey == 0)
						{
							printf("Either DES or SUB is still up x %d y %d\n", xRandom, yRandom);
							createPassKeyLengthCheck(xRandom, yRandom, 3);
						}
						else if(myDESSunkKey == 1 && mySUBSunkKey == 1)
						{
							printf("DES and SUB are sunk x %d y %d\n", xRandom, yRandom);
							if(myBATSunkKey == 0)
							{
								printf("BAT is still up x %d y %d\n", xRandom, yRandom);
								createPassKeyLengthCheck(xRandom, yRandom, 4);
							}
							else if(myBATSunkKey == 1)
							{
								printf("BAT is sunk x %d y %d\n", xRandom, yRandom);
								createPassKeyLengthCheck(xRandom, yRandom, 5);
							}//Closes if(myBATSunkKey = 1)
						}//Closes if(myDESSunkKey = 1 && ...
					}//Closes if(myPATSunkKey = 1)

					if(passOrFailKey == 0)
					{
						printf("Not a good spot x %d y %d\n", xRandom, yRandom);
					}
					if(passOrFailKey == 1)
					{
						printf("Good spot after direction check x %d y %d\n", xRandom, yRandom);
					}
				}//Closes else if(coordinate is water)
				if(passOrFailKey == 1)
				{
					printf("Good spot x %d y %d\n", xRandom, yRandom);
				}
			}//Closes while(passOrFailKey = 0)
			passOrFailKey = 0;
		}//Closes if(HitCounter = 0)
		
		//Use this to force the enemy to choose a specific guess only once
		if(once == 0)
		{
			xRandom = 0;
			yRandom = 8;
			xFirstGuess = xRandom;
			yFirstGuess = yRandom;
			once = 1;
		}
		//printf("xFirstGuess %d yFirstGuess %d\n", xFirstGuess, yFirstGuess);
		
		//If you have hit a ship and want to start checking directions
		//If you need a randomly created direction
		if(hitCounter == 1)
		{
			zRandom = createRandomZ();
			getRandomDirectionFromFirstGuess();
			//printf("x %d  y %d\n", xRandom, yRandom);
			//printf("z %d \n", zRandom);
		}
		//If you need to keep the same direction and continue down it
		if(hitCounter >= 2 && notSunkYet == 0)
		{
			//printf("I did not create another Z direction\n");
			getSameDirection();
			//printf("Inside notSunkYet == 0\n");
			//printf("x %d  y %d\n", xRandom, yRandom);
			//printf("z %d \n", zRandom);
		}
		if(hitCounter >= 2 && notSunkYet == 1)
		{
			notSunkYet = 0;
			getOppositeDirectionFromFirstGuess();
			//printf("x %d  y %d\n", xRandom, yRandom);
			//printf("z %d \n", zRandom);
		}
	
		if(strcmp("CAR", playerABoard[xRandom][yRandom]) == 0 || strcmp("BAT", playerABoard[xRandom][yRandom]) == 0 || strcmp("DES", playerABoard[xRandom][yRandom]) == 0 || strcmp("SUB", playerABoard[xRandom][yRandom]) == 0 || strcmp("PAT", playerABoard[xRandom][yRandom]) == 0)
		{
			hitCounter++;
			hitShipCheck();
		}
		
		if(strcmp(" ~ ", playerABoard[xRandom][yRandom]) == 0)
		{
			//printf("hitCounter %d\n", hitCounter);
			hitWaterCheck();
			if(hitCounter >= 2)
			{
				notSunkYet = 1;
			}
		}
		
		fireX = convertXNumberToLetter(xRandom);
		fireY = yRandom + 1;
		enemyFire = 1;
	}//Closes enemyFires
	
   //Initiate Board A, B, C and D
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			strcpy(playerABoard[i][j], " ~ ");
			strcpy(playerBBoard[i][j], " ~ ");
			strcpy(playerCBoard[i][j], " ~ ");
			strcpy(playerDBoard[i][j], " ~ ");
		}
	}
	
	//Call this whenever you want to print Board A
	void printBoardA()
	{
		printf("\n\n");
		printf("                                      1   2   3   4   5   6   7   8   9   10\n");
		printf("                                     --------------------------------------- \n");
		for(int i = 0; i < 10; i++)
		{
			printf("                                 ");
			printf("%c", rows[i]);
			printf("|  ");
			for(int j = 0; j < 10; j++)
			{
				printf("%s ", playerABoard[i][j]);
			}
			printf(" |");
			printf("%c", rows[i]);
			printf("\n");
		}
		printf("                                     --------------------------------------- \n");
	}
	
	//Call this whenever you want to print Board B
	void printBoardB()
	{
		printf("\n\n");
		printf("                                      1   2   3   4   5   6   7   8   9   10\n");
		printf("                                     --------------------------------------- \n");
		for(int i = 0; i < 10; i++)
		{
			printf("                                 ");
			printf("%c", rows[i]);
			printf("|  ");
			for(int j = 0; j < 10; j++)
			{
				printf("%s ", playerBBoard[i][j]);
			}
			printf(" |");
			printf("%c", rows[i]);
			printf("\n");
		}
		printf("                                     --------------------------------------- \n");
	}
	
	//Call this whenever you want to print Board C
	void printBoardC()
	{
		printf("\n\n");
		printf("                                      1   2   3   4   5   6   7   8   9   10\n");
		printf("                                     --------------------------------------- \n");
		for(int i = 0; i < 10; i++)
		{
			printf("                                 ");
			printf("%c", rows[i]);
			printf("|  ");
			for(int j = 0; j < 10; j++)
			{
				printf("%s ", playerCBoard[i][j]);
			}
			printf(" |");
			printf("%c", rows[i]);
			printf("\n");
		}
		printf("                                     --------------------------------------- \n");
	}
	
	//Call this whenever you want to print Board D
	void printBoardD()
	{
		printf("\n\n");
		printf("                                      1   2   3   4   5   6   7   8   9   10\n");
		printf("                                     --------------------------------------- \n");
		for(int i = 0; i < 10; i++)
		{
			printf("                                 ");
			printf("%c", rows[i]);
			printf("|  ");
			for(int j = 0; j < 10; j++)
			{
				printf("%s ", playerDBoard[i][j]);
			}
			printf(" |");
			printf("%c", rows[i]);
			printf("\n");
		}
		printf("                                     --------------------------------------- \n");
	}
	
	void printShipsA(int xCor, int yCor, const char direction, int length, const char *ship)
	{
		if(direction == 'u')
		{
			for(int i = 0; i < length; i++)
			{
			strcpy(playerABoard[xCor - 1][yCor - 1], ship);
			xCor = xCor - 1;
			}
		}
		if(direction == 'd')
		{
			for(int i = 0; i < length; i++)
			{
			strcpy(playerABoard[xCor - 1][yCor - 1], ship);
			xCor = xCor + 1;
			}
		}
		if(direction == 'l')
		{
			for(int i = 0; i < length; i++)
			{
			strcpy(playerABoard[xCor - 1][yCor - 1], ship);
			yCor = yCor - 1;
			}
		}
		if(direction == 'r')
		{
			for(int i = 0; i < length; i++)
			{
			strcpy(playerABoard[xCor - 1][yCor - 1], ship);
			yCor = yCor + 1;
			}
		}
	}
	
	void printShipsARandom(int xCor, int yCor, const char direction, int length, const char *ship)
	{
		if(direction == 'u')
		{
			for(int i = 0; i < length; i++)
			{
			strcpy(playerABoard[xCor][yCor], ship);
			xCor = xCor - 1;
			}
		}
		if(direction == 'd')
		{
			for(int i = 0; i < length; i++)
			{
			strcpy(playerABoard[xCor][yCor], ship);
			xCor = xCor + 1;
			}
		}
		if(direction == 'l')
		{
			for(int i = 0; i < length; i++)
			{
			strcpy(playerABoard[xCor][yCor], ship);
			yCor = yCor - 1;
			}
		}
		if(direction == 'r')
		{
			for(int i = 0; i < length; i++)
			{
			strcpy(playerABoard[xCor][yCor], ship);
			yCor = yCor + 1;
			}
		}
	}
	
	void printShipsB(int xCor, int yCor, const char direction, int length, const char *ship)
	{
		if(direction == 'u')
		{
			for(int i = 0; i < length; i++)
			{
			strcpy(playerBBoard[xCor][yCor], ship);
			xCor = xCor - 1;
			}
		}
		if(direction == 'd')
		{
			for(int i = 0; i < length; i++)
			{
			strcpy(playerBBoard[xCor][yCor], ship);
			xCor = xCor + 1;
			}
		}
		if(direction == 'l')
		{
			for(int i = 0; i < length; i++)
			{
			strcpy(playerBBoard[xCor][yCor], ship);
			yCor = yCor - 1;
			}
		}
		if(direction == 'r')
		{
			for(int i = 0; i < length; i++)
			{
			strcpy(playerBBoard[xCor][yCor], ship);
			yCor = yCor + 1;
			}
		}
	}
	
	int createPassKeyA(int xRandom, int yRandom, int shipLength)
	{
			passOrFailKey = 0;
			
				//Check to see if initial random coordinate is NOT water
			if(strcmp(" ~ ", playerABoard[xRandom][yRandom]) != 0)
			{
				passOrFailKey = 0;
			}
			else
			{
				passOrFailKey = 1;
				
			}
			
			//Search up, down, left, and right looking for water and ships
			//Four for loops. One for each direction
			if(passOrFailKey == 1)
			{
			for(int i = 1; i < shipLength; i++)
			{
			if(strcmp(" ~ ", playerABoard[xRandom - i][yRandom]) != 0)
			{
				passOrFailKey = 0;
				break;
			}
			else
			{
				passOrFailKey = 1;
			}
			}
			}
			
			if(passOrFailKey == 1)
			{
			for(int i = 1; i < shipLength; i++)
			{
			if(strcmp(" ~ ", playerABoard[xRandom + i][yRandom]) != 0)
			{
				passOrFailKey = 0;
				break;
			}
			else
			{
				passOrFailKey = 1;
			}
			}
			}
			
			if(passOrFailKey == 1)
			{
			for(int i = 1; i < shipLength; i++)
			{
			if(strcmp(" ~ ", playerABoard[xRandom][yRandom - i]) != 0)
			{
				passOrFailKey = 0;
				break;
			}
			else
			{
				passOrFailKey = 1;
			}
			}
			}
			
			if(passOrFailKey == 1)
			{
			for(int i = 1; i < shipLength; i++)
			{
			if(strcmp(" ~ ", playerABoard[xRandom][yRandom + i]) != 0)
			{
				passOrFailKey = 0;
				break;
			}
			else
			{
				passOrFailKey = 1;
			}
			}
			}//Ends the last if statement for each direction check
			
		}//Closes createPassKeyA function
	
	int createPassKeyB(int xRandom, int yRandom, int shipLength)
	{
			passOrFailKey = 0;
			
				//Check to see if initial random coordinate is NOT water
			if(strcmp(" ~ ", playerBBoard[xRandom][yRandom]) != 0)
			{
				passOrFailKey = 0;
			}
			else
			{
				passOrFailKey = 1;
				
			}
			
			//Search up, down, left, and right looking for water and ships
			//Four for loops. One for each direction
			if(passOrFailKey == 1)
			{
			for(int i = 1; i < shipLength; i++)
			{
			if(strcmp(" ~ ", playerBBoard[xRandom - i][yRandom]) != 0)
			{
				passOrFailKey = 0;
				break;
			}
			else
			{
				passOrFailKey = 1;
			}
			}
			}
			
			if(passOrFailKey == 1)
			{
			for(int i = 1; i < shipLength; i++)
			{
			if(strcmp(" ~ ", playerBBoard[xRandom + i][yRandom]) != 0)
			{
				passOrFailKey = 0;
				break;
			}
			else
			{
				passOrFailKey = 1;
			}
			}
			}
			
			if(passOrFailKey == 1)
			{
			for(int i = 1; i < shipLength; i++)
			{
			if(strcmp(" ~ ", playerBBoard[xRandom][yRandom - i]) != 0)
			{
				passOrFailKey = 0;
				break;
			}
			else
			{
				passOrFailKey = 1;
			}
			}
			}
			
			if(passOrFailKey == 1)
			{
			for(int i = 1; i < shipLength; i++)
			{
			if(strcmp(" ~ ", playerBBoard[xRandom][yRandom + i]) != 0)
			{
				passOrFailKey = 0;
				break;
			}
			else
			{
				passOrFailKey = 1;
			}
			}
			}//Ends the last if statement for each direction check
			return passOrFailKey;
		}//Closes createPassKeyB function
	
		//Deploy Carrier function
	void deployCAR()
	{
		int xRandom = 0;
		int yRandom = 0;
		int zRandom = 0;
		int shipLength = 5;
		const char *shipAbb = "CAR";
		
		if(true)
		{
			char x = 'x';
			int y = 0;
			char z = 'z';
			passOrFailKey = 0;
		
			while(passOrFailKey == 0)
			{
				xRandom = createRandomX();
				yRandom = createRandomY();
				zRandom = createRandomZ();
			
				passOrFailKey = createPassKeyA(xRandom, yRandom, shipLength);
		
				if(zRandom == 0)
				{
					int min = 0;
					int max = 3;
					if(xRandom >= min && xRandom <= max)
					{
						zRandom = 'd';
					}
					else
					{
						zRandom = 'u';
					}
				}
				if(zRandom == 1)
				{
					int min = 6;
					int max = 9;
					if(xRandom >= min && xRandom <= max)
					{
						zRandom = 'u';
					}
					else
					{
						zRandom = 'd';
					}
				}
				if(zRandom == 2)
				{
					int min = 0;
					int max = 3;
					if(yRandom >= min && yRandom <= max)
					{
						zRandom = 'r';
					}
					else
					{
						zRandom = 'l';
					}
				}
				if(zRandom == 3)
				{
					int min = 6;
					int max = 9;
					if(yRandom >= min && yRandom <= max)
					{
						zRandom = 'l';
					}
					else
					{
						zRandom = 'r';
					}
				}
			}//Closes while(passOrFailKey == 0)
			passOrFailKey = 0;
		
			if(shipPlacementChoice == 1)
			{
				if(oneOrTwoPlayerChoice == 1)
				{
					printBoardA();
					printf("                               -----------------------------------------------\n");
					printf("                               Player One\n");
				}
				else if(oneOrTwoPlayerChoice == 2)
				{
					printBoardB();
					printf("                               -----------------------------------------------\n");
					printf("                               Player Two\n");
				}
				printf("                               Deploy Carrier (CAR)\n");
			   printf("                               Hull Strength: 5\n");
				printf("                               Enter letter and number of coordinate for pivot\n");
				printf("                               -----------------------------------------------\n");
				scanf(" %c %d", &x, &y);
				fireX = convertXLowercaseToUppercase(x);
				printf("                               -------------------------------\n");
				printf("                               Enter pivot direction from: %c%d\n", fireX, y);
				printf("                               [u]p, [d]own, [l]eft, [r]ight\n");
				printf("                               -------------------------------\n");
				scanf(" %c", &z);
				printf("\n");
				int a = convertXLetterToNumber(x);
				if(oneOrTwoPlayerChoice == 1)
				{
					printShipsA(a, y, z, 5, shipAbb);
				}
				else if(oneOrTwoPlayerChoice == 2)
				{
					a = a - 1;
					y = y - 1;
					printShipsB(a, y, z, 5, shipAbb);
				}
			}
		
			if(shipPlacementChoice == 2)
			{
				//printShipsA will subtract 1 from x and y coordinate
				//So enter 0-9 and then add 1
				printShipsA(0 + 1, 1 + 1, 'd', 5, shipAbb);
			}

			if(shipPlacementChoice == 3)
			{
				printShipsARandom(xRandom, yRandom, zRandom, 5, shipAbb);
			}
		
			if(oneOrTwoPlayerChoice == 1)
			{
				if(twoPlayerKey == 0)
				{
					while(passOrFailKey == 0)
					{
						xRandom = createRandomX();
						yRandom = createRandomY();
						zRandom = createRandomZ();
			
						passOrFailKey = createPassKeyB(xRandom, yRandom, shipLength);
		
						if(zRandom == 0)
						{
							int min = 0;
							int max = 3;
							if(xRandom >= min && xRandom <= max)
							{
								zRandom = 'd';
							}
							else
							{
								zRandom = 'u';
							}
						}
						if(zRandom == 1)
						{
							int min = 6;
							int max = 9;
							if(xRandom >= min && xRandom <= max)
							{
								zRandom = 'u';
							}
							else
							{
								zRandom = 'd';
							}
						}
						if(zRandom == 2)
						{
							int min = 0;
							int max = 3;
							if(yRandom >= min && yRandom <= max)
								{
							zRandom = 'r';
							}
							else
							{
								zRandom = 'l';
							}
						}
						if(zRandom == 3)
						{
							int min = 6;
							int max = 9;
							if(yRandom >= min && yRandom <= max)
							{
								zRandom = 'l';
							}
							else
							{
								zRandom = 'r';
							}
						}
					}//Closes while(passOrFailKey == 0)
					printShipsB(xRandom, yRandom, zRandom, 5, shipAbb);
				}//Closes if(twoPlayerKey == 0)
			}//Closes if(oneOrTwoPlayerChoice == 1)
		}//Closes if true statement
	}//Closes deployCAR
		
		//Deploy Battleship function
		void deployBAT()
		{
		int xRandom = 0;
		int yRandom = 0;
		int zRandom = 0;
		int shipLength = 4;
		const char *shipAbb = "BAT";
		
		if(oneOrTwoPlayerChoice == 1)
		{
			printBoardA();
		}
		if(oneOrTwoPlayerChoice == 2)
		{
			printBoardB();
		}
		
		if(true)
		{
			char x = 'x';
			int y = 0;
			char z = 'z';
			passOrFailKey = 0;
			
			while(passOrFailKey == 0)
			{
			//Create random coordinate
			xRandom = createRandomX();
			yRandom = createRandomY();
			zRandom = createRandomZ();
			
			passOrFailKey = createPassKeyA(xRandom, yRandom, shipLength);
				
			//Make sure z direction wont hit a wall
			//If it will then go in opposite direction
			if(zRandom == 0)
			{
				int min = 0;
				int max = 2;
				if(xRandom >= min && xRandom <= max)
				{
					zRandom = 'd';
				}
				else
				{
					zRandom = 'u';
				}
			}
			if(zRandom == 1)
			{
				int min = 7;
				int max = 9;
				if(xRandom >= min && xRandom <= max)
				{
					zRandom = 'u';
				}
				else
				{
					zRandom = 'd';
				}
			}
			if(zRandom == 2)
			{
				int min = 0;
				int max = 2;
				if(yRandom >= min && yRandom <= max)
				{
					zRandom = 'r';
				}
				else
				{
					zRandom = 'l';
				}
			}
			if(zRandom == 3)
			{
				int min = 7;
				int max = 9;
				if(yRandom >= min && yRandom <= max)
				{
					zRandom = 'l';
				}
				else
				{
					zRandom = 'r';
				}
			}			
			}//Closes while statement
			passOrFailKey = 0;
		
		if(shipPlacementChoice == 1)
		{
		if(oneOrTwoPlayerChoice == 1)
		{
		printf("                               -----------------------------------------------\n");
		printf("                               Player One\n");
		}
		else if(oneOrTwoPlayerChoice == 2)
		{
		printf("                               -----------------------------------------------\n");
		printf("                               Player Two\n");
		}
		printf("                               Deploy Battleship (BAT)\n");
		printf("                               Hull Strength: 4\n");
		printf("                               Enter letter and number of coordinate for pivot\n");
		printf("                               -----------------------------------------------\n");
		scanf(" %c %d", &x, &y);
		fireX = convertXLowercaseToUppercase(x);
		printf("                               -------------------------------\n");
		printf("                               Enter pivot direction from: %c%d\n", fireX, y);
		printf("                               [u]p, [d]own, [l]eft, [r]ight\n");
		printf("                               -------------------------------\n");
		scanf(" %c", &z);
		printf("\n");
		int a = convertXLetterToNumber(x);
			if(oneOrTwoPlayerChoice == 1)
			{
				printShipsA(a, y, z, 4, shipAbb);
			}
			else if(oneOrTwoPlayerChoice == 2)
			{
				a = a - 1;
				y = y - 1;
				printShipsB(a, y, z, 4, shipAbb);
			}
		}
		if(shipPlacementChoice == 2)
		{
		//printShipsA will subtract 1 from x and y coordinate
		//So enter 0-9 and then add 1
		printShipsA(0 + 1, 8 + 1, 'd', 4, shipAbb);
		}
		if(shipPlacementChoice == 3)
		{
		printShipsARandom(xRandom, yRandom, zRandom, 4, shipAbb);
		}
		if(oneOrTwoPlayerChoice == 1)
		{
		if(twoPlayerKey == 0)
		{
		while(passOrFailKey == 0)
			{
			//Create random coordinate
			xRandom = createRandomX();
			yRandom = createRandomY();
			zRandom = createRandomZ();
			
			passOrFailKey = createPassKeyB(xRandom, yRandom, shipLength);
				
			//Make sure z direction wont hit a wall
			//If it will then go in opposite direction
			if(zRandom == 0)
			{
				int min = 0;
				int max = 2;
				if(xRandom >= min && xRandom <= max)
				{
					zRandom = 'd';
				}
				else
				{
					zRandom = 'u';
				}
			}
			if(zRandom == 1)
			{
				int min = 7;
				int max = 9;
				if(xRandom >= min && xRandom <= max)
				{
					zRandom = 'u';
				}
				else
				{
					zRandom = 'd';
				}
			}
			if(zRandom == 2)
			{
				int min = 0;
				int max = 2;
				if(yRandom >= min && yRandom <= max)
				{
					zRandom = 'r';
				}
				else
				{
					zRandom = 'l';
				}
			}
			if(zRandom == 3)
			{
				int min = 7;
				int max = 9;
				if(yRandom >= min && yRandom <= max)
				{
					zRandom = 'l';
				}
				else
				{
					zRandom = 'r';
				}
			}
		}//Closes while(passOrFailKey == 0)
		printShipsB(xRandom, yRandom, zRandom, 4, shipAbb);
		}
		}
		}//Closes if true statement
		}//Closes deployBAT
		
		//Deploy Destroyer function
		void deployDES()
		{
		int xRandom = 0;
		int yRandom = 0;
		int zRandom = 0;
		int shipLength = 3;
		const char *shipAbb = "DES";
		
		if(oneOrTwoPlayerChoice == 1)
		{
			printBoardA();
		}
		if(oneOrTwoPlayerChoice == 2)
		{
			printBoardB();
		}
		
		if(true)
		{
			char x = 'x';
			int y = 0;
			char z = 'z';
			passOrFailKey = 0;
			
			while(passOrFailKey == 0)
			{
			//Create random coordinate
			xRandom = createRandomX();
			yRandom = createRandomY();
			zRandom = createRandomZ();
			
			passOrFailKey = createPassKeyA(xRandom, yRandom, shipLength);
		
			if(zRandom == 0)
			{
				int min = 0;
				int max = 1;
				if(xRandom >= min && xRandom <= max)
				{
					zRandom = 'd';
				}
				else
				{
					zRandom = 'u';
				}
			}
			if(zRandom == 1)
			{
				int min = 8;
				int max = 9;
				if(xRandom >= min && xRandom <= max)
				{
					zRandom = 'u';
				}
				else
				{
					zRandom = 'd';
				}
			}
			if(zRandom == 2)
			{
				int min = 0;
				int max = 1;
				if(yRandom >= min && yRandom <= max)
				{
					zRandom = 'r';
				}
				else
				{
					zRandom = 'l';
				}
			}
			if(zRandom == 3)
			{
				int min = 8;
				int max = 9;
				if(yRandom >= min && yRandom <= max)
				{
					zRandom = 'l';
				}
				else
				{
					zRandom = 'r';
				}
			}
			//printf("Z %c \n", zRandom);
			}//Closes the while statement
			passOrFailKey = 0;
		
		if(shipPlacementChoice == 1)
		{
		if(oneOrTwoPlayerChoice == 1)
		{
		printf("                               -----------------------------------------------\n");
		printf("                               Player One\n");
		}
		else if(oneOrTwoPlayerChoice == 2)
		{
		printf("                               -----------------------------------------------\n");
		printf("                               Player Two\n");
		}
		printf("                               Deploy Destroyer (DES)\n");
		printf("                               Hull Strength: 3\n");
		printf("                               Enter letter and number of coordinate for pivot\n");
		printf("                               -----------------------------------------------\n");
		scanf(" %c %d", &x, &y);
		fireX = convertXLowercaseToUppercase(x);
		printf("                               -------------------------------\n");
		printf("                               Enter pivot direction from: %c%d\n", fireX, y);
		printf("                               [u]p, [d]own, [l]eft, [r]ight\n");
		printf("                               -------------------------------\n");
		scanf(" %c", &z);
		printf("\n");
		int a = convertXLetterToNumber(x);
			if(oneOrTwoPlayerChoice == 1)
			{
				printShipsA(a, y, z, 3, shipAbb);
			}
			else if(oneOrTwoPlayerChoice == 2)
			{
				a = a - 1;
				y = y - 1;
				printShipsB(a, y, z, 3, shipAbb);
			}
		}
		if(shipPlacementChoice == 2)
		{
		//printShipsA will subtract 1 from x and y coordinate
		//So enter 0-9 and then add 1
		printShipsA(9 + 1, 1 + 1, 'u', 3, shipAbb);
		}
		if(shipPlacementChoice == 3)
		{
		printShipsARandom(xRandom, yRandom, zRandom, 3, shipAbb);
		}
		if(oneOrTwoPlayerChoice == 1)
		{
		if(twoPlayerKey == 0)
		{
		while(passOrFailKey == 0)
			{
			//Create random coordinate
			xRandom = createRandomX();
			yRandom = createRandomY();
			zRandom = createRandomZ();
			
			passOrFailKey = createPassKeyB(xRandom, yRandom, shipLength);
		
			if(zRandom == 0)
			{
				int min = 0;
				int max = 1;
				if(xRandom >= min && xRandom <= max)
				{
					zRandom = 'd';
				}
				else
				{
					zRandom = 'u';
				}
			}
			if(zRandom == 1)
			{
				int min = 8;
				int max = 9;
				if(xRandom >= min && xRandom <= max)
				{
					zRandom = 'u';
				}
				else
				{
					zRandom = 'd';
				}
			}
			if(zRandom == 2)
			{
				int min = 0;
				int max = 1;
				if(yRandom >= min && yRandom <= max)
				{
					zRandom = 'r';
				}
				else
				{
					zRandom = 'l';
				}
			}
			if(zRandom == 3)
			{
				int min = 8;
				int max = 9;
				if(yRandom >= min && yRandom <= max)
				{
					zRandom = 'l';
				}
				else
				{
					zRandom = 'r';
				}
			}
			}//Closes the while statement
		printShipsB(xRandom, yRandom, zRandom, 3, shipAbb);
		}
		}
		}//Closes if true statement
		}//Closes deployDES
		
		//Deploy Submarine
		void deploySUB()
		{
		int xRandom = 0;
		int yRandom = 0;
		int zRandom = 0;
		int shipLength = 3;
		const char *shipAbb = "SUB";
		
		if(oneOrTwoPlayerChoice == 1)
		{
			printBoardA();
		}
		if(oneOrTwoPlayerChoice == 2)
		{
			printBoardB();
		}
		
		if(true)
		{
			char x = 'x';
			int y = 0;
			char z = 'z';
			passOrFailKey = 0;
			
			while(passOrFailKey == 0)
			{
			//Create random coordinate
			xRandom = createRandomX();
			yRandom = createRandomY();
			zRandom = createRandomZ();
			
			passOrFailKey = createPassKeyA(xRandom, yRandom, shipLength);
			
			if(zRandom == 0)
			{
				int min = 0;
				int max = 1;
				if(xRandom >= min && xRandom <= max)
				{
					zRandom = 'd';
				}
				else
				{
					zRandom = 'u';
				}
			}
			if(zRandom == 1)
			{
				int min = 8;
				int max = 9;
				if(xRandom >= min && xRandom <= max)
				{
					zRandom = 'u';
				}
				else
				{
					zRandom = 'd';
				}
			}
			if(zRandom == 2)
			{
				int min = 0;
				int max = 1;
				if(yRandom >= min && yRandom <= max)
				{
					zRandom = 'r';
				}
				else
				{
					zRandom = 'l';
				}
			}
			if(zRandom == 3)
			{
				int min = 8;
				int max = 9;
				if(yRandom >= min && yRandom <= max)
				{
					zRandom = 'l';
				}
				else
				{
					zRandom = 'r';
				}
			}
			}//Closes while statement
			passOrFailKey = 0;
		
			if(shipPlacementChoice == 1)
		{
		if(oneOrTwoPlayerChoice == 1)
		{
		printf("                               -----------------------------------------------\n");
		printf("                               Player One\n");
		}
		else if(oneOrTwoPlayerChoice == 2)
		{
		printf("                               -----------------------------------------------\n");
		printf("                               Player Two\n");
		}
				printf("                               Deploy Submarine (SUB)\n");
				printf("                               Hull Strength: 3\n");
				printf("                               Enter letter and number of coordinate for pivot\n");
				printf("                               -----------------------------------------------\n");
				scanf(" %c %d", &x, &y);
				fireX = convertXLowercaseToUppercase(x);
				printf("                               -------------------------------\n");
				printf("                               Enter pivot direction from: %c%d\n", fireX, y);
				printf("                               [u]p, [d]own, [l]eft, [r]ight\n");
				printf("                               -------------------------------\n");
				scanf(" %c", &z);
				printf("\n");
				int a = convertXLetterToNumber(x);
			if(oneOrTwoPlayerChoice == 1)
			{
				printShipsA(a, y, z, 3, shipAbb);
			}
			else if(oneOrTwoPlayerChoice == 2)
			{
				a = a - 1;
				y = y - 1;
				printShipsB(a, y, z, 3, shipAbb);
			}
		}
			
			if(shipPlacementChoice == 2)
			{
				//printShipsA will subtract 1 from x and y coordinate
				//So enter 0-9 and then add 1
				printShipsA(9 + 1, 8 + 1, 'u', 3, shipAbb);
			}

			if(shipPlacementChoice == 3)
			{
				printShipsARandom(xRandom, yRandom, zRandom, 3, shipAbb);
			}
			if(oneOrTwoPlayerChoice == 1)
		{
		if(twoPlayerKey == 0)
		{
		while(passOrFailKey == 0)
			{
			//Create random coordinate
			xRandom = createRandomX();
			yRandom = createRandomY();
			zRandom = createRandomZ();
			
			passOrFailKey = createPassKeyB(xRandom, yRandom, shipLength);
			
			if(zRandom == 0)
			{
				int min = 0;
				int max = 1;
				if(xRandom >= min && xRandom <= max)
				{
					zRandom = 'd';
				}
				else
				{
					zRandom = 'u';
				}
			}
			if(zRandom == 1)
			{
				int min = 8;
				int max = 9;
				if(xRandom >= min && xRandom <= max)
				{
					zRandom = 'u';
				}
				else
				{
					zRandom = 'd';
				}
			}
			if(zRandom == 2)
			{
				int min = 0;
				int max = 1;
				if(yRandom >= min && yRandom <= max)
				{
					zRandom = 'r';
				}
				else
				{
					zRandom = 'l';
				}
			}
			if(zRandom == 3)
			{
				int min = 8;
				int max = 9;
				if(yRandom >= min && yRandom <= max)
				{
					zRandom = 'l';
				}
				else
				{
					zRandom = 'r';
				}
			}
			}//Closes while statement
		printShipsB(xRandom, yRandom, zRandom, 3, shipAbb);
		}
		}
		}//Closes if true statement
		}//Closes deploySUB
		
	//Deploy Patrol Boat
	void deployPAT()
	{
		int xRandom = 0;
		int yRandom = 0;
		int zRandom = 0;
		int shipLength = 2;
		const char *shipAbb = "PAT";
		
		if(oneOrTwoPlayerChoice == 1)
		{
			printBoardA();
		}
		if(oneOrTwoPlayerChoice == 2)
		{
			printBoardB();
		}
		
		if(true)
		{
			char x = 'x';
			int y = 0;
			char z = 'z';
			passOrFailKey = 0;
			
			while(passOrFailKey == 0)
			{
			//Create random coordinate
			xRandom = createRandomX();
			yRandom = createRandomY();
			zRandom = createRandomZ();
			
			passOrFailKey = createPassKeyA(xRandom, yRandom, shipLength);
		
			if(zRandom == 0)
			{
				int min = 0;
				int max = 0;
				if(xRandom >= min && xRandom <= max)
				{
					zRandom = 'd';
				}
				else
				{
					zRandom = 'u';
				}
			}
			if(zRandom == 1)
			{
				int min = 9;
				int max = 9;
				if(xRandom >= min && xRandom <= max)
				{
					zRandom = 'u';
				}
				else
				{
					zRandom = 'd';
				}
			}
			if(zRandom == 2)
			{
				int min = 0;
				int max = 0;
				if(yRandom >= min && yRandom <= max)
				{
					zRandom = 'r';
				}
				else
				{
					zRandom = 'l';
				}
			}
			if(zRandom == 3)
			{
				int min = 9;
				int max = 9;
				if(yRandom >= min && yRandom <= max)
				{
					zRandom = 'l';
				}
				else
				{
					zRandom = 'r';
				}
			}
			}//Closes the while statement
			passOrFailKey = 0;
		
		if(shipPlacementChoice == 1)
		{
			if(oneOrTwoPlayerChoice == 1)
			{
				printf("                               -----------------------------------------------\n");
				printf("                               Player One\n");
			}
			else if(oneOrTwoPlayerChoice == 2)
			{
				printf("                               -----------------------------------------------\n");
				printf("                               Player Two\n");	
			}
			printf("                               Deploy Patrol Boat (PAT)\n");
			printf("                               Hull Strength: 2\n");
			printf("                               Enter letter and number of coordinate for pivot\n");
			printf("                               -----------------------------------------------\n");
			scanf(" %c %d", &x, &y);
			fireX = convertXLowercaseToUppercase(x);
			printf("                               -------------------------------\n");
			printf("                               Enter pivot direction from: %c%d\n", fireX, y);
			printf("                               [u]p, [d]own, [l]eft, [r]ight\n");
			printf("                               -------------------------------\n");
			scanf(" %c", &z);
			printf("\n");
			int a = convertXLetterToNumber(x);
			if(oneOrTwoPlayerChoice == 1)
			{
				printShipsA(a, y, z, 2, shipAbb);
			}
			else if(oneOrTwoPlayerChoice == 2)
			{
				a = a - 1;
				y = y - 1;
				printShipsB(a, y, z, 2, shipAbb);
			}
		}
		
		if(shipPlacementChoice == 2)
		{
			//printShipsA will subtract 1 from x and y coordinate
			//So enter 0-9 and then add 1
			printShipsA(5 + 1, 5 + 1, 'r', 2, shipAbb);
		}
		
		if(shipPlacementChoice == 3)
		{
			printShipsARandom(xRandom, yRandom, zRandom, 2, shipAbb);
		}
		
		if(oneOrTwoPlayerChoice == 1)
		{
			if(twoPlayerKey == 0)
			{
			while(passOrFailKey == 0)
			{
			//Create random coordinate
			xRandom = createRandomX();
			yRandom = createRandomY();
			zRandom = createRandomZ();
			
			passOrFailKey = createPassKeyB(xRandom, yRandom, shipLength);
		
			if(zRandom == 0)
			{
				int min = 0;
				int max = 0;
				if(xRandom >= min && xRandom <= max)
				{
					zRandom = 'd';
				}
				else
				{
					zRandom = 'u';
				}
			}
			if(zRandom == 1)
			{
				int min = 9;
				int max = 9;
				if(xRandom >= min && xRandom <= max)
				{
					zRandom = 'u';
				}
				else
				{
					zRandom = 'd';
				}
			}
			if(zRandom == 2)
			{
				int min = 0;
				int max = 0;
				if(yRandom >= min && yRandom <= max)
				{
					zRandom = 'r';
				}
				else
				{
					zRandom = 'l';
				}
			}
			if(zRandom == 3)
			{
				int min = 9;
				int max = 9;
				if(yRandom >= min && yRandom <= max)
				{
					zRandom = 'l';
				}
				else
				{
					zRandom = 'r';
				}
			}
			}//Closes the while statement
				printShipsB(xRandom, yRandom, zRandom, 2, shipAbb);
			}
		}
	}//Closes if true statement
			
	if(oneOrTwoPlayerChoice == 1)
		{
			printf("\e[1;1H\e[2J");
			printBoardA();
			printf("                               ----------------------------\n");
			printf("                               Player One\n");
			printf("                               You have deployed your ships\n");
			printf("                               Press [E]nter to continue\n");
			printf("                               ----------------------------\n");
		}
	if(oneOrTwoPlayerChoice == 2)
		{
			printf("\e[1;1H\e[2J");
			printBoardB();
			printf("                               ----------------------------\n");
			printf("                               Player Two\n");
			printf("                               You have deployed your ships\n");
			printf("                               Press [E]nter to continue\n");
			printf("                               ----------------------------\n");
		}
		if(twoPlayerKey == 1)
		{
			oneOrTwoPlayerChoice = 2;
		}
}//Closes deployPAT
	
	// **********************************fireMissile*******************************************************
	void fireMissile()
	{
		//Ask for coordinate guess
		scanf(" %c %d", &x, &y);
		
		//Convert letter coordinate to a number
		if(isalpha((unsigned char)x))
		{
			int index = tolower((unsigned char)x) - 'a';
			index = index + 1;
			a = index;
		}
		
		
		
		if(strcmp(" X ", playerCBoard[a-1][y-1]) == 0 || strcmp("HIT", playerCBoard[a-1][y-1]) == 0 || strcmp("CAR", playerCBoard[a-1][y-1]) == 0 || strcmp("BAT", playerCBoard[a-1][y-1]) == 0 || strcmp("DES", playerCBoard[a-1][y-1]) == 0 || strcmp("SUB", playerCBoard[a-1][y-1]) == 0 || strcmp("PAT", playerCBoard[a-1][y-1]) == 0)
		{
			chooseAgain = 1;
		}
		//If my guess is water run through the conditions for a miss
		//Otherwise run through the conditions for a hit
		else if(strcmp(" ~ ", playerBBoard[a-1][y-1]) == 0)
		{
			miss = 1;
			chooseAgain = 0;
			strcpy(playerCBoard[a-1][y-1], " X ");
			if(statusCAR != "**SUNK**             ")
			{
				statusCAR = "Unlocalized          ";
				radCAR = "<10km         ";
			}
			if(statusBAT != "**SUNK**     ")
			{
				statusBAT = "Unlocalized";
				radBAT = "<10km";
			}
			if(statusDES != "**SUNK**             ")
			{
				statusDES = "Unlocalized          ";
				radDES = "<10km         ";
			}
			if(statusSUB != "**SUNK**     ")
			{
				statusSUB = "Unlocalized";
				radSUB = "<10km";
			}
			if(statusPAT != "**SUNK**             ")
			{
				statusPAT = "Unlocalized          ";
				radPAT = "<10km         ";
			} 
		}
		//Run through the conditions if I get a hit
		else
		{
			hit = 1;
			numOfTotalHits++;
			chooseAgain = 0;
			strcpy(playerCBoard[a-1][y-1], "HIT");
			
			if(statusCAR != "**SUNK**             ")
			{
				radCAR = "Scanning      ";
				statusCAR = "Standby              ";
			}
			if(statusBAT != "**SUNK**     ")
			{
				radBAT = "Scanning";
				statusBAT = "Standby      ";
			}
			if(statusDES != "**SUNK**             ")
			{
				radDES = "Scanning      ";
				statusDES = "Standby              ";
			}
			if(statusSUB != "**SUNK**     ")
			{
				radSUB = "Scanning";
				statusSUB = "Standby      ";
			}
			if(statusPAT != "**SUNK**             ")
			{
				radPAT = "Scanning      ";
				statusPAT = "Standby              ";
			}
		
			//Check to see if enemy Carrier is hit or sunk
			if(strcmp("CAR", playerBBoard[a-1][y-1]) == 0)
			{
				numOfCARHits++;
				if(numOfCARHits == 5)
				{
					statusCAR = "**SUNK**             ";
					radCAR = "**NONE**      ";
					if(statusBAT != "**SUNK**     ")
					{
						statusBAT = "Unlocalized";
						radBAT = "<10km";
					}
					if(statusDES != "**SUNK**             ")
					{
						statusDES = "Unlocalized          ";
						radDES = "<10km         ";
					}
					if(statusSUB != "**SUNK**     ")
					{
						statusSUB = "Unlocalized";
						radSUB = "<10km";
					}
					if(statusPAT != "**SUNK**             ")
					{
						statusPAT = "Unlocalized          ";
						radPAT = "<10km         ";
					}
					enemyCARSunk = 1;
					hit = 0;
					
					for(int i = 0; i < 10; i++)
					{
						for(int j = 0; j < 10; j++)
						{
							if(strcmp("CAR", playerBBoard[i][j]) == 0)
							{
								strcpy(playerCBoard[i][j], "CAR");
							}
						}
					}
				}
			}
			
			//Check to see if enemy Battleship is hit or sunk
			if(strcmp("BAT", playerBBoard[a-1][y-1]) == 0)
			{
				numOfBATHits++;
				if(numOfBATHits == 4)
				{
					statusBAT = "**SUNK**     ";
					radBAT = "**NONE**";
					if(statusCAR != "**SUNK**             ")
					{
						statusCAR = "Unlocalized          ";
						radCAR = "<10km         ";
					}
					if(statusDES != "**SUNK**             ")
					{
						statusDES = "Unlocalized          ";
						radDES = "<10km         ";
					}
					if(statusSUB != "**SUNK**     ")
					{
						statusSUB = "Unlocalized";
						radSUB = "<10km";
					}
					if(statusPAT != "**SUNK**             ")
					{
						statusPAT = "Unlocalized          ";
						radPAT = "<10km         ";
					}
					enemyBATSunk = 1;
					hit = 0;
					
					for(int i = 0; i < 10; i++)
					{
						for(int j = 0; j < 10; j++)
						{
							if(strcmp("BAT", playerBBoard[i][j]) == 0)
							{
								strcpy(playerCBoard[i][j], "BAT");
							}
						}
					}
				}
			}
			
			//Check to see if enemy Destroyer is hit or sunk
			if(strcmp("DES", playerBBoard[a-1][y-1]) == 0)
			{
				numOfDESHits++;
				if(numOfDESHits == 3)
				{
					statusDES = "**SUNK**             ";
					radDES = "**NONE**      ";
					if(statusCAR != "**SUNK**             ")
					{
						statusCAR = "Unlocalized          ";
						radCAR = "<10km         ";
					}
					if(statusBAT != "**SUNK**     ")
					{
						statusBAT = "Unlocalized";
						radBAT = "<10km";
					}
					if(statusSUB != "**SUNK**     ")
					{
						statusSUB = "Unlocalized";
						radSUB = "<10km";
					}
					if(statusPAT != "**SUNK**             ")
					{
						statusPAT = "Unlocalized          ";
						radPAT = "<10km         ";
					}
					enemyDESSunk = 1;
					hit = 0;
					
					for(int i = 0; i < 10; i++)
					{
						for(int j = 0; j < 10; j++)
						{
							if(strcmp("DES", playerBBoard[i][j]) == 0)
							{
								strcpy(playerCBoard[i][j], "DES");
							}
						}
					}
				}
			}
			
			//Check to see if enemy Submarine is hit or sunk
			if(strcmp("SUB", playerBBoard[a-1][y-1]) == 0)
			{
				numOfSUBHits++;
				if(numOfSUBHits == 3)
				{
					statusSUB = "**SUNK**     ";
					radSUB = "**NONE**";
					if(statusCAR != "**SUNK**             ")
					{
						radCAR = "<10km         ";
						statusCAR = "Unlocalized          ";
					}
					if(statusBAT != "**SUNK**     ")
					{
						radBAT = "<10km";
						statusBAT = "Unlocalized";
					}
					if(statusDES != "**SUNK**             ")
					{
						radDES = "<10km         ";
						statusDES = "Unlocalized          ";
					}
					if(statusPAT != "**SUNK**             ")
					{
						radPAT = "<10km         ";
						statusPAT = "Unlocalized          ";
					}
					enemySUBSunk = 1;
					hit = 0;
					
					for(int i = 0; i < 10; i++)
					{
						for(int j = 0; j < 10; j++)
						{
							if(strcmp("SUB", playerBBoard[i][j]) == 0)
							{
								strcpy(playerCBoard[i][j], "SUB");
							}
						}
					}
				}
			}//Closes the statement to check if SUB has been hit or is sunk
			
			//Check to see if Enemy Patrol Boat is sunk
			//If your guess hits a PAT coordinate then
			//increase numOfPATHits by one
			if(strcmp("PAT", playerBBoard[a-1][y-1]) == 0)
			{
				numOfPATHits++;
				//Once you hit PAT 2 times change its status to SUNK
				//	and everything else goes Unlocalized if not SUNK already
				if(numOfPATHits == 2)
				{
					statusPAT = "**SUNK**             ";
					radPAT = "**NONE**      ";
					if(statusCAR != "**SUNK**             ")
					{
						statusCAR = "Unlocalized          ";
						radCAR = "<10km         ";
					}
					if(statusBAT != "**SUNK**     ")
					{
						statusBAT = "Unlocalized";
						radBAT = "<10km";
					}
					if(statusDES != "**SUNK**             ")
					{
						statusDES = "Unlocalized          ";
						radDES = "<10km         ";
					}
					if(statusSUB != "**SUNK**     ")
					{
						statusSUB = "Unlocalized";
						radSUB = "<10km";
					}
					enemyPATSunk = 1;
					hit = 0;
					
					for(int i = 0; i < 10; i++)
					{
						for(int j = 0; j < 10; j++)
						{
							if(strcmp("PAT", playerBBoard[i][j]) == 0)
							{
								strcpy(playerCBoard[i][j], "PAT");
							}
						}
					}//Closes the outer for loop
				}//Closes numOfPATHits == 2
			}//Closes check to see if PAT is hit or sunk
		}//Closes else statement for when I get a hit
		fireX = convertXNumberToLetter(a-1);
		fireY = y;
		playerOneFire = 1;
		
		if(a - 1 == seagullX && y - 1 == seagullY)
		{
			seagullGuess = 1;
			seagullMatch = 1;
		}
	}//Closes fireMissile function
	
void fireMissile2()
	{
		//Ask for coordinate guess
		scanf(" %c %d", &x, &y);
		
		//Convert letter coordinate to a number
		
		if(isalpha((unsigned char)x))
		{
			int index = tolower((unsigned char)x) - 'a';
			index = index + 1;
			a = index;
		}
		
		if(strcmp(" X ", playerDBoard[a-1][y-1]) == 0 || strcmp("HIT", playerDBoard[a-1][y-1]) == 0 || strcmp("CAR", playerDBoard[a-1][y-1]) == 0 || strcmp("BAT", playerDBoard[a-1][y-1]) == 0 || strcmp("DES", playerDBoard[a-1][y-1]) == 0 || strcmp("SUB", playerDBoard[a-1][y-1]) == 0 || strcmp("PAT", playerDBoard[a-1][y-1]) == 0)
		{
			chooseAgain = 1;
		}
		//If my guess is water run through the conditions for a miss
		//Otherwise run through the conditions for a hit
		else if(strcmp(" ~ ", playerABoard[a-1][y-1]) == 0)
		{
			strcpy(playerDBoard[a-1][y-1], " X ");
			miss = 1;
			key = 1;
			chooseAgain = 0;
		}
		//Run through the conditions if I get a hit
		else
		{
			hit = 1;
			numOfTotalDamage++;
			chooseAgain = 0;
			strcpy(playerDBoard[a-1][y-1], "HIT");
			
			//Check to see if enemy Carrier is hit or sunk
			if(strcmp("CAR", playerABoard[a-1][y-1]) == 0)
			{
				numOfCARHits2++;
				if(numOfCARHits2 == 5)
				{
					hitMissShipCAR = " <x x x x x]*SUNK*";
					hit = 0;
					numOfCARHealth = 0;
					enemyCARSunk = 1;
					
					if(healthPercentageCounter == 0)
					{
						healthPercentageCounter += 4;
					}
					else
					{
						healthPercentageCounter += 5;
					}
					
					percentFLEETCharacter = printFLEETStatus(healthPercentageCounter);
			
					for(int i = 0; i < 10; i++)
					{
						for(int j = 0; j < 10; j++)
						{
							if(strcmp("CAR", playerABoard[i][j]) == 0)
							{
								strcpy(playerDBoard[i][j], "CAR");
							}
						}
					}
				}
			}
					
			//Check to see if enemy Battleship is hit or sunk
			if(strcmp("BAT", playerABoard[a-1][y-1]) == 0)
			{
				numOfBATHits2++;
				if(numOfBATHits2 == 4)
				{
					hitMissShipBAT = " <x x x x}  *SUNK*";
					hit = 0;
					numOfBATHealth = 0;
					enemyBATSunk = 1;
					
					if(healthPercentageCounter == 0)
					{
						healthPercentageCounter += 3;
					}
					else
					{
						healthPercentageCounter += 4;
					}
					
					percentFLEETCharacter = printFLEETStatus(healthPercentageCounter);
					
					for(int i = 0; i < 10; i++)
					{
						for(int j = 0; j < 10; j++)
						{
							if(strcmp("BAT", playerABoard[i][j]) == 0)
							{
								strcpy(playerDBoard[i][j], "BAT");
							}
						}
					}
				}
			}
			
			//Check to see if enemy Destroyer is hit or sunk
			if(strcmp("DES", playerABoard[a-1][y-1]) == 0)
			{
				numOfDESHits2++;
				if(numOfDESHits2 == 3)
				{
					hitMissShipDES = " <x x x>    *SUNK*";
					hit = 0;
					numOfDESHealth = 0;
					enemyDESSunk = 1;
					
					if(healthPercentageCounter == 0)
					{
						healthPercentageCounter += 2;
					}
					else
					{
						healthPercentageCounter += 3;
					}
					
					percentFLEETCharacter = printFLEETStatus(healthPercentageCounter);
					
					for(int i = 0; i < 10; i++)
					{
						for(int j = 0; j < 10; j++)
						{
							if(strcmp("DES", playerABoard[i][j]) == 0)
							{
								strcpy(playerDBoard[i][j], "DES");
							}
						}
					}
				}
			}
			
			//Check to see if enemy Submarine is hit or sunk
			if(strcmp("SUB", playerABoard[a-1][y-1]) == 0)
			{
				numOfSUBHits2++;
				if(numOfSUBHits2 == 3)
				{
					hitMissShipSUB = " (x x x)    *SUNK*";
					hit = 0;
					numOfSUBHealth = 0;
					enemySUBSunk = 1;
					
					if(healthPercentageCounter == 0)
					{
						healthPercentageCounter += 2;
					}
					else
					{
						healthPercentageCounter += 3;
					}
					
					percentFLEETCharacter = printFLEETStatus(healthPercentageCounter);
					
					for(int i = 0; i < 10; i++)
					{
						for(int j = 0; j < 10; j++)
						{
							if(strcmp("SUB", playerABoard[i][j]) == 0)
							{
								strcpy(playerDBoard[i][j], "SUB");
							}
						}
					}
				}
			}//Closes the statement to check if SUB has been hit or is sunk
			
			//Check to see if Enemy Patrol Boat is sunk
			//If your guess hits a PAT coordinate then
			//increase numOfPATHits by one
			if(strcmp("PAT", playerABoard[a-1][y-1]) == 0)
			{
				numOfPATHits2++;
				//Once you hit PAT 2 times change its status to SUNK
				//	and everything else goes Unlocalized if not SUNK already
				if(numOfPATHits2 == 2)
				{
					hitMissShipPAT = " [x x]      *SUNK*";
					hit = 0;
					numOfPATHealth = 0;
					enemyPATSunk = 1;
					
					if(healthPercentageCounter == 0)
					{
						healthPercentageCounter += 1;
					}
					else
					{
						healthPercentageCounter += 2;
					}
					
					percentFLEETCharacter = printFLEETStatus(healthPercentageCounter);
					
					for(int i = 0; i < 10; i++)
					{
						for(int j = 0; j < 10; j++)
						{
							if(strcmp("PAT", playerABoard[i][j]) == 0)
							{
								strcpy(playerDBoard[i][j], "PAT");
							}
						}
					}//Closes the outer for loop
				}//Closes numOfPATHits == 2
			}//Closes check to see if PAT is hit or sunk
		}//Closes else statement for when I get a hit
		fireX = convertXNumberToLetter(a-1);
		fireY = y;
		playerTwoFire = 1;
	}//Closes fireMissile2 function
	
void printTitle()
{
printf("\n");
printf("                          ______________________________________________________________\n");
printf("                          ______________________________________________________________\n");
printf("                         |+                                                            +|\n");
printf("                         |     ░░        ░░░      ░░░░      ░░░░      ░░░  ░░░░  ░░     |\n");
printf("                         |    ▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒▒  ▒▒  ▒▒▒▒    |\n");
printf("                         |   ▓▓▓▓      ▓▓▓▓  ▓▓▓▓  ▓▓  ▓▓▓   ▓▓  ▓▓▓   ▓▓▓▓    ▓▓▓▓▓▓   |\n");
printf("                         |  █████  ████████  ████  ██  ████  ██  ████  █████  ████████  |\n");
printf("                         | ██████  █████████      ████      ████      ██████  █████████ |\n");
printf("                         |                                                              |\n");
printf("              :::    :::  ::::::::  :::::::::  ::::::::::: ::::::::: ::::::::  ::::    :::  ::::::::  \n");
printf("              :+:    :+: :+:    :+: :+:    :+:     :+:          :+: :+:    :+: :+:+:   :+: :+:    :+: \n");
printf("              +:+    +:+ +:+    +:+ +:+    +:+     +:+         +:+  +:+    +:+ :+:+:+  +:+ +:+        \n");
printf("              +#++:++#++ +#+    +:+ +#++:++#:      +#+        +#+   +#+    +:+ +#+ +:+ +#+ +#++:++#++ \n");
printf("              +#+    +#+ +#+    +#+ +#+    +#+     +#+       +#+    +#+    +#+ +#+  +#+#+#        +#+ \n");
printf("              #+#    #+# #+#    #+# #+#    #+#     #+#      #+#     #+#    #+# #+#   #+#+# #+#    #+# \n");
printf("              ###    ###  ########  ###    ### ########### ######### ########  ###    ####  ########  \n");
printf("                         |                                                              |\n");
printf("                         |                    ┓┏ ┏┓ ┳┳ ╻     ┓┏ ┳ ┳┳┓ ╻                 |\n");
printf("                         |               It's ┗┫ ┃┃ ┃┃ ┃ and ┣┫ ┃ ┃┃┃ ┃                 |\n");
printf("                         |                    ┗┛ ┗┛ ┗┛ •     ┛┗ ┻ ┛ ┗ •                 |\n");
printf("                         |                                                              |\n");
printf("                         |        |--------------------------COMMANDER'S LOG---|        |\n");
printf("                         |        |                                            |        |\n");
printf("                         |        |                    ----                    |        |\n");
printf("                         |        |                                            |        |\n");
printf("                         |        | Pacific Ocean. Early dawn. Weather fair.   |        |\n");
printf("                         |        | Sea calm. Cold fog. The sun is rising but  |        |\n");
printf("                         |        | offers no warmth. Today is going to be a   |        |\n");
printf("                         |        | cold day. Cold decisions will have to be   |        |\n");
printf("                         |        | made. Cold hearts will have to seek        |        |\n");
printf("                         |        | forgiveness. Cold fates will have to be    |        |\n");
printf("                         |        | met.                                       |        |\n");
printf("                         |        |                                            |        |\n");
printf("                         |        |                    ----                    |        |\n");
printf("                         |        |                                            |        |\n");
printf("                         |        | You command a fleet of five warships; he   |        |\n");
printf("                         |        | does the same. You put freedom second only |        |\n");
printf("                         |        | to God; he does the same. You stop at      |        |\n");
printf("                         |        | nothing for victory; he does the same. You |        |\n");
printf("                         |        | turn up MMMBop when it comes on the radio; |        |\n");
printf("                         |        | he does the same. You and him ain't so     |        |\n");
printf("                         |        | different now.                             |        |\n");
printf("                         |        |                                            |        |\n");
printf("                         |        |                    ----                    |        |\n");
printf("                         |        |                                            |        |\n");
printf("                         |        | The radio statically requests your         |        |\n");
printf("                         |        | presence on the bridge. Your crew are      |        |\n");
printf("                         |        | anxious but patiently await your orders.   |        |\n");
printf("                         |        | You scan the foggy horizons and hear them  |        |\n");
printf("                         |        | calling your name, inviting you to search  |        |\n");
printf("                         |        | them.                                      |        |\n");
printf("                         |        |                                            |        |\n");
printf("                         |        | But beware, the enemy prowls around like a |        |\n");
printf("                         |        | roaring lion.                              |        |\n");
printf("                         |        |                                            |        |\n");
printf("                         |        |                    ----                    |        |\n");
printf("                         |        |                                            |        |\n");
printf("                         |        | \"Gunner! Load a Tomahawk!\"                 |        |\n");
printf("                         |        |                                            |        |\n");
printf("                         |        |---------Press [E]nter to load a Tomahawk---|        |\n");
printf("                         |                                                              |\n");
printf("                         |+____________________________[++]____________________________+|\n");
printf("                          ______________________________________________________________\n");
}
	
//Beginning of function calls

//Only need to call these once per game to initialize two boards
//Board A is your board
//You will set this manually
//Board B is the enemies board
//A legal random board (i.e. no ships are going off the edge and no ships overlap) is generated

printf("\e[1;1H\e[2J");
printTitle();
//waits
scanf(" %c", &proceed);
if(proceed == 'x')
{
	exit(0);
}

printf("\e[1;1H\e[2J");
printf("\n");
printf("                          ______________________________________________________________\n");
printf("                          ______________________________________________________________\n");
printf("                         |+                                                            +|\n");
printf("                         |     ░░        ░░░      ░░░░      ░░░░      ░░░  ░░░░  ░░     |\n");
printf("                         |    ▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒▒  ▒▒  ▒▒▒▒    |\n");
printf("                         |   ▓▓▓▓      ▓▓▓▓  ▓▓▓▓  ▓▓  ▓▓▓   ▓▓  ▓▓▓   ▓▓▓▓    ▓▓▓▓▓▓   |\n");
printf("                         |  █████  ████████  ████  ██  ████  ██  ████  █████  ████████  |\n");
printf("                         | ██████  █████████      ████      ████      ██████  █████████ |\n");
printf("                         |                                                              |\n");
printf("              :::    :::  ::::::::  :::::::::  ::::::::::: ::::::::: ::::::::  ::::    :::  ::::::::  \n");
printf("              :+:    :+: :+:    :+: :+:    :+:     :+:          :+: :+:    :+: :+:+:   :+: :+:    :+: \n");
printf("              +:+    +:+ +:+    +:+ +:+    +:+     +:+         +:+  +:+    +:+ :+:+:+  +:+ +:+        \n");
printf("              +#++:++#++ +#+    +:+ +#++:++#:      +#+        +#+   +#+    +:+ +#+ +:+ +#+ +#++:++#++ \n");
printf("              +#+    +#+ +#+    +#+ +#+    +#+     +#+       +#+    +#+    +#+ +#+  +#+#+#        +#+ \n");
printf("              #+#    #+# #+#    #+# #+#    #+#     #+#      #+#     #+#    #+# #+#   #+#+# #+#    #+# \n");
printf("              ###    ###  ########  ###    ### ########### ######### ########  ###    ####  ########  \n");
printf("                         |                                                              |\n");
printf("                         |                    ┓┏ ┏┓ ┳┳ ╻     ┓┏ ┳ ┳┳┓ ╻                 |\n");
printf("                         |               It's ┗┫ ┃┃ ┃┃ ┃ and ┣┫ ┃ ┃┃┃ ┃                 |\n");
printf("                         |                    ┗┛ ┗┛ ┗┛ •     ┛┗ ┻ ┛ ┗ •                 |\n");
printf("                         |                                                              |\n");
printf("                         |        |-----------------ONE OR TWO PLAYER CHOICE---|        |\n");
printf("                         |        |                                            |        |\n");
printf("                         |        |                    ----                    |        |\n");
printf("                         |        |                                            |        |\n");
printf("                         |        | Press 1: One Player                        |        |\n");
printf("                         |        | Press 2: Two Player                        |        |\n");
printf("                         |        |                                            |        |\n");
printf("                         |        |--------------------------------------------|        |\n");
printf("                         |                                                              |\n");
printf("                         |+____________________________[++]____________________________+|\n");
printf("                          ______________________________________________________________\n");
scanf(" %d", &oneOrTwoPlayerChoice);

if(oneOrTwoPlayerChoice == 1)
{
printf("\e[1;1H\e[2J");
printf("\n");
printf("                          ______________________________________________________________\n");
printf("                          ______________________________________________________________\n");
printf("                         |+                                                            +|\n");
printf("                         |     ░░        ░░░      ░░░░      ░░░░      ░░░  ░░░░  ░░     |\n");
printf("                         |    ▒▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒  ▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒▒  ▒▒  ▒▒▒▒    |\n");
printf("                         |   ▓▓▓▓      ▓▓▓▓  ▓▓▓▓  ▓▓  ▓▓▓   ▓▓  ▓▓▓   ▓▓▓▓    ▓▓▓▓▓▓   |\n");
printf("                         |  █████  ████████  ████  ██  ████  ██  ████  █████  ████████  |\n");
printf("                         | ██████  █████████      ████      ████      ██████  █████████ |\n");
printf("                         |                                                              |\n");
printf("              :::    :::  ::::::::  :::::::::  ::::::::::: ::::::::: ::::::::  ::::    :::  ::::::::  \n");
printf("              :+:    :+: :+:    :+: :+:    :+:     :+:          :+: :+:    :+: :+:+:   :+: :+:    :+: \n");
printf("              +:+    +:+ +:+    +:+ +:+    +:+     +:+         +:+  +:+    +:+ :+:+:+  +:+ +:+        \n");
printf("              +#++:++#++ +#+    +:+ +#++:++#:      +#+        +#+   +#+    +:+ +#+ +:+ +#+ +#++:++#++ \n");
printf("              +#+    +#+ +#+    +#+ +#+    +#+     +#+       +#+    +#+    +#+ +#+  +#+#+#        +#+ \n");
printf("              #+#    #+# #+#    #+# #+#    #+#     #+#      #+#     #+#    #+# #+#   #+#+# #+#    #+# \n");
printf("              ###    ###  ########  ###    ### ########### ######### ########  ###    ####  ########  \n");
printf("                         |                                                              |\n");
printf("                         |                    ┓┏ ┏┓ ┳┳ ╻     ┓┏ ┳ ┳┳┓ ╻                 |\n");
printf("                         |               It's ┗┫ ┃┃ ┃┃ ┃ and ┣┫ ┃ ┃┃┃ ┃                 |\n");
printf("                         |                    ┗┛ ┗┛ ┗┛ •     ┛┗ ┻ ┛ ┗ •                 |\n");
printf("                         |                                                              |\n");
printf("                         |        |--------------------SHIP PLACEMENT CHOICE---|        |\n");
printf("                         |        |                                            |        |\n");
printf("                         |        |                    ----                    |        |\n");
printf("                         |        |                                            |        |\n");
printf("                         |        | Press 1: You choose where your ships go    |        |\n");
printf("                         |        | Press 2: I made a pre-set for your ships   |        |\n");
printf("                         |        | Press 3: The computer will choose random   |        |\n");
printf("                         |        |          coordinates for your ships        |        |\n");
printf("                         |        |                                            |        |\n");
printf("                         |        |--------------------------------------------|        |\n");
printf("                         |                                                              |\n");
printf("                         |+____________________________[++]____________________________+|\n");
printf("                          ______________________________________________________________\n");
scanf(" %d", &shipPlacementChoice);

printf("\e[1;1H\e[2J");
deployCAR();
printf("\e[1;1H\e[2J");
deployBAT();
printf("\e[1;1H\e[2J");
deployDES();
printf("\e[1;1H\e[2J");
deploySUB();
printf("\e[1;1H\e[2J");
deployPAT();
//waits
scanf(" %c", &proceed);
if(proceed == 'x')
{
	exit(0);
}
}

if(oneOrTwoPlayerChoice == 2)
{
oneOrTwoPlayerChoice = 1;
twoPlayerKey = 1;
shipPlacementChoice = 1;

printf("\e[1;1H\e[2J");
deployCAR();
printf("\e[1;1H\e[2J");
deployBAT();
printf("\e[1;1H\e[2J");
deployDES();
printf("\e[1;1H\e[2J");
deploySUB();
printf("\e[1;1H\e[2J");
deployPAT();
//waits
scanf(" %c", &proceed);
if(proceed == 'x')
{
	exit(0);
}

printf("\e[1;1H\e[2J");
deployCAR();
printf("\e[1;1H\e[2J");
deployBAT();
printf("\e[1;1H\e[2J");
deployDES();
printf("\e[1;1H\e[2J");
deploySUB();
printf("\e[1;1H\e[2J");
deployPAT();
//waits
scanf(" %c", &proceed);
if(proceed == 'x')
{
	exit(0);
}
}

//Keep running game until you have hit the enemy a total
//of 17 times. The number needed to defeat all enemy ships and win
while(numOfTotalHits < 17 && numOfTotalDamage < 17)
{
	printf("\e[1;1H\e[2J");
	printBoardC();
	//printBoardA();
	//printBoardB();	//Print this if you want to see where the computer put his ships
	printPlayerOneMessage();
	getSpaces();
	printStatus();
	fire2 = 0;
	printRadar();
	//waits
	fireMissile();
	
	while(chooseAgain == 1)
		{
			printf("\e[1;1H\e[2J");
			printBoardC();
			fireX = convertXLowercaseToUppercase(x);
			printf("                               --------------------\n");
			printf("                               Player One\n");
			printf("                               You already chose %c%d\n", fireX, y);
			printf("                               Choose again\n");
			printf("                               --------------------\n");
			getSpaces();
			fire2 = 1;
			printStatus();
			fire2 = 0;
			printRadar();
			//waits
			fireMissile();
		}
	
	printf("\e[1;1H\e[2J");
	printBoardC();
	printPlayerOneMessage();
	getSpaces();
	printStatus();
	printRadar();
	
	if(oneOrTwoPlayerChoice == 1)
	{
		//waits
		enemyFires();
		
		printf("\e[1;1H\e[2J");
		printBoardA();
		printPlayerTwoMessage();
		getSpaces();
		printStatus();
		fire2 = 1;
		printRadar();
		//waits
		scanf(" %c", &proceed);
		if(proceed == 'x')
		{
			exit(0);
		}
	}
	else if(oneOrTwoPlayerChoice == 2)
	{
		//waits
		scanf(" %c", &proceed);
		if(proceed == 'x')
		{
			exit(0);
		}
		
		printf("\e[1;1H\e[2J");
		printBoardD();
		printPlayerTwoMessage();
		getSpaces();
		fire2 = 1;
		printStatus();
		fire2 = 0;
		printRadar();
		//waits
		fireMissile2();
		
		while(chooseAgain == 1)
		{
			printf("\e[1;1H\e[2J");
			printBoardD();
			fireX = convertXLowercaseToUppercase(x);
			printf("                               --------------------\n");
			printf("                               Player Two\n");
			printf("                               You already chose %c%d\n", fireX, y);
			printf("                               Choose again\n");
			printf("                               --------------------\n");
			getSpaces();
			fire2 = 1;
			printStatus();
			fire2 = 0;
			printRadar();
			//waits
			fireMissile2();
		}
		
		printf("\e[1;1H\e[2J");
		printBoardD();
		printPlayerTwoMessage();
		getSpaces();
		printStatus();
		fire2 = 1;
		printRadar();
		//waits
		scanf(" %c", &proceed);
		if(proceed == 'x')
		{
			exit(0);
		}
	}
}	

if(numOfTotalHits == 17)
{
	fire = 0;
	fire2 = 0;
	
	if(oneOrTwoPlayerChoice == 1)
	{
		//FILE *file;
	
		//file = fopen("wins.txt", "r");
		//if(file == NULL)
		//{
			//printf("Error opening file\n");
			//return 1;
		//}
		//else
		//{
			//fscanf(file, "My Wins: %d\n", &myWins);
			//fscanf(file, "Enemy Wins: %d\n", &enemyWins);
			//fscanf(file, "Total Games: %d\n", &totalGames);
			//fclose(file);
		//}

		myWins++;
		totalGames++;
	
		//file = fopen("wins.txt", "w");
		//if(file == NULL)
		//{
			//printf("Error opening file\n");
			//return 1;
		//}
		//else
		//{
			//fprintf(file, "My Wins: %d\n", myWins);
		//	fprintf(file, "Enemy Wins: %d\n", enemyWins);
			//fprintf(file, "Total Games: %d\n", totalGames);
			//fclose(file);
		//}
		
		printf("\e[1;1H\e[2J");
		printBoardC();
		playerOneFire = 2;
		printPlayerOneMessage();
		playerOneFire = 2;
		getSpacesForWins();
		printStatus();
		printRadar();
		//waits
		scanf(" %c", &proceed);
		if(proceed == 'x')
		{
			exit(0);
		}
		
		printf("\e[1;1H\e[2J");
		printBoardA();
		printf("                                 ^^^ YOUR FLEET ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		printBoardB();
		printf("                                 ^^^ ENEMY'S FLEET ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		printBoardC();
		printf("                                 ^^^ YOUR MISSILE STRIKES ^^^^^^^^^^^^^^^^^^^^^^\n\n");
	}//Closes if(oneOrTwoPlayerChoice == 1)
	
	if(oneOrTwoPlayerChoice == 2)
	{
		printf("\e[1;1H\e[2J");
		printBoardC();
		playerOneFire = 3;
		printPlayerOneMessage();
		playerOneFire = 3;
		getSpacesForWins();
		printStatus();
		printRadar();
		//waits
		scanf(" %c", &proceed);
		if(proceed == 'x')
		{
			exit(0);
		}
		
		printf("\e[1;1H\e[2J");
		printBoardA();
		printf("                                 ^^^ PLAYER ONE'S FLEET ^^^^^^^^^^^^^^^^^^^^^^^^\n");
		printBoardD();
		printf("                                 ^^^ PLAYER TWO'S MISSILE STRIKES ^^^^^^^^^^^^^^\n");
		printBoardB();
		printf("                                 ^^^ PLAYER TWO'S FLEET ^^^^^^^^^^^^^^^^^^^^^^^^\n");
		printBoardC();
		printf("                                 ^^^ PLAYER ONE'S MISSILE STRIKES ^^^^^^^^^^^^^^\n\n");
	}//Closes if(oneOrTwoPlayerChoice == 2)
}//Closes if(numOfTotalHits == 17)

if(numOfTotalDamage == 17)
{
	fire = 0;
	fire2 = 0;
	
	if(oneOrTwoPlayerChoice == 1)
	{
	//	FILE *file;
	
		//file = fopen("wins.txt", "r");
		//if(file == NULL)
		//{
			//printf("Error opening file\n");
			//return 1;
		//}
		//else
		//{
			//fscanf(file, "My Wins: %d\n", &myWins);
			//fscanf(file, "Enemy Wins: %d\n", &enemyWins);
			//fscanf(file, "Total Games: %d\n", &totalGames);
			//fclose(file);
		//}

		enemyWins++;
		totalGames++;
	
		//file = fopen("wins.txt", "w");
		//if(file == NULL)
		//{
			//printf("Error opening file\n");
			//return 1;
		//}
		//else
		//{
			//fprintf(file, "My Wins: %d\n", myWins);
			//fprintf(file, "Enemy Wins: %d\n", enemyWins);
			//fprintf(file, "Total Games: %d\n", totalGames);
			//fclose(file);
		//}
		
		printf("\e[1;1H\e[2J");
		printBoardC();
		enemyFire = 2;
		printPlayerTwoMessage();
		enemyFire = 2;
		getSpacesForWins();
		printStatus();
		printRadar();
		//waits
		scanf(" %c", &proceed);
		if(proceed == 'x')
		{
			exit(0);
		}
		
		printf("\e[1;1H\e[2J");
		printBoardA();
		printf("                                 ^^^ YOUR FLEET ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		printBoardB();
		printf("                                 ^^^ ENEMY'S FLEET ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		printBoardC();
		printf("                                 ^^^ YOUR MISSILE STRIKES ^^^^^^^^^^^^^^^^^^^^^^\n\n");
	}//Closes if(oneOrTwoPlayerChoice == 1)
	
	if(oneOrTwoPlayerChoice == 2)
	{
		printf("\e[1;1H\e[2J");
		printBoardD();
		playerTwoFire = 3;
		printPlayerTwoMessage();
		playerTwoFire = 3;
		getSpacesForWins();
		printStatus();
		printRadar();
		//waits
		scanf(" %c", &proceed);
		if(proceed == 'x')
		{
			exit(0);
		}
		
		printf("\e[1;1H\e[2J");
		printBoardB();
		printf("                                 ^^^ PLAYER TWO'S FLEET ^^^^^^^^^^^^^^^^^^^^^^^^\n");
		printBoardC();
		printf("                                 ^^^ PLAYER ONE'S MISSILE STRIKES ^^^^^^^^^^^^^^\n");
		printBoardA();
		printf("                                 ^^^ PLAYER ONE'S FLEET ^^^^^^^^^^^^^^^^^^^^^^^^\n");
		printBoardD();
		printf("                                 ^^^ PLAYER TWO'S MISSILE STRIKES ^^^^^^^^^^^^^^\n\n");
	}//Closes if(oneOrTwoPlayerChoice == 2)
}//Closes if(numOfTotalDamage == 17)

return 0;
}