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

#include "compiler/gram/stage1/numcheck.h"
#include "compiler/gram/token_validator.h"

// STAGE 1: Verify the correct characters are mapped to the right tokens
// STAGE 2: Verify the grammar of the tokens

using namespace Skython;

std::vector<std::unordered_map<std::string, Compiler::token_t>> Compiler::numcheck::s_Tokens;

void Compiler::numcheck::set_tokens(const std::vector<std::unordered_map<std::string, Compiler::token_t>>& tokens) noexcept {
    Compiler::numcheck::s_Tokens = tokens;
}

/// TODO: Clean up to validate multiple tokens of different types

std::tuple<bool, std::string> Compiler::numcheck::validate_tokens() noexcept {
    std::string fail;
    /*
        Verify:
            - TOKEN DIGIT       == DIGIT
            - TOKEN OPERATOR    == OPERATOR
            - TOKEN FLOAT       == FLOAT
            - TOKEN BIDMAS      == LOGIC FORMAT
    */
    for (auto& vec_map : Compiler::numcheck::s_Tokens) {
        for (auto& map : vec_map) {
            /// TODO: New class to verify tokens separately
            const auto r = Compiler::token_validator::check_digit(map.first, vec_map);
            if (std::get<0>(r)) {
                return std::make_tuple(true, "");
            } else {
                fail = std::get<1>(r);
            }
        }
    }
    /* Result of validation checking */
    return std::make_tuple(false, fail);
}