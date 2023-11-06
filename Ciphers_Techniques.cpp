// FCAI - Programming 1 - 2022 - Assignment 2
// All Ciphers
// Last Modification Date: 26/3/2022
// First author / ID : Habiba Alaa Mohamed / 20210121
// Second author / ID : Alaa Hossam Mohamed / 20210072
// Third author / ID : Ahmed Reda Elsayed / 20210018
// Under The Supervision of: Dr. Mohamed El-Ramly

#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <cctype>
#include <iomanip>
using namespace std;

string Affine_Cipher()
{
    int a, b, x;
    string the_message;
    char characters[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                           'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    string user_name;
    cout << "please enter your name: ";
    cin >> user_name;
    cout << "Ahlan Ya " << user_name << " Ya Habibi " << endl;
    cout << "please enter the number that you want to do. \n"
         << "1-cipher a message. \n"
         << "2-decipher a message. \n"
         << "3-End. \n";
    int what_user_want;
    cin >> what_user_want;
    // check if the integer that user entered is valid or not
    while (what_user_want < 1 || what_user_want > 3)
    {
        cout << "please enter the number that you want to do. \n"
             << "1-cipher a message. \n"
             << "2-decipher a message. \n"
             << "3-End. \n";
        cin >> what_user_want;
    }

    if (what_user_want == 1)
    {
        cout << "please enter the message you want to cipher:";
        cin.ignore();
        getline(cin, the_message);
        cout << "please enter the keys (a,b):";
        cin >> a >> b;
        for (char letter : the_message)
        {
            if (isupper(letter))
            {
                for (int x = 0; x < 26; x++)
                {
                    if (characters[x] == letter)
                    {
                        x = (a * x + b) % 26;
                        cout << characters[x];
                        break;
                    }
                }
            }

            if (islower(letter))
            {
                letter = char(int(letter)) - 32;
                for (int x = 0; x < 26; x++)
                {
                    if (characters[x] == letter)
                    {
                        x = (a * x + b) % 26;
                        cout << characters[x];
                        break;
                    }
                }
            }
            else
            {
                cout << letter;
            }
        }
    }
    if (what_user_want == 2)
    {
        cout << "please enter the message you want to decipher:";
        cin.ignore();
        getline(cin, the_message);
        cout << "please enter the keys (a,b):";
        cin >> a >> b;
        for (char letter : the_message)
        {
            if (isupper(letter))
            {
                for (int x = 0; x < 26; x++)
                {
                    if (characters[x] == letter)
                    {
                        x = abs((a * (x - b)) % 26);
                        cout << characters[x];
                        break;
                    }
                }
            }
            if (islower(letter))
            {
                letter = char(int(letter)) - 32;
                for (int x = 0; x < 26; x++)
                {
                    if (characters[x] == letter)
                    {
                        x = abs((a * (x - b)) % 26);
                        cout << characters[x];
                        break;
                    }
                }
            }
            else
            {
                cout << letter;
            }
        }
    }

    if (what_user_want == 3)
    {
        cout << "End" << endl;
    }
}

string Caser_Cipher()
{
    string user_name;
    cout << "please enter your name: ";
    cin >> user_name;
    cout << "Ahlan Ya " << user_name << " Ya Habibi " << endl;
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

    if (n == 1)
    {
        string text;
        cout << "Please enter your text: ";
        cin >> text; // user enter the text he want to encrypt
        string encryption = "";
        string decryption = "";
        int numofshifts;
        cout << "Please enter number of shifts you want: ";
        cin >> numofshifts;
        if (numofshifts > 26) // numbers of alphabet is 26 so if user enters number more than 26 we get its %
        {
            numofshifts = numofshifts % 26;
        }
        if (numofshifts < 0) // if user enters a negative number so number of shifts will be the negativenumber+26
        {
            numofshifts = 26 + numofshifts;
        }
        int x;
        x = numofshifts; // we let x as a temp for the number of shift

        for (int c = 0; c < text.length(); c++) // for loop to pass on each chr of the text
        {
            numofshifts = x;
            if (c == ' ') // if chr is ' '  pass
            {
                ;
            }
            if (c == ',') // if chr is , pass
            {
                ;
            }
            if (isdigit(text[c])) // if chr is decimal number the chr will be the decimal number + numofshifts
            {
                encryption += char(int(text[c]) + numofshifts);
            }
            if (isupper(text[c])) // if chr is upper letter
            {                     // check if int of this chr + numof shifts less than or equal 90
                if (int(text[c]) + numofshifts <= 90)
                {                                                   // 90 as Z in ascii is equal to 90
                    encryption += char(int(text[c]) + numofshifts); // encrypt=encrypt+chr(int of chr in ascii + numof shifts)
                }
                else
                {                                                    // check if int of this chr + numof shifts greater than 90
                    numofshifts = (numofshifts + int(text[c])) % 90; // we get the in number of chr in asci + number of shifts snd get its modulus 90
                    encryption += char(65 - 1 + numofshifts);        // 65 number of A in Ascii
                    // encrypt=encrypt+chr(number of A in ascii-1+numofshifts)
                }
            }
            if (islower(text[c])) // if chr is lower letter
            {                     // check if int of this chr + numof shifts less than or equal 122
                if (int(text[c]) + numofshifts <= 122)
                {                                                   // 122 as z in ascii is equal to 122
                    encryption += char(int(text[c]) + numofshifts); // encrypt=encrypt+chr(int of chr in ascii + numof shifts)
                }
                else
                {                                                     // check if int of this chr + numof shifts greater than 122
                    numofshifts = (numofshifts + int(text[c])) % 122; // we get the in number of chr in asci + number of shifts snd get its modulus 122
                    encryption += char(97 - 1 + numofshifts);         // 97 number of a in ascii
                    // encrypt=encrypt+chr(number of a in ascii-1+numofshifts)
                }
            }
        }

        cout << "Encryption message is:";
        cout << encryption;
    }
    if (n == 2)
    {
        string text;
        cout << "Please enter your text: ";
        cin >> text; // user enter the text he want to encrypt
        string encryption = "";
        string decryption = "";
        int numofshifts;
        cout << "Please enter number of shifts you want: ";
        cin >> numofshifts;
        if (numofshifts > 26) // numbers of alphabet is 26 so if user enters number more than 26 we get its %
        {
            numofshifts = numofshifts % 26;
        }
        if (numofshifts < 0) // if user enters a negative number so number of shifts will be the negativenumber+26
        {
            numofshifts = 26 + numofshifts;
        }
        int x;
        x = numofshifts; // we let x as a temp for the number of shift

        for (int c = 0; c < text.length(); c++) // for loop to pass on each chr of the text
        {
            numofshifts = x;
            if (c == ' ') // if chr is ' '  pass
            {
                ;
            }
            if (c == ',') // if chr is , pass
            {
                ;
            }
            if (isdigit(text[c]))
            {
                decryption += char(int(text[c]) - numofshifts);
            }
            if (isupper(text[c])) // if chr is upper letter
            {                     // check if int of this chr - numof shifts greater than or equal 65
                if (int(text[c]) - numofshifts >= 65)
                { // 65 as A in ascii is equal to 65
                    decryption += char(int(text[c]) - numofshifts);
                    // decrypt=decrypt+chr(int of chr in ascii -  numof shifts)
                }
                else
                {                                                    // check if int of this chr - numof shifts is less than 65
                    numofshifts = 65 % (int(text[c] - numofshifts)); // numbofshifts=65%(number//numofsho of chr in ascii-numofshifts)
                    decryption += char(90 + 1 - numofshifts);        // decrypt=decrypt+chr(number of Z in ascii+1 -numofshifts)
                }
            }
            if (islower(text[c])) // if chr is lower letter
            {                     // check if int of this chr - numof shifts greater than or equal 97
                if (int(text[c]) + numofshifts >= 97)
                { // 97 as a in ascii is equal to 97
                    decryption += char(int(text[c]) - numofshifts);
                    // decrypt=decrypt+chr(int of chr in ascii -  numof shifts)
                }
                else
                {                                                     // check if int of this chr - numof shifts is less than 97
                    numofshifts = 122 % (int(text[c] - numofshifts)); // numbofshifts=122%(number//numofshiftd of chr in ascii-numofshifts)
                    decryption += char((122) + 1 - numofshifts);      // decrypt=decrypt+chr(number of Z in ascii+1 -numofshifts)
                }
            }
        }
        cout << "decryption message is:";
        cout << decryption;
    }
    if (n == 3)
    {
        cout << "END" << endl;
    }
}
string Atbash_Cipher()
{
    string user_name;
    cout << "please enter your name: ";
    cin >> user_name;
    cout << "Ahlan Ya " << user_name << " Ya Habibi " << endl;
    cout << "please enter the number that you want to do. \n"
         << "1-cipher a message. \n"
         << "2-decipher a message. \n"
         << "3-End. \n";
    int what_user_want;
    cin >> what_user_want;
    // check if the integer that user entered is valid or not
    while (what_user_want < 1 || what_user_want > 3)
    {
        cout << "please enter the number that you want to do. \n"
             << "1-cipher a message. \n"
             << "2-decipher a message. \n"
             << "3-End. \n";
        cin >> what_user_want;
    }

    // cipher the message that user want
    if (what_user_want == 1)
    {
        string the_message;
        string encryption;
        cout << "please enter the message you want to cipher:";
        cin >> the_message;
        for (int x = 0; x < the_message.length(); x++)
        {
            // check if the message is letters or not
            if (64 < char(int(the_message[x])) < 91 || 96 < char(int(the_message[x])) < 123)
            {
                // if they are letters check if they are upper letters or not and cipher them
                if (isupper(the_message[x]))
                {
                    encryption += 155 - char(int(the_message[x]));
                }

                // if they are letters check if they are upper letters or not and cipher them
                if (islower(the_message[x]))
                {
                    encryption += 187 - char(int(the_message[x]));
                }

                // if they are not letters then there is no change
                else
                {
                    encryption += char(int(the_message[x]));
                }
            }
        }
        cout << "Encryption message is:";
        cout << encryption;
    }

    // decipher the message that user want
    if (what_user_want == 2)
    {
        string the_message;
        string decryption;
        cout << "please enter the message you want to decipher:";
        cin >> the_message;
        for (int x = 0; x < the_message.length(); x++)
        {
            // check if the message is letters or not
            if (64 < char(int(the_message[x])) < 91 or 96 < char(int(the_message[x])) < 123)
            {
                // if they are letters check if they are upper letters or not and cipher them
                if (isupper(the_message[x]))
                {
                    decryption += 155 - char(int(the_message[x]));
                }

                // if they are letters check if they are upper letters or not and cipher them
                if (islower(the_message[x]))
                {
                    decryption += 187 - char(int(the_message[x]));
                }

                // if they are not letters then there is no change
                else
                {
                    decryption += char(int(the_message[x]));
                }
            }
        }
        cout << "decryption message is:";
        cout << decryption;
    }

    // if the user wants to end the program then print end and close the program
    if (what_user_want == 3)
    {
        cout << "End" << endl;
    }
}

string message, keyword;
int x, y;
string preparingkeyword() // preparing keyword to use it in cipher or decipher message
{
    int m = keyword.length();
    for (int i = 0; i <= m; i++)
    {
        x = message.length();
        y = keyword.length();

        if (y == x) // if message length=keyword lengh then break
        {
            break;
        }

        if (y < x) // if keyword length is smaller than message length
        {
            keyword.push_back(keyword[i]); // We add the value i as the parameter to the back of the keyword
        }
        if (i == m) // if i =keyword length then i will be =0 to make the loop again
        {
            i = 0;
        }
    }
    return keyword;
}
string Vignere_Cipher()
{
    string user_name;
    cout << "please enter your name: ";
    cin >> user_name;
    cout << "Ahlan Ya " << user_name << " Ya Habibi " << endl;
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

    if (n == 1)
    {
        cout << "Please enter the your message: ";
        cin.ignore();
        getline(cin, message);
        cout << "Please enter keyword you want to use: ";
        cin >> keyword;

        x = message.length();
        y = keyword.length();

        while (x > 80) // if message length is greater than 80
        {
            cout << "long message please enter a shorter message" << endl;
            ;
            cin >> message;
            x = message.length();
        }
        if (x <= 80) // if message length is smaller than 80
        {
            // cout << "message less than 80" << endl;;
            while (y > 8) // while keyword length is greater than 8
            {
                cout << "long keyword please enter a shorter keyword" << endl;
                cin >> keyword;
                y = keyword.length();
            }
            if (y <= 8) // if keyword length lessthan or equal 8
            {
                // cout<<"keyword less than 8" << endl;
                preparingkeyword();
            }
        }
        string encryption = "";
        for (int v = 0; v < message.length(); v++) // for loop on each character in the message
        {
            if (isdigit(message[v])) // if character is digit number
            {
                encryption += message[v];
            }
            else if (int(message[v]) == int(' ')) // if character is space
            {
                encryption += message[v];
            }
            else
            {
                message[v] = toupper(message[v]); // change each character in the message to upper letter
                keyword[v] = toupper(keyword[v]); // change each character in the keyword to upper letter

                int z = (int(message[v]) + int(keyword[v])) % 26;
                z += int('A');

                encryption += char(z);
            }
        }
        cout << "encrypted message = " << encryption << endl;
        return encryption;
    }
    if (n == 2)
    {
        cout << "Please enter the your message: ";
        cin.ignore();
        getline(cin, message);
        cout << "Please enter keyword you want to use: ";
        cin >> keyword;

        x = message.length();
        y = keyword.length();

        while (x > 80) // if message length is greater than 80
        {
            cout << "long message please enter a shorter message" << endl;
            ;
            cin >> message;
            x = message.length();
        }
        if (x <= 80) // if message length is smaller than 80
        {
            // cout << "message less than 80" << endl;;
            while (y > 8) // while keyword length is greater than 8
            {
                cout << "long keyword please enter a shorter keyword" << endl;
                cin >> keyword;
                y = keyword.length();
            }
            if (y <= 8) // if keyword length lessthan or equal 8
            {
                // cout<<"keyword less than 8" << endl;
                preparingkeyword();
            }
        }
        string decryption = "";
        for (int v = 0; v < message.length(); v++) // for loop on each character in the message
        {
            if (isdigit(message[v])) // if character is digit number
            {
                decryption += message[v];
            }
            else if (int(message[v]) == int(' ')) // if character is space
            {
                decryption += message[v];
            }
            else
            {

                message[v] = toupper(message[v]); // change each character in the message to upper letter
                keyword[v] = toupper(keyword[v]); // change each character in the keyword to upper letter
                int z = (int(message[v]) - int(keyword[v]) + 26) % 26;
                z += int('A');

                decryption += char(z);
            }
        }
        cout << "decrypted message = " << decryption << endl;
        return decryption;
    }

    if (n == 3)
    {
        cout << "END" << endl;
    }
}

string Baconian_Cipher()
{
    string the_message, decipher, code;
    istringstream enter(" ");
    map<char, string> opposite{
        {'A', "aaaaa"}, {'B', "aaaab"}, {'C', "aaaba"}, {'D', "aaabb"}, {'E', "aabaa"}, {'F', "aabab"}, {'G', "aabba"}, {'H', "aabbb"}, {'I', "abaaa"}, {'J', "abaab"}, {'K', "ababa"}, {'L', "ababb"}, {'M', "abbaa"}, {'N', "abbab"}, {'O', "abbba"}, {'P', "abbbb"}, {'Q', "baaaa"}, {'R', "baaab"}, {'S', "baaba"}, {'T', "baabb"}, {'U', "babaa"}, {'V', "babab"}, {'W', "babba"}, {'X', "babbb"}, {'Y', "bbaaa"}, {'Z', "bbaab "}};

    string user_name;
    cout << "please enter your name:";
    cin >> user_name;
    cout << "Ahlan Ya " << user_name << " Ya Habibi " << endl;
    cout << "please enter the number that you want to do. \n"
         << "1-cipher a message. \n"
         << "2-decipher a message. \n"
         << "3-End. \n";
    int what_user_want;
    cin >> what_user_want;
    // check if the integer that user entered is valid or not
    while (what_user_want < 1 || what_user_want > 3)
    {
        cout << "please enter the number that you want to do. \n"
             << "1-cipher a message. \n"
             << "2-decipher a message. \n"
             << "3-End. \n";
        cin >> what_user_want;
    }

    if (what_user_want == 1)
    {
        cout << "please enter the message you want to cipher:";
        cin.ignore();
        getline(cin, the_message);
        for (int x = 0; x < the_message.length(); x++)
        {
            if (isupper(the_message[x]))
            {
                cout << opposite[the_message[x]] << " ";
            }

            if (islower(the_message[x]))
            {
                the_message[x] = char(int(the_message[x])) - 32;
                cout << opposite[the_message[x]] << " ";
            }
            else
            {
                cout << char(the_message[x]);
            }
        }
    }

    if (what_user_want == 2)
    {
        cout << "please enter the message you want to decipher:";
        cin.ignore();
        getline(cin, code);
        enter.str(code);
        enter >> decipher;
        while (enter)
        {
            for (char letter = 65; letter < 91; letter++)
            {
                if (opposite[letter] == decipher)
                {
                    cout << letter << " ";
                }
            }
            enter >> decipher;
        }
    }

    if (what_user_want == 3)
    {
        cout << "End" << endl;
    }
}

string Simple_Substitution_Cipher()
{
    string user_name;
    cout << "please enter your name: ";
    cin >> user_name;
    cout << "Ahlan Ya " << user_name << " Ya Habibi " << endl;
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
    if (n == 1)
    {
        string alphabets, keyword, message;
        alphabets = "abcdefghijklmnopqrstuvwxyz";

        cout << "Please enter keyword you want to use: ";
        cin >> keyword;
        for (int v = 0; v <= keyword.length(); v++)
        {
            keyword[v] = tolower(keyword[v]); // change each character in the keyword to lower letter
        }

        while (keyword.length() > 5) // while keyword length is greater than 5
        {
            cout << "long keyword please enter shorter keyword";
            cin >> keyword;
        }

        bool boolean = true;
        while (boolean)
        {
            for (int i = 0; i < keyword.length(); i++) // for loop on each character in the keyword
            {
                char charac = keyword[i];
                int temp1 = keyword.find(charac);            // temp1 find the index of charac
                int temp2 = keyword.find(charac, temp1 + 1); // temp2 find index of same charac after temp1

                if ((temp1 != -1) && (temp2 != -1)) // if charac is in in more than one index
                {
                    cout << "not unique keyword, please enter keyword again: " << endl;
                    cout << "wrong keyword, please enter keyword again" << endl;
                    cin >> keyword;
                }
                else
                {
                    boolean = false;
                }
            }
        }

        for (int i = 0; i < keyword.length(); i++) // for loop on each character in the keyword
        {
            keyword[i] = tolower(keyword[i]); // change each character to lower letter
        }

        keyword += alphabets; // keyword=keyword+alphabets

        for (int i = 0; i < 5; i++) // for loop for first 5 characters in keyword
        {
            for (int j = 5; j < 31; j++) // forloop for characters in keyword from element 5 to 30
            {
                if (keyword[i] == keyword[j]) // if character in first 5 characters = to character from element 5 to 30
                {
                    keyword.erase(j, 1); // remove character from keyword
                    j--;
                }
            }
        }
        cout << "cipher alphabet is: " << keyword << endl;
        cout << endl;
        cout << "enter message to encrypt: ";
        cin.ignore();
        getline(cin, message);

        string encryption = "";

        for (int k = 0; k < message.length(); k++) // for loop on each character in the message
        {
            if (int(message[k]) == int(' ')) // if character is space
            {
                encryption += " ";
            }
            else
            {
                message[k] = tolower(message[k]);   // change each character in the message to lower letter
                int x = alphabets.find(message[k]); // x find the index of k in message in the alphabets
                encryption += keyword[x];
            }
        }
        cout << "encryption is: " << encryption << endl;
    }
    if (n == 2)
    {
        string alphabets, keyword, message;
        alphabets = "abcdefghijklmnopqrstuvwxyz";

        cout << "Please enter keyword you want to use: ";
        cin >> keyword;
        for (int v = 0; v <= keyword.length(); v++)
        {
            keyword[v] = tolower(keyword[v]); // change each character in the keyword to lower letter
        }

        while (keyword.length() > 5) // while keyword length is greater than 5
        {
            cout << "long keyword please enter shorter keyword";
            cin >> keyword;
        }

        bool boolean = true;
        while (boolean)
        {
            for (int i = 0; i < keyword.length(); i++) // for loop on each character in the keyword
            {
                char charac = keyword[i];
                int temp1 = keyword.find(charac);            // temp1 find the index of charac
                int temp2 = keyword.find(charac, temp1 + 1); // temp2 find index of same charac after temp1

                if ((temp1 != -1) && (temp2 != -1)) // if charac is in in more than one index
                {
                    cout << "not unique keyword, please enter keyword again: " << endl;
                    cout << "wrong keyword, please enter keyword again" << endl;
                    cin >> keyword;
                }
                else
                {
                    boolean = false;
                }
            }
        }

        for (int i = 0; i < keyword.length(); i++) // for loop on each character in the keyword
        {
            keyword[i] = tolower(keyword[i]); // change each character to lower letter
        }

        keyword += alphabets; // keyword=keyword+alphabets

        for (int i = 0; i < 5; i++) // for loop for first 5 characters in keyword
        {
            for (int j = 5; j < 31; j++) // forloop for characters in keyword from element 5 to 30
            {
                if (keyword[i] == keyword[j]) // if character in first 5 characters = to character from element 5 to 30
                {
                    keyword.erase(j, 1); // remove character from keyword
                    j--;
                }
            }
        }
        cout << "cipher alphabet is: " << keyword << endl;
        cout << endl;
        cout << "enter message to decrypt: ";
        cin.ignore();
        getline(cin, message);

        string decryption = "";

        for (int k = 0; k < message.length(); k++) // for loop on each character in the message
        {
            if (int(message[k]) == int(' ')) // if character is space
            {
                decryption += " ";
            }
            else
            {
                message[k] = tolower(message[k]); // change each character in the message to lower letter
                int x = keyword.find(message[k]); // x find the index of k in message in the keyword
                decryption += alphabets[x];
            }
        }
        cout << "decryption is: " << decryption << endl;
    }
    if (n == 3)
    {
        cout << "END" << endl;
    }
}

string Polybius_Square_Cipher()
{
    string user_name;
    cout << "please enter your name: ";
    cin >> user_name;
    cout << "Ahlan Ya " << user_name << " Ya Habibi " << endl;
    cout << "please enter the number that you want to do. \n"
         << "1-cipher a message. \n"
         << "2-decipher a message. \n"
         << "3-End. \n";
    int what_user_want;
    cin >> what_user_want;
    // check if the integer that user entered is valid or not
    while (what_user_want < 1 || what_user_want > 3)
    {
        cout << "please enter the number that you want to do. \n"
             << "1-cipher a message. \n"
             << "2-decipher a message. \n"
             << "3-End. \n";
        cin >> what_user_want;
    }
    if (what_user_want == 1)
    {
        char p[5][5] = {
            {'A', 'B', 'C', 'D', 'E'},
            {'F', 'G', 'H', 'I', 'J'},
            {'K', 'L', 'M', 'N', 'O'},
            {'P', 'Q', 'R', 'S', 'T'},
            {'U', 'V', 'W', 'X', 'Y'}}; // 2D array
        string text, key;

        cout << "Enter message to encrypt: ";
        cin.ignore();
        getline(cin, text);
        cout << "Enter key as 5 numbers: ";
        cin >> key;

        string encryption = "";

        for (int i = 0; i < text.length(); i++)
        {
            text[i] = toupper(text[i]); // convert lower letters to upper
            if (int(text[i]) == int(' '))
            {
                continue;
            }
            else
            {
                for (int j = 0; j < 5; j++)
                {
                    for (int k = 0; k < 5; k++)
                    {
                        if (text[i] == p[j][k]) // this to find same letter in the 2D array and get the index
                        {
                            encryption += key[j]; // key[j] : to get the number of the key in the same row of the letter in the 2D array
                            encryption += key[k]; // key[k] : to get the number of the key in the same column of the letter in the 2D array
                        }
                    }
                }
            }
        }
        cout << "encryption is: " << encryption << endl;
    }
    if (what_user_want == 2)
    {
        char p[5][5] = {
            {'A', 'B', 'C', 'D', 'E'},
            {'F', 'G', 'H', 'I', 'J'},
            {'K', 'L', 'M', 'N', 'O'},
            {'P', 'Q', 'R', 'S', 'T'},
            {'U', 'V', 'W', 'X', 'Y'}}; // 2D array

        string text, key;
        cout << "Enter message to decrypt: ";
        cin.ignore();
        getline(cin, text);
        cout << "Enter key as 5 numbers: ";
        cin >> key;

        string decryption = "";

        for (int i = 0; i < (text.length()); i += 2)
        {
            string x = text.substr(i, 1);     // extract character from the string
            string y = text.substr(i + 1, 1); // extract the next character from the string

            int temp1 = key.find(x); // to get row index
            int temp2 = key.find(y); // to get column index

            decryption += p[temp1][temp2]; // p[temp1][temp2] : to get the letter from the 2D array
        }
        cout << "decryption is: " << decryption << endl;
    }
    if (what_user_want == 3)
    {
        cout << "End" << endl;
    }
}

string Morse_Cipher()
{
    string the_message, code, decryption;
    istringstream enter(" ");
    map<char, string> opposite{
        {'A', "._"}, {'B', "_..."}, {'C', "_._."}, {'D', "-.."}, {'E', "."}, {'F', ".._."}, {'G', "__."}, {'H', "...."}, {'I', ".."}, {'J', ".___"}, {'K', "_._"}, {'L', "._.."}, {'M', "__"}, {'N', "_."}, {'O', "___"}, {'P', ".__."}, {'Q', "__._"}, {'R', "._."}, {'S', "..."}, {'T', "_"}, {'U', ".._"}, {'V', "..._"}, {'W', ".__"}, {'X', "_.._"}, {'Y', "_.__"}, {'Z', "__.."}

    };

    string user_name;
    cout << "please enter your name:";
    cin >> user_name;
    cout << "Ahlan Ya " << user_name << " Ya Habibi " << endl;
    cout << "please enter the number that you want to do. \n"
         << "1-cipher a message. \n"
         << "2-decipher a message. \n"
         << "3-End. \n";
    int what_user_want;
    cin >> what_user_want;
    // check if the integer that user entered is valid or not
    while (what_user_want < 1 || what_user_want > 3)
    {
        cout << "please enter the number that you want to do. \n"
             << "1-cipher a message. \n"
             << "2-decipher a message. \n"
             << "3-End. \n";
        cin >> what_user_want;
    }

    if (what_user_want == 1)
    {
        cout << "please enter the message you want to cipher:";
        cin.ignore();
        getline(cin, the_message);
        for (char letter : the_message)
        {
            if (isupper(letter))
            {
                cout << opposite[letter] << " ";
            }

            if (islower(letter))
            {
                letter = char(int(letter)) - 32;
                cout << opposite[letter] << " ";
            }
            if (char(letter) == 32)
            {
                cout << "  ";
            }
        }
    }

    if (what_user_want == 2)
    {
        cout << "please enter the message you want to decipher:";
        cin.ignore();
        getline(cin, code);
        enter.str(code);
        enter >> decryption;
        while (enter)
        {
            for (char letter = 65; letter < 91; letter++)
            {
                if (opposite[letter] == decryption)
                {
                    cout << letter;
                }
            }
            enter >> decryption;
        }
    }

    if (what_user_want == 3)
    {
        cout << "End" << endl;
    }
}

string Xor_Cipher()
{
    string user_name;
    cout << "please enter your name: ";
    cin >> user_name;
    cout << "Ahlan Ya " << user_name << " Ya Habibi " << endl;
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
    if (n == 1)
    {
        string sec_key;
        cout << "enter the secret key: ";
        cin >> sec_key;

        string msg;
        cout << "enter the message to encrypt it: ";
        cin >> msg;

        int num_in_dec;
        int z = 0;
        string encrypt_as_dec = "";
        string encrypt_as_text = "";
        string encrypt_as_hex = "";

        for (int i = 0; i < msg.length(); i++)
        {
            num_in_dec = int(msg[i]) ^ int(sec_key[z]); // each letter of the message goes through XOR operation with the secret letter
            encrypt_as_dec += to_string(num_in_dec);    // change integers to string to print the encrypted message as decimal
            encrypt_as_text += char(num_in_dec);        // change integers to character to print the encrypted message as text

            ostringstream num_in_hex;
            num_in_hex << setfill('0') << setw(2) << hex << num_in_dec; // convert decimal to hexadecimal
            encrypt_as_hex += num_in_hex.str();                         // change integers to string to print the encrypted message as hexadecimal
        }
        cout << "encryption as decimal: " << encrypt_as_dec << endl;
        cout << "encryption as text: " << encrypt_as_text << endl;
        cout << "encryption as hex: " << encrypt_as_hex << endl;
    }
    if (n == 2)
    {
        string sec_key2;
        cout << "enter the secret key: ";
        cin >> sec_key2;

        string msg2;
        cout << "enter hex to decipher to text: ";
        cin >> msg2;

        int conv_to_dec, num_in_dec_after_xor;
        int w = 0;
        string decrypt = "";

        for (int q = 0; q < msg2.length(); q += 2)
        {
            string part = msg2.substr(q, 2);                     // extract 2 characters from the string each time
            int ch = stoul(part, nullptr, 16);                   // convert hexadecimal to decimal
            num_in_dec_after_xor = (int(ch) ^ int(sec_key2[w])); // each character of the message goes through XOR operation with the secret letter
            decrypt += char(num_in_dec_after_xor);               // convert from decimal to character then assign to decrypt each time
        }
        cout << "decryption as text: " << decrypt << endl;
    }
}

string Rail_Fence_Cipher()
{
    string user_name;
    cout << "please enter your name: ";
    cin >> user_name;
    cout << "Ahlan Ya " << user_name << " Ya Habibi " << endl;
    cout << "please enter the number that you want to do. \n"
         << "1-cipher a message. \n"
         << "2-decipher a message. \n"
         << "3-End. \n";
    int what_user_want;
    cin >> what_user_want;
    // check if the integer that user entered is valid or not
    while (what_user_want < 1 || what_user_want > 3)
    {
        cout << "please enter the number that you want to do. \n"
             << "1-cipher a message. \n"
             << "2-decipher a message. \n"
             << "3-End. \n";
        cin >> what_user_want;
    }
    if (what_user_want == 1)
    {
        string text;
        cout << "enter text to encrypt:";
        cin.ignore();
        getline(cin, text);

        int key;
        cout << "enter key u want to use: ";
        cin >> key;

        string encryption = "";

        char rail[key][(text.length())];

        for (int i = 0; i < key; i++)
        {
            for (int j = 0; j < text.length(); j++)
            {
                rail[i][j] = '.';
            }
        }

        int row = 0, col = 0;
        for (int i = 0; i < text.length();)
        {
            if (row <= (key - 1))
            {
                rail[row][col] = text[i];
                row++, col++, i++;
            }
            else
            {
                for (int temp = row - 2; temp >= 0;)
                {
                    rail[temp][col] = text[i];
                    col++, i++, temp--;
                }
                row -= 2;
            }
        }
        for (int i = 0; i < key; i++)
        {
            for (int j = 0; j < text.length(); j++)
            {
                if (rail[i][j] != '.')
                {
                    encryption += rail[i][j];
                }
            }
        }
        cout << "encryption is: " << encryption << endl;
    }
    if (what_user_want == 2)
    {
        string text;
        cout << "enter text to decrypt:";
        cin.ignore();
        getline(cin, text);

        int key;
        cout << "enter key u want to use: ";
        cin >> key;

        string decryption = "";
        char rail[key][(text.length())];

        for (int i = 0; i < key; i++)
        {
            for (int j = 0; j < text.length(); j++)
            {
                rail[i][j] = '.';
            }
        }
        int row = 0, col = 0;
        bool temp;
        for (int i = 0; i < text.length(); i++)
        {
            if (row == 0)
            {
                temp = true;
            }
            if (row == (key - 1))
            {
                temp = false;
            }
            rail[row][col++] = '*';
            if (temp == true)
            {
                row++;
            }
            else
            {
                row--;
            }
        }
        int index = 0;
        for (int i = 0; i < key; i++)
        {
            for (int j = 0; j < text.length(); j++)
            {
                if (rail[i][j] == '*' && index < text.length())
                {
                    rail[i][j] = text[index++];
                }
            }
        }
        for (int i = 0; i < text.length(); i++)
        {
            for (int j = 0; j < key; j++)
            {
                if (rail[j][i] != '.')
                {
                    decryption += rail[j][i];
                }
            }
        }
        cout << "decryption is: " << decryption << endl;
    }
    if (what_user_want == 3)
    {
        cout << "End" << endl;
    }
}

int main()
{
    cout << "Ahlan Ya User Ya Habibi" << endl;
    cout << "What do you like to do today?" << endl;
    cout << "0-Affine Cipher" << endl;
    cout << "1-Caser Cipher" << endl;
    cout << "2-Atbash Cipher" << endl;
    cout << "3-Vignere Cipher" << endl;
    cout << "4-Baconian Cipher" << endl;
    cout << "5-Simple Substiution Cipher" << endl;
    cout << "6-Polybius Square Cipher" << endl;
    cout << "7-Morse Cipher" << endl;
    cout << "8-Xor Cipher" << endl;
    cout << "9-Rail-Fence Cipher" << endl;
    cout << "10-End" << endl;
    int x;
    cout << "Please enter what you want to do today: ";
    cin >> x;
    if (x == 0)
    {
        Affine_Cipher();
    }
    if (x == 1)
    {
        Caser_Cipher();
    }
    if (x == 2)
    {
        Atbash_Cipher();
    }
    if (x == 3)
    {
        Vignere_Cipher();
    }
    if (x == 4)
    {
        Baconian_Cipher();
    }
    if (x == 5)
    {
        Simple_Substitution_Cipher();
    }
    if (x == 6)
    {
        Polybius_Square_Cipher();
    }
    if (x == 7)
    {
        Morse_Cipher();
    }
    if (x == 8)
    {
        Xor_Cipher();
    }
    if (x == 9)
    {
        Rail_Fence_Cipher();
    }
    if (x == 10)
    {
        cout << "End" << endl;
    }
    while (x < 0 || x > 10)
    {
        cout << "Please enter number from 0 to 10" << endl;
        cout << "0-Affine Cipher" << endl;
        cout << "1-Caser Cipher" << endl;
        cout << "2-Atbash Cipher" << endl;
        cout << "3-Vignere Cipher" << endl;
        cout << "4-Baconian Cipher" << endl;
        cout << "5-Simple Substiution Cipher" << endl;
        cout << "6-Polybius Square Cipher" << endl;
        cout << "7-Morse Cipher" << endl;
        cout << "8-Xor Cipher" << endl;
        cout << "9-Rail-Fence Cipher" << endl;
        cout << "10-End" << endl;
        cin >> x;
    }
}