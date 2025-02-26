# include <iostream>
# include <cstdio>
# include <chrono>
# include <thread>
# include <string>
# include <vector>
# include <map>
# include <algorithm>
# include <fstream>
# include "../include/Chip.hpp"

using namespace std;


/***************************************************************************************************************/

Chip::Chip () 
{
	Num = 0;
	Network = "";
	FName = "";
	Balance = 0;
	Bonus = 0;
	NumberEnv = 0;
	NumberRec = 0;
	Cpt = 0;
}

/***************************************************************************************************************/

Chip::Chip (int n, std::string r, std::string np, int s, int b, int c)
{
    Num = n;
	Network = r;
	FName = np;
	Balance = s;
	Bonus = b;
	NumberEnv = 0;
	NumberRec = 0;
	Cpt = c;
}

/***************************************************************************************************************/
 
Chip::~Chip () 
{
    
}

/***************************************************************************************************************/
 
void Chip::Input1 () 
{
	int number;
	txt : 
		std::cout << "\n\n\t\t Number : +227";
		while (true)
			{
				if (std::cin >> number && number > 0)
				{
					break;
				}
				else
				{
					// La donnée saisie n'était pas un entier ou était négative
					std::cout << "\n\n\t\t Invalid number. Please try again" << std::endl;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "\n\n\t\t Number : +227";
				}
			}
	int number1 = number;
	number = Search_Number(number);
	if (number == 0)
	{
		std::cout << "\n\n\t\t\033[1m\033[31m The number +227" << number1 << " already exists\033[0m\033[0m " << std::endl;
		goto txt;
	}
	number = Orange_control (number);
	Num = number;
	Network = "Zamani_Telecom";
	cin.ignore();
	FName  = controlName();
	std::cout << "\n\n\t\t Balance : ";
	while (true)
		{
			if (std::cin >> Balance && Balance > 0)
			{
				break;
			}
			else
			{
				// La donnée saisie n'était pas un entier ou était négative
				std::cout << "\n\n\t\t Invalid number. Please try again" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\n\n\t\t Balance :";
			}
		}

	Chip chip1(Num, Network, FName, Balance, 0);

    chip.push_back(chip1);

	Update_file();

}

/***************************************************************************************************************/

void Chip::Display () const
{
	for (auto it = chip.begin(); it < chip.end(); ++it)
	{
		std::cout << "\n\t\t**************************************" << std::endl;
		std::cout << "\n\t\t Number : +227" << it->Num << std::endl;
		std::cout << "\t\t Network : " << it->Network << std::endl;
		std::cout << "\t\t FName : " << it->FName << std::endl;
		std::cout << "\t\t Balance : " << it->Balance << " SAHEL" << std::endl;
		std::cout << "\t\t Bonus : " << it->Bonus << " SAHEL" << std::endl;
		SendEnv1(it->Num); 
		SendRec1(it->Num);
		std::cout << "\n\t\t**************************************" << std::endl;
	}
	Update_file();
}

/***************************************************************************************************************/

void Chip::Modify ()
{
	int number {}, n {};

	std::cout << "\n\n\t\t Please enter the chip number to modify : +227";
	while (true)
	{
		if (std::cin >> number && number > 0)
		{
			break;
		}
		else
		{
			// La donnée saisie n'était pas un entier ou était négative
			std::cout << "\n\n\t\t Invalid number. Please try again" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\n\n\t\t Number : +227";
		}
	}

	// Trie le vector par numero ;
            		
    std::sort(chip.begin(), chip.end(), [] (const Chip& a, const Chip& b){
        return a.Num < b.Num;
            });
         
    // Supression des doublons
            		
    chip.erase(std::unique(chip.begin(), chip.end(), [](const Chip& a, const Chip& b){
        return a.Num == b.Num;
            }), chip.end());
			
	std::cout << "\n\n\t\t\033[1m\033[34m Chip before modification \033[0m\033[0m" << std::endl;
	n = Display_account (number);

	if (n == 0)
	{
		std::cout << "\n\n\t\t++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
        std::cout << "\t\t| Did you really modify this chip ?? \t       |" << std::endl;
        std::cout << "\t\t++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
        std::cout << "\t\t|\t 1 : Yes \t||\t 0 : No\t       |" << std::endl;
        std::cout << "\t\t++++++++++++++++++++++++++++++++++++++++++++++++\n\n\t\t";
        std::cin >> n;

        if (n == 1)
        {
        	system ("cls");

			for (auto it = chip.begin(); it < chip.end(); ++it)
			{
				if (it->Num == number)
				{
					std::cout << "\n\n\t\t FName : ";
					cin.ignore();
					getline(cin, it->FName);
					std::cout << "\n\n\t\t Balance : "; 
					std::cin >> it->Balance;
					std::cout << "\n\n\t\t\t\033[1m\033[7m\033[34m Chip Modified \033[0m\033[0m\033[0m" << std::endl;
					Update_file ();
					break;
				}
			}
		}

	n = 0;

	}

	system("cls");
	if (n == 0)
	{
		std::cout << "\n\n\t\t\033[1m\033[34m Chip after modification \033[0m\033[0m" << std::endl;
		Display_account (number);
	}
}

/***************************************************************************************************************/

void Chip::Delete ()
{
	int number {}, n1 {};

	std::cout << "\n\n\t\t Please enter the chip number to delete : +227";
	while (true)
	{
		if (std::cin >> number && number > 0)
		{
			break;
		}
		else
		{
			// La donnée saisie n'était pas un entier ou était négative
			std::cout << "\n\n\t\t Invalid number. Please try again" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\n\n\t\t Number : +227";
		}
	}

	// Trie le vector par numero ;
            		
    std::sort(chip.begin(), chip.end(), [] (const Chip& a, const Chip& b){
        return a.Num < b.Num;
            });
         
    // Supression des doublons
            		
    chip.erase(std::unique(chip.begin(), chip.end(), [](const Chip& a, const Chip& b){
        return a.Num == b.Num;
            }), chip.end());

	n1 = Display_account (number);

	if (n1 == 0)
	{
		std::cout << "\n\n\t\t++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
        std::cout << "\t\t| Did you really delete this chip ?? \t       |" << std::endl;
        std::cout << "\t\t++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
        std::cout << "\t\t|\t 1 : Yes \t||\t 0 : No\t       |" << std::endl;
        std::cout << "\t\t++++++++++++++++++++++++++++++++++++++++++++++++\n\n\t\t";
        std::cin >> n1;

        if (n1 == 1)
        {
        	system ("cls");

			for (auto it = chip.begin(); it < chip.end(); ++it)
			{
				if (it->Num == number)
				{
					Trash.push_back(*it);
					it = chip.erase(it);
					std::cout << "\n\n\t\t\t\033[1m\033[7m\033[31m Chip Moved to Trash \033[0m\033[0m\033[0m" << std::endl;
					Update_file ();
					break;
				}
			}
		}
	}

	Update_Trash_file ();
}

/***************************************************************************************************************/

void Chip::Reload (int n)
{
	int amount {}, n1 {};
	
	std::cout << "\n\n\t\t Please enter the amount : ";

	while (true)
	{
		if (std::cin >> amount && amount > 0)
		{
			break;
		}
		else
		{
			// La donnée saisie n'était pas un entier ou était négative
			std::cout << "\n\n\t\t Invalid number. Please try again" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\n\n\t\t Amount : ";
		}
	}

	n1 = Display_account (n);

	for (auto it = chip.begin(); it < chip.end(); ++it)
	{
		if (it->Num == n)
		{
			it->Balance += amount;

			if (amount >= 500)
			{
				it->Bonus += amount;
			} 

			std::cout << "\n\n\t\t\t\033[1m\033[7m\033[36m Recharge completed \033[0m\033[0m\033[0m" << std::endl;
			std::cout << "\n\n\t\t\033[1m\033[36m You have received 100% bonus \033[0m\033[0m" << std::endl;
			Update_file ();
			break;
		}
	}

	if (n1 == 0)
	{
		std::cout << "\n\n\t\t\033[1m\033[36m Account after recharge \033[0m\033[0m" << std::endl;
		Display_account (n);
	}
}

/***************************************************************************************************************/

int Chip::GetBalance (int num) const
{
	for (auto it = chip.begin(); it < chip.end(); ++it)
	{
		if (it->Num == num)
		{
			Update_file ();
			return it->Balance;
		}
	}
return 0;
}

/***************************************************************************************************************/

int Chip::SendSMS (int num)
{
	int number {};
	txt :
		std::cout << "\n\n\t\t Please enter the receiver\'s number : +227";
		while (true)
		{
			if (std::cin >> number && number > 0)
			{
				break;
			}
			else
			{
				// La donnée saisie n'était pas un entier ou était négative
				std::cout << "\n\n\t\t Invalid number. Please try again" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\n\n\t\t Number :+227";
			}
		}

	number = Search_Number1(number);
	if (number == 0)
	{
		std::cout << "\n\n\t\t\033[1m\033[31m The number +227" << number << " does not exists\033[0m\033[0m " << std::endl;
		goto txt;
	}

	// Trie le vector par numero ;
            		
    std::sort(chip.begin(), chip.end(), [] (const Chip& a, const Chip& b){
        return a.Num < b.Num;
            });
         
    // Supression des doublons
            		
    chip.erase(std::unique(chip.begin(), chip.end(), [](const Chip& a, const Chip& b){
        return a.Num == b.Num;
            }), chip.end());

	for (auto it = chip.begin(); it < chip.end(); ++it)
	{
		if (it->Num == num)
		{
			it->NumberEnv++;

			for (auto pas = chip.begin(); pas < chip.end(); ++pas)
			{
				if (pas->Num == number)
				{
					pas->NumberRec++;

					if ((it->Network == pas->Network))
					{
						it->Balance = GetBalance(it->Num);

						if (it->Balance == 0)
							return printf("\n\n\t\t\033[1m\033[31m Sorry your balance is insufficient \033[0m\033[0m\n\n"); 
						
						it->Balance--; it->Cpt++;
						Chip Sms;
						Sms.Num1 = it->Num;
						cin.ignore();
						std::cout << "\n\n\t\t Please tape the message : ";
						getline(cin, Sms.FName);
						Sms.Num = pas->Num;
						SendEnv.push_back(Sms);
						SendRec.push_back(Sms);
						std::cout << "\n\n\t\t\t\033[1m\033[34m Message sent \033[0m\033[0m" << std::endl;
						Update_file ();
						return 0;
					}
					else if ((it->Network != pas->Network))
					{
						it->Balance = GetBalance(it->Num);

						if (it->Balance <= 5)
							return printf("\n\n\t\t\033[1m\033[31m Sorry your balance is insufficient \033[0m\033[0m\n\n"); 
						
						it->Balance -= 5; it->Cpt += 5;
						Chip Sms;
						Sms.Num1 = it->Num;
						cin.ignore();
						std::cout << "\n\n\t\t Please tape the message : ";
						getline(cin, Sms.FName);
						Sms.Num = pas->Num;
						SendEnv.push_back(Sms);
						SendRec.push_back(Sms);
						std::cout << "\n\n\t\t\t\033[1m\033[34m Message sent \033[0m\033[0m" << std::endl;
						Update_file ();
						return 0;
					}
				}
			}
		}
	}
return 0;
}

/***************************************************************************************************************/

int Chip::Exchange (int num)
{
	int number {};
	txt :
		std::cout << "\n\n\t\t Please enter the receiver\'s number : +227";
		while (true)
		{
			if (std::cin >> number && number > 0)
			{
				break;
			}
			else
			{
				// La donnée saisie n'était pas un entier ou était négative
				std::cout << "\n\n\t\t Invalid number. Please try again" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\n\n\t\t Number :+227";
			}
		}
	int number1 = number;
	number = Search_Number1(number);
	if (number == 0)
	{
		std::cout << "\n\n\t\t\033[1m\033[31m The number +227" << number1 << " does not exists\033[0m\033[0m " << std::endl;
		goto txt;
	}

	std::cout << "\n\n\t\t Message between " << num << " and " << number << "\n" << std::endl;

	int cpt = 0;
	for (auto it = SendEnv.begin(); it < SendEnv.end(); ++it)
	{
		if (((it->Num1 == num) && (it->Num == number)) || ((it->Num == num) && (it->Num1 == number)))
		{
			std::cout << "\n\n\t\t " << it->FName << std::endl;
			cpt++;
		}
	}
	if (cpt != 0)
	{
		Update_file ();
		return 0;
	}

return printf("\n\n\t\t No message between\n");
}

/***************************************************************************************************************/

void Chip::CalculateRecipe (int num) 
{
	// Trie le vector par numero ;
            		
    std::sort(chip.begin(), chip.end(), [] (const Chip& a, const Chip& b){
        return a.Num < b.Num;
            });
         
    // Supression des doublons
            		
    chip.erase(std::unique(chip.begin(), chip.end(), [](const Chip& a, const Chip& b){
        return a.Num == b.Num;
            }), chip.end());
	
	for (auto it = chip.begin(); it < chip.end(); ++it)
	{
		if (it->Num == num)
		{
			std::cout << "\n\t\t**************************************" << std::endl;
			std::cout << "\n\t\t Recipe : " << it->Cpt << " SAHEL" << std::endl;
			std::cout << "\n\t\t**************************************" << std::endl;
		}
	}
	Update_file ();
}

/***************************************************************************************************************/

int Chip::Display_account (int number) const 
{
	for (auto it = chip.begin(); it < chip.end(); ++it)
	{
		if (it->Num == number)
		{
			std::cout << "\n\t\t**************************************" << std::endl;
			std::cout << "\n\t\t Number : +227" << it->Num << std::endl;
			std::cout << "\t\t Network : " << it->Network << std::endl;
			std::cout << "\t\t FName : " << it->FName << std::endl;
			std::cout << "\t\t Balance : " << it->Balance << " SAHEL" << std::endl;
			std::cout << "\t\t Bonus : " << it->Bonus << " SAHEL" << std::endl;
			SendEnv1(it->Num); 
			SendRec1(it->Num);
			std::cout << "\n\t\t**************************************" << std::endl;
			Update_file ();
			return 0;
		}
	}
return printf("\n\n\t\t\033[1m\033[31m The number +227 %d does not exist\033[0m\033[0m ", number);
}

/***************************************************************************************************************/

void Chip::Update_file () const
{
	fstream file("File.txt", ios::out);

	if(file.is_open())
	{
		for (const Chip &chip : chip)
			file << chip.Num << " " << chip.Network << " " << chip.FName << " " << chip.Balance << " " << chip.Bonus << " " << chip.Cpt << std::endl;
	}
	file.close();
}

/***************************************************************************************************************/

void Chip::Read_file ()
{// Vider le vecteur
	chip.clear();

	fstream file("File.txt", ios::in);

	if(file.is_open())
	{
		int number, balance, bonus, cpt; std::string network, fname, lname;
		while (file >> number >> network >> fname >> lname >> balance >> bonus >> cpt)
		{
			Num = number;
			Network = network;
			FName = fname + " " + lname;
			Balance = balance;
			Bonus = bonus;
			Cpt = cpt;
			Chip chip1(Num, Network, FName, Balance, Bonus, Cpt);
			chip.push_back(chip1);
		}
	}
	file.close();
}

/***************************************************************************************************************/

int Chip::SendEnv1 (int number) const
{
	int cpt = 0;
	for (auto it = SendEnv.begin(); it < SendEnv.end(); ++it)
	{
		if (it->Num1 == number)
		{
			std::cout << "\n\t\t Message sent : " << it->FName << std::endl;
			std::cout << "\t\t To : " << it->Num << std::endl;
			cpt++;
		}
	}
	if (cpt != 0)
		return 0;
return printf("\n\t\t No messages sent\n");
}

/***************************************************************************************************************/

int Chip::SendRec1 (int number) const
{
	int cpt = 0;
	for (auto it = SendRec.begin(); it < SendRec.end(); ++it)
	{
		if (it->Num == number)
		{
			std::cout << "\n\t\t Message received : " << it->FName << std::endl;
			std::cout << "\t\t From : " << it->Num1 << std::endl;
			cpt++;
		}
	}
	if (cpt != 0)
		return 0;
return printf("\n\t\t No messages received\n");
}

/***************************************************************************************************************/

int Chip::Search_Number (int number) const
{
	for (auto it = chip.begin(); it < chip.end(); ++it)
	{
		if (it->Num == number)
		{
			return 0;
		}
	}
return number;
}

/***************************************************************************************************************/

int Chip::Search_Number1 (int number) const
{
	for (auto it = chip.begin(); it < chip.end(); ++it)
	{
		if (it->Num == number)
		{
			return number;
		}
	}
return 0;
}

/***************************************************************************************************************/
 
void Chip::Input2 () 
{
	int number;
	txt : 
		std::cout << "\n\n\t\t Number : +227";
		while (true)
			{
				if (std::cin >> number && number > 0)
				{
					break;
				}
				else
				{
					// La donnée saisie n'était pas un entier ou était négative
					std::cout << "\n\n\t\t Invalid number. Please try again" << std::endl;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "\n\n\t\t Number : +227";
				}
			}
	int number1 = number;
	number = Search_Number(number);
	if (number == 0)
	{
		std::cout << "\n\n\t\t\033[1m\033[31m The number +227" << number1 << " already exists\033[0m\033[0m " << std::endl;
		goto txt;
	}
	number = Niger_Telecom_control (number);
	Num = number;
	Network = "Niger_Telecom";
	cin.ignore();
	FName  = controlName();
	std::cout << "\n\n\t\t Balance : ";
	while (true)
		{
			if (std::cin >> Balance && Balance > 0)
			{
				break;
			}
			else
			{
				// La donnée saisie n'était pas un entier ou était négative
				std::cout << "\n\n\t\t Invalid number. Please try again" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\n\n\t\t Balance :";
			}
		}

	Chip chip1(Num, Network, FName, Balance, 0);

    chip.push_back(chip1);

	Save_file();
	Update_file();

}

/***************************************************************************************************************/
 
void Chip::Input3 () 
{
	int number;
	txt : 
		std::cout << "\n\n\t\t Number : +227";
		while (true)
			{
				if (std::cin >> number && number > 0)
				{
					break;
				}
				else
				{
					// La donnée saisie n'était pas un entier ou était négative
					std::cout << "\n\n\t\t Invalid number. Please try again" << std::endl;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "\n\n\t\t Number : +227";
				}
			}
	int number1 = number;
	number = Search_Number(number);
	if (number == 0)
	{
		std::cout << "\n\n\t\t\033[1m\033[31m The number +227" << number1 << " already exists\033[0m\033[0m " << std::endl;
		goto txt;
	}
	number = Airtel_control (number);
	Num = number;
	Network = "Airtel";
	cin.ignore();
	FName  = controlName();
	std::cout << "\n\n\t\t Balance : ";
	while (true)
		{
			if (std::cin >> Balance && Balance > 0)
			{
				break;
			}
			else
			{
				// La donnée saisie n'était pas un entier ou était négative
				std::cout << "\n\n\t\t Invalid number. Please try again" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\n\n\t\t Balance :";
			}
		}

	Chip chip1(Num, Network, FName, Balance, 0);

    chip.push_back(chip1);

	Save_file();
	Update_file();

}

/***************************************************************************************************************/
 
void Chip::Input4 ()
{
	int number;
	txt : 
		std::cout << "\n\n\t\t Number : +227";
		while (true)
			{
				if (std::cin >> number && number > 0)
				{
					break;
				}
				else
				{
					// La donnée saisie n'était pas un entier ou était négative
					std::cout << "\n\n\t\t Invalid number. Please try again" << std::endl;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "\n\n\t\t Number : +227";
				}
			}
	int number1 = number;
	number = Search_Number(number);
	if (number == 0)
	{
		std::cout << "\n\n\t\t\033[1m\033[31m The number +227" << number1 << " already exists\033[0m\033[0m " << std::endl;
		goto txt;
	}
	number = Moov_control (number);
	Num = number;
	Network = "Moov";
	cin.ignore();
	FName  = controlName();
	std::cout << "\n\n\t\t Balance : ";
	while (true)
		{
			if (std::cin >> Balance && Balance > 0)
			{
				break;
			}
			else
			{
				// La donnée saisie n'était pas un entier ou était négative
				std::cout << "\n\n\t\t Invalid number. Please try again" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\n\n\t\t Balance :";
			}
		}

	Chip chip1(Num, Network, FName, Balance, 0);

    chip.push_back(chip1);

	Update_file();

}
