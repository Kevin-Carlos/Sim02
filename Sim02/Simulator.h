/**
  * File: Simulator.h
  *
  * Details: Runs the simulation timing processes
  *
  * Version 1.00 Initial 
  *
  * Notes: None
  *
*/

//Include Guards
#ifndef __SIMULATOR__
#define __SIMULATOR__

//
// Libraries
//
#include <pthread.h>
#include "MetaData.h"
#include <ctime>
#include <chrono>


class Simulator
{
public:
	//Variables
	char		code;
	string	key;
   int		configTime ,
            metaTime ,
            processTime;
   queue<int> tempQueue;
   

	double process;

	//Methods
	void runSim ( MetaData , ConfigData );
   void copyMetaQueue ( MetaData );
	void setMetaCode ( MetaData& );
	void setMetaKey ( MetaData& );
	void setConfigTime ( MetaData& , ConfigData );
};
#endif
