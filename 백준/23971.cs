using System;
using static System.Console;
class Program
{
    static void main()
    {
        string input = Console.ReadLine();
        string[] num = input.Split(' ');

        long H = num[0];
        long W = num[1];
        long N = num[2];
        long M = num[3];


        long rows = (H + N) / (N + 1);
        long cols = (W + M) / (M + 1);

        Console.WriteLine(rows * cols);
    }
}