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

#include "compiler/gram/token_validator.h"

using namespace Skython;

std::tuple<bool, std::string> Compiler::token_validator::check_digit(const std::string& key, const std::unordered_map<std::string, Compiler::token_t>& digit_token) noexcept {
    const auto& data = digit_token.at(key);
    if (data == Compiler::token_t::TOKEN_NUMERICAL) {
        return std::make_tuple(std::isdigit(key[0]), key);
    }
    return std::make_tuple(false, key);
}

std::tuple<bool, std::string> Compiler::token_validator::check_fp_digit(const std::string& key, const std::unordered_map<std::string, Compiler::token_t>& fp_tok) noexcept {
    const auto& data = fp_tok.at(key);
    int dot_count = 0;
    int c = 0;

    if (data == Compiler::token_t::TOKEN_FLOATING_POINT) {
        if (key[0] == '.')
            goto invalid_syntax;
        do {
            if (dot_count > 1)
                goto invalid_syntax;
            if (std::isdigit(key[0])) {
                if (key[c] == '.')
                    dot_count++;
            }
            c++;
        } while(key[c] != '\0');
        if (std::isdigit(key[key.length() - 1]))
            return std::make_tuple(true, key);
        else
            goto invalid_syntax;
    }

    invalid_syntax:
        return std::make_tuple(false, key);

    return std::make_tuple(false, key);
}