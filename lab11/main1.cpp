#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print_menu();

struct note {
    char Firstname[10];
    char Secondname[10];
    char Fathername[10];
    int ThinksWeight;
    int Mesta;
    void print()
    {
        cout << Firstname << " ";
        cout << Secondname << " ";
        cout << Fathername << " ";
        cout << ThinksWeight << " ";
        cout << Mesta << endl;
    }
};

void scopy(char* arr, string str)
{
    for (int i = 0; i < (int)str.size() + 1; i++) {
        arr[i] = str[i];
    }
}

int main()
{
    bool flag;
    vector<note> notes;
    note InputNote;
    int ForSwitch;
    string InputTemp;
    string FileName;
    int n;
    fstream file;
    do {
        print_menu();
        cin >> ForSwitch;
        system("clear");
        switch (ForSwitch) {
        case 1:
            cout << "input N:";
            cin >> n;
            cout << "input name of file:";
            cin >> FileName;
            file.open(FileName + ".txt", ios::out);

            for (int i = 0; i < n; i++) {
                cout << "input FIO:";
                cin >> InputTemp;
                scopy(InputNote.Firstname, InputTemp);
                cin >> InputTemp;
                scopy(InputNote.Secondname, InputTemp);
                cin >> InputTemp;
                scopy(InputNote.Fathername, InputTemp);
                cout << "input weight of things:";
                cin >> InputNote.ThinksWeight;
                cout << "input space for things:";
                cin >> InputNote.Mesta;
                file.write((char*)&InputNote, sizeof(InputNote));
                system("clear");
            }
            file.close();
            break;
        case 2:
            cout << "input name of file:";
            cin >> FileName;
            cout << endl;
            file.open(FileName + ".txt", ios::in);
            while (true) {
                file.read((char*)&InputNote, sizeof(InputNote));
                if (file.eof())
                    break;
                InputNote.print();
            }
            cout << endl;
            file.close();
            break;
        case 3:
            cout << "input name of file:";
            cin >> FileName;
            file.open(FileName + ".txt", ios::out | ios::app);
            file.seekg(-1, ios::end);
            cout << "input FIO:";
            cin >> InputTemp;
            scopy(InputNote.Firstname, InputTemp);
            cin >> InputTemp;
            scopy(InputNote.Secondname, InputTemp);
            cin >> InputTemp;
            scopy(InputNote.Fathername, InputTemp);
            cout << "input weight of things:";
            cin >> InputNote.ThinksWeight;
            cout << "input space for things:";
            cin >> InputNote.Mesta;
            file.write((char*)&InputNote, sizeof(InputNote));
            system("clear");
            file.close();
            break;
        case 4:
            cout << "input name of file:";
            cin >> FileName;
            cout << endl;
            file.open(FileName + ".txt", ios::in);
            while (true) {
                file.read((char*)&InputNote, sizeof(InputNote));
                if (!(InputNote.ThinksWeight < 10)) {
                    notes.push_back(InputNote);
                }
                if (file.eof())
                    break;
            }
            file.close();
            file.open(FileName + ".txt", ios::out);
            for (int i = 0; i < (int)notes.size(); i++) {
                file.write((char*)&notes[i], sizeof(InputNote));
            }
            file.close();
            notes.clear();
            break;
        case 5:
            cout << "input name of file:";
            cin >> FileName;
            cout << endl;
            cout << "input firstname:";
            cin >> InputTemp;
            cout << "input new weight:";
            cin >> n;
            file.open(FileName + ".txt", ios::in | ios::out);
            while (true) {
                file.read((char*)&InputNote, sizeof(InputNote));
                if (file.eof())
                    break;
                notes.push_back(InputNote);
                if (notes[notes.size() - 1].Firstname == InputTemp)
                    notes[notes.size() - 1].ThinksWeight = n;
            }
            file.close();
            file.open(FileName + ".txt", ios::out);
            for (int i = 0; i < (int)notes.size(); i++) {
                file.write((char*)&notes[i], sizeof(InputNote));
            }
            file.close();
            notes.clear();
            break;
            break;
        }
    } while (ForSwitch != 0);
    return 0;
}

void print_menu()
{
    cout << "1.create a file from N records" << endl;
    cout << "2.view the file" << endl;
    cout << "3.add a new entry to the end of the file" << endl;
    cout << "4.find and delete from the file records about passengers whose "
            "total weight of things is less than 10 kg."
         << endl;
    cout << "5.change the weight of the passenger's belongings by the "
            "specified name "
         << endl;
}
