Stack Machines (Machine = Autonomous Data Processor)
    A computer that uses a stack for short term data storage.
        Storage for operations ot be performed.

Register Machines
    A computer that uses registers for short term data.
    Fast because they're right next to the CPU.

3 + 4 * 7
    push 4
    push 7
    mult
    push 3
    add

1 + 2 + 3
    push 1
    push 2
    add
    push 3
    add

    pre: + + 1 2 3
    post: 3 2 1 + +

6 * 7 + 3
    push 6
    push 7
    mult
    push 3
    add

    pre: + * 6 7 3
    post: 3 6 7 * +

3 * 2 / 4
    push 3
    push 2
    mult
    push 4
    div

    pre: * 3 / 2 4
    post: 4 3 2 * /

Infix
    Operator is written between operands

Prefix
    Operator goes before operands

Postfix
    Operator goes after operands

Input from user: fgets/scanf
Stack: array
Operations: if/else/switch

// structs are classes but just less complicated
struct stack {
    int *top;
    int *bottom;
};

void push (struct stack *s, int val)
{
    (*s).top = (*s).top + 1;
    (*s).top = val;
    *(*s).top = 7;
}

push (_, 7);

int main()
{
    struct stack bucket;
    bucket.bottom = malloc(sizeof(int) * 256);
    bucket.top = buket.bottom;

    // malloc goes on the heap so remember to free it
}

