//
// Created by joseph on 21/09/2024.
//

#include "iostream"


float findMedian(int agentData[12]) {

    return (agentData[5] + agentData[6]) /2;
}

//3.9

float findAverage(int agentData[12]) {
    float sum = 0;
    int months = 0;

    for (int i = 0; i < 12; i++) {
        if (agentData[i] == -1)
            continue;
        sum+= agentData[i];
        months++;
    }

    return {sum / months};


}


int compareFuncSales(const void* voidA, const void* voidB) {

    int* intA = (int*) (voidA);
    int* intB = (int*) (voidB);

    return *intA - *intB;
}



int main()
{
    const int NUM_AGENTS = 3;
    const int NUM_MONTHS = 12;


    int sales[NUM_AGENTS][NUM_MONTHS] = {
            {-1,-1,-1,-1, 387, 3754, 387587, 2873, 276, 32, -1, -1},
            {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534},
            {23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}
    };

    //sort all arrays first;
    for (int i = 0; i < NUM_AGENTS; i++) {
        qsort(sales[i], NUM_MONTHS, sizeof(int), compareFuncSales);
        for (int j = 0; j< 12; j++) {
            //std::cout << sales[i][j] << ", ";
        }
        std::cout << "\n";
    }


    auto highestMedian = findMedian(sales[0]);

    for (int agent = 1; agent < NUM_AGENTS; agent++) {
        if(findMedian(sales[agent]) > highestMedian) {
            highestMedian = findMedian(sales[agent]);
        }
    }

    //std::cout << highestMedian << std::endl;


    std::cout << findAverage(sales[0]);

    return 1;
    //find median of each agent's sales




}


