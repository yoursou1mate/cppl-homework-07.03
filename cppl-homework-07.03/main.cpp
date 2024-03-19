//
//  main.cpp
//  cppl-homework-07.03
//
//  Created by a1ex on 2/28/24.
//

#include <iostream>
#include <exception>

class ErrorException : public std::exception
{
public:
   const  char* what() const noexcept override
   {
       return "Wrong index!";
   }
};


template<class T>
class my_vector
{
private:
    unsigned size = 0;
    unsigned capacity = 0;
    T *arr = new T[size];
public:
    my_vector(){++capacity;}

    my_vector (const my_vector &other)
    {
        size = other.size;
        capacity = other.capacity;
        arr = new T[size];
        for (int i = 0; i < size; ++i)
          {
            arr[i] = other.arr[i];
          }
    }

    my_vector (my_vector &&other)
    {
     size = other.size;
     capacity = other.capacity;
     arr = other.arr;
     other.size = 0;
     other.capacity = 0;
     other.arr = nullptr;
    }
    my_vector &operator=(const my_vector &other)
    {
     if (this == &other)
      {
        return *this;
      }
    }
    my_vector &operator=(my_vector &&other)
    {
     if (this == &other)
      {
        return *this;
      }
    }

    ~my_vector()
    {
        delete [] arr;
    }

    T at(int index) const
    {
        if (index < 0 || index >= size)
        {
            throw ErrorException();
        }
        return arr[index];
    }

    void push_back(T value)
    {
        if(size == capacity)
        {
            capacity = capacity*2;
            T* new_arr = new T[capacity];
            for(int index = 0; index < size; ++index)
            {
                new_arr[index] = arr[index];
            }
            delete[] arr;
            arr = new_arr;
        }
            arr[size] = value;
            ++size;

    }

    int Size() const
    {
        return size;
    }

    int Capacity() const
    {
        return capacity;
    }

};

int main(int argc, const char * argv[]) {

    my_vector<int> v1;

    v1.push_back(4);
    v1.push_back(15);
    v1.push_back(21);
    v1.push_back(5);
    v1.push_back(1);
    v1.push_back(1);
    v1.push_back(1);
    v1.push_back(1);
    v1.push_back(1);

    try {
        std::cout << "Your index is: " << 2 << std::endl << "Element is: " << v1.at(1) << '\n';
    } catch (const ErrorException& ex) {
        std::cout << ex.what() << std::endl;
    }
    std::cout << "Vector size is: " << v1.Size() << '\n';
    std::cout << "Vector capacity is: " << v1.Capacity() << '\n';


    return 0;
}
