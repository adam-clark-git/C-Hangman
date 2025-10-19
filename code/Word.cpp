#include "RandomWord.h"
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Word {
    std::string realWord;
    std::list<int> anonmyousLetters;
    public:
        void randomize_word() {
            RandomWord random;
            realWord = random.randomize();
        }
        void reset_letters() {
            anonmyousLetters = {};
        }
        bool is_completed() {
            if (anonmyousLetters.size() == realWord.length())
            {
                return true;
            }
            else return false;
        }
        std::string get_word()
        {
            return realWord;
        }
        std::string show_anon_word() {
            std::string word = "";
            for (int i =0; i < realWord.length(); i++)
            {
                if (std::find(anonmyousLetters.begin(), anonmyousLetters.end(), i) != anonmyousLetters.end())
                {
                    word.append(realWord.substr(i,1));
                }
                else word.append("*");
            }
            return word;

        }
        bool check_letter(std::string letter) {
            std::string curWord = realWord;
            int removedLetters = 0;
            int x =0;
            while (x < 20)
            {
                int letterPos = curWord.find(letter);
                if (letterPos == std::string::npos)
                {
                    break;
                }
                anonmyousLetters.push_back(letterPos+removedLetters);
                removedLetters += letterPos+1;
                curWord = curWord.substr(letterPos+1, string::npos);
                x++;
            }
            return x> 0;
        }
        
};

class Hangman {
    Word word;
    std::vector<std::string> displays = {" |----|  \n |    | \n      | \n      | \n      | \n    --|--\n", " |----|  \n |    | \n 0    | \n      | \n      | \n    --|--\n", " |----|  \n |    | \n 0    | \n |    | \n      | \n    --|--\n", " |----|  \n |    | \n 0    | \n-|    | \n      | \n    --|--\n", " |----|  \n |    | \n 0    | \n-|-   | \n      | \n    --|--\n", " |----|  \n |    | \n 0    | \n-|-   | \n/     | \n    --|--\n", " |----|  \n |    | \n 0    | \n-|-   | \n/|    | \n    --|--\n"};


    public:
        void start_game()
        {
            system("cls");
            cout << "WELCOME TO HANGMAN!!!\n";
            cout << " |----|  \n |    | \n 0    | \n-|-   | \n/|    | \n    --|--\n";
            word.randomize_word();
            word.reset_letters();
            cout << word.show_anon_word();
            cout << word.get_word();
            std::string guessedLetter ="";
            int wrongAnswers = 0;
            while(wrongAnswers < 6)
            {
                cout << "\n Guess a letter?\n";
                std::cin >> guessedLetter;
                system("cls");
                if (word.check_letter(guessedLetter))
                {
                    if (word.is_completed())
                    {
                        cout << "\nYou won! The word was " + word.get_word();
                        break;
                    }
                    else
                    {
                        cout << "\n You got it right!\n";
                    }
                }
                else
                {
                    wrongAnswers++;
                    cout << "\n You're dead wrong!";
                }
                cout << "\n" +displays[wrongAnswers];
                cout << "\n" +word.show_anon_word();
                if (wrongAnswers > 5)
                {
                    cout << "\nSorry! YOU LOSE!!!!\n";
                    cout << word.get_word();
                }
            }
            cout << "\n Would you like to play again?\n";
            std::string input;
            std::cin >> input;
            if (input == "yes") {
                start_game();
            }
            
        }
};

int main() {
    Hangman game;
    std::string input = "";
    cout << "Would you like to play a game?\n";
    cout << "Type 'yes' to play, and only type in lowercase\n";
    std::cin >> input;
    if (input == "yes")
    {
        game.start_game();
    }
    return 0;
}