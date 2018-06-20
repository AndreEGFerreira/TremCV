#include <iostream>
#include "class/mapatrem.h"
#include "class/threads/thread.h"
#include <vector>
#include <unistd.h>

using namespace std;


/* CARA, TEM QUE FAZER MUITA TRANSICAO E ESTADOS, ATUALMENTE ESTÁ MUUUUITO INCOMPLETO, QUASE NÃO DA PARA FAZER ASSIM */
int posTrans[17][16] = {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,
                        0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                        0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,
                        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,
                        0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0};

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
                        0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0};

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
            redePetri[i] -= preTrans[i][colunaDaVez];
        }

        switch (colunaDaVez) {
            case 0:
                trens.Trem1Txt("A1 Ativo");
                trens.Trem1Pos(67,158);
                break;
            case 1:
                trens.Trem2Txt("A2 Ativo");
                break;
            case 2:
                trens.Trem1Txt("B1 Volta");
                break;
            case 3:
                trens.Trem2Txt("B2 Volta");
                break;
            case 4:
                trens.Trem1Txt("Estacionamento T1");
                break;
            case 5:
                trens.Trem2Txt("Estacionamento T2");
                break;
            case 6:
                trens.Trem1Txt("Freiar T1");
                break;
            case 7:
                trens.Trem2Txt("Freiar T2");
                break;
            case 10:
                trens.Trem1Txt("G = 0");
                trens.Gate(1);
                break;
            case 11:
                trens.Trem2Txt("G = 1");
                trens.Gate(0);
                break;
            case 12:
                trens.Trem1Txt("M1");
                break;
            case 13:
                trens.Trem2Txt("M2");
                break;
            case 14:
                trens.Trem1Txt("Partida Engelberg T1");
                break;
            case 15:
                trens.Trem2Txt("Partida Engelberg T2");
                break;
            case 8:
                trens.Trem1Txt("Freiar T1");
                break;
            case 9:
                trens.Trem2Txt("Freiar T2");
                break;
        }

        sleep(1);

        for(int i=0; i<17; i++){
            redePetri[i] += posTrans[i][colunaDaVez];
        }
    }

    // A CADA ITERAÇÃO VER DE COLUNA EM COLUNA SE EH POSSIVEL LANCAR A TRANSICAO <<<<<<<<<<<<<<<<<<<<<<<<<<<< FEITO
    // PEGA A COLUNA preTrans E QUANDO ACHAR 1, PROCURAR SE NO VETOR TEM 1 TBM, ENTAO DA PARA FAZER <<<<<<<<< FEITO

    trens.Gate(1);
    for(Point p : pt1)
    {
        trens.Trem2Txt("lul");
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
