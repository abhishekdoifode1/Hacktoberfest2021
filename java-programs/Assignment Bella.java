import java.util.Scanner;

class employee1
{
    String name;
    String mailid;
    String address;
    String mobileno;
    int empid;
    public
    void getdata()
    {
        System.out.println("enter name,mailid,address,mobileno,empid");
        Scanner input=new Scanner(System.in);
        name=input.nextLine();
        mailid=input.nextLine();
        address=input.nextLine();
        mobileno=input.nextLine();
        empid=input.nextInt();
    }
    void display()
    {
        System.out.println("Payslip details are:");
        System.out.println("name="+name);
        System.out.println("mailid="+mailid);
        System.out.println("address="+address);
        System.out.println("empid="+empid);
        System.out.println("mobileno="+mobileno);
    }
}
class programmer extends employee1
{
    double BP;
    
    void calculate()
    {
        double DA,HRA,PF,SCF,GP,NP;
        System.out.println("enter basic pay OF PROGRAMMER");
        Scanner input=new Scanner(System.in);
        BP=input.nextDouble();
        DA=0.97*BP;
        HRA=0.1*BP;
        PF=0.12*BP;
        SCF=0.001*BP;
        GP=BP+DA+HRA;
        NP=GP-PF-SCF;
        display();
        System.out.println("Gross pay="+GP);
        System.out.println("Net salary="+NP);
    }
}

class teamlead extends employee1
{
    double BP;
    void calculate()
    {
        double DA,HRA,PF,SCF,GP,NP;
        System.out.println("enter basic pay of TEAMLEAD");
        Scanner input1=new Scanner(System.in);
        BP=input1.nextDouble();
        DA=0.97*BP;
        HRA=0.1*BP;
        PF=0.12*BP;
        SCF=0.001*BP;
        GP=BP+DA+HRA;
        NP=GP-PF-SCF;
        display();
        System.out.println("Gross pay="+GP);
        System.out.println("grosspay="+GP);
    }
}
class apm extends employee1
{
    double BP;
    void calculate()
    {
        double DA,HRA,PF,SCF,GP,NP;
        System.out.println("enter basic pay of APM");
        Scanner input1=new Scanner(System.in);
        BP=input1.nextDouble();
        DA=0.97*BP;
        HRA=0.1*BP;
        PF=0.12*BP;
        SCF=0.001*BP;
        GP=BP+DA+HRA;
        NP=GP-PF-SCF;
        display();
        System.out.println("Gross pay="+GP);
        System.out.println("grosspay="+GP);
    }
}
class pm extends employee1
{
    double BP;
    void calculate()
    {
        double DA,HRA,PF,SCF,GP,NP;
        System.out.println("enter basic pay of PM");
        Scanner input1=new Scanner(System.in);
        BP=input1.nextDouble();
        DA=0.97*BP;
        HRA=0.1*BP;
        PF=0.12*BP;
        SCF=0.001*BP;
        GP=BP+DA+HRA;
        NP=GP-PF-SCF;
        display();
        System.out.println("Gross pay="+GP);
        System.out.println("grosspay="+GP);
    }
}
class Main {
    public static void main(String args[]) {
        programmer obj=new programmer();
        obj.getdata();
        //obj.display();
        obj.calculate();
        teamlead obj1=new teamlead();
        obj1.getdata();
        //obj1.display();
        obj1.calculate();
        apm obj2=new apm();
        obj2.getdata();

        //obj2.display();
        obj2.calculate();
        pm obj3=new pm();
        obj3.getdata();
        //obj3.display();
        obj3.calculate();
        }
        
}
