class Node:

    def __init__(self, data):
        self.data = data
        self.next = None

class Queue:

    def __init__(self):
        self.front = None
        self.rear = None


    def isEmpty(self):
        return self.front == None


    def enQueue(self, data):
        temp = Node(data)

        if self.rear == None:
            self.front = temp
            self.rear = temp
            return

        self.rear.next = temp
        self.rear = temp


    def deQueue(self):

        if self.isEmpty():
            return None

        temp = self.front
        data = temp.data
        self.front = temp.next
        temp.next = None

        if (self.front == None):
            self.rear = None

        return data


    def display(self):
        temp = self.front

        if temp is None:
            print("Empty")


        while(temp != None):
            print(temp.data, end=" ")
            if temp.next != None:
                print("->", end=" ")
            temp = temp.next


class Stack:

    def __init__(self):
        self.head = None


    def isempty(self):
        if self.head == None:
            return True
        else:
            return False


    def push(self,data):

        if self.head == None:
            self.head = Node(data)
        else:
            temp = Node(data)
            temp.next = self.head
            self.head = temp


    def pop(self):

        if self.isempty():
            return None

        else:
            temp = self.head
            self.head = self.head.next
            temp.next = None
            return temp.data


    def peek(self):

        if self.isempty():
            return None

        else:
            return self.head.data


    def display(self):

        temp = self.head
        if self.isempty():
            print("Empty")

        else:
            while(temp != None):
                print(temp.data, end=" ")
                if temp.next != None:
                    print("->", end=" ")
                temp = temp.next



choice = int(input("Enter the your choice: \n1) Queue\n2) Stack\nChoice : "))
while choice > 2 or choice < 1:
    print("    Invalid choice.")
    choice = int(input("\nEnter the ds you want to use : \n1) Queue\n2) Stack"))

if choice == 1:
    queue = Queue()

    cont = True
    while cont:
        print("\n\n    Choose the operation on queue")
        print("    1) Enqueue")
        print("    2) Dequeue")
        print("    3) Display")
        print("    0) Exit")
        choice = int(input("    Choice : "))

        if choice == 0:
            print("\nThanks you")
            cont = False

        elif choice == 1:
            data = int(input("        Enter data : "))
            queue.enQueue(data)
            print("\n        Added", data, "to queue.")
            print("        Queue : ", end=" ")
#             queue.display()

        elif choice == 2:
            data = queue.deQueue()
            if data == None:
                print("\n        Noting to dequeue")
            else:
                print("\n        Dequed", data, "from queue.")
                print("        Queue : ", end=" ")
                queue.display()

        elif choice == 3:
            print("\n        Queue : ", end=" ")
            queue.display()

        else:
            print("        Invalid choice")

else:
    stack = Stack()

    cont = True
    while cont:
        print("\n\n    Choose the operation on stack")
        print("    1) Push")
        print("    2) Pop")
        print("    3) Peek")
        print("    4) Display")
        print("    0) Exit")
        choice = int(input("    Choice : "))

        if choice == 0:
            print("\nThanks you")
            cont = False

        elif choice == 1:
            data = int(input("        Enter data : "))
            stack.push(data)
            print("\n        Pushed", data, "to stack.")
            print("        Stack : ", end=" ")
#             stack.display()

        elif choice == 2:
            data = stack.pop()
            if data == None:
                print("\n        stack underflow")
            else:
                print("\n        Popped", data, "from stack.")
                print("        Stack : ", end=" ")
                stack.display()

        elif choice == 3:
            data = stack.peek()
            if data == None:
                print("\n        Stack is empty")
            else:
                print("\n        Stack top =", data)

        elif choice == 4:
            print("\n        Stack : ", end=" ")
            stack.display()

        else:
            print("        Invalid choice")