#include "stdafx.h"
#include <iostream>
#include <math.h>
#include "Consola.h"
#include "cardGameRule.h"
#include <iomanip>
#include <string>
using namespace std;

void welcome(int Choose[1]){
	settitle("~~¾ôµP~~Press any key then press ENTER to restart. Press Ctrl+Z to exit.");
	setsizexy(80,35);
	textcolor(LIGHTRED);
	gotoxy(1,7);
	cout<<"         ¡´       ¡´¡´¡´¡´¡´¡´¡´               ¡´    ¡´        ¡´"<<endl;
	cout<<"         ¡´             ¡´                     ¡´    ¡´      ¡´"<<endl;
	cout<<"     ¡´¡´¡´¡´¡´   ¡´¡´¡´¡´¡´¡´¡´               ¡´¡´¡´¡´    ¡´¡´¡´¡´¡´¡´¡´"<<endl;
	cout<<"         ¡´           ¡´  ¡´                   ¡´          ¡´    ¡´    ¡´"<<endl;
	cout<<"       ¡´¡´¡´       ¡´ ¡´¡´ ¡´                 ¡´          ¡´¡´¡´¡´¡´¡´¡´"<<endl;
	cout<<"     ¡´  ¡´  ¡´   ¡´   ¡´¡´   ¡´               ¡´          ¡´    ¡´    ¡´"<<endl;
	cout<<"         ¡´       ¡´¡´¡´¡´¡´¡´¡´               ¡´          ¡´¡´¡´¡´¡´¡´¡´"<<endl;
	cout<<"         ¡´       ¡´          ¡´               ¡´¡´¡´¡´      ¡´  ¡´"<<endl;
	cout<<"         ¡´       ¡´  ¡´¡´¡´  ¡´               ¡´    ¡´   ¡´¡´¡´¡´¡´¡´¡´¡´"<<endl;
	cout<<"         ¡´       ¡´  ¡´  ¡´  ¡´               ¡´    ¡´          ¡´"<<endl;
	cout<<"         ¡´       ¡´  ¡´¡´¡´  ¡´               ¡´    ¡´          ¡´"<<endl;
	cout<<"         ¡´       ¡´          ¡´               ¡´    ¡´          ¡´"<<endl;

	textcolor(YELLOW);
	gotoxy(10,27);
	cout<<"Choose your mode: ";
	gotoxy(10,28);
	cout<<"Press 1 for normal mode";
	gotoxy(10,29);
	cout<<"Press 2 for Crazy mode";
	gotoxy(28,27);
	cin>>Choose[0];

	gotoxy(45,28);
	string LOADING="NOW LOADING...";                  //A window console decoration
	int j=0;                                          //Used for counting
	for(int i=0;i<=35;i++){
	  cout<<LOADING.at(j);
	  j++;
	  if(j==14){
		  gotoxy(45,28);
		  cout<<"              ";
		  j=0; 
		  gotoxy(45,28);
	  }

	delay(250);                                     //Set time delay.
	}
	gotoxy(45,28);                                    
	cout<<"LOADING COMPLETE.";
	delay(500);

}

void scorepad(int point[4]){                        //Show player's statues and points,
	                                                //linked to void printCards
	 textbackground(LIGHTGREEN);
	 textcolor(LIGHTRED);
	 gotoxy(36,12);
	  cout<<"PLAYER  1";                            //statue
	 gotoxy(36,13);
	  cout<<"Point: "<<setw(2)<<point[0];           //point

	 gotoxy(17,17);
	  cout<<"PLAYER  2";
	 gotoxy(17,18);
	  cout<<"Point: "<<setw(2)<<point[1];

	 gotoxy(36,22);
	  cout<<"PLAYER  3";
	 gotoxy(36,23);
	  cout<<"Point: "<<setw(2)<<point[2];

	 gotoxy(56,17);
	  cout<<"PLAYER  4";
	 gotoxy(56,18);
	  cout<<"Point: "<<setw(2)<<point[3];

     gotoxy(40,17);
	 textbackground(GREEN);
	 textcolor(GREEN);
}

void cardlook(){                                    //the card display on the console
	                                                //linked with void window
	char cardHorizon[6][10]={1,1,1,1,1,1,1,1,1,1,   //draw card by array
		                     1,0,0,0,0,0,0,0,0,1,
							 1,0,0,0,0,0,0,0,0,1,
							 1,0,0,0,0,0,0,0,0,1,
	                         1,0,0,0,0,0,0,0,0,1,
	                         1,0,0,0,0,0,0,0,0,1};
	char cardVertical[5][12]={1,1,1,1,1,1,1,1,1,1,1,1,
		                      0,0,0,0,0,0,0,0,0,0,0,1,
		                      0,0,0,0,0,0,0,0,0,0,0,1,
                              0,0,0,0,0,0,0,0,0,0,0,1,
							  1,1,1,1,1,1,1,1,1,1,1,1};

	
	for(int k=1;k<=37;k=k+3)
	 for(int i=0;i<6;i++){
		 gotoxy(17+k,30+i);
		 for(int j=0;j<10;j++){
			 textbackground(BLACK);
			 if(cardHorizon[i][j]==1) 
				 cout<<" ";
			 else{
				 textbackground(WHITE);
				 cout<<" ";
			 }
		 }
	 }
	 
	 	for(int k=1;k<=37;k=k+3)
	 for(int i=5;i>=0;i--){
		 gotoxy(54-k,6-i);
		 for(int j=9;j>=0;j--){
			 textbackground(BLACK);
			 if(cardHorizon[i][j]==1) 
				 cout<<" ";
			 else{
				 textbackground(WHITE);
				 cout<<" ";
			 }
		 }
	 }

	for(int k=1;k<=25;k=k+2)
	 for(int i=0;i<5;i++){
		 gotoxy(1,3+k+i);
		 for(int j=0;j<12;j++){
			 textbackground(BLACK);
			 if(cardVertical[i][j]==1) 
				 cout<<" ";
			 else{
				 textbackground(WHITE);
				 cout<<" ";
			 }
		 }
	 }

	for(int k=1;k<=25;k=k+2)
	 for(int i=0;i<5;i++){
		 gotoxy(69,33-k-i);
		 for(int j=11;j>=0;j--){
			 textbackground(BLACK);
			 if(cardVertical[i][j]==1) 
				 cout<<" ";
			 else{
				 textbackground(WHITE);
				 cout<<" ";
			 }
		 }
	 }
	 
}

void cardPattern(char playerCardType){              //cardPattern with diamond...
	                                                //linked with void printCards
	if(playerCardType==3||playerCardType==4){       //changing the cout color
		textcolor(LIGHTRED);
		cout<<playerCardType;
		textcolor(BLACK);
	}
	else if(playerCardType==6||playerCardType==5)
		cout<<playerCardType;
}

void printCards(int player[4][13], int point[4], char playerCardType[4][13]){
	 textbackground(WHITE);                        //Print out the cards
	 textcolor(BLACK);
     for(int i=0;i<4;i++)
		 for(int j=0;j<13;j++){
			 if(i==0){                             //listing player name
				 gotoxy(60-j*3,5);
				 cout<<setw(2);
				 cardvalue(player[i][j]);          //show cardvalue
				 gotoxy(61-j*3,4);
				 cardPattern(playerCardType[i][j]);//show pattern
			 }
			 else if(i==1){
				 gotoxy(10,5+j*2);
				 cout<<setw(2);
				 cardvalue(player[i][j]);
				 gotoxy(9,5+j*2);
				 cardPattern(playerCardType[i][j]);
			 }
			 else if(i==2){
				 gotoxy(19+j*3,31);
				 cardvalue(player[i][j]);
				 gotoxy(19+j*3,32);
				 cardPattern(playerCardType[i][j]);
			 }
			 else if(i==3){
				 gotoxy(70,31-j*2);
				 cardvalue(player[i][j]);
				 gotoxy(72,31-j*2);
				 cardPattern(playerCardType[i][j]);
			 }
		 }

    scorepad(point);
}


void window(){                                    //The main looking window

	textbackground(GREEN);
	_setcursortype(1);                            //show no cursor
	for(int i=1;i<=(80*35);i++)                   //change background to Green
		cout<<" ";
	

	cardlook();

    
    
}



