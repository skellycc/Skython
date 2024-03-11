#include "compiler/gram/token_validator.h"

using namespace Skython;

/// TODO: FIX IM TIRED
bool Compiler::token_validator::check_digit(const std::string& key, const std::unordered_map<std::string, Compiler::token_t>& digit_token) noexcept {
    const auto& data = digit_token.at(key);
    if (data == Compiler::token_t::TOKEN_NUMERICAL) {
        return std::isdigit(key[0]);
    }
    return false;
}

bool Compiler::token_validator::check_fp_digit(const std::string& key, const std::unordered_map<std::string, Compiler::token_t>& fp_tok) noexcept {
    const auto& data = fp_tok.at(key);
    if (data == Compiler::token_t::TOKEN_FLOATING_POINT) {
        // Check here if it is a floating point number
    }
    return false;
}