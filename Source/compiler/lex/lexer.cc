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

using namespace Skython;

Compiler::lexer::lexer(const std::string& source) : m_Source(source), m_Cursor(-1) { }
Compiler::lexer::~lexer() { }

void Compiler::lexer::advance_source() noexcept(false) {
    this->m_Cursor++;
    this->m_Char = this->m_Source[this->m_Cursor];
}

void Compiler::lexer::skip_whitespace() noexcept {
    if (std::isspace(this->m_Char)) { /* IGNORE */ }
}

std::vector<std::unordered_map<char, Compiler::token_t>> Compiler::lexer::generate_tokens() noexcept(false) {
    do {
        this->skip_whitespace();        

        if (std::isdigit(this->m_Char)) {
            std::unordered_map<char, Compiler::token_t> tokenMap;
            tokenMap[this->m_Char] = TOKEN_NUMERICAL;
            this->m_Tokens.push_back(tokenMap);
        }
        
        if (this->m_Char == '+') {
            std::unordered_map<char, Compiler::token_t> tokenMap;
            tokenMap[this->m_Char] = TOKEN_ARITHMETIC;
            this->m_Tokens.push_back(tokenMap);
        }
        
        this->advance_source();
        
    } while (this->m_Source[this->m_Cursor] != '\0');
    
    return this->m_Tokens;
}
