using System; 
class Triangle //5073
{
    static void Main(string[] args)
    {

        while (true)
        {
            string? s = Console.ReadLine();
            if (s is null) break;
            
            string[] num = s.Split(' ');

            int a = int.Parse(num[0]);
            int b = int.Parse(num[1]);
            int c = int.Parse(num[2]);
            Array.Sort(num);

            if ((a == 0) && (b == 0) && (c == 0)) break;
            else if ((a == b) && (b == c)) { Console.WriteLine("Equilateral"); }
            else if (a + b <= c) { Console.WriteLine("Invalid"); }
            else if ((a == b) || (b == c) || (c == a)) { Console.WriteLine("Isosceles"); }
            else { Console.WriteLine("Scalene"); }
        }
    }
}