#include "assembler.h"

namespace mws {
  std::string Assembler::translate_tokeon(std::string token) {
    // IMP
    if (imp == "SM") {
      return " ";
    }
    if (imp == "AM") {
      return "\t ";
    }
    if (imp == "HA") {
      return "\t\t";
    }
    if (imp == "FC") {
      return "\n";
    }
    if (imp == "IO") {
      return "\t\n";
    }

    // SM Instrunctions
    if (mins == "PUSH") {
      return " ";
    }
    if (mins == "DUP") {
      return "\n ";
    }
    if (mins == "SWP") {
      return "\n\t";
    }
    if (mins == "POP") {
      return "\n\n";
    }

    // AM Instrunctions
    if (mins == "ADD") {
      return " ";
    }
    if (mins == "SUB") {
      return "\n ";
    }
    if (mins == "MUL") {
      return "\n\t";
    }
    if (mins == "DIV") {
      return "\n\n";
    }
    if (mins == "MOD") {
      return "\t\t";
    }

    // HA Instrunctions
    if (mins == "STR") {
      return " ";
    }
    if (mins == "RTR") {
      return "\t";
    }

    // FC Instrunctions
    if (mins == "LABEL") {
      return " ";
    }
    if (mins == "CALL") {
      return "\n ";
    }
    if (mins == "JMP") {
      return "\n\t";
    }
    if (mins == "BRNZ") {
      return "\n\n";
    }
    if (mins == "RET") {
      return "\t\t";
    }
    if (mins == "END") {
      return "\n\n";
    }

    // IO Instrunctions
    if (mins == "PUTC") {
      return "  ";
    }
    if (mins == "PUTI") {
      return " \t";
    }
    if (mins == "GETC") {
      return "\t ";
    }
    if (mins == "GETI") {
      return "\t\t";
    }

    // Invalid Token
    return "INVALID";
  }
}
