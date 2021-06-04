using System;
using System.Collections.Generic;
using System.IO;
using System.Text.RegularExpressions;

namespace laboratory6a
{
    class Program
    {
        public static void Main()
        {
            using (var input = new StreamReader("set.in"))
            {
                using (var output = new StreamWriter("set.out"))
                {
                    List<Int64>[] hashTable = new List<Int64>[1000001];
                    while (true)
                    {
                        string inp = input.ReadLine()?.Trim();
                        if (inp == null)
                            break;
                        inp = Regex.Replace(inp, @"\s+", " ");
                        string[] line = inp.Split();
                        Int64 element = Int64.Parse(line[1]);
                        int hashCode = Math.Abs((int) (element % 1000001));

                        switch (line[0])
                        {
                            case "insert":
                                if (hashTable[hashCode] == null)
                                    hashTable[hashCode] = new List<Int64>();
                                if (!hashTable[hashCode].Contains(element))
                                    hashTable[hashCode].Add(element);
                                break;
                            case "exists":
                                output.WriteLine(hashTable[hashCode]?.Contains(element) ?? false ? "true" : "false");
                                break;
                            case "delete":
                                hashTable[hashCode]?.Remove(element);
                                break;
                        }
                    }
                }
            }
        }
    }
}