#include "mws/assembler.h"

#include <algorithm>

namespace mws {
namespace assembler {
std::string SubstituteToken(const std::string &token) {
  std::string out_token = token;
  std::transform(token.begin(), token.end(), out_token.begin(), ::tolower);

  // IMP
  if (out_token == "sm") {
    out_token = " ";
  } else if (out_token == "am") {
    out_token = "\t ";
  } else if (out_token == "ha") {
    out_token = "\t\t";
  } else if (out_token == "fc") {
    out_token = "\n";
  } else if (out_token == "io") {
    out_token = "\t\n";
  }

  // SM Instrunctions
  else if (out_token == "push") {
    out_token = " ";
  } else if (out_token == "dup") {
    out_token = "\n ";
  } else if (out_token == "cp") {
    out_token = "\t ";
  } else if (out_token == "swp") {
    out_token = "\n\t";
  } else if (out_token == "pop") {
    out_token = "\n\n";
  } else if (out_token == "slide") {
    out_token = "\t\n";
  }

  // AM Instrunctions
  else if (out_token == "add") {
    out_token = "  ";
  } else if (out_token == "sub") {
    out_token = " \t";
  } else if (out_token == "mul") {
    out_token = " \n";
  } else if (out_token == "div") {
    out_token = "\t ";
  } else if (out_token == "mod") {
    out_token = "\t\t";
  }

  // HA Instrunctions
  else if (out_token == "str") {
    out_token = " ";
  } else if (out_token == "rtr") {
    out_token = "\t";
  }

  // FC Instrunctions
  else if (out_token == "label") {
    out_token = "  ";
  } else if (out_token == "call") {
    out_token = " \t";
  } else if (out_token == "jmp") {
    out_token = " \n";
  } else if (out_token == "jz") {
    out_token = "\t ";
  } else if (out_token == "js") {
    out_token = "\t\t";
  }else if (out_token == "ret") {
    out_token = "\t\n";
  } else if (out_token == "end") {
    out_token = "\n\n";
  }

  // IO Instrunctions
  else if (out_token == "outc") {
    out_token = "  ";
  } else if (out_token == "out") {
    out_token = " \t";
  } else if (out_token == "inc") {
    out_token = "\t ";
  } else if (out_token == "in") {
    out_token = "\t\t";
  }

  // Invalid option
  else {
    out_token = "invalid";
  }

  return out_token;
}
} // namespace assembler
} // namespace mws
