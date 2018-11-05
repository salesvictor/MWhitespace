#ifndef PARSER_H
#define PARSER_H

#include <string>

namespace mws {
  class Parser {
    private:
      static const char* tokens[];
      const char* mimp(std::string imp);
      const char* sm_ins(std::string mins);
      const char* am_ins(std::string mins);
      const char* ha_ins(std::string mins);
      const char* fc_ins(std::string mins);
      const char* io_ins (std::string mins);
  };
}

#endif // PARSER_H
