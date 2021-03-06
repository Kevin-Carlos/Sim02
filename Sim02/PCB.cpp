/**
  * @file PCB.cpp
  *
  * @details implementation file for the PCB header file
  *
  * @version 1.00 Initial development
  *
  * @author Kevin Carlos
  *
  * @notes none
  *
*/

// Directives //////////////////////////////////////////////////////////////////
#ifndef __PCB_CPP
#define __PCB_CPP

// Header files ////////////////////////////////////////////////////////////////
#include "PCB.h"
#include "Timer.h"

// Global Thread Variables /////////////////////////////////////////////////////
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

/**
  * Sleep thread to handle the how long a thread should take
*/
void* sleep ( void* param )
{
   //Lock the mutex
   pthread_mutex_lock ( &mutex );

   //Critical section
   
   //param is passed in milliseconds
   long sleepTimeMilliSec = ( long ) param; 

   //Convert to microseconds
   long sleepTimeMicroSec = ( sleepTimeMilliSec ) * 1000;

   //Start my timer
   Timer myThreadTimer;
   myThreadTimer.start ( );

   //Pause the thread for ... microseconds
   while ( myThreadTimer.elapsedMicro ( ) < sleepTimeMicroSec );

   //Unlock the mutex
   pthread_mutex_unlock ( &mutex );

   return nullptr;
}

/**
  * @function genHandler
  *
  * @details This function is the general handler for any non IO process
  *
*/
void PCB::genHandler ( )
{
   //Set the time
   long time;
   time = dataQueue.front ( ).processTime;
   //std::cout << "Time: " << time << std::endl;

   sleep ( ( void* ) time );
}

/**
  * @function IOHandler
  *
  * @details This function takes in the process type to output for input or
  *            output
  *
*/
void PCB::IOHandler ( )
{
   //Variables
   pthread_t IOthread;

   //Set the time
   long time;
   time = dataQueue.front ( ).processTime;
  
   //Start the thread 
   pthread_create (
      &IOthread ,
      NULL ,
      sleep ,
      (void *) time
   );
   pthread_join ( IOthread , NULL ); 
}


void PCB::setProcessState ( int newState )
{
   processState = newState;
}

int PCB::getProcessState ( )
{
   return processState;
}


#endif
