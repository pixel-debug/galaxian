#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include "variaveis.h"


GLuint carregaTextura(const char* arquivo) {
  GLuint idTextura = SOIL_load_OGL_texture(
                     arquivo,
                     SOIL_LOAD_AUTO,
                     SOIL_CREATE_NEW_ID,
                     SOIL_FLAG_INVERT_Y
                    );

  if (idTextura == 0) {
    printf("Erro do SOIL: '%s'\n", SOIL_last_result());
  }

  return idTextura;
}

void iniciarJogador(){
  idProta[3] = carregaTextura("imagens/personagens/sheet_protagonista.png");
  idProta[2] = carregaTextura("imagens/personagens/sheet_protagonista1.png");
  idProta[1] = carregaTextura("imagens/personagens/sheet_protagonista2.png");
  idProta[0] = carregaTextura("imagens/personagens/sheet_protagonista3.png");
}

void inicializaVilao(){
  idVilao[0] = carregaTextura("imagens/personagens/sheet_vilao_1.png");
  idVilao[1] = carregaTextura("imagens/personagens/sheet_vilao_2.png");
  idVilao[2] = carregaTextura("imagens/personagens/sheet_vilao_3.png");
  idVilao[3] = carregaTextura("imagens/personagens/sheet_vilao_4.png");
  idVilao[4] = carregaTextura("imagens/personagens/sheet_vilao_5.png");
  idVilao[5] = carregaTextura("imagens/personagens/sheet_vilao_6.png");
  idBoto = carregaTextura("imagens/personagens/sheet_boto.png");
}

void inicializatiro(){
  idtiro1[0] = carregaTextura("imagens/tiro/singaro1.png");
  idtiro1[1] = carregaTextura("imagens/tiro/singaro2.png");
  idtiro1[2] = carregaTextura("imagens/tiro/singaro3ponto1.png");
  idcaixa[0] = carregaTextura("imagens/tiro/singar1.png");
  idcaixa[1] = carregaTextura("imagens/tiro/singar2.png");
  idcaixa[2] = carregaTextura("imagens/tiro/singar3.png");
  idboleto = carregaTextura("imagens/tiro/boleto.png");
  idPensao = carregaTextura("imagens/tiro/pensao.png");
}

void inicializafundos(){
  idFundo1 = carregaTextura("imagens/fundos/primeiraFase.png");
  idmenuzin = carregaTextura("imagens/fundos/dados_de_jogo.png");
  idLose = carregaTextura("imagens/fundos/lose.png");
  idLoseInvertido = carregaTextura("imagens/fundos/loseInvertido.jpeg");
  idCarro = carregaTextura("imagens/fundos/carro.png");
  idCorvo = carregaTextura("imagens/fundos/corvo.png");
  idConfirmacao = carregaTextura("imagens/fundos/confirmacao.png");
  idMenu = carregaTextura("imagens/fundos/menu.png");
  idCreditos = carregaTextura("imagens/fundos/creditos.png");
  idHowtopray = carregaTextura("imagens/fundos/controle.png");
}

void inicializa() {
  glClearColor(1, 0.5, 1, 1);
  glEnable(GL_BLEND );
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,2,4096);
  musicMenu = Mix_LoadMUS("sons/meu_pai_foi_comprar_cigarro.mp3");
  somTiro = Mix_LoadWAV("sons/tosse.wav");
  musicGameOver = Mix_LoadMUS("sons/butter_cup.mp3");
  inicializafundos();
  inicializatiro();
  inicializaVilao();
  iniciarJogador();
}

void menu(int start) {
  if(start == 0){
    // Começa a usar a textura que criamos
    glBindTexture(GL_TEXTURE_2D, idMenu);
    glBegin( GL_QUADS );

      glTexCoord2f(0, 1);
      glVertex3f(-100.0, 100.0, 0.0);

      glTexCoord2f(0, 0);
      glVertex3f(-100.0, -140.0, 0.0);

      glTexCoord2f(1, 0);
      glVertex3f(100.0, -140.0, 0.0);

      glTexCoord2f(1, 1);
      glVertex3f(100.0, 100.0, 0.0);
    glEnd();
    
  }
}
void howtoplai(int howtopray) {
  if(howtopray == 1){
    // Começa a usar a textura que criamos
    glBindTexture(GL_TEXTURE_2D, idHowtopray);
    glBegin( GL_QUADS );

      glTexCoord2f(0, 1);
      glVertex3f(-100.0, 100.0, 0.0);

      glTexCoord2f(0, 0);
      glVertex3f(-100.0, -140.0, 0.0);

      glTexCoord2f(1, 0);
      glVertex3f(100.0, -140.0, 0.0);

      glTexCoord2f(1, 1);
      glVertex3f(100.0, 100.0, 0.0);
    glEnd();
  }
}

void credritos(int creditos){
  if(creditos == 1){
  glBindTexture(GL_TEXTURE_2D, idCreditos);
    glBegin( GL_QUADS );

      glTexCoord2f(0, 1);
      glVertex3f(-100.0, 100.0, 0.0);

      glTexCoord2f(0, 0);
      glVertex3f(-100.0, -140.0, 0.0);

      glTexCoord2f(1, 0);
      glVertex3f(100.0, -140.0, 0.0);

      glTexCoord2f(1, 1);
      glVertex3f(100.0, 100.0, 0.0);
    glEnd();
  }
}


void Background(){

  if(vidas >= 0){        
    glBindTexture(GL_TEXTURE_2D, idFundo1);
                                                 /*---------------------------
                                                     COLOCA O BACKGROUND 
                                                 ----------------------------*/
    glBegin( GL_QUADS );

       glTexCoord2f(0, 1);
       glVertex3f(-100.0, 100.0, 0.0);

       glTexCoord2f(0, 0);
       glVertex3f(-100.0, -100.0, 0.0);

       glTexCoord2f(1, 0);
       glVertex3f(100.0, -100.0, 0.0);

       glTexCoord2f(1, 1);
       glVertex3f(100.0, 100.0, 0.0);


      glEnd();
      
    glBindTexture(GL_TEXTURE_2D, idmenuzin);
                                                 /*-----------------------------------
                                                     COLOCA O BACKGROUNDIZINHO MENU
                                                 -----------------------------------*/
      glBegin( GL_QUADS );

        glTexCoord2f(0, 1);
        glVertex3f(-100, -100, 0.0);

        glTexCoord2f(0, 0);
        glVertex3f(-100, -140, 0.0);

        glTexCoord2f(1, 0);
        glVertex3f(100, -140, 0.0);

        glTexCoord2f(1, 1);
        glVertex3f(100, -100, 0.0);


        glEnd();

    glBindTexture(GL_TEXTURE_2D, idProta[vidas]);
      glBegin( GL_QUADS );

        glTexCoord2f(0.25, 1);
        glVertex3f(-100, -110, 0.0);

        glTexCoord2f(0.25, 1 - alt_cabecc);
        glVertex3f(-100, -130, 0.0);

        glTexCoord2f(0.5, 1 - alt_cabecc);
        glVertex3f(-80, -130, 0.0);

        glTexCoord2f(0.5, 1);
        glVertex3f(-80, -110, 0.0);


      glEnd();


    glBindTexture(GL_TEXTURE_2D, idcaixa[modotiro]);
                                                 /*-----------------------------------
                                                     COLOCA O BACKGROUNDIZINHO MENU
                                                 -----------------------------------*/
      glBegin( GL_QUADS );

        glTexCoord2f(0, 1);
        glVertex3f(65, -110, 0.0);

        glTexCoord2f(0, 0);
        glVertex3f(65, -140, 0.0);

        glTexCoord2f(1, 0);
        glVertex3f(100, -140, 0.0);

        glTexCoord2f(1, 1);
        glVertex3f(100, -110, 0.0);


        glEnd();
    }
}

void loseInvertido(){
  if(vidaBoto <= 0){
    glBindTexture(GL_TEXTURE_2D, idLoseInvertido);
                                                 /*------------------------------------
                                                     COLOCA O BACKGROUND DO GAME 0VER
                                                 --------------------------------------*/
      glBegin( GL_QUADS );

        glTexCoord2f(0, 1);
        glVertex3f(-100.0, 100.0, 0.0);

        glTexCoord2f(0, 0);
        glVertex3f(-100.0, -140.0, 0.0);

        glTexCoord2f(1, 0);
        glVertex3f(100.0, -140.0, 0.0);

        glTexCoord2f(1, 1);
        glVertex3f(100.0, 100.0, 0.0);


      glEnd();
    }
}

void lose(){
  if(vidas <= -1){
    glBindTexture(GL_TEXTURE_2D, idLose);
                                                 /*------------------------------------
                                                     COLOCA O BACKGROUND DO GAME 0VER
                                                 --------------------------------------*/
      glBegin( GL_QUADS );

        glTexCoord2f(0, 1);
        glVertex3f(-100.0, 100.0, 0.0);

        glTexCoord2f(0, 0);
        glVertex3f(-100.0, -140.0, 0.0);

        glTexCoord2f(1, 0);
        glVertex3f(100.0, -140.0, 0.0);

        glTexCoord2f(1, 1);
        glVertex3f(100.0, 100.0, 0.0);


      glEnd();
    }
}

void confirmacao(int i){
  if(i == 1){        
    glBindTexture(GL_TEXTURE_2D, idConfirmacao);
                                                 /*---------------------------
                                                     COLOCA O BACKGROUND 
                                                 ----------------------------*/
      glBegin( GL_QUADS );

        glTexCoord2f(0, 1);
        glVertex3f(-100.0, 100.0, 0.0);

        glTexCoord2f(0, 0);
        glVertex3f(-100.0, -100.0, 0.0);

        glTexCoord2f(1, 0);
        glVertex3f(100.0, -100.0, 0.0);

        glTexCoord2f(1, 1);
        glVertex3f(100.0, 100.0, 0.0);


      glEnd();
      }
}

void Carro(int xcarro, int ycarro){
  glBindTexture(GL_TEXTURE_2D, idCarro);
                                             /*----------------------------------
                                                  LÊ O SPRITE DO BUSAO E O
                                                   MOVIMENTA
                                              -----------------------------------*/
    
    glBegin( GL_POLYGON );
        
      glTexCoord2f(0, 1);
      glVertex3f(xcarro , ycarro, 0.0); //coordenadas iniciais na tela

      glTexCoord2f(0, 0);
      glVertex3f(xcarro, ycarro - alt_carro , 0.0);

      glTexCoord2f(1, 0);
      glVertex3f(xcarro + larg_carro, ycarro - alt_carro, 0.0);

      glTexCoord2f(1 , 1);
      glVertex3f(xcarro + larg_carro, ycarro, 0.0);

    glEnd();
}

void Corvo(float xbate, float ybate){
  glBindTexture(GL_TEXTURE_2D, idCorvo);
                                             /*----------------------------------
                                                  LÊ O SPRITE DO CORVO E O
                                                  FAZ AVOÁ
                                              -----------------------------------*/
    
    glBegin( GL_POLYGON );
        
      glTexCoord2f(xbate, ybate);
      glVertex3f(corvox , corvoy, 0.0); //coordenadas iniciais na tela

      glTexCoord2f(xbate, ybate - alt_larg_corvo);
      glVertex3f(corvox, corvoy - alt_corvo , 0.0);

      glTexCoord2f(xbate + alt_larg_corvo, ybate - alt_larg_corvo);
      glVertex3f(corvox + larg_corvo, corvoy - alt_corvo, 0.0);

      glTexCoord2f(xbate + alt_larg_corvo , ybate);
      glVertex3f(corvox + larg_corvo, corvoy, 0.0);

    glEnd();
}

void Protagonista(float passo, float sentido){
  glBindTexture(GL_TEXTURE_2D, idProta[vidas]);
                                             /*----------------------------------
                                                  LÊ O SPRITE SHEET DO PROTA 
                                                  E DETERMINA QUAL SPRITE DEVE
                                                  SER ACIONADO QUANDO ELE SE 
                                                   MOVIMENTA
                                              -----------------------------------*/
    
    glBegin( GL_POLYGON );
        
      glTexCoord2f(passo, sentido); //coordenadas de corte do sheet
      glVertex3f(protago.x, protago.y, 0.0); //coordenadas iniciais na tela

      glTexCoord2f(passo, sentido - alt_larg_sheet);
      glVertex3f(protago.x ,protago.y - alt_personagens , 0.0);

      glTexCoord2f(passo + alt_larg_sheet, sentido - alt_larg_sheet);
      glVertex3f(protago.x + larg_personagens, protago.y - alt_personagens, 0.0);

      glTexCoord2f(passo + alt_larg_sheet , sentido);
      glVertex3f(protago.x + larg_personagens, protago.y, 0.0);

    glEnd();
}

void geraItem(coordenada item,int modo){
  if(modo == 1)
    glBindTexture(GL_TEXTURE_2D, idcaixa[1]);   //0 para o tiro do inimigo
    if(modo == 2)
      glBindTexture(GL_TEXTURE_2D, idcaixa[2]);  //1 para o tiro do prota
      if(modo == 3)
        glBindTexture(GL_TEXTURE_2D, idboleto);  //1 para o tiro do prota

        glBegin( GL_POLYGON );
            
          glTexCoord2f(0, 1);
          glVertex3f(item.x, item.y, 0.0);
          glTexCoord2f(0, 0);
          glVertex3f(item.x, item.y - 15, 0.0);
          glTexCoord2f(1, 0);
          glVertex3f(item.x + 10, item.y -15, 0.0);
          glTexCoord2f(1, 1);
          glVertex3f(item.x + 10, item.y, 0.0);
        glEnd();
}

void itemPego(coordenada itemn, int item){
                                        /*-------------------------------------------------
                                                    QUANDO ACERTA O HEROI 
                                         -------------------------------------------------*/
  if((itemn.x + 7) >= protago.x && (itemn.x + 7) <= (protago.x + larg_personagens) ){ //hitbox em x e em y, melhores valores
    if((itemn.y + 10) <= protago.y && (itemn.y + 10) >= (protago.y - alt_personagens) ){
      itemglobal.x = -159;
      itemglobal.y = -159;
      if(item == 1){
        modotiro = 1;
        quantidadeDeTiro = 3;
      }
      if(item == 2){
        modotiro = 2;
        quantidadeDeTiro =3;
      }
      if(item == 3){
        if(vidas < 3)
          vidas++;
      }
      
    }
  }
}

int escolheModo (){
  int item = rand()%100;
  if(item <= 9)
    return 1;
  else if(item < 19)
    return 2;
  else if(item < 29)
    return 3;
  else 
    return 0;
}

void item(coordenada vilua, int i){
  itemglobal.y -= 0.06;
  itemglobal.x += (sin(itemglobal.y/6)/10);
  if(sai[i] == 1){
    if(vilua.x == xvilaodefault[i] && vilua.y == yvilaodefault[i] && itemglobal.y <= -159){
      modoitem = escolheModo();
      itemglobal.x = vilua.x;
      itemglobal.y = vilua.y;
      }
    if(modoitem && itemglobal.x >= -95){
      geraItem(itemglobal, modoitem);
      itemPego(itemglobal,modoitem);
    }
  }
}

void viloesAleatorios(){
                                    /*--------------------------------
                                         ALEATORIZAÇÃO DOS VILOES
                                     ----------------------------------*/
  for(int i = 0; i < 16; i++){
    viloes_aleatorios[i] = rand()%6;
  }
    
}
void vilao(coordenada posicao, int abssissa, int ordenada, int i){
                                     /*--------------------------------
                                          LÊ O SPRITE SHEET DOS VILÕES
                                          E DETERMINA QUAL SPRITE DEVE
                                          SER ACIONADO QUANDO ELE SE 
                                          MOVIMENTA 
                                     ----------------------------------*/
    

  if(atingiu[i]){ // parametro de atingiu na posição x, 1 desenha e 0 some
    glBindTexture(GL_TEXTURE_2D, idVilao[viloes_aleatorios[i]]);
      glBegin( GL_POLYGON );        
        glTexCoord2f(xpasso_vilao[abssissa] ,ysentido_vilao[ordenada] ); 
        glVertex3f( posicao.x, posicao.y, 0.0);
        glTexCoord2f(xpasso_vilao[abssissa],ysentido_vilao[ordenada] - alt_larg_sheet);
        glVertex3f(posicao.x, posicao.y - alt_personagens , 0.0);
        glTexCoord2f(xpasso_vilao[abssissa] + alt_larg_sheet, ysentido_vilao[ordenada] - alt_larg_sheet);
        glVertex3f(posicao.x + larg_personagens, posicao.y - alt_personagens, 0.0);
        glTexCoord2f(xpasso_vilao[abssissa] + alt_larg_sheet, ysentido_vilao[ordenada]);
        glVertex3f(posicao.x + larg_personagens, posicao.y, 0.0);
      glEnd();
      
   }
}

void andaHorizontal(int key, int direcao){
                                 /*----------------------------------------
                                     FAZ O PROTAGONISTA ANDAR PELO EIXO X
                                     QUANDO A TECLA É ACIONADA, POSSIBILITANDO
                                     A ANIMAÇÃO
                                  -----------------------------------------*/
  sentido = direcao;

  if(key == 1 && protago.x + larg_personagens < 100)
    protago.x+=2;   //velocidade do protagonista a direita, limitando até a posição 100
  else if (protago.x > -100 && key == 0)
    protago.x-=2; //velocidade do protagonista a esquerda, limitando até a posição -100
  if(controle_velocidade_prota % 5 == 0){
    if (passo >= 3)  //limitar
      passo = 0;
    else
      passo++;
  }
  controle_velocidade_prota++;
}

void andaVilao(coordenada posicao, int i, int lado){
  if(controle_velocidade_vilao % 5 == 0){
    if(passo_vilao[i] == 3)
      passo_vilao[i] = 0;
    else
      passo_vilao[i] ++;
    }
   if (lado == 0){
     sentido_vilao[i] = 0;
     posicao.x += 2 ;
   }
   else if(lado == 1){
    sentido_vilao[i] = 1;
    posicao.x-= 2 ;
   }
   else if(lado == 2){
    sentido_vilao[i] = 2;
    posicao.x -= 2 ;
    }
   if(lado == 3){
    sentido_vilao[i] = 3;
    posicao.x += 2 ;
    }
   controle_velocidade_vilao++;
}

void atira(int xtiro, int ytiro, int shape){
                             /*-------------------------------------------------
                                LÊ O SPRITE DO TIRO E DETERMINA SUA TRAGETÓRIA
                              -------------------------------------------------*/
  if(shape){
    glBindTexture(GL_TEXTURE_2D, idtiro1[modotiro]);  //1 para o tiro do prota
    if(modotiro == 2){
      glBegin( GL_POLYGON );
      if(ladotiro == 0){
        glTexCoord2f(0, 1);
        glVertex3f(xtiro + 10, ytiro, 0.0);
        glTexCoord2f(0, 0);
        glVertex3f(xtiro + 10, ytiro - 15, 0.0);
        glTexCoord2f(0.5, 0);
        glVertex3f(xtiro, ytiro -15, 0.0);
        glTexCoord2f(0.5, 1);
        glVertex3f(xtiro, ytiro, 0.0);
      }
      else if(ladotiro == 1){
        glTexCoord2f(1, 1);
        glVertex3f(xtiro + 10, ytiro, 0.0);
        glTexCoord2f(0.5, 1);
        glVertex3f(xtiro + 10, ytiro - 15, 0.0);
        glTexCoord2f(0.5, 0);
        glVertex3f(xtiro, ytiro -15, 0.0);
        glTexCoord2f(1, 0);
        glVertex3f(xtiro, ytiro, 0.0);
      }      
     else{
        glTexCoord2f(0.5, 0);
        glVertex3f(xtiro + 10, ytiro, 0.0);
        glTexCoord2f(1, 0);
        glVertex3f(xtiro + 10, ytiro - 15, 0.0);
        glTexCoord2f(1, 1);
        glVertex3f(xtiro, ytiro -15, 0.0);
        glTexCoord2f(0.5, 1);
        glVertex3f(xtiro, ytiro, 0.0);
      }
      glEnd();
      }
    }
    else
      glBindTexture(GL_TEXTURE_2D, idPensao);   //0 para o tiro do inimigo

    if(modotiro != 2 || shape == 0){
      glBegin( GL_POLYGON );
            
        glTexCoord2f(0, 1);
        glVertex3f(xtiro + 10, ytiro, 0.0);
        glTexCoord2f(0, 0);
        glVertex3f(xtiro + 10, ytiro - 15, 0.0);
        glTexCoord2f(1, 0);
        glVertex3f(xtiro, ytiro -15, 0.0);
        glTexCoord2f(1, 1);
        glVertex3f(xtiro, ytiro, 0.0);
      glEnd();
    }
}

void singaro(int key){ 
  if(xtiroProta >= 100 || xtiroProta <= -120 || ytiroProta >= 90){
    ytiroProta = 120;
    ladotiro = 0;
  }  
                                         /*-------------------------------------------------
                                            QUANDO ACIONADA A BARRA DE ESPAÇO O TIRO VAI
                                            SAIR DE ONDE O PROTAGONISTA ESTÁ
                                         -------------------------------------------------*/
 if(key && ladotiro == 1)
  xtiroProta-= 4;

 else if(key && ladotiro == 2)
  xtiroProta+= 4;

 else if(key && ytiroProta<=100)  //key funciona como booleano
  ytiroProta+= 4;         //velocidade


  atira(xtiroProta ,ytiroProta,1); //coordenas do tiro do prota, shape  
}

void pensaoPaga(int xpensao, float ypensao, int i){
  if((xpensao + 7) >= xcarro && (xpensao + 7) <= (xcarro + larg_carro) ){ //hitbox em x e em y, melhores valores
    if((ypensao + 10) <= ycarro && (ypensao + 10) >= (ycarro - alt_carro) ){
      xtiroVilao[i] = 140; //faz o tiro sumir quando acerta
      ytiroVilao[i] = -150;
    }
  }
                                        /*-------------------------------------------------
                                                    QUANDO ACERTA O HEROI 
                                         -------------------------------------------------*/
  if((xpensao + 7) >= protago.x && (xpensao + 7) <= (protago.x + larg_personagens) ){ //hitbox em x e em y, melhores valores
    if((ypensao + 10) <= protago.y && (ypensao + 10) >= (protago.y - alt_personagens) ){
      vidas--;
      xtiroVilao[i] = 140; //faz o tiro sumir quando acerta
      ytiroVilao[i] = -150;
    }
  }
}

void pensao (coordenada vilua, int i){
                                        /*-------------------------------------------------
                                            AQUI DETERMINA A TRAJETORIA DO TIRO DOS VILÕES 
                                         -------------------------------------------------*/
  ytiroVilao[0]-= 0.15; //velocidade de queda
  ytiroVilao[1]-= 0.15;
  ytiroVilao[2]-= 0.15;
  int segundotiro = rand()%16;
  int terceirotiro = rand()%16;
  if(sai[i] == 0){ //não atirar depois de morto
    if(protago.x >= vilua.x && protago.x <= (vilua.x + larg_personagens) && ytiroVilao[0] <= -95 ){ //protagonista em baixo do vilao
                                                                                               // quando atingir o chão, reinicia o tiro
      xtiroVilao[0] = vilua.x;       //posição do tiro inicial do tiro que segue                 // que segue
      ytiroVilao[0] = vilua.y;
    }

    if(xvilao[segundotiro] != xtiroVilao[0] && ytiroVilao[1] <= -95 && sai[segundotiro] == 0){  //não deixa atirar duas vezes ao mesmo tempo
      xtiroVilao[1] = xvilao[segundotiro];                    // são tiros aleatorios
      ytiroVilao[1] = yvilao[segundotiro];
    }
    if(xvilao[terceirotiro] != xtiroVilao[0] && xvilao[terceirotiro] != xtiroVilao[1] && ytiroVilao[2] <= -95 && sai[terceirotiro] == 0){
      xtiroVilao[2] = xvilao[terceirotiro];                   // são tiros aleatorios
      ytiroVilao[2] = yvilao[terceirotiro];
    }
  }
  atira(xtiroVilao[0], ytiroVilao[0], 0);
  atira(xtiroVilao[1], ytiroVilao[1], 0);
  atira(xtiroVilao[2], ytiroVilao[2], 0);
  pensaoPaga(xtiroVilao[0], ytiroVilao[0], 0);
  pensaoPaga(xtiroVilao[1], ytiroVilao[1], 1);
  pensaoPaga(xtiroVilao[2], ytiroVilao[2], 2);
}

void SaiDaTela(int i,coordenada vilua){
                                        /*-------------------------------------------------
                                            QUANDO ATINGIDO, O VILÃO IRÁ RETORNAR PARA O 
                                            CANTO SUPERIOR ESQUERDO DA TELA
                                         -------------------------------------------------*/
  if(sai[i]){ //assume 1 quando o vilão é atingido
    if(vilua.x >= 0){        //anda até o meio 
      xvilao[i]--;
      andaVilao(vilua, i, 1);
    }
    else if(vilua.y <= 80){
      yvilao[i]++;            //vai até a calçada
      andaVilao(vilua, i, 2);
    }
    else if(vilua.x >= -120){
      xvilao[i]--;             // sai da tela
      andaVilao(vilua, i, 1);
    }
    else{
      atingiu[i] = 0;         //some
      andaVilao(vilua, i, 4);
    }
  }
}

//modotiro =1 hollywood
//2 malboro

void impacto(int i, coordenada posicao){
  if(xtiroProta+5 >= xcarro && xtiroProta+5 <= (xcarro + larg_carro) ){
    if(ytiroProta+10 >= ycarro && ytiroProta+10 <= ycarro+alt_carro )
      ytiroProta = 110;
  }
                                        /*----------------------------------------------------
                                            VÊ SE O TIRO ACERTOU O TAL INIMIGO OU NÃO
                                         ----------------------------------------------------*/
  if(sai[i] == 0){ // impede que o tiro trave
    if(xtiroProta+5 >= posicao.x && xtiroProta + 5 <= (posicao.x  + larg_personagens)){ //intervalo de x
      if(ytiroProta >= posicao.y-10 && ytiroProta <= (posicao.y + alt_personagens)-10 && ytiroProta != 104){ // intervalo de y
        sai[i] = 1;
        if(modotiro != 1)
          ytiroProta = 110;                // valor pra y fora da margem de erro
      }
    }
  pontos++;
  }

  SaiDaTela(i, posicao);
}

void rage(int i, coordenada vilua){
                                        /*---------------------------------------------------------
                                            FAZ O BICHINHO INIMIGO FICAR DOIDÃO. IMAGINA QUE 
                                            VOCÊ É O BATMAN, BATEU EM 29 DOS 30 INIMGOS, O ÚLTIMO
                                            QUE SOBRA ACHA QUE PODE CONTIGO E FICA LOUCAO, RUSHANDO
                                            E TE PROCURANDO. FICANDO FORA DE POSIÇÃO
                                         ---------------------------------------------------------*/
  if(contador_de_viloes == 1 && sai[i] == 0){ //se sobrar um vilão e ele não foi atingido
    if(modo == 1){                          // qual direção e sentido ele vai
      if(vilua.y >= 80)                   // limita atè onde vai
        modo = (rand()%3)+2;            // sorteia próxima direção impedindo que seja 1 novamente
        yvilao[i] += 2;                     // ele vai pra cima, o 2 é velocidade
        andaVilao(vilua, i, 2);
    }
    else if(modo == 2){
      if(vilua.x <= -90 && vilua.y <80)   //liimita até onde vai
        modo = (rand()%4)+1;            
      else if(vilua.x <= -90)              //impede que vá mais pra direita, em cima dos prédios
        modo = (rand()%2)+3;
        xvilao[i] -= 2;                     //vai para a esquerda
        andaVilao(vilua, i, 1);
    }
    else if(modo == 3){
      if(vilua.y <= 30 && vilua.y < 80)
        modo = (rand()%4)+1;            
      else if (vilua.y <= 30)                 //impede que vá pra cima dos prédios
        modo = (rand()%3)+2;
        yvilao[i] -= 2;                         //vai pra baixo
        andaVilao(vilua, i, 3);
    }
    else if(modo == 4){
      if(vilua.x >= 70 && vilua.y <80)
        modo = (rand()%3)+1;
      else if(vilua.x >= 70)                 // não vá para os prédios
        modo = (rand()%3)+2;
        xvilao[i] += 2;                         // vai ṕara direita
        andaVilao(vilua, i, 0);
    }
  }
}

void andaCarro(){

  if(inicializacao == 0){
    if(xcarro >= -250 ){
       xcarro += 1;
    }
    if(xcarro == 400){
      xcarro = -250;        
    }
  }      
  else{
    if(xcarro <= 0){
      xcarro +=1;
      for(int i = 8; i<16; i++){
        xvilao[i] = xcarro+3;
        yvilao[i] = ycarro-i+8;
      }
    }
    else
      carroinicial = 1;
  }

Carro(xcarro, ycarro);
}

void cenaInicial(coordenada vilua, int i){
  int D = i+1;
    if(8==D || D <8){
      if(vilua.x > xvilaodefault[i]){
        xvilao[i]-=1;
        andaVilao(vilua, i, 1);
      }
      else if(vilua.y > yvilaodefault[i]){
        yvilao[i]-=1;
        andaVilao(vilua, i, 3);
      }
      else{
        sentido_vilao[i]=3;
        passo_vilao[i]= 0;
        if(EmPosicao[i] == 0)
          inicializacao--;
        EmPosicao[i]=1;
      }
      
    }
    else if(carroinicial){
        if(vilua.y < 30){
          yvilao[i]++;
          andaVilao(vilua, i, 2);
        }
        else if(xvilaodefault[i] > 0 && vilua.x < xvilaodefault[i]){
          xvilao[i]++;
          andaVilao(vilua, i, 0);
        }
        else if(xvilaodefault[i] < 0 && vilua.x > xvilaodefault[i]){
          xvilao[i]--;
          andaVilao(vilua, i, 1);
        }
        else{
        sentido_vilao[i]=3;
        passo_vilao[i]= 0;
        if(EmPosicao[i] == 0)
          inicializacao--;
        EmPosicao[i] =1;
      }
        
    }
  vilao(vilua, passo_vilao[i] , sentido_vilao[i], i );
}


void vilao_impacto(){
                                        /*-------------------------------------------------
                                            AQUI, FAZE-SE A ATRIBUIÇÃO DAS COORDENADAS,
                                            CONFIRMA SE TEVE IMPACTO AO CHAMAR A FUNÇÃO 
                                            IMPACTO E, SE TIVER, CHAMA A VILÃO COM O VALOR
                                            DO IMPACTO PARA DESENHA-LO OU PEDIR GENTILMENTE
                                            QUE SE RETIRE PELO CANTO SUPERIOR ESQUERDO
                                         -------------------------------------------------*/
  int num_de_viloes = 0;
  coordenada vilua[16];
  for(int i = 0; i < 16; i++){  // posição dos vilões
    vilua[i].x = xvilao[i];
    vilua[i].y = yvilao[i];
  }
  for(int i = 0; i<16; i++){ //quantos vilões vivos ainda temos
    if(sai[i] == 0){  // não levou tiro ainda
      num_de_viloes++;
    }
  }
  contador_de_viloes = num_de_viloes; //quanto tiver apenas 1 = rage

  for (int i = 0; i < 16; ++i){   //faz a chamada dessas funções para cada personagem
    if(inicializacao == 0){
      rage(i, vilua[i]);
      impacto(i, vilua[i]);
      vilao(vilua[i], passo_vilao[i] , sentido_vilao[i], i );
      pensao(vilua[i] , i);
      item(vilua[i], i);
    }
    else{
      cenaInicial(vilua[i],i);  
    }
  }
}

void VoaCorvo(){
  if(controle_velocidade_corvo % 7 == 0){
    if(xbate == 3)
      xbate = 0;
    else 
      xbate ++;
     }
     controle_velocidade_corvo++;
 
    if(corvox <= 95){
        corvox -= 1;
    }
    if(corvox == -500){
      corvox = 95;
    }
  Corvo(xasa[xbate], yasa[ybate]);
}
void reinicia(){
                                        /*-------------------------------------------------
                                            REINICIA O JOGO QUANDO ACIONADA A TELA 'R'
                                            COM OS VALORES DEFINIDOS LÁ EM RIBA COMO DEFAULT
                                         -------------------------------------------------*/             
    
  for (int i = 0; i < 16; ++i){
    xvilao[i] = xvilaodefault[i];
    yvilao[i] = yvilaodefault[i];

    sai[i] = 0;

    atingiu[i] = 1;

    passo_vilao[i] = 0;
    sentido_vilao[i] = 3;
  }

  xtiroVilao[0] = 140;
  ytiroVilao[0] = -100;
  xtiroVilao[1] = 140;
  ytiroVilao[1] = -100;
  xtiroVilao[2] = 140;
  ytiroVilao[2] = -100;
  vidas = 3;

  tiro= 0;
  xtiroProta = 150;
  ytiroProta = -80;

  passo = 1;
  sentido = 0; 
 
  protago.x = 0;
  protago.y = -76;

  xcarro = -250;
  corvox = 95;
}

void desenhaBoto(coordenada posicao, coordenada sheet){
  glBindTexture(GL_TEXTURE_2D, idBoto);
    glBegin( GL_POLYGON );           
      glTexCoord2f(sheet.x,sheet.y);
      glVertex3f(posicao.x,posicao.y,0); 
      glTexCoord2f(sheet.x + alt_larg_sheet,sheet.y);
      glVertex3f(posicao.x + dimensoesBoto.x , posicao.y,0);
      glTexCoord2f(sheet.x + alt_larg_sheet,sheet.y - alt_larg_sheet);
      glVertex3f(posicao.x + dimensoesBoto.x , posicao.y - dimensoesBoto.y ,0);
      glTexCoord2f(sheet.x,sheet.y - alt_larg_sheet);
      glVertex3f(posicao.x, posicao.y - dimensoesBoto.y ,0);
    glEnd();
}            

coordenada andaBoto(coordenada posicao,int modo){ //1 pra esqueda,2 pra cima ,3 pra baixo, 0 pra direita
  controle++;
  if(controle%5 == 0){
    passoBoto++;
    if(passoBoto > 3)
      passoBoto = 0;
  }

  float sentido[4] = {0,0.25,0.5,0.75};
  float direcao[4] = {0.25,0.5,0.75,1};
  coordenada aux;
  aux.y = direcao[modo];
  aux.x = sentido[passoBoto];
  return aux;  
}

void botoSaiDaTela(){
  if(posicaoBoto.x >= 0){        //anda até o meio 
    posicaoBoto.x--;
    sheet = andaBoto(posicaoBoto, 1);            
  }
  else if(posicaoBoto.y <= 80){
    posicaoBoto.y++;            //vai até a calçada
    sheet = andaBoto(posicaoBoto, 2);
  }
  else if(posicaoBoto.x >= -120){
    posicaoBoto.x--;             // sai da tela
    sheet = andaBoto(posicaoBoto, 1);
  }
}

int botoVolta(){
  if(posicaoBoto.x <= 0){
    posicaoBoto.x++;             // volta da tela
    sheet = andaBoto(posicaoBoto, 0);
  }
  else if(posicaoBoto.y >= 60){
    posicaoBoto.y--;            //sai da calçada
    sheet = andaBoto(posicaoBoto, 3);
  }
  else 
    return 1;
  return 0;
}

void rageBoto(coordenada posicao){
  if(modo == 1){                          // qual direção e sentido ele vai
    if(posicao.y >= 80)                   // limita atè onde vai
      modo = (rand()%3)+2;            // sorteia próxima direção impedindo que seja 1 novamente
      posicaoBoto.y += 2;                     // ele vai pra cima, o 2 é velocidade
      sheet = andaBoto(posicao, 2);
    }
    else if(modo == 2){
      if(posicao.x <= -90 && posicao.y <80)   //liimita até onde vai
        modo = (rand()%4)+1;
      else if(posicao.x <= -90)              //impede que vá mais pra direita, em cima dos prédios
        modo = (rand()%2)+3;
        posicaoBoto.x -= 2;                     //vai para a esquerda    
        sheet = andaBoto(posicao, 1);
    }
    else if(modo == 3){
      if(posicao.y <= 30 && posicao.y < 80)
        modo = (rand()%4)+1;    
      else if (posicao.y <= 30)                 //impede que vá pra cima dos prédios
        modo = (rand()%3)+2;
        posicaoBoto.y -= 2;                         //vai pra baixo
            
        sheet = andaBoto(posicao, 3);
    }
    else if(modo == 4){
      if(posicao.x >= 70 && posicao.y <80)
        modo = (rand()%3)+1;       
      else if(posicao.x >= 70)                 // não vá para os prédios
        modo = (rand()%3)+2;
        posicaoBoto.x += 2;                         // vai ṕara direita
            
        sheet = andaBoto(posicao, 0);
    }
}

void pensaoBoto(coordenada vilua){
  if(protago.x >= vilua.x && protago.x <= (vilua.x + larg_personagens) && ytiroVilao[0] <= -95 ){ //protagonista em baixo do vilao
                                                                                                        // quando atingir o chão, reinicia o tiro
    xtiroVilao[0] = vilua.x;       //posição do tiro inicial do tiro que segue                 // que segue
    ytiroVilao[0] = vilua.y;
  }
  if( ytiroVilao[1] <= -95 ){  //não deixa atirar duas vezes ao mesmo tempo
    xtiroVilao[1] = vilua.x;                    // são tiros aleatorios
    ytiroVilao[1] = vilua.y;
  }
  if(ytiroVilao[2] <= -95){
    xtiroVilao[2] = vilua.x;                   // são tiros aleatorios
    ytiroVilao[2] = vilua.y;
  }
}

void impactoBoto(coordenada posicao){
  if(xtiroProta+5 >= posicao.x && xtiroProta + 5 <= (posicao.x  + larg_personagens)){ //intervalo de x
    if(ytiroProta >= posicao.y-10 && ytiroProta <= (posicao.y + alt_personagens)-10 && ytiroProta != 104){ // intervalo de y
      vidaBoto--;
      ytiroProta = 110;
    }
  }
}

void vemBoto(){
  modotiro = 2;
  desenhaBoto(posicaoBoto,sheet);
  rageBoto(posicaoBoto);
  //botoVolta();
  pensaoBoto(posicaoBoto);
  impactoBoto(posicaoBoto);
  }


void pause(){
  if(pausar)
    pausar = 0;
  else
    pausar = 1;
}



void desenha() {
  //inicializacao = 0;
  Background();
   if(pausar){
     vilao_impacto();
     andaCarro();
      
    if(inicializacao != 0){
     desenhaBoto(posicaoBoto,sheet);
     botoSaiDaTela();
    } 
    if(inicializacao == 0){
      VoaCorvo();
      singaro(tiro);
      Protagonista(xpasso[passo], ysentido[sentido]);
      lose();
    }
    if(contador_de_viloes == 0 && vidaBoto > 0)
      vemBoto();
  }
  loseInvertido();
}

void redimensiona(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-100, 100, -140, 100, -1.0, 1.0);
  glMatrixMode(GL_MODELVIEW);
}

void teclasLenvatadas(unsigned char key, int x, int y){
  switch (key){
    case 32:
      quantidadeDeTiro--;
      if(quantidadeDeTiro == 0)
        modotiro = 0;
        break;
  }
}

void teclas(int key, int x, int y){
  if(key == GLUT_KEY_RIGHT){
    andaHorizontal(1, 2);
  }
  if(key == GLUT_KEY_LEFT){
    andaHorizontal(0, 1);
  }
  if(key == GLUT_KEY_UP){
    passo = 1;
    sentido = 0;
  }
  if(key == GLUT_KEY_DOWN){
    passo = 1;
    sentido = 3;
  }
}

void mouse(int button, int state, int x, int y){
                                /*----------------------------------------------
                                   AQUI IRÁ TRATAR OS EVENTOS DO MOUSE PARA
                                  O MENU PRINCIPAL E MENSAGENS DE CONFIRMAÇÃO
                                    (REINICIAR E SAIR)
                                -----------------------------------------------*/
  if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
    posicaoMouse.x = x;
    posicaoMouse.y=y;
    if(posicaoMouse.x >= 667 && posicaoMouse.x <= 801 && posicaoMouse.y >= 386 && posicaoMouse.y <= 435){ // botão começar
      start = 1; //ligado           
    }
    if(posicaoMouse.x >= 671 && posicaoMouse.x <= 800 && posicaoMouse.y >= 550 && posicaoMouse.y <= 610){ // botão dos créditos
      creditos = 1; //ligado        
    }
    if(posicaoMouse.x >= 661 && posicaoMouse.x <= 814 && posicaoMouse.y >= 463 && posicaoMouse.y <= 522){ // botão dos créditos
      howtopray = 1; //ligado         
    }
    if(posicaoMouse.x >= 7 && posicaoMouse.x <= 137 && posicaoMouse.y >= 13 && posicaoMouse.y <= 78){ 
      volta += 1; //volta uma página     
    }
    if(posicaoMouse.x >= 240 && posicaoMouse.x <= 280 && posicaoMouse.y >= 248 && posicaoMouse.y <= 300){ 
      clique_sim = 1; //confirmacao SIM     
    }
    if(posicaoMouse.x >= 430 && posicaoMouse.x <= 470 && posicaoMouse.y >= 248 && posicaoMouse.y <= 300){ 
      clique_nao = 1; //confirmacao SIM     
    }  
  }
}

void getOUT(){
  if(saida %2 == 0){
    confirmacao(1);
    if(clique_sim == 1){
      exit(0);
    }
      if(clique_nao == 1){
        saida = 1;
        clique_nao = 0;
        pause();
      }
  }
  if(saida == 1){
    confirmacao(0);
  }
}

void refressh(){
  if(refresh %2 == 0){
    confirmacao(1);
    if(clique_sim == 1){
      reinicia();
      pause();
      clique_sim = 0;
      refresh = 1;
    }
    if(clique_nao == 1){
      refresh = 1;
      pause();
    }
  }
  if(refresh == 1){
    confirmacao(0);
    clique_nao = 0;
    clique_sim = 0;
  }
}

void teclado(unsigned char key, int x, int y) {
  switch (key) {
  case 'a':
    if(modotiro == 2)
      ladotiro = 1;
      break;
  case 'd':
    if(modotiro == 2)
      ladotiro = 2;
      break;
  case 27:
    pause();
    saida += 1;
    break;
  case 'r':
    pause();
    refresh +=1;
    break;
  case 'p':
    pause();
    break;
  case 32:   //espaço
    passo = 2;        //coordenadas do sheet
    sentido = 0; 
    if(ytiroProta >= 100 || ytiroProta == -80){    // primeiro e segundo tiro iniciais
      xtiroProta = protago.x;
      ytiroProta= -80;
      tiro = 0;
      ladotiro = 0;
    }
    tiro = 1;
    modo = (rand()%4)+1;
    //mod = (rand()%4)+1;        
    break;
  }
}

void atualiza() {
  glutPostRedisplay();
}

void soltaOSom(int start){
  if(start != 1  && !Mix_PlayingMusic()){
    Mix_PlayMusic(musicMenu, -1);
  }
  if(vidas <= -1 && start ==1 && !Mix_PlayingMusic()){
    Mix_PlayMusic(musicGameOver, -1);
  }
  /*
  ESSE DAQUI É O BARRULHO QUANDO O VILÃO É ATINGIDO
Mix_PlayChannel(-1, somTiro,0);
Mix_VolumeChunk(somTiro, 96);
*/
}
void jogo(){
  glClear(GL_COLOR_BUFFER_BIT);
  glEnable(GL_TEXTURE_2D);
  
  menu(start);
  
  soltaOSom(start);
    
  if(start == 1){
    desenha();
    getOUT();
    refressh();
    volta = 3;
    creditos = 2;
    howtopray = 2;
  }
 
  credritos(creditos);    
  howtoplai(howtopray);
  if(volta %2 == 0){
    start = 0;
    creditos = 0;
    howtopray = 0;
    volta = 1;
  }
  glDisable(GL_TEXTURE_2D);
  glutSwapBuffers();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  SDL_Init(SDL_INIT_AUDIO);
  Mix_Init(MIX_INIT_MP3);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(900, 700);
  glutInitWindowPosition(1000, 1000);
  srand(time(0));
  glutCreateWindow("Where's my Pai");
  glutReshapeFunc(redimensiona);
  glutKeyboardFunc(teclado);
  glutIdleFunc(atualiza);
  glutSpecialFunc(teclas);
  glutKeyboardUpFunc(teclasLenvatadas);
  glutMouseFunc(mouse);
  glutDisplayFunc(jogo);
  viloesAleatorios();
  inicializa();
  glutMainLoop();
  return 0;
}