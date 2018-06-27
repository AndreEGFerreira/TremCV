#include <iostream>
#include "class/mapatrem.h"
#include "class/threads/thread.h"
#include <vector>
#include <unistd.h>

using namespace std;

int posTrans[23][22] = {0 ,	0 ,	0 ,	0 ,	1 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0,
                        0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	1 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0,
                        0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	1 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0,
                        0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	1 ,	0 ,	0 ,	0,
                        0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	1 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0,
                        0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	1 ,	0 ,	0,
                        0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	1 ,	0 ,	0 ,	0 ,	0,
                        0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	1 ,	0 ,	0 ,	0 ,	0 ,	0,
                        0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	1 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0,
                        0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	1 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0,
                        0 ,	1 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0,
                        0 ,	0 ,	0 ,	1 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0,
                        0 ,	0 ,	0 ,	0 ,	0 ,	1 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0,
                        0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	1 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0,
                        0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	1 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0,
                        0 ,	0 ,	1 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0,
                        1 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0,
                        0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	1 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0,
                        0 ,	0 ,	0 ,	0 ,	0 ,	1 ,	0 ,	1 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0,
                        0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	1 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0,
                        0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	1 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0,
                        0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	1 ,	0,
                        0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	1};

int preTrans[23][22] = {0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	1 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0,
                        0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	1 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0,
                        0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	1 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0,
                        0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	1,
                        0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	1 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0,
                        0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	1 ,	0,
                        0 ,	0 ,	1 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0,
                        1 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0,
                        0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	1 ,	0 ,	0 ,	0,
                        0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	1 ,	0 ,	0,
                        0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	1 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0,
                        0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	1 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0,
                        0 ,	1 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0,
                        0 ,	0 ,	0 ,	1 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0,
                        0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	1 ,	0 ,	0 ,	0 ,	0 ,	0,
                        0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	1 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0,
                        0 ,	0 ,	0 ,	0 ,	1 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0,
                        0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	1 ,	0 ,	0 ,	0 ,	0,
                        0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	1 ,	1 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0,
                        0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	1 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0,
                        0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	1 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0,
                        0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	1 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0,
                        0 ,	0 ,	0 ,	0 ,	0 ,	1 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0};

int qtdeUns[22] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1};

int redePetri[23] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0};

int buscaTransicaoAtiva(){
    int nroUns = 0;

    for(int j = 0; j < 22; j++){
        nroUns = 0;
        for(int i = 0; i < 23; i++){
            if(preTrans[i][j] == 1 && redePetri[i] == 1){
                nroUns++;

            }
            if (nroUns == qtdeUns[j])
                return j;
        }
    }
}

int main(int argc, char **argv) {
    MapaTrem trens;

    // posições para os trens
    vector<Point> pt1;
    pt1.push_back(Point(25, 158));  // Estacao inicial
    pt1.push_back(Point(67, 158));  // a1
    pt1.push_back(Point(180, 158)); // b1
    pt1.push_back(Point(304, 242)); // ponto crit
    pt1.push_back(Point(435, 242)); // c1
    pt1.push_back(Point(475, 242)); // Engelberg

    vector<Point> pt2;
    pt2.push_back(Point(25, 326));  // Estacao Inicial
    pt2.push_back(Point(67, 326));  // a2
    pt2.push_back(Point(180, 326)); // b2
    pt2.push_back(Point(304, 242)); // ponto crit
    pt2.push_back(Point(435, 242)); // c1
    pt2.push_back(Point(475, 242)); // Engelberg

    //trens.Trem1Pos(200,200);
    //trens.Trem2Pos(100,200);
    //trens.Trem1Txt("Mensagem trem 1.");
    //trens.Trem2Txt("Mensagem trem 2.");

    int colunaDaVez;

    while (1) {
        colunaDaVez = buscaTransicaoAtiva();

        for(int i=0; i<23; i++){
            redePetri[i] -= preTrans[i][colunaDaVez];
        }

        switch (colunaDaVez) {
            case 0:
                trens.Trem1Txt("A1 Ativo");
                trens.Trem1Pos(67,158);
                break;
            case 1:
                trens.Trem1Txt("A1 Ativo");
                trens.Trem1Pos(67,158);
                break;
            case 2:
                trens.Trem2Txt("A2 Ativo");
                trens.Trem2Pos(67, 326);
                break;
            case 3:
                trens.Trem2Txt("A2 Ativo");
                trens.Trem2Pos(67, 326);
                break;
            case 4:
                trens.Trem1Txt("B1 Ativo");
                trens.Trem1Pos(180, 158);
                break;
            case 5:
                trens.Trem1Txt("Stans");
                trens.Trem1Pos(304, 242);
                sleep(1);
                trens.Trem1Txt("B1 Ativo");
                trens.Trem1Pos(180, 158);
                break;
            case 6:
                trens.Trem2Txt("B2 Ativo");
                trens.Trem2Pos(180, 326);
                break;
            case 7:
                trens.Trem2Txt("Stans");
                trens.Trem2Pos(304, 242);
                sleep(1);
                trens.Trem2Txt("B2 Ativo");
                trens.Trem2Pos(180, 326);
                break;
            case 8:
                trens.Trem1Txt("C1 Ativo");
                trens.Trem1Pos(435, 242);
                break;
            case 9:
                trens.Trem2Txt("C2 Ativo");
                trens.Trem2Pos(435, 242);
                break;
            case 10:
                trens.Trem1Txt("Estacionamento T1");
                trens.Trem1Pos(25, 158);
                break;
            case 11:
                trens.Trem2Txt("Estacionamento T2");
                trens.Trem2Pos(25, 326);
                break;
            case 12:
                trens.Trem1Txt("Freiar T1");
                trens.Trem1Pos(235, 197);
                break;
            case 13:
                trens.Trem2Txt("Freiar T2");
                trens.Trem2Pos(235, 288);
                break;
            case 14:
                trens.Trem2Txt("G = 0");
                trens.Gate(0);
                sleep(0.5);
                trens.Trem2Pos(304, 242);
                break;
            case 15:
                trens.Trem1Txt("G = 1");
                trens.Gate(1);
                sleep(0.5);
                trens.Trem1Pos(304, 242);
                break;
            case 16:
                trens.Trem1Txt("M1");
                trens.Trem1Pos(25, 158);
                break;
            case 17:
                trens.Trem2Txt("M2");
                trens.Trem2Pos(25, 326);
                break;
            case 18:
                trens.Trem1Txt("Partida Engelberg T1");
                trens.Trem1Pos(475, 242);
                break;
            case 19:
                trens.Trem2Txt("Partida Engelberg T2");
                trens.Trem2Pos(475, 242);
                break;
            case 20:
                trens.Trem2Txt("C2 Ativo");
                trens.Trem2Pos(435, 242);
                break;
            case 21:
                trens.Trem1Txt("C1 Ativo");
                trens.Trem1Pos(435, 242);
                break;
        }

        sleep(1);

        for(int i=0; i<23; i++){
            redePetri[i] += posTrans[i][colunaDaVez];
        }
    }

    return 0;
}
