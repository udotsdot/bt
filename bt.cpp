#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;


struct data{
	int number;

	data *left, *right;
}*root;


void push(data **current, int number){
	
	if((*current)==NULL){
		(*current) = (struct data *)malloc(sizeof(data));
		
		(*current)->number=number;
		(*current)->left = (*current)->right = NULL;
	 	
	}else if(number < (*current)->number){
		push(&(*current)->left, number);
	
	}else if(number >= (*current)->number){
		push(&(*current)->right, number);
	}
}


void preOrder(data **current){
	if((*current)!=NULL){
		printf("%d -> ", (*current)->number);
		preOrder(&(*current)->left);
		preOrder(&(*current)->right);
	}
}


void inOrder(data **current){
	if((*current)!=NULL){
		inOrder(&(*current)->left);
		printf("%d -> ", (*current)->number);
		inOrder(&(*current)->right);
	}
}


void postOrder(data **current){
	if((*current)!=NULL){
		postOrder(&(*current)->left);
		postOrder(&(*current)->right);
		printf("%d -> ", (*current)->number);
	}
}


void search(data **current, int number){

	if((*current)!=NULL){
	
		if(number<(*current)->number){
			search(&(*current)->left,number);
	
		}else if(number>(*current)->number){
			search(&(*current)->right,number);
	
		}else{
			printf("Found : %d\n", (*current)->number);
		}

	}else{
		printf("Not Found.\n");
	}
}

int main(){

	int input,cari,perulangan,menu,n;
do{
	cout<<"		Menu		"<<endl;
	cout<<"1.Tambah data"<<endl;
	cout<<"2.Pre order"<<endl;
	cout<<"3.In order"<<endl;
	cout<<"4.Post order"<<endl;	
	cout<<"5.Cari data"<<endl;	
	cin>>menu;
	if(menu==1){
	cout<<"Jumlah data = ";
	cin>>n;
	for(int j=1;j<=n;j++){
	cout<<"Masukan Nilai "<<j<<" = ";
	cin>>input;
	push(&root,input);;
}
}
if(menu==2){
	preOrder(&root);
	cout<<("\n");
}
if(menu==3){
	inOrder(&root);
	cout<<("\n");}
if(menu==4){
	postOrder(&root);
	cout<<("\n");;}
if(menu==5){
	cout<<"Data yang ingin dicari = ";
	cin>>cari;
	search(&root,cari);}

cout<<"Kembali ke menu?(1)";
cin>>perulangan;
system("cls");}
while(perulangan==1);


return 0;}
