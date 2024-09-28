//
// Created by josep on 27/09/2024.
//

//Creating linkedList of agent sales

#include "string"
#include "iostream"

using namespace std;

typedef struct salesCollection {
    int value;
    salesCollection * next;
} salesCollection;


typedef struct agentNode {
    string name;
    salesCollection* agentSales;
} agentNode;

void viewRecord(agentNode agent) { //View record of specific agent
    salesCollection* s = agent.agentSales;
    while(true){
        cout << s->value << ", ";
        if(s->next == nullptr)
            break;
        s = s->next;

    }
}




int main() {

    salesCollection *s1 = new salesCollection;
    salesCollection *s2 = new salesCollection;
    salesCollection *s3 = new salesCollection;

    s1->value = 300;
    s2->value = 1000;
    s3->value = 3000;


    salesCollection * a1Sales = new salesCollection;

    a1Sales = s1;
    s1->next = s2;
    s2->next = s3;
    s3->next = nullptr;

    s1 = s2 = nullptr;

    agentNode a1 = {"Joseph", a1Sales};


    viewRecord(a1);


}


int appendRecord(agentNode agent, int salesFigure); //Append months of sales to agent Collection



void calculateAverage(salesCollection s);

