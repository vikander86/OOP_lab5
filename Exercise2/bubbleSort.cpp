#include <iostream>
#include <vector>

template <typename T>
class BubbleSort
{
public:
    static void bubbleSort(std::vector<T> &data)
    {
        size_t size = data.size();
        for (size_t i = 0; i < size - 1; i++)
        {
            for (size_t j = 0; j < size - i - 1; j++)
            {
                if (data[j] > data[j + 1])
                {
                    swap(data[j], data[j + 1]);
                }
            }
        }
    }
    static void print(std::vector<T> &data)
    {
        std::cout << "Printing: " << std::endl;
        for (auto &num : data)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

private:
    static void swap(T &dataOne, T &dataTwo)
    {
        T temp = dataOne;
        dataOne = dataTwo;
        dataTwo = temp;
    }
};

int main()
{
    std::vector<int> numbers = {4, 3, 1, 7, 24, 15, 8, 4, 19};
    BubbleSort<int>::print(numbers);

    BubbleSort<int>::bubbleSort(numbers);
    BubbleSort<int>::print(numbers);

    std::vector<float> numbers2 = {4.123, 3.521, 1.854, 7.3452, 24.7544, 15.1235678, 8.975433, 4.9658165, 19.156688};
    BubbleSort<float>::print(numbers2);
    BubbleSort<float>::bubbleSort(numbers2);
    BubbleSort<float>::print(numbers2);

    return 0;
}
