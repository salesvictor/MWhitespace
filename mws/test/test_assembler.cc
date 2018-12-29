#include "mws/assembler.h"

#include <gtest/gtest.h>

#define EXPECT_TOKEN(token, ws_token) \
  EXPECT_EQ(mws::assembler::SubstituteToken(token), ws_token)

TEST(SubstituteTokenTest, CheckIMPTokens) {
  EXPECT_TOKEN("sm", " ");
  EXPECT_TOKEN("am", "\t ");
  EXPECT_TOKEN("ha", "\t\t");
  EXPECT_TOKEN("fc", "\n");
  EXPECT_TOKEN("io", "\t\n");
}

TEST(SubstituteTokenTest, CheckSMTokens) {
  EXPECT_TOKEN("push", " ");
  EXPECT_TOKEN("dup", "\n ");
  EXPECT_TOKEN("cp", "\t ");
  EXPECT_TOKEN("swp", "\n\t");
  EXPECT_TOKEN("pop", "\n\n");
  EXPECT_TOKEN("slide", "\t\n");
}

TEST(SubstituteTokenTest, CheckAMTokens) {
  EXPECT_TOKEN("add", "  ");
  EXPECT_TOKEN("sub", " \t");
  EXPECT_TOKEN("mul", " \n");
  EXPECT_TOKEN("div", "\t ");
  EXPECT_TOKEN("mod", "\t\t");
}

TEST(SubstituteTokenTest, CheckHATokens) {
  EXPECT_TOKEN("str", " ");
  EXPECT_TOKEN("rtr", "\t");
}

TEST(SubstituteTokenTest, CheckFCTokens) {
  EXPECT_TOKEN("label", "  ");
  EXPECT_TOKEN("call", " \t");
  EXPECT_TOKEN("jmp", " \n");
  EXPECT_TOKEN("jz", "\t ");
  EXPECT_TOKEN("js", "\t\t");
  EXPECT_TOKEN("ret", "\t\n");
  EXPECT_TOKEN("end", "\n\n");
}

TEST(SubstituteTokenTest, CheckIOTokens) {
  EXPECT_TOKEN("out", " \t");
  EXPECT_TOKEN("outc", "  ");
  EXPECT_TOKEN("in", "\t\t");
  EXPECT_TOKEN("inc", "\t ");
}

TEST(SubstituteTokenTest, CheckInvalidTokens) {
  EXPECT_TOKEN("invalid", "invalid");
  EXPECT_TOKEN("oaskdm", "invalid");
  EXPECT_TOKEN(" ", "invalid");
}

TEST(AssembleProgramTest, CheckMultiTokenWrongProgram) {
  std::stringstream program("dup dup jz\nout outc in");
  std::stringstream out_program;
  mws::assembler::AssembleProgram(program, out_program);

  EXPECT_EQ(out_program.str(), "\n \n \t  \t  \t\t");
}

TEST(AssembleProgramTest, CheckMultiTokenProgram) {
  std::stringstream program("push 123456\nout");
  std::stringstream out_program;
  mws::assembler::AssembleProgram(program, out_program);

  EXPECT_EQ(out_program.str(), " \t\t\t\t   \t  \t       \t");
}
