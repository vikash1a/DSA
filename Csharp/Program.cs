using System;

namespace Csharp
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            test();
        }
        private static void test(){
            Console.WriteLine("Hello for test method");
            LinkedList linkedList = new LinkedList();
            Console.WriteLine("linkedList val -> "+linkedList.val);
            linkedList.next = new LinkedList(1);
            linkedList.print(linkedList);
            return;
        }
    }
    public class LinkedList
    {
        public int val { get; set; }
        public LinkedList next { get; set; }
        public LinkedList(int val = 0)
        {
            this.val = val;
        }
        public void print(LinkedList linkedList ){
            while(linkedList!=null){
                Console.Write(linkedList.val+" ");
                linkedList = linkedList.next;
            }
            Console.Write("\n");
            return;
        }
    }
}
