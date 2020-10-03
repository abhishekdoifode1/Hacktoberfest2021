import java.io.*;
import java.util.*;
public class TicTacToeGame
{
public static ArrayList<Integer> avail=new ArrayList<>();
public static Random rn=new Random();
public static boolean found;
    public static int getPoint() {
	return avail.get(rn.nextInt(avail.size()));
     }
    public static void main(String args[])
    {
	try {
	(new ProcessBuilder("cmd","/c","cls").inheritIO().start()).waitFor();
	(new ProcessBuilder("cmd","/c","color 1f").inheritIO().start()).waitFor();
	(new ProcessBuilder("cmd","/c","title TicTacToe").inheritIO().start()).waitFor();
	}
	catch(Exception e) {
	System.out.println("ERRRRR");
	}
    while(true) {
	System.out.println("1:Player vs Computer\n2:Computer vs Player\n3:Player vs Player\n4:Exit");
	System.out.println("\tPress 1 or 2 or 3 or 4\n");
	switch((new Scanner (System.in)).nextInt()) {
	case 1:
	System.out.println("\n");
	    singlePlayer(1);
	break;
	case 2:
	System.out.println("\n");
	    singlePlayer(-1);
	break;
	case 3:
	System.out.println("\n");
	    dualPlayer();
	break;
	case 4:
	try {
	(new ProcessBuilder("cmd","/c","cls").inheritIO().start()).waitFor();
	(new ProcessBuilder("cmd","/c","color 07").inheritIO().start()).waitFor();
	}
	catch(Exception e) {
	System.out.println("ERRRRR");
	}
	    System.exit(0);
	break;
	default :
	    System.out.println("Wrong Input,Try Again\n");
	}
          }
    }
   public static void singlePlayer(int dr) {
	tictactoe tc=new tictactoe();
         Scanner sc=new Scanner (System.in);
         int x=0,y=0;
	int z=0;
	for(int i=0;i<9;i++) {
	avail.add(i);
	}
	try {
	(new ProcessBuilder("cmd","/c","cls").inheritIO().start()).waitFor();
	}
	catch(Exception e) {
	System.out.println("ERRRRR");
	}
	System.out.println(tc.toString());
             System.out.println("____________");
	tc.player=dr;
         do
         {
	found=false;
             System.out.println(tc.player==tc.X ? "player X turn" : "player O turn");
             if(tc.player==tc.X) {
             z=sc.nextInt()-1;
	}
	else {
	for(int i=0;i<avail.size();i++) {
	if(tc.check(avail.get(i),-1,3)) {
	z=avail.get(i);
	found=true;
	}
	}
	if(!found) {
	for(int i=0;i<avail.size();i++) {
	if(tc.check(avail.get(i),1,3)) {
	z=avail.get(i);
	found=true;
	}
	}
	}
	if(!found) {
	for(int i=0;i<avail.size();i++) {
	if(tc.check(avail.get(i),-1,2)) {
	z=avail.get(i);
	found=true;
	}
	}
	}
	if(!found) {
	z=getPoint();
	}
	}
	tc.putSign(z);
	avail.remove((Integer)z);
	try {
	(new ProcessBuilder("cmd","/c","cls").inheritIO().start()).waitFor();
	}
	catch(Exception e) {
	System.out.println("ERRRRR");
	}
	if(tc.warn!=null) {
	System.out.println(tc.warn);
	tc.warn=null;
	}
             System.out.println(tc.toString());
             System.out.println("____________");
             tc.displayWinner();
   } while (tc.isEm);
}
   public static void dualPlayer() {
	tictactoe tc=new tictactoe();
         Scanner sc=new Scanner (System.in);
         int x=0,y=0;
	int z;
	try {
	(new ProcessBuilder("cmd","/c","cls").inheritIO().start()).waitFor();
	}
	catch(Exception e) {
	System.out.println("ERRRRR");
	}
	System.out.println(tc.toString());
             System.out.println("____________");
         do
         {
             System.out.println(tc.player==tc.X ? "player X turn" : "player O turn");
             /*x=sc.nextInt();
             y=sc.nextInt();*/
             z=sc.nextInt()-1;
	tc.putSign(z);
	try {
	(new ProcessBuilder("cmd","/c","cls").inheritIO().start()).waitFor();
	}
	catch(Exception e) {
	System.out.println("ERRRRR");
	}
	if(tc.warn!=null) {
	System.out.println(tc.warn);
	tc.warn=null;
	}
             System.out.println(tc.toString());
             System.out.println("____________");
             tc.displayWinner();
   } while (tc.isEm);
}
}
class tictactoe
{
    public static final int X=1,O=-1;
    public static final int EM=0;
    public int player=X,look=1;
    private int[][]board=new int[3][3];
    private int virtual[][]=new int[3][3];
    private int fboard[][]=new int[3][3];
    public boolean isEm=false;
    public String warn=null;
    public void putSign(int z)
    {
	int x,y;
        if(z<0||z>8)
        {
            warn="Invalid board position";
            return;
             }
	x=z/3;
	y=z%3;
       if(virtual[x][y]!=0) {
	warn=(z+1)+" place already asigned";
	return;
	}
        board[x][y]=player;
        fboard[x][y]=player;
        virtual[x][y]=1;
        player=-player;
    }
    public boolean check(int z,int pl,int c) {
	int x,y;
	x=z/3;
	y=z%3;
	fboard[x][y]=pl;
	if(isFWin(pl,c)) {
	fboard[x][y]=0;
	return true ;
	}
	fboard[x][y]=0;
	return false ;
    }
    public boolean isWin(int player)
    {
        return ((board[0][0]+board[0][1]+board[0][2]==player*3)||(board[1][0]+board[1][1]+board[1][2]==player*3)||
                (board[2][0]+board[2][1]+board[2][2]==player*3)||(board[0][0]+board[1][0]+board[2][0]==player*3)||
                (board[0][1]+board[1][1]+board[2][1]==player*3)||(board[0][2]+board[1][2]+board[2][2]==player*3)||
                (board[2][0]+board[1][1]+board[0][2]==player*3)||(board[0][0]+board[1][1]+board[2][2]==player*3));
    }
    public boolean isFWin(int player,int c)
    {
        return ((fboard[0][0]+fboard[0][1]+fboard[0][2]==player*c)||(fboard[1][0]+fboard[1][1]+fboard[1][2]==player*c)||
                (fboard[2][0]+fboard[2][1]+fboard[2][2]==player*c)||(fboard[0][0]+fboard[1][0]+fboard[2][0]==player*c)||
                (fboard[0][1]+fboard[1][1]+fboard[2][1]==player*c)||(fboard[0][2]+fboard[1][2]+fboard[2][2]==player*c)||
                (fboard[2][0]+fboard[1][1]+fboard[0][2]==player*c)||(fboard[0][0]+fboard[1][1]+fboard[2][2]==player*c));
    }
    public void displayWinner()
    {
        if(isWin(X))
        {
          System.out.println("\n X wins....!\n\n");
          isEm=false;
        }
        else if(isWin(O))
        {
              System.out.println("\n O wins....!\n\n");
          isEm=false;
        }
        else
        {
            if(!isEm)
            {
                 System.out.println("it's tie\n\n");

            }
        }
    }
    public String toString()
    {
	
         StringBuilder s=new StringBuilder();
         isEm=false;
         for(int i=0;i<3;i++)
         {
             for(int j=0;j<3;j++)
             {
                 switch(board[i][j])
                 {
                     case X:
                         s.append("X");
                         break;
                     case O:
                         s.append("O");
                         break;
                     case EM:
		if(look<10) {
                         s.append(Integer.toString(look));
		look++;
		}
		else {
		 s.append(" ");
		}
                         isEm=true;
                         break;
                          }
                 if(j<2)
                 {
                     s.append("|");

                 }
             }
             if(i<2)
             {
                 s.append("\n------\n");

             }

         }
         return s.toString();
    }

}
