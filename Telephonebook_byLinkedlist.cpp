#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
#include <fstream>
using namespace std;
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
    int HashFunc(int k) {
        return k % Size;
    }
    void Insert(int k, int v, int c,string name, string surname, string address, string email,string emailsec) {
        int h = HashFunc(k);
        while (t[h] != NULL &&t[h]->k != k) {
            h = HashFunc(h + 1);
        }
        if (t[h]!= NULL && t[h]->k == k) {
            cout << "*************************" << endl;
            cout << "Database already has the same Key" << endl;
            cout << "*************************" << endl;
        };
        if (t[h] == NULL) {
            t[h] = new HashTableEntry(k,v,c, name,surname,address,email,emailsec);
            cout << "Mission completed!" << endl;
        };
    }
    bool check_number(string str) {
        for (int i = 0; i < str.length(); i++)
            if (isdigit(str[i]) == false)
                return false;
        return true;
    }
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

     /*   int h = HashFunc(k);
        while (t[h] != NULL && t[h]->k != k) {
            h = HashFunc(h + 1);
        }
        if (t[h] == NULL)
        {
            cout << "No element found at key " << k << endl;
            return -1;
        }
        else
        {
            cout << "Number : " << t[h]->k << endl;
            cout << "Second Number : " << t[h]->v << endl;
            cout << "Third Number : " << t[h]->c << endl;
            cout << "Name : " << t[h]->name << endl;
            cout << "Surname : " << t[h]->surname << endl;
            cout << "address : " << t[h]->address << endl;
            cout << "Email address : " << t[h]->email << endl;
            cout << "Second email address : " << t[h]->emailsec << endl;
            return 1;
        };*/
        
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
    void display()
    {
        int k = 0;
        for (int i = 0; i < Size; i++)
        {
            k++;
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

            }
        }
        if (k == 0)
            cout << "Database is empty" << endl;
    }
    void edit(int k, int tus) {
        int h = HashFunc(k);
        while (t[h] != NULL) {
            if (t[h]->k == k) {
                if (tus == 1) {
                    cout << "Enter new number :";
                    cin >> t[h]->k;
     Insert(t[h]->k,t[h]->v, t[h]->c, t[h]->name, t[h]->surname, t[h]->address,t[h]->email, t[h]->emailsec);
        delete t[h];
        t[h] = NULL;
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
    HashMapTable hash;
    int k=0, v=0,c=0;
    int choice,tus;
    string name,check,surname,email,emailsec,address;
    while (1) {
        cout << "1.Save a person into the table" << endl;
        cout << "2.Search a person from the database" << endl;
        cout << "3.Delete a person" << endl;
        cout << "4.Display all data" << endl;
        cout << "5.Edit data " << endl;
        cout << "6.Show all data from database" << endl;
        cout << "7. Save all data to database" << endl;
        cout << "8.Exit " << endl;
        cout << "Enter your choice: ";
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
            cin.ignore();
            getline(cin,surname);
            cout << "Enter address to be inserted :";
            cin.clear();
            cin.ignore();
            getline(cin,address);
            cout << "Enter email address to be inserted :";
            cin.clear();
            cin.ignore();
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
                    }

                    hash.SearchKey(k);
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
            cout << "1:Number 2:Name 3:Surname 4:Address 5:Email 6:Second Number 7: Third Number 8:Second Email 9:Exit\n" << endl;
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
