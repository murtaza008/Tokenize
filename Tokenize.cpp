#include <iostream>

using namespace std;

// Take string From User and Reverse it Word By Word

int main()
{
    
    char input[200]; // initialize array to store input
    char reversedWords[50][200]; // initialize 2D array to store reversed words

    cout << "Enter the statement: "; // prompting
    cin.getline(input, 200); // storing user input

    // initialize variables
    int wordCount = 1; // number of words in input
    int currentWordIndex = 0; // current word being processed in input
    int currentCharIndex = 0; // current character being processed in input word
    char tempWord[100]; // temporary array to store input word

    for (int i = 0; input[i] != '\0'; i++) // count the number of words in input
    {
        if (input[i] == ' ') {
            wordCount++;
        }
    }

    for (int i = 0; input[i] != '\0'; i++)  // iterate through each character in input 
    {
        tempWord[currentCharIndex] = input[i]; // add current character to temporary array
        currentCharIndex++; // move to next character in temporary array

        if (input[i] == ' ' || input[i + 1] == '\0') // if a space is encountered or end of input is reached
        {
            if (input[i + 1] == '\0')// if end of input is reached, add null character to temporary array
            {
                tempWord[currentCharIndex] = '\0';
            }
            else // if not at end of input, remove space and add null character to temporary array
            {
                tempWord[currentCharIndex - 1] = '\0';
            }

            // copy temporary array to reversed_words array
            int k = 0;
            while (tempWord[k] != '\0')
            {
                reversedWords[wordCount - currentWordIndex - 1][k] = tempWord[k];
                k++;
            }
            reversedWords[wordCount - currentWordIndex - 1][k] = '\0';
            currentWordIndex++;
            currentCharIndex = 0;

            if (input[i + 1] == '\0') // if end of input is reached, exit loop
            {
                break;
            }
        }
    }

    for (int i = 0; i < wordCount; i++) // print reversed words
    {
        cout << reversedWords[i] << " ";
    }

    return 0; // program ends
}
