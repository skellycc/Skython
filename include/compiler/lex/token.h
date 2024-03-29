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

#ifndef __LIB_SKYTHON_TOKEN_H__
#define __LIB_SKYTHON_TOKEN_H__

namespace Skython {
namespace Compiler
{

typedef enum token {
    
    /* Arithmetic */
    TOKEN_NUMERICAL,
    TOKEN_FLOATING_POINT,
    
    TOKEN_ADD_OP,
    TOKEN_SUB_OP,
    TOKEN_MUL_OP,
    TOKEN_DIV_OP,
    TOKEN_MOD_OP,
    TOKEN_NO_REMAINDER_OP,
    
    TOKEN_OPEN_PAREN,
    TOKEN_CLOSE_PAREN,
    TOKEN_WHITESPACE,
    
    TOKEN_UNKNOWN
} token_t;

}
}

#endif /* __LIB_SKYTHON_TOKEN_H__ */
