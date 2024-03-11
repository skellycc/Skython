#include "compiler/gram/stage1/numcheck.h"
#include "compiler/gram/token_validator.h"

// STAGE 1: Verify the correct characters are mapped to the right tokens
// STAGE 2: Verify the grammar of the tokens

using namespace Skython;

Compiler::numcheck::numcheck() { }
Compiler::numcheck::~numcheck() { }

void Compiler::numcheck::set_tokens(const std::vector<std::unordered_map<std::string, Compiler::token_t>>& tokens) noexcept {
    this->m_Tokens = tokens;
}

const bool Compiler::numcheck::validate_tokens() const noexcept {
    /*
        Verify:
            - TOKEN DIGIT       == DIGIT
            - TOKEN OPERATOR    == OPERATOR
            - TOKEN FLOAT       == FLOAT
            - TOKEN BIDMAS      == LOGIC FORMAT
    */
    for (auto& vec_map : this->m_Tokens) {
        for (auto& map : vec_map) {
            /// TODO: New class to verify tokens separately
            if (Compiler::token_validator::check_digit(map.first, vec_map)) {
                return true;
            }
        }
    }
    /* Result of validation checking */
    return false;
}