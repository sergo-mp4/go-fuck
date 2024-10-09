#include <iostream>
#include <string>
#include <vector>
#include <map>

enum TokenType {
    GO_FUCK,
    COMMENT,
    EOF_TOKEN
};

struct Token {
    TokenType type;
    std::string value;
};

std::vector<Token> lex(const std::string& source) {
    std::vector<Token> tokens;
    std::string currentToken;

    for (char c : source) {
        if (c == '/') { // coment
            tokens.push_back({COMMENT, ""});
            while (c != '\n' && c != EOF) {
                c = getchar();
            }
        } else if (c == ' ' || c == '\t' || c == '\n') { // whitespace
            if (!currentToken.empty()) {
                if (currentToken == "go" && getchar() == 'f' && getchar() == 'u' && getchar() == 'c' && getchar() == 'k') {
                    tokens.push_back({GO_FUCK, "go fuck"});
                    currentToken.clear();
                } else {
                    tokens.push_back({COMMENT, currentToken});
                    currentToken = clear();
                }
            }
        } else {
            currentToken += c;
        }
    }

    if (!currentToken.empty()) {
        tokens.push_back({COMMENT, currentToken});
    }

    tokens.push_back({EOF_TOKEN, ""});
    return tokens;
}

void parse(const std::vector<Token>& tokens) {
    for (const Token& token : tokens) {
        if (token.type == GO_FUCK) {
            std::cout << "GoFuck! "; // handle "go fuck" keyword
        } else if (token.type == COMMENT) {
            // ignore
        } else if (token.type == EOF_TOKEN) {
            break;
        }
    }
}

int main() {
    std::string source;
    std::cout << "Enter GoFuck code: ";
    std::geline(std::cin, source);

    std::vector<Token> tokens = lex(source);
    parse(tokens);

    return 0;
}