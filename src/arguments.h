/*
  libarguments provides simple command line argument parsing for C++ programs
  Copyright (C) 2004  Jonathan Harlap
  
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
  
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

// $Id: arguments.h,v 1.2 2004-09-04 00:00:52 jharlap Exp $
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
