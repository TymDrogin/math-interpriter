#include "main.hpp"


int main() {
    std::string input = "((4 + 3) * (6 - (2 + 1))) / (5 - 2)";

    // Start the timer
    auto start = std::chrono::high_resolution_clock::now();
    // Your code
    Lexer myLexer(input);
    auto tokens = myLexer.tokenize();
    printTokens(tokens);

    Parser myParser(tokens);
    auto tree = myParser.toAST();
    double result = tree->evaluate();
    std::cout << result;

    // End the timer
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the elapsed time
    std::chrono::duration<double> duration = end - start;

    // Print the elapsed time in seconds
    std::cout << "\nElapsed time: " << duration.count() << " seconds\n";

    return 0;
}