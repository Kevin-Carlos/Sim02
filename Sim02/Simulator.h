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
#include <iomanip>


class Simulator
{
public:
	//Variables
	char		code;

	string	key;

   int		configTime ,
            metaTime ,
            processTime ,
            memory ,
            address ,
            count;

   double process;

   queue<int> tempQueue;
   map<string , string>::iterator it;
   

	//Methods
	void runSim ( MetaData , ConfigData );
   void copyMetaQueue ( MetaData );
	void setMetaCode ( MetaData& );
	void setMetaKey ( MetaData& );
	void setConfigTime ( MetaData& , ConfigData );
   void setMemory ( MetaData& , ConfigData );
   void RNG ( );

};
#endif
