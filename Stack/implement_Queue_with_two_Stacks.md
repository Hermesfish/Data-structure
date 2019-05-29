### 问题描述
用两个栈实现队列。
已知栈的4个运算定义如下：
```
Push(S, x);                // 元素x入栈S
Pop(S, x);                 // S出栈并将出栈的值赋给x
StackEmpty(S);             // 判断栈是否为空
StackOverflow(S);          // 判断栈是否满
```
利用栈的运算实现队列的3个运算？
```
Enqueue(Q, x);             // 元素x入队
Dequeue(Q, x);             // 出队，并将出队元素赋值给x
QueueEmpty(Q);             // 判断队列是否为空
```

实际实现：
```
QueueEmpty(S1, S2);        // 如果两个栈均为空，则队列为空
```