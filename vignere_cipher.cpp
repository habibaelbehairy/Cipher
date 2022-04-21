#include <iostream>
#include <string>
using namespace std;
string message,keyword;
int x,y;
string preparingkeyword()//preparing keyword to use it in cipher or decipher message
{
    int m = keyword.length();
    for (int i = 0; i <= m ; i++) 
    {   
        x = message.length();
        y = keyword.length();

        if (y==x)//if message length=keyword lengh then break
        {
            break;
        }
        
        if (y < x)//if keyword length is smaller than message length
        {
            keyword.push_back(keyword[i]);//We add the value i as the parameter to the back of the keyword
        }
        if (i == m)//if i =keyword length then i will be =0 to make the loop again 
        {
            i = 0;
        }
    }
    return keyword;
}
string encrypt(){
    cout<<"Please enter the message you want to encrypt: ";
    cin.ignore();
    getline(cin,message);
    cout<<"Please enter keyword you want to use: ";
    cin>>keyword;

    x=message.length();
    y=keyword.length();

    while (x > 80)//if message length is greater than 80
    {
        cout << "long message please enter a shorter message" << endl;;
        cin >> message;
        x = message.length();
    }
    if (x<=80) //if message length is smaller than 80
    {
        cout << "message less than 80" << endl;;
        while (y > 8)//while keyword length is greater than 8
        {
            cout << "long keyword please enter a shorter keyword" << endl;
            cin >> keyword;
            y = keyword.length();
        }
        if (y<=8)//if keyword length lessthan or equal 8
        {
            cout<<"keyword less than 8" << endl;
            preparingkeyword();
        }
    }   
    string encryption = "";

    for (int v = 0; v < message.length(); v++)//for loop on each character in the message
    {   
        if (isdigit(message[v]))//if character is digit number
        {
            encryption += message[v];
        }
        else if (int(message[v]) == int(' '))//if character is space
        {
            encryption += message[v];
        }
        else
        {
            message[v] = toupper(message[v]);//change each character in the message to upper letter
            keyword[v] = toupper(keyword[v]);//change each character in the keyword to upper letter

            int z = (int(message[v]) + int(keyword[v])) % 26;
            z += int('A');

            encryption += char(z);
        }
    }
    cout << "encrypted message = " << encryption << endl;
    return encryption;
}
    

string decrypt(){
    //string message2, keyword2;
    cout << "Please enter the message you want to decrypt: ";
    cin.ignore();
    getline(cin, message);
    cout<<"Please enter keyword you want to use: ";
    cin >> keyword;

    x = message.length();
    y = keyword.length();

    while (x > 80)//if message length is greater than 80
    {
        cout << "long message please enter a shorter message" << endl;;
        cin >> message;
        x = message.length();
    }
    if (x <= 80)//if message length is smaller than 80
    {
        cout << "message less than 80" << endl;;
        while (y > 8)//while keyword length is greater than 8
        {
            cout << "long keyword please enter a shorter keyword" << endl;
            cin >> keyword;
            y = keyword.length();
        }
        if (y <= 8)//if keyword length lessthan or equal 8
        {
            cout << "keyword less than 8" << endl;
            preparingkeyword();
        }
    }
    string decryption = "";

    for (int v = 0; v < message.length(); v++)//for loop on each character in the message
    {
        if (isdigit(message[v]))//if character is digit number
        {
            decryption += message[v];
        }
        else if (int(message[v]) == int(' '))//if character is space
        {
            decryption += message[v];
        }
        else
        {
            int z = (int(message[v]) - int(keyword[v]) + 26) % 26;
            z += int('A');

            decryption += char(z);
        }
    }
    cout << "decrypted message = " << decryption << endl;
    return decryption;
}
int main()
{
    cout << "Ahlan Ya User Ya Habibi" << endl;
    cout << "What do you like to do today?" << endl;
    cout << "1-Cipher message" << endl;
    cout << "2-Decipher message" << endl;
    cout << "3-End" << endl;
    int n;
    cin >> n;
    while (n < 1 || n > 3)
    {
        cout << "Please enter number from 1 to 3" << endl;
        cout << "1-Cipher message" << endl;
        cout << "2-Decipher message" << endl;
        cout << "3-End" << endl;
        cin >> n;
    }
    if (n == 1) {
        encrypt();
    }
    if (n == 2) {
        decrypt();
    }
    if (n == 3) {
        cout << "END" << endl;
    }
}