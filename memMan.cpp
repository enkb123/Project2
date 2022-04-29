/*
Eshen Brinkert
April 29, 2022
This program simulates the operating system loading processes onto processors based on their memory capacity and the method
in which the processes are to be loaded.
Note: As of right now there is a stack overflow error if I try to run scenario 2 using my IDE. But if
it does work when run on the online compiler ideone (https://ideone.com/TLe67X).
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
};

class Processor{ //processor object
public:
    int hz; //processor speed
    int memory; //processor memory
    map<int,int> proMap; //map that stores holes in processor
    int proArr[2500]; // array of 2500 for processor

};

int getSeed(){ //asks the user for a seed value and returns it
    int mySeed;
    cout<<"What value would you like your seed to be?"<<endl;
    cin>>mySeed;
    return mySeed;
}

Process* createPros(int seedVal){ //creates 50 processes with random memory and service times based on criteria. takes in user seed.
    static Process pro[50];
    srand(seedVal);//seeds the random generators with user seed
    default_random_engine generator(seedVal);
    normal_distribution<double> distribution(200,75); //distributes mem with mean of 200 and sd of 75
    int memLeft = 99950; //the amount of memory available for the processes after each gets onekb
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
        myPro.ID = i;
        pro[i] = myPro;
    }
    return pro;//returns pointer to array of processes
}

void useOS(Process* pro){//memory allocation is handled by the os in this scenario
    using namespace std::chrono;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    int cycles = 0;
    int* p0; int* p1; int* p2; int* p3; int* p4; int* p5; int* p6; int* p7; int* p8; int* p9;
    int* p10; int* p11; int* p12; int* p13; int* p14; int* p15; int* p16; int* p17; int* p18; int* p19;
    int* p20; int* p21; int* p22; int* p23; int* p24; int* p25; int* p26; int* p27; int* p28; int* p29;
    int* p30; int* p31; int* p32; int* p33; int* p34; int* p35; int* p36; int* p37; int* p38; int* p39;
    int* p40; int* p41; int* p42; int* p43; int* p44; int* p45; int* p46; int* p47; int* p48; int* p49;
    for(int i = 0; i<80; i++){
        cycles += 100;
        double byteVal = pro[i].memory * 1000; //calculates number of bytes process needs
        double intNum = byteVal/4;
        if(i == 0){
            p0 = (int*)malloc(byteVal);
            *p0 = byteVal;
        }else if(i>0){
            if(pro[0].cycles > 0){
                pro[0].cycles-=100;
                if (pro[0].cycles<=0){
                  free(p0);
                  p0 = NULL;
                  cout<<"ID: "<<pro[0].ID<<endl;
                  cout<<"Memory: "<<pro[0].memory<<endl;
                  cout<<"Service Time: " <<pro[0].serviceTime<<endl;
                }
            }
        }
        if(i == 1){
            p1 = (int*)malloc(byteVal);
            *p1 = byteVal;
        }else if(i>1){
            if(pro[1].cycles > 0){
                pro[1].cycles-=100;
                if (pro[1].cycles<=0){
                  free(p1);
                  p1=NULL;
                  cout<<"ID: "<<pro[1].ID<<endl;
                  cout<<"Memory: "<<pro[1].memory<<endl;
                  cout<<"Service Time: " <<pro[1].serviceTime<<endl;
                }
            }
        }
        if(i == 2){
            p2 = (int*)malloc(byteVal);
            *p2 = byteVal;
        }else if(i>2){
            if(pro[2].cycles > 0){
                pro[2].cycles-=100;
                if (pro[2].cycles<=0){
                  free(p2);
                  p2 = NULL;
                  cout<<"ID: "<<pro[2].ID<<endl;
                  cout<<"Memory: "<<pro[2].memory<<endl;
                  cout<<"Service Time: " <<pro[2].serviceTime<<endl;
                }
            }
        }
        if(i == 3){
            p3 = (int*)malloc(byteVal);
            *p3 = byteVal;
        }else if(i>3){
            if(pro[3].cycles > 0){
                pro[3].cycles-=100;
                if (pro[3].cycles<=0){
                  free(p3);
                  p3 = NULL;
                  cout<<"ID: "<<pro[3].ID<<endl;
                  cout<<"Memory: "<<pro[3].memory<<endl;
                  cout<<"Service Time: " <<pro[3].serviceTime<<endl;
                }
            }
        }
        if(i == 4){
            p4 = (int*)malloc(byteVal);
            *p4 = byteVal;
        }else if(i>4){
            if(pro[4].cycles > 0){
                pro[4].cycles-=100;
                if (pro[4].cycles<=0){
                  free(p4);
                  p4 = NULL;
                  cout<<"ID: "<<pro[4].ID<<endl;
                  cout<<"Memory: "<<pro[4].memory<<endl;
                  cout<<"Service Time: " <<pro[4].serviceTime<<endl;
                }
            }
        }
        if(i == 5){
            p5 = (int*)malloc(byteVal);
            *p5 = byteVal;
        }else if(i>5){
            if(pro[5].cycles > 0){
                pro[5].cycles-=100;
                if (pro[5].cycles<=0){
                  free(p5);
                  p5 = NULL;
                  cout<<"ID: "<<pro[5].ID<<endl;
                  cout<<"Memory: "<<pro[5].memory<<endl;
                  cout<<"Service Time: " <<pro[5].serviceTime<<endl;
                }
            }
        }
        if(i == 6){
            p6 = (int*)malloc(byteVal);
            *p6 = byteVal;
        }else if(i>6){
            if(pro[6].cycles > 0){
                pro[6].cycles-=100;
                if (pro[6].cycles<=0){
                  free(p6);
                  p6 = NULL;
                  cout<<"ID: "<<pro[6].ID<<endl;
                  cout<<"Memory: "<<pro[6].memory<<endl;
                  cout<<"Service Time: " <<pro[6].serviceTime<<endl;
                }
            }
        }
        if(i == 7){
            p7 = (int*)malloc(byteVal);
            *p7 = byteVal;
        }else if(i>7){
            if(pro[7].cycles > 0){
                pro[7].cycles-=100;
                if (pro[7].cycles<=0){
                  free(p7);
                  p7 =NULL;
                  cout<<"ID: "<<pro[7].ID<<endl;
                  cout<<"Memory: "<<pro[7].memory<<endl;
                  cout<<"Service Time: " <<pro[7].serviceTime<<endl;
                }
            }
        }
        if(i == 8){
            p8 = (int*)malloc(byteVal);
            *p8 = byteVal;
        }else if(i>8){
            if(pro[8].cycles > 0){
                pro[8].cycles-=100;
                if (pro[8].cycles<=0){
                  free(p8);
                  p8 =NULL;
                  cout<<"ID: "<<pro[8].ID<<endl;
                  cout<<"Memory: "<<pro[8].memory<<endl;
                  cout<<"Service Time: " <<pro[8].serviceTime<<endl;
                }
            }
        }
        if(i == 9){
            p9 = (int*)malloc(byteVal);
            *p9 = byteVal;
        }else if(i>9){
            if(pro[9].cycles > 0){
                pro[9].cycles-=100;
                if (pro[9].cycles<=0){
                  free(p9);
                  p9 =NULL;
                  cout<<"ID: "<<pro[9].ID<<endl;
                  cout<<"Memory: "<<pro[9].memory<<endl;
                  cout<<"Service Time: " <<pro[9].serviceTime<<endl;
                }
            }

        }if(i == 10){
            p10 = (int*)malloc(byteVal);
            *p10 = byteVal;
        }else if(i>10){
            if(pro[10].cycles > 0){
                pro[10].cycles-=100;
                if (pro[10].cycles<=0){
                  free(p10);
                  p10 =NULL;
                  cout<<"ID: "<<pro[10].ID<<endl;
                  cout<<"Memory: "<<pro[10].memory<<endl;
                  cout<<"Service Time: " <<pro[10].serviceTime<<endl;
                }
            }
        }
        if(i == 11){
            p11 = (int*)malloc(byteVal);
            *p11 = byteVal;
        }else if(i>11){
            if(pro[11].cycles > 0){
                pro[11].cycles-=100;
                if (pro[11].cycles<=0){
                  free(p11);
                  p11 =NULL;
                  cout<<"ID: "<<pro[11].ID<<endl;
                  cout<<"Memory: "<<pro[11].memory<<endl;
                  cout<<"Service Time: " <<pro[11].serviceTime<<endl;
                }
            }
        }
        if(i == 12){
            p12 = (int*)malloc(byteVal);
            *p12 = byteVal;
        }else if(i>12){
            if(pro[12].cycles > 0){
                pro[12].cycles-=100;
                if (pro[12].cycles<=0){
                  free(p12);
                  p12 =NULL;
                  cout<<"ID: "<<pro[12].ID<<endl;
                  cout<<"Memory: "<<pro[12].memory<<endl;
                  cout<<"Service Time: " <<pro[12].serviceTime<<endl;
                }
            }
        }
        if(i == 13){
            p13 = (int*)malloc(byteVal);
            *p13 = byteVal;
        }else if(i>13){
            if(pro[13].cycles > 0){
                pro[13].cycles-=100;
                if (pro[13].cycles<=0){
                  free(p13);
                  p13 =NULL;
                  cout<<"ID: "<<pro[13].ID<<endl;
                  cout<<"Memory: "<<pro[13].memory<<endl;
                  cout<<"Service Time: " <<pro[13].serviceTime<<endl;
                }
            }
        }
        if(i == 14){
            p14 = (int*)malloc(byteVal);
            *p14 = byteVal;
        }else if(i>14){
            if(pro[14].cycles > 0){
                pro[14].cycles-=100;
                if (pro[14].cycles<=0){
                  free(p14);
                  p14 =NULL;
                  cout<<"ID: "<<pro[14].ID<<endl;
                  cout<<"Memory: "<<pro[14].memory<<endl;
                  cout<<"Service Time: " <<pro[14].serviceTime<<endl;
                }
            }
        }
        if(i == 15){
            p15 = (int*)malloc(byteVal);
            *p15 = byteVal;
        }else if(i>5){
            if(pro[15].cycles > 0){
                pro[15].cycles-=100;
                if (pro[15].cycles<=0){
                  free(p15);
                  p15 =NULL;
                  cout<<"ID: "<<pro[15].ID<<endl;
                  cout<<"Memory: "<<pro[15].memory<<endl;
                  cout<<"Service Time: " <<pro[15].serviceTime<<endl;
                }
            }
        }
        if(i == 16){
            p16 = (int*)malloc(byteVal);
            *p16 = byteVal;
        }else if(i>16){
            if(pro[16].cycles > 0){
                pro[16].cycles-=100;
                if (pro[16].cycles<=0){
                  free(p16);
                  p16 =NULL;
                  cout<<"ID: "<<pro[16].ID<<endl;
                  cout<<"Memory: "<<pro[16].memory<<endl;
                  cout<<"Service Time: " <<pro[16].serviceTime<<endl;
                }
            }
        }
        if(i == 17){
            p17 = (int*)malloc(byteVal);
            *p17 = byteVal;
        }else if(i>17){
            if(pro[17].cycles > 0){
                pro[17].cycles-=100;
                if (pro[17].cycles<=0){
                  free(p17);
                  p17 =NULL;
                  cout<<"ID: "<<pro[17].ID<<endl;
                  cout<<"Memory: "<<pro[17].memory<<endl;
                  cout<<"Service Time: " <<pro[17].serviceTime<<endl;
                }
            }
        }
        if(i == 18){
            p18 = (int*)malloc(byteVal);
            *p18 = byteVal;
        }else if(i>18){
            if(pro[18].cycles > 0){
                pro[18].cycles-=100;
                if (pro[18].cycles<=0){
                  free(p18);
                  p18 =NULL;
                  cout<<"ID: "<<pro[18].ID<<endl;
                  cout<<"Memory: "<<pro[18].memory<<endl;
                  cout<<"Service Time: " <<pro[18].serviceTime<<endl;
                }
            }
        }
        if(i == 19){
            p19 = (int*)malloc(byteVal);
            *p19 = byteVal;
        }else if(i>19){
            if(pro[19].cycles > 0){
                pro[19].cycles-=100;
                if (pro[19].cycles<=0){
                  free(p19);
                  p19 =NULL;
                  cout<<"ID: "<<pro[19].ID<<endl;
                  cout<<"Memory: "<<pro[19].memory<<endl;
                  cout<<"Service Time: " <<pro[19].serviceTime<<endl;
                }
            }
        }if(i == 20){
            p20 = (int*)malloc(byteVal);
            *p20 = byteVal;
        }else if(i>20){
            if(pro[20].cycles > 0){
                pro[20].cycles-=100;
                if (pro[20].cycles<=0){
                  free(p20);
                  p20 =NULL;
                  cout<<"ID: "<<pro[20].ID<<endl;
                  cout<<"Memory: "<<pro[20].memory<<endl;
                  cout<<"Service Time: " <<pro[20].serviceTime<<endl;
                }
            }
        }
        if(i == 21){
            p21 = (int*)malloc(byteVal);
            *p21 = byteVal;
        }else if(i>21){
            if(pro[21].cycles > 0){
                pro[21].cycles-=100;
                if (pro[21].cycles<=0){
                  free(p21);
                  p21 =NULL;
                  cout<<"ID: "<<pro[21].ID<<endl;
                  cout<<"Memory: "<<pro[21].memory<<endl;
                  cout<<"Service Time: " <<pro[21].serviceTime<<endl;
                }
            }
        }
        if(i == 22){
            p22 = (int*)malloc(byteVal);
            *p22 = byteVal;
        }else if(i>22){
            if(pro[22].cycles > 0){
                pro[22].cycles-=100;
                if (pro[22].cycles<=0){
                  free(p2);
                  p22 =NULL;
                  cout<<"ID: "<<pro[22].ID<<endl;
                  cout<<"Memory: "<<pro[22].memory<<endl;
                  cout<<"Service Time: " <<pro[22].serviceTime<<endl;
                }
            }
        }
        if(i == 23){
            p23 = (int*)malloc(byteVal);
            *p23 = byteVal;
        }else if(i>23){
            if(pro[23].cycles > 0){
                pro[23].cycles-=100;
                if (pro[23].cycles<=0){
                  free(p23);
                  p23 =NULL;
                  cout<<"ID: "<<pro[23].ID<<endl;
                  cout<<"Memory: "<<pro[23].memory<<endl;
                  cout<<"Service Time: " <<pro[23].serviceTime<<endl;
                }
            }
        }
        if(i == 24){
            p24 = (int*)malloc(byteVal);
            *p24 = byteVal;
        }else if(i>24){
            if(pro[24].cycles > 0){
                pro[24].cycles-=100;
                if (pro[24].cycles<=0){
                  free(p24);
                  //p24 =NULL;
                  cout<<"ID: "<<pro[24].ID<<endl;
                  cout<<"Memory: "<<pro[24].memory<<endl;
                  cout<<"Service Time: " <<pro[24].serviceTime<<endl;
                }
            }
        }
        if(i == 25){
            p25 = (int*)malloc(byteVal);
            *p25 = byteVal;
        }else if(i>25){
            if(pro[25].cycles > 0){
                pro[25].cycles-=100;
                if (pro[25].cycles<=0){
                  free(p25);
                  //p25 =NULL;
                  cout<<"ID: "<<pro[25].ID<<endl;
                  cout<<"Memory: "<<pro[25].memory<<endl;
                  cout<<"Service Time: " <<pro[25].serviceTime<<endl;
                }
            }
        }
        if(i == 26){
            p26 = (int*)malloc(byteVal);
            *p26 = byteVal;
        }else if(i>26){
            if(pro[26].cycles > 0){
                pro[26].cycles-=100;
                if (pro[26].cycles<=0){
                  free(p26);
                  //p26 =NULL;
                  cout<<"ID: "<<pro[26].ID<<endl;
                  cout<<"Memory: "<<pro[26].memory<<endl;
                  cout<<"Service Time: " <<pro[26].serviceTime<<endl;
                }
            }
        }
        if(i == 27){
            p27 = (int*)malloc(byteVal);
            *p27 = byteVal;
        }else if(i>27){
            if(pro[27].cycles > 0){
                pro[27].cycles-=100;
                if (pro[27].cycles<=0){
                  free(p27);
                  //p27 =NULL;
                  cout<<"ID: "<<pro[27].ID<<endl;
                  cout<<"Memory: "<<pro[27].memory<<endl;
                  cout<<"Service Time: " <<pro[27].serviceTime<<endl;
                }
            }
        }
        if(i == 28){
            p28 = (int*)malloc(byteVal);
            *p28 = byteVal;
        }else if(i>28){
            if(pro[28].cycles > 0){
                pro[28].cycles-=100;
                if (pro[28].cycles<=0){
                  free(p28);
                  //p28 =NULL;
                  cout<<"ID: "<<pro[28].ID<<endl;
                  cout<<"Memory: "<<pro[28].memory<<endl;
                  cout<<"Service Time: " <<pro[28].serviceTime<<endl;
                }
            }
        }
        if(i == 29){
            p29 = (int*)malloc(byteVal);
            *p29 = byteVal;
        }else if(i>29){
            if(pro[29].cycles > 0){
                pro[29].cycles-=100;
                if (pro[29].cycles<=0){
                  free(p29);
                  //p29 =NULL;
                  cout<<"ID: "<<pro[29].ID<<endl;
                  cout<<"Memory: "<<pro[29].memory<<endl;
                  cout<<"Service Time: " <<pro[29].serviceTime<<endl;
                }
            }
        }if(i == 30){
            p30 = (int*)malloc(byteVal);
            *p30 = byteVal;
        }else if(i>30){
            if(pro[30].cycles > 0){
                pro[30].cycles-=100;
                if (pro[30].cycles<=0){
                  free(p30);
                  //p30 =NULL;
                  cout<<"ID: "<<pro[30].ID<<endl;
                  cout<<"Memory: "<<pro[30].memory<<endl;
                  cout<<"Service Time: " <<pro[30].serviceTime<<endl;
                }
            }
        }
        if(i == 31){
            p31 = (int*)malloc(byteVal);
            *p31 = byteVal;
        }else if(i>31){
            if(pro[31].cycles > 0){
                pro[31].cycles-=100;
                if (pro[31].cycles<=0){
                  free(p31);
                  //p31 =NULL;
                  cout<<"ID: "<<pro[31].ID<<endl;
                  cout<<"Memory: "<<pro[31].memory<<endl;
                  cout<<"Service Time: " <<pro[31].serviceTime<<endl;
                }
            }
        }
        if(i == 32){
            p32 = (int*)malloc(byteVal);
            *p32 = byteVal;
        }else if(i>32){
            if(pro[32].cycles > 0){
                pro[32].cycles-=100;
                if (pro[32].cycles<=0){
                  free(p32);
                  //p32 =NULL;
                  cout<<"ID: "<<pro[32].ID<<endl;
                  cout<<"Memory: "<<pro[32].memory<<endl;
                  cout<<"Service Time: " <<pro[32].serviceTime<<endl;
                }
            }
        }
        if(i == 33){
            p33 = (int*)malloc(byteVal);
            *p33 = byteVal;
        }else if(i>33){
            if(pro[33].cycles > 0){
                pro[33].cycles-=100;
                if (pro[33].cycles<=0){
                  free(p33);
                  //p33 =NULL;
                  cout<<"ID: "<<pro[33].ID<<endl;
                  cout<<"Memory: "<<pro[33].memory<<endl;
                  cout<<"Service Time: " <<pro[33].serviceTime<<endl;
                }
            }
        }
        if(i == 34){
            p4 = (int*)malloc(byteVal);
            *p4 = byteVal;
        }else if(i>34){
            if(pro[34].cycles > 0){
                pro[34].cycles-=100;
                if (pro[34].cycles<=0){
                  free(p34);
                  //p34 =NULL;
                  cout<<"ID: "<<pro[34].ID<<endl;
                  cout<<"Memory: "<<pro[34].memory<<endl;
                  cout<<"Service Time: " <<pro[34].serviceTime<<endl;
                }
            }
        }
        if(i == 35){
            p35 = (int*)malloc(byteVal);
            *p35 = byteVal;
        }else if(i>35){
            if(pro[35].cycles > 0){
                pro[35].cycles-=100;
                if (pro[35].cycles<=0){
                  free(p35);
                  //p35 =NULL;
                  cout<<"ID: "<<pro[35].ID<<endl;
                  cout<<"Memory: "<<pro[35].memory<<endl;
                  cout<<"Service Time: " <<pro[35].serviceTime<<endl;
                }
            }
        }
        if(i == 36){
            p36 = (int*)malloc(byteVal);
            *p36 = byteVal;
        }else if(i>36){
            if(pro[36].cycles > 0){
                pro[36].cycles-=100;
                if (pro[36].cycles<=0){
                  free(p36);
                  //p36 =NULL;
                  cout<<"ID: "<<pro[36].ID<<endl;
                  cout<<"Memory: "<<pro[36].memory<<endl;
                  cout<<"Service Time: " <<pro[36].serviceTime<<endl;
                }
            }
        }
        if(i == 37){
            p37 = (int*)malloc(byteVal);
            *p37 = byteVal;
        }else if(i>37){
            if(pro[37].cycles > 0){
                pro[37].cycles-=100;
                if (pro[37].cycles<=0){
                  free(p37);
                  //p37 =NULL;
                  cout<<"ID: "<<pro[37].ID<<endl;
                  cout<<"Memory: "<<pro[37].memory<<endl;
                  cout<<"Service Time: " <<pro[37].serviceTime<<endl;
                }
            }
        }
        if(i == 38){
            p38 = (int*)malloc(byteVal);
            *p38 = byteVal;
        }else if(i>38){
            if(pro[38].cycles > 0){
                pro[38].cycles-=100;
                if (pro[38].cycles<=0){
                  free(p38);
                  //p38 =NULL;
                  cout<<"ID: "<<pro[38].ID<<endl;
                  cout<<"Memory: "<<pro[38].memory<<endl;
                  cout<<"Service Time: " <<pro[38].serviceTime<<endl;
                }
            }
        }
        if(i == 39){
            p39 = (int*)malloc(byteVal);
            *p39 = byteVal;
        }else if(i>39){
            if(pro[39].cycles > 0){
                pro[39].cycles-=100;
                if (pro[39].cycles<=0){
                  free(p39);
                  //p39 =NULL;
                  cout<<"ID: "<<pro[39].ID<<endl;
                  cout<<"Memory: "<<pro[39].memory<<endl;
                  cout<<"Service Time: " <<pro[39].serviceTime<<endl;
                }
            }
        }if(i == 40){
            p40 = (int*)malloc(byteVal);
            *p40 = byteVal;
        }else if(i>40){
            if(pro[40].cycles > 0){
                pro[40].cycles-=100;
                if (pro[40].cycles<=0){
                  free(p40);
                  //p40 =NULL;
                  cout<<"ID: "<<pro[40].ID<<endl;
                  cout<<"Memory: "<<pro[40].memory<<endl;
                  cout<<"Service Time: " <<pro[40].serviceTime<<endl;
                }
            }
        }
        if(i == 41){
            p41 = (int*)malloc(byteVal);
            *p41 = byteVal;
        }else if(i>41){
            if(pro[41].cycles > 0){
                pro[41].cycles-=100;
                if (pro[41].cycles<=0){
                  free(p41);
                  //p41 =NULL;
                  cout<<"ID: "<<pro[41].ID<<endl;
                  cout<<"Memory: "<<pro[41].memory<<endl;
                  cout<<"Service Time: " <<pro[41].serviceTime<<endl;
                }
            }
        }
        if(i == 42){
            p42 = (int*)malloc(byteVal);
            *p42 = byteVal;
        }else if(i>42){
            if(pro[42].cycles > 0){
                pro[42].cycles-=100;
                if (pro[42].cycles<=0){
                  free(p42);
                  //p42 =NULL;
                  cout<<"ID: "<<pro[42].ID<<endl;
                  cout<<"Memory: "<<pro[42].memory<<endl;
                  cout<<"Service Time: " <<pro[42].serviceTime<<endl;
                }
            }
        }
        if(i == 43){
            p43 = (int*)malloc(byteVal);
            *p43 = byteVal;
        }else if(i>43){
            if(pro[43].cycles > 0){
                pro[43].cycles-=100;
                if (pro[43].cycles<=0){
                  free(p43);
                  //p43 =NULL;
                  cout<<"ID: "<<pro[43].ID<<endl;
                  cout<<"Memory: "<<pro[43].memory<<endl;
                  cout<<"Service Time: " <<pro[43].serviceTime<<endl;
                }
            }
        }
        if(i == 44){
            p44 = (int*)malloc(byteVal);
            *p44 = byteVal;
        }else if(i>44){
            if(pro[44].cycles > 0){
                pro[44].cycles-=100;
                if (pro[44].cycles<=0){
                  free(p44);
                  //p44 =NULL;
                  cout<<"ID: "<<pro[44].ID<<endl;
                  cout<<"Memory: "<<pro[44].memory<<endl;
                  cout<<"Service Time: " <<pro[44].serviceTime<<endl;
                }
            }
        }
        if(i == 45){
            p45 = (int*)malloc(byteVal);
            *p45 = byteVal;
        }else if(i>45){
            if(pro[45].cycles > 0){
                pro[45].cycles-=100;
                if (pro[45].cycles<=0){
                  free(p45);
                  //p45 =NULL;
                  cout<<"ID: "<<pro[45].ID<<endl;
                  cout<<"Memory: "<<pro[45].memory<<endl;
                  cout<<"Service Time: " <<pro[45].serviceTime<<endl;
                }
            }
        }
        if(i == 46){
            p46 = (int*)malloc(byteVal);
            *p46 = byteVal;
        }else if(i>46){
            if(pro[46].cycles > 0){
                pro[46].cycles-=100;
                if (pro[46].cycles<=0){
                  free(p46);
                  //p46 =NULL;
                  cout<<"ID: "<<pro[46].ID<<endl;
                  cout<<"Memory: "<<pro[46].memory<<endl;
                  cout<<"Service Time: " <<pro[46].serviceTime<<endl;
                }
            }
        }
        if(i == 47){
            p47 = (int*)malloc(byteVal);
            *p47 = byteVal;
        }else if(i>47){
            if(pro[47].cycles > 0){
                pro[47].cycles-=100;
                if (pro[47].cycles<=0){
                  free(p47);
                  //p47 =NULL;
                  cout<<"ID: "<<pro[47].ID<<endl;
                  cout<<"Memory: "<<pro[47].memory<<endl;
                  cout<<"Service Time: " <<pro[47].serviceTime<<endl;
                }
            }
        }
        if(i == 48){
            p48 = (int*)malloc(byteVal);
            *p48 = byteVal;
        }else if(i>48){
            if(pro[48].cycles > 0){
                pro[48].cycles-=100;
                if (pro[48].cycles<=0){
                  free(p48);
                  //p48 =NULL;
                  cout<<"ID: "<<pro[48].ID<<endl;
                  cout<<"Memory: "<<pro[48].memory<<endl;
                  cout<<"Service Time: " <<pro[48].serviceTime<<endl;
                }
            }
        }
        if(i == 49){
            p49 = (int*)malloc(byteVal);
            *p49 = byteVal;
        }else if(i>49){
            if(pro[49].cycles > 0){
                pro[49].cycles-=100;
                if (pro[49].cycles<=0){
                  free(p49);
                  //p49 =NULL;
                  cout<<"ID: "<<pro[49].ID<<endl;
                  cout<<"Memory: "<<pro[49].memory<<endl;
                  cout<<"Service Time: " <<pro[49].serviceTime<<endl;
                }
            }
        }
        //cout<<cycles<<endl;

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
    cout<<"On processor: " <<pro.processor<<endl;
    cout<<"Starting at: "<<i<< endl;
    return myProcessor;
}

int findHole(Process pro, map<int,int> map1, map<int, int> map2, map<int, int> map3, map<int, int> map4){//finds hole that process will fit in
    auto iter = map1.begin();
    int myMap = 1;
    while (iter->second <  pro.memory) {
        if(iter == map1.end()){
                myMap = 2;
                iter = map2.begin();
                while(iter->second <pro.memory){
                    if(iter == map2.end()){
                        myMap = 3;
                        iter = map3.begin();
                        while(iter->second <pro.memory){
                            if(iter == map3.end()){
                                myMap = 4;
                                iter = map4.begin();
                                while(iter->second < pro.memory){
                                    if(iter == map4.end()){
                                        return 5;//means that there was no spot for process
                                    }else{
                                        iter++;
                                    }
                                }
                            }else{
                                iter++;
                            }
                        }
                    }else{
                        iter++;
                    }
                }
        }else{
            iter++;
        }

    }
    return myMap;
}

void ff10(Process* pro){//memory is allocated using first fit between four processors with 10 MB of memory available
    using namespace std::chrono;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    Processor essor1; //creates an array for processor 1
    Processor essor2; //creates an array for processor 2
    Processor essor3; //creates an array for processor 3
    Processor essor4; //creates an array for processor 4
    essor1.proMap[0] = 2500;//identifies that slot zero of processor 1 has a hole of 2500 KB
    essor2.proMap[0] = 2500;//identifies that slot zero of processor 1 has a hole of 2500 KB
    essor3.proMap[0]= 2500;//identifies that slot zero of processor 1 has a hole of 2500 KB
    essor4.proMap[0] = 2500;//identifies that slot zero of processor 1 has a hole of 2500 KB
    map<int,int> myMap;//stores the map to be used
    int cycles = 0;
    int processorMap = 0;//finds the processor with a fitting hole
    queue <Process> waiting;//stores the processes waiting for space

    for(int i = 0; i<80; i++){
        cycles += 100;
        processorMap = findHole(pro[i],essor1.proMap, essor2.proMap, essor3.proMap, essor4.proMap);
        if(processorMap == 1){
            pro[i].processor = 1;
            essor1 = my_alloc(pro[i], essor1);
        }else if(processorMap == 2){
            pro[i].processor = 2;
            essor2 = my_alloc(pro[i], essor2);
        }else if(processorMap == 3){
            pro[i].processor = 3;
            essor3 = my_alloc(pro[i], essor3);
        }else if(processorMap == 4){
            pro[i].processor = 4;
            essor4 = my_alloc(pro[i], essor4);
        }else{
        	cout<<pro[i].ID<<" does not fit"<<endl;
            //waiting.push(pro[i]);
        }

        if(i>0){
            if(pro[0].cycles > 0){
                pro[0].cycles-=100;
                if (pro[0].cycles<=0){
                  if(pro[0].processor == 1){
                    essor1 = my_free(pro[0], essor1);
                  }else if(pro[0].processor == 2){
                    essor2 = my_free(pro[0], essor2);
                  }else if(pro[0].processor == 3){
                    essor3 = my_free(pro[0], essor3);
                  }else if(pro[0].processor == 4)
                    essor4 = my_free(pro[0], essor4);
                }
            }
        }
         if(i>1){
            int u = 1;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
      if(i>2){
            int u = 2;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
     if(i>3){
            int u = 3;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
     if(i>4){
            int u = 4;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
       if(i>5){
            int u = 5;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
       if(i>6){
            int u = 6;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
       if(i>7){
            int u = 7;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
         if(i>8){
            int u = 8;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
         if(i>9){
            int u = 9;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
        if(i>10){
            int u = 10;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
         if(i>11){
            int u = 11;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
       if(i>12){
            int u = 12;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
        if(i>13){
            int u = 13;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
         if(i>14){
            int u = 14;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
         if(i>15){
            int u = 15;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
         if(i>16){
            int u = 16;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
         if(i>17){
            int u = 17;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
         if(i>18){
            int u = 18;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
         if(i>19){
            int u = 19;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
         if(i>20){
            int u = 20;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
        if(i>21){
            int u = 21;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
        if(i>22){
            int u = 22;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
        if(i>23){
            int u = 23;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
        if(i>24){
            int u = 24;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
        if(i>25){
            int u = 25;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
        if(i>26){
            int u = 26;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
        if(i>27){
            int u = 27;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
        if(i>28){
            int u = 28;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
        if(i>29){
            int u = 29;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
        if(i>30){
            int u = 30;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
        if(i>31){
            int u = 31;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
        if(i>32){
            int u = 32;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
        if(i>33){
            int u = 33;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
        if(i>34){
            int u = 34;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
        if(i>35){
            int u = 35;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
        if(i>36){
            int u = 36;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
        if(i>37){
            int u = 37;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
        if(i>38){
            int u = 38;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
        if(i>39){
            int u = 39;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
        if(i>40){
            int u = 40;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
        if(i>41){
            int u = 41;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
        if(i>42){
            int u = 42;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
        if(i>43){
            int u = 43;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
        if(i>44){
            int u = 44;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
        if(i>45){
            int u = 45;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
        if(i>46){
            int u = 46;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
        if(i>48){
            int u = 48;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }
        if(i>49){
            int u = 49;
            if(pro[u].cycles > 0){
                pro[u].cycles-=100;
                if (pro[u].cycles<=0){
                  if(pro[u].processor == 1){
                    essor1 = my_free(pro[u], essor1);
                  }else if(pro[u].processor == 2){
                    essor2 = my_free(pro[u], essor2);
                  }else if(pro[u].processor == 3){
                    essor3 = my_free(pro[u], essor3);
                  }else if(pro[u].processor == 4)
                    essor4 = my_free(pro[u], essor4);
                }
            }
        }




    }

    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
    std::cout << "It took " << time_span.count() << " seconds.";
}

void wf10(Process* pro){//memory is allocated using worst fit between four processors with 10 MB of memory available

}

int main(){
    int seedVal = getSeed(); //stores user supplied seed value
    Process *pro;
    pro = createPros(seedVal);

    int scenario;
    cout<<"Which scenario would you like to run: 1, 2, 3, or 4?"<<endl;
    cin>>scenario;
    switch(scenario){//runs the scenario that the user has selected
    case 1:
        useOS(pro);
        break;
    case 2:
        ff10(pro);
        wf10(pro);
        break;
    case 3:
        break;
    case 4:
        break;
    default:
        cout<<"That was not a valid selection."<<endl;
        break;
    }


}

