#include <iostream>

using namespace std;

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

    void display()
    {
        cout << "The elements of the array is: " << endl;

        for(int i = 0; i < length; i++)
        {
            cout << "arr[" << i << "] = " << arr[i] << endl;
        }
    }

    bool insert_method1(int index, int value)
    {
        if(index < 0 && index >= size && index > length)
            return false;
        else
        {
            int prev;
            int next = arr[index];

            for(int i = index; i < size; i++)
            {
                prev = next;
                next = arr[i];

                if(i == index)
                    arr[i] = value;
                else
                    arr[i] = prev;
            }
        }

        length++;
        return true;
    }

    bool insert_method2(int index, int value)
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

    void append(int value)
    {
        if(length < size)
        {
            arr[length] = value;
            length++;
        }
    }

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

    int liniarSearch(int key)
    {
        for(int i = 0; i < length; i++)
        {
            if(arr[i] == key)
                return i;
        }
        return INT_MIN;
    }

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

    int get(int index)
    {
        if(index >= 0 && index < length)
        {
            return arr[index];
        }

        return INT_MIN;
    }

    bool set(int index, int value)
    {
        if(index >= 0 && index < length)
        {
            arr[index] = value;
            return true;
        }
        return false;
    }

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

    void leftShift()
    {
        if(length >= 0 && length < size)
        {
            for(int i = 1; i < length; i++)
                arr[i - 1] = arr[i];
            
            arr[length - 1] = 0;
        }
    }

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

    void rightShift()
    {
        if(length >= 0 && length < size)
        {
            for(int i = length - 2; i >= 0; i--)
                arr[i + 1] = arr[i];
            
            arr[0] = 0;
        }
    }

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

    int insertInASortedArray(int value)
    {
        if(length >= 0 && length < size)
        {
            for(int i = length - 1; i > 0; i--)
            {
                if(value < arr[i])
                    arr[i + 1] = arr[i];
                else if(value > arr[i])
                {
                    arr[i + 1] = value;
                    length++;
                    return i;
                }
                else
                {
                    cout << "This value is already in the array" << endl;
                    return i;
                }
            }
        }
        return -1;
    }

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

    void rearrange()
    {
        if(length >= 0 && length < size)
        {
            int* newArr = new int[length];
            int leftIndex = 0;
            int rightIndex = length - 1;

            for(int i = 0; i < length; i++)
            {
                if(arr[i] < 0)
                {
                    newArr[leftIndex] = arr[i];
                    leftIndex++;
                }
                else
                {
                    newArr[rightIndex] = arr[i];
                    rightIndex--;
                }
            }

            for(int i = 0; i < length; i++)
                arr[i] = newArr[i];

            delete []newArr;
        }
    }

    void merge(int* arr1, int* arr2, int lengthArr1, int lengthArr2)
    {
        int mergedLength = lengthArr1 + lengthArr2;

        if(mergedLength > size)
            arr = new int[mergedLength];
        else
            length = mergedLength;

        int indexArr = 0, indexArr1 = 0, indexArr2 = 0;

        while((indexArr1 + indexArr2) != mergedLength)
        {
            if(indexArr1 == lengthArr1)
            {
                arr[indexArr] = arr2[indexArr2];
                indexArr++;
                indexArr2++;
            }
            else if(indexArr2 == lengthArr2)
            {
                arr[indexArr] = arr1[indexArr1];
                indexArr++;
                indexArr1++;
            }
            else if(arr1[indexArr1] < arr2[indexArr2])
            {
                arr[indexArr] = arr1[indexArr1];
                indexArr++;
                indexArr1++;
            }
            else if(arr1[indexArr1] > arr2[indexArr2])
            {
                arr[indexArr] = arr2[indexArr2];
                indexArr++;
                indexArr2++;
            }
            else
            {
                arr[indexArr] = arr1[indexArr1];
                indexArr++;
                indexArr1++;
                indexArr2++;
                length--;
            }
        }
    }

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

    void pairWithSumKInAUnsortedArray(int sum)
    {
        if(length > 0 && length < size)
        {
            for(int i = 0; i < length; i++)
            {
                for(int j = i + 1; j < length; j++)
                {
                    if(arr[j] != INT_MIN)
                    {
                        if((arr[j] + arr[i]) == sum)
                        {
                            cout << arr[j] << " + " << arr[i] << " = " << sum << endl;
                            arr[j] = INT_MIN;
                        }

                        if(arr[j] == sum)
                        {
                            cout << arr[j] << " = " << sum << endl;
                            arr[j] = INT_MIN;
                        }
                    }
                }
            }
                    
        }
    }

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

    void minMaxSingleScan()
    {
        if(length > 0 && length < size)
        {
            int minElement = INT_MAX;
            int maxElement = INT_MIN;

            for(int i = 0; i < length; i++)
            {
                if(arr[i] < minElement)
                    minElement = arr[i];
                
                if(arr[i] > maxElement)
                    maxElement = arr[i];
            }

            cout << "Min element from array is " << minElement << endl;
            cout << "Max element from array is " << maxElement << endl;
        }
    }



};

int main()
{

    Array* myArray = new Array(15);
    
    myArray->append(1);
    myArray->append(2);
    myArray->append(4);
    myArray->append(6);
    myArray->append(8);
    myArray->append(9);
    myArray->append(10);
    myArray->append(11);
    myArray->append(19);
    myArray->append(20);
    myArray->append(21);

    myArray->minMaxSingleScan();

    return 0;
}
