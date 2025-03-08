#include <iostream>
#include <stdexcept>

// Функция для поиска пары чисел в массиве, сумма которых равна заданному числу
void findPair(int arr[], int size, int target) {
    // Проверка на корректность входных данных
    if (size <= 1) {
        std::cerr << "Array size must be greater than 1." << std::endl;
        return;
    }

    // Итерация по массиву для поиска пары
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            // Проверка, если сумма двух чисел равна целевому значению
            if (arr[i] + arr[j] == target) {
                std::cout << "Pair found: " << arr[i] << " and " << arr[j] << std::endl;
                return; // Выход из функции после нахождения пары
            }
        }
    }

    // Если пара не найдена
    std::cerr << "No pair found that sums to the target value." << std::endl;
}

int main() {
    int size;
    std::cout << "Enter array size: ";
    std::cin >> size;

    if (size <= 0) {
        std::cerr << "Array size must be a positive integer." << std::endl;
        return 1;
    }

    int* arr = new int[size];

    // Ввод элементов массива
    std::cout << "Enter array elements:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    int target;
    std::cout << "Enter target sum: ";
    std::cin >> target;

    findPair(arr, size, target);

    delete[] arr; // Освобождение памяти

    return 0;
}
