// Copyright (c) 2022 Katie G All rights reserved.
//
// Created by: Katie G
// Created on : November 9th, 2022
// This program generates a random number, then uses a
// do... while loop to get the user number, uses a try... catch statement
// to check if the user input is an integer, then an if... then
// statement to check if the user's input is within the range of 0-9.
// the program then uses an if... then statement to check if the user guess
// is equal to the generated number - if so, uses a break statement to break
// out of the loop.
#include <iostream>
#include <random>
#include <string>

// this function will generate a random number,
// then, while using a do...while loop,
// uses a try... catch statement and an
// if... then statement to check if the user
// guess is valid, then uses an if...
// then statement to check if the user guess
// is equal to the generated num - if so, uses a "break"
// statement to break out of the loop.
int main() {
    // initializing userGuessString and userGuessInt variables.
    std::string userGuessString;
    int userGuessInt, randomNum;

    // generating a random number from 0 - 9.
    std::random_device rseed;

    std::mt19937 rgen(rseed());

    std::uniform_int_distribution<int> idist(0, 9);

    // assigning the randomly generated num to the variable.
    randomNum = idist(rgen);

    // beginning the loop that contains the rest of the program
    // and allows the user to guess more than once if they are wrong.
    do {
        // getting the user input.
        std::cout << "I am thinking of a number from 0-9. ";
        std::cout << "You will guess what it is please. ";
        std::cin >> userGuessString;

        // try...catch checking to make sure
        // the user's input is a valid integer.
        try {
            userGuessInt = std::stoi(userGuessString);
            // i very politely borrowed this code from my good friend carolyn :)
            // because my code wasn't working right
            float userGuessFloat = stof(userGuessString);
            // To make sure the user guess is not a decimal
            if (userGuessFloat != static_cast<int>(userGuessFloat)
            || userGuessFloat < 0) {
                std::cout << "Please enter a valid integer from 0-9\n";
            } else {
                // if statement to check if the user guess is between 0 to 9.
                if (userGuessInt >= 0 && userGuessInt <= 9) {
                    // if statement to check if the user guess is
                    // equal to the random num.
                    if (userGuessInt == randomNum) {
                        std::cout << "You guessed correctly! Well done!\n";
                        break;
                    } else {
                        std::cout << "You have not guessed correctly. ";
                        std::cout << "Try again.\n";
                    }
                } else {
                    std::cout << "Please enter a whole, positive ";
                    std::cout << "number from 0-9.";
                }
            }
        } catch (std::invalid_argument) {
            std::cout << "Please enter a valid integer from 0-9." << std::endl;
        }
    } while (userGuessInt != randomNum);
}
