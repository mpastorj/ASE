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
     
    cout<<endl<<endl<<"Matriz: NECESIDAD"<<endl<<endl;
         
  }


int NecesidadCubierta(int C[10][10], int N , int procesos, int Disponibles[10]){
    
int i = 0;
int j = 0;
int cont = 0;

 while(cont < N){
           
  for(j = 0 ; j < N ; j++){
        
        if(C[i][j] <= Disponibles[j]){
            cont++;
            }
        }         
           
    if(cont == N){
        return i;    
      }
    else if(i == procesos){
          return 11;        
         } 
      
    cont = 0;
    i++;     
}    
    
return i;    
    
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
       
       cout<<endl<<endl<<"Matriz: ASIGNADOS"<<endl<<endl;
       imprimir(A,N,procesos);
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
       cout<<endl<<endl<<"Matriz: MAXIMOS"<<endl<<endl;
       imprimir(B,N,procesos);
       
       CalcularNecesidad(A,B,C,procesos,N);
       imprimir(C,N,procesos);
       cout<<endl<<endl<<"-> RECURSOS DISPONIBLES: "<<endl;
       for(i=0;i<N;i++){
                               Disponibles[i]=Recursos[i]-SumaA[i];
                               cout<<"\t"<<"R["<<i<<"]: "<<Disponibles[i];
                               }
                               
       cout << NecesidadCubierta(C,N,procesos,Disponibles);
                               
       system("PAUSE");
}
