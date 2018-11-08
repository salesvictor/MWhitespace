#include "assembler.h"

namespace mws
{
  namespace assembler
  {
    std::string translate_token(std::string token)
    {
      // IMP
      if (token == "SM")
      {
        return " ";
      }
      if (token == "AM")
      {
        return "\t ";
      }
      if (token == "HA")
      {
        return "\t\t";
      }
      if (token == "FC")
      {
        return "\n";
      }
      if (token == "IO")
      {
        return "\t\n";
      }

      // SM Instrunctions
      if (token == "PUSH")
      {
        return " ";
      }
      if (token == "DUP")
      {
        return "\n ";
      }
      if (token == "SWP")
      {
        return "\n\t";
      }
      if (token == "POP")
      {
        return "\n\n";
      }

      // AM Instrunctions
      if (token == "ADD")
      {
        return " ";
      }
      if (token == "SUB")
      {
        return "\n ";
      }
      if (token == "MUL")
      {
        return "\n\t";
      }
      if (token == "DIV")
      {
        return "\n\n";
      }
      if (token == "MOD")
      {
        return "\t\t";
      }

      // HA Instrunctions
      if (token == "STR")
      {
        return " ";
      }
      if (token == "RTR")
      {
        return "\t";
      }

      // FC Instrunctions
      if (token == "LABEL")
      {
        return " ";
      }
      if (token == "CALL")
      {
        return "\n ";
      }
      if (token == "JMP")
      {
        return "\n\t";
      }
      if (token == "BRNZ")
      {
        return "\n\n";
      }
      if (token == "RET")
      {
        return "\t\t";
      }
      if (token == "END")
      {
        return "\n\n";
      }

      // IO Instrunctions
      if (token == "PUTC")
      {
        return "  ";
      }
      if (token == "PUTI")
      {
        return " \t";
      }
      if (token == "GETC")
      {
        return "\t ";
      }
      if (token == "GETI")
      {
        return "\t\t";
      }

      // Invalid Token
      return "INVALID";
    }
  } // namespace assembler
} // namespace mws
