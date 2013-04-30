#include <stdio.h>
#include <iostream>

using namespace std;


void imprimir(int Matriz[10][10],int N,int procesos){
     int i=0;
     int j=0;
     for(i=0;i<procesos;i++){
                             for(j=0;j<N;j++){
                                         cout<<"\t"<<Matriz[i][j];
                                         }
                                         cout<<endl;
                        }
     }
     
void CalcularNecesidad(int A[10][10],int B[10][10], int C[10][10], int procesos, int N){ 
     
   int i=0;
   int j=0;
     for(i=0;i<procesos;i++){
                             for(j=0;j<N;j++){
                                         
                                         C[i][j] = B[i][j] - A[i][j];
                                         }
                             
                        }
     
   
         
  }


int NecesidadCubierta(int C[10][10], int N , int procesos, int Disponibles[10]){
    
int i = 0;
int j = 0;
int cont = 0;
int cont2 = 10;

 while(cont < N){
           
  for(j = 0 ; j < N ; j++){
        
        if(C[i][j] == 0){
          cont2++;        
           }
        if(C[i][j] <= Disponibles[j]){
            cont++;
            }
        } 
        
     if(cont2 == N+10){
       cont = 0; 
       cont2 = 10;      
     }            
           
    if(cont == N){
        return i;    
      }
    else if(i == procesos && cont2 ==10){
          return 11;        
         } 
    else if(i == procesos){  
          return 12;   
          }
          
    cont = 0;
    i++;     
}    
    
    
    
}

void AsignaNecesidades(int A[10][10], int B[10][10] , int C[10][10] , int i , int N, int Disponibles[10]){
 
int j = 0;
     
  for(j = 0 ; j < N ; j++){
    A[i][j] = B[i][j];
    Disponibles[j] = Disponibles[j] - C[i][j];
    C[i][j] = 0;    
        
        
        }     
}


     
void DevolverRecursos(int A[10][10], int B[10][10], int i , int N, int Disponibles[10]){     

int j ;
     
 for(j=0;j<N;j++){             

                               Disponibles[j] += A[i][j];
                               cout<<"\t"<<"R["<<j<<"]: "<<Disponibles[j];
                               A[i][j] = 0;
                               B[i][j] = 0;
                               }     
}

main(){
       int A[10][10];
       int B[10][10];
       int C[10][10];
       int Recursos[10];
       int SumaA[10];
       int Disponibles[10];
       int suma=0;
       int N=0;
       int procesos=0;
       int i=0;
       int j=0;
       int maximo=0;
       int indice = 0;
       int contador=0;
       int veces=0;
       
       cout<<"Ingrese Cantidad de Procesos: ";
       cin>>procesos;
       
       cout<<"Ingrese Numero de Recursos: ";
       cin>>N;
       
       for(i=0;i<N;i++){
                        cout<<"Ingrese Instancias Totales de R["<<i<<"]:";
                        cin>>Recursos[i];
                        }
       
       cout<<endl<<endl<<"------ Ahora se llenaran las matrices ------"<<endl;
       cout<<endl<<"1) ** RECURSOS ASIGNADOS **"<<endl<<endl;
       
       for(i=0;i<procesos;i++){
                        for(j=0;j<N;j++){
                                         cout<<"Ingrese Recursos asignados de: P["<<i<<"], R["<<j<<"]: ";
                                         cin>>A[i][j];
                                         }
                        }
       for(j=0;j<N;j++){
                        for(i=0;i<procesos;i++){
                                         suma=suma+A[i][j];
                                         }
                                         SumaA[j]=suma;
                                         suma=0;
                                         
                        }
                        

       cout<<endl<<"2) ** RECURSOS MAXIMOS **"<<endl<<endl;
       for(i=0;i<procesos;i++){
                        for(j=0;j<N;j++){
                                         cout<<"Ingrese Recursos maximos de: P["<<i<<"], R["<<j<<"]: ";
                                         cin>>maximo;
                                         if(A[i][j]<=maximo){
                                                            B[i][j]=maximo;
                                                            }
                                         else{
                                              cout<<"El recurso maximo no debe ser menor que el recurso asignado!"<<endl;
                                              j=j-1;
                                              }
                                         }
                        }
       
       cout<<endl<<endl<<"-> RECURSOS DISPONIBLES: "<<endl;
       for(i=0;i<N;i++){
                               Disponibles[i]=Recursos[i]-SumaA[i];
                               cout<<"\t"<<"R["<<i<<"]: "<<Disponibles[i];
                               }
      
       CalcularNecesidad(A,B,C,procesos,N);
                           
       indice = NecesidadCubierta(C,N,procesos,Disponibles);
        
      
        while(indice != 11 && indice != 12)
        {       
       cout<<endl<<endl<<"Matriz: ASIGNADOS"<<endl<<endl;
       imprimir(A,N,procesos);    
                         
       cout<<endl<<endl<<"Matriz: MAXIMOS"<<endl<<endl;
       imprimir(B,N,procesos);
       
       cout<<endl<<endl<<"Matriz: NECESIDAD"<<endl<<endl;
       imprimir(C,N,procesos);
       
       indice = NecesidadCubierta(C,N,procesos,Disponibles);
       
       AsignaNecesidades(A,B,C,indice,N,Disponibles);
       
       DevolverRecursos(A,B,indice,N,Disponibles);
       contador++;
       if(contador<=procesos && indice!=11 && indice!=12){
                             cout<<endl<<"-------------------------------------"<<endl;
                             cout<<endl<<"Se ha seleccionado P["<<indice<<"]"<<endl;
                             veces++;
                             }
       if((indice==11 || indice==12) && veces!=procesos){
                     cout << endl << "****** MEMORIA INSUFICIENTE ********"; 
                     }
       }
       
       cout<<endl<<endl<<endl;           
       system("PAUSE");
}
