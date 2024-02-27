#include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include <fstream>
#include <iterator>
#include <deque>

int main() {
    std::vector<int> numbers;
    int size;
    std::cout << "Enter size: " << std::endl;
    std::cin >> size;
    std::cout << "Enter numbers: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        int num;
        std::cin >> num;
        numbers.push_back(num);
    }


// Вывод всех чисел
    std::cout << "All numbers: ";
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

// Сортировка чисел
    std::sort(numbers.begin(), numbers.end());
    std::cout << "Sorted numbers: ";
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

// Поиск числа
    int findnum;
    std::cout << "Enter a number to search: ";
    std::cin >> findnum;
    std::cout << std::endl;
    auto it = std::find(numbers.begin(), numbers.end(), findnum);
    if (it != numbers.end()) {
        std::cout << "Number found at index: " << std::distance(numbers.begin(), it) + 1 << std::endl;
    } else {
        std::cout << "Number not found" << std::endl;
    }

// Перестановка чисел
    std::rotate(numbers.begin(), numbers.begin() + 2, numbers.end());
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

// back_inserter
    std::back_insert_iterator<std::vector<int>> backit(numbers);
    *backit = 1372;

// inserter
    std::insert_iterator<std::vector<int>> insert(numbers, numbers.begin() + 3);
    *insert = 456738;

// List
    std::list<int> listik = {1, 2, 3, 4, 5};

// back_inserter
    std::back_insert_iterator<std::list<int>> back_it(listik);
    *back_it = 6;

// front_inserter
    std::front_insert_iterator<std::list<int>> front_it(listik);
    *front_it = 4675;

// inserter
    std::insert_iterator<std::list<int>> ins_it(listik, ++listik.begin());
    *ins_it = 9734;

    std::cout << "List after inserting elements: ";
    for (const auto& elem : listik) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

// Files
    {
        {
            std::ofstream outputFile("test.txt");
            if (outputFile.is_open())
            {
                std::string phrase = "Hello, world!\n";
                std::copy(phrase.begin(), phrase.end(), std::ostream_iterator<char>(outputFile));
                outputFile.close();
            } else {
                std::cerr << "Error opening file for writing\n";
                return 1;
            }
        }
    }
        {
            std::ifstream inputFile("test.txt");
            if (inputFile.is_open()) {
                std::istream_iterator<char> inputIter(inputFile);
                std::istream_iterator<char> endIter;
                std::string textFromFile(inputIter, endIter);
                std::cout << "Text read from file:\n" << textFromFile << std::endl;
                inputFile.close();
            } else {
                std::cerr << "Error opening file for reading\n";
                return 1;
            }
        }

// deque
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::deque<int> dq;

    std::copy(vec.begin(), vec.end(), std::back_inserter(dq));

    for (auto it = dq.begin(); it != dq.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
// last
    std::vector<int> array;

    std::cout << "Enter size: " << std::endl;
    std::cin >> size;
    std::cout << "Enter numbers: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        int num;
        std::cin >> num;
        array.push_back(num);
    }

    std::cout << "Inversion: ";
    for (auto it = array.rbegin(); it != array.rend(); ++it) {
        std::cout << *it << " ";
    }

    return 0;
}