#include <iostream>
#include <string>
#include <ctime>

using namespace std;

string generator(int length)
{
    string newPassword;
    string characters = "0123456789!@#$%^&*()abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int position;

    // use time to seed rand()
    srand(time(nullptr));

    for (int i = 0; i < length; i++)
    {
        position = rand() % characters.length();
        newPassword += characters[position];
    }

    return newPassword;
}

int main()
{
    int length;

    cout << "How long do you want your password to be?\n";
    cin >> length;
    cout << endl;

    cout << "Your Password is: ";
    cout << generator(length);
    cout << endl;

    return 0;
}