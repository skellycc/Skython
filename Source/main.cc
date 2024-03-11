/**
 *  Skython - An alternative to the Python Programming Language.
 *  Copyright (C) 2024 Mustafa Malik
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <https://www.gnu.org/licenses/>.          
 */

#include "compiler/lex/lexer.h"
#include "compiler/gram/token_validator.h"

#include <iostream>

int main(void) {
    
    char x = ';';
    std::string y(1, x);
    std::cout << y << std::endl;

    const std::string source = "1 + 1\n1.0 + 1";

    std::cout << "\n";
    std::cout << "Skython 0.0.1 Shell" << std::endl;

    std::string in;
    std::cout << "Shell: >> ";
    std::getline(std::cin, in);

    Skython::Compiler::lexer lex(in);
    std::vector<std::unordered_map<std::string, Skython::Compiler::token_t>> tokens = lex.generate_tokens();

    for (const auto& tokenMap : tokens) {
        for (const auto& pair : tokenMap) {
            std::string character = pair.first;
            Skython::Compiler::token_t tokenType = pair.second;
            std::cout << "CHARACTER: " << character << " TOKEN TYPE: " << tokenType << std::endl;

            std::cout << "VERIFYING TOKENS\n";
            if (Skython::Compiler::token_validator::check_digit(pair.first, tokenMap)) {
                std::cout << character << " TOKEN IS VALID\n";
            } else {
                std::cout << character << " IS NOT A VALID DIGIT\n";
            }
        }
    }
}
