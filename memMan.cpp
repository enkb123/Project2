/*
Eshen Brinkert
May 6, 2022
This program simulates the operating system loading processes onto processors based on their memory capacity and the method
in which the processes are to be loaded.
All simulations were run with a seed value of 13

*/

#include <iostream>
#include <random>
#include <ctime>
#include <ratio>
#include <chrono>
#include <map>
#include <queue>

using namespace std;


class Process{ //Process object
public:
    int cycles; //cycles of the process
    int memory; //memory requirements of the process
    int serviceTime; //cycles of the process, but stored to access if cycles change
    int ID; //creates ID for process
    int processor;
    int *loc;//keeps track of location that malloc has allocated to
    bool done;
};

class Processor{ //memory with 10000
public:
    map<int,int> proMap; //map that stores holes in processor
    int proArr[10000]; // array of 10000 for processor

};

class Processor2{// memory of 5000
public:
    map<int,int> proMap; //map that stores holes in processor
    int proArr[5000]; // array of 5000 for processor
};

class Processor3{//memory of 1000
public:
    map<int,int> proMap; //map that stores holes in processor
    int proArr[1000]; // array of 1000 for processor
};


int getSeed(){ //asks the user for a seed value and returns it
    int mySeed;
    cout<<"What value would you like your seed to be?"<<endl;
    cin>>mySeed;
    return mySeed;
}

Process* createPros(int seedVal){ //creates 50 processes with random memory and service times based on criteria. takes in user seed.
    static Process pro[50]; //this has to be static or nothing works I don't know why
    srand(seedVal);//seeds the random generators with user seed
    default_random_engine generator(seedVal);
    normal_distribution<double> distribution(200,75); //distributes mem with mean of 200 and sd of 75
    int memLeft = 9950; //the amount of memory available for the processes after each gets onekb
    int avgM; //stores average mem requirements
    int avgST; //stores average service time
    for(int i = 0; i<50; i++){
        Process myPro;
        int number = distribution(generator); //distributes memory in KB
        if(i == 49){
          number = memLeft;
        }else if(memLeft > number){
            memLeft -= number;
        }else{
            number = memLeft;
            memLeft = 0;
        }
        number += 1; //ensures every process has at least one kb
        int serviceT = rand()% 2000 + 200;
        myPro.memory = number;
        myPro.cycles = serviceT;
        myPro.serviceTime = serviceT;
        avgST += myPro.serviceTime;
        avgM += myPro.memory;
        myPro.ID = i;
        myPro.done = false;
        pro[i] = myPro;
        //cout<<myPro.memory<<endl;
    }
    //cout<<"Avg Mem "<<avgM/50<<endl;
    //cout<<"Avg ST" <<avgST/50<<endl;
    return pro;//returns pointer to array of processes
}

void useOS(Process* pro){//memory allocation is handled by the os in this scenario
    using namespace std::chrono;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    int cycles = 0;
    for(int i = 0; i<80; i++){
        cycles += 100;
        double byteVal = pro[i].memory * 1000; //calculates number of bytes process needs
        byteVal = byteVal/4;
        pro[i].loc = (int*)malloc(sizeof(int)*byteVal);
        for(int j = i; j>=0; j--){
            pro[j].cycles-=100;
            if(pro[j].cycles<=0 && !pro[j].done && pro[j].memory != 0){
                free(pro[j].loc);
                pro[j].loc = NULL;
                pro[j].done = true;
                cout<<"ID: "<<pro[j].ID<<endl;
                cout<<"Memory: "<<pro[j].memory<<endl;
                cout<<"Service Time: " <<pro[j].serviceTime<<endl;
            }
        }
    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
    std::cout << "It took " << time_span.count() << " seconds.";

}


Processor my_alloc(Process pro, Processor myProcessor){ //allocates memory by first fit
    auto iter = myProcessor.proMap.begin();
    while(iter ->second < pro.memory){//iterates through the processor map to find hole
        ++iter;
    }
    for(int i = iter->first; i<iter->first + pro.memory; i++){//sets all slots needed in the hole to the process id
        myProcessor.proArr[i] = pro.ID;
    }
    int one = iter->first;
    myProcessor.proMap.erase(one);//erases the hole
    int two = iter->second;
    myProcessor.proMap.insert({one + pro.memory + 1, two - pro.memory});//marks where the process ends
    return myProcessor;
}

Processor2 my_alloc(Process pro, Processor2 myProcessor){ //allocates memory by first fit for processors 2
    auto iter = myProcessor.proMap.begin();
    while(iter ->second < pro.memory){//iterates through the processor map to find hole
        ++iter;
    }
    for(int i = iter->first; i<iter->first + pro.memory; i++){//sets all slots needed in the hole to the process id
        myProcessor.proArr[i] = pro.ID;
    }
    int one = iter->first;
    myProcessor.proMap.erase(one);//erases the hole
    int two = iter->second;
    myProcessor.proMap.insert({one + pro.memory + 1, two - pro.memory});//marks where the process ends
    return myProcessor;
}

Processor3 my_alloc(Process pro, Processor3 myProcessor){ //allocates memory by first fit

    auto iter = myProcessor.proMap.begin();
    while(iter ->second < pro.memory){//iterates through the processor map to find hole
        ++iter;
    }
    for(int i = iter->first; i<iter->first + pro.memory; i++){//sets all slots needed in the hole to the process id
        myProcessor.proArr[i] = pro.ID;
    }
    int one = iter->first;
    myProcessor.proMap.erase(one);//erases the hole
    int two = iter->second;
    myProcessor.proMap.insert({one + pro.memory + 1, two - pro.memory});//marks where the process ends
    return myProcessor;
}

Processor my_allocW(Process pro, Processor myProcessor){ //allocates memory by worst fit
    auto iter = myProcessor.proMap.begin();
    int worstHole = 0;
    int worstHole2nd = 0;
    while(iter != myProcessor.proMap.end()){//iterates through the processor map to find hole
        if(iter->second > worstHole){
            worstHole = iter->first;
            worstHole2nd = iter ->second;
        }
        ++iter;
    }
    for(int i = worstHole; i<worstHole + pro.memory; i++){//sets all slots needed in the hole to the process id
        myProcessor.proArr[i] = pro.ID;
    }
    int one = worstHole;
    myProcessor.proMap.erase(one);//erases the hole
    int two = worstHole2nd;
    myProcessor.proMap.insert({one + pro.memory + 1, two - pro.memory});//marks where the process ends
    return myProcessor;
}

Processor2 my_allocW(Process pro, Processor2 myProcessor){ //allocates memory by worst fit
    auto iter = myProcessor.proMap.begin();
    int worstHole = 0;
    int worstHole2nd = 0;
    while(iter != myProcessor.proMap.end()){//iterates through the processor map to find hole
        if(iter->second > worstHole){
            worstHole = iter->first;
            worstHole2nd = iter ->second;
        }
        ++iter;
    }
    for(int i = worstHole; i<worstHole + pro.memory; i++){//sets all slots needed in the hole to the process id
        myProcessor.proArr[i] = pro.ID;
    }
    int one = worstHole;
    myProcessor.proMap.erase(one);//erases the hole
    int two = worstHole2nd;
    myProcessor.proMap.insert({one + pro.memory + 1, two - pro.memory});//marks where the process ends
    return myProcessor;
}

Processor3 my_allocW(Process pro, Processor3 myProcessor){ //allocates memory by worst fit
    auto iter = myProcessor.proMap.begin();
    int worstHole = 0;
    int worstHole2nd = 0;
    while(iter != myProcessor.proMap.end()){//iterates through the processor map to find hole
        if(iter->second > worstHole){
            worstHole = iter->first;
            worstHole2nd = iter ->second;
        }
        ++iter;
    }
    for(int i = worstHole; i<worstHole + pro.memory; i++){//sets all slots needed in the hole to the process id
        myProcessor.proArr[i] = pro.ID;
    }
    int one = worstHole;
    myProcessor.proMap.erase(one);//erases the hole
    int two = worstHole2nd;
    myProcessor.proMap.insert({one + pro.memory + 1, two - pro.memory});//marks where the process ends
    return myProcessor;
}

Processor my_free(Process pro, Processor myProcessor){//removes finished processes from processor
    int i = 0;
    while(myProcessor.proArr[i] != pro.ID){//finds process on processor
        i++;
    }
    int j = i;
    int k = 1;
    myProcessor.proMap.insert({i, k});
    while(myProcessor.proArr[j] == pro.ID){//erases process from processor and places hole in map
        myProcessor.proArr[j] = 0;
        myProcessor.proMap.erase(i);
        myProcessor.proMap.insert({i, k});
        k++;
        j++;
    }
    cout<<"ID: "<<pro.ID<<endl;
    cout<<"Memory: "<<pro.memory<<endl;
    cout<<"Service Time: " <<pro.serviceTime<<endl;
    cout<<"Starting at: "<<i<< endl;
    return myProcessor;
}

Processor2 my_free(Process pro, Processor2 myProcessor){//removes finished processes from processor
    int i = 0;
    while(myProcessor.proArr[i] != pro.ID){//finds process on processor
        i++;
    }
    int j = i;
    int k = 1;
    myProcessor.proMap.insert({i, k});
    while(myProcessor.proArr[j] == pro.ID){//erases process from processor and places hole in map
        myProcessor.proArr[j] = 0;
        myProcessor.proMap.erase(i);
        myProcessor.proMap.insert({i, k});
        k++;
        j++;
    }
    cout<<"ID: "<<pro.ID<<endl;
    cout<<"Memory: "<<pro.memory<<endl;
    cout<<"Service Time: " <<pro.serviceTime<<endl;
    cout<<"Starting at: "<<i<< endl;
    return myProcessor;
}

Processor3 my_free(Process pro, Processor3 myProcessor){//removes finished processes from processor
    int i = 0;
    while(myProcessor.proArr[i] != pro.ID){//finds process on processor
        i++;
    }
    int j = i;
    int k = 1;
    myProcessor.proMap.insert({i, k});
    while(myProcessor.proArr[j] == pro.ID){//erases process from processor and places hole in map
        myProcessor.proArr[j] = 0;
        myProcessor.proMap.erase(i);
        myProcessor.proMap.insert({i, k});
        k++;
        j++;
    }
    int y = 1;
    if(myProcessor.proArr[i + k + 1] == 0){ //if holes are touching, merges them
        myProcessor.proMap.erase(i+k+1);
        j = i;
        while(myProcessor.proArr[j] == 0){
            myProcessor.proMap.erase(i);
            myProcessor.proMap.insert({i, y});
            y++;
            j++;
        }
    }
    cout<<"ID: "<<pro.ID<<endl;
    cout<<"Memory: "<<pro.memory<<endl;
    cout<<"Service Time: " <<pro.serviceTime<<endl;
    cout<<"Starting at: "<<i<< endl;
    return myProcessor;
}

int findHole(Process pro, map<int,int> map1){//finds first hole that process will fit in
    auto iter = map1.begin();
    while (iter->second <  pro.memory) {
        if(iter == map1.end()){
            return 5;
        }else{
            iter++;
        }

    }
    return 1;
}

int findHoleW(Process pro, map<int,int> map1){ //finds the worst fit hole
    auto iter = map1.begin();
    int myMap = 1;
    int mapWBiggest = 0;
    int biggestHole = 0;
    while (iter != map1.end()) {
        if(iter->second > biggestHole){
            biggestHole = iter->second;
            mapWBiggest = myMap;
        }
        iter++;
    }
    if(biggestHole < pro.memory){
        mapWBiggest = 5;
    }
    return mapWBiggest;
}

void ff10(Process* pro){//memory is allocated using first fit between four processors with 10 MB of memory available
    using namespace std::chrono;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    Processor essor1; //creates an array for processor 1
    essor1.proMap[0] = 10000;//identifies that slot zero of memory 1 has a hole of 10000 KB
    map<int,int> myMap;//stores the map to be used
    int cycles = 0;
    int processorMap = 0;//finds the processor with a fitting hole
    queue <Process> waiting;//stores the processes waiting for space

    for(int i = 0; i<80; i++){//runs the simulation until all the processes have finished
        cycles += 100;
        if(!waiting.empty()){
            Process temp = waiting.front();
            waiting.pop();
            processorMap = findHole(pro[i],essor1.proMap);
            if(processorMap == 1){
                pro[i].processor = 1;
                essor1 = my_alloc(pro[i], essor1);
            }else{
                waiting.push(pro[i]);
            }
        }
        processorMap = findHole(pro[i],essor1.proMap);
        if(processorMap == 1){
            pro[i].processor = 1;
            essor1 = my_alloc(pro[i], essor1);
        }else{
        	cout<<pro[i].ID<<" does not fit because of its memory of: "<< pro[i].memory<<endl;
            //waiting.push(pro[i]);
        }
        for(int u = i; u>=0; u--){ //checks to see if each process on the processor has finished
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0 && pro[u].memory != 0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }
            }
        }
        }
    }

    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
    std::cout << "It took " << time_span.count() << " seconds.";
}

void wf10(Process* pro){//memory is allocated using worst fit between four processors with 10 MB of memory available
    using namespace std::chrono;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    Processor essor1; //creates an array for memory
    essor1.proMap[0] = 10000;//identifies that slot zero of processor 1 has a hole of 2500 KB
    map<int,int> myMap;//stores the map to be used
    int cycles = 0;
    int processorMap = 0;//finds the processor with a fitting hole
    queue <Process> waiting;//stores the processes waiting for space

    for(int i = 0; i<80; i++){//runs the simulation until all the processes have finished
        cycles += 100;
        processorMap = findHoleW(pro[i],essor1.proMap);
        if(processorMap == 1){
            pro[i].processor = 1;
            essor1 = my_allocW(pro[i], essor1);
        }else{
        	cout<<pro[i].ID<<" does not fit because of its memory of: "<< pro[i].memory<<endl;
            //waiting.push(pro[i]);
        }
        for(int u = i; u>=0; u--){ //checks to see if each process on the processor has finished
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0 && pro[u].memory != 0){
                    essor1 = my_free(pro[u], essor1);
                }
            }
        }
    }

    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
    std::cout << "It took " << time_span.count() << " seconds.";
}

void ff5(Process* pro){//memory is allocated using first fit between four processors with 5 MB of memory available
    using namespace std::chrono;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    Processor2 essor1; //creates an array for processor 1
    essor1.proMap[0] = 5000;//identifies that slot zero of memory has a hole of 5000KB
    map<int,int> myMap;//stores the map to be used
    int cycles = 0;
    int processorMap = 0;//finds the processor with a fitting hole
    queue <Process> waiting;//stores the processes waiting for space
    int saveMe;

    for(int i = 0; i<100; i++){//runs the simulation until all the processes have finished
        cycles += 100;
        if(!waiting.empty()){
            Process temp = waiting.front();
            waiting.pop();
            saveMe = i;
            i = temp.ID;
            processorMap = findHole(pro[i],essor1.proMap);
            if(processorMap == 1){
                pro[i].processor = 1;
                essor1 = my_alloc(pro[i], essor1);
            }else{
                waiting.push(pro[i]);
            }
            i = saveMe;
        }
        processorMap = findHole(pro[i],essor1.proMap);
        if(processorMap == 1){
            pro[i].processor = 1;
            essor1 = my_alloc(pro[i], essor1);
        }else{
            if(pro[i].memory>5000){
                cout<<pro[i].ID<<" does not fit because of its memory of: "<< pro[i].memory<<endl;
            }else{
                waiting.push(pro[i]);
            }
        }
        for(int u = i; u>=0; u--){ //checks to see if each process on the processor has finished
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0 && pro[u].memory > 1){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }
                }
            }
        }
    }

    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
    std::cout << "It took " << time_span.count() << " seconds.";
}

void wf5(Process* pro){//memory is allocated using worst fit between four processors with 5 MB of memory available
    using namespace std::chrono;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    Processor2 essor1; //creates an array for processor 1
    essor1.proMap[0] = 5000;//identifies that slot zero of processor 1 has a hole of 2500 KB
    map<int,int> myMap;//stores the map to be used
    int cycles = 0;
    int processorMap = 0;//finds the processor with a fitting hole
    queue <Process> waiting;//stores the processes waiting for space
    int saveMe;

    for(int i = 0; i<100; i++){//runs the simulation until all the processes have finished
        cycles += 100;
        if(!waiting.empty()){
            Process temp = waiting.front();
            waiting.pop();
            saveMe = i; //saves the value of i
            i = temp.ID;
            processorMap = findHoleW(pro[i],essor1.proMap);
            if(processorMap == 1){
                pro[i].processor = 1;
                essor1 = my_allocW(pro[i], essor1);
            }else{
                waiting.push(pro[i]);
            }
            i =saveMe;
        }
        processorMap = findHoleW(pro[i],essor1.proMap);
        if(processorMap == 1){
            pro[i].processor = 1;
            essor1 = my_allocW(pro[i], essor1);
        }else{
        	if(pro[i].memory>5000){
                cout<<pro[i].ID<<" does not fit because of its memory of: "<< pro[i].memory<<endl;
            }else{
                waiting.push(pro[i]);
            }
        }
        for(int u = i; u>=0; u--){ //checks to see if each process on the processor has finished
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0 && pro[u].memory > 1){
                    essor1 = my_free(pro[u], essor1);
                }
            }
        }
}

    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
    std::cout << "It took " << time_span.count() << " seconds.";
}

void ff1(Process* pro){//memory is allocated using first fit between four processors with 1 MB of memory available
    using namespace std::chrono;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    Processor3 essor1; //creates an array for processor 1
    essor1.proMap[0] = 1000;//identifies hole in memory with size 1000
    map<int,int> myMap;//stores the map to be used
    int cycles = 0;
    int processorMap = 0;//finds the processor with a fitting hole
    int saveMe;
    queue <Process> waiting;//stores the processes waiting for space

    for(int i = 0; i<200; i++){//runs the simulation until all the processes have finished
        cycles += 100;
        if(!waiting.empty()){
            Process temp = waiting.front();
            waiting.pop();
            saveMe = i;
            i = temp.ID;
            processorMap = findHole(pro[i],essor1.proMap);
            if(processorMap == 1){
                pro[i].processor = 1;
                essor1 = my_alloc(pro[i], essor1);
            }else{
                waiting.push(pro[i]);
            }
            i = saveMe;
        }
        if(i<50){
            processorMap = findHole(pro[i],essor1.proMap);
            if(processorMap == 1){
                pro[i].processor = 1;
                essor1 = my_alloc(pro[i], essor1);
            }else{
                if(pro[i].memory>1000){
                    cout<<pro[i].ID<<" does not fit because of its memory of: "<< pro[i].memory<<endl;
                }else{
                    waiting.push(pro[i]);
                }
            }
            for(int u = i; u>=0; u--){ //checks to see if each process on the processor has finished
                if(pro[u].cycles > 0){
                    pro[u].cycles-=100;
                    if (pro[u].cycles<=0 && pro[u].memory > 1){
                      if(pro[u].processor == 1){
                        essor1 = my_free(pro[u], essor1);
                      }
                    }
                }
            }
        }else{
            for(int u = 49; u>=0; u--){ //checks to see if each process on the processor has finished
                if(pro[u].cycles > 0){
                    pro[u].cycles-=100;
                    if (pro[u].cycles<=0 && pro[u].memory > 1){
                      if(pro[u].processor == 1){
                        essor1 = my_free(pro[u], essor1);
                      }
                    }
                }
            }
        }


    }
    while(!waiting.empty()){
        Process temp = waiting.front();
        waiting.pop();
                temp.processor = 1;
                essor1 = my_alloc(temp, essor1);
                cycles+=temp.cycles;
                essor1 = my_free(temp, essor1);


    }


    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
    std::cout << "It took " << time_span.count() << " seconds.";
}

void wf1(Process* pro){//memory is allocated using worst fit between four processors with 1 MB of memory available
    using namespace std::chrono;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    Processor3 essor1; //creates an array for processor 1
    essor1.proMap[0] = 1000;//identifies that slot zero of processor 1 has a hole of 2500 KB
    map<int,int> myMap;//stores the map to be used
    int cycles = 0;
    int saveMe;
    int processorMap = 0;//finds the processor with a fitting hole
    queue <Process> waiting;//stores the processes waiting for space

    for(int i = 0; i<200; i++){//runs the simulation until all the processes have finished
        cycles += 100;
        if(!waiting.empty()){
            Process temp = waiting.front();
            waiting.pop();
            saveMe = i; //saves the value of i
            i = temp.ID;
            processorMap = findHoleW(pro[i],essor1.proMap);
            if(processorMap == 1){
                pro[i].processor = 1;
                essor1 = my_allocW(pro[i], essor1);
            }else{
                waiting.push(pro[i]);
            }
            i =saveMe;
        }
        if(i<50){
            processorMap = findHoleW(pro[i],essor1.proMap);
            if(processorMap == 1){
                pro[i].processor = 1;
                essor1 = my_allocW(pro[i], essor1);
            }else{
                if(pro[i].memory>1000){
                    cout<<pro[i].ID<<" does not fit because of its memory of: "<< pro[i].memory<<endl;
                }else{
                    waiting.push(pro[i]);
                }
            }
            for(int u = i; u>=0; u--){ //checks to see if each process on the processor has finished
                if(pro[u].cycles > 0){
                    pro[u].cycles-=100;
                    if (pro[u].cycles<=0 && pro[u].memory>1){
                      if(pro[u].processor == 1){
                        essor1 = my_free(pro[u], essor1);
                        }
                    }
                }
            }
        }else{
            for(int u = 49; u>=0; u--){ //checks to see if each process on the processor has finished
                if(pro[u].cycles > 0){
                    pro[u].cycles-=100;
                    if (pro[u].cycles<=0 && pro[u].memory > 1){
                      if(pro[u].processor == 1){
                        essor1 = my_free(pro[u], essor1);
                      }
                    }
                }
            }
        }
    }
    while(!waiting.empty()){
        Process temp = waiting.front();
        waiting.pop();
        temp.processor = 1;
        essor1 = my_allocW(temp, essor1);
        cycles+=temp.cycles;
        essor1 = my_free(temp, essor1);

    }

    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
    std::cout << "It took " << time_span.count() << " seconds.";
}

int main(){
    int seedVal = getSeed(); //stores user supplied seed value
    Process *pro;
    pro = createPros(seedVal);
    cout<<"Using OS:"<<endl;
    useOS(pro);
    Process *pro1;
    pro1 = createPros(seedVal);
    cout<<endl<<endl<<"First Fit 10 MB:"<<endl;
    ff10(pro1);
    Process *pro2;
    pro2 = createPros(seedVal);
    cout<<endl<<endl<<"Worst Fit 10 MB:"<<endl;
    wf10(pro2);
    Process *pro3;
    pro3 = createPros(seedVal);
    cout<<endl<<endl<<"First Fit 5 MB:"<<endl;
    ff5(pro3);//done
    Process *pro4;
    pro4 = createPros(seedVal);
    cout<<endl<<endl<<"Worst Fit 5 MB:"<<endl;
    wf5(pro4);
    Process *pro5;
    pro5 = createPros(seedVal);
    cout<<endl<<endl<<"First Fit 1 MB:"<<endl;
    ff1(pro5);
    Process *pro6;
    pro6 = createPros(seedVal);
    cout<<endl<<endl<<"Worst Fit 1 MB:"<<endl;
    wf1(pro6);



}

