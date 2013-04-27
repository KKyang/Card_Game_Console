#include "stdafx.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void cardShuffle(int player[4][13], char playerCardType[4][13]){     //Shuffle the cards by random
	int cardCount[14]={0};
	int cardCountType[14][7]={0};
	for(int i=0;i<4;i++)
		for(int j=0;j<13;j++){
			player[i][j]=rand()%13+1;
			cardCount[player[i][j]]++;              //checking by counting how many cards has been used

			if(cardCount[player[i][j]]>4)           //if used j--
				j--;
		}

	for(int i=0;i<4;i++)
		for(int j=0;j<13;j++){
		  playerCardType[i][j]=rand()%4+3;               //Using ASCII code ♠as 6、♦ as 4、♣ as 5、♥ as 3
		  cardCountType[player[i][j]][playerCardType[i][j]]++;//Same method with cardvalue

		  if(cardCountType[player[i][j]][playerCardType[i][j]]>1)
			  j--;
		}

}

void drawcount(int player[4][13], int point[4]){         //Adding points of each player
	for(int i=0;i<4;i++)
		for(int j=0;j<13;j++)
			switch(player[i][j]){
			 case 1:
				 point[i]+=4;
				 break;
			 case 13:
				 point[i]+=3;
				 break;
			 case 12:
				 point[i]+=2;
				 break;
			 case 11:
				 point[i]+=1;
				 break;
			}
		
}

void cardvalue(int a){                                  //Changing 1,11,12,13 to A,J,Q,K
	switch(a){
		case 1:
			cout<<"A";
			break;
		case 11:
			cout<<"J";
			break;
		case 12:
			cout<<"Q";
			break;
		case 13:
			cout<<"K";
			break;
		default:
			cout<<a;
			break;
	}
}

int CheatMode(int point[4]){
	int ReturnValue=0;
	if((point[0]+point[2])<25)
	   ReturnValue=1;
	else
	   ReturnValue=0;

	return ReturnValue;
}