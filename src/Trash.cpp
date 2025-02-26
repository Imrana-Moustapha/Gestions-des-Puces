# include <iostream>
# include <cstdio>
# include <chrono>
# include <thread>
# include <string>
# include <vector>
# include <algorithm>
# include <fstream>
# include "../include/Chip.hpp"

using namespace std;

/***************************************************************************************************************/

void Chip::DisplayTrash () const
{
    for (auto it = Trash.begin(); it < Trash.end(); ++it)
	{
		std::cout << "\n\t\t**************************************" << std::endl;
		std::cout << "\n\t\t Number : +227" << it->Num << std::endl;
		std::cout << "\t\t Network : " << it->Network << std::endl;
		std::cout << "\t\t FName : " << it->FName << std::endl;
		std::cout << "\t\t Balance : " << it->Balance << " SAHEL" << std::endl;
		std::cout << "\t\t Bonus : " << it->Bonus << " SAHEL" << std::endl;
		std::cout << "\n\t\t**************************************" << std::endl;
	}
}

/***************************************************************************************************************/

int Chip::Display_Trash_account (int number) const // 
{
	for (auto it = Trash.begin(); it < Trash.end(); ++it)
	{
		if (it->Num == number)
		{
			std::cout << "\n\t\t**************************************" << std::endl;
			std::cout << "\n\t\t Number : +227" << it->Num << std::endl;
			std::cout << "\t\t Network : " << it->Network << std::endl;
			std::cout << "\t\t FName : " << it->FName << std::endl;
			std::cout << "\t\t Balance : " << it->Balance << " SAHEL" << std::endl;
			std::cout << "\t\t Bonus : " << it->Bonus << " SAHEL" << std::endl;
			std::cout << "\n\t\t**************************************" << std::endl;
			return 0;
		}
	}
return printf("\n\n\t\t\033[1m\033[31m The number +227%d does not exist\033[0m\033[0m ", number);
}

/***************************************************************************************************************/

void Chip::Restoration_Trash (int number)
{
    Display_Trash_account (number);
    
    for (auto it = Trash.begin(); it < Trash.end(); ++it)
    {
        if (it->Num == number)
        {
            chip.push_back(*it);
            it = Trash.erase(it);
            std::cout << "\n\n\t\t\t\033[1m\033[34m Chip restored \033[0m\033[0m" << std::endl;
            Update_file ();
            Update_Trash_file ();
            break;
        }
    }
}

/***************************************************************************************************************/

void Chip::Trash_clear ()
{
    Trash.clear ();
    Update_Trash_file ();
    std::cout << "\n\n\t\t\t\033[1m\033[7m\033[31m Deletion completed \033[0m\033[0m\033[0m" << std::endl;
}

/***************************************************************************************************************/

void Chip::Update_Trash_file () const
{
    fstream file("Trash.txt", ios::out);

    if (file.is_open())
    {
        for (const Chip &deletedChip : Trash)
        {
            file << deletedChip.Num << " " << deletedChip.Network << " " << deletedChip.FName << " " << deletedChip.Balance << " " << deletedChip.Bonus << " " << deletedChip.Cpt << std::endl;
        }
    }
    file.close();
}

/***************************************************************************************************************/

void Chip::Load_Trash_File()
{
    Trash.clear();

    fstream file("Trash.txt", ios::in);

    if (file.is_open())
    {
        int number, balance, bonus, cpt;
        std::string network, fname, lname;

        while (file >> number >> network >> fname >> lname >> balance >> bonus >> cpt)
        {
            Num = number;
            Network = network;
            FName = fname + " " + lname;
            Balance = balance;
            Bonus = bonus;
            Cpt = cpt;
            Chip deletedChip(Num, Network, FName, Balance, Bonus, Cpt);
            Trash.push_back(deletedChip);
        }

    }
    file.close();
}
