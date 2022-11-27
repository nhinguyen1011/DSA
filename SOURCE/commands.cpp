#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include "DataGenerator.h"
#include "algorithms.h"

using namespace std;
using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;

int *readDataFromFile(string input_file, int &size)
{
    ifstream fi(input_file);
    if (!fi.is_open())
    {
        cerr << "Can't open file" << endl;
    }

    string s, num;
    getline(fi, s);
    size = stoi(s);
    int *array = new int[size];

    getline(fi, s);
    stringstream ss(s);
    for (int i = 0; i < size; i++)
    {
        getline(ss, num, ' ');
        array[i] = stoi(num);
    }

    fi.close();

    return array;
}

void writeToOutputFile(string output_file, int *array, int size)
{
    ofstream fo(output_file);
    for (int i = 0; i < size; i++)
    {
        fo << array[i] << " ";
    }
    fo.close();
}

void writeToInputFile(string input_file, int array[], int size)
{
    ofstream fo(input_file);
    fo << size << endl;
    for (int i = 0; i < size; i++)
    {
        fo << array[i] << " ";
    }
    fo.close();
}

void selectAlgorithmWithTime(string algorithm_name, int *array, int size, double &time)
{
    duration<double, milli> exec_time;
    high_resolution_clock::time_point start_time;
    high_resolution_clock::time_point end_time;

    if (algorithm_name == "selection-sort")
    {
        start_time = high_resolution_clock::now();
        selectionSortWithTime(array, size);
        end_time = high_resolution_clock::now();
        exec_time = end_time - start_time;
    }
    else if (algorithm_name == "insertion-sort")
    {
        start_time = high_resolution_clock::now();
        insertionSortWithTime(array, size);
        end_time = high_resolution_clock::now();
        exec_time = end_time - start_time;
    }
    else if (algorithm_name == "bubble-sort")
    {
        start_time = high_resolution_clock::now();
        bubbleSortWithTime(array, size);
        end_time = high_resolution_clock::now();
        exec_time = end_time - start_time;
    }
    else if (algorithm_name == "heap-sort")
    {
        start_time = high_resolution_clock::now();
        heapSortWithTime(array, size);
        end_time = high_resolution_clock::now();
        exec_time = end_time - start_time;
    }
    else if (algorithm_name == "merge-sort")
    {
        start_time = high_resolution_clock::now();
        mergeSortWithTime(array, 0, size - 1);
        end_time = high_resolution_clock::now();
        exec_time = end_time - start_time;
    }
    else if (algorithm_name == "quick-sort")
    {
        start_time = high_resolution_clock::now();
        quickSortWithTime(array, 0, size - 1);
        end_time = high_resolution_clock::now();
        exec_time = end_time - start_time;
    }
    else
    {
        start_time = high_resolution_clock::now();
        radixSortWithTime(array, size);
        end_time = high_resolution_clock::now();
        exec_time = end_time - start_time;
    }

    time = exec_time.count();
}

void selectAlgorithmWithComparison(string algorithm_name, int *array, int size, unsigned long long &count_compare)
{
    if (algorithm_name == "selection-sort")
    {
        selectionSortWithComparison(array, size, count_compare);
    }
    else if (algorithm_name == "insertion-sort")
    {
        insertionSortWithComparison(array, size, count_compare);
    }
    else if (algorithm_name == "bubble-sort")
    {
        bubbleSortWithComparison(array, size, count_compare);
    }
    else if (algorithm_name == "heap-sort")
    {
        heapSortWithComparison(array, size, count_compare);
    }
    else if (algorithm_name == "merge-sort")
    {
        mergeSortWithComparison(array, 0, size - 1, count_compare);
    }
    else if (algorithm_name == "quick-sort")
    {
        quickSortWithComparison(array, 0, size - 1, count_compare);
    }
    else
    {
        radixSortWithComparison(array, size, count_compare);
    }
}

void checkInputOrder(string input_order, int &flag_order, string &order_display)
{
    if (input_order == "-rand")
    {
        flag_order = 0;
        order_display = "Randomized";
    }
    else if (input_order == "-sorted")
    {
        flag_order = 1;
        order_display = "Sorted";
    }
    else if (input_order == "-rev")
    {
        flag_order = 2;
        order_display = "Reverse";
    }
    else
    {
        flag_order = 3;
        order_display = "Nearly sorted";
    }
}

// Command 1 ------------------------------------------------------------------------
void runCommand1(string algorithm_name, string input_file, string output_param)
{
    unsigned long long count_compare = 0;
    double time = 0;
    int size = 0;
    int *array = readDataFromFile(input_file, size);

    // Nhập tên file và kích cỡ
    cout << "Input file: " << input_file << endl;
    cout << "Input size: " << size << endl;
    cout << "------------------------" << endl;

    // Chọn các yêu cầu là thời gian hoặc so sánh
    if (output_param == "-time")
    {
        selectAlgorithmWithTime(algorithm_name, array, size, time);

        cout << "Running time: " << time << " (ms)" << endl;
    }
    else if (output_param == "-comp")
    {
        selectAlgorithmWithComparison(algorithm_name, array, size, count_compare);
        cout << "Comparisons: " << count_compare << endl;
    }
    else
    {
        // Khởi tạo mảng phụ từ mảng chính để đếm tg và số lượng phép so sánh
        int *second_array = new int[size];
        for (int i = 0; i < size; i++)
        {
            second_array[i] = array[i];
        }

        // Thời gian và phép so sánh
        selectAlgorithmWithTime(algorithm_name, array, size, time);
        selectAlgorithmWithComparison(algorithm_name, second_array, size, count_compare);

        cout << "Running time: " << time << " (ms)" << endl;
        cout << "Comparisons: " << count_compare << endl;

        // xoá mảng phụ
        delete[] second_array;
    }

    // Ghi mảng đã sắp xếp
    writeToOutputFile("output.txt", array, size);

    delete[] array;
}

// Command 2 ----------------------------------------------------------------------------------------
void runCommand2(string algorithm_name, int size, string input_order, string output_param)
{
    double time = 0;
    unsigned long long count_compare = 0;
    int *array = new int[size];
    int flag_order = 0;
    string order_display;

    // kiểm tra input đầu vào 
    checkInputOrder(input_order, flag_order, order_display);

    // Nhập số lượng
    cout << "Input size: " << size << endl;
    cout << "Input order " << order_display << endl;
    cout << "------------------------" << endl;

    // Khởi tạo dữ liệu 
    GenerateData(array, size, flag_order);
    writeToInputFile("input.txt", array, size);

    // Chọn các yêu cầu là thời gian hoặc so sánh
    if (output_param == "-time")
    {
        selectAlgorithmWithTime(algorithm_name, array, size, time);
        cout << "Running time: " << time << " (ms)" << endl;
    }
    else if (output_param == "-comp")
    {
        selectAlgorithmWithComparison(algorithm_name, array, size, count_compare);
        cout << "Comparisons: " << count_compare << endl;
    }
    else
    {
        // Khởi tạo mảng phụ từ mảng chính để đếm tg và số lượng phép so sánh
        int *second_array = new int[size];
        for (int i = 0; i < size; i++)
        {
            second_array[i] = array[i];
        }

        selectAlgorithmWithTime(algorithm_name, array, size, time);
        selectAlgorithmWithComparison(algorithm_name, second_array, size, count_compare);

        cout << "Running time: " << time << " (ms)" << endl;
        cout << "Comparisons: " << count_compare << endl;

        // xoá mảng phụ
        delete[] second_array;
    }

    // Ghi mảng đã sắp xếp vào file
    writeToOutputFile("output.txt", array, size);

    delete[] array;
}

// Command 3 ----------------------------------------------------------------------------------------
void runCommand3(string algorithm_name, int size, string output_param)
{
    double time = 0;
    unsigned long long count_compare = 0;
    int *array = new int[size];

    // Khởi tạo mảng cho phép lựa chọn, và các file
    string order_display[4] = {"Randomized", "Sorted", "Reversed", "Nearly Sorted"};
    string input_file[4] = {"input1.txt", "input2.txt", "input3.txt", "input4.txt"};

    
    cout << "Input size: " << size << endl;
    cout << endl;

    //  Các yêu cầu chọn lựa
    for (int i = 0; i < 4; i++)
    {
        GenerateData(array, size, i);
        writeToInputFile(input_file[i], array, size);

        cout << "Input order: " << order_display[i] << endl;
        cout << "------------------------" << endl;

        if (output_param == "-time")
        {
            selectAlgorithmWithTime(algorithm_name, array, size, time);
            cout << "Running time: " << time << " (ms)" << endl;
        }
        else if (output_param == "-comp")
        {
            selectAlgorithmWithComparison(algorithm_name, array, size, count_compare);
            cout << "Comparisons: " << count_compare << endl;
        }
        else
        {
            // Khởi tạo mảng phụ từ mảng chính để đếm tg và số lượng phép so sánh
            int *second_array = new int[size];
            for (int j = 0; j < size; j++)
            {
                second_array[j] = array[j];
            }

            selectAlgorithmWithTime(algorithm_name, array, size, time);
            selectAlgorithmWithComparison(algorithm_name, second_array, size, count_compare);

            cout << "Running time: " << time << " (ms)" << endl;
            cout << "Comparisons: " << count_compare << endl;

            // Xoá mảng phụ
            delete[] second_array;
        }

        cout << endl;
    }

    
    delete[] array;
}

// Command 4 ----------------------------------------------------------------------------------------
void runCommand4(string algorithm_name, string algorithm_name1, string input_file)
{
    unsigned long long count_compare = 0, count_compare1 = 0;
    double time = 0, time1 = 0;
    int size = 0;
    int *array1 = readDataFromFile("input.txt", size);
    int *array2 = readDataFromFile("input.txt", size);
    int *array3 = readDataFromFile("input.txt", size);
    int *array4 = readDataFromFile("input.txt", size);

    // Nhập các thông tin
    cout << "Input file: " << input_file << endl;
    cout << "Input size: " << size << endl;
    cout << "------------------------" << endl;

    // Đếm thời gian và các phép so sánh
    selectAlgorithmWithTime(algorithm_name, array1, size, time);
    selectAlgorithmWithTime(algorithm_name1, array2, size, time1);
    selectAlgorithmWithComparison(algorithm_name, array3, size, count_compare);
    selectAlgorithmWithComparison(algorithm_name1, array4, size, count_compare1);

    cout << "Running time: " << time << "(ms) | " << time1 << "(ms)" << endl;
    cout << "Comparisons: " << count_compare << " | " << count_compare1 << endl;

    delete[] array1, array2, array3, array4;
}

// Command 5 ------------------------------------------------------------------------
void runCommand5(string algorithm_name1, string algorithm_name2, int size, string input_order)
{
    unsigned long long count_compare1 = 0, count_compare2 = 0;
    double time1 = 0, time2 = 0;
    int *array1 = new int[size];
    int *array2 = new int[size];
    int *array3 = new int[size];
    int *array4 = new int[size];
    int flag_order = 0;
    string order_display;

    // kiểm tra input đầu vào
    checkInputOrder(input_order, flag_order, order_display);

    // Khởi tạo dữ liệu
    GenerateData(array1, size, flag_order);
    // Copy data từ mảng chính
    for (int i = 0; i < size; i++)
    {
        array2[i] = array1[i];
        array3[i] = array1[i];
        array4[i] = array1[i];
    }

    // Ghi ra file
    writeToInputFile("input.txt", array1, size);

    // Nhập các thông tin
    cout << "Input size: " << size << endl;
    cout << "Input order: " << order_display << endl;
    cout << "------------------------" << endl;

    // Đếm thời gian và các phép so sánh
    selectAlgorithmWithTime(algorithm_name1, array1, size, time1);
    selectAlgorithmWithTime(algorithm_name2, array2, size, time2);
    selectAlgorithmWithComparison(algorithm_name1, array3, size, count_compare1);
    selectAlgorithmWithComparison(algorithm_name2, array4, size, count_compare2);
    cout << "Running time: " << time1 << " (ms) | " << time2 << " (ms)" << endl;
    cout << "Comparisons: " << count_compare1 << " | " << count_compare2 << endl;

    delete[] array1, array2, array3, array4;
}
