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

#include <exception>
#include <iostream>

#include "compiler/lex/lexer.h"

using namespace Skython;

/// TODO: Add no reminder operator later

static std::unordered_map<char, Compiler::token_t> __arithmetic_logic = {
    {'+', Skython::Compiler::TOKEN_ADD_OP},
    {'-', Skython::Compiler::TOKEN_SUB_OP},
    {'*', Skython::Compiler::TOKEN_MUL_OP},
    {'/', Skython::Compiler::TOKEN_DIV_OP},
    {'%', Skython::Compiler::TOKEN_MOD_OP}
};

Compiler::lexer::lexer() { }
Compiler::lexer::lexer(const std::string& source) : m_Source(source), m_Cursor(-1) { }
Compiler::lexer::~lexer() { }

std::tuple<std::string, Compiler::token_t> Compiler::lexer::extract_fp_value(const char& source) noexcept(false) {
    Compiler::token_t tok = Compiler::token_t::TOKEN_UNKNOWN;

    std::string fp_v;
    bool ready = false;
    int dot_count = 0;

    while (this->m_Source[this->m_Cursor] != '\0') {
        this->skip_whitespace();
        if (std::isdigit(this->m_Char) || (this->m_Char == '.' && dot_count == 0)) {
            fp_v += this->m_Char;
            if (this->m_Char == '.') {
                dot_count++;
            }
            ready = true;
            tok = Compiler::token_t::TOKEN_FLOATING_POINT;
        } else {
            break;
        }

        if (!std::isdigit(this->m_Source[this->m_Cursor + 1]) && this->m_Source[this->m_Cursor + 1] != '.') {
            break;
        }

        this->advance_source();
    }

    return std::make_tuple(fp_v, tok);
}

std::tuple<bool, Compiler::token_t> Compiler::lexer::extract_arithmetic_op(const char& source) noexcept(false) {
    Compiler::token_t tok = Compiler::token_t::TOKEN_UNKNOWN;
    bool ready = false;

    try {
        tok = __arithmetic_logic.at(source);
        ready = true;
    } catch (const std::out_of_range& e) {
        ready = false;
    }

    return std::make_tuple(ready, tok);
}

void Compiler::lexer::generate_fp_tokens() noexcept(false) {
    const auto& fp = this->extract_fp_value(this->m_Char);
    std::string fp_value = std::get<0>(fp);
    if (!fp_value.empty() && fp_value.find(".") != std::string::npos) {
        std::unordered_map<std::string, Compiler::token_t> tokenMap;
        tokenMap[fp_value] = std::get<1>(fp);
        this->m_Tokens.push_back(tokenMap);
    }
}

void Compiler::lexer::generate_numerical_tokens() noexcept(false) {
    /* Extract Whole Numbers */
    if (std::isdigit(this->m_Char) && this->m_Source[this->m_Cursor + 1] != '.') {
        std::unordered_map<std::string, Compiler::token_t> token_map;
        token_map[std::string(1, this->m_Char)] = Compiler::token_t::TOKEN_NUMERICAL;
        this->m_Tokens.push_back(token_map);
    }

    /* Extract Operators */
    const auto& arithmetic_logic = this->extract_arithmetic_op(this->m_Char);
    if (std::get<0>(arithmetic_logic)) {
        std::unordered_map<std::string, Compiler::token_t> tokenMap;
        tokenMap[std::string(1, this->m_Char)] = std::get<1>(arithmetic_logic);
        this->m_Tokens.push_back(tokenMap);
    }

    this->extract_arithmetic_op(this->m_Char);
}

void Compiler::lexer::advance_source() noexcept(false) {
    this->m_Cursor ++;
    this->m_Char = this->m_Source[this->m_Cursor];
}

void Compiler::lexer::skip_whitespace() noexcept {
    if (std::isspace(this->m_Char)) { /* Ingore */ }
}

std::vector<std::unordered_map<std::string, Compiler::token_t>> Compiler::lexer::generate_tokens() noexcept(false) {
    this->advance_source();

    if (this->m_Source.empty()) {
        return this->m_Tokens;
    }

    do {
        this->skip_whitespace();

        this->generate_numerical_tokens();
        this->generate_fp_tokens();

        this->advance_source();
    } while (this->m_Char != '\0');

    return this->m_Tokens;
}

void Compiler::lexer::set_source(const std::string& source) noexcept {
    this->m_Source = source;
}
