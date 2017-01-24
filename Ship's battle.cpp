#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

char** PlFieldVis;
char** PlField;
char** PCFieldVis;
char** PCField;
int** PlShipsData;
int** PCShipsData;
int* ValPl;
int* ValPC;
int CurPosPC0=-1,CurPosPC1=-1;
bool lt=false,rt=false,up=false,down=false;
int dir=-1;
bool g=false;
int Player=0,PC=0;
void ShowFields()
{
	cout<<"      Player's field                   PC's field         \n";
	cout<<"   ---------------------          ---------------------\n";
	cout<<" 1 |"<<PlFieldVis[0][0]<<"|"<<PlFieldVis[0][1]<<"|"<<PlFieldVis[0][2]<<"|"<<PlFieldVis[0][3]<<"|"<<PlFieldVis[0][4]<<"|"<<PlFieldVis[0][5]<<"|";
	cout<<PlFieldVis[0][6]<<"|"<<PlFieldVis[0][7]<<"|"<<PlFieldVis[0][8]<<"|"<<PlFieldVis[0][9]<<"|        1 |"<<PCFieldVis[0][0]<<"|"<<PCFieldVis[0][1];
	cout<<"|"<<PCFieldVis[0][2]<<"|"<<PCFieldVis[0][3]<<"|"<<PCFieldVis[0][4]<<"|"<<PCFieldVis[0][5]<<"|"<<PCFieldVis[0][6]<<"|"<<PCFieldVis[0][7];
	cout<<"|"<<PCFieldVis[0][8]<<"|"<<PCFieldVis[0][9]<<"|"<<endl;
	
	cout<<"   ---------------------          ---------------------\n";
	cout<<" 2 |"<<PlFieldVis[1][0]<<"|"<<PlFieldVis[1][1]<<"|"<<PlFieldVis[1][2]<<"|"<<PlFieldVis[1][3]<<"|"<<PlFieldVis[1][4]<<"|"<<PlFieldVis[1][5]<<"|";
	cout<<PlFieldVis[1][6]<<"|"<<PlFieldVis[1][7]<<"|"<<PlFieldVis[1][8]<<"|"<<PlFieldVis[1][9]<<"|        2 |"<<PCFieldVis[1][0]<<"|"<<PCFieldVis[1][1];
	cout<<"|"<<PCFieldVis[1][2]<<"|"<<PCFieldVis[1][3]<<"|"<<PCFieldVis[1][4]<<"|"<<PCFieldVis[1][5]<<"|"<<PCFieldVis[1][6]<<"|"<<PCFieldVis[1][7];
	cout<<"|"<<PCFieldVis[1][8]<<"|"<<PCFieldVis[1][9]<<"|"<<endl;
	
	cout<<"   ---------------------          ---------------------\n";
	cout<<" 3 |"<<PlFieldVis[2][0]<<"|"<<PlFieldVis[2][1]<<"|"<<PlFieldVis[2][2]<<"|"<<PlFieldVis[2][3]<<"|"<<PlFieldVis[2][4]<<"|"<<PlFieldVis[2][5]<<"|";
	cout<<PlFieldVis[2][6]<<"|"<<PlFieldVis[2][7]<<"|"<<PlFieldVis[2][8]<<"|"<<PlFieldVis[2][9]<<"|        3 |"<<PCFieldVis[2][0]<<"|"<<PCFieldVis[2][1];
	cout<<"|"<<PCFieldVis[2][2]<<"|"<<PCFieldVis[2][3]<<"|"<<PCFieldVis[2][4]<<"|"<<PCFieldVis[2][5]<<"|"<<PCFieldVis[2][6]<<"|"<<PCFieldVis[2][7];
	cout<<"|"<<PCFieldVis[2][8]<<"|"<<PCFieldVis[2][9]<<"|"<<endl;
	
	cout<<"   ---------------------          ---------------------\n";
	cout<<" 4 |"<<PlFieldVis[3][0]<<"|"<<PlFieldVis[3][1]<<"|"<<PlFieldVis[3][2]<<"|"<<PlFieldVis[3][3]<<"|"<<PlFieldVis[3][4]<<"|"<<PlFieldVis[3][5]<<"|";
	cout<<PlFieldVis[3][6]<<"|"<<PlFieldVis[3][7]<<"|"<<PlFieldVis[3][8]<<"|"<<PlFieldVis[3][9]<<"|        4 |"<<PCFieldVis[3][0]<<"|"<<PCFieldVis[3][1];
	cout<<"|"<<PCFieldVis[3][2]<<"|"<<PCFieldVis[3][3]<<"|"<<PCFieldVis[3][4]<<"|"<<PCFieldVis[3][5]<<"|"<<PCFieldVis[3][6]<<"|"<<PCFieldVis[3][7];
	cout<<"|"<<PCFieldVis[3][8]<<"|"<<PCFieldVis[3][9]<<"|"<<endl;
	
	cout<<"   ---------------------          ---------------------\n";
	cout<<" 5 |"<<PlFieldVis[4][0]<<"|"<<PlFieldVis[4][1]<<"|"<<PlFieldVis[4][2]<<"|"<<PlFieldVis[4][3]<<"|"<<PlFieldVis[4][4]<<"|"<<PlFieldVis[4][5]<<"|";
	cout<<PlFieldVis[4][6]<<"|"<<PlFieldVis[4][7]<<"|"<<PlFieldVis[4][8]<<"|"<<PlFieldVis[4][9]<<"|        5 |"<<PCFieldVis[4][0]<<"|"<<PCFieldVis[4][1];
	cout<<"|"<<PCFieldVis[4][2]<<"|"<<PCFieldVis[4][3]<<"|"<<PCFieldVis[4][4]<<"|"<<PCFieldVis[4][5]<<"|"<<PCFieldVis[4][6]<<"|"<<PCFieldVis[4][7];
	cout<<"|"<<PCFieldVis[4][8]<<"|"<<PCFieldVis[4][9]<<"|"<<endl;
	
	cout<<"   ---------------------          ---------------------\n";
	cout<<" 6 |"<<PlFieldVis[5][0]<<"|"<<PlFieldVis[5][1]<<"|"<<PlFieldVis[5][2]<<"|"<<PlFieldVis[5][3]<<"|"<<PlFieldVis[5][4]<<"|"<<PlFieldVis[5][5]<<"|";
	cout<<PlFieldVis[5][6]<<"|"<<PlFieldVis[5][7]<<"|"<<PlFieldVis[5][8]<<"|"<<PlFieldVis[5][9]<<"|        6 |"<<PCFieldVis[5][0]<<"|"<<PCFieldVis[5][1];
	cout<<"|"<<PCFieldVis[5][2]<<"|"<<PCFieldVis[5][3]<<"|"<<PCFieldVis[5][4]<<"|"<<PCFieldVis[5][5]<<"|"<<PCFieldVis[5][6]<<"|"<<PCFieldVis[5][7];
	cout<<"|"<<PCFieldVis[5][8]<<"|"<<PCFieldVis[5][9]<<"|"<<endl;
	
	cout<<"   ---------------------          ---------------------\n";
	cout<<" 7 |"<<PlFieldVis[6][0]<<"|"<<PlFieldVis[6][1]<<"|"<<PlFieldVis[6][2]<<"|"<<PlFieldVis[6][3]<<"|"<<PlFieldVis[6][4]<<"|"<<PlFieldVis[6][5]<<"|";
	cout<<PlFieldVis[6][6]<<"|"<<PlFieldVis[6][7]<<"|"<<PlFieldVis[6][8]<<"|"<<PlFieldVis[6][9]<<"|        7 |"<<PCFieldVis[6][0]<<"|"<<PCFieldVis[6][1];
	cout<<"|"<<PCFieldVis[6][2]<<"|"<<PCFieldVis[6][3]<<"|"<<PCFieldVis[6][4]<<"|"<<PCFieldVis[6][5]<<"|"<<PCFieldVis[6][6]<<"|"<<PCFieldVis[6][7];
	cout<<"|"<<PCFieldVis[6][8]<<"|"<<PCFieldVis[6][9]<<"|"<<endl;
	
	cout<<"   ---------------------          ---------------------\n";
	cout<<" 8 |"<<PlFieldVis[7][0]<<"|"<<PlFieldVis[7][1]<<"|"<<PlFieldVis[7][2]<<"|"<<PlFieldVis[7][3]<<"|"<<PlFieldVis[7][4]<<"|"<<PlFieldVis[7][5]<<"|";
	cout<<PlFieldVis[7][6]<<"|"<<PlFieldVis[7][7]<<"|"<<PlFieldVis[7][8]<<"|"<<PlFieldVis[7][9]<<"|        8 |"<<PCFieldVis[7][0]<<"|"<<PCFieldVis[7][1];
	cout<<"|"<<PCFieldVis[7][2]<<"|"<<PCFieldVis[7][3]<<"|"<<PCFieldVis[7][4]<<"|"<<PCFieldVis[7][5]<<"|"<<PCFieldVis[7][6]<<"|"<<PCFieldVis[7][7];
	cout<<"|"<<PCFieldVis[7][8]<<"|"<<PCFieldVis[7][9]<<"|"<<endl;
	
	cout<<"   ---------------------          ---------------------\n";
	cout<<" 9 |"<<PlFieldVis[8][0]<<"|"<<PlFieldVis[8][1]<<"|"<<PlFieldVis[8][2]<<"|"<<PlFieldVis[8][3]<<"|"<<PlFieldVis[8][4]<<"|"<<PlFieldVis[8][5]<<"|";
	cout<<PlFieldVis[8][6]<<"|"<<PlFieldVis[8][7]<<"|"<<PlFieldVis[8][8]<<"|"<<PlFieldVis[8][9]<<"|        9 |"<<PCFieldVis[8][0]<<"|"<<PCFieldVis[8][1];
	cout<<"|"<<PCFieldVis[8][2]<<"|"<<PCFieldVis[8][3]<<"|"<<PCFieldVis[8][4]<<"|"<<PCFieldVis[8][5]<<"|"<<PCFieldVis[8][6]<<"|"<<PCFieldVis[8][7];
	cout<<"|"<<PCFieldVis[8][8]<<"|"<<PCFieldVis[8][9]<<"|"<<endl;
	
	cout<<"   ---------------------          ---------------------\n";
	cout<<" 10|"<<PlFieldVis[9][0]<<"|"<<PlFieldVis[9][1]<<"|"<<PlFieldVis[9][2]<<"|"<<PlFieldVis[9][3]<<"|"<<PlFieldVis[9][4]<<"|"<<PlFieldVis[9][5]<<"|";
	cout<<PlFieldVis[9][6]<<"|"<<PlFieldVis[9][7]<<"|"<<PlFieldVis[9][8]<<"|"<<PlFieldVis[9][9]<<"|        10|"<<PCFieldVis[9][0]<<"|"<<PCFieldVis[9][1];
	cout<<"|"<<PCFieldVis[9][2]<<"|"<<PCFieldVis[9][3]<<"|"<<PCFieldVis[9][4]<<"|"<<PCFieldVis[9][5]<<"|"<<PCFieldVis[9][6]<<"|"<<PCFieldVis[9][7];
	cout<<"|"<<PCFieldVis[9][8]<<"|"<<PCFieldVis[9][9]<<"|"<<endl;
	
	cout<<"   ---------------------          ---------------------\n";
	cout<<"    1 2 3 4 5 6 7 8 9 10           1 2 3 4 5 6 7 8 9 10 \n";
}
void AutoFill(char** a)
{
	int k=rand()%2;
	switch (k)
	{
		case 0: {  
			       int k1,k2;
			       for (int i=0;;i++)
			       {
			       	k1=rand()%10;
			       	k2=rand()%7;
			       	if ((a[k1][k2]!='-')&&(a[k1][k2]!='@')&&(a[k1][k2+1]!='-')&&(a[k1][k2+1]!='@')&&(a[k1][k2+2]!='-')&&
					   (a[k1][k2+2]!='@')&&(a[k1][k2+3]!='-')&&(a[k1][k2+3]!='@'))
			       	   {
			       		  a[k1][k2]='@';
			       		  a[k1][k2+1]='@';
			       		  a[k1][k2+2]='@';
			       		  a[k1][k2+3]='@';
			       		  if (a==PCField) 
			       		  {
			       		  	PCShipsData[0][0]=10;PCShipsData[1][0]=k1*10+k2;
			       		  	PCShipsData[0][1]=20;PCShipsData[1][1]=k1*10+k2+1;
			       		  	PCShipsData[0][2]=30;PCShipsData[1][2]=k1*10+k2+2;
			       		  	PCShipsData[0][3]=40;PCShipsData[1][3]=k1*10+k2+3;
						  }
						  else
						  {
						  	PlShipsData[0][0]=10;PlShipsData[1][0]=k1*10+k2;
			       		  	PlShipsData[0][1]=20;PlShipsData[1][1]=k1*10+k2+1;
			       		  	PlShipsData[0][2]=30;PlShipsData[1][2]=k1*10+k2+2;
			       		  	PlShipsData[0][3]=40;PlShipsData[1][3]=k1*10+k2+3;
						  }
			       		  if ((k2-1)>=0) a[k1][k2-1]='-';
			       		  if (((k1-1)>=0)&&((k2-1)>=0)) a[k1-1][k2-1]='-';
			       		  if (((k1+1)<10)&&((k2-1)>=0)) a[k1+1][k2-1]='-';
			       		  if ((k1-1)>=0) {a[k1-1][k2]='-';a[k1-1][k2+1]='-';a[k1-1][k2+2]='-';a[k1-1][k2+3]='-';}
			       		  if ((k1+1)<10) {a[k1+1][k2]='-';a[k1+1][k2+1]='-';a[k1+1][k2+2]='-';a[k1+1][k2+3]='-';}
			       		  if (((k1-1)>=0)&&((k2+4)<10)) a[k1-1][k2+4]='-';
			       		  if ((k2+4)<10) a[k1][k2+4]='-';
			       		  if (((k1+1)<10)&&((k2+4)<10)) a[k1+1][k2+4]='-'; 
						  break;
					   }
				   }
			       break;
	        	}
	    case 1: {  
	    	       int k1,k2;
			       for (int i=0;;i++)
			       {
			       	k1=rand()%7;
			       	k2=rand()%10;
			       	if ((a[k1][k2]!='-')&&(a[k1][k2]!='@')&&(a[k1+1][k2]!='-')&&(a[k1+1][k2]!='@')&&(a[k1+2][k2]!='-')&&
					   (a[k1+2][k2]!='@')&&(a[k1+3][k2]!='-')&&(a[k1+3][k2]!='@'))
			       	   {
			       		  a[k1][k2]='@';
			       		  a[k1+1][k2]='@';
			       		  a[k1+2][k2]='@';
			       		  a[k1+3][k2]='@';
			       		  if (a==PCField) 
			       		  {
			       		  	PCShipsData[0][0]=10;PCShipsData[1][0]=k1*10+k2;
			       		  	PCShipsData[0][1]=20;PCShipsData[1][1]=(k1+1)*10+k2;
			       		  	PCShipsData[0][2]=30;PCShipsData[1][2]=(k1+2)*10+k2;
			       		  	PCShipsData[0][3]=40;PCShipsData[1][3]=(k1+3)*10+k2;
						  }
						  else
						  {
						  	PlShipsData[0][0]=10;PlShipsData[1][0]=k1*10+k2;
			       		  	PlShipsData[0][1]=20;PlShipsData[1][1]=(k1+1)*10+k2;
			       		  	PlShipsData[0][2]=30;PlShipsData[1][2]=(k1+2)*10+k2;
			       		  	PlShipsData[0][3]=40;PlShipsData[1][3]=(k1+3)*10+k2;
						  }
			       		  if ((k1-1)>=0) a[k1-1][k2]='-';
			       		  if (((k1-1)>=0)&&((k2-1)>=0)) a[k1-1][k2-1]='-';
			       		  if (((k1-1)>=0)&&((k2+1)<10)) a[k1-1][k2+1]='-';
			       		  if ((k2-1)>=0) {a[k1][k2-1]='-';a[k1+1][k2-1]='-';a[k1+2][k2-1]='-';a[k1+3][k2-1]='-';}
			       		  if ((k2+1)<10) {a[k1][k2+1]='-';a[k1+1][k2+1]='-';a[k1+2][k2+1]='-';a[k1+3][k2+1]='-';}
			       		  if (((k2-1)>=0)&&((k1+4)<10)) a[k1+4][k2-1]='-';
			       		  if ((k1+4)<10) a[k1+4][k2]='-';
			       		  if (((k1+4)<10)&&((k2+1)<10)) a[k1+4][k2+1]='-'; 
						  break;
					   }
				   }
		        	break;
	        	}
	}
	
	for (int j=0;j<2;j++)
	{
		k=rand()%2;
		switch (k)
	   {
		case 0: {  
			       int k1,k2;
			       for (int i=0;;i++)
			       {
			       	k1=rand()%10;
			       	k2=rand()%8;
			       	if ((a[k1][k2]!='-')&&(a[k1][k2]!='@')&&(a[k1][k2+1]!='-')&&(a[k1][k2+1]!='@')&&
					   (a[k1][k2+2]!='-')&&(a[k1][k2+2]!='@'))
			       	   {
			       		  a[k1][k2]='@';
			       		  a[k1][k2+1]='@';
			       		  a[k1][k2+2]='@';
			       		  if (a==PCField) 
			       		  {
			       		  	PCShipsData[0][3*(1+j)+1]=11+j;PCShipsData[1][3*(1+j)+1]=k1*10+k2;
			       		  	PCShipsData[0][3*(1+j)+2]=21+j;PCShipsData[1][3*(1+j)+2]=k1*10+k2+1;
			       		  	PCShipsData[0][3*(1+j)+3]=31+j;PCShipsData[1][3*(1+j)+3]=k1*10+k2+2;
			       		  }
						  else
						  {
						  	PlShipsData[0][3*(1+j)+1]=11+j;PlShipsData[1][3*(1+j)+1]=k1*10+k2;
			       		  	PlShipsData[0][3*(1+j)+2]=21+j;PlShipsData[1][3*(1+j)+2]=k1*10+k2+1;
			       		  	PlShipsData[0][3*(1+j)+3]=31+j;PlShipsData[1][3*(1+j)+3]=k1*10+k2+2;
						  }
			       		  if ((k2-1)>=0) a[k1][k2-1]='-';
			       		  if (((k1-1)>=0)&&((k2-1)>=0)) a[k1-1][k2-1]='-';
			       		  if (((k1+1)<10)&&((k2-1)>=0)) a[k1+1][k2-1]='-';
			       		  if ((k1-1)>=0) {a[k1-1][k2]='-';a[k1-1][k2+1]='-';a[k1-1][k2+2]='-';}
			       		  if ((k1+1)<10) {a[k1+1][k2]='-';a[k1+1][k2+1]='-';a[k1+1][k2+2]='-';}
			       		  if (((k1-1)>=0)&&((k2+3)<10)) a[k1-1][k2+3]='-';
			       		  if ((k2+3)<10) a[k1][k2+3]='-';
			       		  if (((k1+1)<10)&&((k2+3)<10)) a[k1+1][k2+3]='-'; 
						  break;
					   }
				   }
			       break;
	        	}
	    case 1: {  
	    	       int k1,k2;
			       for (int i=0;;i++)
			       {
			       	k1=rand()%8;
			       	k2=rand()%10;
			       	if ((a[k1][k2]!='-')&&(a[k1][k2]!='@')&&(a[k1+1][k2]!='-')&&(a[k1+1][k2]!='@')&&
					   (a[k1+2][k2]!='-')&&(a[k1+2][k2]!='@'))
			       	   {
			       		  a[k1][k2]='@';
			       		  a[k1+1][k2]='@';
			       		  a[k1+2][k2]='@';
			       		  if (a==PCField) 
			       		  {
			       		  	PCShipsData[0][3*(1+j)+1]=11+j;PCShipsData[1][3*(1+j)+1]=k1*10+k2;
			       		  	PCShipsData[0][3*(1+j)+2]=21+j;PCShipsData[1][3*(1+j)+2]=(k1+1)*10+k2;
			       		  	PCShipsData[0][3*(1+j)+3]=31+j;PCShipsData[1][3*(1+j)+3]=(k1+2)*10+k2;
			       		  }
						  else
						  {
						  	PlShipsData[0][3*(1+j)+1]=11+j;PlShipsData[1][3*(1+j)+1]=k1*10+k2;
			       		  	PlShipsData[0][3*(1+j)+2]=21+j;PlShipsData[1][3*(1+j)+2]=(k1+1)*10+k2;
			       		  	PlShipsData[0][3*(1+j)+3]=31+j;PlShipsData[1][3*(1+j)+3]=(k1+2)*10+k2;
						  }
			       		  if ((k1-1)>=0) a[k1-1][k2]='-';
			       		  if (((k1-1)>=0)&&((k2-1)>=0)) a[k1-1][k2-1]='-';
			       		  if (((k1-1)>=0)&&((k2+1)<10)) a[k1-1][k2+1]='-';
			       		  if ((k2-1)>=0) {a[k1][k2-1]='-';a[k1+1][k2-1]='-';a[k1+2][k2-1]='-';}
			       		  if ((k2+1)<10) {a[k1][k2+1]='-';a[k1+1][k2+1]='-';a[k1+2][k2+1]='-';}
			       		  if (((k2-1)>=0)&&((k1+3)<10)) a[k1+3][k2-1]='-';
			       		  if ((k1+3)<10) a[k1+3][k2]='-';
			       		  if (((k1+3)<10)&&((k2+1)<10)) a[k1+3][k2+1]='-'; 
						  break;
					   }
				   }
		        	break;
	        	}
	    }
	}
	
	for (int j=0;j<3;j++)
	{
		k=rand()%2;
		switch (k)
	   {
		case 0: {  
			       int k1,k2;
			       for (int i=0;;i++)
			       {
			       	k1=rand()%10;
			       	k2=rand()%9;
			       	if ((a[k1][k2]!='-')&&(a[k1][k2]!='@')&&(a[k1][k2+1]!='-')&&(a[k1][k2+1]!='@'))
			       	   {
			       		  a[k1][k2]='@';
			       		  a[k1][k2+1]='@';
			       		  if (a==PCField) 
			       		  {
			       		  	PCShipsData[0][2*(4+j)+2]=13+j;PCShipsData[1][2*(4+j)+2]=k1*10+k2;
			       		  	PCShipsData[0][2*(4+j)+3]=23+j;PCShipsData[1][2*(4+j)+3]=k1*10+k2+1;
			       		  }
						  else
						  {
						  	PlShipsData[0][2*(4+j)+2]=13+j;PlShipsData[1][2*(4+j)+2]=k1*10+k2;
			       		  	PlShipsData[0][2*(4+j)+3]=23+j;PlShipsData[1][2*(4+j)+3]=k1*10+k2+1;
						  }
			       		  if ((k2-1)>=0) a[k1][k2-1]='-';
			       		  if (((k1-1)>=0)&&((k2-1)>=0)) a[k1-1][k2-1]='-';
			       		  if (((k1+1)<10)&&((k2-1)>=0)) a[k1+1][k2-1]='-';
			       		  if ((k1-1)>=0) {a[k1-1][k2]='-';a[k1-1][k2+1]='-';}
			       		  if ((k1+1)<10) {a[k1+1][k2]='-';a[k1+1][k2+1]='-';}
			       		  if (((k1-1)>=0)&&((k2+2)<10)) a[k1-1][k2+2]='-';
			       		  if ((k2+2)<10) a[k1][k2+2]='-';
			       		  if (((k1+1)<10)&&((k2+2)<10)) a[k1+1][k2+2]='-'; 
						  break;
					   }
				   }
			       break;
	        	}
	    case 1: {  
	    	       int k1,k2;
			       for (int i=0;;i++)
			       {
			       	k1=rand()%9;
			       	k2=rand()%10;
			       	if ((a[k1][k2]!='-')&&(a[k1][k2]!='@')&&(a[k1+1][k2]!='-')&&(a[k1+1][k2]!='@'))
			       	   {
			       		  a[k1][k2]='@';
			       		  a[k1+1][k2]='@';
			       		  if (a==PCField) 
			       		  {
			       		  	PCShipsData[0][2*(4+j)+2]=13+j;PCShipsData[1][2*(4+j)+2]=k1*10+k2;
			       		  	PCShipsData[0][2*(4+j)+3]=23+j;PCShipsData[1][2*(4+j)+3]=(k1+1)*10+k2;
			       		  }
						  else
						  {
						  	PlShipsData[0][2*(4+j)+2]=13+j;PlShipsData[1][2*(4+j)+2]=k1*10+k2;
			       		  	PlShipsData[0][2*(4+j)+3]=23+j;PlShipsData[1][2*(4+j)+3]=(k1+1)*10+k2;
						  }
			       		  if ((k1-1)>=0) a[k1-1][k2]='-';
			       		  if (((k1-1)>=0)&&((k2-1)>=0)) a[k1-1][k2-1]='-';
			       		  if (((k1-1)>=0)&&((k2+1)<10)) a[k1-1][k2+1]='-';
			       		  if ((k2-1)>=0) {a[k1][k2-1]='-';a[k1+1][k2-1]='-';}
			       		  if ((k2+1)<10) {a[k1][k2+1]='-';a[k1+1][k2+1]='-';}
			       		  if (((k2-1)>=0)&&((k1+2)<10)) a[k1+2][k2-1]='-';
			       		  if ((k1+2)<10) a[k1+2][k2]='-';
			       		  if (((k1+2)<10)&&((k2+1)<10)) a[k1+2][k2+1]='-'; 
						  break;
					   }
				   }
		        	break;
	        	}
	    }
	}
	
	for (int j=0;j<4;j++)
	{
	    int k1,k2;
		for (int i=0;;i++)
		{
			k1=rand()%10;
			k2=rand()%10;
			if ((a[k1][k2]!='-')&&(a[k1][k2]!='@'))
			    {
			       	a[k1][k2]='@';
			       	if (a==PCField)
			       		{PCShipsData[0][16+j]=16+j;PCShipsData[1][16+j]=k1*10+k2;}
					else
						{PlShipsData[0][16+j]=16+j;PlShipsData[1][16+j]=k1*10+k2;}
			       	if ((k2-1)>=0) a[k1][k2-1]='-';
			       	if (((k1-1)>=0)&&((k2-1)>=0)) a[k1-1][k2-1]='-';
			       	if (((k1+1)<10)&&((k2-1)>=0)) a[k1+1][k2-1]='-';
			       	if ((k1-1)>=0) a[k1-1][k2]='-';
			       	if ((k1+1)<10) a[k1+1][k2]='-';
			       	if (((k1-1)>=0)&&((k2+1)<10)) a[k1-1][k2+1]='-';
			       	if ((k2+1)<10) a[k1][k2+1]='-';
			       	if (((k1+1)<10)&&((k2+1)<10)) a[k1+1][k2+1]='-'; 
					break;
				}
		}
			       
	}
	
	for (int i=0;i<10;i++)
	for (int j=0;j<10;j++)
	if (a[i][j]=='-') a[i][j]=' ';
}
void ManualFill()
{
	int a,b,f;
	bool t=true;
	int min0,min1,max0,max1;
	int** Coord=new int*[2];
	for (int i=0;i<2;i++)
	Coord[i]=new int[4];
	
	for (int j=0;;j++)
	{
		for (int i1=0;i1<10;i1++)
	    for (int j1=0;j1<10;j1++)
	    if (PlField[i1][j1]=='-') PlFieldVis[i1][j1]=' ';
	    else PlFieldVis[i1][j1]=PlField[i1][j1];
		ShowFields();
		for (int i=0;i<4;i++)
		{
			cout<<"Please, input the first coordinate of the "<<i+1<<"-st(-nd,-th) part 4-parts ship.\n";
			f=0;
			cin>>a;
			cin.get();
			if ((a<=0)||(a>10))
			{
				cout<<"You input wrong data. Try again.\n";
				t=false;
				for (int i1=0;i1<10;i1++)
				for (int j1=0;j1<10;j1++)
				PlField[i1][j1]=' ';
				break;
			}
			Coord[f][i]=a-1;
			cout<<"Please, input the second coordinate of the "<<i+1<<"-st(-nd,-th) part 4-parts ship.\n";
			f=1;
			cin>>b;
			cin.get();
			if ((b<=0)||(b>10))
			{
				cout<<"You input wrong data. Try again.\n";
				t=false;
				for (int i1=0;i1<10;i1++)
				for (int j1=0;j1<10;j1++)
				PlField[i1][j1]=' ';
				break;
			}
			Coord[f][i]=b-1;
			PlField[a-1][b-1]='@';
			for (int i1=0;i1<10;i1++)
	        for (int j1=0;j1<10;j1++)
	        if (PlField[i1][j1]=='-') PlFieldVis[i1][j1]=' ';
	        else PlFieldVis[i1][j1]=PlField[i1][j1];
			ShowFields();
		}
		if (!t) 
		{
			t=true;
			continue;
		}
		min0=Coord[0][0];
		max0=Coord[0][0];
		for (int i=1;i<4;i++)
		{
		  if (Coord[0][i]<min0) min0=Coord[0][i];
		  if (Coord[0][i]>max0) max0=Coord[0][i];
		}
		min1=Coord[1][0];
		max1=Coord[1][0];
		for (int i=1;i<4;i++)
		{
		  if (Coord[1][i]<min1) min1=Coord[1][i];
		  if (Coord[1][i]>max1) max1=Coord[1][i];	
		}
		
		if ((((Coord[0][0]==Coord[0][1])&&(Coord[0][0]==Coord[0][2])&&(Coord[0][0]==Coord[0][3]))||
		((Coord[1][0]==Coord[1][1])&&(Coord[1][0]==Coord[1][2])&&(Coord[1][0]==Coord[1][3])))&&
        ((min0>=0)&&(min0<10)&&(max0>=0)&&(max0<10)&&(min1>=0)&&(min1<10)&&(max1>=0)&&(max1<10))&&
        (((max0-min0)==3)||((max1-min1)==3)))
        {
        	if ((Coord[0][0]==Coord[0][1])&&(Coord[0][0]==Coord[0][2])&&(Coord[0][0]==Coord[0][3]))
        	{
        		int c=Coord[0][0];
        		if ((min1-1)>=0) PlField[c][min1-1]='-';
			    if (((c-1)>=0)&&((min1-1)>=0)) PlField[c-1][min1-1]='-';
			    if (((c+1)<10)&&((min1-1)>=0)) PlField[c+1][min1-1]='-';
			    if ((c-1)>=0) {PlField[c-1][min1]='-';PlField[c-1][min1+1]='-';PlField[c-1][min1+2]='-';PlField[c-1][min1+3]='-';}
			    if ((c+1)<10) {PlField[c+1][min1]='-';PlField[c+1][min1+1]='-';PlField[c+1][min1+2]='-';PlField[c+1][min1+3]='-';}
			    if (((c-1)>=0)&&((min1+4)<10)) PlField[c-1][min1+4]='-';
			    if ((min1+4)<10) PlField[c][min1+4]='-';
			    if  (((c+1)<10)&&((min1+4)<10)) PlField[c+1][min1+4]='-';
			    PlShipsData[0][0]=10;PlShipsData[1][0]=c*10+min1;
			    PlShipsData[0][1]=20;PlShipsData[1][1]=c*10+min1+1;
			    PlShipsData[0][2]=30;PlShipsData[1][2]=c*10+min1+2;
			    PlShipsData[0][3]=40;PlShipsData[1][3]=c*10+min1+3;
			}
			if ((Coord[1][0]==Coord[1][1])&&(Coord[1][0]==Coord[1][2])&&(Coord[1][0]==Coord[1][3]))
			{
				int c=Coord[1][0];
			    if ((min0-1)>=0) PlField[min0-1][c]='-';
			    if (((min0-1)>=0)&&((c-1)>=0)) PlField[min0-1][c-1]='-';
			    if (((min0-1)>=0)&&((c+1)<10)) PlField[min0-1][c+1]='-';
			    if ((c-1)>=0) {PlField[min0][c-1]='-';PlField[min0+1][c-1]='-';PlField[min0+2][c-1]='-';PlField[min0+3][c-1]='-';}
			    if ((c+1)<10) {PlField[min0][c+1]='-';PlField[min0+1][c+1]='-';PlField[min0+2][c+1]='-';PlField[min0+3][c+1]='-';}
			    if (((c-1)>=0)&&((min0+4)<10)) PlField[min0+4][c-1]='-';
			    if ((min0+4)<10) PlField[min0+4][c]='-';
			    if (((min0+4)<10)&&((c+1)<10)) PlField[min0+4][c+1]='-';
				PlShipsData[0][0]=10;PlShipsData[1][0]=min0*10+c;
			    PlShipsData[0][1]=20;PlShipsData[1][1]=(min0+1)*10+c;
			    PlShipsData[0][2]=30;PlShipsData[1][2]=(min0+2)*10+c;
			    PlShipsData[0][3]=40;PlShipsData[1][3]=(min0+3)*10+c;	
			}
			break;
		}
        else 
		{
		    cout<<"You input wrong data. Try again.\n";
		   	PlField[Coord[0][0]][Coord[1][0]]=' ';
		   	PlField[Coord[0][1]][Coord[1][1]]=' ';
		   	PlField[Coord[0][2]][Coord[1][2]]=' ';
		   	PlField[Coord[0][3]][Coord[1][3]]=' ';
		}		
	}
	for (int i=0;i<2;i++)
		   delete []Coord[i];
		   delete []Coord;
		   
	cout<<"\nAnd now we shall input coordinates of two 3-parts ships.\n";
	for (int l=0;l<2;l++)
  {
  	cout<<"\nPlease, input coordinates of the "<<l+1<<"-st(-nd,-th) ship.\n";
	Coord=new int*[2];
	for (int i=0;i<2;i++)
	Coord[i]=new int[3];	
	for (int j=0;;j++)
	{
		for (int i1=0;i1<10;i1++)
	    for (int j1=0;j1<10;j1++)
	    if (PlField[i1][j1]=='-') PlFieldVis[i1][j1]=' ';
	    else PlFieldVis[i1][j1]=PlField[i1][j1];
		ShowFields();
		for (int i=0;i<3;i++)
		{
			cout<<"Please, input the first coordinate of the "<<i+1<<"-st(-nd,-th) part 3-parts ship.\n";
			f=0;
			cin>>a;
			cin.get();
			if ((a<=0)||(a>10))
			{
				cout<<"You input wrong data. Try again.\n";
				t=false;
				for (int i1=0;i1<i;i1++)
				PlField[Coord[f][i1]][Coord[f+1][i1]]=' ';
				break;
			}
			Coord[f][i]=a-1;
			cout<<"Please, input the second coordinate of the "<<i+1<<"-st(-nd,-th) part 3-parts ship.\n";
			f=1;
			cin>>b;
			cin.get();
			if ((b<=0)||(b>10))
			{
				cout<<"You input wrong data. Try again.\n";
				t=false;
				for (int i1=0;i1<i;i1++)
				PlField[Coord[f-1][i1]][Coord[f][i1]]=' ';
				break;
			}
			Coord[f][i]=b-1;
			if ((PlField[a-1][b-1]!='-')&&(PlField[a-1][b-1]!='@'))
			PlField[a-1][b-1]='@';
			else 
			{
				cout<<"You input wrong data. Try again.\n";
				t=false;
				for (int i1=0;i1<i;i1++)
				PlField[Coord[f-1][i1]][Coord[f][i1]]=' ';
				break;
			}
			for (int i1=0;i1<10;i1++)
	        for (int j1=0;j1<10;j1++)
	        if (PlField[i1][j1]=='-') PlFieldVis[i1][j1]=' ';
	        else PlFieldVis[i1][j1]=PlField[i1][j1];
			ShowFields();
		}
		if (!t) 
		{
			t=true;
			continue;
		}
		min0=Coord[0][0];
		max0=Coord[0][0];
		for (int i=1;i<3;i++)
		{
		  if (Coord[0][i]<min0) min0=Coord[0][i];
		  if (Coord[0][i]>max0) max0=Coord[0][i];
		}
		min1=Coord[1][0];
		max1=Coord[1][0];
		for (int i=1;i<3;i++)
		{
		  if (Coord[1][i]<min1) min1=Coord[1][i];
		  if (Coord[1][i]>max1) max1=Coord[1][i];	
		}
		
		if ((((Coord[0][0]==Coord[0][1])&&(Coord[0][0]==Coord[0][2]))||
		((Coord[1][0]==Coord[1][1])&&(Coord[1][0]==Coord[1][2])))&&
        ((min0>=0)&&(min0<10)&&(max0>=0)&&(max0<10)&&(min1>=0)&&(min1<10)&&(max1>=0)&&(max1<10))&&
        (((max0-min0)==2)||((max1-min1)==2)))
        {
        	if ((Coord[0][0]==Coord[0][1])&&(Coord[0][0]==Coord[0][2]))
        	{
        		int c=Coord[0][0];
        		if ((min1-1)>=0) PlField[c][min1-1]='-';
			    if (((c-1)>=0)&&((min1-1)>=0)) PlField[c-1][min1-1]='-';
			    if (((c+1)<10)&&((min1-1)>=0)) PlField[c+1][min1-1]='-';
			    if ((c-1)>=0) {PlField[c-1][min1]='-';PlField[c-1][min1+1]='-';PlField[c-1][min1+2]='-';}
			    if ((c+1)<10) {PlField[c+1][min1]='-';PlField[c+1][min1+1]='-';PlField[c+1][min1+2]='-';}
			    if (((c-1)>=0)&&((min1+3)<10)) PlField[c-1][min1+3]='-';
			    if ((min1+3)<10) PlField[c][min1+3]='-';
			    if  (((c+1)<10)&&((min1+3)<10)) PlField[c+1][min1+3]='-';
			    PlShipsData[0][3*(1+l)+1]=11+l;PlShipsData[1][3*(1+l)+1]=c*10+min1;
			    PlShipsData[0][3*(1+l)+2]=21+l;PlShipsData[1][3*(1+l)+2]=c*10+min1+1;
			    PlShipsData[0][3*(1+l)+3]=31+l;PlShipsData[1][3*(1+l)+3]=c*10+min1+2;
			}
			if ((Coord[1][0]==Coord[1][1])&&(Coord[1][0]==Coord[1][2]))
			{
				int c=Coord[1][0];
			    if ((min0-1)>=0) PlField[min0-1][c]='-';
			    if (((min0-1)>=0)&&((c-1)>=0)) PlField[min0-1][c-1]='-';
			    if (((min0-1)>=0)&&((c+1)<10)) PlField[min0-1][c+1]='-';
			    if ((c-1)>=0) {PlField[min0][c-1]='-';PlField[min0+1][c-1]='-';PlField[min0+2][c-1]='-';}
			    if ((c+1)<10) {PlField[min0][c+1]='-';PlField[min0+1][c+1]='-';PlField[min0+2][c+1]='-';}
			    if (((c-1)>=0)&&((min0+3)<10)) PlField[min0+3][c-1]='-';
			    if ((min0+3)<10) PlField[min0+3][c]='-';
			    if (((min0+3)<10)&&((c+1)<10)) PlField[min0+3][c+1]='-';	
			    PlShipsData[0][3*(1+l)+1]=11+l;PlShipsData[1][3*(1+l)+1]=min0*10+c;
			    PlShipsData[0][3*(1+l)+2]=21+l;PlShipsData[1][3*(1+l)+2]=(min0+1)*10+c;
			    PlShipsData[0][3*(1+l)+3]=31+l;PlShipsData[1][3*(1+l)+3]=(min0+2)*10+c;
			}
			break;
		}
        else 
		{
		    cout<<"You input wrong data. Try again.\n";
		   	PlField[Coord[0][0]][Coord[1][0]]=' ';
		   	PlField[Coord[0][1]][Coord[1][1]]=' ';
		   	PlField[Coord[0][2]][Coord[1][2]]=' ';
		}		
	}
	for (int i=0;i<2;i++)
		   delete []Coord[i];
		   delete []Coord;	 
  }
  
	cout<<"\nAnd now we shall input coordinates of three 2-parts ships.\n";
	for (int l=0;l<3;l++)
  {
  	cout<<"\nPlease, input coordinates of the "<<l+1<<"-st(-nd,-th) ship.\n";
	Coord=new int*[2];
	for (int i=0;i<2;i++)
	Coord[i]=new int[2];	
	for (int j=0;;j++)
	{
		for (int i1=0;i1<10;i1++)
	    for (int j1=0;j1<10;j1++)
	    if (PlField[i1][j1]=='-') PlFieldVis[i1][j1]=' ';
	    else PlFieldVis[i1][j1]=PlField[i1][j1];
		ShowFields();
		for (int i=0;i<2;i++)
		{
			cout<<"Please, input the first coordinate of the "<<i+1<<"-st(-nd,-th) part 2-parts ship.\n";
			f=0;
			cin>>a;
			cin.get();
			if ((a<=0)||(a>10))
			{
				cout<<"You input wrong data. Try again.\n";
				t=false;
				for (int i1=0;i1<i;i1++)
				PlField[Coord[f][i1]][Coord[f+1][i1]]=' ';
				break;
			}
			Coord[f][i]=a-1;
			cout<<"Please, input the second coordinate of the "<<i+1<<"-st(-nd,-th) part 2-parts ship.\n";
			f=1;
			cin>>b;
			cin.get();
			if ((b<=0)||(b>10))
			{
				cout<<"You input wrong data. Try again.\n";
				t=false;
				for (int i1=0;i1<i;i1++)
				PlField[Coord[f-1][i1]][Coord[f][i1]]=' ';
				break;
			}
			Coord[f][i]=b-1;
			if ((PlField[a-1][b-1]!='-')&&(PlField[a-1][b-1]!='@'))
			PlField[a-1][b-1]='@';
			else 
			{
				cout<<"You input wrong data. Try again.\n";
				t=false;
				for (int i1=0;i1<i;i1++)
				PlField[Coord[f-1][i1]][Coord[f][i1]]=' ';
				break;
			}
			for (int i1=0;i1<10;i1++)
	        for (int j1=0;j1<10;j1++)
	        if (PlField[i1][j1]=='-') PlFieldVis[i1][j1]=' ';
	        else PlFieldVis[i1][j1]=PlField[i1][j1];
			ShowFields();
		}
		if (!t) 
		{
			t=true;
			continue;
		}
		min0=Coord[0][0];
		max0=Coord[0][0];
		for (int i=1;i<2;i++)
		{
		  if (Coord[0][i]<min0) min0=Coord[0][i];
		  if (Coord[0][i]>max0) max0=Coord[0][i];
		}
		min1=Coord[1][0];
		max1=Coord[1][0];
		for (int i=1;i<2;i++)
		{
		  if (Coord[1][i]<min1) min1=Coord[1][i];
		  if (Coord[1][i]>max1) max1=Coord[1][i];	
		}
		
		if ((((Coord[0][0]==Coord[0][1]))||
		((Coord[1][0]==Coord[1][1])))&&
        ((min0>=0)&&(min0<10)&&(max0>=0)&&(max0<10)&&(min1>=0)&&(min1<10)&&(max1>=0)&&(max1<10))&&
        (((max0-min0)==1)||((max1-min1)==1)))
        {
        	if ((Coord[0][0]==Coord[0][1]))
        	{
        		int c=Coord[0][0];
        		if ((min1-1)>=0) PlField[c][min1-1]='-';
			    if (((c-1)>=0)&&((min1-1)>=0)) PlField[c-1][min1-1]='-';
			    if (((c+1)<10)&&((min1-1)>=0)) PlField[c+1][min1-1]='-';
			    if ((c-1)>=0) {PlField[c-1][min1]='-';PlField[c-1][min1+1]='-';}
			    if ((c+1)<10) {PlField[c+1][min1]='-';PlField[c+1][min1+1]='-';}
			    if (((c-1)>=0)&&((min1+2)<10)) PlField[c-1][min1+2]='-';
			    if ((min1+2)<10) PlField[c][min1+2]='-';
			    if  (((c+1)<10)&&((min1+2)<10)) PlField[c+1][min1+2]='-';
			    PlShipsData[0][2*(4+l)+2]=13+l;PlShipsData[1][2*(4+l)+2]=c*10+min1;
			    PlShipsData[0][2*(4+l)+3]=23+l;PlShipsData[1][2*(4+l)+3]=c*10+min1+1;
			}
			if ((Coord[1][0]==Coord[1][1]))
			{
				int c=Coord[1][0];
			    if ((min0-1)>=0) PlField[min0-1][c]='-';
			    if (((min0-1)>=0)&&((c-1)>=0)) PlField[min0-1][c-1]='-';
			    if (((min0-1)>=0)&&((c+1)<10)) PlField[min0-1][c+1]='-';
			    if ((c-1)>=0) {PlField[min0][c-1]='-';PlField[min0+1][c-1]='-';}
			    if ((c+1)<10) {PlField[min0][c+1]='-';PlField[min0+1][c+1]='-';}
			    if (((c-1)>=0)&&((min0+2)<10)) PlField[min0+2][c-1]='-';
			    if ((min0+2)<10) PlField[min0+2][c]='-';
			    if (((min0+2)<10)&&((c+1)<10)) PlField[min0+2][c+1]='-';
				PlShipsData[0][2*(4+l)+2]=13+l;PlShipsData[1][2*(4+l)+2]=min0*10+c;
			    PlShipsData[0][2*(4+l)+3]=23+l;PlShipsData[1][2*(4+l)+3]=(min0+1)*10+c;	
			}
			break;
		}
        else 
		{
		    cout<<"You input wrong data. Try again.\n";
		   	PlField[Coord[0][0]][Coord[1][0]]=' ';
		   	PlField[Coord[0][1]][Coord[1][1]]=' ';
		}		
	}
	for (int i=0;i<2;i++)
		   delete []Coord[i];
		   delete []Coord;	 
  }
  
	cout<<"\nAnd now we shall input four 1-parts ships.\n";
	int* Coord1;
	for (int l=0;l<4;l++)
  {
  	cout<<"\nPlease, input coordinates of the "<<l+1<<"-st(-nd,-th) ship.\n";
	Coord1=new int[2];
	for (int j=0;;j++)
	{
		for (int i1=0;i1<10;i1++)
	    for (int j1=0;j1<10;j1++)
	    if (PlField[i1][j1]=='-') PlFieldVis[i1][j1]=' ';
	    else PlFieldVis[i1][j1]=PlField[i1][j1];
		ShowFields();
			cout<<"Please, input the first coordinate of the 1-parts ship.\n";
			cin>>a;
			cin.get();
			if ((a<=0)||(a>10))
			{
				cout<<"You input wrong data. Try again.\n";
				continue;
			}
			Coord1[0]=a-1;
			cout<<"Please, input the second coordinate of the 1-parts ship.\n";
			cin>>b;
			cin.get();
			if ((b<=0)||(b>10))
			{
				cout<<"You input wrong data. Try again.\n";
				continue;
			}
			Coord1[1]=b-1;
			if ((PlField[a-1][b-1]!='-')&&(PlField[a-1][b-1]!='@'))
			PlField[a-1][b-1]='@';
			else 
			{
				cout<<"You input wrong data. Try again.\n";
				continue;
			}
			for (int i1=0;i1<10;i1++)
	        for (int j1=0;j1<10;j1++)
	        if (PlField[i1][j1]=='-') PlFieldVis[i1][j1]=' ';
	        else PlFieldVis[i1][j1]=PlField[i1][j1];
			ShowFields();
		
			min1=Coord1[1];
			int c=Coord1[0];
            if ((min1-1)>=0) PlField[c][min1-1]='-';
	     	if (((c-1)>=0)&&((min1-1)>=0)) PlField[c-1][min1-1]='-';
		    if (((c+1)<10)&&((min1-1)>=0)) PlField[c+1][min1-1]='-';
		    if ((c-1)>=0) {PlField[c-1][min1]='-';}
		    if ((c+1)<10) {PlField[c+1][min1]='-';}
		    if (((c-1)>=0)&&((min1+1)<10)) PlField[c-1][min1+1]='-';
		    if ((min1+1)<10) PlField[c][min1+1]='-';
		    if  (((c+1)<10)&&((min1+1)<10)) PlField[c+1][min1+1]='-';
		    PlShipsData[0][16+l]=16+l;PlShipsData[1][16+l]=c*10+min1;
		    break;
	}
		delete []Coord1;	 
  }
  for (int i1=0;i1<10;i1++)
  for (int j1=0;j1<10;j1++)
  if (PlField[i1][j1]=='-') PlField[i1][j1]=' ';
}
bool IsDestroyed(char** a,int b,int c)
{
	if (a==PlField) 
	{
		for (int i=0;i<20;i++)
		if (PlShipsData[1][i]==(b*10+c))
		ValPl[(PlShipsData[0][i])%10]--;
		for (int i=0;i<10;i++)
		if (ValPl[i]==0)
		{
			ValPl[i]=-1;
			return true;
		}
	}
	if (a==PCField) 
	{
		for (int i=0;i<20;i++)
		if (PCShipsData[1][i]==(b*10+c))
		ValPC[(PCShipsData[0][i])%10]--;
		for (int i=0;i<10;i++)
		if (ValPC[i]==0)
		{
			ValPC[i]=-1;
			return true;
		}
	}
	return false;
}

void PCShot(int a,int b)
{ 
	if (PlField[a-1][b-1]!='@')
	{
		PlField[a-1][b-1]='-';
		PlFieldVis[a-1][b-1]=PlField[a-1][b-1];
		g=false;
		ShowFields();
		cout<<"\nPC didn't hit'! Let's do your shot'!\n";
		switch (dir)
		{
			case 0: {lt=false; break;}
			case 1: {rt=false; break;}
			case 2: {up=false; break;}
			case 3: {down=false; break;}
		}
		dir=-1;
		return;
	}
	if (IsDestroyed(PlField,a-1,b-1))
	{
		CurPosPC0=-1;CurPosPC1=-1;dir=-1;
		lt=false;rt=false;up=false;down=false;
		PlField[a-1][b-1]='X';
		PC++;
		int FirstEl,LastEl;
		for (int i=0;i<20;i++)
		{
			if (PlShipsData[1][i]==((a-1)*10+b-1))
			{
			int j=PlShipsData[0][i]%10;
			switch(j)
			{
				case 0:
				       {
				       	 FirstEl=PlShipsData[1][0];
						 LastEl=PlShipsData[1][3];
						 int k1=FirstEl/10;
						 int k2=FirstEl%10;
						 if ((FirstEl/10)==(LastEl/10))
						 {
						 	if ((k2-1)>=0) PlField[k1][k2-1]='-';
			       		    if (((k1-1)>=0)&&((k2-1)>=0)) PlField[k1-1][k2-1]='-';
			       		    if (((k1+1)<10)&&((k2-1)>=0)) PlField[k1+1][k2-1]='-';
			       		    if ((k1-1)>=0) {PlField[k1-1][k2]='-';PlField[k1-1][k2+1]='-';PlField[k1-1][k2+2]='-';PlField[k1-1][k2+3]='-';}
			       		    if ((k1+1)<10) {PlField[k1+1][k2]='-';PlField[k1+1][k2+1]='-';PlField[k1+1][k2+2]='-';PlField[k1+1][k2+3]='-';}
			       		    if (((k1-1)>=0)&&((k2+4)<10)) PlField[k1-1][k2+4]='-';
			       		    if ((k2+4)<10) PlField[k1][k2+4]='-';
			       		    if (((k1+1)<10)&&((k2+4)<10)) PlField[k1+1][k2+4]='-';
						 }
						 else
						 {
						  if ((k1-1)>=0) PlField[k1-1][k2]='-';
			       		  if (((k1-1)>=0)&&((k2-1)>=0)) PlField[k1-1][k2-1]='-';
			       		  if (((k1-1)>=0)&&((k2+1)<10)) PlField[k1-1][k2+1]='-';
			       		  if ((k2-1)>=0) {PlField[k1][k2-1]='-';PlField[k1+1][k2-1]='-';PlField[k1+2][k2-1]='-';PlField[k1+3][k2-1]='-';}
			       		  if ((k2+1)<10) {PlField[k1][k2+1]='-';PlField[k1+1][k2+1]='-';PlField[k1+2][k2+1]='-';PlField[k1+3][k2+1]='-';}
			       		  if (((k2-1)>=0)&&((k1+4)<10)) PlField[k1+4][k2-1]='-';
			       		  if ((k1+4)<10) PlField[k1+4][k2]='-';
			       		  if (((k1+4)<10)&&((k2+1)<10)) PlField[k1+4][k2+1]='-'; 
						 }	 
					     break;
				       }
				case 1: 
				       {
				          FirstEl=PlShipsData[1][4];
						  LastEl=PlShipsData[1][6];
						  int k1=FirstEl/10;
						  int k2=FirstEl%10;
						 if ((FirstEl/10)==(LastEl/10))	
						 {
						  if ((k2-1)>=0) PlField[k1][k2-1]='-';
			       		  if (((k1-1)>=0)&&((k2-1)>=0)) PlField[k1-1][k2-1]='-';
			       		  if (((k1+1)<10)&&((k2-1)>=0)) PlField[k1+1][k2-1]='-';
			       		  if ((k1-1)>=0) {PlField[k1-1][k2]='-';PlField[k1-1][k2+1]='-';PlField[k1-1][k2+2]='-';}
			       		  if ((k1+1)<10) {PlField[k1+1][k2]='-';PlField[k1+1][k2+1]='-';PlField[k1+1][k2+2]='-';}
			       		  if (((k1-1)>=0)&&((k2+3)<10)) PlField[k1-1][k2+3]='-';
			       		  if ((k2+3)<10) PlField[k1][k2+3]='-';
			       		  if (((k1+1)<10)&&((k2+3)<10)) PlField[k1+1][k2+3]='-'; 
						 }
						 else
						 {
						  if ((k1-1)>=0) PlField[k1-1][k2]='-';
			       		  if (((k1-1)>=0)&&((k2-1)>=0)) PlField[k1-1][k2-1]='-';
			       		  if (((k1-1)>=0)&&((k2+1)<10)) PlField[k1-1][k2+1]='-';
			       		  if ((k2-1)>=0) {PlField[k1][k2-1]='-';PlField[k1+1][k2-1]='-';PlField[k1+2][k2-1]='-';}
			       		  if ((k2+1)<10) {PlField[k1][k2+1]='-';PlField[k1+1][k2+1]='-';PlField[k1+2][k2+1]='-';}
			       		  if (((k2-1)>=0)&&((k1+3)<10)) PlField[k1+3][k2-1]='-';
			       		  if ((k1+3)<10) PlField[k1+3][k2]='-';
			       		  if (((k1+3)<10)&&((k2+1)<10)) PlField[k1+3][k2+1]='-';
						 }
					    break;
			           }
			    case 2: 
				       {
				          FirstEl=PlShipsData[1][7];
						  LastEl=PlShipsData[1][9];
						  int k1=FirstEl/10;
						  int k2=FirstEl%10;
						 if ((FirstEl/10)==(LastEl/10))	
						 {
						  if ((k2-1)>=0) PlField[k1][k2-1]='-';
			       		  if (((k1-1)>=0)&&((k2-1)>=0)) PlField[k1-1][k2-1]='-';
			       		  if (((k1+1)<10)&&((k2-1)>=0)) PlField[k1+1][k2-1]='-';
			       		  if ((k1-1)>=0) {PlField[k1-1][k2]='-';PlField[k1-1][k2+1]='-';PlField[k1-1][k2+2]='-';}
			       		  if ((k1+1)<10) {PlField[k1+1][k2]='-';PlField[k1+1][k2+1]='-';PlField[k1+1][k2+2]='-';}
			       		  if (((k1-1)>=0)&&((k2+3)<10)) PlField[k1-1][k2+3]='-';
			       		  if ((k2+3)<10) PlField[k1][k2+3]='-';
			       		  if (((k1+1)<10)&&((k2+3)<10)) PlField[k1+1][k2+3]='-'; 
						 }
						 else
						 {
						  if ((k1-1)>=0) PlField[k1-1][k2]='-';
			       		  if (((k1-1)>=0)&&((k2-1)>=0)) PlField[k1-1][k2-1]='-';
			       		  if (((k1-1)>=0)&&((k2+1)<10)) PlField[k1-1][k2+1]='-';
			       		  if ((k2-1)>=0) {PlField[k1][k2-1]='-';PlField[k1+1][k2-1]='-';PlField[k1+2][k2-1]='-';}
			       		  if ((k2+1)<10) {PlField[k1][k2+1]='-';PlField[k1+1][k2+1]='-';PlField[k1+2][k2+1]='-';}
			       		  if (((k2-1)>=0)&&((k1+3)<10)) PlField[k1+3][k2-1]='-';
			       		  if ((k1+3)<10) PlField[k1+3][k2]='-';
			       		  if (((k1+3)<10)&&((k2+1)<10)) PlField[k1+3][k2+1]='-';
						 }
					    break;
			           }
			    case 3: 
				       {
				          FirstEl=PlShipsData[1][10];
						  LastEl=PlShipsData[1][11];
						  int k1=FirstEl/10;
						  int k2=FirstEl%10;
						 if ((FirstEl/10)==(LastEl/10))	
						 {
						  if ((k2-1)>=0) PlField[k1][k2-1]='-';
			       		  if (((k1-1)>=0)&&((k2-1)>=0)) PlField[k1-1][k2-1]='-';
			       		  if (((k1+1)<10)&&((k2-1)>=0)) PlField[k1+1][k2-1]='-';
			       		  if ((k1-1)>=0) {PlField[k1-1][k2]='-';PlField[k1-1][k2+1]='-';}
			       		  if ((k1+1)<10) {PlField[k1+1][k2]='-';PlField[k1+1][k2+1]='-';}
			       		  if (((k1-1)>=0)&&((k2+2)<10)) PlField[k1-1][k2+2]='-';
			       		  if ((k2+2)<10) PlField[k1][k2+2]='-';
			       		  if  (((k1+1)<10)&&((k2+2)<10)) PlField[k1+1][k2+2]='-'; 
						 }
						 else
						 {
						  if ((k1-1)>=0) PlField[k1-1][k2]='-';
			       		  if (((k1-1)>=0)&&((k2-1)>=0)) PlField[k1-1][k2-1]='-';
			       		  if (((k1-1)>=0)&&((k2+1)<10)) PlField[k1-1][k2+1]='-';
			       		  if ((k2-1)>=0) {PlField[k1][k2-1]='-';PlField[k1+1][k2-1]='-';}
			       		  if ((k2+1)<10) {PlField[k1][k2+1]='-';PlField[k1+1][k2+1]='-';}
			       		  if (((k2-1)>=0)&&((k1+2)<10)) PlField[k1+2][k2-1]='-';
			       		  if ((k1+2)<10) PlField[k1+2][k2]='-';
			       		  if (((k1+2)<10)&&((k2+1)<10)) PlField[k1+2][k2+1]='-'; 
						 }
					    break;
			           }  
				 case 4: 
				       {
				          FirstEl=PlShipsData[1][12];
						  LastEl=PlShipsData[1][13];
						  int k1=FirstEl/10;
						  int k2=FirstEl%10;
						 if ((FirstEl/10)==(LastEl/10))	
						 {
						  if ((k2-1)>=0) PlField[k1][k2-1]='-';
			       		  if (((k1-1)>=0)&&((k2-1)>=0)) PlField[k1-1][k2-1]='-';
			       		  if (((k1+1)<10)&&((k2-1)>=0)) PlField[k1+1][k2-1]='-';
			       		  if ((k1-1)>=0) {PlField[k1-1][k2]='-';PlField[k1-1][k2+1]='-';}
			       		  if ((k1+1)<10) {PlField[k1+1][k2]='-';PlField[k1+1][k2+1]='-';}
			       		  if (((k1-1)>=0)&&((k2+2)<10)) PlField[k1-1][k2+2]='-';
			       		  if ((k2+2)<10) PlField[k1][k2+2]='-';
			       		  if  (((k1+1)<10)&&((k2+2)<10)) PlField[k1+1][k2+2]='-'; 
						 }
						 else
						 {
						  if ((k1-1)>=0) PlField[k1-1][k2]='-';
			       		  if (((k1-1)>=0)&&((k2-1)>=0)) PlField[k1-1][k2-1]='-';
			       		  if (((k1-1)>=0)&&((k2+1)<10)) PlField[k1-1][k2+1]='-';
			       		  if ((k2-1)>=0) {PlField[k1][k2-1]='-';PlField[k1+1][k2-1]='-';}
			       		  if ((k2+1)<10) {PlField[k1][k2+1]='-';PlField[k1+1][k2+1]='-';}
			       		  if (((k2-1)>=0)&&((k1+2)<10)) PlField[k1+2][k2-1]='-';
			       		  if ((k1+2)<10) PlField[k1+2][k2]='-';
			       		  if (((k1+2)<10)&&((k2+1)<10)) PlField[k1+2][k2+1]='-'; 
						 }
					    break;
			           }
				 case 5: 
				       {
				          FirstEl=PlShipsData[1][14];
						  LastEl=PlShipsData[1][15];
						  int k1=FirstEl/10;
						  int k2=FirstEl%10;
						 if ((FirstEl/10)==(LastEl/10))	
						 {
						  if ((k2-1)>=0) PlField[k1][k2-1]='-';
			       		  if (((k1-1)>=0)&&((k2-1)>=0)) PlField[k1-1][k2-1]='-';
			       		  if (((k1+1)<10)&&((k2-1)>=0)) PlField[k1+1][k2-1]='-';
			       		  if ((k1-1)>=0) {PlField[k1-1][k2]='-';PlField[k1-1][k2+1]='-';}
			       		  if ((k1+1)<10) {PlField[k1+1][k2]='-';PlField[k1+1][k2+1]='-';}
			       		  if (((k1-1)>=0)&&((k2+2)<10)) PlField[k1-1][k2+2]='-';
			       		  if ((k2+2)<10) PlField[k1][k2+2]='-';
			       		  if  (((k1+1)<10)&&((k2+2)<10)) PlField[k1+1][k2+2]='-'; 
						 }
						 else
						 {
						  if ((k1-1)>=0) PlField[k1-1][k2]='-';
			       		  if (((k1-1)>=0)&&((k2-1)>=0)) PlField[k1-1][k2-1]='-';
			       		  if (((k1-1)>=0)&&((k2+1)<10)) PlField[k1-1][k2+1]='-';
			       		  if ((k2-1)>=0) {PlField[k1][k2-1]='-';PlField[k1+1][k2-1]='-';}
			       		  if ((k2+1)<10) {PlField[k1][k2+1]='-';PlField[k1+1][k2+1]='-';}
			       		  if (((k2-1)>=0)&&((k1+2)<10)) PlField[k1+2][k2-1]='-';
			       		  if ((k1+2)<10) PlField[k1+2][k2]='-';
			       		  if (((k1+2)<10)&&((k2+1)<10)) PlField[k1+2][k2+1]='-'; 
						 }
					    break;
			           }
				 case 6: 
				       {
				          FirstEl=PlShipsData[1][16];
						  int k1=FirstEl/10;
						  int k2=FirstEl%10;
						  if ((k2-1)>=0) PlField[k1][k2-1]='-';
			       	      if (((k1-1)>=0)&&((k2-1)>=0)) PlField[k1-1][k2-1]='-';
			       	      if (((k1+1)<10)&&((k2-1)>=0)) PlField[k1+1][k2-1]='-';
			       	      if ((k1-1)>=0) PlField[k1-1][k2]='-';
			       	      if ((k1+1)<10) PlField[k1+1][k2]='-';
			       	      if (((k1-1)>=0)&&((k2+1)<10)) PlField[k1-1][k2+1]='-';
			       	      if ((k2+1)<10) PlField[k1][k2+1]='-';
			       	      if (((k1+1)<10)&&((k2+1)<10)) PlField[k1+1][k2+1]='-'; 
					      break;
			           }
				 case 7: 
				       {
				          FirstEl=PlShipsData[1][17];
						  int k1=FirstEl/10;
						  int k2=FirstEl%10;
						  if ((k2-1)>=0) PlField[k1][k2-1]='-';
			       	      if (((k1-1)>=0)&&((k2-1)>=0)) PlField[k1-1][k2-1]='-';
			       	      if (((k1+1)<10)&&((k2-1)>=0)) PlField[k1+1][k2-1]='-';
			       	      if ((k1-1)>=0) PlField[k1-1][k2]='-';
			       	      if ((k1+1)<10) PlField[k1+1][k2]='-';
			       	      if (((k1-1)>=0)&&((k2+1)<10)) PlField[k1-1][k2+1]='-';
			       	      if ((k2+1)<10) PlField[k1][k2+1]='-';
			       	      if (((k1+1)<10)&&((k2+1)<10)) PlField[k1+1][k2+1]='-'; 
					      break;
			           } 
				 case 8: 
				       {
				          FirstEl=PlShipsData[1][18];
						  int k1=FirstEl/10;
						  int k2=FirstEl%10;
						  if ((k2-1)>=0) PlField[k1][k2-1]='-';
			       	      if (((k1-1)>=0)&&((k2-1)>=0)) PlField[k1-1][k2-1]='-';
			       	      if (((k1+1)<10)&&((k2-1)>=0)) PlField[k1+1][k2-1]='-';
			       	      if ((k1-1)>=0) PlField[k1-1][k2]='-';
			       	      if ((k1+1)<10) PlField[k1+1][k2]='-';
			       	      if (((k1-1)>=0)&&((k2+1)<10)) PlField[k1-1][k2+1]='-';
			       	      if ((k2+1)<10) PlField[k1][k2+1]='-';
			       	      if (((k1+1)<10)&&((k2+1)<10)) PlField[k1+1][k2+1]='-'; 
					      break;
			           } 
				 case 9: 
				       {
				          FirstEl=PlShipsData[1][19];
						  int k1=FirstEl/10;
						  int k2=FirstEl%10;
						  if ((k2-1)>=0) PlField[k1][k2-1]='-';
			       	      if (((k1-1)>=0)&&((k2-1)>=0)) PlField[k1-1][k2-1]='-';
			       	      if (((k1+1)<10)&&((k2-1)>=0)) PlField[k1+1][k2-1]='-';
			       	      if ((k1-1)>=0) PlField[k1-1][k2]='-';
			       	      if ((k1+1)<10) PlField[k1+1][k2]='-';
			       	      if (((k1-1)>=0)&&((k2+1)<10)) PlField[k1-1][k2+1]='-';
			       	      if ((k2+1)<10) PlField[k1][k2+1]='-';
			       	      if (((k1+1)<10)&&((k2+1)<10)) PlField[k1+1][k2+1]='-'; 
					      break;
			           }       	     	         	           	     	          	          	               
			}
		   }
		}
		for (int l1=0;l1<10;l1++)
		for (int l2=0;l2<10;l2++)
		PlFieldVis[l1][l2]=PlField[l1][l2];
		ShowFields();
		cout<<"\nShip is destroyed!";
		if (PC<10) cout<<" PC shoots again!\n"; else cout<<endl;
		g=true;
		return;
	}
	if (CurPosPC0==-1) CurPosPC0=(a-1)*10+b-1;
	else CurPosPC1=(a-1)*10+b-1;
    g=true;
    if (CurPosPC1==-1)
    {
    	if (((b-1)>0)&&(PlFieldVis[a-1][b-2]!='-')) lt=true;
	    if (((b+1)<=10)&&(PlFieldVis[a-1][b]!='-')) rt=true;
	    if (((a-1)>0)&&(PlFieldVis[a-2][b-1]!='-')) up=true;
	    if (((a+1)<=10)&&(PlFieldVis[a][b-1]!='-')) down=true;
	}
	else
	{
		if (CurPosPC0/10==CurPosPC1/10)
		{
			up=false;
			down=false;
			if ((CurPosPC1%10>CurPosPC0%10)&&(((CurPosPC1%10+1)>9)||(PlFieldVis[CurPosPC1/10][CurPosPC1%10+1]=='-')))
			rt=false;
			if ((CurPosPC1%10<CurPosPC0%10)&&(((CurPosPC1%10-1)<0)||(PlFieldVis[CurPosPC1/10][CurPosPC1%10-1]=='-')))
			lt=false;
		}
		if (CurPosPC0%10==CurPosPC1%10)
		{
			lt=false;
			rt=false;
			if ((CurPosPC1/10<CurPosPC0/10)&&(((CurPosPC1/10-1)<0)||(PlFieldVis[CurPosPC1/10-1][CurPosPC1%10]=='-')))
			up=false;
			if ((CurPosPC1/10>CurPosPC0/10)&&(((CurPosPC1/10+1)>9)||(PlFieldVis[CurPosPC1/10+1][CurPosPC1%10]=='-')))
			down=false;
		}
	}
	PlField[a-1][b-1]='X';
	PlFieldVis[a-1][b-1]=PlField[a-1][b-1];
	ShowFields();
	dir=-1;
	cout<<"Accurate shot!";
	if (PC<10) cout<<" PC shoots again!\n"; else cout<<endl;
	return;
}
void PlShot(int a,int b)
{
	if (PCField[a-1][b-1]!='@')
	{
		PCFieldVis[a-1][b-1]='-';
		g=true;
		ShowFields();
		cout<<"\nYou didn't hit! And now PC is shooting!\n";
		return;
	}
	if (IsDestroyed(PCField,a-1,b-1))
	{
		PCField[a-1][b-1]='X';
	    PCFieldVis[a-1][b-1]=PCField[a-1][b-1];
		Player++;
		int FirstEl,LastEl;
		for (int i=0;i<20;i++)
		{
			if (PCShipsData[1][i]==((a-1)*10+b-1))
			{
			int j=PCShipsData[0][i]%10;
			switch(j)
			{
				case 0:
				       {
				       	 FirstEl=PCShipsData[1][0];
						 LastEl=PCShipsData[1][3];
						 int k1=FirstEl/10;
						 int k2=FirstEl%10;
						 if ((FirstEl/10)==(LastEl/10))
						 {
						 	if ((k2-1)>=0) PCFieldVis[k1][k2-1]='-';
			       		    if (((k1-1)>=0)&&((k2-1)>=0)) PCFieldVis[k1-1][k2-1]='-';
			       		    if (((k1+1)<10)&&((k2-1)>=0)) PCFieldVis[k1+1][k2-1]='-';
			       		    if ((k1-1)>=0) {PCFieldVis[k1-1][k2]='-';PCFieldVis[k1-1][k2+1]='-';PCFieldVis[k1-1][k2+2]='-';PCFieldVis[k1-1][k2+3]='-';}
			       		    if ((k1+1)<10) {PCFieldVis[k1+1][k2]='-';PCFieldVis[k1+1][k2+1]='-';PCFieldVis[k1+1][k2+2]='-';PCFieldVis[k1+1][k2+3]='-';}
			       		    if (((k1-1)>=0)&&((k2+4)<10)) PCFieldVis[k1-1][k2+4]='-';
			       		    if ((k2+4)<10) PCFieldVis[k1][k2+4]='-';
			       		    if (((k1+1)<10)&&((k2+4)<10)) PCFieldVis[k1+1][k2+4]='-';
						 }
						 else
						 {
						  if ((k1-1)>=0) PCFieldVis[k1-1][k2]='-';
			       		  if (((k1-1)>=0)&&((k2-1)>=0)) PCFieldVis[k1-1][k2-1]='-';
			       		  if (((k1-1)>=0)&&((k2+1)<10)) PCFieldVis[k1-1][k2+1]='-';
			       		  if ((k2-1)>=0) {PCFieldVis[k1][k2-1]='-';PCFieldVis[k1+1][k2-1]='-';PCFieldVis[k1+2][k2-1]='-';PCFieldVis[k1+3][k2-1]='-';}
			       		  if ((k2+1)<10) {PCFieldVis[k1][k2+1]='-';PCFieldVis[k1+1][k2+1]='-';PCFieldVis[k1+2][k2+1]='-';PCFieldVis[k1+3][k2+1]='-';}
			       		  if (((k2-1)>=0)&&((k1+4)<10)) PCFieldVis[k1+4][k2-1]='-';
			       		  if ((k1+4)<10) PCFieldVis[k1+4][k2]='-';
			       		  if (((k1+4)<10)&&((k2+1)<10)) PCFieldVis[k1+4][k2+1]='-'; 
						 }	 
					     break;
				       }
				case 1: 
				       {
				          FirstEl=PCShipsData[1][4];
						  LastEl=PCShipsData[1][6];
						  int k1=FirstEl/10;
						  int k2=FirstEl%10;
						 if ((FirstEl/10)==(LastEl/10))	
						 {
						  if ((k2-1)>=0) PCFieldVis[k1][k2-1]='-';
			       		  if (((k1-1)>=0)&&((k2-1)>=0)) PCFieldVis[k1-1][k2-1]='-';
			       		  if (((k1+1)<10)&&((k2-1)>=0)) PCFieldVis[k1+1][k2-1]='-';
			       		  if ((k1-1)>=0) {PCFieldVis[k1-1][k2]='-';PCFieldVis[k1-1][k2+1]='-';PCFieldVis[k1-1][k2+2]='-';}
			       		  if ((k1+1)<10) {PCFieldVis[k1+1][k2]='-';PCFieldVis[k1+1][k2+1]='-';PCFieldVis[k1+1][k2+2]='-';}
			       		  if (((k1-1)>=0)&&((k2+3)<10)) PCFieldVis[k1-1][k2+3]='-';
			       		  if ((k2+3)<10) PCFieldVis[k1][k2+3]='-';
			       		  if (((k1+1)<10)&&((k2+3)<10)) PCFieldVis[k1+1][k2+3]='-'; 
						 }
						 else
						 {
						  if ((k1-1)>=0) PCFieldVis[k1-1][k2]='-';
			       		  if (((k1-1)>=0)&&((k2-1)>=0)) PCFieldVis[k1-1][k2-1]='-';
			       		  if (((k1-1)>=0)&&((k2+1)<10)) PCFieldVis[k1-1][k2+1]='-';
			       		  if ((k2-1)>=0) {PCFieldVis[k1][k2-1]='-';PCFieldVis[k1+1][k2-1]='-';PCFieldVis[k1+2][k2-1]='-';}
			       		  if ((k2+1)<10) {PCFieldVis[k1][k2+1]='-';PCFieldVis[k1+1][k2+1]='-';PCFieldVis[k1+2][k2+1]='-';}
			       		  if (((k2-1)>=0)&&((k1+3)<10)) PCFieldVis[k1+3][k2-1]='-';
			       		  if ((k1+3)<10) PCFieldVis[k1+3][k2]='-';
			       		  if (((k1+3)<10)&&((k2+1)<10)) PCFieldVis[k1+3][k2+1]='-';
						 }
					    break;
			           }
			    case 2: 
				       {
				          FirstEl=PCShipsData[1][7];
						  LastEl=PCShipsData[1][9];
						  int k1=FirstEl/10;
						  int k2=FirstEl%10;
						 if ((FirstEl/10)==(LastEl/10))	
						 {
						  if ((k2-1)>=0) PCFieldVis[k1][k2-1]='-';
			       		  if (((k1-1)>=0)&&((k2-1)>=0)) PCFieldVis[k1-1][k2-1]='-';
			       		  if (((k1+1)<10)&&((k2-1)>=0)) PCFieldVis[k1+1][k2-1]='-';
			       		  if ((k1-1)>=0) {PCFieldVis[k1-1][k2]='-';PCFieldVis[k1-1][k2+1]='-';PCFieldVis[k1-1][k2+2]='-';}
			       		  if ((k1+1)<10) {PCFieldVis[k1+1][k2]='-';PCFieldVis[k1+1][k2+1]='-';PCFieldVis[k1+1][k2+2]='-';}
			       		  if (((k1-1)>=0)&&((k2+3)<10)) PCFieldVis[k1-1][k2+3]='-';
			       		  if ((k2+3)<10) PCFieldVis[k1][k2+3]='-';
			       		  if (((k1+1)<10)&&((k2+3)<10)) PCFieldVis[k1+1][k2+3]='-'; 
						 }
						 else
						 {
						  if ((k1-1)>=0) PCFieldVis[k1-1][k2]='-';
			       		  if (((k1-1)>=0)&&((k2-1)>=0)) PCFieldVis[k1-1][k2-1]='-';
			       		  if (((k1-1)>=0)&&((k2+1)<10)) PCFieldVis[k1-1][k2+1]='-';
			       		  if ((k2-1)>=0) {PCFieldVis[k1][k2-1]='-';PCFieldVis[k1+1][k2-1]='-';PCFieldVis[k1+2][k2-1]='-';}
			       		  if ((k2+1)<10) {PCFieldVis[k1][k2+1]='-';PCFieldVis[k1+1][k2+1]='-';PCFieldVis[k1+2][k2+1]='-';}
			       		  if (((k2-1)>=0)&&((k1+3)<10)) PCFieldVis[k1+3][k2-1]='-';
			       		  if ((k1+3)<10) PCFieldVis[k1+3][k2]='-';
			       		  if (((k1+3)<10)&&((k2+1)<10)) PCFieldVis[k1+3][k2+1]='-';
						 }
					    break;
			           }
			    case 3: 
				       {
				          FirstEl=PCShipsData[1][10];
						  LastEl=PCShipsData[1][11];
						  int k1=FirstEl/10;
						  int k2=FirstEl%10;
						 if ((FirstEl/10)==(LastEl/10))	
						 {
						  if ((k2-1)>=0) PCFieldVis[k1][k2-1]='-';
			       		  if (((k1-1)>=0)&&((k2-1)>=0)) PCFieldVis[k1-1][k2-1]='-';
			       		  if (((k1+1)<10)&&((k2-1)>=0)) PCFieldVis[k1+1][k2-1]='-';
			       		  if ((k1-1)>=0) {PCFieldVis[k1-1][k2]='-';PCFieldVis[k1-1][k2+1]='-';}
			       		  if ((k1+1)<10) {PCFieldVis[k1+1][k2]='-';PCFieldVis[k1+1][k2+1]='-';}
			       		  if (((k1-1)>=0)&&((k2+2)<10)) PCFieldVis[k1-1][k2+2]='-';
			       		  if ((k2+2)<10) PCFieldVis[k1][k2+2]='-';
			       		  if (((k1+1)<10)&&((k2+2)<10)) PCFieldVis[k1+1][k2+2]='-'; 
						 }
						 else
						 {
						  if ((k1-1)>=0) PCFieldVis[k1-1][k2]='-';
			       		  if (((k1-1)>=0)&&((k2-1)>=0)) PCFieldVis[k1-1][k2-1]='-';
			       		  if (((k1-1)>=0)&&((k2+1)<10)) PCFieldVis[k1-1][k2+1]='-';
			       		  if ((k2-1)>=0) {PCFieldVis[k1][k2-1]='-';PCFieldVis[k1+1][k2-1]='-';}
			       		  if ((k2+1)<10) {PCFieldVis[k1][k2+1]='-';PCFieldVis[k1+1][k2+1]='-';}
			       		  if (((k2-1)>=0)&&((k1+2)<10)) PCFieldVis[k1+2][k2-1]='-';
			       		  if ((k1+2)<10) PCFieldVis[k1+2][k2]='-';
			       		  if (((k1+2)<10)&&((k2+1)<10)) PCFieldVis[k1+2][k2+1]='-'; 
						 }
					    break;
			           }  
				 case 4: 
				       {
				          FirstEl=PCShipsData[1][12];
						  LastEl=PCShipsData[1][13];
						  int k1=FirstEl/10;
						  int k2=FirstEl%10;
						 if ((FirstEl/10)==(LastEl/10))	
						 {
						  if ((k2-1)>=0) PCFieldVis[k1][k2-1]='-';
			       		  if (((k1-1)>=0)&&((k2-1)>=0)) PCFieldVis[k1-1][k2-1]='-';
			       		  if (((k1+1)<10)&&((k2-1)>=0)) PCFieldVis[k1+1][k2-1]='-';
			       		  if ((k1-1)>=0) {PCFieldVis[k1-1][k2]='-';PCFieldVis[k1-1][k2+1]='-';}
			       		  if ((k1+1)<10) {PCFieldVis[k1+1][k2]='-';PCFieldVis[k1+1][k2+1]='-';}
			       		  if (((k1-1)>=0)&&((k2+2)<10)) PCFieldVis[k1-1][k2+2]='-';
			       		  if ((k2+2)<10) PCFieldVis[k1][k2+2]='-';
			       		  if (((k1+1)<10)&&((k2+2)<10)) PCFieldVis[k1+1][k2+2]='-'; 
						 }
						 else
						 {
						  if ((k1-1)>=0) PCFieldVis[k1-1][k2]='-';
			       		  if (((k1-1)>=0)&&((k2-1)>=0)) PCFieldVis[k1-1][k2-1]='-';
			       		  if (((k1-1)>=0)&&((k2+1)<10)) PCFieldVis[k1-1][k2+1]='-';
			       		  if ((k2-1)>=0) {PCFieldVis[k1][k2-1]='-';PCFieldVis[k1+1][k2-1]='-';}
			       		  if ((k2+1)<10) {PCFieldVis[k1][k2+1]='-';PCFieldVis[k1+1][k2+1]='-';}
			       		  if (((k2-1)>=0)&&((k1+2)<10)) PCFieldVis[k1+2][k2-1]='-';
			       		  if ((k1+2)<10) PCFieldVis[k1+2][k2]='-';
			       		  if (((k1+2)<10)&&((k2+1)<10)) PCFieldVis[k1+2][k2+1]='-'; 
						 }
					    break;
			           }
				 case 5: 
				       {
				          FirstEl=PCShipsData[1][14];
						  LastEl=PCShipsData[1][15];
						  int k1=FirstEl/10;
						  int k2=FirstEl%10;
						 if ((FirstEl/10)==(LastEl/10))	
						 {
						  if ((k2-1)>=0) PCFieldVis[k1][k2-1]='-';
			       		  if (((k1-1)>=0)&&((k2-1)>=0)) PCFieldVis[k1-1][k2-1]='-';
			       		  if (((k1+1)<10)&&((k2-1)>=0)) PCFieldVis[k1+1][k2-1]='-';
			       		  if ((k1-1)>=0) {PCFieldVis[k1-1][k2]='-';PCFieldVis[k1-1][k2+1]='-';}
			       		  if ((k1+1)<10) {PCFieldVis[k1+1][k2]='-';PCFieldVis[k1+1][k2+1]='-';}
			       		  if (((k1-1)>=0)&&((k2+2)<10)) PCFieldVis[k1-1][k2+2]='-';
			       		  if ((k2+2)<10) PCFieldVis[k1][k2+2]='-';
			       		  if (((k1+1)<10)&&((k2+2)<10)) PCFieldVis[k1+1][k2+2]='-'; 
						 }
						 else
						 {
						  if ((k1-1)>=0) PCFieldVis[k1-1][k2]='-';
			       		  if (((k1-1)>=0)&&((k2-1)>=0)) PCFieldVis[k1-1][k2-1]='-';
			       		  if (((k1-1)>=0)&&((k2+1)<10)) PCFieldVis[k1-1][k2+1]='-';
			       		  if ((k2-1)>=0) {PCFieldVis[k1][k2-1]='-';PCFieldVis[k1+1][k2-1]='-';}
			       		  if ((k2+1)<10) {PCFieldVis[k1][k2+1]='-';PCFieldVis[k1+1][k2+1]='-';}
			       		  if (((k2-1)>=0)&&((k1+2)<10)) PCFieldVis[k1+2][k2-1]='-';
			       		  if ((k1+2)<10) PCFieldVis[k1+2][k2]='-';
			       		  if (((k1+2)<10)&&((k2+1)<10)) PCFieldVis[k1+2][k2+1]='-'; 
						 }
					    break;
			           }
				 case 6: 
				       {
				          FirstEl=PCShipsData[1][16];
						  int k1=FirstEl/10;
						  int k2=FirstEl%10;
						  if ((k2-1)>=0) PCFieldVis[k1][k2-1]='-';
			       	      if (((k1-1)>=0)&&((k2-1)>=0)) PCFieldVis[k1-1][k2-1]='-';
			       	      if (((k1+1)<10)&&((k2-1)>=0)) PCFieldVis[k1+1][k2-1]='-';
			       	      if ((k1-1)>=0) PCFieldVis[k1-1][k2]='-';
			       	      if ((k1+1)<10) PCFieldVis[k1+1][k2]='-';
			       	      if (((k1-1)>=0)&&((k2+1)<10)) PCFieldVis[k1-1][k2+1]='-';
			       	      if ((k2+1)<10) PCFieldVis[k1][k2+1]='-';
			       	      if (((k1+1)<10)&&((k2+1)<10)) PCFieldVis[k1+1][k2+1]='-'; 
					      break;
			           }
				 case 7: 
				       {
				          FirstEl=PCShipsData[1][17];
						  int k1=FirstEl/10;
						  int k2=FirstEl%10;
						  if ((k2-1)>=0) PCFieldVis[k1][k2-1]='-';
			       	      if (((k1-1)>=0)&&((k2-1)>=0)) PCFieldVis[k1-1][k2-1]='-';
			       	      if (((k1+1)<10)&&((k2-1)>=0)) PCFieldVis[k1+1][k2-1]='-';
			       	      if ((k1-1)>=0) PCFieldVis[k1-1][k2]='-';
			       	      if ((k1+1)<10) PCFieldVis[k1+1][k2]='-';
			       	      if (((k1-1)>=0)&&((k2+1)<10)) PCFieldVis[k1-1][k2+1]='-';
			       	      if ((k2+1)<10) PCFieldVis[k1][k2+1]='-';
			       	      if (((k1+1)<10)&&((k2+1)<10)) PCFieldVis[k1+1][k2+1]='-'; 
					      break;
			           } 
				 case 8: 
				       {
				          FirstEl=PCShipsData[1][18];
						  int k1=FirstEl/10;
						  int k2=FirstEl%10;
						  if ((k2-1)>=0) PCFieldVis[k1][k2-1]='-';
			       	      if (((k1-1)>=0)&&((k2-1)>=0)) PCFieldVis[k1-1][k2-1]='-';
			       	      if (((k1+1)<10)&&((k2-1)>=0)) PCFieldVis[k1+1][k2-1]='-';
			       	      if ((k1-1)>=0) PCFieldVis[k1-1][k2]='-';
			       	      if ((k1+1)<10) PCFieldVis[k1+1][k2]='-';
			       	      if (((k1-1)>=0)&&((k2+1)<10)) PCFieldVis[k1-1][k2+1]='-';
			       	      if ((k2+1)<10) PCFieldVis[k1][k2+1]='-';
			       	      if (((k1+1)<10)&&((k2+1)<10)) PCFieldVis[k1+1][k2+1]='-'; 
					      break;
			           } 
				 case 9: 
				       {
				          FirstEl=PCShipsData[1][19];
						  int k1=FirstEl/10;
						  int k2=FirstEl%10;
						  if ((k2-1)>=0) PCFieldVis[k1][k2-1]='-';
			       	      if (((k1-1)>=0)&&((k2-1)>=0)) PCFieldVis[k1-1][k2-1]='-';
			       	      if (((k1+1)<10)&&((k2-1)>=0)) PCFieldVis[k1+1][k2-1]='-';
			       	      if ((k1-1)>=0) PCFieldVis[k1-1][k2]='-';
			       	      if ((k1+1)<10) PCFieldVis[k1+1][k2]='-';
			       	      if (((k1-1)>=0)&&((k2+1)<10)) PCFieldVis[k1-1][k2+1]='-';
			       	      if ((k2+1)<10) PCFieldVis[k1][k2+1]='-';
			       	      if (((k1+1)<10)&&((k2+1)<10)) PCFieldVis[k1+1][k2+1]='-'; 
					      break;
			           }       	     	         	           	     	          	          	               
			}
		   }
		}
		ShowFields();
		cout<<"\nShip is destroyed!";
		if (Player<10) cout<<" You can shoot again!\n"; else cout<<endl;
		g=false;
		return;
	}
    g=false;
	PCField[a-1][b-1]='X';
	PCFieldVis[a-1][b-1]=PCField[a-1][b-1];
	ShowFields();
	cout<<"Accurate shot!";
	if (Player<10) cout<<" You can shoot again!\n"; else cout<<endl;
	return;
}
void Game()
{
	cout<<"Let's start the game! And now the first shooter is ... ";
	int p=rand()%2;
	if (p==0) 
	{
		cout<<"player!\n";
		g=false;
	}
	else 
	{
	   cout<<"PC!\n";
	   g=true;	
	}
	int Pl1,Pl2,PC1,PC2;
	for (int i=0;;i++)
	{
		if(g) 
		{
			cout<<"PC's shot: ";
		   if(!lt&&!rt&&!up&&!down)
		   {
		   	   for (int j=0;;j++)
		      	{
		      	  PC1=rand()%10+1;
		      	  PC2=rand()%10+1;
		      	  if ((PlFieldVis[PC1-1][PC2-1]=='X')||(PlFieldVis[PC1-1][PC2-1]=='-')) continue;
		      	  cout<<PC1<<";"<<PC2<<endl;
		      	  PCShot(PC1,PC2);
		      	  break;
		        }
		        cout<<"Game score (player - PC):   "<<Player<<":"<<PC<<endl;
		      	if ((Player>PC)&&(Player==10)) 
		      	{
		      	   cout<<"Game over! You win! Congratulations!\n";
				   break;	
				}
				if ((PC>Player)&&(PC==10))
				{
				   cout<<"PC is winner! Game over!\n";
				   cout<<"\nLocation of ships in the end of the game:\n";
		      	   for (int e1=0;e1<10;e1++)
		      	   for (int e2=0;e2<10;e2++)
		      	   if ((PCField[e1][e2]=='@')&&(PCFieldVis[e1][e2]!='X')) PCFieldVis[e1][e2]='@';
		      	   ShowFields();
				   break;
				}
		        continue;
		   }
		   
		   if (lt&&rt&&up&&down)
	       {
	          int loc=rand()%4;
	           switch (loc)
	   	      {   
	   	        case 0: {
	   	        	      cout<<CurPosPC0/10+1<<";"<<CurPosPC0%10<<endl;
						  dir=0;
	   	   	              PCShot(CurPosPC0/10+1,CurPosPC0%10);
				          break;
			            }
		        case 1: {
		   	              cout<<CurPosPC0/10+1<<";"<<CurPosPC0%10+2<<endl;
						  dir=1;
	   	   	              PCShot(CurPosPC0/10+1,CurPosPC0%10+2);
				          break;
		                }
		        case 2: {
		   	              cout<<CurPosPC0/10<<";"<<CurPosPC0%10+1<<endl;
						  dir=2;
	   	   	              PCShot(CurPosPC0/10,CurPosPC0%10+1);
				          break;
		                }
		        case 3: {
		   	              cout<<CurPosPC0/10+2<<";"<<CurPosPC0%10+1<<endl;
						  dir=3;
	   	   	              PCShot(CurPosPC0/10+2,CurPosPC0%10+1);
				          break;
		                }
		       }
		      	cout<<"Game score (player - PC):   "<<Player<<":"<<PC<<endl;
		      	if ((Player>PC)&&(Player==10)) 
		      	{
		      	   cout<<"Game over! You win! Congratulations!\n";
				   break;	
				}
				if ((PC>Player)&&(PC==10))
				{
				   cout<<"PC is winner! Game over!\n";
				   cout<<"\nLocation of ships in the end of the game:\n";
		      	   for (int e1=0;e1<10;e1++)
		      	   for (int e2=0;e2<10;e2++)
		      	   if ((PCField[e1][e2]=='@')&&(PCFieldVis[e1][e2]!='X')) PCFieldVis[e1][e2]='@';
		      	   ShowFields();
				   break;
				}	
		      continue;
	       }
	       
	        if (lt&&rt&&up&&!down)
	       {
	          int loc=rand()%3;
	           switch (loc)
	   	      {   
	   	        case 0: {
	   	        	      cout<<CurPosPC0/10+1<<";"<<CurPosPC0%10<<endl;
						  dir=0;
	   	   	              PCShot(CurPosPC0/10+1,CurPosPC0%10);
				          break;
			            }
		        case 1: {
		   	              cout<<CurPosPC0/10+1<<";"<<CurPosPC0%10+2<<endl;
						  dir=1;
	   	   	              PCShot(CurPosPC0/10+1,CurPosPC0%10+2);
				          break;
		                }
		        case 2: {
		   	              cout<<CurPosPC0/10<<";"<<CurPosPC0%10+1<<endl;
						  dir=2;
	   	   	              PCShot(CurPosPC0/10,CurPosPC0%10+1);
				          break;
		                }
		       }
		      	cout<<"Game score (player - PC):   "<<Player<<":"<<PC<<endl;
		      	if ((Player>PC)&&(Player==10)) 
		      	{
		      	   cout<<"Game over! You win! Congratulations!\n";
				   break;	
				}
				if ((PC>Player)&&(PC==10))
				{
				   cout<<"PC is winner! Game over!\n";
				   cout<<"\nLocation of ships in the end of the game:\n";
		      	   for (int e1=0;e1<10;e1++)
		      	   for (int e2=0;e2<10;e2++)
		      	   if ((PCField[e1][e2]=='@')&&(PCFieldVis[e1][e2]!='X')) PCFieldVis[e1][e2]='@';
		      	   ShowFields();
				   break;
				}	
		      continue;
	       }
	       
	        if (lt&&rt&&!up&&down)
	       {
	          int loc=rand()%3;
	           switch (loc)
	   	      {   
	   	        case 0: {
	   	        	      cout<<CurPosPC0/10+1<<";"<<CurPosPC0%10<<endl;
						  dir=0;
	   	   	              PCShot(CurPosPC0/10+1,CurPosPC0%10);
				          break;
			            }
		        case 1: {
		   	              cout<<CurPosPC0/10+1<<";"<<CurPosPC0%10+2<<endl;
						  dir=1;
	   	   	              PCShot(CurPosPC0/10+1,CurPosPC0%10+2);
				          break;
		                }
		        case 2: {
		   	              cout<<CurPosPC0/10+2<<";"<<CurPosPC0%10+1<<endl;
						  dir=3;
	   	   	              PCShot(CurPosPC0/10+2,CurPosPC0%10+1);
				          break;
		                }
		       }
		      	cout<<"Game score (player - PC):   "<<Player<<":"<<PC<<endl;
		      	if ((Player>PC)&&(Player==10)) 
		      	{
		      	   cout<<"Game over! You win! Congratulations!\n";
				   break;	
				}
				if ((PC>Player)&&(PC==10))
				{
				   cout<<"PC is winner! Game over!\n";
				   cout<<"\nLocation of ships in the end of the game:\n";
		      	   for (int e1=0;e1<10;e1++)
		      	   for (int e2=0;e2<10;e2++)
		      	   if ((PCField[e1][e2]=='@')&&(PCFieldVis[e1][e2]!='X')) PCFieldVis[e1][e2]='@';
		      	   ShowFields();
				   break;
				}	
		      continue;
	       }
	       
	       if (lt&&!rt&&up&&down)
	       {
	          int loc=rand()%3;
	           switch (loc)
	   	      {  
	   	        case 0: {
	   	        	      cout<<CurPosPC0/10+1<<";"<<CurPosPC0%10<<endl;
						  dir=0;
	   	   	              PCShot(CurPosPC0/10+1,CurPosPC0%10);
				          break;
			            }
		        case 1: {
		   	              cout<<CurPosPC0/10<<";"<<CurPosPC0%10+1<<endl;
						  dir=2;
	   	   	              PCShot(CurPosPC0/10,CurPosPC0%10+1);
				          break;
		                }
		        case 2: {
		   	              cout<<CurPosPC0/10+2<<";"<<CurPosPC0%10+1<<endl;
						  dir=3;
	   	   	              PCShot(CurPosPC0/10+2,CurPosPC0%10+1);
				          break;
		                }
		      }
		      	cout<<"Game score (player - PC):   "<<Player<<":"<<PC<<endl;
		      	if ((Player>PC)&&(Player==10)) 
		      	{
		      	   cout<<"Game over! You win! Congratulations!\n";
				   break;	
				}
				if ((PC>Player)&&(PC==10))
				{
				   cout<<"PC is winner! Game over!\n";
				   cout<<"\nLocation of ships in the end of the game:\n";
		      	   for (int e1=0;e1<10;e1++)
		      	   for (int e2=0;e2<10;e2++)
		      	   if ((PCField[e1][e2]=='@')&&(PCFieldVis[e1][e2]!='X')) PCFieldVis[e1][e2]='@';
		      	   ShowFields();
				   break;
				}	
		      continue;
	       }
	       
	       if (!lt&&rt&&up&&down)
	       {
	          int loc=rand()%3;
	           switch (loc)
	   	      {   
		        case 0: {
		   	              cout<<CurPosPC0/10+1<<";"<<CurPosPC0%10+2<<endl;
						  dir=1;
	   	   	              PCShot(CurPosPC0/10+1,CurPosPC0%10+2);
				          break;
		                }
		        case 1: {
		   	              cout<<CurPosPC0/10<<";"<<CurPosPC0%10+1<<endl;
						  dir=2;
	   	   	              PCShot(CurPosPC0/10,CurPosPC0%10+1);
				          break;
		                }
		        case 2: {
		   	              cout<<CurPosPC0/10+2<<";"<<CurPosPC0%10+1<<endl;
						  dir=3;
	   	   	              PCShot(CurPosPC0/10+2,CurPosPC0%10+1);
				          break;
		                }
		      }
		      	cout<<"Game score (player - PC):   "<<Player<<":"<<PC<<endl;
		      	if ((Player>PC)&&(Player==10)) 
		      	{
		      	   cout<<"Game over! You win! Congratulations!\n";
				   break;	
				}
				if ((PC>Player)&&(PC==10))
				{
				   cout<<"PC is winner! Game over!\n";
				   cout<<"\nLocation of ships in the end of the game:\n";
		      	   for (int e1=0;e1<10;e1++)
		      	   for (int e2=0;e2<10;e2++)
		      	   if ((PCField[e1][e2]=='@')&&(PCFieldVis[e1][e2]!='X')) PCFieldVis[e1][e2]='@';
		      	   ShowFields();
				   break;
				}	
		      continue;
	       }
	       
	       if (lt&&!rt&&up&&!down)
	       {
	          int loc=rand()%2;
	           switch (loc)
	   	      {   
	   	        case 0: {
	   	        	      cout<<CurPosPC0/10+1<<";"<<CurPosPC0%10<<endl;
						  dir=0;
	   	   	              PCShot(CurPosPC0/10+1,CurPosPC0%10);
				          break;
			            }
		        case 1: {
		   	              cout<<CurPosPC0/10<<";"<<CurPosPC0%10+1<<endl;
						  dir=2;
	   	   	              PCShot(CurPosPC0/10,CurPosPC0%10+1);
				          break;
		                }
		      }
		      	cout<<"Game score (player - PC):   "<<Player<<":"<<PC<<endl;
		      	if ((Player>PC)&&(Player==10)) 
		      	{
		      	   cout<<"Game over! You win! Congratulations!\n";
				   break;	
				}
				if ((PC>Player)&&(PC==10))
				{
				   cout<<"PC is winner! Game over!\n";
				   cout<<"\nLocation of ships in the end of the game:\n";
		      	   for (int e1=0;e1<10;e1++)
		      	   for (int e2=0;e2<10;e2++)
		      	   if ((PCField[e1][e2]=='@')&&(PCFieldVis[e1][e2]!='X')) PCFieldVis[e1][e2]='@';
		      	   ShowFields();
				   break;
				}	
		      continue;
	       }
	       
	       if (lt&&!rt&&!up&&down)
	       {
	          int loc=rand()%2;
	           switch (loc)
	   	      {   
	   	        case 0: {
	   	        	      cout<<CurPosPC0/10+1<<";"<<CurPosPC0%10<<endl;
						  dir=0;
	   	   	              PCShot(CurPosPC0/10+1,CurPosPC0%10);
				          break;
			            }
		        case 1: {
		   	              cout<<CurPosPC0/10+2<<";"<<CurPosPC0%10+1<<endl;
						  dir=3;
	   	   	              PCShot(CurPosPC0/10+2,CurPosPC0%10+1);
				          break;
		                }
		      }
		      	cout<<"Game score (player - PC):   "<<Player<<":"<<PC<<endl;
		      	if ((Player>PC)&&(Player==10)) 
		      	{
		      	   cout<<"Game over! You win! Congratulations!\n";
				   break;	
				}
				if ((PC>Player)&&(PC==10))
				{
				   cout<<"PC is winner! Game over!\n";
				   cout<<"\nLocation of ships in the end of the game:\n";
		      	   for (int e1=0;e1<10;e1++)
		      	   for (int e2=0;e2<10;e2++)
		      	   if ((PCField[e1][e2]=='@')&&(PCFieldVis[e1][e2]!='X')) PCFieldVis[e1][e2]='@';
		      	   ShowFields();
				   break;
				}	
		      continue;
	       }
	       
	       if (!lt&&rt&&up&&!down)
	       {
	          int loc=rand()%2;
	           switch (loc)
	   	      {   
		        case 0: {
		   	              cout<<CurPosPC0/10+1<<";"<<CurPosPC0%10+2<<endl;
						  dir=1;
	   	   	              PCShot(CurPosPC0/10+1,CurPosPC0%10+2);
				          break;
		                }
		        case 1: {
		   	              cout<<CurPosPC0/10<<";"<<CurPosPC0%10+1<<endl;
						  dir=2;
	   	   	              PCShot(CurPosPC0/10,CurPosPC0%10+1);
				          break;
		                }
		      }
		      	cout<<"Game score (player - PC):   "<<Player<<":"<<PC<<endl;
		      	if ((Player>PC)&&(Player==10)) 
		      	{
		      	   cout<<"Game over! You win! Congratulations!\n";
				   break;	
				}
				if ((PC>Player)&&(PC==10))
				{
				   cout<<"PC is winner! Game over!\n";
				   cout<<"\nLocation of ships in the end of the game:\n";
		      	   for (int e1=0;e1<10;e1++)
		      	   for (int e2=0;e2<10;e2++)
		      	   if ((PCField[e1][e2]=='@')&&(PCFieldVis[e1][e2]!='X')) PCFieldVis[e1][e2]='@';
		      	   ShowFields();
				   break;
				}	
		      continue;
	       }
	       
	       if (!lt&&rt&&!up&&down)
	       {
	          int loc=rand()%2;
	           switch (loc)
	   	      {   
		        case 0: {
		   	              cout<<CurPosPC0/10+1<<";"<<CurPosPC0%10+2<<endl;
						  dir=1;
	   	   	              PCShot(CurPosPC0/10+1,CurPosPC0%10+2);
				          break;
		                }
		        case 1: {
		   	              cout<<CurPosPC0/10+2<<";"<<CurPosPC0%10+1<<endl;
						  dir=3;
	   	   	              PCShot(CurPosPC0/10+2,CurPosPC0%10+1);
				          break;
		                }
		      }
		      	cout<<"Game score (player - PC):   "<<Player<<":"<<PC<<endl;
		      	if ((Player>PC)&&(Player==10)) 
		      	{
		      	   cout<<"Game over! You win! Congratulations!\n";
				   break;	
				}
				if ((PC>Player)&&(PC==10))
				{
				   cout<<"PC is winner! Game over!\n";
				   cout<<"\nLocation of ships in the end of the game:\n";
		      	   for (int e1=0;e1<10;e1++)
		      	   for (int e2=0;e2<10;e2++)
		      	   if ((PCField[e1][e2]=='@')&&(PCFieldVis[e1][e2]!='X')) PCFieldVis[e1][e2]='@';
		      	   ShowFields();
				   break;
				}	
		      continue;
	       }
	       
	       if (lt&&rt&&!up&&!down)
	       {  
                if (CurPosPC1==-1)
	   	        {
	   	          int loc=rand()%2;
				  switch(loc)
				  {
				  	case 0:{
						      cout<<CurPosPC0/10+1<<";"<<CurPosPC0%10<<endl;
							  dir=0;
	   	   	                  PCShot(CurPosPC0/10+1,CurPosPC0%10);
				              break;
					       }
					case 1:{
		   	                  cout<<CurPosPC0/10+1<<";"<<CurPosPC0%10+2<<endl;
							  dir=1;
	   	   	                  PCShot(CurPosPC0/10+1,CurPosPC0%10+2);
				              break;
		                   }	
	              }
				}
				else
				{  
				  if (CurPosPC1%10<CurPosPC0%10)
					{
	   	        	  cout<<CurPosPC1/10+1<<";"<<CurPosPC1%10<<endl;
					  dir=0;
	   	   	          PCShot(CurPosPC1/10+1,CurPosPC1%10);  
					}
					
				  if (CurPosPC1%10>CurPosPC0%10)
				    {
				  	  cout<<CurPosPC1/10+1<<";"<<CurPosPC1%10+2<<endl;
					  dir=1;
	   	   	          PCShot(CurPosPC1/10+1,CurPosPC1%10+2);   
				    }
				}
					cout<<"Game score (player - PC):   "<<Player<<":"<<PC<<endl;
		      	if ((Player>PC)&&(Player==10)) 
		      	{
		      	   cout<<"Game over! You win! Congratulations!\n";
				   break;	
				}
				if ((PC>Player)&&(PC==10))
				{
				   cout<<"PC is winner! Game over!\n";
				   cout<<"\nLocation of ships in the end of the game:\n";
		      	   for (int e1=0;e1<10;e1++)
		      	   for (int e2=0;e2<10;e2++)
		      	   if ((PCField[e1][e2]=='@')&&(PCFieldVis[e1][e2]!='X')) PCFieldVis[e1][e2]='@';
		      	   ShowFields();
				   break;
				}	
				continue;
	       }
	       
	       if (!lt&&!rt&&up&&down)
	       {  
	       	  if (CurPosPC1==-1)
	   	      {
	            int loc=rand()%2;
	            switch (loc)
	   	        {   
		        case 0: {
		   	              cout<<CurPosPC0/10<<";"<<CurPosPC0%10+1<<endl;
						  dir=2;
	   	   	              PCShot(CurPosPC0/10,CurPosPC0%10+1);
				          break;
		                }
		        case 1: {
		   	              cout<<CurPosPC0/10+2<<";"<<CurPosPC0%10+1<<endl;
						  dir=3;
	   	   	              PCShot(CurPosPC0/10+2,CurPosPC0%10+1);
				          break;
		                }
		        } 
	          }
	          else
	          {  
				  if (CurPosPC1/10<CurPosPC0/10)
					{
	   	        	  cout<<CurPosPC1/10<<";"<<CurPosPC1%10+1<<endl;
					  dir=2;
	   	   	          PCShot(CurPosPC1/10,CurPosPC1%10+1);  
					}
					
				  if (CurPosPC1/10>CurPosPC0/10)
				    {
				  	  cout<<CurPosPC1/10+2<<";"<<CurPosPC1%10+1<<endl;
					  dir=3;
	   	   	          PCShot(CurPosPC1/10+2,CurPosPC1%10+1);  
				    }
				}
					cout<<"Game score (player - PC):   "<<Player<<":"<<PC<<endl;
		      	if ((Player>PC)&&(Player==10)) 
		      	{
		      	   cout<<"Game over! You win! Congratulations!\n";
				   break;	
				}
				if ((PC>Player)&&(PC==10))
				{
				   cout<<"PC is winner! Game over!\n";
				   cout<<"\nLocation of ships in the end of the game:\n";
		      	   for (int e1=0;e1<10;e1++)
		      	   for (int e2=0;e2<10;e2++)
		      	   if ((PCField[e1][e2]=='@')&&(PCFieldVis[e1][e2]!='X')) PCFieldVis[e1][e2]='@';
		      	   ShowFields();
				   break;
				}	
				continue;
	        }
	       
	       if (lt&&!rt&&!up&&!down)
	       {   
	   	        if (CurPosPC1==-1)
	   	        {
	   	        	cout<<CurPosPC0/10+1<<";"<<CurPosPC0%10<<endl;
					dir=0;
	   	   	        PCShot(CurPosPC0/10+1,CurPosPC0%10);
				}
				else 
				{
					if (CurPosPC1%10<CurPosPC0%10)
					{
					   cout<<CurPosPC1/10+1<<";"<<CurPosPC1%10<<endl;
					   dir=0;
	   	   	           PCShot(CurPosPC1/10+1,CurPosPC1%10); 	
					}
					if (CurPosPC1%10>CurPosPC0%10) 
					{
					   cout<<CurPosPC0/10+1<<";"<<CurPosPC0%10<<endl;
					   dir=0;
	   	   	           PCShot(CurPosPC0/10+1,CurPosPC0%10);
					}
				}
					cout<<"Game score (player - PC):   "<<Player<<":"<<PC<<endl;
		      	if ((Player>PC)&&(Player==10)) 
		      	{
		      	   cout<<"Game over! You win! Congratulations!\n";
				   break;	
				}
				if ((PC>Player)&&(PC==10))
				{
				   cout<<"PC is winner! Game over!\n";
				   cout<<"\nLocation of ships in the end of the game:\n";
		      	   for (int e1=0;e1<10;e1++)
		      	   for (int e2=0;e2<10;e2++)
		      	   if ((PCField[e1][e2]=='@')&&(PCFieldVis[e1][e2]!='X')) PCFieldVis[e1][e2]='@';
		      	   ShowFields();
				   break;
				}	
				continue;
		   }
		        
		    if (!lt&&rt&&!up&&!down)
	        {   
				if (CurPosPC1==-1)
	   	        {
		   	      cout<<CurPosPC0/10+1<<";"<<CurPosPC0%10+2<<endl;
				  dir=1;
	   	   	      PCShot(CurPosPC0/10+1,CurPosPC0%10+2);
	   	   	    }
	   	   	    else 
	   	   	    {
	   	   	    	if (CurPosPC1%10>CurPosPC0%10)
	   	   	    	{
	   	   	    		cout<<CurPosPC1/10+1<<";"<<CurPosPC1%10+2<<endl;
						dir=1;
	   	   	            PCShot(CurPosPC1/10+1,CurPosPC1%10+2);  
					}
					if (CurPosPC1%10<CurPosPC0%10) 
					{
						cout<<CurPosPC0/10+1<<";"<<CurPosPC0%10+2<<endl;
						dir=1;
	   	   	            PCShot(CurPosPC0/10+1,CurPosPC0%10+2);
					}
				}
					cout<<"Game score (player - PC):   "<<Player<<":"<<PC<<endl;
		      	if ((Player>PC)&&(Player==10)) 
		      	{
		      	   cout<<"Game over! You win! Congratulations!\n";
				   break;	
				}
				if ((PC>Player)&&(PC==10))
				{
				   cout<<"PC is winner! Game over!\n";
				   cout<<"\nLocation of ships in the end of the game:\n";
		      	   for (int e1=0;e1<10;e1++)
		      	   for (int e2=0;e2<10;e2++)
		      	   if ((PCField[e1][e2]=='@')&&(PCFieldVis[e1][e2]!='X')) PCFieldVis[e1][e2]='@';
		      	   ShowFields();
				   break;
				}	
				continue;
		    }
		    
		    if (!lt&&!rt&&up&&!down)
	        {  
				if (CurPosPC1==-1)
	   	        {
		   	      cout<<CurPosPC0/10<<";"<<CurPosPC0%10+1<<endl;
				  dir=2;
	   	   	      PCShot(CurPosPC0/10,CurPosPC0%10+1);
	   	   	    }
	   	   	    else 
	   	   	    {
	   	   	    	if (CurPosPC1/10<CurPosPC0/10)
	   	   	    	{
	   	   	    		cout<<CurPosPC1/10<<";"<<CurPosPC1%10+1<<endl;
						dir=2;
	   	   	            PCShot(CurPosPC1/10,CurPosPC1%10+1);
					} 
					if (CurPosPC1/10>CurPosPC0/10)
					{
					   cout<<CurPosPC0/10<<";"<<CurPosPC0%10+1<<endl;
					   dir=2;
	   	   	           PCShot(CurPosPC0/10,CurPosPC0%10+1);
					}
				}
					cout<<"Game score (player - PC):   "<<Player<<":"<<PC<<endl;
		      	if ((Player>PC)&&(Player==10)) 
		      	{
		      	   cout<<"Game over! You win! Congratulations!\n";
				   break;	
				}
				if ((PC>Player)&&(PC==10))
				{
				   cout<<"PC is winner! Game over!\n";
				   cout<<"\nLocation of ships in the end of the game:\n";
		      	   for (int e1=0;e1<10;e1++)
		      	   for (int e2=0;e2<10;e2++)
		      	   if ((PCField[e1][e2]=='@')&&(PCFieldVis[e1][e2]!='X')) PCFieldVis[e1][e2]='@';
		      	   ShowFields();
				   break;
				}	
				continue;
		    }
		
	       if (!lt&&!rt&&!up&&down)
	       {    
				if (CurPosPC1==-1)
	   	        {
		   	      cout<<CurPosPC0/10+2<<";"<<CurPosPC0%10+1<<endl;
				  dir=3;
	   	   	      PCShot(CurPosPC0/10+2,CurPosPC0%10+1);
	   	   	    }
	   	   	    else
	   	   	    {
	   	   	    	if (CurPosPC1/10>CurPosPC0/10)
	   	   	    	{
	   	   	    		cout<<CurPosPC1/10+2<<";"<<CurPosPC1%10+1<<endl;
						dir=3;
	   	   	            PCShot(CurPosPC1/10+2,CurPosPC1%10+1);
					}
					if (CurPosPC1/10<CurPosPC0/10)
					{
						cout<<CurPosPC0/10+2<<";"<<CurPosPC0%10+1<<endl;
						dir=3;
	   	   	            PCShot(CurPosPC0/10+2,CurPosPC0%10+1);
					}
				}
				cout<<"Game score (player - PC):   "<<Player<<":"<<PC<<endl;
		      	if ((Player>PC)&&(Player==10)) 
		      	{
		      	   cout<<"Game over! You win! Congratulations!\n";
				   break;	
				}
				if ((PC>Player)&&(PC==10))
				{
				   cout<<"PC is winner! Game over!\n";
				   cout<<"\nLocation of ships in the end of the game:\n";
		      	   for (int e1=0;e1<10;e1++)
		      	   for (int e2=0;e2<10;e2++)
		      	   if ((PCField[e1][e2]=='@')&&(PCFieldVis[e1][e2]!='X')) PCFieldVis[e1][e2]='@';
		      	   ShowFields();
				   break;
				}	
				continue;
	       }
		}
		
		else
		{
			cout<<"\nPlease, input two coordinates of shot (each between 1 and 10)\n";
			cout<<"Player's shot: ";
			for (int i=0;;i++)
			{
				cin>>Pl1;
			    cin.get();
			    cin>>Pl2;
			    cin.get();
			    if ((Pl1<1)||(Pl1>10)||(Pl2<1)||(Pl2>10))
				{
					cout<<"\nYou input wrong data. Try again.\n";
					continue;
				}
				if ((PCFieldVis[Pl1-1][Pl2-1]=='X')||(PCFieldVis[Pl1-1][Pl2-1]=='-'))
				{
					cout<<"\nYou have been shot there or your shot is illogical. Try again.\n";
					continue;
				}
				break;
			}
			PlShot(Pl1,Pl2);
			cout<<"Game score (player - PC):   "<<Player<<":"<<PC<<endl;
		      	if ((Player>PC)&&(Player==10)) 
		      	{
		      	   cout<<"Game over! You win! Congratulations!\n";
				   break;	
				}
				if ((PC>Player)&&(PC==10))
				{
				   cout<<"PC is winner! Game over!\n";
				   cout<<"\nLocation of ships in the end of the game:\n";
		      	   for (int e1=0;e1<10;e1++)
		      	   for (int e2=0;e2<10;e2++)
		      	   if ((PCField[e1][e2]=='@')&&(PCFieldVis[e1][e2]!='X')) PCFieldVis[e1][e2]='@';
		      	   ShowFields();
				   break;
				}	
		}
	}
	
}
int main() 
{
	srand(time(NULL));
	
	PlField=new char*[10];
	for (int i=0;i<10;i++)
	PlField[i]=new char[10];
	for (int i=0;i<10;i++)
	for (int j=0;j<10;j++)
	PlField[i][j]=' ';
	
	PlFieldVis=new char*[10];
	for (int i=0;i<10;i++)
	PlFieldVis[i]=new char[10];
	for (int i=0;i<10;i++)
	for (int j=0;j<10;j++)
	PlFieldVis[i][j]=' ';
	
	PCField=new char*[10];
	for (int i=0;i<10;i++)
	PCField[i]=new char[10];
	for (int i=0;i<10;i++)
	for (int j=0;j<10;j++)
	PCField[i][j]=' ';
	
	PCFieldVis=new char*[10];
	for (int i=0;i<10;i++)
	PCFieldVis[i]=new char[10];
	for (int i=0;i<10;i++)
	for (int j=0;j<10;j++)
	PCFieldVis[i][j]=' ';
	
	PlShipsData=new int*[2];
	PCShipsData=new int*[2];
	for (int i=0;i<2;i++)
	{
		PlShipsData[i]=new int[20];
		PCShipsData[i]=new int[20];
	}
	cout<<"\n                             The game 'Ship's battle'\n";
	ValPl=new int[10];
	ValPl[0]=4;ValPl[1]=3;ValPl[2]=3;ValPl[3]=2;ValPl[4]=2;ValPl[5]=2;ValPl[6]=1;ValPl[7]=1;ValPl[8]=1;ValPl[9]=1;	
	ValPC=new int[10];
	ValPC[0]=4;ValPC[1]=3;ValPC[2]=3;ValPC[3]=2;ValPC[4]=2;ValPC[5]=2;ValPC[6]=1;ValPC[7]=1;ValPC[8]=1;ValPC[9]=1;	
	AutoFill(PCField);
	int Fill;
	cout<<"\nShips are oriented horizontally and vertically. For automatic filling press '0'; manually - press '1'\n";
	for (int i=0;;i++)
	{
	  cin>>Fill;
	  cin.get();
	  if ((Fill!=0)&&(Fill!=1)) 
	  {
	  	cout<<"\nYou input wrong data. Try again.\n";
	  	continue;
	  }
	  else break;
    }
    if (Fill==0) 
	{
		AutoFill(PlField); 
		for (int i=0;i<10;i++)
	    for (int j=0;j<10;j++)
     	PlFieldVis[i][j]=PlField[i][j];
    }
	else ManualFill();
	ShowFields();
	Game();
	cout<<"\n\n\n\nThis program was written by Oleksandr Chaparin. All rights reserved.\n";
	for (int i=0;i<10;i++)
	{
		delete []PlField[i];
		delete []PlFieldVis[i];
		delete []PCField[i];
		delete []PCFieldVis[i];
	}
	for (int i=0;i<2;i++)
	{
		delete []PlShipsData[i];
		delete []PCShipsData[i];
	}
	
	delete []PlField;
	delete []PlFieldVis;
	delete []PCField;
	delete []PCFieldVis;
	delete []PlShipsData;
	delete []PCShipsData;
	delete []ValPl;
	delete []ValPC;
	return 0;
}
