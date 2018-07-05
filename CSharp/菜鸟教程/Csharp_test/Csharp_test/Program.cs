using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_test
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            string path = @"C:\Users\xixie\workshop_tmp\Client\UnityProj\Assets\Languages\build_define.json";
            string content = File.ReadAllText(path);
            int changedBeginPos = content.IndexOf("garena_southeast_asia_mys_show");
            



            // Keep the console window open in debug mode.
            Console.WriteLine("Press any key to exit.");
            Console.ReadKey();
        }
    }
}
