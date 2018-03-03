/**
  * File: Simulator.cpp
  *
  * Details: Implementation of Simulator
  *
  * Version: 1.00 Initial development 
  *
  * Notes: None
  *
  *
*/
#include "Simulator.h"
#include <iostream>

#define DEBUG 1

void Simulator::runSim ( MetaData myMeta , ConfigData myConfig )
{
	//Variables
   const string BEGIN = "begin";
   const string FINISH = "finish";
   
   //First copy the intQueue
   copyMetaQueue ( myMeta );
   setMemory ( myMeta, myConfig );
   //Now I can use this to create processTimes

   //Start time
   chrono::high_resolution_clock::time_point beginTime = 
      chrono::high_resolution_clock::now ( );

   while ( !tempQueue.empty ( ) )
   {
      //Grab the code, the key, configTime
      setMetaCode ( myMeta );
      setMetaKey ( myMeta );
      setConfigTime ( myMeta , myConfig );
      metaTime = tempQueue.front ( );
      tempQueue.pop ( );

      chrono::high_resolution_clock::time_point tempTime =
         chrono::high_resolution_clock::now ( );
      processTime = configTime * metaTime;

      chrono::duration<double> now =
         chrono::duration_cast< chrono::duration<double> >
         ( tempTime - beginTime );

      switch ( code )
      {

      case 'S':
         if ( key == BEGIN )
         {
            cout << now.count ( ) << " - Simulator program starting\n";
         }
         else if ( key == FINISH )
         {
            cout << now.count ( ) << " - Simulator program ending\n";
         }
         break;

      case 'A':
         if ( key == BEGIN )
         {

         }
         else if ( key == FINISH )
         {

         }
         break;
      case 'P':
         break;
      case 'I':
         break;
      case 'O':
         break;
      case 'M':
         cout << now.count ( ) << " - allocating memory\n";
         RNG ( );
         cout << now.count ( ) << " - memory allocated at " 
            << "0x" << hex << address << "\n";
         break;
      default:
         cout << "Error with the switch codes...\n";
         break;
      }

      if ( DEBUG == 1 )
      {
         cout << "Code: " << code << "\n";
         cout << "Key: " << key << "\n";
         cout << "ConfigTime: " << configTime << "\n";
         cout << "MetaTime: " << metaTime << "\n";
         cout << "ProcessTime: " << processTime << "\n";
      }
   }
}

void Simulator::RNG ( )
{
   int num;
   srand ( time ( NULL ) );
   num = rand ( );
   address = num;
}


void Simulator::setMemory ( MetaData &myMeta , ConfigData myConfig )
{
   string temp;
   it = myConfig.configMap.find ( "system" );
   temp = it->second;
   memory = stoi ( temp );
}

void Simulator::copyMetaQueue ( MetaData myMeta )
{
   while ( !myMeta.intQueue.empty ( ) )
   {
      tempQueue.push ( myMeta.intQueue.front ( ) );
      myMeta.intQueue.pop ( );
   }
}

void Simulator::setMetaCode ( MetaData &myMeta )
{
	//std::cout << "Front: " << myMeta.charQueue.front() << "\n";
	code = myMeta.charQueue.front ( );
   myMeta.charQueue.pop ( );
}

void Simulator::setMetaKey ( MetaData &myMeta )
{
	myMeta.stringQueue.pop ( ); //Now its on the key, not data
	//std::cout << "Key: " << myMeta.stringQueue.front ( ) << "\n";
	key = myMeta.stringQueue.front ( );
   myMeta.stringQueue.pop ( ); // Back to the entire string
}

void Simulator::setConfigTime ( MetaData &myMeta , ConfigData myConfig )
{
	string temp , temp2;

   if ( key == "begin" )
      return;
   if ( key == "run" )
      temp = "processor";
   else if ( key == "allocate" )
      temp = "memory";
   else if ( key == "hard drive" )
      temp = "hard";
   else
      temp = key;

   it = myConfig.configMap.find ( temp );
   temp2 = it->second;
   configTime = stoi ( temp2 );

}