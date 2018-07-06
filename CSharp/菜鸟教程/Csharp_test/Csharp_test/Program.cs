using System;
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
            tree head = new tree("Root");
            //tree head = new tree("Root");
            head.child = new List<tree>();
            foreach (string key in build_content.Keys)
            {
                string template = build_content[key].base_name;
                // 创建当前key节点
                tree curTree = new tree(key);
                if (template != null)
                {
                    // 将当前cur 节点添加到 搜索到的 节点（如果搜索完还没有找到，先创建，再添加）
                    List<tree> find = null;
                    FindTree(head, template, ref find);
                    if (find == null)
                    {
                        tree tempTree = new tree(template);
                        if (tempTree.child == null)
                        {
                            tempTree.child = new List<tree>();
                        }
                        tempTree.child.Add(curTree);
                        head.child.Add(tempTree);
                    }
                    else
                    {
                        if (find.Count == 1)
                        {
                            if (find[0].child == null)
                            {
                                find[0].child = new List<tree>();
                            }
                            find[0].child.Add(curTree);
                        }
                        else
                        {
                                
                        }
                    }
                }
                else
                {
                    // 将当前节点添加为1级节点
                    head.child.Add(curTree);
                }


            }
        }

        //构建空树 floors：构建层数 head：根节点 sonnumber：子节点数量 sonvalue：子节点值
        static void buildTree(int floors, tree head, int sonnumber, int sonvalue)
        {
            if (floors == 1)
                return;
            head.child = new List<tree>();
            for (int i = 0; i != sonnumber; i++)
                head.child.Add(new tree(sonvalue + 1));
            foreach (tree temp_tree in head.child)
                buildTree(floors - 1, temp_tree, sonnumber, sonvalue + 1);
        }
        //先序遍历
        static void readTree(tree head)
        {
            Console.WriteLine(head.value);
            if (head.child != null)
            {
                foreach (tree temp_tree in head.child)
                    readTree(temp_tree);
            }
        }
        //按层遍历
        static void bfsTree(tree head)
        {
            Queue<tree> queueTree = new Queue<tree>();
            queueTree.Enqueue(head);
            while (queueTree.Count != 0)
            {
                Console.WriteLine(queueTree.Peek().value);
                if (queueTree.Peek().child != null)
                {
                    foreach (tree temp_tree in queueTree.Peek().child)
                    {
                        queueTree.Enqueue(temp_tree);
                    }
                }
                queueTree.Dequeue();
            }
        }

        // dfs
        static public void FindTree(tree head, string value, ref List<tree> res)
        {
            //Console.WriteLine(head.value);
            if (head.value.CompareTo(value) == 0)
            {
                res.Add(head);
            }
            if (head.child != null)
            {
                foreach (tree temp_tree in head.child)
                {
                    FindTree(temp_tree, value, ref res);
                }

            }
        }

    } // class        


    class tree
    {
        public int value;
        public List<tree> child;

        public tree(int treeValue)
        {
            value = treeValue;
        }
    }

}// namespace
