#ifndef ARGUMENTS_H
#define ARGUMENTS_H

#include <string>
#include <map>
#include <vector>

using namespace std;

class Arguments {
  string optionPrefix;
  string programName;
  string programDescription;
  
 public:
  class Option;

  class Argument {
    friend class Arguments;
    friend class Option;
    
    string argName;
    string argDescription;
    string argValue;
    string argDef;
    
  public:
    Argument(string name, string description="", string def="");
  };
  
  typedef vector<Argument> ArgumentVector;
  
  class Option {
    friend class Arguments;
    
    string optName;
    string optDescription;
    ArgumentVector optArguments;
    bool optIsSet;

  public:
    Option(string name, string description);
    void addArgument(string name, string description="", string def="");

    string &operator[](char* name);
    string &operator[](const char *name);

    operator bool();
    string getName();
  };

 public:
  typedef vector<string> LeftoversVector;

 private:
  typedef map<string, Option> OptionMap;

  OptionMap argsOptions;
  ArgumentVector argsArguments;
  static Option unknownOption;
  static Argument unknownArgument;
  LeftoversVector argsLeftovers;


 public:
  void usage();
  void addOption(string name, string description="");
  void addOption(Option &option);
  void addArgument(string name, string description="", string def="");
  bool parse(int argc, char *argv[]);

  string &operator[](char* name);
  Option &getOption(char* name);
  LeftoversVector &Arguments::getLeftovers();

  Arguments(string name, string description="", string prefix="-");
};

#endif // ARGUMENTS_H
