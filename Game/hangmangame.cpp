#include<fstream.h>
#include<bios.h>
#include<time.h>
#include<dos.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
#include<mouse.h>

#define SMILE 1
#define SAD 0

//VARIABLES AND FUNCTIONS DECLARATION
unsigned key;
char firstrow[]={'Q','W','E','R','T','Y','U','I','O','P'};
char secondrow[]={'A','S','D','F','G','H','J','K','L'};
char thirdrow[]={'Z','X','C','V','B','N','M'};
char *main_menu[]={{"1. PLAY"},{"2. INSTRUCTIONS"},{"3. HI-SCORE"},{"4.
EXIT"}};
char *categories[]={{"1. MOVIES"},{"2. SPORTS"},{"3. MOVIE STARS"},{"4.
PLACES"}};
char *m_m[]={"P","I","H","E"},*c_m[]={"M","S","A","P"};
int
blankpos_x[]={25,50,75,100,125,150,175,200,225,250,275,300,325,350,375,400
};
int blankpos_y[]={80,150,300,340},cat_pos_x[]={130,130,314,130};
char string[50],name[25],category[20],checklist[50],hitlist[50];
char wr_guesses[10],ch,datebuf[9],timebuf[9];

int
button,x,y,corx,cory,len=0,d,m,mx,my,i,j,k,count_s=0,count_f=0,hcount=0,fl
ag=0,hlflag=1,spaces=0;
int hlcount=0,prflag=0,hngmnflag=0,dispflag=0,gameflag=0;
int tcolor=GREEN,acolor=RED;

void drawsetup();
void game();
void play();
void initgraphics();
void show_main_menu();
void getoption();

//FUNCTION TO INITIALISE ALL THE VARIABLES
void init()
{
 hlcount=0,prflag=0,hngmnflag=0,dispflag=0,gameflag=0;
 tcolor=GREEN,acolor=RED;
 len=0,count_s=0,count_f=0,hcount=0,flag=0,hlflag=1,spaces=0;
 strcpy(hitlist,"");
 strcpy(checklist,"");
 strcpy(wr_guesses,"");
}

//CLASS RECORD TO READ RECORD FROM THE FILES
 class record
 {
  char word[50];
  public:
		  void input()
		  {
		   gets(word);
		  }
		  void output()
		  {
		   puts(word);
		  }
		  char *returnword()
		  {
		   return word;
		  }
 }rec,out;

//BORDER FUNCTIONS TO BORDER EACH PAGE
void border()
{
  setcolor(GREEN);
  rectangle(2,2,mx-2,my-2);
  setcolor(RED);
  rectangle(4,4,mx-4,my-4);
  setcolor(GREEN);
  rectangle(6,6,mx-6,my-6);
  settextstyle(4,0,5);
  outtextxy(180,40,"HANGMAN");
  setcolor(YELLOW);
  line(175,88,420,88);
  setcolor(RED);
  line(175,90,420,90);
}

//FUNCTION TO DISPLAY THE VERY FIRST SCREEN OF THE PROGRAM
void FIRSTSCREEN()
{
  clrscr();
  initgraphics();
  border();

  settextstyle(3,0,3);
  setcolor(RED);
  outtextxy(130,200,"Programmed By:");
  settextstyle(1,0,3);
  setcolor(WHITE);
  outtextxy(330,200,"Manish Jain");
  outtextxy(150,235,"mkj_manishjain@yahoo.co.in");
  outtextxy(150,275,"         +91 9896455735");
  settextstyle(1,0,4);
  setcolor(RED);
  outtextxy(120,360,"Press any key to play");

  getch();
}

//FUNCTION TO SHOW INSTRUCTIONS FOR THE USERS
void instruction()
{
 cleardevice();
 border();
 setcolor(RED);
 settextstyle(1,0,5);
 outtextxy(50,140,"I N S T R U C T I O N S");
 settextstyle(3,0,3);
 setcolor(WHITE);
 outtextxy(60,190,"1. Fill the Blanks with the suitable word.");
 outtextxy(60,230,"2. The word should belong to the category");
 outtextxy(60,270,"   selected by you.");
 outtextxy(60,300,"3. You will be given 8 chances to fill it up.");
 outtextxy(60,330,"4. Man on the Hanger describes your attempts ");
 outtextxy(60,365,"5. Your wrong guesses are shown there.");
 settextstyle(4,0,4);
 setcolor(RED);
 outtextxy(140,425,"Press any key to Continue");
 getch();
 show_main_menu();
}

//FUNCTION TO CHOOSE ONE FROM THE OPTIONS GIVEN USING MOUSE
void chooseoption()
{
  cleardevice();
  border();
  settextstyle(1,0,5);
  setcolor(GREEN);
  outtextxy(50,140,"C A T E G O R I E S");

  settextstyle(3,0,5);

  for(i=0;i<4;i++)
  {
   setcolor(WHITE);
   outtextxy(67,190+(45*i),categories[i]);
   setcolor(RED);
   rectangle(50,210+(45*i),60,220+(45*i));
   outtextxy(cat_pos_x[i],190+(45*i),c_m[i]);
  }
   getoption();
}

//FUNCTION TO CHECK THE CATEGORY SELECTED BY THE USER
 int getcategory(int x,int y)
 {
  //Check for category "Movies"
   if((x>=10&&x<=80)&&(y>=200 &&y<=240))
	  {
		strcpy(category,"Movies");
		return 1;
	  }
  //Check for Category "Sports"
   if((x>=10&&x<=80)&&(y>=255 &&y<=280))
	  {
		strcpy(category,"Sports");
		return 1;
	  }
   //Check for Category "Actors"
   if((x>=10&&x<=80)&&(y>=285 &&y<=310))
	  {
		strcpy(category,"Actors");
		return 1;
	  }
   //Check for Category "Places"
   if((x>=10&&x<=80)&&(y>=315 &&y<=350))
	  {
		strcpy(category,"Places");
		return 1;
	  }
  return 0;
 }

//FUNCTION TO GET OPTION FROM THE USER USING MOUSE OR KEYBOARD
void getoption()
{
 showmouseptr();
 restrictmouseptr(10,200,80,400);
	while(1)
	{
	  getmousepos(&button,&x,&y);
	  if((button&1)==1)
	  { corx=x;
		cory=y;
		if(getcategory(corx,cory)==1)
			break;
	  }
	  int cho=bioskey(0);
	  cho=cho>>8;
	   switch(cho)
		{
		  case 2:
		  case 50:
		  case 28:
		  case 79: strcpy(category,"Movies");
				   return;
		  case 3:
		  case 31:
		  case 80: strcpy(category,"Sports");
				   return;
		  case 4:
		  case 30:
		  case 81: strcpy(category,"Actors");
				   return;
		  case 5:
		  case 25:
		  case 75: strcpy(category,"Places");
				   return;
		  default: break;
		}
	  }
}

//FUNCTION TO SHOWFACE (SMILING OR SAD)
void showface(int expr)
{
   setcolor(RED);
   circle(390,50,25);
   setcolor(WHITE);
   ellipse(378,45,0,360,3,4);
   ellipse(402,45,0,360,3,4);
   if(expr==SMILE)
	arc(390,55,235,305,13);
   else
	arc(390,80,55,120,13);
}
//PRINTING HIGH SCORE WITH THE NAMES OF THE SCORERS
void hiscore()
{
 cleardevice();
 border();
 setcolor(RED);
 settextstyle(1,0,5);
 outtextxy(50,140,"    H I   S C O R E");
 settextstyle(3,0,3);
 setcolor(WHITE);
 outtextxy(60,220,"Sorry! This feature is not available in this version
");
 outtextxy(60,270,"For further details, Contact  :  ");
 setcolor(GREEN);
 outtextxy(60,310,"        mkj_manishjain@yahoo.co.in");
 outtextxy(60,345,"        Mobile no.: +91 9896455735 ");
 settextstyle(4,0,4);
 setcolor(RED);
 outtextxy(140,425,"Press any key to Continue");
 getch();
 show_main_menu();
}

//GETTING THE CHOICE FROM THE USER FOR THE MAIN MENU
void get_mm_choice()
{
 get:
 int cho=bioskey(0);
 cho=cho>>8;
 switch(cho)
 {
  case 2:
  case 25:
  case 28:
  case 79: play();
	   break;

  case 3:
  case 23:
  case 80: instruction();
	   break;

  case 4:
  case 35:
  case 81: hiscore();
	   break;

  case 5:
  case 18:
  case 75: exit(0);
	   break;
  default: goto get;
 }
}

//MAIN MENU OF THE PROGRAM
void show_main_menu()
{
 cleardevice();
 border();
 settextstyle(1,0,5);
 setcolor(GREEN);
 outtextxy(60,130,"M A I N  M E N U");
 settextstyle(3,0,5);

 for(i=0;i<4;i++)
 {
  setcolor(WHITE);
  outtextxy(67,180+(35*i),main_menu[i]);
  setcolor(RED);
  outtextxy(130,180+(35*i),m_m[i]);
 }
 get_mm_choice();
}

//DISPLAY THE CHARACTER AT ITS APPROPRIATE POSITION WITH DESIRED COLOR
void display(char ch,int pos,int color)
{
 char c[2];
 c[0]=ch;
 c[1]='\0';
 setcolor(color);
 outtextxy(blankpos_x[pos%16]+15,blankpos_y[pos/16],c);
}

//DRAWING THE MAN ON THE HANGER PARTS BY PARTS AS PER CORRECTNESS OF
GUESSES
void drawhangman(int count_f)
{
 setcolor(RED);
 if(hngmnflag==1)
 {
  switch(count_f)
  {
  case 1:   circle(500,150,10);
			hngmnflag=0;
			break;
  case 2:   line(500,160,500,170);
			hngmnflag=0;
			break;
  case 3:   ellipse(500,192,0,360,15,20);
			hngmnflag=0;
			break;
  case 4:   line(500,213,490,218);
			hngmnflag=0;
			break;
  case 5:   line(500,213,510,218);
			hngmnflag=0;
			break;
  case 6:   line(500,170,480,180);
			hngmnflag=0;
			break;
  case 7:   line(500,170,520,180);
			hngmnflag=0;
			break;
  case 8:  	setcolor(acolor);
			outtextxy(100,340,"MERCY CHANCE");
			delay(1000);
			setcolor(getbkcolor());
			outtextxy(100,340,"MERCY CHANCE");
			hngmnflag=0;
			break;
  }
 }
}

//ASKING USER IF HE WISHES TO PLAY AGAIN
void asktocontinue()
{
   setcolor(WHITE);
   outtextxy(40,340,"Wish to Play again:(Y/N):");
   get:
   char ch=getch();
   if(ch=='y'||ch=='Y')
	 {
	   outtextxy(440,340,"Y");
	   getch();
	   play();
	 }
   else if(ch=='n'||ch=='N')
	 {
	   outtextxy(440,340,"N");
	   getch();
	   exit(0);
	 }
	goto get;
}

//CHECK THE KEY PRESSED AND TAKE APPROPRIATE ACTION
void check(char ch)
{
 flag=0;
 hlflag=1;
 prflag=0;
 for(i=0;string[i]!='\0';i++) //CHECKING CHARACTER IN THE STRING
  {
   if(ch==string[i])      //If char is present in the string
	{
	 prflag=1;
	 for(j=0;j<hlcount;j++)
	  {
	   if(ch==hitlist[j])    //if char is present in the list of pressed
characters
		{
		 hlflag=0;
		 break;
		}
	  }
	 if(hlflag==1)
	  { setcolor(tcolor);flag=1;display(ch,i,GREEN);count_s--; }
	 else break;
	}
  }
  if(prflag==0)    //If the character is not present in the string
   {
	for(j=0;checklist[j]!='\0';j++)
	 {
	  if(ch==checklist[j])
		return;
	 }
	checklist[count_f++]=ch;
	wr_guesses[count_f-1]=ch;
	display(ch,32+(count_f),RED);
	hngmnflag=1;
   }
  else if(prflag==1 && flag==1)  //If the character present is repeated
	  hitlist[hlcount++]=ch;

  if(count_s==0)                  //GAME CLEARED
  {
   setcolor(acolor);
   outtextxy(100,265,"\nGame Cleared");
   gameflag=1;
  //DRAWING A SMILING FACE TO SHOW GAME CLEARED
   showface(SMILE);
   asktocontinue();
  }
  else if(count_f>8)              //GAME OVER
  {
   setcolor(acolor);
   outtextxy(100,265,"\nGame Over");
   gameflag=1;
   setcolor(RED);
   for(i=0;string[i]!='\0';i++)
   {
	dispflag=0;
	 for(j=0;j<hlcount;j++)
	  {
		if(string[i]==hitlist[j])
		 {
		  dispflag=1;
		  break;
		 }
	  }
	if(dispflag==0)                 //Display Remaining Characters
	 display(string[i],i,RED);
   }
 //DRAWING A SAD FACE TO SHOW GAME OVER
   showface(SAD);
   asktocontinue();
   getch();
   exit(0);
  }
  drawhangman(count_f);
}

void matchkey(int s)        //GENERATING THE ASCII OF THE KEY PRESSED
{
  if(s>=16 && s<=25)
	ch=firstrow[s-16];
  else if(s>=30 && s<=38)
	ch=secondrow[s-30];
  else if(s>=44 && s<=50)
	ch=thirdrow[s-44];
  else if(s>=2 && s<=10)
	ch=(char)(47+s);
  else if(s==11)
	ch=(char)48;
  check(ch);
}

//SHOW DATE AND TIME
void showtime()
{
  _strtime(timebuf);
  setcolor(GREEN);
  settextstyle(1,0,3);
  setviewport(340,18,460,60,1);
  outtextxy(10,2,timebuf);
  delay(50);
  clearviewport();
  settextstyle(1,0,4);
}

//DRAW THE HANGER FOR MAN TO BE HANGED
void drawhanger()
{
 setcolor(WHITE);
 line(500,125,500,140);
 line(500,125,525,125);
 line(525,125,525,220);
}

//DRAW THE SETUP FOR THE GAME
void drawsetup()
{
 hidemouseptr();
 cleardevice();

 setcolor(BLUE);
 rectangle(8,8,mx-8,my-8);

 setcolor(RED);
 rectangle(9,9,mx-9,my-9);
 line(10,381,mx-10,381);
 line(10,341,468,341);
 line(10,301,468,301);
 line(10,65,330,65);

 setcolor(GREEN);
 rectangle(10,10,mx-10,my-10);
 line(10,380,mx-10,380);
 line(10,340,468,340);
 line(10,300,468,300);
 line(10,66,330,66);

 bar(468,10,472,380);
 bar(188,10,192,66);
 bar(328,10,332,66);

  settextstyle(1,0,3);
  _strdate(datebuf);
  outtextxy(220,10,"DATE");
  outtextxy(200,30,datebuf);

 settextstyle(8,0,7);
 outtextxy(50,360,"H A N G M A N");
 setcolor(YELLOW);
 outtextxy(48,360,"H A N G M A N");
 setcolor(WHITE);
 outtextxy(46,360,"H A N G M A N");
 settextstyle(2,0,4);
 outtextxy(46,446,"c");       //COPYRIGHT SYMBOL
 circle(48,453,4);
 settextstyle(3,0,3);
 outtextxy(56,435," Fantasatic Four (P) Ltd. 2003-07");

 settextstyle(3,0,4);
 setcolor(BLUE);
 outtextxy(500,18,"Player");
 settextstyle(3,0,2);
 setcolor(WHITE);
 outtextxy(510-(strlen(name)*2),55,name);
 setcolor(GREEN);
 settextstyle(1,0,5);
 outtextxy(40,13,category);

 drawhanger();
}

//FUNCTION GAME-MAIN FUNCTION WHERE FUNCTIONING OF GAME STARTS
void game()
{
 strcat(category,".man");
 fstream f1(category,ios::in|ios::nocreate|ios::binary);
 randomize();
 int num=(random(150))%99+1;
 f1.seekg(num*sizeof(rec));
 f1.read((char*)&rec,sizeof(rec));

 strcpy(string,rec.returnword());
 len=strlen(string);

 setcolor(GREEN);
 settextstyle(1,0,4);

 for(i=0;string[i]!='\0';i++)
 { //DISPLAYING THE BLANK SPACES('_') FOR EACH CHARACTER
  if((string[i]>=48 &&string[i]<=57) ||(string[i]>=65 &&string[i] <=90) 
||
(string[i] >=97 &&string[i] <=122))
	{
	 outtextxy(blankpos_x[i%16],blankpos_y[i/16]," _ ");
	 count_s++;
	}
  else
	{ //DISPLAYING THE COMMA(',') FOR EACH SPACE
	  outtextxy(blankpos_x[i%16],blankpos_y[i/16]," , ");
	  spaces++;
	}
 }
  setcolor(RED);
  outtextxy(50,300,"\nPRESS ANY KEY TO PLAY");
  getch();
  setcolor(getbkcolor());
  outtextxy(50,300,"\nPRESS ANY KEY TO PLAY");
  setcolor(GREEN);

  //ACCEPTING KEYSTROKE UNTILL THE CONDITION IS SATISFIED
 while(count_s>=0 && count_f<=8)   //INITIALLY count_s=len i.e.(LENGTH 
of
word)
 {                                 	//and count_f is no. of wrong 
guesses
   if(bioskey(1))
   {
	 key=bioskey(0);
	 int s=key>>8;
	 if(s==1)
	  {
	   getch();
	   exit(0);
	  }
	 else if(s==28)
	  continue;
	 else
	  matchkey(s);
   }
  if(gameflag!=1)
	showtime();
  setviewport(0,0,mx,my,1);
 }
}

//FUN
//FUNCTION TO INITIALISE GRAPHICS
void initgraphics()
{
 d=DETECT;
 initgraph(&d,&m,"..//bgi");
 mx=getmaxx();
 my=getmaxy();
}

void play()
{
 init();
 chooseoption();
 drawsetup();
 game();
}

//FUNCTION TO INPUT NAME OF TEH USER
 void getuser()
 {
  cleardevice();
  cout<<"\n\nEnter your Name:";
  gets(name);
  if(strlen(name)<1)
   strcpy(name,"USER");
 }

//WELCOMING THE USER
 void welcomeuser()
 {
  cleardevice();
  setcolor(GREEN);
  border();
  settextjustify(CENTER_TEXT,CENTER_TEXT);
  settextstyle(3,0,8);
  outtextxy(mx/2,150,"WELCOME");
  setcolor(WHITE);
  settextstyle(1,0,7);
  outtextxy(mx/2,my/2,name);
  setcolor(RED);
  settextstyle(5,0,5);
  outtextxy(mx/2,380,"\nPRESS ANY KEY TO PLAY");
  settextstyle(5,0,5);
  outtextxy(mx/2-1,380,"\nPRESS ANY KEY TO PLAY");
  settextstyle(5,0,5);
  outtextxy(mx/2+1,380,"\nPRESS ANY KEY TO PLAY");
  settextjustify(LEFT_TEXT,TOP_TEXT);
  getch();
  show_main_menu();
  cleardevice();
 }


 //MAIN FUNCTION- THE PROGRAM STARTS HERE
void main()
{
 init();
 FIRSTSCREEN();
 getuser();
 welcomeuser();
}
