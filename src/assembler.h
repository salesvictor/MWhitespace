#ifndef MWS_ASSEMBLER_H
#define MWS_ASSEMBLER_H

#include <string>

namespace mws {
  class Assembler {
    public:
      static std::string translate_token(std::string token);
  };
}

#endif // MWS_ASSEMBLER_H
