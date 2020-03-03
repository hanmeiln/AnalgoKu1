/*
Nama Program    : Stable Matching
Nama            : Hana Meilina Fauziyyah
NPM             : 140810180012
Kelas           : B
********************************************/

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define N 5

bool chooseMen(int priority[2 * N][N], int m, int m1, int w);
void match(int prioritas[2 * N][N]);

main(){
    int priority[2 * N][N] =    {{6, 5, 8, 9, 7},
                                {8, 6, 5, 7, 9},
                                {6, 9, 7, 8, 5},
                                {5, 8, 7, 6, 9},
                                {6, 8, 5, 9, 7},
                                {4, 0, 1, 3, 2},
                                {2, 1, 3, 0, 4},
                                {1, 2, 3, 4, 0},
                                {0, 4, 3, 2, 1},
                                {3, 1, 4, 2, 0}};
    match(priority);
    return 0;
}

bool chooseMen(int priority[2 * N][N], int m, int m1, int w){
    for (int i = 0; i < N; i++)
    {
        if (priority[w][i] == m1)
            return true;

        if (priority[w][i] == m)
            return false;
    }
}

void match(int priority[2 * N][N]){
    int wanita[N];
    bool pria[N];
    memset(wanita, -1, sizeof(wanita));
    memset(pria, false, sizeof(pria));
    int jumlah=N;

    while (jumlah>0){
        int m;
        for(m=0;m<N;m++)
            if (pria[m]==false)
            break;

        for(int i=0;i<N&&pria[m]==false;i++){
            int w=priority[m][i];
            if(wanita[w-N]==-1){
                wanita[w-N]=m;
                pria[m]=true;
                jumlah--;
            }
            else{
                int m1=wanita[w-N];
                if(chooseMen(priority, m, m1, w)==false){
                    wanita[w - N] = m;
                    pria[m] = true;
                    pria[m1] = false;
                }
            }
        }
    }

    cout<<"Hana Meilina Fauziyyah"<<endl;
    cout<<"140810180012"<<endl;
    cout<<endl;
    cout<<"=-=-=-=-=-=-=-=-="<<endl;
    cout<<"  Pria     Wanita  "<<endl;
    cout<<"................."<<endl;
    string man;
    string woman;
    for (int i = 0; i < N; i++){
        if (i < N){
            if (wanita[i] == 0)
                man = "Victor";
            if (wanita[i] == 1)
                man = "Wyatt";
            if (wanita[i] == 2)
                man = "Xavier";
            if (wanita[i] == 3)
                man = "Yancey";
            if (wanita[i] == 4)
                man = "Zeus";

            if (i == 0)
                woman = "Amy";
            if (i == 1)
                woman = "Bertha";
            if (i == 2)
                woman = "Clare";
            if (i == 3)
                woman = "Diane";
            if (i == 4)
                woman = "Erika";
        }
        cout<<" "<<man<<"\t  "<<woman<<endl;
    }
    cout<<"=-=-=-=-=-=-=-=-="<<endl;
}
