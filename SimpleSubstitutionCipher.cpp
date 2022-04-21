#include <iostream>
#include <string>
using namespace std;

string alphabets, keyword, message;

void cipher_alphabet()//preparing cipher alphabet to use it in cipher or decipher message
{
	alphabets = "abcdefghijklmnopqrstuvwxyz";

	cout << "Please enter keyword you want to use: ";
	cin >> keyword;

	while (keyword.length() > 5)//while keyword length is greater than 5
	{
		cout << "long keyword please enter shorter keyword";
		cin >> keyword;
	}

	bool boolean = true;
	while (boolean)
	{
		for (int i = 0; i < keyword.length(); i++)//for loop on each character in the keyword
		{
			char charac = keyword[i];
			int temp1 = keyword.find(charac);//temp1 find the index of charac
			int temp2 = keyword.find(charac, temp1 + 1);//temp2 find index of same charac after temp1

			if ((temp1 != -1) && (temp2 != -1))//if charac is in in more than one index
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

	for (int i = 0; i < keyword.length(); i++)//for loop on each character in the keyword
	{
		keyword[i] = tolower(keyword[i]);//change each character to lower letter
	}

	keyword += alphabets;//keyword=keyword+alphabets

	for (int i = 0; i < 5; i++)//for loop for first 5 characters in keyword
	{
		for (int j = 5; j < 31; j++)//forloop for characters in keyword from element 5 to 30
		{
			if (keyword[i] == keyword[j])//if character in first 5 characters = to character from element 5 to 30
			{
				keyword.erase(j, 1);//remove character from keyword
				j--;
			}
		}
	}
	cout << "cipher alphabet is: " << keyword << endl;
}

void encrypt()
{
	cipher_alphabet();

	cout << "enter message to encrypt: ";
	cin.ignore();
	getline(cin, message);

	string encryption = "";

	for (int k = 0; k < message.length(); k++)//for loop on each character in the message
	{
		if (int(message[k]) == int(' '))//if character is space
		{
			encryption += " ";
		}
		else
		{
			message[k] = tolower(message[k]);//change each character in the message to lower letter
			int x = alphabets.find(message[k]);//x find the index of k in message in the alphabets
			encryption += keyword[x];
		}
	}
	cout << "encryption is: " << encryption << endl;
}

void decrypt()
{
	cipher_alphabet();

	cout << "enter message to decrypt: ";
	cin.ignore();
	getline(cin, message);

	string decryption = "";

	for (int k = 0; k < message.length(); k++)//for loop on each character in the message
	{
		if (int(message[k]) == int(' '))//if character is space
		{
			decryption += " ";
		}
		else
		{
			int x = keyword.find(message[k]);//x find the index of k in message in the keyword
			decryption += alphabets[x];
		}
	}
	cout << "decryption is: " << decryption << endl;
}

int main()
{
	int num;
	cout << "Ahlan Ya User Ya Habibi" << endl;
	cout << "What do you like to do today?" << endl;
	cout << "1- Cipher" << endl;
	cout << "2- Decipher" << endl;
	cout << "3- End" << endl;
	cin >> num;
	while ((num < 1) || (num > 3))
	{
		cout << "wrong choice, please choose again: ";
		cin >> num;
	}

	if (num == 1)
	{
		encrypt();
	}
	else if (num == 2)
	{
		decrypt();
	}
	else if (num == 3)
	{
		cout << "End" << endl;
	}
}