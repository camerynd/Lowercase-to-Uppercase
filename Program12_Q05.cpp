#include<iostream>
#include<cctype>//allows toupper function
using namespace std;
//function prototype
void convert_to_uppercase(char *);
//global constant for max size of user input cstring
const int MAX_CHARACTERS = 100;
//main function
int main()
{
    char userInput[MAX_CHARACTERS];//cstring to store user input
    char * sentences;//char pointer
    //prompt user for input
    cout << "Please enter a few sentences and I will capitalize the first letter" << endl;
    cout << "of each sentence. Your limit is 100 characters." << endl << endl;
    //get user input and store in cstring so that each character can be individually processed
    cin.get(userInput, MAX_CHARACTERS);
    cout << endl;
    //sentences now points to the user's input
    sentences = userInput;
    //function call
    convert_to_uppercase(sentences);
    return 0;
}
//fuction to convert necessary characters to uppercase
void convert_to_uppercase(char *sen)
{
    //point to first character of user input and capitalize (because first letter of sentence 
    //should always be capitalized)
    sen[0] = toupper(sen[0]);
    //loop to convert rest of necessary characters to uppercase
    for(int i = 1; i < MAX_CHARACTERS; i++)
    {
        if(sen[i] == '.')//detect when theres a period(signaling the end of a sentence)
        {
            //skip the space following the period and capitalize the next character as it is 
            //the first letter of the next sentence
            sen[i + 2] = toupper(sen[i + 2]);
        }
    }
    cout << sen << endl << endl;//display sentence after capitalizing necessary characters
}
