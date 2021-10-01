using System;

namespace ClassAndObject
{
    class Cat
    {
        string name, type, color;
        int age;

        public Cat() { }

        public Cat(string name, string type, string color, int age)
        {
            this.Name = name;
            this.Type = type;
            this.Color = color;
            this.Age = age;
        }

        public string Name { get => name; set => name = value; }
        public string Type { get => type; set => type = value; }
        public string Color { get => color; set => color = value; }
        public int Age { get => age; set => age = value; }

        public void showCat()
        {
            Console.WriteLine("Cat name : " + Name);
            Console.WriteLine("Cat breed : " + Type);
            Console.WriteLine("Cat color : " + Color);
            Console.WriteLine("Cat age : " + Age + " years old");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            //Entering data directly
            Cat Catdirectly = new Cat("Moza", "Persia", "White", 3);
            Catdirectly.showCat();

            //Separator
            Console.WriteLine("================= \n");

            //Entering data using input from the user 
            Cat catInput = new Cat();
            Console.WriteLine("Enter cat name : "); catInput.Name = Console.ReadLine();
            Console.WriteLine("Enter cat type : "); catInput.Type = Console.ReadLine();
            Console.WriteLine("Enter cat color : "); catInput.Color = Console.ReadLine();
            Console.WriteLine("Enter cat age : "); catInput.Age = Convert.ToInt32(Console.ReadLine());
            catInput.showCat();
            Console.ReadLine();
        }
    }
}