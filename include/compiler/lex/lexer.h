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

#ifndef __LIB_SKYTHON_LEXER_H__
#define __LIB_SKYTHON_LEXER_H__

#include <string>
#include <vector>
#include <map>
#include <tuple>

#include "token.h"

/// TODO: Validate arithmetic like 1+1 (1+1)*1 1.0 + 1.0

namespace Skython {
namespace Compiler
{

class lexer final {
    std::string m_Source;
    std::vector<std::unordered_map<std::string, Compiler::token_t>> m_Tokens;
    int m_Cursor;
    char m_Char;
private:
    std::tuple<std::string, Compiler::token_t> extract_fp_value(const char&) noexcept(false);
    std::tuple<bool, Compiler::token_t> extract_arithmetic_op(const char&) noexcept(false);
private:
    void generate_fp_tokens() noexcept(false);
    void generate_numerical_tokens() noexcept(false);
public:
    lexer();
    lexer(const std::string&);
    ~lexer();
protected:
    void advance_source() noexcept(false);
    void skip_whitespace() noexcept;
public:
    void set_source(const std::string&) noexcept;
    std::vector<std::unordered_map<std::string, Compiler::token_t>> generate_tokens() noexcept(false);
};

}
}

#endif /* __LIB_SKYTHON_LEXER_H__ */
