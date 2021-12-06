#include <iostream>
#include <string>
#include <fstream>

using namespace std;
bool frepeat() {

    string repeatt;
    cout << "\nContinue? (Y/N)>";
    cin >> repeatt;
    while (((repeatt == "Y") || (repeatt == "y") || (repeatt == "N") || (repeatt == "n")) != 1 || (cin.peek() != '\n'))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Unidentified operator, try again" << endl;
        cout << "Repeat? (Y/N) " << endl;
        cin >> repeatt;
        cout << endl;
    }
    if (repeatt == "Y" || repeatt == "y")
    {
        return true;
    }
    else
    {
        return false;
    }
}

string check_str()
{
    
    string in_value;
    cout << "Input a string>";
    cin >> in_value;
    while ((cin.fail()) || (cin.peek() != '\n'))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Wrong type of input data, try again: "; cin >> in_value;
        cout << endl;
    }
    return in_value;
    
}

string filename_check()
{

    string in_value;
    cout << "Input a filename>";
    cin >> in_value;
    while ((cin.fail()) || (cin.peek() != '\n'))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Wrong type of input data, try again: "; cin >> in_value;
        cout << endl;
    }
    return in_value;

}

int main()
{
    cout << "Text search" << endl;
    bool repeat = true;
    while (repeat)
    {
        ifstream infile;
        string to_find = check_str();
        string filename = filename_check();
        size_t pos;
        infile.open(filename);
        bool check = false;
        if (!infile.is_open()) cout << "Can`t open the file." << endl;
        else
        {
            int i = 0;
            while (!infile.eof() && !check)
            {
                i++;
                string buffer;
                getline(infile, buffer);
                
                if (pos = buffer.find(to_find) != string::npos)
                {
                    cout << "Line #" << i << endl << buffer << endl;
                    check = true;
                }
            }
            if (!check) cout << "No such string in input file." << endl;
        }
        infile.close();
        repeat = frepeat();
    }
    return 0;
}