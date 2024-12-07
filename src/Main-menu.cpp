# include <iostream>
# include <stdio.h>
# include <vector>
# include <string>
# include <limits>
# include <map>
# include <algorithm>
# include "../include/Chip.hpp"

using namespace std;

void Chip::Main_menu ()
{
    bool choice1 {}; int choice {}, number {}, number1 {}, amount {};

    extern int val;

    if(val == 1) 
    {
        About ();
    }

    std::cout << std::endl;

    clear();

    Time ();
    do
    {
        texte1 : 
        
            std::cout << "\n\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
            std::cout << "\n\t\t||\033[1m\033[35m************************* Main-menu *************************\033[0m\033[0m||" << std::endl;
            std::cout << "\t\t|| \t01 : Input \t\t|  \t07 : Reload \t       ||" << std::endl;
            std::cout << "\t\t|| \t02 : Display \t\t|  \t08 : Calculate-Recipe  || " << std::endl;
            std::cout << "\t\t|| \t03 : Modify \t\t|  \t09 : GetBalance        || " << std::endl;
            std::cout << "\t\t|| \t04 : Delete \t\t|  \t10 : Display-Account   || " << std::endl;
            std::cout << "\t\t|| \t05 : Send-SMS \t\t|  \t11 : About \t       || " << std::endl;
            std::cout << "\t\t|| \t06 : Exchange \t\t|  \t12 : Trash    \t       || " << std::endl;
            std::cout << "\t\t|| \t13 : Delete all \t|  \t14 : Exit    \t       || " << std::endl;
            std::cout << "\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
            std::cout << "\t\t||\033[1m\033[32m The file updates automatically after each operation \033[0\033[0m        ||" <<std::endl;
            std::cout << "\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;

            std::cout << "\t\t Please enter your choice : ";
        while (true)
		{
			if (std::cin >> choice && choice > 0)
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

        Read_file (); Load_Trash_File ();   
        
        clear();

        switch (choice)
        {
            do
            {
                system ("cls");
                
                case 1 : std::cout << "\n\n\t\t\033[1m Input \033[0m" << std::endl;
                        texte2 :
                            std::cout << "\n\n\t\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
                            std::cout << "\n\t\t|| \t\033[1m\033[33m 1 : Zamani Telecom \t \033[0m\033[0m| \t\033[1m\033[31m 3 : Airtel \t  \033[0m\033[0m||" << std::endl;
                            std::cout << "\t\t|| \t\033[1m\033[37m 2 : Niger Telecom \t \033[0m\033[0m| \t\033[1m\033[32m 4 : Moov Niger   \033[0m\033[0m|| " << std::endl;
                            std::cout << "\t\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                            std::cout << "\t\t Please enter your choice : ";
                            while (true)
                            {
                                    if (std::cin >> choice && choice > 0)
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

                            clear();

                            switch (choice)
                                {
                                    case 1 : Input1 (); break;
                                    case 2 : Input2 (); break;
                                    case 3 : Input3 (); break;
                                    case 4 : Input4 (); break;
                                    default : cout << "\n\n\t\t\t\a Error in choice ... \n" << endl; goto texte2;
                                }
                std::cout << "\n\n\t\t++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                std::cout << "\t\t| Do you want to return to the previous menu ??|" << std::endl;
                std::cout << "\t\t++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                std::cout << "\t\t|\t 1 : Yes \t||\t 0 : No\t       |" << std::endl;
                std::cout << "\t\t++++++++++++++++++++++++++++++++++++++++++++++++\n\n\t\t";
                std::cin >> choice1;
                clear();
            } while (choice1 != 0); 

            break;

            case 2 : std::cout << "\n\n\t\t\033[1m\033[32m Display \033[0m\033[0m" << std::endl;
                        // Trie le vector par numero ;
            		
                        std::sort(chip.begin(), chip.end(), [] (const Chip& a, const Chip& b){
                            return a.Num < b.Num;
                                });
                            
                        // Supression des doublons
                                        
                        chip.erase(std::unique(chip.begin(), chip.end(), [](const Chip& a, const Chip& b){
                            return a.Num == b.Num;
                                }), chip.end());
            	        
                        Display(); break;

            case 3 : std::cout << "\n\n\t\t\033[1m\033[33m Modify \033[1m\033[0m" << std::endl;
                        
                        Modify (); break;

            case 4 : std::cout << "\n\n\t\t\033[1m\033[31m Delete \033[0m\033[0m" << std::endl;
                        
                        Delete(); break;

            case 5 : std::cout << "\n\n\t\t\033[1m\033[35m Send-SMS \033[0m\033[0m" << std::endl;
                        txt2 :
                            std::cout << "\n\n\t\t Please enter the sender\'s number : +227";
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
                        number1 = number;
                        number = Search_Number1(number);
                        if (number == 0)
                        {
                            std::cout << "\n\n\t\t\033[1m\033[31m The number +227" << number1 << " does not exists\033[0m\033[0m " << std::endl;
                            goto txt2;
                        }

                        SendSMS (number);
                        break;
            
            case 6 : std::cout << "\n\n\t\t\033[1m\033[34m Exchage \033[0m\033[0m" << std::endl;
                        txt :
                            std::cout << "\n\n\t\t Please enter the sender\'s number : +227";
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
                        number1 = number;
                        number = Search_Number1(number);
                        if (number == 0)
                        {
                            std::cout << "\n\n\t\t\033[1m\033[31m The number +227" << number1 << " does not exists\033[0m\033[0m " << std::endl;
                            goto txt;
                        }
                        Exchange (number);
                        break;

            case 7 : std::cout << "\n\n\t\t\033[1m\033[36m Reload \033[0m\033[0m" << std::endl;
                        
                        std::cout << "\n\n\t\t Please enter the chip number : +227";
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
                        
                        Reload (number); break;

            case 8 : std::cout << "\n\n\t\t\033[1m\033[37m Calculate-Recipe \033[0m\033[0m" << std::endl;
                        
                        std::cout << "\n\n\t\t Please enter the chip number : +227";
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

                        CalculateRecipe (number); break;

            case 9 : std::cout << "\n\n\t\t\033[1m\033[38m GetBalance \033[0m\033[0m" << std::endl;
                        
                        std::cout << "\n\n\t\t Please enter the chip number : +227";
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

                        std::cout << "\n\n\t\t " << GetBalance (number) << std::endl; break;

            case 10 : std::cout << "\n\n\t\t\033[1m\033[39m Display-Account \033[0m\033[0m" << std::endl;
                        
                        std::cout << "\n\n\t\t Please enter the chip number : +227";
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
                        
                        Display_account (number); break;

            case 11 :   About (); break;

            case 12 : std::cout << "\n\n\t\t\033[1m Trash \033[0m" << std::endl;
                do
                {   
                    system ("cls");

                    texte3 :
                        std::cout << "\n\n\t\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
                        std::cout << "\n\t\t|| \t\033[1m 1 : Display the trash \t \033[0m| \033[1m\033[35m 3 : Restore a number  \033[0m\033[0m||" << std::endl;
                        std::cout << "\t\t|| \t\033[1m\033[32m 2 : Search for a number \033[0m\033[0m| \033[1m\033[31m 4 : Empty the trash   \033[0m\033[0m|| " << std::endl;
                        std::cout << "\t\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                        std::cout << "\t\t Please enter your choice : ";
                        while (true)
                        {
                                if (std::cin >> choice && choice > 0)
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

                        clear();

                        switch (choice)
                            {
                                case 1 : DisplayTrash (); break;

                                case 2 : std::cout << "\n\n\t\t Please enter the chip number : +227";
                                
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
                                
                                Display_Trash_account (number); break;
                                
                                case 3 : std::cout << "\n\n\t\t Please enter the chip number : +227";
                                
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
                                
                                Restoration_Trash (number); break;
                                
                                case 4 : Trash_clear (); break;

                                default : cout << "\n\n\t\t\t\a Error in choice ... " << endl; goto texte3;
                            }
                    std::cout << "\n\n\t\t++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    std::cout << "\t\t| Do you want to return to the previous menu ??|" << std::endl;
                    std::cout << "\t\t++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    std::cout << "\t\t|\t 1 : Yes \t||\t 0 : No\t       |" << std::endl;
                    std::cout << "\t\t++++++++++++++++++++++++++++++++++++++++++++++++\n\n\t\t";
                    std::cin >> choice1;
                    clear();
                } while (choice1 != 0);

                    break;

            case 13 :   

                chip.clear ();
                Trash.clear ();
                SendEnv.clear ();
                SendRec.clear ();
                Update_file ();
                Update_Trash_file ();
                std::cout << "\n\n\t\t\t\033[1m\033[7m\033[31m Deletion completed \033[0m\033[0m\033[0m" << std::endl;
                break;

            case 14 :

                exit(0);

            default : cout << "\n\n\t\t\t\a Error in choice ... \n" << endl; goto texte1;
        }
        std::cout << "\n\n\t\t++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
        std::cout << "\t\t| You\'ll find yourself back at the main-menu ??|" << std::endl;
        std::cout << "\t\t++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
        std::cout << "\t\t|\t 1 : Yes \t||\t 0 : No\t       |" << std::endl;
        std::cout << "\t\t++++++++++++++++++++++++++++++++++++++++++++++++\n\n\t\t";
        std::cin >> choice1;
        clear();
    } while (choice1 != 0);        
}
