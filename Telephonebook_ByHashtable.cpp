/*BATUHAN KILLIOGLU 
THIS PROJECT RUNS LIKE THAT, PROGRAM SHOWS SELECTIONS TO USER AND WAIT FOR INPUT.
AFTER INPUT IT CHECKS IF INPUT IS CORRECT OR NOT THEN CONTINUES.
PROGRAM CHOOSES USER'S FIRST NUMBER AS A KEY BECAUSE EVERYONES PHONE NUMBER IS UNIQUE AND
USERS SHOULD NOT ENTER ANOTHER NUMBER FOR KEY. PROGRAM'S SIZE IS 200 THAT MEANS IT CAN ADD 200 CONTACTS.
CONTACTS NUMBER MUST BE INTEGER OTHERWISE PROGRAM WILL NOT SAVE IT AND PROGRAM WILL GO TO START.
PROGRAM DOES NOT ALWAYS UPDATE TEXT FILE. IT UPDATES TEXT FILE IF USERS WANT TO WRITE TO TEXT FILE.
ALSO USERS CAN SHOW OLD CONTACTS IN TEXT FILE BEFORE ADD ANYTHING NEW. IF A NEW CONTACT IS ADDED THEN
PROGRAM CLEAR TEXT FILE'S OLD CONTACTS AND WRITE NEW CONTACTS. ALSO USERS CAN SHOW NEWLY CHANGED TEXT FILE.
THE NAME OF THE TEXT FILE IS DATABASE. 
*/

#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
#include <fstream>
using namespace std;
// SIZE IS SIZE OF TELEPHONEBOOK.
const int Size = 200;
class HashTableEntry {
public:
    int k,v,c;
    string name,surname,address,email,emailsec;
    HashTableEntry(int k, int v, int c, string name,string surname, string address, string email,string emailsec) {
        this->k = k;
        this->v = v;
        this->c = c;
        this->name = name;
        this->surname =surname;
        this->address =address;
        this->email = email;
        this->emailsec = emailsec;
    }
};
class HashMapTable {
private:
    HashTableEntry** t;
public:
    HashMapTable() {
        t = new HashTableEntry * [Size];
        for (int i = 0; i < Size; i++) {
            t[i] = NULL;
        }
    }
    /*HERE WE TAKE MOD'S OF FIRST NUMBER (KEY) BY TELEPHONEBOOK'S SIZE*/
    int HashFunc(int k) {
        return k % Size;
    }
    /*HERE WE SAVE CONTACTS TO ARRAY
    PROGRAM TAKE INPUTS FROM USER. WE CHOOSE USERS FIRST NUMBER AS A KEY BECAUSE WE DO NOT WANT USER TO
    ENTER ANOTHER INTEGER OR STRING FOR KEY. AFTER INPUTS PROGRAM CHOOSE A PLACE IN ARRAY
    AND CHECK IF ITS NULL OR NOT AND IF THERE IS ALSO THE SAME Fırst NUMBER IN THE ARRAY. 
    PROGRAM DOES NOT CARE SECOND AND THIRD NUMBER BECAUSE A FAMILY CAN USE THE SAME HOME TELEPHONE NUMBER
    OR A PERSON CAN SELECT SECOND NUMBER AS ANOTHER PERSON'S PHONE NUMBER SUCH AS A CHILD CAN CHOOSE IT 
    AS FATHER'S OR MOTHER'S NUMBER.
    IF PROGRAM FINDS NUMBER WHICH IS MATCHED WITH THE INPUT THEN ITS NOT WRITE TO ARRAY.
    PROGRAM KEEPS THE OLD DATAS.
    IF IT IS NOT NULL THEN PROGRAM GOES ONE UPPER ARRAY POINT H=H+1
    IT CONTINUES TO FIND A NULL POINT AFTER PROGRAM FOUND NULL POINT THEN IT SAVES THE INPUTS.
    */
    void Insert(int k,int v,int c,string name,string surname,string address,string email,string emailsec) 
    {
        int h = HashFunc(k);
     
        
        while (t[h] != NULL &&t[h]->k != k) {
            h = HashFunc(h + 1);
        }
        if (t[h] == NULL) {

            t[h] = new HashTableEntry(k, v, c, name, surname, address, email, emailsec);
            cout << "******Mission completed!*******" << endl;
        }
        else
            cout << "Already has a record mission didnt complete" << endl;
    }
    // WE CHECK THE INPUTS IF STRING OR INTEGER//
    bool check_number(string str) {
        for (int i = 0; i < str.length(); i++)
            if (isdigit(str[i]) == false)
                return false;
        return true;
    }
    /* WE SEARCH AN ACCOUNT HERE BY USING NUMBER
       PROGRAM TAKES INPUT NUMBER FROM USERS THEN TRIES TO MATCH IT.
       IF PROGRAM FINDS ANY NUMBER EXACT TO INPUT THEN IT PRINT CONTACTS INFORMATION TO SCREEN.
       WE USE SAYAC AS A CHECK FLAG. ITS CHECK IF DATABASE IS EMPTY OR NOT.
       SAYAC VALUE INCREASES IF ARRAY IS NOT EMPTY 
      IF SAYAC VALUE DID NOT INCREASED THEN PROGRAM SAYS DATA BASE IS EMPTY.
    */
    void SearchKey(int k) {
        int sayac=0;
        for (int i = 0; i < Size; i++) {
            if (t[i] != NULL)
            {
                sayac++;
                if ((t[i]->k == k) || (t[i]->v == k) || (t[i]->c == k)) {

                    cout << "Number :" << t[i]->k << endl;
                    cout << "Second Number :" << t[i]->v << endl;
                    cout << "Third Number :" << t[i]->c << endl;
                    cout << "Name :" << t[i]->name << endl;
                    cout << "Surname :" << t[i]->surname << endl;
                    cout << "address :" << t[i]->address << endl;
                    cout << "Email address :" << t[i]->email << endl;
                    cout << "Second email address :" << t[i]->emailsec << endl;
                }

            }
          
        }
                  if(sayac==0)
                cout << "Database is empty" << endl;

                  cout << "********************" << endl;
        }      
    /* WE SEARH AN ACCOUNT HERE BY USING NAME  OR PART OF A NAME
    HERE WE TAKE INPUT NAME AND USE FIND FUNCTION. IF NAME INCLUDES ANY PART OF INPUT,
    PROGRAM WILL PRINT IT TO SCREEN CONTACTS WHICH ARE CONTAINS INPUT.
    IF IT DOESN'T MATCH ANY ACCOUNT THAN PROGRAM WILL SAY COULDN'T FIND
    WE USE K HERE AS A CHECK FLAG IF DATABASE IS EMPTY OR NOT SUCH AS IF DATABASE IS NOT EMPTY
    THEN ITS VALUE INCREASES AT THE END WE CHECK K'S VALUE.
    */
    void Searchname(string name) {
        std::size_t found;
        int k = 0;
        for (int i = 0; i < Size; i++)
        {
            if (t[i] != NULL)
            {
                k++;
                found = t[i]->name.find(name);
                if (found != string::npos)
                {
                    cout << "Number : " << t[i]->k << endl;
                    cout << "Second Number :" << t[i]->v << endl;
                    cout << "Third Number :" << t[i]->c << endl;
                    cout << "Name :" << t[i]->name << endl;
                    cout << "Surname :" << t[i]->surname << endl;
                    cout << "address :" << t[i]->address << endl;
                    cout << "Email address :" << t[i]->email << endl;
                    cout << "Second email address :" << t[i]->emailsec << endl;
                }
                if (found == string::npos)
                    cout << "Couldn't Found" << endl;
            }
            
        }
        if(k==0)
                cout << "Database is empty" << endl;

        cout << "********************" << endl;
    }
    /* WE DELETE CONTACTS HERE
    AFTER USER ENTER FIRST NUMBER (PROGRAM TAKES IT AS KEY) IT SEARCHES KEY AT ITS POSSIBLE POSITION
    IF IT COULDN'T FIND IT CONTINUES TO SEARCH BY ONE BY ONE. AFTER THIS STEP IF IT COULDN'T FIND ANY
    MATCHED DATA IT DOES NOT DELETE ANY THING. IF IT FINDS IT WILL DELETE THAT ARRAY AND AFTER THAT
    IT DEFINE THAT ARRAY POINT AS A NULL. WE DEFINE IT AS A NULL BECAUSE IT COULD BE USEABLE IN ANOTHER USES.
   
    */
    void Remove(int k) {
        int h = HashFunc(k);
        while (t[h] != NULL) {
            if (t[h]->k == k)
                break;
            h = HashFunc(h + 1);
        }
        if (t[h] == NULL) {
            cout << "No contact is found at key " << k << endl;
            return;
        }
        else {
            delete t[h];
            t[h] = NULL;
        }
        cout << "Contact is Deleted" << endl;
    }
    ~HashMapTable() {
        for (int i = 0; i < Size; i++) {
            if (t[i] != NULL)
                delete t[i];
            delete[] t;
        }
    }
    /* WE DISPLAY CONTACTS WHICH WERE ADDED AFTER APPLICATION STARTED.
    WE USE FOR LOOP FOR TO SCAN ALL ARRAY AND WE USE K AS CHECK FLAG.
    K WORKS LIKE THAT, IF ARRAY IS EMPTY THEN ITS VALUE DOES NOT GO UP
    AND STAY 0 AFTER THAT WE CHECK IF K IS ZERO OR NOT .
    */
    void display()
    {
        int k = 0;
        for (int i = 0; i < Size; i++)
        {
           
            if (t[i] != NULL)
            {
                cout << "Number : " << t[i]->k << endl;
                cout << "Second Number : " << t[i]->v << endl;
                cout << "Third Number : " << t[i]->c << endl;
                cout << "Name : " << t[i]->name << endl;
                cout << "Surname : " << t[i]->surname << endl;
                cout << "address : " << t[i]->address << endl;
                cout << "Email address : " << t[i]->email << endl;
                cout << "Second email address : " << t[i]->emailsec << endl;
                 k++;
            }
        }
        if (k == 0)
            cout << "Database is empty" << endl;
    }
    /* WE CHANGE OR APPEND DATAS HERE WITH EDIT FUNCTION
    FIRST PROGRAM CHECK IF INPUT (TUS) THEN GOES TO IFS.
    IF ITS FIRST NUMBER WHICH WILL BE EDITED THEN WE ADD NEW CONTACT THEN WE DELETE OLD
    CONTACT BECAUSE PROGRAM TAKES FIRST NUMBER AS A KEY.
    IF ITS JUST ANOTHER CRITERIA WHICH IS EDITTED THEN ITS JUST REWRITE ON IT.
    */
    void edit(int k, int tus) {
        int h = HashFunc(k);
        int a = 0;
        string str;
        int check;
        while (t[h] != NULL) {
            if (t[h]->k == k) {
                if (tus == 1) {
                    cout << "Enter new number :";
                    cin >> str;
                    for (int i = 0; i < str.length(); i++)
                    {
                        if (isdigit(str[i]) == false)
                        {
                            a = 0;

                        }
                        else
                            a = 1;
                    }
                    if (a == 1) {

                        if (t[h]->k == std::stoi(str)) {
                            cout << "New number can not be the same as old number" << endl;
                        }
                        else {

                        t[h]->k = std::stoi(str);
                        Insert(t[h]->k, t[h]->v, t[h]->c, t[h]->name, t[h]->surname, t[h]->address, t[h]->email, t[h]->emailsec);
                        delete t[h];
                        t[h] = NULL;

                        }

                    };
                    if(a==0)
                        cout << "Please enter number " << endl;
                };
                if (tus == 2) {
                    cout << "Enter new name :";
                    cin >> t[h]->name;
                };
                if (tus == 3) {
                    cout << "Enter new surname :";
                    cin >> t[h]->surname;
                };
                if (tus == 4) {
                    cout << "Enter new address :";
                    cin >> t[h]->address;
                };
                if (tus == 5) {
                    cout << "Enter new email :";
                    cin >> t[h]->email;
                };
                if (tus == 6) {
                    cout << "Enter new second number :";
                    cin >> t[h]->v;
                };
                if (tus == 7) {
                    cout << "Enter new third number :";
                    cin >> t[h]->c;
                };
                if (tus == 8) {
                    cout << "Enter new second email :";
                    cin >> t[h]->emailsec;
                };
                if (tus == 9) {
                    cout << "Exit :";
                };
            }
            h = HashFunc(h + 1);
        }
    }
    /* WE SAVE CHANGES TO DATA BASE HERE. IF IT ALREADY HAS DATA IN IT THEN WE CLEAR AND REWRITE.
        IF USER WANTS TO SAVE CONTACTS TO TEXT FILE THEN PROGRAM USES THIS MODULE TO SAVE IT.  
        PROGRAM FIRST CREAT TEXT FILE IF ITS ALREADY CREATED THEN PROGRAM OPENS THE TEXT FILE.
        THEN PROGRAM WRITES ALL ARRAYS TO THE TEXT FILE AND AFTER THE PROCESS  PROGRAM CLOSES THE 
        TEXT FILE.
    */
    void databasewrite() {
        ofstream myfile("database.txt");
        for (int i = 0; i < Size; i++)
        {
            if (t[i] != NULL)
            {

                myfile << "Number :" << t[i]->k << endl;
                myfile << "Second Number :" << t[i]->v << endl;
                myfile << "Third Number :" << t[i]->c << endl;
                myfile << "Name :" << t[i]->name << endl;
                myfile << "Surname :" << t[i]->surname << endl;
                myfile << "Address :" << t[i]->address << endl;
                myfile << "Email address :" << t[i]->email << endl;
                myfile << "Second email address :" << t[i]->emailsec << endl;
            };
        }
        myfile.close();
        cout << "Mission completed" << endl;
    }
    /* WE LOAD CONTACTS FROM DATABASE 
    IF USER WANTS TO READ TEXT FILE PROGRAM USES TTHIS MODULE 
    FIRST PROGRAM OPENS TEXT FILE BY USING IFSTREAM MYFILE COMMAND THEN PROGRAM TAKES LINES AND PRINTS IT
    TO THE CONSOLE(SCREEN). AFTER PROCESS IS DONE WE CLOSE FILE.
    
    */
    void databaseread() {
        int sayac = 0;
        string line;
        ifstream myfile("database.txt");
        for (int i = 0; i < Size; i++)
        {
            sayac++;
            if (myfile.is_open())
            {
                while (getline(myfile, line))
                {

                    cout << line << '\n';
                    
                }

            }
        }
        myfile.close();
        cout << " ***************" << endl;
        if (sayac == 0)
            cout << "Database is empty" << endl;
    }
};
int main() {

    /*AT HERE WE DEFINE VARIABLES WHICH WE WILL USE IN CASES. */
    HashMapTable hash;
    int k=0, v=0,c=0;// THERE ARE INTEGER WHICH WILL BE SAVE NUMBERS 
    int choice,tus;// WE USE THIS INTEGERS FOR CHOICES AND CASES.
    string name,check,surname,email,emailsec,address;// THESE ARE STRING BECAUSE IT CAN CONTAINS NUMBERS DOTS SPACES.
    while (1) {
        /*WE WANTS USERS TO GIVE PROGRAM AN ORDER HERE */
        cout << "1.Save a person into the table" << endl;
        cout << "2.Search a person " << endl;
        cout << "3.Delete a person" << endl;
        cout << "4.Display all contacts" << endl;
        cout << "5.Edit  contacts " << endl;
        cout << "6.Show all contacts from database" << endl;
        cout << "7.Save all contacts to database" << endl;
        cout << "8.Exit " << endl;
        cout << "Enter your choice: ";
        /* FIRST WE CHECK THE INPUT IF ITS INTEGER OR NOT. IF ITS NOT INTEGER WE STARTS AGAIN FROM BEGINNING
        IF ITS INTEGER THEN USE THIS INPUT AS CHOICE.*/
        cin >> check;
        if (hash.check_number(check)) {
            choice = std::stoi(check);
        }
        else
            choice = 0;
        switch (choice) {
        case 1:  
            cout << "Enter telephone number at which element to be inserted :";
            cin >> check;
            if (hash.check_number(check)) {
                k = std::stoi(check);
            }
            else {
                cout << "The input was string please enter number " << endl;
                cout << "************************************** " << endl;
                break;
            };
                cout << "Do you want to enter second number?  1 for Yes or Another Number for No (0)" << endl;
                cin >> check;
                if (hash.check_number(check)) {
                    tus = std::stoi(check);
                    if (tus == 1) {
                        cout << "number:";
                        cin >> check;
                        if (hash.check_number(check)) {
                            v = std::stoi(check);

                        }
                        else {
                            cout << "The input was string please enter number " << endl;
                            cout << "************************************** " << endl;
                            tus = NULL;
                            break;
                        };
                        cout << "Do you want to enter third number?  1 for Yes or Another Number for No (0)" << endl;
                        cin >> check;
                        if (hash.check_number(check)) {
                            tus = std::stoi(check);
                            if (tus == 1) {
                                cout << "number:";
                                cin >> check;
                                if (hash.check_number(check)) {
                                    c = std::stoi(check);

                                }
                                else {
                                    cout << "The input was string please enter number " << endl;
                                    cout << "************************************** " << endl;
                                    tus = NULL;
                                    break;

                                };
                            }

                        }
                        else {
                            cout << "The input was string please enter number " << endl;
                            cout << "************************************** " << endl;
                            tus = NULL;
                            break;

                        };
                    }

                }        
                else {
                        cout << "The input was string please enter number " << endl;
                        cout << "************************************** " << endl;
                        break;
                    };
            cout << "Enter name to be inserted :";
            cin.ignore();
            getline(cin,name);
            cout << "Enter surname to be inserted :";
            cin.clear();
            getline(cin,surname);
            cout << "Enter address to be inserted :";
            cin.clear();
            getline(cin,address);
            cout << "Enter email address to be inserted :";
            cin.clear();
            getline(cin,email);
            cout << "Do you want to add Second Email?  1 for Yes or Another Number for No (0)" << endl;
            cin >> check;
            if (hash.check_number(check))
            {
                tus = std::stoi(check);
                if (tus == 1) {
                    cout << "Please enter second email :";
                    cin.ignore();
                    getline(cin,emailsec);
                }

                else {
                    emailsec.empty();
                }
            }
            else
                cout << "Please enter number not character" << endl;
            hash.Insert(k,v,c,name,surname,address,email,emailsec);
            break;
        case 2:
            cout << "Press 1 For Searching Number or Press to 2 For Searching by Name and To Exit Press Another number(0) :";
            cin >> check;
            if (hash.check_number(check)) {
                tus = std::stoi(check);
                if (tus == 1) {
                    cout << "Enter First number of the person to be searched: ";
                    cin >> check;
                    if (hash.check_number(check)) {
                        k = std::stoi(check);
                        hash.SearchKey(k);
                    }
                    else {
                        cout << "Please enter Number not character" << endl;
                        cout << "******************************" << endl;
                    }
                }
                if (tus == 2)
                {
                      cout << "Enter name of the element to be searched: ";
                         cin >> name;
                          hash.Searchname(name);
                }
            }   
            else {
                        cout << "The input was string please enter number " << endl;
                        cout << "************************************** " << endl;
                        break;
                    };
            break;
        case 3:
            cout << "Press 1 For Applying Removing Application by Name or Press 2 For Applying Removing Application by Number :";
            cin >> check;
            if (hash.check_number(check)) {
                tus = std::stoi(check);
                if (tus == 1) {
                    cout << "Please Enter the Name You Want To Remove :";
                    cin >> name;
                    hash.Searchname(name);
                    cout << "Please Enter the Number of the Name You Want to Remove :";
                    cin >> check;
                    if (hash.check_number(check)) {
                        k = std::stoi(check);
                        hash.Remove(k);
                    }
                    else {
                        cout << "Please enter number" << endl;
                        break;
                    }
                    }
                if (tus == 2) {
                         cout << "Enter Number of the person to be deleted: ";
                             cin >> check;
                             if (hash.check_number(check)) {
                                 k = std::stoi(check);
                                 hash.Remove(k);
                             }
                             else {
                                 cout << "Please enter number" << endl;
                                 break;
                             }
                            

                }
            }
                break;
        case 4:
            hash.display();
            break;
        case 5:
            cout << "Please Select the Section You Want To Change" << endl;
            cout << "1:Number 2:Name 3:Surname 4:Address 5:Email 6:Second Number 7: Third Number 8:Second Email 9:Exit" << endl;
            cin >> check;
            if (hash.check_number(check)) {
                tus = std::stoi(check);
                check.clear();
                if (tus == 1) {
                    cout << "Enter personal number for Personal information" << endl;
                    cin >> k;
                    hash.edit(k,tus);
                };
                if (tus == 2) {
                    cout << "Enter personal number for Personal information" << endl;
                    cin >> k;
                    hash.edit(k, tus);
                };
                if (tus == 3) {
                    cout << "Enter personal number for Personal information" << endl;
                    cin >> k;
                    hash.edit(k, tus);
                };
                if (tus == 4) {
                    cout << "Enter personal number for Personal information" << endl;
                    cin >> k;
                    hash.edit(k, tus);
                };
                if (tus == 5) {
                    cout << "Enter personal number for Personal information" << endl;
                    cin >> k;
                    hash.edit(k, tus);
                };
                if (tus == 6) {
                    cout << "Enter personal number for Personal information" << endl;
                    cin >> k;
                    hash.edit(k, tus);
                };
                if (tus == 7) {
                    cout << "Enter personal number for Personal information" << endl;
                    cin >> k;
                    hash.edit(k, tus);
                };
                if (tus == 8) {
                    cout << "Enter personal number for Personal information" << endl;
                    cin >> k;
                    hash.edit(k, tus);
                };
                if (tus == 9) {
                    cout << "Returning to Main menu" << endl;
                    break;
                };
            }
            break; 
        case 6:
            hash.databaseread();
            break;
        case 7:
            hash.databasewrite();
            break;
        case 8:
            exit(1);
        default:
            cout << "\nEnter correct option\n";
        }
    }
    return 0;
}
