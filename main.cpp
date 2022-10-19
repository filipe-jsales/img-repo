/*
* Multiple line
* comment
*/
#include<iostream>
using std::cout;
using std::endl;

#include "Overwatch2.h"
#include "Overwatch2.cpp"
#include "Data.h"
#include "Data.cpp"
#include "Player.cpp"


int main()
{

   Overwatch2 sp1( 132323, Data( 30, 9, 2021 ) );

   //Player
   vector< string > socialMediaConection{ string("Discord"), string("PS+"), string("Valve") };
   Player id01( "Jose", "jose@gmail.com", socialMediaConection );
   Player id02( "Vinicius", "vinicius@gmail.com", socialMediaConection );
   cout << "Player id01: \n";
   id01.printSocialConnection();

   sp1.includePlayer( id01 );

   socialMediaConection.push_back( string("Tiktok") );
   sp1.includePlayer( "Joao", "joao@gmail.com", socialMediaConection );

   sp1.printPlayersList( );


   Overwatch2 sp2( sp1 );
   socialMediaConection.push_back( string("Instagram") );
   sp2.includePlayer( "Maria", "maria@gmail.com", socialMediaConection );

   cout << "Lista de contatos do sp2.\n";
   sp2.printPlayersList( );

   cout << "\n\nUsando o friend ostream &operator\n";
   cout << sp2;

   cout << "List history: \n";
   sp2.sendMVPToPlayer("Zyra");
   sp2.removeMVPByname("Zyra");
   sp2.listMVPHistory();

   id01.setTimeSpent(5.0);
   id02.setTimeSpent(10.0);

   cout << "Removing last MVP give to a player\n ";
   sp2.removeLastMVP( );
   sp2.listMVPHistory();

   
   cout << "Test3";
   return 0;
}