#include <iostream>

enum Command
{
    Push = 1,
    Pop = 2,
    Exit = 3
};

const int STACK_SIZE{ 10 };

struct Stack
{
    int array[STACK_SIZE]{};
    int topIndex{-1};
};

void PrintInfo()
{
    std::cout << "<STACK>" << std::endl;
    std::cout << "[1] push" << std::endl;
    std::cout << "[2] pop" << std::endl;
    std::cout << "[3] exit" << std::endl;
    std::cout << "------------" << std::endl;
}

void printStack(Stack& stack)
{
    std::cout << "<STACK>" << std::endl;
    if (stack.topIndex < 0)
    {
        std::cout << "EMPTY" << std::endl;
    }
}
void PushStack(Stack& stack, int value)
{
    if (stack.topIndex >= STACK_SIZE - 1)
    {
        std::cout << "스택이 가득 찼습니다!! 더 이상 추가할 수 없어요!" << std::endl;
        return;
    }
    stack.array[++stack.topIndex] = value;
}

void PopStack(Stack& stack)
{
    if (stack.topIndex < 0)
    {
        std::cout << "스택이 비어 있습니다!! 더 이상 꺼낼 수 없어요!" << std::endl;
        return;
    }
    std::cout << stack.array[stack.topIndex--] << "를 꺼냇습니다." << std::endl;
}

void ProcessUserInput(Stack& stack)
{
    int command{};
    bool isExit{ false };

    while (true)
    {
        printStack(stack);
        std::cout << std::endl << "> ";
        std::cin >> command;
        switch (command)
        {
            case Push:
                int value;
                std::cout << "    value>>" ;
                std::cin >> value;
                    PushStack(stack, value);
            break;
            case Pop:
                PopStack(stack);
                break;
            case Exit:
                isExit = true;
                break;
            default:
                std::cout << "잘못된 명령어 입니다 ." << std::endl;
                break;
        }
        if (isExit)
        {

        }
    }
}



int main()
{
    Stack myStack;

    PrintInfo();
    ProcessUserInput(myStack);
}