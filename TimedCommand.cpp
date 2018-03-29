/*
 * TimedCommand.cpp
 *
 *  Created on: 7 Jun 2012
 *      Author: fletcherb
 *  Modified on: 27 Mar 2018
 *      Contributor: chverma
 */

#include "TimedCommand.h"

TimedCommand::TimedCommand(String iCronString, Command *iCommand) {
	cronString = iCronString;
	command = iCommand;
  executed = false;
  oneShot = false;
}

TimedCommand::TimedCommand(String iCronString, Command *iCommand,String iParameters) {
	cronString = iCronString;
	command = iCommand;
	parameters = iParameters;
  executed = false;
  oneShot = false;
  tMode = -1;
}

TimedCommand::TimedCommand(String iCronString, Command *iCommand, String iParameters, bool oneShotP, int tModeP) {
	cronString = iCronString;
	command = iCommand;
	parameters = iParameters;
  executed = false;
  oneShot = oneShotP;
  tMode = tModeP;
}

TimedCommand::~TimedCommand() {
}

void TimedCommand::setExecuted(bool exec, DateTime tm){
  executed = (oneShot && exec);
  if (executed) {
    lastExecuted = tm;
  }
}

void TimedCommand::setCronString(String iCronString){
	cronString = iCronString;
}

void TimedCommand::setCommand(Command *iCommand){
	command = iCommand;
}

String TimedCommand::getCronString(){
	return cronString;
}

Command* TimedCommand::getCommand(){
	return command;
}

String TimedCommand::getParameters(){
	return parameters;
}

void TimedCommand::setParameters(String iParameters){
	parameters = iParameters;
}

bool TimedCommand::done(DateTime tm){
  bool res;
  switch(tMode){
    case 0:
      res = (tm.second() == lastExecuted.second());
      break;
    case 1:
      res = (tm.minute() == lastExecuted.minute());
      break;
    case 2:
      res = (tm.hour() == lastExecuted.hour());
      break;
    case 3:
      res = (tm.day() == lastExecuted.day());
      break;
    case 4:
      res = (tm.month() == lastExecuted.month());
      break;
    case 5:
      res = (tm.year() == lastExecuted.year());
      break;
  }

  if (!res) {
    executed = false;
  }
  return executed ;
}
