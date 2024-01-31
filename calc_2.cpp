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

std::vector<int> FillVector(std::vector<int> vec, int size) {
    vec.resize(size);
    for (int i = 0; i < size; i++) {
        vec[i] = rand() % size;
    }
    return vec;
}

float CalculateVectorInsert(std::vector<int> vec) {
    vec.reserve(1);

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
        mp[i] = rand() % size;
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

float CalculateListAccess(std::list<int>& lst) {
    auto start = std::chrono::high_resolution_clock::now();
    if (!lst.empty()) {
        int index = 1000;
        auto it = lst.begin();
        std::advance(it, index);
        int value = *it;  // Accessing the value
    }
    auto stop = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
}

float CalculateMapAccess(std::map<int, int>& mp) {
    auto start = std::chrono::high_resolution_clock::now();
    if (!mp.empty()) {
        int key = 1000;
        int value = mp[key];  // Accessing the value
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
    const int experimentsCount = 50000;
    std::vector<float> insertResults, testVectorResize, accessResults, eraseResults, resizeResults, findResults, sortResults;
    const int containerSize = 10000;
    std::vector<int> testVector;
    testVector.reserve(containerSize);
    for (int i = 0; i < experimentsCount; i++) {
        insertResults.push_back(CalculateVectorInsert(testVector));

        testVector = FillVector(testVector, containerSize);

        testVectorResize.push_back(CalculateVectorInsert(testVector));

        // First insertion

        // Access
        accessResults.push_back(CalculateVectorAccess(testVector));

        // Erase
        eraseResults.push_back(CalculateVectorErase(testVector));
        testVector.reserve(100001);
        // Insertion after erase
        testVectorResize.push_back(CalculateVectorInsert(testVector));

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
    std::cout << "Average Insert Time After Resize (nanoseconds): " << calculateAverage(testVectorResize) << std::endl;
    std::cout << "Average Access Time (nanoseconds): " << calculateAverage(accessResults) << std::endl;
    std::cout << "Average Erase Time (nanoseconds): " << calculateAverage(eraseResults) << std::endl;
    std::cout << "Average Resize Time (nanoseconds): " << calculateAverage(resizeResults) << std::endl;
    std::cout << "Average Find Time (nanoseconds): " << calculateAverage(findResults) << std::endl;
    std::cout << "Average Sort Time (nanoseconds): " << calculateAverage(sortResults) << std::endl;

    insertResults.clear();
    testVectorResize.clear();
    accessResults.clear();
    eraseResults.clear();
    resizeResults.clear();
    findResults.clear();
    sortResults.clear();

    // size = 2 * prevSize
    std::vector<int> testVectorSecond(2 * containerSize, 0);
    for (int i = 0; i < experimentsCount; i++) {

        insertResults.push_back(CalculateVectorInsert(testVectorSecond));

        testVectorSecond = FillVector(testVectorSecond, 2 * containerSize);

        accessResults.push_back(CalculateVectorAccess(testVectorSecond));

        eraseResults.push_back(CalculateVectorErase(testVectorSecond));

        testVectorResize.push_back(CalculateVectorInsert(testVectorSecond));

        // Resize
        resizeResults.push_back(CalculateVectorResize(testVectorSecond));

        // Find
        findResults.push_back(CalculateVectorFind(testVectorSecond));

        // Sort
        sortResults.push_back(CalculateVectorSort(testVectorSecond));

    }

    std::cout << "Average Insert Time (nanoseconds): " << calculateAverage(insertResults) << std::endl;
    std::cout << "Average Insert Time After Resize (nanoseconds): " << calculateAverage(testVectorResize) << std::endl;
    std::cout << "Average Access Time (nanoseconds): " << calculateAverage(accessResults) << std::endl;
    std::cout << "Average Erase Time (nanoseconds): " << calculateAverage(eraseResults) << std::endl;
    std::cout << "Average Resize Time (nanoseconds): " << calculateAverage(resizeResults) << std::endl;
    std::cout << "Average Find Time (nanoseconds): " << calculateAverage(findResults) << std::endl;
    std::cout << "Average Sort Time (nanoseconds): " << calculateAverage(sortResults) << std::endl;

    insertResults.clear();
    testVectorResize.clear();
    accessResults.clear();
    eraseResults.clear();
    resizeResults.clear();
    findResults.clear();
    sortResults.clear();

    // Increased size of testVector to 20000 elements
    std::vector<int> testVector3(3 * containerSize, 0);
    for (int i = 0; i < experimentsCount; i++) {
        insertResults.push_back(CalculateVectorInsert(testVector3));

        testVector3 = FillVector(testVector3, 3 * containerSize);

        // First insertion

        // Access
        accessResults.push_back(CalculateVectorAccess(testVector3));

        // Erase
        eraseResults.push_back(CalculateVectorErase(testVector3));
        // Insertion after erase
        testVectorResize.push_back(CalculateVectorInsert(testVector3));

        // Resize
        resizeResults.push_back(CalculateVectorResize(testVector3));

        // Find
        findResults.push_back(CalculateVectorFind(testVector3));

        // Sort
        sortResults.push_back(CalculateVectorSort(testVector3));

    }

    std::cout << "Average Insert Time (nano3s): " << calculateAverage(insertResults) << std::endl;
    std::cout << "Average Insert Time After Resize (nano3s): " << calculateAverage(testVectorResize) << std::endl;
    std::cout << "Average Access Time (nano3s): " << calculateAverage(accessResults) << std::endl;
    std::cout << "Average Erase Time (nano3s): " << calculateAverage(eraseResults) << std::endl;
    std::cout << "Average Resize Time (nano3s): " << calculateAverage(resizeResults) << std::endl;
    std::cout << "Average Find Time (nano3s): " << calculateAverage(findResults) << std::endl;
    std::cout << "Average Sort Time (nano3s): " << calculateAverage(sortResults) << std::endl;



    std::vector<float> listInsertResults, listEraseResults, listFindResults, listSortResults, listAccessResults;

    std::list<int> testList;
    for (int i = 0; i < experimentsCount; i++) {
        testList = FillList(testList, containerSize); // Fill list with 10000 elements

        // Insert
        listInsertResults.push_back(CalculateListInsert(testList));

        // Erase
        listEraseResults.push_back(CalculateListErase(testList));

        // Find
        int searchValue = rand() % 10000;
        listFindResults.push_back(CalculateListFind(testList, searchValue));

        listAccessResults.push_back(CalculateListAccess(testList));

        // Sort
        listSortResults.push_back(CalculateListSort(testList));

    }

    // Calculating and printing averages for list operations
    std::cout << "List Operations:" << std::endl;
    std::cout << "Average List Insert Time (nanoseconds): " << calculateAverage(listInsertResults) << std::endl;
    std::cout << "Average List Erase Time (nanoseconds): " << calculateAverage(listEraseResults) << std::endl;
    std::cout << "Average List Find Time (nanoseconds): " << calculateAverage(listFindResults) << std::endl;
    std::cout << "Average List Sort Time (nanoseconds): " << calculateAverage(listSortResults) << std::endl;
    std::cout << "Average List Access Time (nanoseconds): " << calculateAverage(listAccessResults) << std::endl;

    listInsertResults.clear();
    listEraseResults.clear();
    listFindResults.clear();
    listSortResults.clear();
    listAccessResults.clear();

    std::list<int> testListSecond;
    for (int i = 0; i < experimentsCount; i++) {
        testListSecond = FillList(testListSecond, 2 * containerSize); // Fill list with 10000 elements

        // Insert
        listInsertResults.push_back(CalculateListInsert(testListSecond));

        // Erase
        listEraseResults.push_back(CalculateListErase(testListSecond));

        // Find
        int searchValue = rand() % 10000;
        listFindResults.push_back(CalculateListFind(testListSecond, searchValue));

        // Sort
        listSortResults.push_back(CalculateListSort(testListSecond));

        listAccessResults.push_back(CalculateListAccess(testListSecond));
    }

    std::cout << "List Operations:" << std::endl;
    std::cout << "Average List Insert Time (nanoseconds): " << calculateAverage(listInsertResults) << std::endl;
    std::cout << "Average List Erase Time (nanoseconds): " << calculateAverage(listEraseResults) << std::endl;
    std::cout << "Average List Find Time (nanoseconds): " << calculateAverage(listFindResults) << std::endl;
    std::cout << "Average List Sort Time (nanoseconds): " << calculateAverage(listSortResults) << std::endl;
    std::cout << "Average List Access Time (nanoseconds): " << calculateAverage(listAccessResults) << std::endl;

    listInsertResults.clear();
    listEraseResults.clear();
    listFindResults.clear();
    listSortResults.clear();
    listAccessResults.clear();

    std::list<int> testList3;
    for (int i = 0; i < experimentsCount; i++) {
        testList3 = FillList(testList3, 3 * containerSize); // Fill list with 10000 elements

        // Insert
        listInsertResults.push_back(CalculateListInsert(testList3));

        // Erase
        listEraseResults.push_back(CalculateListErase(testList3));

        // Find
        int searchValue = rand() % 10000;
        listFindResults.push_back(CalculateListFind(testList3, searchValue));

                     // Sort
        listSortResults.push_back(CalculateListSort(testList3));

        listAccessResults.push_back(CalculateListAccess(testList3));
    }

    std::cout << "List Operations:" << std::endl;
    std::cout << "Average List Insert Time (nano3s): " << calculateAverage(listInsertResults) << std::endl;
    std::cout << "Average List Erase Time (nano3s): " << calculateAverage(listEraseResults) << std::endl;
    std::cout << "Average List Find Time (nano3s): " << calculateAverage(listFindResults) << std::endl;
    std::cout << "Average List Sort Time (nano3s): " << calculateAverage(listSortResults) << std::endl;
    std::cout << "Average List Access Time (nano3s): " << calculateAverage(listAccessResults) << std::endl;


    std::vector<float> mapInsertResults, mapEraseResults, mapFindResults, mapIterationResults, mapAccessResults = {};
        
    std::map<int, int> testMap;
    for (int i = 0; i < experimentsCount; i++) {
        testMap = FillMap(testMap, containerSize); // Filling the map with 100000 elements

        // Insert
        mapInsertResults.push_back(CalculateMapInsert(testMap));

        // Erase
        mapEraseResults.push_back(CalculateMapErase(testMap));

        // Find
        int searchValue = rand() % containerSize;
        mapFindResults.push_back(CalculateMapFind(testMap, searchValue));

        // Iteration
        mapIterationResults.push_back(CalculateMapIteration(testMap));

        mapAccessResults.push_back(CalculateMapAccess(testMap));

    }

    std::cout << "Map Operations:" << std::endl;
    std::cout << "Average Map Insert Time (nanoseconds): " << calculateAverage(mapInsertResults) << std::endl;
    std::cout << "Average Map Erase Time (nanoseconds): " << calculateAverage(mapEraseResults) << std::endl;
    std::cout << "Average Map Find Time (nanoseconds): " << calculateAverage(mapFindResults) << std::endl;
    std::cout << "Average Map Iteration Time (nanoseconds): " << calculateAverage(mapIterationResults) << std::endl;
    std::cout << "Average Map Access Time (nanoseconds): " << calculateAverage(mapAccessResults) << std::endl;

    mapInsertResults.clear();
    mapEraseResults.clear();
    mapFindResults.clear();
    mapIterationResults.clear();
    mapAccessResults.clear();

    std::map<int, int> testMapSecond;
    for (int i = 0; i < experimentsCount; i++) {
        testMapSecond = FillMap(testMapSecond, 2 * containerSize); 
        // Insert
        mapInsertResults.push_back(CalculateMapInsert(testMapSecond));

        // Erase
        mapEraseResults.push_back(CalculateMapErase(testMapSecond));

        // Find
        int searchValue = rand() % 2 * containerSize;
        mapFindResults.push_back(CalculateMapFind(testMapSecond, searchValue));

        // Iteration
        mapIterationResults.push_back(CalculateMapIteration(testMapSecond));

        mapAccessResults.push_back(CalculateMapAccess(testMapSecond));

    }

    std::cout << "Map Operations:" << std::endl;
    std::cout << "Average Map Insert Time (nanoseconds): " << calculateAverage(mapInsertResults) << std::endl;
    std::cout << "Average Map Erase Time (nanoseconds): " << calculateAverage(mapEraseResults) << std::endl;
    std::cout << "Average Map Find Time (nanoseconds): " << calculateAverage(mapFindResults) << std::endl;
    std::cout << "Average Map Iteration Time (nanoseconds): " << calculateAverage(mapIterationResults) << std::endl;
    std::cout << "Average Map Access Time (nanoseconds): " << calculateAverage(mapAccessResults) << std::endl;

    mapInsertResults.clear();
    mapEraseResults.clear();
    mapFindResults.clear();
    mapIterationResults.clear();
    mapAccessResults.clear();

    std::map<int, int> testMap3;
    for (int i = 0; i < experimentsCount; i++) {
        testMap3 = FillMap(testMap3, 3 * containerSize);
        // Insert
        mapInsertResults.push_back(CalculateMapInsert(testMap3));

        // Erase
        mapEraseResults.push_back(CalculateMapErase(testMap3));

        // Find
        int searchValue = rand() % 3 * containerSize;
        mapFindResults.push_back(CalculateMapFind(testMap3, searchValue));

        // Iteration
        mapIterationResults.push_back(CalculateMapIteration(testMap3));

        mapAccessResults.push_back(CalculateMapAccess(testMap3));

    }

    std::cout << "Map Operations:" << std::endl;
    std::cout << "Average Map Insert Time (nano3s): " << calculateAverage(mapInsertResults) << std::endl;
    std::cout << "Average Map Erase Time (nano3s): " << calculateAverage(mapEraseResults) << std::endl;
    std::cout << "Average Map Find Time (nano3s): " << calculateAverage(mapFindResults) << std::endl;
    std::cout << "Average Map Iteration Time (nano3s): " << calculateAverage(mapIterationResults) << std::endl;
    std::cout << "Average Map Access Time (nano3s): " << calculateAverage(mapAccessResults) << std::endl;

    return 0;
}
