#include "mws/assembler.h"

#include <gtest/gtest.h>

#define EXPECT_TOKEN(token, ws_token) \
  EXPECT_EQ(mws::assembler::SubstituteToken(token), ws_token)

TEST(SubstituteTokenTest, IMPTokensLower) {
  EXPECT_TOKEN("sm", " ");
  EXPECT_TOKEN("am", "\t ");
  EXPECT_TOKEN("ha", "\t\t");
  EXPECT_TOKEN("fc", "\n");
  EXPECT_TOKEN("io", "\t\n");
}

TEST(SubstituteTokenTest, IMPTokensUpper) {
  EXPECT_TOKEN("SM", " ");
  EXPECT_TOKEN("AM", "\t ");
  EXPECT_TOKEN("HA", "\t\t");
  EXPECT_TOKEN("FC", "\n");
  EXPECT_TOKEN("IO", "\t\n");
}

TEST(SubstituteTokenTest, SMTokensLower) {
  EXPECT_TOKEN("push", " ");
  EXPECT_TOKEN("dup", "\n ");
  EXPECT_TOKEN("cp", "\t ");
  EXPECT_TOKEN("swp", "\n\t");
  EXPECT_TOKEN("pop", "\n\n");
  EXPECT_TOKEN("slide", "\t\n");
}

TEST(SubstituteTokenTest, SMTokensUpper) {
  EXPECT_TOKEN("PUSH", " ");
  EXPECT_TOKEN("DUP", "\n ");
  EXPECT_TOKEN("CP", "\t ");
  EXPECT_TOKEN("SWP", "\n\t");
  EXPECT_TOKEN("POP", "\n\n");
  EXPECT_TOKEN("SLIDE", "\t\n");
}

TEST(SubstituteTokenTest, AMTokensLower) {
  EXPECT_TOKEN("add", "  ");
  EXPECT_TOKEN("sub", " \t");
  EXPECT_TOKEN("mul", " \n");
  EXPECT_TOKEN("div", "\t ");
  EXPECT_TOKEN("mod", "\t\t");
}

TEST(SubstituteTokenTest, AMTokensUpper) {
  EXPECT_TOKEN("ADD", "  ");
  EXPECT_TOKEN("SUB", " \t");
  EXPECT_TOKEN("MUL", " \n");
  EXPECT_TOKEN("DIV", "\t ");
  EXPECT_TOKEN("MOD", "\t\t");
}

TEST(SubstituteTokenTest, HATokensLower) {
  EXPECT_TOKEN("str", " ");
  EXPECT_TOKEN("rtr", "\t");
}

TEST(SubstituteTokenTest, HATokensUpper) {
  EXPECT_TOKEN("STR", " ");
  EXPECT_TOKEN("RTR", "\t");
}

TEST(SubstituteTokenTest, FCTokensLower) {
  EXPECT_TOKEN("label", "  ");
  EXPECT_TOKEN("call", " \t");
  EXPECT_TOKEN("jmp", " \n");
  EXPECT_TOKEN("jz", "\t ");
  EXPECT_TOKEN("js", "\t\t");
  EXPECT_TOKEN("ret", "\t\n");
  EXPECT_TOKEN("end", "\n\n");
}

TEST(SubstituteTokenTest, FCTokensUpper) {
  EXPECT_TOKEN("LABEL", "  ");
  EXPECT_TOKEN("CALL", " \t");
  EXPECT_TOKEN("JMP", " \n");
  EXPECT_TOKEN("JZ", "\t ");
  EXPECT_TOKEN("JS", "\t\t");
  EXPECT_TOKEN("RET", "\t\n");
  EXPECT_TOKEN("END", "\n\n");
}

TEST(SubstituteTokenTest, IOTokensLower) {
  EXPECT_TOKEN("out", " \t");
  EXPECT_TOKEN("outc", "  ");
  EXPECT_TOKEN("in", "\t\t");
  EXPECT_TOKEN("inc", "\t ");
}

TEST(SubstituteTokenTest, IOTokensUpper) {
  EXPECT_TOKEN("OUT", " \t");
  EXPECT_TOKEN("OUTC", "  ");
  EXPECT_TOKEN("IN", "\t\t");
  EXPECT_TOKEN("INC", "\t ");
}


TEST(SubstituteTokenTest, Numbers) {
  EXPECT_TOKEN("1", " \t");
  EXPECT_TOKEN("2", " \t ");
  EXPECT_TOKEN("3", " \t\t");
  EXPECT_TOKEN("8", " \t   ");
  EXPECT_TOKEN("-1", "\t\t");
  EXPECT_TOKEN("-11", "\t\t \t\t");
}

TEST(SubstituteTokenTest, InvalidTokens) {
  EXPECT_TOKEN("invalid", "invalid");
  EXPECT_TOKEN("oaskdm", "invalid");
  EXPECT_TOKEN(" ", "invalid");
}

TEST(AssembleProgramTest, MultiTokenWrongProgram) {
  std::stringstream program("dup dup jz\nout outc in");
  std::stringstream out_program;
  mws::assembler::AssembleProgram(program, out_program);

  EXPECT_EQ(out_program.str(), "\n \n \t  \t  \t\t");
}

TEST(AssembleProgramTest, MultiTokenProgram) {
  std::stringstream program("push 123456\nout");
  std::stringstream out_program;
  mws::assembler::AssembleProgram(program, out_program);

  EXPECT_EQ(out_program.str(), "  \t\t\t\t   \t  \t       \t");
}
