#include <iostream>
#include <fstream>
#include <string>

const int wall = 0;
const int start = 1;
const int end = 2;
const int road = 3;

void save(int tab[])
{
	std::ofstream myfile;
	myfile.open("test.txt");
	

	for(int i=0;i<484;i++)
	myfile << tab[i]<<std::endl;
	myfile.close();
}

void load(int tab[])
{
    std::ifstream myfile;
    myfile.open("test.txt");
    std::string line;
    int number = 0;
    int i = 0;
    while (myfile >> number)
    {
        tab[i] = number;
        i++;
    }
    
    myfile.close();
}

int check(int tab[]) 
{
    bool exit_exist = false;
    int one_start = 0;
    int start = -5;
    for (int i = 22; i < 461; i++)
    {
        if (tab[i] == 2) { exit_exist = true;}
        if (tab[i] == 1) {one_start++; start = i;}           
    }

    if ((exit_exist == true) && (one_start == 1))
    {
        return start;
    }
    else { return -4; }
        
}