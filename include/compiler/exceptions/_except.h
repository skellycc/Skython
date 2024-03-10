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

#ifndef __LIB_SKYTHON__EXCEPT_H__
#define __LIB_SKYTHON__EXCEPT_H__

#include <string>

namespace Skython {
namespace Compiler {
namespace Exceptions
{

class _except {
protected:
    std::string _cause;
    std::string _file;
    int line;
    int row;
public:
    _except();
    _except(const std::string&);
    virtual ~_except() = 0;
public:
    virtual void raise()                                const noexcept  = 0;
    virtual const std::string get_cause()               const noexcept  = 0;
    virtual const std::string get_localized_cause()     noexcept        = 0;
};

}
}
}

#endif /* __LIB_SKYTHON__EXCEPT_H__ */