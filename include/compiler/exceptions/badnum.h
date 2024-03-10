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

#ifndef __LIB_SKYTHON_BADNUM_H__
#define __LIB_SKYTHON_BADNUM_H__

#include "_except.h"
#include "log/basic_log.h"

namespace Skython {
namespace Compiler {
namespace Exceptions
{

class badnum : public _except {
public:
    badnum() { }
    badnum(const std::string& value) {
        if (value.find("FILE:") == std::string::npos)
            _cause = value;
        else
            _file = value;
    }
    ~badnum() override = default;
public:
    void raise() const noexcept override {
        __raise_log(_cause);
    }
    const std::string get_cause() const noexcept override {
        return _cause;
    }
    const std::string get_localized_cause() noexcept override {
        /// TODO: localize it
        return _cause;
    }
};

}
}
}

#endif /* __LIB_SKYTHON_BADNUM_H__ */