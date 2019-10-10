#include<iostream>
using namespace std;


class Queue
{
private:
        int* queue_container;
        int queue_size, max_size;
        int front, rear;
        
        void allocate_new_memory()
        {
           max_size = queue_size * 2; 
           int * temporary_array = new int [max_size];
           for(int i = 0; i < queue_size; i++)
           {
               temporary_array[i] = queue_container[front + i];
           }
           delete[] queue_container;
           queue_container = temporary_array;
        }
public:
        //Constructor will set front and rear as -1
        //assuming that for an empty queue, both 
        // front and rear will be -1
        Queue()
        {
            front = -1;
            rear = -1;
            max_size = 20;
            queue_container = new int[max_size];
            queue_size = 0;
        }
        
        Queue(int i)
        {
            front = -1;
            rear = -1;
            max_size = i;
            queue_container = new int[max_size];
            queue_size = 0;   
        }
        
        Queue(const Queue&);
        
        ~Queue()
        {
            delete[] queue_container;
        }
        
        int operator[](int i)
        {
            return queue_container[i];
        }

        int size()
        {
            return queue_size;
        }

        // to check whether Que is empty or not
        bool empty()
        {
            return (front == -1 && rear == -1);
        }

        // check if que is full or not
        bool is_full()
        {
            return (rear+1)%max_size == front ? true : false;
        }

        //Inserts an element in queue at rear end.
        void push(int x)
        {
            cout << "Inserting element " 
                 << x << " at back of queue. \n";
            if (is_full())
            {
                allocate_new_memory();
            }
            if (empty())
            {
                front = rear = 0;
            }
            else
            {
                rear = (rear + 1) % max_size;
            }
            queue_container[rear] = x;
            queue_size++;
            
        }
        //Removes an element in Queue from front end.
        void pop()
        {
            cout << "Popping first element from queue \n";
            if(empty())
            {
                cout << "error: Queue is Empty\n";
                return;
            }
            else if(front == rear)
            {
                rear = front = -1;
            }
            else
            {
                front = (front + 1) % max_size;
            }

            queue_size--;
            
        }

        int Front() // Returns element at the front of queue.
        {
            if(front == -1)
            {
                cout << "Error cannot return front from empty queue\n";
                return -1;
            }
            return queue_container[front];
        }
        /*
            printing the elements in queue from front to rear.
            this finction is only to test the code.
        */
       void print()
       {
           //Finding the number of elemints in queue
           int count = (rear + max_size - front) % max_size + 1;
           cout << "Queue   : ";
           for(int i = 0; i < count; i++)
           {
               int index = (front + i) % max_size; // Index of the element while traversing the circular array from front
               cout << queue_container[index] << " ";
           }
           cout << "\n\n";
       }
};



int main()
{
    Queue que;
    int element = 1;
    for (int i = 0; i < 19 ; i++)
    {
        que.push(element++);
        que.print();
    }

    cout << "The size of your Queue is ";
    cout << que.size() << "\n\n";
    
    for (int i = 0; i < 25 ; i++)
    {
        que.pop();
        que.print();
    }
    return 0;
}