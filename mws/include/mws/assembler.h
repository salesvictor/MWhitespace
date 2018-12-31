#ifndef MWS_INCLUDE_MWS_ASSEMBLER_H
#define MWS_INCLUDE_MWS_ASSEMBLER_H

#include <string>

namespace mws {
namespace assembler {
std::string SubstituteToken(const std::string &token);
void AssembleProgram(std::istream &program, std::ostream &out_program);
} // namespace assembler
} // namespace mws

#endif // MWS_INCLUDE_MWS_ASSEMBLER_H
