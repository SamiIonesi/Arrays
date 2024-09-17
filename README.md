# Arrays
This repository explains the theory behind arrays and the various methods applied to them.

Definition: An array is a build-in data structure that is provided almost by every programming language.

## Arrays representation

Arrays can be represented in two different form in C++:  
- **Static Arrays**: Arrays with a fixed size, determined at compile time.
```cpp
  #include <iostream>
  using namespace std;
  int main()
  {
      int array[] = {1, 2, 3, 4, 5}; //this line of code will create an array in stack with five elements 
      return 0;
  }
```
- **Dynamic Arrays**: Arrays whose size can be determined at runtime, typically managed using pointers and dynamic memory allocation.
```cpp
  #include <iostream>
  using namespace std;
  int main()
  {
      int* array = new int[5]; //this line of code will create an array in heap with five elements 
      return 0;
  }
```

If we look at an array as an Abstract Data Type, then we have to mention that the representation of an array has the following requirements:

1. **Contiguity of Memory**: The elements must be stored in contiguous memory locations.
2. **Fixed Size**: The size of the array must be determined when the array is created.
3. **Direct Access**: Each element can be accessed directly via its index in constant time.
4. **Homogeneity**: All elements in the array must be of the same data type.
5. **Size** is the dimension of an array and **length** is the number of elements present in that array.

And also, an array can perform a number of operations, of which I will mention a few. This operations are member functions of the next class:

```cpp
class Array
{
private:
    int *arr;
    int size;
    int length;

public:
    Array(int size)
    {
        this->size = size;
        arr = new int[size];
        length = 0;
    }

    ~Array()
    {
        delete []arr;
    }

    int* getArr() { return arr; }
    void setSize(int size) { this->size = size; }
    int getSize() { return size;}
    int getLength() { return length; }
}
```

## Array operations

### 1. **Display**

    This function will display all the elements of the array.

    It has a time complexity of **O(n)**.
  
```cpp
void display()
{
    cout << "The elements of the array is: " << endl;

    for(int i = 0; i < length; i++)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
}
```

### 2. **Append**

    This function will add an element at the end of the array.

    It has a time complexity of **O(1)**.
  
```cpp
void append(int value)
{
    if(length < size)
    {
        arr[length] = value;
        length++;
    }
}
```
  
### 3. **Insert**

    This function will add an element at a specific index, with a specific value into the array.

    It has a time complexity of:
    - **Ω(1)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case
  
```cpp
bool insert(int index, int value)
{
    if(index >= 0 && index <= length)
    {
        for(int i = length; i > index; i--)
            arr[i] = arr[i - 1];
        arr[index] = value;
        length++;
        return true;
    }

    return false;
}
```

### 4. **Delete**

    This function will delete an element from a specific index of the array.

    It has a time complexity of:
    - **Ω(1)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case
  
```cpp
int deleteElement(int index)
{
    if(index >= 0 && index < length)
    {
        int temp = arr[index];
        
        for(int i = index; i < length; i++)
        {
            arr[i] = arr[i + 1];
        }

        length--;
        return temp;
    }

    return INT_MIN;
}
```

###  5. **Get**

    This function will return the element present in array from a specific index.

    It has a time complexity of:
    - **Ω(1)** for best case
    - **θ(1)** for average case
    - **O(1)** for worst case
  
```cpp
int get(int index)
{
    if(index >= 0 && index < length)
    {
        return arr[index];
    }

    return INT_MIN;
}
```

### 6. **Set**

    This function will set a specific value to an element from the array given by a specific index.

    It has a time complexity of:
    - **Ω(1)** for best case
    - **θ(1)** for average case
    - **O(1)** for worst case
  
```cpp
bool set(int index, int value)
{
    if(index >= 0 && index < length)
    {
        arr[index] = value;
        return true;
    }
    return false;
}
```

### 7. **Max**

    This function will return the maximum element value from the array.

    It has a time complexity of:
    - **Ω(1)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case
  
```cpp
int max()
{
    if(length >= 0 && length < size)
    {
        int maxElement = arr[0];

        for(int i = 1; i < length; i++)
        {
            if(maxElement < arr[i])
                maxElement = arr[i];
        }
        return maxElement;
    }
    return INT_MIN;
}
```

### 8. **Min**

    This function will return the minimum element value from the array.

    It has a time complexity of:
    - **Ω(1)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case
  
```cpp
int min()
{
    if(length >= 0 && length < size)
    {
        int minElement = arr[0];

        for(int i = 1; i < length; i++)
        {
            if(minElement > arr[i])
                minElement = arr[i];
        }
        return minElement;
    }
    return INT_MIN;
}
```

9. **Sum**

    This function will return the sum of all elements from the array.

    It has a time complexity of:
    - **Ω(n)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case
  
```cpp
int sum()
{
    if(length >= 0 && length < size)
    {
        int sum = 0;

        for(int i = 0; i < length; i++)
            sum += arr[i];

        return sum;
    }
    return INT_MIN;
}
```

10. **Average**

    This function will return the average of all elements from the array.

    It has a time complexity of:
    - **Ω(n)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case
  
```cpp
float avg()
{
    if(length >= 0 && length < size)
    {
        int sum = 0;

        for(int i = 0; i < length; i++)
            sum += arr[i];

        return (float)sum / length;
    }
    return INT_MIN;
}
```

11. **Reverse**

    This function will reverse the array.

    It has a time complexity of:
    - **Ω(1)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case
  
```cpp
void reverse()
{
    if(length >= 0 && length < size)
    {
        for(int i = 0; i < length / 2; i++)
        {
            int temp = arr[i];
            arr[i] = arr[length - i - 1];
            arr[length - i - 1] = temp;
        }
    }
}
```

12. **Left Shift**

    This function will shift to left all the elements from the array by one.

    It has a time complexity of:
    - **Ω(n)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case
  
```cpp
void leftShift()
{
    if(length >= 0 && length < size)
    {
        for(int i = 1; i < length; i++)
            arr[i - 1] = arr[i];
        
        arr[length - 1] = 0;
    }
}
```

13. **Left Rotate**

    This function will rotate to left all the elements from the array.

    It has a time complexity of:
    - **Ω(n)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case
  
```cpp
void leftRotate()
{
    if(length >= 0 && length < size)
    {
        int temp = arr[0];

        for(int i = 1; i < length; i++)
            arr[i - 1] = arr[i];
        
        arr[length - 1] = temp;
    }
}
```

14. **Right Shift**

    This function will shift to right all the elements from the array by one.

    It has a time complexity of:
    - **Ω(n)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case
  
```cpp
 void rightShift()
{
    if(length >= 0 && length < size)
    {
        for(int i = length - 2; i >= 0; i--)
            arr[i + 1] = arr[i];
        
        arr[0] = 0;
    }
}
```

15. **Right Rotate**

    This function will rotate to right all the elements from the array.

    It has a time complexity of:
    - **Ω(n)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case
  
```cpp
void rightRotate()
{
    if(length >= 0 && length < size)
    {
        int temp = arr[length - 1];

        for(int i = length - 2; i >= 0; i--)
            arr[i + 1] = arr[i];
        
        arr[0] = temp;
    }
}
```

16. **Check if an array is sorted**

    This function checks if an array is sorted and returns _true_ if it is; otherwise, it returns _false_.

    It has a time complexity of:
    - **Ω(1)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case
  
```cpp
bool isSorted()
    {
        if(length >= 0 && length < size)
        {
            for(int i = 0; i < length - 1; i++)
            {
                if(arr[i] > arr[i + 1])
                    return false;
            }
            return true;
        }
        return false;
    }
```

17. **Merge**

    This function will merge two sorted arrays into a single sorted array.

    Condition: The input arrays must be sorted.

    It has a time complexity of:
    - **Ω(n)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case
  
```cpp
bool isSorted()
    {
        if(length >= 0 && length < size)
        {
            for(int i = 0; i < length - 1; i++)
            {
                if(arr[i] > arr[i + 1])
                    return false;
            }
            return true;
        }
        return false;
    }
```

18. **Find duplicates in a sorted array**

    This function will find the duplicates in a sorted array and then print the duplicate number along with the number of times it appears.

    Condition: The input arrays must be sorted.

    It has a time complexity of:
    - **Ω(n)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case
  
```cpp
void findDuplicatesInASortedArray()
{
    if(length >= 0 && length < size)
    {
        int count = 0;

        for(int i = 1; i < length; i++)
        {
            while(arr[i] == arr[i - 1])
            {
                count++;
                i++;
            }

            if(count > 0)
            {
                cout << "There ar " << count << " duplicates of " << arr[i - count] << endl;
                count = 0;
            }

        }
    }
}
```

19. **Find duplicates in a unsorted array**

    This function will find the duplicates in a unsorted array and then print the duplicate number along with the number of times it appears.

    It has a time complexity of:
    - **Ω(n)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case
  
```cpp
void findDuplicatesInAUnsortedArray()
{
    int maxNumber = INT_MIN;

    if(length > 0 && length < size)
    {
        for(int i = 0; i < length; i++)
        {
            if(arr[i] > maxNumber)
                maxNumber = arr[i];
        }

        int* hashTable = new int[maxNumber + 1]{0};

        for(int i = 0; i < length; i++)
            hashTable[arr[i]]++;

        for(int i = 0; i < maxNumber + 1; i++)
        {
            if(hashTable[i] > 1)
                cout << "There ar " << hashTable[i] << " duplicates of " << i << endl;
        }
    }
}
```

20. **Find pairs of sum in a sortded array**

    This function will find pairs of numbers in a sorted array that sum to k and will display those pairs.

    It has a time complexity of:
    - **Ω(n)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case
  
```cpp
void pairWithSumKInASortedArray(int sum)
{
    if(length > 0 && length < size)
    {
        int maxElement = arr[length - 1];
        int* hashTable = new int[maxElement]{0};

        for(int i = 0; i < length; i++)
        {
            int diff = 0;

            if(arr[i] < sum)
                diff = sum - arr[i];

            if(hashTable[diff] != 0)
            {
                cout << diff << " + " << arr[i] << " = " << sum << endl;
            }

            hashTable[arr[i]]++;
        }

    }
}
```

There are two methods for searching in an array:

-----

1. **Linear search**

    In this method, we will search for the key (element) in the array in linear mode. 
    
    Workflow: we will check each element in the array for the key; if it's found, then we say that the search was successful; otherwise, the search is unsuccessful.

    Condition: the elements in an array must be unique, there must not be any duplicate elements in the array.

    It has a time complexity of:
    - **Ω(1)** for best case
    - **θ(n)** for average case
    - **O(n)** for worst case
  
```cpp
int liniarSearch(int key)
{
    for(int i = 0; i < length; i++)
    {
        if(arr[i] == key)
            return i;
    }
    return INT_MIN;
}
```

2. **Binary search**

    In this method, we will search for the key (element) in the array in binary mode. 
    
    Workflow: the array will be halved and it will be checked in which half the key fits. This operation is done until finally the key is found at the corresponding index.
    
    Conndition: the array should be sorted.

    It has a time complexity of:
    - **Ω(1)** for best case
    - **θ(log n)** for average case
    - **O( log n)** for worst case
  
```cpp
int binarySearch(int key)
{
    int start = 0;
    int end = length - 1;
    int half;

    while(start <= end)
    {
        half = (start + end) / 2;

        if(key == arr[half])
            return half;
        else if(key < arr[half])
            end = half - 1;
        else if(key > arr[half])
            start = half + 1;
    }

    return -1;
}
```
