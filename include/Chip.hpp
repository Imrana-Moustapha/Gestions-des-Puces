#ifndef Chip_HPP_INCLUDED
#define Chip_HPP_INCLUDED

# include <string>
# include <vector>

class Chip
{
    private :
        int Num, Num1, Balance, Bonus, NumberEnv, NumberRec, Cpt;
        std::string Network;
        std::string FName;
        std::vector <Chip> chip;
        std::vector <Chip> Trash;
        std::vector <Chip> SendEnv;
        std::vector <Chip> SendRec;
    public :
        Chip(); // Constructeur par d�faut
        Chip (int n, std::string r, std::string np, int s, int b, int c = 0); // Constructeur avec paramétres
        ~Chip(); // Destructeur
        void Main_menu (); // Menu principal
        void Input1 (); // Pour saisir les données au clavier pour une puce Zamani Telecom
        void Input2 (); // Pour saisir les données au clavier pour une puce Niger Telecom
        void Input3 (); // Pour saisir les données au clavier pour une puce Airtel
        void Input4 (); // Pour saisir les données au clavier pour une puce Moov
        void Display () const; // Pour afficher toutes les données d'une Chip
        int  Display_account (int number) const; // Pour afficher un compte donnée
        void Modify (); // Pour modifier une puce
        void Delete (); // Pour supprimer une puce
        void Reload (int n); // Pour recharger ou créditer la Chip
        int SendSMS (int num); // Envoyer le msg (taille en octet) à la Chip indiquée en paramètre
        int Exchange (int num); // Afficher dans cette puce tous les échanges avec la puce en paramétre
        void CalculateRecipe (int num); // Calculer la recette réalisée par cette puce à travers tous les messages envoyés
        int  GetBalance (int num) const; // Renvoie la solde de la puce
        void Update_file () const; // Methode pour mettre à jour le fichier ()
        void Read_file (); // Methode pour dans le fichier
        int Search_Number (int number) const; // Recherche sur un numéro et renvoi 0 si le numéro exist déjà
        int Search_Number1 (int number) const; // Recherche sur un numéro et renvoi le numéro si il n'exist pas
        int SendEnv1 (int number) const; // Pour afficher les messages envoyers
        int SendRec1 (int number) const; // Pour afficher les messages reçus
        
        // Methode pour Trash 
        void DisplayTrash() const; // Pour afficher la corbeille
        int  Display_Trash_account (int number) const; // Pour chercher un numéro dans la corbeille
        void Restoration_Trash (int number); // Pour restoré un numero dans la corbeille
        void Trash_clear (); // Pour vider la corbeille
        void Update_Trash_file () const; // Mettre à jour le fichier de la corbeille
        void Load_Trash_File (); // Lire le fichier de la corbeille

};

    void Control (); // Pour le control de mot de passe
    void Password (); // Pour inserer un mot de passe
    void Save_file (); // Sauvegarder le mot de passe dans un fichier
    void Read_file (); // Pour lire le fichier du mot de passe
    void Time (); // Pour afficher la date et l'heure
    int Orange_control (int number1); // Control si c'est un numéro Zamani Telecom
    int Niger_Telecom_control (int number1); // Control si c'est un numéro Niger Telecom
    int Airtel_control (int number1); // Control si c'est un numéro Airtel
    int Moov_control (int number1); // Control si c'est un numéro Moov
    void About (); // Pour afficher un propos concernant le programme
    void welcom (); // Pour afficher un Welcome
    std::string getSaisieMasquee(); // Pour masqué la saisie du mot de passe
    std::string criptage (std::string txt); // Pour cripter un mot de passe
    std::string decriptage (std::string txt); // Pour decripter un mot de passe
    std::string controlName(); // Pour controler le nom
    void clear(); // Pour effacer l'ecran

#endif // Chip_HPP_INCLUDED
