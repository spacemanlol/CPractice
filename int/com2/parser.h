#ifndef PARSER_H
#define PARSER_H

#include <fstream>
#include <string>
#include <vector>
#include "def.h"
 
class  Parser
{

private:
	std::string _filename;
	std::ifstream _fs;

        bool OpenStream();
        void CloseStream();
public:
  	Parser(std::string filename);


	std::vector<LLAData> ParseToLLA();

        ~Parser();

};

#endif
