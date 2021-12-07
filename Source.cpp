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

int main()
{
    cout << "Text search" << endl;
    bool repeat = true;
    while (repeat)
    {
        ifstream infile;
        string to_find;
        cout << "Input a string>";
        getline(cin, to_find);
        string filename;
        cout << "Input a filename>";
        getline(cin, filename);
        size_t pos;
        infile.open(filename);
        //cout << endl << filename;
        bool check = false;
        //cout << to_find << endl << filename << endl;
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
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return 0;
}