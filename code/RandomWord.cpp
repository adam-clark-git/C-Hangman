#include "RandomWord.h"
#include <string>
#include <iostream>
#include <fstream> 
#include <random>
std::string RandomWord::randomize() {
    std::string newWord;
    int wordCount = 0;
    std::random_device rd;
    std::mt19937 gen(rd());
    
    std::fstream myFile("datasets/dataset_words.txt");
    if (!myFile.is_open())
    {
        std::cerr << "Unable to open file!" << std::endl;
        return "";
    }

    std::string temp;
    while (myFile >> temp)
    {
        wordCount++;
    }
    myFile.clear();  // Clear EOF flag
    myFile.seekg(0, std::ios::beg);

    std::uniform_int_distribution<> dis(0, wordCount-1);
    int randomNum = dis(gen);

    int newCount = 0;
    while (myFile >> newWord)
    {
        if (newCount == randomNum)
        {
            break;
        }
        newCount++;
    }
    myFile.close();
    return newWord;
}