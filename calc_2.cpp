#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <list>
#include <map>

std::list<int> FillList(std::list<int>& lst, int size) {
    lst.clear();
    for (int i = 0; i < size; i++) {
        lst.push_back(rand() % size);
    }
    return lst;
}

float CalculateListInsert(std::list<int>& lst) {
    auto start = std::chrono::high_resolution_clock::now();

    lst.push_back(31);

    auto stop = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
}

float CalculateListErase(std::list<int>& lst) {
    auto start = std::chrono::high_resolution_clock::now();

    if (!lst.empty()) {
        auto it = lst.begin();
        std::advance(it, lst.size() / 2);
        lst.erase(it);
    }

    auto stop = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
}

float CalculateListFind(std::list<int>& lst, int searchValue) {
    auto start = std::chrono::high_resolution_clock::now();

    auto it = std::find(lst.begin(), lst.end(), searchValue);

    auto stop = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
}

float CalculateListSort(std::list<int>& lst) {
    auto start = std::chrono::high_resolution_clock::now();

    lst.sort();

    auto stop = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
}

std::vector<int> FillVector(std::vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        vec[i] = rand() % vec.size();
    }
    return vec;
}

float CalculateVectorInsert(std::vector<int> vec) {
    auto start = std::chrono::high_resolution_clock::now();

    vec.push_back(31);

    auto stop = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
}

float CalculateVectorAccess(std::vector<int> vec) {
    auto start = std::chrono::high_resolution_clock::now();

    int randomIndex = rand() % vec.size();
    int value = vec[randomIndex];

    auto stop = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
}

float CalculateVectorErase(std::vector<int> vec) {
    auto start = std::chrono::high_resolution_clock::now();

    if (!vec.empty()) {
        vec.erase(vec.begin() + vec.size() / 2);
    }

    auto stop = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
}

float CalculateVectorResize(std::vector<int> vec) {
    auto start = std::chrono::high_resolution_clock::now();

    vec.resize(vec.size() + 1);

    auto stop = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
}

float CalculateVectorFind(std::vector<int> vec) {
    auto start = std::chrono::high_resolution_clock::now();

    int searchValue = rand() % vec.size();
    auto it = std::find(vec.begin(), vec.end(), searchValue);

    auto stop = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
}

float CalculateVectorSort(std::vector<int> vec) {
    auto start = std::chrono::high_resolution_clock::now();

    std::sort(vec.begin(), vec.end());

    auto stop = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
}

std::map<int, int> FillMap(std::map<int, int>& mp, int size) {
    mp.clear();
    for (int i = 0; i < size; ++i) {
        mp[rand() % size] = rand() % size;
    }
    return mp;
}

// Function to calculate the time taken to insert an element into the map
float CalculateMapInsert(std::map<int, int>& mp) {
    auto start = std::chrono::high_resolution_clock::now();

    mp[rand() % mp.size()] = 31;

    auto stop = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
}

// Function to calculate the time taken to erase an element from the map
float CalculateMapErase(std::map<int, int>& mp) {
    auto start = std::chrono::high_resolution_clock::now();

    if (!mp.empty()) {
        mp.erase(mp.begin());
    }

    auto stop = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
}

// Function to calculate the time taken to find an element in the map
float CalculateMapFind(std::map<int, int>& mp, int searchValue) {
    auto start = std::chrono::high_resolution_clock::now();

    auto it = mp.find(searchValue);

    auto stop = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
}

// Function to calculate the time taken to iterate through the map
float CalculateMapIteration(std::map<int, int>& mp) {
    auto start = std::chrono::high_resolution_clock::now();

    for (const auto& pair : mp) {
        // Just accessing the key and value
        int key = pair.first;
        int value = pair.second;
    }

    auto stop = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
}

int main() {
    const int experimentsCount = 200000;
    std::vector<float> insertResults, postEraseInsertResults, accessResults, eraseResults, resizeResults, findResults, sortResults;

    std::vector<int> testVector(100000, 0);
    for (int i = 0; i < experimentsCount; i++) {
        testVector = FillVector(testVector);

        // First insertion
        insertResults.push_back(CalculateVectorInsert(testVector));

        // Access
        accessResults.push_back(CalculateVectorAccess(testVector));

        // Erase
        eraseResults.push_back(CalculateVectorErase(testVector));
        testVector.reserve(100001);
        // Insertion after erase
        postEraseInsertResults.push_back(CalculateVectorInsert(testVector));

        // Resize
        resizeResults.push_back(CalculateVectorResize(testVector));

        // Find
        findResults.push_back(CalculateVectorFind(testVector));

        sortResults.push_back(CalculateVectorSort(testVector));

    }

    auto calculateAverage = [](const std::vector<float>& results) {
        long double avg = 0;
        for (auto time : results) {
            avg += time;
        }
        return avg / results.size();
        };

    std::cout << "Average Insert Time (nanoseconds): " << calculateAverage(insertResults) << std::endl;
    std::cout << "Average Insert Time After Erase (nanoseconds): " << calculateAverage(postEraseInsertResults) << std::endl;
    std::cout << "Average Access Time (nanoseconds): " << calculateAverage(accessResults) << std::endl;
    std::cout << "Average Erase Time (nanoseconds): " << calculateAverage(eraseResults) << std::endl;
    std::cout << "Average Resize Time (nanoseconds): " << calculateAverage(resizeResults) << std::endl;
    std::cout << "Average Find Time (nanoseconds): " << calculateAverage(findResults) << std::endl;
    std::cout << "Average Sort Time (nanoseconds): " << calculateAverage(sortResults) << std::endl;

    std::vector<float> insertResultsSecond, postEraseInsertResultsSecond, accessResultsSecond, eraseResultsSecond, resizeResultsSecond, findResultsSecond, sortResultsSecond;

    // Increased size of testVector to 20000 elements
    std::vector<int> testVectorSecond(200000, 0);
    for (int i = 0; i < experimentsCount; i++) {
        testVectorSecond = FillVector(testVectorSecond);

        // First insertion
        insertResultsSecond.push_back(CalculateVectorInsert(testVectorSecond));

        // Access
        accessResultsSecond.push_back(CalculateVectorAccess(testVectorSecond));

        // Erase
        eraseResultsSecond.push_back(CalculateVectorErase(testVectorSecond));
        testVectorSecond.reserve(200001); // Adjusted to the new size of the vector
        // Insertion after erase
        postEraseInsertResultsSecond.push_back(CalculateVectorInsert(testVectorSecond));

        // Resize
        resizeResultsSecond.push_back(CalculateVectorResize(testVectorSecond));

        // Find
        findResultsSecond.push_back(CalculateVectorFind(testVectorSecond));

        // Sort
        sortResultsSecond.push_back(CalculateVectorSort(testVectorSecond));
    }

    std::cout << "Average Insert Time (nanoseconds): " << calculateAverage(insertResultsSecond) << std::endl;
    std::cout << "Average Insert Time After Erase (nanoseconds): " << calculateAverage(postEraseInsertResultsSecond) << std::endl;
    std::cout << "Average Access Time (nanoseconds): " << calculateAverage(accessResultsSecond) << std::endl;
    std::cout << "Average Erase Time (nanoseconds): " << calculateAverage(eraseResultsSecond) << std::endl;
    std::cout << "Average Resize Time (nanoseconds): " << calculateAverage(resizeResultsSecond) << std::endl;
    std::cout << "Average Find Time (nanoseconds): " << calculateAverage(findResultsSecond) << std::endl;
    std::cout << "Average Sort Time (nanoseconds): " << calculateAverage(sortResultsSecond) << std::endl;

    std::vector<float> listInsertResults, listEraseResults, listFindResults, listSortResults;

    std::list<int> testList;
    for (int i = 0; i < experimentsCount; i++) {
        testList = FillList(testList, 100000); // Fill list with 10000 elements

        // Insert
        listInsertResults.push_back(CalculateListInsert(testList));

        // Erase
        listEraseResults.push_back(CalculateListErase(testList));

        // Find
        int searchValue = rand() % 10000;
        listFindResults.push_back(CalculateListFind(testList, searchValue));

        // Sort
        listSortResults.push_back(CalculateListSort(testList));
    }

    // Calculating and printing averages for list operations
    std::cout << "List Operations:" << std::endl;
    std::cout << "Average List Insert Time (nanoseconds): " << calculateAverage(listInsertResults) << std::endl;
    std::cout << "Average List Erase Time (nanoseconds): " << calculateAverage(listEraseResults) << std::endl;
    std::cout << "Average List Find Time (nanoseconds): " << calculateAverage(listFindResults) << std::endl;
    std::cout << "Average List Sort Time (nanoseconds): " << calculateAverage(listSortResults) << std::endl;

    std::vector<float> listInsertResultsSecond, listEraseResultsSecond, listFindResultsSecond, listSortResultsSecond;

    std::list<int> testListSecond;
    for (int i = 0; i < experimentsCount; i++) {
        testListSecond = FillList(testListSecond, 200000); // Fill list with 10000 elements

        // Insert
        listInsertResultsSecond.push_back(CalculateListInsert(testListSecond));

        // Erase
        listEraseResultsSecond.push_back(CalculateListErase(testListSecond));

        // Find
        int searchValue = rand() % 10000;
        listFindResultsSecond.push_back(CalculateListFind(testListSecond, searchValue));

        // Sort
        listSortResultsSecond.push_back(CalculateListSort(testListSecond));
    }

    // Calculating and printing averages for list operations
    std::cout << "List Operations:" << std::endl;
    std::cout << "Average List Insert Time (nanoseconds): " << calculateAverage(listInsertResultsSecond) << std::endl;
    std::cout << "Average List Erase Time (nanoseconds): " << calculateAverage(listEraseResultsSecond) << std::endl;
    std::cout << "Average List Find Time (nanoseconds): " << calculateAverage(listFindResultsSecond) << std::endl;
    std::cout << "Average List Sort Time (nanoseconds): " << calculateAverage(listSortResultsSecond) << std::endl;

    std::vector<float> mapInsertResults, mapEraseResults, mapFindResults, mapIterationResults;

    std::map<int, int> testMap;
    for (int i = 0; i < experimentsCount; i++) {
        testMap = FillMap(testMap, 100000); // Filling the map with 100000 elements

        // Insert
        mapInsertResults.push_back(CalculateMapInsert(testMap));

        // Erase
        mapEraseResults.push_back(CalculateMapErase(testMap));

        // Find
        int searchValue = rand() % 100000;
        mapFindResults.push_back(CalculateMapFind(testMap, searchValue));

        // Iteration
        mapIterationResults.push_back(CalculateMapIteration(testMap));
    }

    // Calculating and printing averages for map operations
    std::cout << "Map Operations:" << std::endl;
    std::cout << "Average Map Insert Time (nanoseconds): " << calculateAverage(mapInsertResults) << std::endl;
    std::cout << "Average Map Erase Time (nanoseconds): " << calculateAverage(mapEraseResults) << std::endl;
    std::cout << "Average Map Find Time (nanoseconds): " << calculateAverage(mapFindResults) << std::endl;
    std::cout << "Average Map Iteration Time (nanoseconds): " << calculateAverage(mapIterationResults) << std::endl;

    return 0;
}
