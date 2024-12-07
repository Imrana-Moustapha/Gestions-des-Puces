# include <iostream>
# include <typeinfo>
# include <cstdio>
# include <chrono>
# include <thread>
# include <string>
# include <cstdlib>
# include <iomanip>
# include <ctime>
# include <cctype>
# include <fstream>
# include "../include/Chip.hpp"

#ifdef _WIN32
    #include <conio.h>
#else
    #include <termios.h>
    #include <unistd.h>
#endif

using namespace std;

    std::string mon_code0;

int val = 1;

/*************************************************************************************************************************/

void Control()
{
    Read_file ();
    Password ();
    Save_file ();
    system("cls");
}

/*************************************************************************************************************************/

void Password ()
{

    int i{3};
    bool code, check{true};
    std::string essai;
    std::string mon_code1;
    code = false;

    if (mon_code0.empty())
    {
        std::cout <<"\n\n\t\t Enter the new code :";
        mon_code0 = getSaisieMasquee();
        system("cls");
    }

    while(check)
    {
        std::cout <<"\n\n\t\t Confirm the code :";
        mon_code1 = getSaisieMasquee();

        if (mon_code0 == mon_code1)
        {
            check = false;
        }
        else
        {
            std::cout <<"\n\n\t\t the code must match first code entered \a." <<std::endl;
            --i;
        }

        if(i == 0)
        {
            std::cout << "\n\n\t\t Too many incorrect attempts. \n please wait 30 seconds before trying again." <<std::endl;
            for(int seconds = 30; seconds > 0; --seconds)
            {
                std::cout << "\n\t\t " << "Retry in " << seconds << " \r ";
                std::this_thread::sleep_for(std::chrono::seconds(1));
                system("cls");
            }
            std::cout << "\n\n\t\t Wait is over, you can try again ." <<std::endl;
            i = 3;
        }
    }
}

/*************************************************************************************************************/

void Save_file ()
{
    mon_code0 = criptage(mon_code0);

    fstream file("../file/Password.txt", ios::out);
    
    if(file.is_open())
        file << mon_code0 << " " << val;
    file.close();
}

/*************************************************************************************************************************/

void Read_file ()
{
    std::string number {}; int val1 = 0;

    fstream file("../file/Password.txt", ios::in);

    if(file.is_open())
    {
        while (file >> number >> val1)
        {
            file >> number;
            number = decriptage(number);
            mon_code0 = number;
            val += val1;
        }
        
    }
    file.close();
}

/*************************************************************************************************************************/

void Time ()
{
    std::cout << endl;
    std::time_t currentTime = std::time(nullptr);

    // Struct tm pour stocker les composants de temps (heure, minute, etc.)
    std::tm *localTime = std::localtime(&currentTime);

    // Affichage du temps au format "hh:mm:ss"
    // Affichage de la date au format "jj-mm-aaaa"
    std::cout << "\n\n" << std::endl;
    std::cout << "\t\t -----------------\t\t\t       ----------------- " <<std::endl;
    std::cout << "\t\t|\033[1m\033[34m Date :" << std::put_time(localTime, "%d-%m-%Y")<<"\033[0m\033[0m|";
    std::cout << "\t\t\t      |\033[34m\033[1m Temps :" << std::put_time(localTime, "%T") <<"\033[0m\033[0m |" << std::endl;
    std::cout << "\t\t -----------------\t\t\t       ----------------- " << std::endl;
}

/*************************************************************************************************************************/

int Number_control (float number)
{
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
			std::cout << "\n\n\t\t Number :";
		}
	}

    number = (int)number;

    return number;
}

/*************************************************************************************************************************/

int Orange_control (int number1)
{
    string number = std::to_string(number1);
    bool F;
    do{
        F=false;

    // VÃ©rifier si la longueur est egale à  8
    if (number.length() == 8) {
        // Extraire les deux premiers chiffres
        string B = number.substr(0, 2);

        // Convertir les deux premiers chiffres en entier
        int C = stoi(B);

        // Verifier si les deux premiers chiffres sont dans les intervalles 
        if ((C >= 70 && C <= 72) ||
            (C >= 80 && C <= 82) ||
            (C >= 90 && C <= 92))
        {
    		number1 = std::stoi(number);
    		return number1;
        } 
	else 
	{
            std::cout << "\n\n\t\t The isn\'t Zamani Telecom number." << std::endl;
    }
    } 
    else
    {
        std::cout << "\n\n\t\t PLease you must enter eight(8) digits." << std::endl;
    }
    std::cout << "\n\n\t\t Number : +227";
    std::cin >> number;
}while(!F);
 
return 0;
}

/*************************************************************************************************************************/

void About ()
{
    system ("cls");

    std::string About = "\n\n\t\t About \n"
    "\n\t\t We wouldn\'t begin this program without thanking the good lord for giving us the opportunity\n"
   "\t\t to see the great day.\n"

    "\n\t\t This program is based on chip management, allowing you to add, modify, delete, display all \n"
    "\t\t chips, and many other features to discover. We invite you to explore it step by step and we\n"
    "\t\t hope that this program will meet your expectations.\n"

    "\n\t\t Through this program, we take the opportunity to express our gratitude to our leader, friend \n"
    "\t\t and teacher Mr Moubarak, for guiding us, providing advice , and supporting us troughout. we \n"
    "\t\t cannot thank him enough, and a special thanks to our dear teacher MOUBARAK... \n"

    "\n\t\t Written by : \n"
    "\n\t\t\t RABE SAIDOU ADAMOU \n"
    "\n\t\t\t ASSOUMANA MAHAMADOU ISSA \n"
    "\n\t\t\t SALISSOU MAHAMANE ABOUBACAR \n"
    "\n\t\t\t MAMANE IDE IDE \n"
    "\n\t\t\t SAADOU HABOU MOUSAL ACH ARI \n"
    "\n\t\t\t MOUSTAPHA MAHAMAN MAIKASSOUA IMRANA \n";
    
    for (char Character : About)
    {
    	std::cout << Character << std::flush;
    	std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    
    std::cout << std::endl;

    getchar ();
}

/*************************************************************************************************************************/

void welcom ()
{
    system("cls");
    
    std::string welcomeArt = "\n\n\n\n\n\n\n\n\n\n\n\n\n\t ___          ___    ____        _           ____        _______      _     _      ____ \n"

                             "\t \\  \\        /  /   | ___|      | |         |  __|      |  ___  |    |  \\_/  |    | ___|\n"
                             "\t  \\  \\  __  /  /    | |_        | |         | |         | |   | |    | |\\_/| |    | |_  \n"
                             "\t   \\  \\/  \\/  /     | |__       | |__       | |__       | |___| |    | |   | |    | |__ \n"
                             "\t    \\___/\\___/      |____|      |____|      |____|      |_______|    |_|   |_|    |____|\n";

    // Afficher chaque caractère un à un avec une pause
    for (char character : welcomeArt) 
    {
        std::cout << character << std::flush;
        // Pause pour un effet progressif
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    std::cout << std::endl;

    getchar();
}

/*************************************************************************************************************************/

int Niger_Telecom_control (int number1)
{
    string number = std::to_string(number1);
    bool F;
    do{
        F=false;

    // VÃ©rifier si la longueur est egale à  8
    if (number.length() == 8) {
        // Extraire les deux premiers chiffres
        string B = number.substr(0, 2);

        // Convertir les deux premiers chiffres en entier
        int C = stoi(B);

        // Verifier si les deux premiers chiffres sont dans les intervalles 
        if ((C == 83 || C == 93))
        {
    		number1 = std::stoi(number);
    		return number1;
        } 
	else 
	{
            std::cout << "\n\n\t\t The isn\'t Niger Telecom number." << std::endl;
    }
    } 
    else
    {
        std::cout << "\n\n\t\t PLease you must enter eight(8) digits." << std::endl;
    }
    std::cout << "\n\n\t\t Number : +227";
    std::cin >> number;
}while(!F);
 
return 0;
}

/*************************************************************************************************************************/

int Airtel_control (int number1)
{
    string number = std::to_string(number1);
    bool F;
    do{
        F=false;

    // VÃ©rifier si la longueur est egale à  8
    if (number.length() == 8) {
        // Extraire les deux premiers chiffres
        string B = number.substr(0, 2);

        // Convertir les deux premiers chiffres en entier
        int C = stoi(B);

        // Verifier si les deux premiers chiffres sont dans les intervalles 
        if ((C >= 76 && C <= 79) ||
            (C >= 86 && C <= 89) ||
            (C >= 96 && C <= 99))
        {
    		number1 = std::stoi(number);
    		return number1;
        } 
	else 
	{
            std::cout << "\n\n\t\t The isn\'t Airtel number." << std::endl;
    }
    } 
    else
    {
        std::cout << "\n\n\t\t PLease you must enter eight(8) digits." << std::endl;
    }
    std::cout << "\n\n\t\t Number : +227";
    std::cin >> number;
}while(!F);
 
return 0;
}

/*************************************************************************************************************************/

int Moov_control (int number1)
{
    string number = std::to_string(number1);
    bool F;
    do{
        F=false;

    // VÃ©rifier si la longueur est egale à  8
    if (number.length() == 8) {
        // Extraire les deux premiers chiffres
        string B = number.substr(0, 2);

        // Convertir les deux premiers chiffres en entier
        int C = stoi(B);

        // Verifier si les deux premiers chiffres sont dans les intervalles 
        if ((C >= 74 && C <= 75) ||
            (C >= 84 && C <= 85) ||
            (C >= 94 && C <= 95))
        {
    		number1 = std::stoi(number);
    		return number1;
        } 
	else 
	{
            std::cout << "\n\n\t\t The isn\'t Moov number." << std::endl;
    }
    } 
    else
    {
        std::cout << "\n\n\t\t PLease you must enter eight(8) digits." << std::endl;
    }
    std::cout << "\n\n\t\t Number : +227";
    std::cin >> number;
}while(!F);
 
return 0;
}

/*************************************************************************************************************************/

std::string getSaisieMasquee() 
{
    std::string saisie;
    char ch;

#ifdef _WIN32
    while ((ch = _getch()) != 13) 
    { // 13 correspond à la touche Entrée
        if (ch == 8) 
        { // 8 correspond à la touche Retour arrière (Backspace)
            if (!saisie.empty()) 
            {
                std::cout << "\b \b"; // Déplacer le curseur en arrière, effacer le caractère, puis revenir en arrière
                saisie.pop_back();
            }
        }
         else 
        {
            std::cout << '*';
            saisie += ch;
        }
    }
#else
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~ECHO; // Désactiver l'affichage des caractères
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    while ((ch = getchar()) != '\n') 
    {
        if (ch == 127) 
        { // 127 correspond au code ASCII pour la touche Retour arrière
            if (!saisie.empty()) 
            {
                std::cout << "\b \b"; // Déplacer le curseur en arrière, effacer le caractère, puis revenir en arrière
                saisie.pop_back();
            }
        } 
        else 
        {
            std::cout << '*';
            saisie += ch;
        }
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restaurer les paramètres du terminal d'origine
#endif

    return saisie;
}

/*************************************************************************************************************************/

std::string criptage (std::string txt)
{
    for (int i = 0; i < txt.size(); ++i)
    {
        txt[i] -= 3;
    }

    return txt;
}

/*************************************************************************************************************************/

std::string decriptage (std::string txt)
{
    for (int i = 0; i < txt.size(); ++i)
    {
        txt[i] += 3;
    }

    return txt;
}

/*************************************************************************************************************************/

void clear()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

/*************************************************************************************************************************/

std::string controlName()
{
    std::string name;

    chip : 
        std::cout << "\n\n\t\t First Name and Last Name : ";
        getline(std::cin , name);

        for (int i = 0; i < name.length(); i++)
        {
            if(isdigit(name[i]))
            {
                goto chip;
            }
        }

    return name;
}
