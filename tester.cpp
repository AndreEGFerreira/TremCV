#include <iostream>
using namespace std;

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

int qtdeUns[16] = {1,1,1,1,1,1,1,1,1,1,2,2,1,1,1,1};

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

int main (void){

    int colunaDaVez = buscaTransicaoAtiva();

    for(int i=0; i<17; i++){
        redePetri[i] -= preTrans[i][colunaDaVez];
        cout << redePetri[i] << " ";
    }

    cout << endl << endl << colunaDaVez << endl;

    for(int j=0; j<17; j++){
            preTrans[j][colunaDaVez] = 88;
    }
    for(int i=0; i<17; i++){
        for(int j=0; j<16; j++){
            cout << preTrans[i][j] << " ";
        }
        cout << "i =" << i << endl;
    }

}
