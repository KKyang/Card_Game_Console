/**********************************************************************/
/*姓名：黃揚文                                                         */
/*名稱：HW06018                                                        */
/*日期：2010/12/20                                                     */
/*程式敘述：橋牌發牌及顯示                                              */
/**********************************************************************/
#include "stdafx.h"
#include "cardGameRule.h"
#include "Windowlook.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include "consola.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	int Choose[1]={0};                           //Used for choosing mode.
	char Key;                                    //Used to restart or exit the program
	int player[4][13]={0};                       //Used to save the player's card value
	char playerCardType[4][13]={0};              //Used to save the pattern of the player
	                                             //0~3 is the for players, 0~12 is the cards 
	welcome(Choose);                             //Set welcome pages

	if(Choose[0]==1){
	while(cin){                                  //break when entering CTRL+Z
	
	
	 int point[4]={0};                            //Used to save points of each player

	 window();                                    //card look and decoration of the window
	 cardShuffle(player, playerCardType);         //Shuffle and give cards
	 drawcount(player, point);                    //Counting the points of the players
	 printCards(player, point, playerCardType);   //print out the card values
	
	
     cin>>Key;
	 }	
	}

	else if(Choose[0]==2){
	 while(cin){                                  //break when entering CTRL+Z
	  int ReturnCheatCode=1;
	  int point[4]={0};                            //Used to save points of each player

	  window();                                    //card look and decoration of the window

	   while(ReturnCheatCode==1){
	   gotoxy(1,1);
	   cout<<"CHEAT MODE";
	   cardShuffle(player, playerCardType);         //Shuffle and give cards
	   drawcount(player, point);                    //Counting the points of the players
	   ReturnCheatCode=CheatMode(point);
	   if(ReturnCheatCode)
		   for(int i=0;i<=4;i++)
			   point[i]=0;
	  }

	  printCards(player, point, playerCardType);   //print out the card values
     cin>>Key;
	 }	
	}
	

	return 0;
}

