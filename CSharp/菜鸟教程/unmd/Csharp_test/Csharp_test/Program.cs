using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_test
{ 
    public class Customer
    {
        public virtual string Name
        {
            get;
            set;
        }

        int[] theValues = new int[3] { 1, 2, 3 };
        public int this[int index]      // 相当于实现了运算符重载 int operator[](int index){}
        {
            get { return theValues[index]; }
            set { theValues[index] = value; }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Customer obj = new Customer();
            obj.Name = "good";
            Console.WriteLine(obj.Name);


            int val = obj[1];
            Console.WriteLine(val);
            Console.ReadKey();

        }
       

    } // class        


}// namespace
