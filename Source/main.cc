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
#include <iostream>

int main(void) {
    
    const std::string source = "1 + 1";
    Skython::Compiler::lexer lex(source);
    
    std::vector<std::unordered_map<char, Skython::Compiler::token_t>> tokens = lex.generate_tokens();


    for (const auto& tokenMap : tokens) {
        for (const auto& pair : tokenMap) {
            char character = pair.first;
            Skython::Compiler::token_t tokenType = pair.second;
            
            std::cout << "CHARACTER: " << character << " TOKEN TYPE: " << tokenType << std::endl;
        }
    }
}
