#include "parser.h"

namespace mws {
  const char* Parser::tokens[] = {
    // IMP
    "SM", "AM", "HA", "FC", "IO",

    // SM Instrunctions
    "PUSH", "DUP", "SWP", "POP",

    // AM Instrunctions
    "ADD", "SUB", "MUL", "DIV", "MOD",

    // HA Instrunctions
    "STR", "RTR",

    // FC Instrunctions
    "LABEL", "CALL", "JMP", "BRNZ", "RET", "END",

    // IO Instrunctions
    "PUTC", "PUTI", "GETC", "GETI",

    // Invalid
    "INVALID"
  };

  const char* Parser::mimp(std::string imp) {
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
    return "INVALID";
  }

  const char* Parser::sm_ins(std::string mins) {
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
    return "INVALID";
  }

  const char* Parser::am_ins(std::string mins) {
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
    return "INVALID";
  }

  const char* Parser::ha_ins(std::string mins) {
    if (mins == "STR") {
      return " ";
    }
    if (mins == "RTR") {
      return "\t";
    }
    return "INVALID";
  }

  const char* Parser::fc_ins(std::string mins) {
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
    return "INVALID";
  }

  const char* Parser::io_ins(std::string mins) {
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
    return "INVALID";
  }
}
