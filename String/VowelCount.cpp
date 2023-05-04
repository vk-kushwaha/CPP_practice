#include <iostream>
#include <cstring>
using namespace std;

int VowelCount(string str)
{
    int count = 0;
    for (int i = 0; i <( (str.length())); i++)
    {
        if ((str[i] == 'a') || (str[i] == 'e') || (str[i] == 'i') || (str[i] == 'o') || (str[i] == 'u'))
            count++;
        if ((str[i] == 'A') || (str[i] == 'E') || (str[i] == 'I') || (str[i] == 'O') || (str[i] == 'U'))
            count++;
    }
    return count;
}
int main()
{
    string str;
    cout << "Enter string to count vowels\n";
    cin >> str;
    cout << "\nTotal Number of vowels are = " << VowelCount(str);
}
