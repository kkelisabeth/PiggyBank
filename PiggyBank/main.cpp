/*
  Programer: Kozlova Elizabeth Paula
  Date Created: 08.12.2021 - 19.12.2021
  This program is used to keep track of the money that are saved in the piggybank.
  There are following options in the menu:
										  1) Deposit Option - deposit in the piggybank coins of 5 cent, 10 cent, 50 cent, and 1 Euro
										  2) Withdraw Option - withdraw the desired amount if it is valid
										  3) Show Option - display the amount that is currently in the piggybank
														 - display the exact number of coins
										  4) Empty Option - return all coins to the user
										  5) Quit Option - the program terminates
*/

#include <iostream>
#include <string>
using namespace std;

//function prototypes

void piggybank(int& choice, int& fiveCents, int& tenCents, int& fiftyCents, int& oneEuro, float& totalAmount, int& coinCounter);
void menu();
void mainBody(int& choice, int& fiveCents, int& tenCents, int& fiftyCents, int& oneEuro, float& totalAmount, int& coinCounter);
float deposit(int& fiveCents, int& tenCents, int& fiftyCents, int& oneEuro, int& coinCounter, float& totalAmount);
void show(float& totalAmount, int& fiveCents, int& tenCents, int& fiftyCents, int& oneEuro);
void empty(float& totalAmount, int& fiveCents, int& tenCents, int& fiftyCents, int& oneEuro);
float withdraw(float& totalAmount, int& fiveCents, int& tenCents, int& fiftyCents, int& oneEuro);

//main function

int main()
{
	int choice = 0;
	int fiveCents = 0;
	int tenCents = 0;
	int fiftyCents = 0;
	int oneEuro = 0;
	float totalAmount = 0;
	int coinCounter = 0;

	piggybank(choice, fiveCents, tenCents, fiftyCents, oneEuro, totalAmount, coinCounter);

	return 0;
}

//piggybank function 

void piggybank(int& choice, int& fiveCents, int& tenCents, int& fiftyCents, int& oneEuro, float& totalAmount, int& coinCounter)
{
	menu();
	mainBody(choice, fiveCents, tenCents, fiftyCents, oneEuro, totalAmount, coinCounter);
}

//menu function

void menu()
{
	cout << "Welcome to the PiggyBank!" << endl;
	cout << "     Menu     " << endl;
	cout << "==============" << endl;
	cout << "1. Deposit " << endl;
	cout << "2. Withdraw " << endl;
	cout << "3. Show total" << endl;
	cout << "4. Empty" << endl;
	cout << "5. Quit" << endl;

}

//main body finction with while loop and switch for choice of the user 

void mainBody(int& choice, int& fiveCents, int& tenCents, int& fiftyCents, int& oneEuro, float& totalAmount, int& coinCounter)
{
	cout << "Please enter choice: ";
	cin >> choice;

	while (choice != 5)
	{
		switch (choice)
		{
		case 1:
			totalAmount = deposit(fiveCents, tenCents, fiftyCents, oneEuro, coinCounter, totalAmount);
			cout << "PiggyBank has " << totalAmount << " Euros" << endl;
			break;
		case 2:
			totalAmount = withdraw(totalAmount, fiveCents, tenCents, fiftyCents, oneEuro);
			cout << "\nPiggyBank has " << totalAmount << " Euros" << endl;
			break;
		case 3:
			show(totalAmount, fiveCents, tenCents, fiftyCents, oneEuro);
			break;
		case 4:
			empty(totalAmount, fiveCents, tenCents, fiftyCents, oneEuro);
			break;
		default:
			cout << "Invalid Value." << endl;
			break;
		}

		cout << "Please, enter choice: ";
		cin >> choice;
	}

	cout << "Goodbye!" << endl;
}

//deposit function

float deposit(int& fiveCents, int& tenCents, int& fiftyCents, int& oneEuro, int& coinCounter, float& totalAmount)
{
	int num1, num2, num3, num4;

	//test for the maximum number of coins in the piggybank

	if (coinCounter > 200)
	{
		cout << "You have entered a maximum number of coins. " << endl;
		totalAmount = totalAmount;
	}
	else
	{
		cout << "Number of 5 cents: ";
		cin >> num1;
		coinCounter = coinCounter + num1;

		//test if the number of the coins is less than 200 after adding 5 cent coins 

		if (coinCounter < 200)
		{
			fiveCents += num1;
			cout << "Number of 10 cents: ";
			cin >> num2;
			coinCounter = coinCounter + num2;

			//test if the number of the coins is less than 200 after adding 10 cent coins 

			if (coinCounter < 200)
			{
				tenCents += num2;
				cout << "Number of 50 cents: ";
				cin >> num3;
				coinCounter = coinCounter + num3;

				//test if the number of the coins is less than 200 after adding 50 cent coins

				if (coinCounter < 200)
				{
					fiftyCents += num3;
					cout << "Number of 1 Euro: ";
					cin >> num4;
					coinCounter = coinCounter + num4;

					//test if the number of the coins is less than 200 after adding 1 euro coins

					if (coinCounter < 200)
					{
						oneEuro += num4;
						totalAmount = totalAmount + num1 * 0.05 + num2 * 0.1 + num3 * 0.5 + num4;
					}

					//test if the number of coins is equal to 200 after adding 1 euro coins 

					else if (coinCounter == 200)
					{
						totalAmount = totalAmount + num4;
						oneEuro = oneEuro + num4;
					}

					//test if the number of coins is more than 200 after adding 1 euro coins

					else
					{
						oneEuro = oneEuro + (num4 - (coinCounter - 200));
						cout << "You have entered a maximum number of coins. " << endl;
						totalAmount = totalAmount + num1 * 0.05 + num2 * 0.1 + num3 * 0.5 + (num4 - (coinCounter - 200));
					}

					//test if the number of coins is equal to 200 after adding 50 cent coins 

				}
				else if (coinCounter == 200)
				{
					totalAmount = totalAmount + num3 * 0.5;
					fiftyCents = fiftyCents + num3;
				}

				//test if the number of coins is more than 200 after adding 50 cent coins 

				else
				{
					fiftyCents = fiftyCents + (num3 - (coinCounter - 200));
					cout << "You have entered a maximum number of coins. " << endl;
					totalAmount = totalAmount + num1 * 0.05 + num2 * 0.1 + (num3 - (coinCounter - 200)) * 0.5;
				}

				//test if the number of coins is equal to 200 after adding 10 cent coins 

			}
			else if (coinCounter == 200)
			{
				totalAmount = totalAmount + num2 * 0.1;
				tenCents = tenCents + num2;
			}

			//test if the number of coins is more than 200 after adding 10 cent coins 

			else
			{
				tenCents = tenCents + (num2 - (coinCounter - 200));
				cout << "You have entered a maximum number of coins. " << endl;
				totalAmount = totalAmount + num1 * 0.05 + (num2 - (coinCounter - 200)) * 0.1;
			}

			//test if the number of coins is equal to 200 after adding 5 cent coins 

		}
		else if (coinCounter == 200)
		{
			totalAmount = totalAmount + num1 * 0.05;
			fiveCents = fiveCents + num1;
		}

		//test if the number of coins is more than 200 after adding 5 cent coins 

		else
		{
			fiveCents = fiveCents + (num1 - (coinCounter - 200));
			cout << "You have entered a maximum number of coins. " << endl;
			totalAmount = totalAmount + (num1 - (coinCounter - 200)) * 0.05;
		}
	}
	return totalAmount;
}

//show function

void show(float& totalAmount, int& fiveCents, int& tenCents, int& fiftyCents, int& oneEuro)
{
	cout << "Total amount of the money in the piggybank: " << totalAmount << endl;
	cout << "Total number of 5 cent coins: " << fiveCents << endl;
	cout << "Total number of 10 cent coins: " << tenCents << endl;
	cout << "Total number of 50 cent coins: " << fiftyCents << endl;
	cout << "Total number of 1 Euro coins: " << oneEuro << endl;
}

//empty function

void empty(float& totalAmount, int& fiveCents, int& tenCents, int& fiftyCents, int& oneEuro)
{
	//display all the coins that are in the piggybank 

	cout << "You will get: " << oneEuro << " 'One Euro' coins " << fiftyCents << " '50 Cent' coins " << tenCents << " '10 Cent' coins " << fiveCents << " '5 Cent' coins" << endl;

	//set to zero all the variables 

	totalAmount = 0;
	fiveCents = 0;
	tenCents = 0;
	fiftyCents = 0;
	oneEuro = 0;
}

//withdraw function

float withdraw(float& totalAmount, int& fiveCents, int& tenCents, int& fiftyCents, int& oneEuro)
{
	float enteredAmount;
	int enteredAmountCents, coins5cents, coins50and10cents, coins1euro, coin5counter, coin10counter, coin50counter, coin1counter;
	string fivecents, tencents, fiftycents, oneeuro, cent, euro;

	//create strings for displaying the result of the withdrawal option 

	cent = " Cent";
	euro = " Euro";
	fivecents = "5" + cent;
	tencents = "10" + cent;
	fiftycents = "50" + cent;
	oneeuro = "1" + euro;

	//validation for the case when total amount of money in the piggybank equals to zero 

	if (totalAmount == 0)
		cout << "There is nothing in your piggybank. Please deposit somthing first before withdrawing it." << endl;

	//main withdrawal function 

	else
	{
		cout << "How much would you like to withdraw: ";
		cin >> enteredAmount;

		//validation for the case when entered amount is more than the total amount in the piggybank 

		while (enteredAmount > totalAmount)
		{
			cout << "How much would you like to withdraw: ";
			cin >> enteredAmount;
		}

		//solution for the case when entered amount is equal to total amount

		if (enteredAmount == totalAmount)
		{
			cout << "You will get: ";
			cout << oneEuro << " " << oneeuro << " coins ";
			cout << fiftyCents << " " << fiftycents << " coins ";
			cout << tenCents << " " << tencents << " coins ";
			cout << fiveCents << " " << fivecents << " coins " << endl;
			totalAmount = 0;
			oneEuro = 0;
			fiftyCents = 0;
			tenCents = 0;
			fiveCents = 0;
		}

		//solution for the case when entered amount is less than total amount 

		else
		{
			//determine the number of coins of each denomination without validation 

			enteredAmountCents = enteredAmount * 100;
			coins5cents = enteredAmountCents % 10;
			if (coins5cents == 5)
				coin5counter = 1;
			else
				coin5counter = 0;
			enteredAmountCents = enteredAmountCents / 10;
			coins50and10cents = enteredAmountCents % 10;
			if (coins50and10cents >= 5)
			{
				coin50counter = coins50and10cents / 5;
				coin10counter = coins50and10cents % 5;
			}
			else
			{
				coin50counter = 0;
				coin10counter = coins50and10cents;
			}
			coin1counter = enteredAmountCents / 10;

			//displaying the result

			cout << "You will get: ";

			//1 euro coins

			//case 1 : if there are enough 1 euro coins in the piggybank

			if (coin1counter <= oneEuro)
			{
				cout << coin1counter << " " << oneeuro << " coins ";
				oneEuro = oneEuro - coin1counter;
			}

			//case 2 : if there are not enough 1 euro coins in the piggybank 

			else
			{
				coin1counter = coin1counter - oneEuro;

				//case 2.1 : if there are enough 50 cent coins to replace missing 1 euro coins 

				if (coin1counter * 2 <= fiftyCents)
				{
					cout << oneEuro << " " << oneeuro << " coins ";
					oneEuro = 0;
					coin50counter = coin50counter + (coin1counter * 2);
				}

				//case 2.2 : if there are not enough 50 cent coins to replace missing 1 euro coins 

				else
				{
					coin1counter = coin1counter * 100 - fiftyCents * 50;
					coin50counter = fiftyCents;

					//case 2.2.1 : if there are enough 10 cent coins to replace missing 1 euro coins 

					if (coin1counter / 10 <= tenCents)
					{
						cout << oneEuro << " " << oneeuro << " coins ";
						oneEuro = 0;
						coin10counter = coin10counter + (coin1counter / 10);
					}

					//case 2.2.2 : if there are not enough 10 cent coins to replace missing 1 euro coins 

					else
					{
						coin1counter = coin1counter - tenCents * 10;
						coin10counter = tenCents;

						//case 2.2.2.1 : if there are enough 5 cent coins to replace missing 1 euro coins 

						if (coin1counter / 5 <= fiveCents)
						{
							cout << oneEuro << " " << oneeuro << " coins ";
							oneEuro = 0;
							coin5counter = coin5counter + (coin1counter / 5);
						}

						//case 2.2.2.2 : if there are not enough 5 cent coins to replace missing 1 euro coins 

						else
						{
							coin5counter = fiveCents;
							cout << oneEuro << " " << oneeuro << " coins ";
							oneEuro = 0;
							cout << "There is not enough coins of this denomination.";
						}
					}
				}
			}

			//50 cent coins

			//case 1 : if there are enough 50 cent coins 

			if (coin50counter <= fiftyCents)
			{
				cout << coin50counter << " " << fiftycents << " coins ";
				fiftyCents = fiftyCents - coin50counter;
			}

			//case 2 : if there are not enough 50 cent coins 

			else
			{
				coin50counter = coin50counter - fiftyCents;

				//case 2.1 : if there are enough 10 cent coins to replace missing 50 cent coins 

				if (coin50counter * 5 <= tenCents)
				{
					cout << fiftyCents << " " << fiftycents << " coins ";
					fiftyCents = 0;
					coin10counter = coin10counter + (coin50counter * 5);
				}

				//case 2.2 : if there are not enough 10 cent coins to replace missing 50 cent coins 

				else
				{
					coin50counter = (coin50counter * 5 - tenCents) * 100;
					coin10counter = tenCents;

					//case 2.2.1 : if there are enough 5 cent coins to replace missing 50 cent coins 

					if (coin50counter / 5 <= fiveCents)
					{
						cout << fiftyCents << " " << fiftycents << " coins ";
						fiftyCents = 0;
						coin5counter = coin5counter + (coin50counter / 5);
					}

					//case 2.2.2 : if there are not enough 5 cent coins to replace missing 50 cent coins 

					else
					{
						coin5counter = fiveCents;
						cout << fiftyCents << " " << fiftycents << " coins ";
						fiftyCents = 0;
						cout << "There is not enought coins of this denomination. ";
					}
				}
			}
			//10 Cent Coins

			//case 1 : if there are anough 10 cent coins 

			if (coin10counter <= tenCents)
			{
				cout << coin10counter << " " << tencents << " coins ";
				tenCents = tenCents - coin10counter;
			}

			//case 2 : if there are not enough 10 cent coins 

			else
			{
				coin10counter = coin10counter - tenCents;

				//case 2.1 : if there are enough 5 cent coins to replace missing 10 cent coins 

				if (coin10counter * 2 <= fiveCents)
				{
					cout << tenCents << " " << tencents << " coins ";
					tenCents = 0;
					coin5counter = coin5counter + (coin10counter * 2);
				}

				//case 2.2 : if there are not enough 5 cent coins to replace missing 10 cent coins 

				else
				{
					coin5counter = fiveCents;
					cout << tenCents << " " << tencents << " coins ";
					tenCents = 0;
					cout << "There is not enough coins of this denomination. ";
				}
			}
			//5 Cent Coins

			//case 1 : if there are enough 5 cent coins 

			if (coin5counter <= fiveCents)
			{
				cout << coin5counter << " " << fivecents << " coins ";
				fiveCents = fiveCents - coin5counter;
			}

			//case 2 : if there are not enough 5 cent coins 

			else
				cout << "There is not enough coins of this denomination.";

			//total amount after the withdrawal operation

			totalAmount = totalAmount - enteredAmount;
		}
	}
	return totalAmount;
}