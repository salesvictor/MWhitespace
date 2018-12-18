#include "mws/assembler.h"

#include <algorithm>

namespace mws{
namespace assembler{
std::string sibstitute_token(const std::string &token){
  std::string out_token;
  std::transform(token.begin(), token.end(), out_token.begin(), ::tolower);

  // IMP
  if (out_token == "sm"){
    out_token = " ";
  } else if (out_token == "am"){
    out_token = "\t ";
  } else if (out_token == "ha"){
    out_token = "\t\t";
  } else if (out_token == "fc"){
    out_token = "\n";
  } else if (out_token == "io"){
    out_token = "\t\n";
  }

  // SM Instrunctions
  if (out_token == "push") {
    out_token = " ";
  } else if (out_token == "dup"){
    out_token = "\n ";
  } else if (out_token == "swp"){
    out_token = "\n\t";
  } else if (out_token == "pop"){
    out_token = "\n\n";
  }

  // AM Instrunctions
  if (out_token == "add"){
    out_token = " ";
  } else if (out_token == "sub"){
    out_token = "\n ";
  } else if (out_token == "mul"){
    out_token = "\n\t";
  } else if (out_token == "div"){
    out_token = "\n\n";
  } else if (out_token == "mod"){
    out_token = "\t\t";
  }

  // HA Instrunctions
  if (out_token == "str"){
    out_token = " ";
  } else if (out_token == "rtr"){
    out_token = "\t";
  }

  // FC Instrunctions
  if (out_token == "label"){
    out_token = " ";
  } else if (out_token == "call"){
    out_token = "\n ";
  } else if (out_token == "jmp"){
    out_token = "\n\t";
  } else if (out_token == "brnz"){
    out_token = "\n\n";
  } else if (out_token == "ret"){
    out_token = "\t\t";
  } else if (out_token == "end"){
    out_token = "\n\n";
  }

  // IO Instrunctions
  if (out_token == "putc"){
    out_token = "  ";
  } else if (out_token == "puti"){
    out_token = " \t";
  } else if (out_token == "getc"){
    out_token = "\t ";
  } else if (out_token == "geti"){
    out_token = "\t\t";
  }

  return out_token;
}
} // namespace assembler
} // namespace mws
