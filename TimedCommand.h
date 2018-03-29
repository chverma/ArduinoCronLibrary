/*
 * TimedCommand.h
 *
 *  Created on: 7 Jun 2012
 *    Author: fletcherb
 *  Modified on: 27 Mar 2018
 *    Contributor: chverma
 */

#ifndef TIMEDCOMMAND_H_
#define TIMEDCOMMAND_H_
#include "Command.h"
#include <RTClib.h>
class TimedCommand {
public:
  TimedCommand(String, Command*);
  TimedCommand(String, Command*,String);
  TimedCommand(String, Command*,String, bool, int);
  virtual ~TimedCommand();
  void setCronString(String);
  void setCommand(Command*);
  void setParameters(String);
  void setExecuted(bool, DateTime);
  Command* getCommand();
  String getCronString();
  String getParameters();
  bool done(DateTime);

private:
  Command *command;
  String cronString;
  String parameters;
  bool executed;
  bool oneShot;
  int tMode;
  DateTime lastExecuted;
};

#endif /* TIMEDCOMMAND_H_ */
