#include "mws/assembler.h"

#include <gtest/gtest.h>

#define EXPECT_TOKEN(token, ws_token) \
  EXPECT_EQ(mws::assembler::SubstituteToken(token), ws_token)

TEST(SubstituteTokenTest, IMPTokens) {
  EXPECT_TOKEN("sm", " ");
  EXPECT_TOKEN("am", "\t ");
  EXPECT_TOKEN("ha", "\t\t");
  EXPECT_TOKEN("fc", "\n");
  EXPECT_TOKEN("io", "\t\n");
}

TEST(SubstituteTokenTest, SMTokens) {
  EXPECT_TOKEN("push", " ");
  EXPECT_TOKEN("dup", "\n ");
  EXPECT_TOKEN("cp", "\t ");
  EXPECT_TOKEN("swp", "\n\t");
  EXPECT_TOKEN("pop", "\n\n");
  EXPECT_TOKEN("slide", "\t\n");
}

TEST(SubstituteTokenTest, AMTokens) {
  EXPECT_TOKEN("add", "  ");
  EXPECT_TOKEN("sub", " \t");
  EXPECT_TOKEN("mul", " \n");
  EXPECT_TOKEN("div", "\t ");
  EXPECT_TOKEN("mod", "\t\t");
}

TEST(SubstituteTokenTest, HATokens) {
  EXPECT_TOKEN("str", " ");
  EXPECT_TOKEN("rtr", "\t");
}

TEST(SubstituteTokenTest, FCTokens) {
  EXPECT_TOKEN("label", "  ");
  EXPECT_TOKEN("call", " \t");
  EXPECT_TOKEN("jmp", " \n");
  EXPECT_TOKEN("jz", "\t ");
  EXPECT_TOKEN("js", "\t\t");
  EXPECT_TOKEN("ret", "\t\n");
  EXPECT_TOKEN("end", "\n\n");
}

TEST(SubstituteTokenTest, IOTokens) {
  EXPECT_TOKEN("out", " \t");
  EXPECT_TOKEN("outc", "  ");
  EXPECT_TOKEN("in", "\t\t");
  EXPECT_TOKEN("inc", "\t ");
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
