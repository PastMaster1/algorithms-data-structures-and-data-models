using Xunit;
using AlgorithmsOnCs;
namespace MinStackTests;

public class StructureMinStackTests
{
    [Fact]
    public void PrintEmptyStack()
    {
        using (var stringWriter = new StringWriter())
        {
            var originalOutput = Console.Out;
            Console.SetOut(stringWriter);
            try
            {
                MinStack stack = new MinStack();
                stack.PrintStack();
                var actualOutput = stringWriter.ToString();
                Assert.Equal($"Stack is empty{Environment.NewLine}", actualOutput);
            }
            finally
            {
                Console.SetOut(originalOutput);
            }
        }
    }

    [Fact]
    public void PrintNotEmptyStack()
    {
        using (var stringWriter = new StringWriter())
        {
            var originalOutput = Console.Out;
            Console.SetOut(stringWriter);
            try
            {
                MinStack stack = new MinStack();
                stack.Push(1);
                stack.Push(2);
                stack.Push(3);
                stack.PrintStack();
                var actualOutput = stringWriter.ToString();
                Assert.Equal($"3{Environment.NewLine}2{Environment.NewLine}1{Environment.NewLine}", actualOutput);
            }
            finally
            {
                Console.SetOut(originalOutput);
            }
        }
    }

    [Fact]
    public void CalculateSizeOfEmptyStack()
    {
        MinStack stack = new MinStack();
        var exception = Assert.Throws<InvalidOperationException>(() =>
        {
            stack.Count();
        });
        Assert.Equal("Stack is empty", exception.Message);
    }
    
    [Fact]
    public void CalculateSizeOfNotEmptyStack()
    {
        MinStack stack = new MinStack();
        stack.Push(1);
        stack.Push(2);
        stack.Push(3);
        int size = stack.Count();
        Assert.Equal(3, size);
    }

    [Fact]
    public void TopElementOfEmptyStack()
    {
        MinStack stack = new MinStack();
        var exception = Assert.Throws<InvalidOperationException>(() =>
        {
            stack.Top();
        });
        Assert.Equal("Stack is empty", exception.Message);
    }

    [Fact]
    public void TopElementOfNotEmptyStack()
    {
        MinStack stack = new MinStack();
        stack.Push(1);
        stack.Push(2);
        stack.Push(3);
        int d = stack.Top();
        Assert.Equal(3, d);
    }

    [Fact]
    public void DeleteElementFromEmptyStack()
    {
        MinStack stack = new MinStack();
        var exception = Assert.Throws<InvalidOperationException>(() =>
        {
            stack.Pop();
        });
        Assert.Equal("Stack is empty", exception.Message);
    }

    [Fact]
    public void DeleteElementFromNotEmptyStack()
    {
        using (var stringWriter = new StringWriter())
        {
            var originalOutput = Console.Out;
            Console.SetOut(stringWriter);
            try
            {
                MinStack stack = new MinStack();
                stack.Push(1);
                stack.Push(2);
                stack.Push(3);
                stack.Pop();
                stack.PrintStack();
                var actualOutput = stringWriter.ToString();
                Assert.Equal($"2{Environment.NewLine}1{Environment.NewLine}", actualOutput);
            }
            finally
            {
                Console.SetOut(originalOutput);
            }
        }
    }

    [Fact]
    public void GetMinValueFromEmptyStack()
    {
        MinStack stack = new MinStack();
        var exception = Assert.Throws<InvalidOperationException>(() =>
        {
            stack.GetMin();
        });
        Assert.Equal("Stack is empty", exception.Message);
    }

    [Fact]
    public void GetMinValueFromNotEmptyStack()
    {
        MinStack stack = new MinStack();
        stack.Push(1);
        stack.Push(2);
        stack.Push(3);
        int minValue = stack.GetMin();
        Assert.Equal(1, minValue);
    }
}
