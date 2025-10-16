#include "RandomWord.h"
#include <string>
#include <iostream>
using namespace std;
class Word {
    std::string realWord;
    std::string anonmyousWord;
    public:
        void randomize_word() {
            RandomWord random;
            realWord = random.randomize();
        }
        void annomyize_word() {

        }
        void check_word() {

        }
        void reveal_word() {

        }
        
};
int main() {
    Word newWord;
    newWord.randomize_word();
    cout << "Hello World!";
    return 0;
}