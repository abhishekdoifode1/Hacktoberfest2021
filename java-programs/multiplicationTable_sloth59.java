public class Program
{
	public static void main(String[] args) {


	   // look at the end for this method
	   Straightline();

	//beginning of actual multiplication
	// the row elements as i
	for(int i=1;i<11;i++){
	System.out.print("|");
		 //the column elements as j
		for(int j=1;j<11;j++){
		 // the whole if procedure to make all digits occupy a space equivalent to 3 digits
		if (i*j>9&&i*j<100){
			System.out.print(" "+i*j+"|");
			}else if(i*j<10){
			System.out.print("  "+i*j+"|");
		}else{
			System.out.print(i*j+"|");
		}
}	//end of for j loop       
	Straightline();
} //end of for i loop
	
	
}//main method ends here
	
	
	//a method that creates a staright line looking output
	public static void Straightline(){
		for(int b=1;b<11;b++){
			System.out.print("*---");
			}
	System.out.println("*");
	    } 
	
}//the class Program ends here
