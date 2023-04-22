#include <stdio.h>
#include <string.h>
#include <graphics.h>
#include <stdlib.h>


int i, tamanho[6][4] = {050, 150, 200, 300,
                        050, 350, 200, 500,
                        250, 150, 400, 300,
                        250, 350, 400, 500,
                        450, 150, 600, 300,
                        450, 350, 600, 500},

        medida [6][4] = {115, 390, 265, 550,
                         295, 390, 445, 550,
                         475, 390, 625, 550,
                         655, 390, 805, 550,
                         835, 390, 985, 550,
                         1015,390,1165, 550};


char confirma[9]="Confirma", cancela[8]="Cancela";

struct candidatos{
    char nome[15], foto[20], votoTela[5], seguidores[25];
    int voto;
    int conferir;


};
candidatos c[6];
candidatos r[6];

void desenharTela();
void alocarFotosENomes();
void zerarVariavel(int zerar, int extensao);
void funcaoImagem(int x1, int x2, int y1, int y2, int candidato);
void finalizarVotacao();
int segundaTela = initwindow(1280,600,"Ranking",150,100), primeiraTela = initwindow(1280,600,"Votacao",150,100);


main(){

    zerarVariavel(r[i].voto,6);
    zerarVariavel(c[i].voto,6);
    alocarFotosENomes();
    desenharTela();
    while(!kbhit())
    {
        for(i=0;i<6;i++)
            funcaoImagem(tamanho[i][0], tamanho[i][1], tamanho[i][2], tamanho[i][3], i);
        finalizarVotacao();
    }

}
void zerarVariavel(int zerar, int extensao)
{
    for(i=0;i<extensao;i++)
    zerar;
}
void alocarFotosENomes()
{
    strcpy(c[0].nome, "Gaulês");
    strcpy(c[0].foto, "./img/GAU.jpg");
    strcpy(c[0].seguidores, "3,6 Mi seguidores");

    strcpy(c[1].nome, "Michel");
    strcpy(c[1].foto, "./img/MCH.jpg");
    strcpy(c[1].seguidores, "549,4 mil seguidores");

    strcpy(c[2].nome, "Velho Vamp");
    strcpy(c[2].foto, "./img/VVV.jpg");
    strcpy(c[2].seguidores, "262,7 mil seguidores");

    strcpy(c[3].nome, "Liminha");
    strcpy(c[3].foto, "./img/LIMAS.jpg");
    strcpy(c[3].seguidores, "548,2 mil seguidores");

    strcpy(c[4].nome, "Apoka");
    strcpy(c[4].foto, "./img/APOKA.jpg");
    strcpy(c[4].seguidores, "246,7 mil seguidores");

    strcpy(c[5].nome, "Bt0");
    strcpy(c[5].foto, "./img/BT0.jpg");
    strcpy(c[5].seguidores, "357,8 mil seguidores");
}
void desenharTela()
{
    setcurrentwindow(primeiraTela);
    readimagefile("./img/Tribonera.jpg", 0, 0, 1280, 600);
    for(i=0;i<6;i++){
        readimagefile("./img/preto.jpg",tamanho[i][0]+7, tamanho[i][1]+7, tamanho[i][2]+7, tamanho[i][3]+7);
        readimagefile(c[i].foto,tamanho[i][0], tamanho[i][1], tamanho[i][2], tamanho[i][3]);
    }

    readimagefile("./img/titulo2.jpg", 0, 15, 1280 , 90);

    readimagefile("./img/preto.jpg", 1005, 505, 1155, 545);
    setfillstyle(1,2);
    bar(1000,500,1150,540);
    setlinestyle(0,0,3);
    setcolor(3);
    rectangle(1000,500,1150,540);
    setcolor(0);
    settextstyle(0, 0, 2);
    setbkcolor(2);
    outtextxy(1020,515,confirma);

    readimagefile("./img/preto.jpg", 825, 505, 975, 545);
    setfillstyle(1,4);
    bar(820,500,970,540);
    setlinestyle(0,0,3);
    setcolor(3);
    rectangle(820,500,970,540);
    setcolor(0);
    settextstyle(0, 0, 2);
    setbkcolor(4);
    outtextxy(850,515,cancela);

    readimagefile("./img/preto.jpg", 1205, 35, 1255, 80);
    settextstyle(0, 0, 5);
    setcolor(15);
    setbkcolor(4);
    bar(1200,30,1250,75);
    outtextxy(1205,35, "X");

}

void funcaoImagem(int x1, int y1, int x2, int y2, int candidato)
{
    if(ismouseclick(WM_LBUTTONDOWN)&& mousex() > x1 && mousex() < x2   //CLICK NA IMAGEM
                                    && mousey() > y1 && mousey() < y2)
        {   setcurrentwindow(primeiraTela);
            for(i=0;i<6;i++)
            c[i].conferir = 0;
            c[candidato].conferir++;
            clearmouseclick(WM_LBUTTONDOWN);
            readimagefile("./img/recorte2.jpg", 805, 150,1165, 499);
            readimagefile("./img/preto.jpg", 860, 180, 1130, 410);
            readimagefile(c[candidato].foto, 850, 170, 1120, 400);
            settextstyle(0, 0, 2);
            setbkcolor(0);
            outtextxy(950,425,c[candidato].nome);
            outtextxy(868,445,c[candidato].seguidores);
        }

        if(ismouseclick(WM_LBUTTONDOWN)&& mousex() > 1000 && mousex() < 1150        //CLICK PARA CONFIRMAR O VOTO
                        && mousey() > 500 && mousey() < 540 && c[candidato].conferir == 1)
        {
                setfillstyle(1,14);
                bar(1000,500,1150,540);
                setlinestyle(0,0,3);
                setcolor(3);
                rectangle(1000,500,1150,540);
                settextstyle(0, 0, 2);
                setbkcolor(14);
                outtextxy(1020,515,confirma);
                delay(300);

                c[candidato].voto++;
                c[candidato].conferir = 0;

                delay(300);
                readimagefile("./img/recorte2.jpg", 805, 150,1165, 499);
                setcolor(2);
                setfillstyle(1,2);
                bar(1000,500,1150,540);
                setlinestyle(0,0,3);
                setcolor(3);
                rectangle(1000,500,1150,540);
                setcolor(0);
                settextstyle(0, 0, 2);
                setbkcolor(2);
                outtextxy(1020,515,confirma);

                clearmouseclick(WM_LBUTTONDOWN);
        }

        if(ismouseclick(WM_LBUTTONDOWN)&& mousex() > 820 && mousex() < 970          //CLICK PARA CANCELAR O VOTO
                        && mousey() > 500 && mousey() < 540 && c[candidato].conferir == 1)
        {
                setfillstyle(1,14);
                bar(820,500,970,540);
                setlinestyle(0,0,3);
                setcolor(4);
                rectangle(820,500,970,540);
                setcolor(0);
                settextstyle(0, 0, 2);
                setbkcolor(14);
                outtextxy(850,515,cancela);
                delay(300);

                c[candidato].conferir=0;

                delay(300);

                readimagefile("./img/recorte2.jpg", 805, 150,1165, 499);

                setfillstyle(1,4);
                bar(820,500,970,540);
                setlinestyle(0,0,3);
                setcolor(3);
                rectangle(820,500,970,540);
                setcolor(0);
                settextstyle(0, 0, 2);
                setbkcolor(4);
                outtextxy(850,515,cancela);

                clearmouseclick(WM_LBUTTONDOWN);
        }
}

void finalizarVotacao()
{

        if(ismouseclick(WM_LBUTTONDOWN) && mousex() > 1200 && mousex() < 1250 //CLICK NO "x"
                                        && mousey() > 30 && mousey() < 75)
        {
            closegraph(primeiraTela);
            setcurrentwindow(segundaTela);
            setbkcolor(15);
            readimagefile("./img/latribonera.jpg",0,0,1280,554);
            settextstyle(0, 0, 4);
            setcolor(0);
            clearmouseclick(WM_LBUTTONDOWN);
            settextstyle(0, 0, 2);


            r[0].voto = c[0].voto;

            for(i=1;i<6;i++) // GAULES CAMPEÃO
            {
                if(r[0].voto > c[i].voto)
                {
                    strcpy(r[0].nome, c[0].nome);
                    strcpy(r[0].foto, c[0].foto);
                    readimagefile(r[0].foto, 510, 40, 780, 240);
                    itoa(r[0].voto, r[0].votoTela, 10);
                }

            }

            for(i=1;i<6;i++) // PRIMEIRO LUGAR
            {
                if(r[0].voto < c[i].voto)
                {
                    r[0].voto = c[i].voto;
                    strcpy(r[0].nome, c[i].nome);
                    strcpy(r[0].foto, c[i].foto);
                    readimagefile("./img/preto.jpg", 517, 47, 788, 248);
                    readimagefile(r[0].foto, 510, 40, 780, 240);
                    itoa(r[0].voto, r[0].votoTela, 10);
                }
            }

            for(i=0;i<6;i++) // SEGUNDO LUGAR
            {
                if(r[0].voto > c[i].voto && c[i].voto > r[1].voto)
                {
                    r[1].voto = c[i].voto;
                    strcpy(r[1].nome, c[i].nome);
                    strcpy(r[1].foto, c[i].foto);
                    itoa(r[1].voto, r[1].votoTela, 10);
                }
            }

            for(i=0;i<6;i++) // TERCEIRO LUGAR
            {
                if(r[1].voto > c[i].voto && c[i].voto > r[2].voto)
                {
                    r[2].voto = c[i].voto;
                    strcpy(r[2].nome, c[i].nome);
                    strcpy(r[2].foto, c[i].foto);
                    itoa(r[2].voto, r[2].votoTela, 10);
                }
            }

            for(i=0;i<6;i++) // QUARTO LUGAR
            {
                if(r[2].voto > c[i].voto && c[i].voto > r[3].voto)
                {

                    r[3].voto = c[i].voto;
                    strcpy(r[3].nome, c[i].nome);
                    strcpy(r[3].foto, c[i].foto);
                    itoa(r[3].voto, r[3].votoTela, 10);
                }
            }

            for(i=0;i<6;i++) // QUINTO LUGAR
            {
                if(r[3].voto > c[i].voto && c[i].voto > r[4].voto)
                {
                    r[4].voto = c[i].voto;
                    strcpy(r[4].nome, c[i].nome);
                    strcpy(r[4].foto, c[i].foto);
                    itoa(r[4].voto, r[4].votoTela, 10);

                }
            }

            for(i=0;i<6;i++) // SEXTO LUGAR
            {
                if(r[4].voto > c[i].voto && c[i].voto > r[5].voto)
                {
                    r[5].voto = c[i].voto;
                    strcpy(r[5].nome, c[i].nome);
                    strcpy(r[5].foto, c[i].foto);
                    itoa(r[5].voto, r[5].votoTela, 10);
                }
            }
        }
        for(i=0;i<6;i++)
        {
            outtextxy(medida[i][0] + ((medida[i][2]-medida[i][0]-(strlen(r[i].nome)*14))/2), medida[i][3]+9, r[i].nome);
            setbkcolor(0);
            setcolor(15);
            outtextxy(medida[i][0] + ((medida[i][2]-medida[i][0]-(strlen(r[i].votoTela)*14))/2), medida[i][3]+30, r[i].votoTela);
            readimagefile(r[i].foto, medida[i][0],medida[i][1],medida[i][2],medida[i][3]);
        }
}

