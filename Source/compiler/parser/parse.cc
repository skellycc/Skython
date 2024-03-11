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

#include "compiler/parser/parse.h"
#include "compiler/gram/token_validator.h"
#include "compiler/gram/stage1/numcheck.h"

using namespace Skython;

std::tuple<bool, std::string> Compiler::Parser::parse::verify_tokens(const std::vector<std::unordered_map<std::string, Compiler::token_t>>& tokens) noexcept {
    /* Validate Numerical Values */
    Compiler::numcheck::set_tokens(tokens);
    return Compiler::numcheck::validate_tokens();
}