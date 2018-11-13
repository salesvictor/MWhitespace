#include "assembler.h"

namespace mws {
namespace assembler {
  std::string translate_token(std::string token) {
    // IMP
    if (token == "SM") {
      return " ";
    } else if (token == "AM") {
      return "\t ";
    } else if (token == "HA") {
      return "\t\t";
    } else if (token == "FC") {
      return "\n";
    } else if (token == "IO") {
      return "\t\n";
    }

    // SM Instrunctions
    if (token == "PUSH") {
      return " ";
    } else if (token == "DUP") {
      return "\n ";
    } else if (token == "SWP") {
      return "\n\t";
    } else if (token == "POP") {
      return "\n\n";
    }

    // AM Instrunctions
    if (token == "ADD")
    {
      return " ";
    } else if (token == "SUB") {
      return "\n ";
    } else if (token == "MUL") {
      return "\n\t";
    } else if (token == "DIV") {
      return "\n\n";
    } else if (token == "MOD") {
      return "\t\t";
    }

    // HA Instrunctions
    if (token == "STR") {
      return " ";
    } else if (token == "RTR") {
      return "\t";
    }

    // FC Instrunctions
    if (token == "LABEL") {
      return " ";
    } else if (token == "CALL") {
      return "\n ";
    } else if (token == "JMP") {
      return "\n\t";
    } else if (token == "BRNZ") {
      return "\n\n";
    } else if (token == "RET") {
      return "\t\t";
    } else if (token == "END") {
      return "\n\n";
    }

    // IO Instrunctions
    if (token == "PUTC") {
      return "  ";
    } else if (token == "PUTI") {
      return " \t";
    } else if (token == "GETC") {
      return "\t ";
    } else if (token == "GETI") {
      return "\t\t";
    }

    // Invalid Token
    return "INVALID";
  }
} // namespace assembler
} // namespace mws
