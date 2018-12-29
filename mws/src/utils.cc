#include "mws/utils.h"

#include <regex>

namespace mws {
namespace utils {
bool IsNumber(const std::string &token) {
  return std::regex_match(token, std::regex("[+-]?[0-9]+"));
}
} // namespace utils
} // namespace mws
