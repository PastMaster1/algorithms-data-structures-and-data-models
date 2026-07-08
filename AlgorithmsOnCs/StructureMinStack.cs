namespace AlgorithmsOnCs;

public class MinStack
{
    private class Node
    {
        public int data;
        public Node? previous;
        public int min_data;
        public int count;
        public Node(int value)
        {
            data = value;
            previous = null;
        }
    }
    private Node? current;
    public MinStack()
    {
        current = null;
    }
    public void Push(int value)
    {
        Node node = new Node(value);
        if (!IsEmpty())
        {
            node.previous = current;
            node.min_data = ((value < current!.min_data) ? value : current!.min_data);
            node.count = current.count + 1;
        }
        else
        {
            node.min_data = value;
            node.count = 1;
        }
        current = node;
    }
    public bool IsEmpty()
    {
        return (current == null);
    }
    public void Pop()
    {
        if (IsEmpty())
        {
            throw new InvalidOperationException("Stack is empty");
        }
        else
        {
            current = current!.previous;
        }
    }
    public int Top()
    {
        if (IsEmpty())
        {
            throw new InvalidOperationException("Stack is empty");
        }
        return current!.data;
    }
    public int GetMin()
    {
        if (IsEmpty())
        {
            throw new InvalidOperationException("Stack is empty");
        }
        return current!.min_data;
    }
    public int Count()
    {
        if (IsEmpty())
        {
            return 0;
        }
        return current!.count;
    }
    public void PrintStack()
    {
        if (IsEmpty())
        {
            Console.WriteLine("Stack is empty");
        }
        else
        {
            Node? cur = current!;
            while (cur != null)
            {
                Console.WriteLine(cur.data);
                cur = cur.previous;
            }
        }
    }
}