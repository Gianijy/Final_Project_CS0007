#pragma once
#ifndef PART1_2_H
#define PART1_2_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

class PartOne_Two{
    private:
        const std::string months[12] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"}; 
        const std::string room_categ[5] = {"Standard Queen", "Standard King", "Standard King - Connecting", "Deluxe", "Suites"};
        struct Market_Data{ //Structure to hold the data on each month.
            std::string name;
            int priceData[5][5]; //Uses [Source][Room type] notation. Utilizes divide-and-conquer approach by creating a matrix for different room types.
        };        
        std::vector<Market_Data> data;
        int priceData[5][5];

    public:
    int summarizedPrice_monthly[12]; // Contains the highest price of each rooom type for every month.
    void swap(int *a, int *b);
    void selectionSort(int array[], int size);
    void readData(std::string source); // Function to read data from the csv file.
    int dynamicPricing(int room_type, int month); //Utilizes greedy algorithm to search for the best pricing available for each room type.
};

#endif