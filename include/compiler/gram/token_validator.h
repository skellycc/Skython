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

#ifndef __LIB_SKYTHON_TOKEN_VALIDATOR_H__
#define __LIB_SKYTHON_TOKEN_VALIDATOR_H__

#include <string>
#include <map>

#include "compiler/lex/token.h"

namespace Skython {
namespace Compiler
{

class token_validator final {
private:
    token_validator()   = delete;
    ~token_validator()  = delete;
public:
    static bool check_digit(const std::string&, const std::unordered_map<std::string, Compiler::token_t>&) noexcept;
    static bool check_fp_digit(const std::string&, const std::unordered_map<std::string, Compiler::token_t>&) noexcept;
};

}
}

#endif /* __LIB_SKYTHON_TOKEN_VALIDATOR_H__ */