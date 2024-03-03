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
    unsigned capacity = 1;
    T *arr = new T[size];
public:
    my_vector()
    {
        this->size = size;
        this->capacity = capacity;
        this->arr = arr;
    }
    
    my_vector (const my_vector &other)
    {
        this->size = other.size;
        this->capacity = other.capacity;
        this->arr = other.arr;
    }
    
    ~my_vector()
    {
        delete [] arr;
    }

    T at(int index) const
    {
        T elem;
        if(index < size && index > 0)
          {
               elem = arr[index];
          }
        else
          {
              throw ErrorException();
          }
        return elem;
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

    try {
        std::cout << "Your index is: " << 2 << std::endl << "Element is: " << v1.at(1) << '\n';
    } catch (const ErrorException& ex) {
        std::cout << ex.what() << std::endl;
    }
//    std::cout << "Your index is: " << 2 << std::endl << "Element is: " << v1.at(1) << '\n';
    std::cout << "Vector size is: " << v1.Size() << '\n';
    std::cout << "Vector capacity is: " << v1.Capacity() << '\n';


    return 0;
}
