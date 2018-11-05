#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include "parser.h"

int main(int argc, char **argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  std::ifstream fin(argv[1]);
  std::ofstream fout(argv[2]);
  if (!fin) {
    std::cerr << "Unable to open " << argv[1] << "." << std::endl;
    return -1;
  } else {
    std::string token;
    while(fin >> token) {
      if (!mimp.count(token)) {
        std::cerr << "Invalid IMP: " << token << std::endl;
        return -1;
      } else {
        std::string imp = token;
        fout << mimp(imp);

        fin >> token;
        if (!ins_map[])

      }
    }
  }
  fin.close();
  fout.close();

  return 0;
}
