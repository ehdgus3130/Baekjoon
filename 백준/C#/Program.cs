using System;

class Program
{
    static void Main()
    {

        string input = Console.ReadLine();
        string[] num = input.Split(' ');

        long H = long.Parse(num[0]);
        long W = long.Parse(num[1]);
        long N = long.Parse(num[2]);
        long M = long.Parse(num[3]);
        

        long rows = (H + N) / (N + 1);
        long cols = (W + M) / (M + 1);

        Console.WriteLine(rows * cols);
    }
}