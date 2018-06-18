#include <iostream>
#include "class/mapatrem.h"
#include "class/threads/thread.h"
#include <vector>

using namespace std;

int posTrans[17][16] = {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,
                        0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,};

int preTrans[17][16] = {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,
                        0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,
                        0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,
                        0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                        0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,
                        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
                        0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,};

int qtdeUns[16] = {1,1,1,1,1,1,1,1,1,1,2,2,1,1,1,1};  //quantidade de "1" em cada transicao da matrz preTrans

int redePetri[17] = {0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0};

int buscaTransicaoAtiva(){
    int nroUns = 0;

    for(int j = 0; j < 16; j++){
        nroUns = 0;
        for(int i = 0; i < 17; i++){
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
    pt1.push_back(Point(25, 158));
    pt1.push_back(Point(67, 158));
    pt1.push_back(Point(180, 158));
    pt1.push_back(Point(304, 242));
    pt1.push_back(Point(435, 242));
    pt1.push_back(Point(475, 242));

    vector<Point> pt2;
    pt2.push_back(Point(25, 326));
    pt2.push_back(Point(67, 326));
    pt2.push_back(Point(180, 326));
    pt2.push_back(Point(304, 242));
    pt2.push_back(Point(435, 242));
    pt2.push_back(Point(475, 242));

    //trens.Trem1Pos(200,200);
    //trens.Trem2Pos(100,200);
    //trens.Trem1Txt("Mensagem trem 1.");
    //trens.Trem2Txt("Mensagem trem 2.");

    int colunaDaVez;

    while (1) {
        colunaDaVez = buscaTransicaoAtiva();

        for(int i=0; i<17; i++){
            redePetri[i] -= preTrans[colunaDaVez][i];
        }

        switch (colunaDaVez) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
        }
    }

    // A CADA ITERAÇÃO VER DE COLUNA EM COLUNA SE EH POSSIVEL LANCAR A TRANSICAO <<<<<<<<<<<<<<<<<<<<<<<<<<<< FEITO
    // PEGA A COLUNA preTrans E QUANDO ACHAR 1, PROCURAR SE NO VETOR TEM 1 TBM, ENTAO DA PARA FAZER <<<<<<<<< FEITO

    trens.Gate(1);
    for(Point p : pt1)
    {
        trens.Trem1Pos(p.x,p.y);  //como pegar posição +-
        Thread::SleepMS(3000);    //tempo SLEEP NORMAL

        int key = trens.GetLastKey();
        cout << "LastKey = " << key << endl;
        if(key == 27)
            return 1;
    }

    trens.Gate(0);
    for(Point p : pt2)
    {
        trens.Trem2Pos(p.x,p.y);
        Thread::SleepMS(3000);

        int key = trens.GetLastKey();
        cout << "LastKey = " << key << endl;
        if(key == 27)
            return 1;
    }

    return 0;
}
