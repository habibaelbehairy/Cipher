//Caesar Cipher
//this cipher is working by shifting alphabets
//first user choose if he want to encrypt message or
//decrypt it then the user enter the text he want 
//then he enters number of shifts he want 
//Author:Habiba Alaa Mohamed Ali El-Behairy
//Date:22-3-2022
//version:1.0
#include<iostream>
using namespace std;

void encrypt()//encrypt function
{
    string text;
    cout << "Please enter your text: ";
    cin >> text; // user enter the text he want to encrypt
    string encryption = "";
    int numofshifts;
    cout << "Please enter number of shifts you want: ";
    cin >> numofshifts;
    if (numofshifts > 26) //numbers of alphabet is 26 so if user enters number more than 26 we get its %
    {
        numofshifts = numofshifts % 26;
    }
    if (numofshifts < 0) //if user enters a negative number so number of shifts will be the negativenumber+26
    {
        numofshifts = 26 + numofshifts;
    }
    int x; 
    x = numofshifts; // we let x as a temp for the number of shift
    for (int c = 0; c < text.length(); c++) //for loop to pass on each chr of the text
    {
        numofshifts = x;
        if (c == ' ') //if chr is ' '  pass
        {
            ;
        }
        if (c == ',')// if chr is , pass
        {
            ;
        }
        if (isdigit(text[c]))// if chr is decimal number the chr will be the decimal number + numofshifts
        {
            encryption += char(int(text[c]) + numofshifts);

        }
        if (isupper(text[c]))//if chr is upper letter
        {//check if int of this chr + numof shifts less than or equal 90
            if (int(text[c]) + numofshifts <= 90) { //90 as Z in ascii is equal to 90
                encryption += char(int(text[c]) + numofshifts);//encrypt=encrypt+chr(int of chr in ascii + numof shifts)
            }
            else {//check if int of this chr + numof shifts greater than 90
                numofshifts = (numofshifts + int(text[c])) % 90;//we get the in number of chr in asci + number of shifts snd get its modulus 90
                encryption += char(65 - 1 + numofshifts);//65 number of A in Ascii
                //encrypt=encrypt+chr(number of A in ascii-1+numofshifts)
            }
        }
        if (islower(text[c]))//if chr is lower letter
        {//check if int of this chr + numof shifts less than or equal 122
            if (int(text[c]) + numofshifts <= 122) {//122 as z in ascii is equal to 122
                encryption += char(int(text[c]) + numofshifts);//encrypt=encrypt+chr(int of chr in ascii + numof shifts)
            }
            else {//check if int of this chr + numof shifts greater than 122
                numofshifts = (numofshifts + int(text[c])) % 122;//we get the in number of chr in asci + number of shifts snd get its modulus 122
                encryption += char(97 - 1 + numofshifts);//97 number of a in ascii
                //encrypt=encrypt+chr(number of a in ascii-1+numofshifts)
            }
            }
        }

    
    cout << "Encryption message is:";
    cout << encryption;
}

void decrypt() {
    string text;
    cout << "Please enter your text: ";
    cin >> text;// user enter the text he want to decrypt
    string decryption;
    decryption = "";
    int numofshifts;
    cout << "Please enter number of shifts you want: ";
    cin >> numofshifts;

    if (numofshifts > 26)//numbers of alphabet is 26 so if user enters number more than 26 we get its %
    {
        numofshifts = numofshifts % 26;
    }
    if (numofshifts < 0)//if user enters a negative number so number of shifts will be the negativenumber+26
    {
        numofshifts = 26 + numofshifts;
    }
    int x;// we let x as a temp for the number of shift
    x = numofshifts;
    for (int c = 0; c < text.length(); c++)//for loop to pass on each chr of the text
    {
        numofshifts = x;
        if (c == ' ')//if chr is ' '  pass
        {
            ;
        }
        if (c == ',')//if chr is , pass
        {
            ;
        }
        if (isdigit(text[c]))
        {
            decryption += char(int(text[c]) - numofshifts);
        }
        if (isupper(text[c]))//if chr is upper letter
        {//check if int of this chr - numof shifts greater than or equal 65
            if (int(text[c]) - numofshifts >= 65) { //65 as A in ascii is equal to 65
                decryption += char(int(text[c]) - numofshifts);
                //decrypt=decrypt+chr(int of chr in ascii -  numof shifts)
            }
            else {//check if int of this chr - numof shifts is less than 65
                numofshifts = 65 % (int(text[c] - numofshifts)); //numbofshifts=65%(number//numofsho of chr in ascii-numofshifts)
                decryption += char(90 + 1 - numofshifts);//decrypt=decrypt+chr(number of Z in ascii+1 -numofshifts)
            }
        }
        if (islower(text[c]))//if chr is lower letter
        {//check if int of this chr - numof shifts greater than or equal 97
            if (int(text[c]) + numofshifts >= 97) {//97 as a in ascii is equal to 97
                decryption += char(int(text[c]) - numofshifts);
                //decrypt=decrypt+chr(int of chr in ascii -  numof shifts)
                }
            else
            {//check if int of this chr - numof shifts is less than 97
                numofshifts = 122 % (int(text[c] - numofshifts));//numbofshifts=122%(number//numofshiftd of chr in ascii-numofshifts)
                decryption += char((122) + 1 - numofshifts);//decrypt=decrypt+chr(number of Z in ascii+1 -numofshifts)
            }
        }

    }
    cout << "decryption message is:";
    cout << decryption;
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
    while (n < 1 || n > 3) {
        cout << "Please enter number from 1 to 3"<<endl;
        cout << "1-Cipher message" << endl;
        cout << "2-Decipher message" << endl;
        cout << "3-End" << endl;
        cin>>n;
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
    