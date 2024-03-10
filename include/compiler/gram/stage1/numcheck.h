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

#ifndef __LIB_SKYTHON_NUMCHECK_H__
#define __LIB_SKYTHON_NUMCHECK_H__

#include <string>
#include <map>
#include <vector>

#include "compiler/lex/token.h"

namespace Skython {
namespace Compiler
{

class numcheck final {
private:
    std::vector<std::unordered_map<std::string, Compiler::token_t>> m_Tokens;
public:
    numcheck();
    ~numcheck();
public:
    void set_tokens(const std::vector<std::unordered_map<std::string, Compiler::token_t>>&) noexcept;
    const bool validate_tokens() const noexcept;
};

}
}

#endif /* __LIB_SKYTHON_NUMCHECK_H__ */