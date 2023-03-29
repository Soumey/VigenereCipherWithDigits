// VigenereCipherWithDigits.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//



#include <fstream>
#include <iostream>
#include <string>
const char Alphabet[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9' };
const int Alphabet_Size = sizeof(Alphabet) / sizeof(Alphabet[0]);
const char Alphab[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
const int alphab_Size= sizeof(Alphab) / sizeof(Alphab[0]);
using namespace std;

int position(char character);

string Vigenere_cipher_encrypt(string text, string key);
string Vigenere_cipher_decrypt(string text, string key);


int main()
{
    int decision;
    
    string key, text;

    ifstream input_file("input.txt");
    if (!input_file) {
        cout << "Failed to open input file." << endl;
        return 1;
    }

    ofstream output_file("encrypted.txt");
    if (!output_file) {
        cout << "Failed to open encrypted file." << endl;
        return 1;
    }

    cout << "Welcome to Vigenere Cipher\nDo you want to encrypt(1), decrypt(2)" << endl;
    cin >> decision;
    if (decision == 1)
    {
        cout << "You choose encryption\nEnter the key of encription:";
        cin >> key;
        while (getline(input_file, text)) {

            string encrypted_line = Vigenere_cipher_encrypt(text, key);
            output_file << encrypted_line << endl;

        }
        text = "";
    }
    if (decision == 2)
    {
        cout << "You choose decryption\nEnter the key of decryption:";
        cin >> key;
        while (getline(input_file, text)) {

            string encrypted_line = Vigenere_cipher_decrypt(text, key);
            output_file << encrypted_line << endl;

        }
        text = "";
    }
    else
    {
        return 0;
    }



    input_file.close();
    output_file.close();

    return 0;

}

int position(char character)
{
    for (int i = 0; i < Alphabet_Size; i++)
    {
        if (Alphabet[i] == character || Alphab[i]==character)
        {
            return i;
        }
    }
}
string Vigenere_cipher_encrypt(string text, string key)
{
    string result = "";
    for (int i = 0; i < text.size(); i++)
    {
        int positionKey = position(key[i % key.size()]);
        int positionText = position(text[i]);
        result += Alphabet[(positionText + positionKey) % Alphabet_Size];
    }
    return result;
}
string Vigenere_cipher_decrypt(string text, string key)
{
    string result = "";
    for (int i = 0; i < text.size(); i++)
    {
        int positionKey = position(key[i % key.size()]);
        int positionText = position(text[i]);
        result += Alphabet[-(positionText + positionKey) % Alphabet_Size];
    }
    return result;
}

