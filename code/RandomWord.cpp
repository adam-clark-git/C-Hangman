#include <string>
#include <iostream>
#include <fstream> 
class RandomWord {
    public:
        std::string randomize() {
            std::string newWord;
            std::fstream myFile("datasets/dataset_words.txt");

            if (!myFile.is_open())
            {
                std::cerr << "Unable to open file!" << std::endl;
            }
        }
};