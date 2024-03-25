#include "part1_2.h"



void PartOne_Two::swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void PartOne_Two::selectionSort(int array[], int size) { // Selectioon sort, a greedy algorithm-type approach to sorting.
for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {
        if (array[i] < array[min_idx])
            min_idx = i;
    }
    swap(&array[min_idx], &array[step]);
    }
}


void PartOne_Two::readData(std::string source){ // Function to read data from the csv file.
    std::ifstream api_marketData;
    api_marketData.open(source);

    Market_Data temp_data;
    std::string temp_string;

    temp_data.name = source;
    std::string line = "";      
    if (api_marketData.fail()){ //Checks if file is readable. Returns an error if not.
        system("CLS");
        std::cout << "Error with data. Please try again. Error on file: " << source << std::endl;
        system("Pause");
        return;
    }
    for (int x = 0; x < 5; x++) { //Reads .csv file and pushes a [data] struct instance to a vector.
        for (int y = 0; y < 5; y++){
            if (y == 4)
                std::getline(api_marketData, temp_string, '\n');
            else
                std::getline(api_marketData, temp_string, ',');
            temp_data.priceData[x][y] = atoi(temp_string.c_str());
        }
        line = ";";
    } 
    data.push_back(temp_data);
    /* 
    std::cout << source << std::endl;
    for (int x = 0; x < 5; x++){
        for (int y = 0; y < 5; y++){
            std::cout << temp_data.priceData[x][y] << " ";
        }
        std::cout << std::endl;
    }
    */
}



/* void PartOne_Two::dynamicPricing(int room_type, int month){     
    //Utilizes greedy algorithm to search for the best pricing available for each room type.
    //Room type [0-4] corresponds to each room category as stated in the [Market Data] struct.
    int temp_sortedPrice[5];
    for (int x = 0; x < 12; x++){
        //int temp_sortedPrice[5];
        for (auto y = 0; y < 5; y++){
            temp_sortedPrice[y] = data[month-1].priceData[y][room_type]; 
        }
        selectionSort(temp_sortedPrice, 5);
        //std::cout << months[x] << ": " << temp_sortedPrice[4] << std::endl;

    }
    std::cout<<months[month]<<": "<<temp_sortedPrice[4]<<std::endl;
}*/

int PartOne_Two::dynamicPricing(int room_type, int month){     
    //Utilizes greedy algorithm to search for the best pricing available for each room type.
    //Room type [0-4] corresponds to each room category as stated in the [Market Data] struct.
    int temp_sortedPrice[5];
    for (int x = 0; x < 12; x++){
        //int temp_sortedPrice[5];
        for (auto y = 0; y < 5; y++){
            temp_sortedPrice[y] = data[month-1].priceData[y][room_type]; 
        }
        selectionSort(temp_sortedPrice, 5);
        //std::cout << months[x] << ": " << temp_sortedPrice[4] << std::endl;

    }
    int basePrice = temp_sortedPrice[4];
    return basePrice;
}
