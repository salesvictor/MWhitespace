#include "mws/assembler.h"

#include <gtest/gtest.h>

#define EXPECT_TOKEN(token, ws_token) \
  EXPECT_EQ(mws::assembler::SubstituteToken(token), ws_token)

TEST(AssemblerTest, CheckIMPTokens) {
  EXPECT_TOKEN("sm", " ");
  EXPECT_TOKEN("am", "\t ");
  EXPECT_TOKEN("ha", "\t\t");
  EXPECT_TOKEN("fc", "\n");
  EXPECT_TOKEN("io", "\t\n");
}

TEST(AssemblerTest, CheckSMTokens) {
  EXPECT_TOKEN("push", " ");
  EXPECT_TOKEN("dup", "\n ");
  EXPECT_TOKEN("cp", "\t ");
  EXPECT_TOKEN("swp", "\n\t");
  EXPECT_TOKEN("pop", "\n\n");
  EXPECT_TOKEN("slide", "\t\n");
}

TEST(AssemblerTest, CheckAMTokens) {
  EXPECT_TOKEN("add", "  ");
  EXPECT_TOKEN("sub", " \t");
  EXPECT_TOKEN("mul", " \n");
  EXPECT_TOKEN("div", "\t ");
  EXPECT_TOKEN("mod", "\t\t");
}

TEST(AssemblerTest, CheckHATokens) {
  EXPECT_TOKEN("str", " ");
  EXPECT_TOKEN("rtr", "\t");
}

TEST(AssemblerTest, CheckFCTokens) {
  EXPECT_TOKEN("label", "  ");
  EXPECT_TOKEN("call", " \t");
  EXPECT_TOKEN("jmp", " \n");
  EXPECT_TOKEN("jz", "\t ");
  EXPECT_TOKEN("js", "\t\t");
  EXPECT_TOKEN("ret", "\t\n");
  EXPECT_TOKEN("end", "\n\n");
}

TEST(AssemblerTest, CheckIOTokens) {
  EXPECT_TOKEN("out", " \t");
  EXPECT_TOKEN("outc", "  ");
  EXPECT_TOKEN("in", "\t\t");
  EXPECT_TOKEN("inc", "\t ");
}

TEST(AssemblerTest, CheckInvalidTokens) {
  EXPECT_TOKEN("invalid", "invalid");
  EXPECT_TOKEN("oaskdm", "invalid");
  EXPECT_TOKEN(" ", "invalid");
}
