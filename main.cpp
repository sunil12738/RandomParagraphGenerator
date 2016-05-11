#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
#define total 11
#define null "0"
using namespace std;
int main(){
	int i=0,j=0,k=0;
	string word="";
	string list[total];
	string initial[total];
	//input the string of words
	while(word!="000"){
		cin >> word;
		list[i]=word;
		initial[i]=word;
		++i;
		// scanf("%s",word);
	}

	//get the unique list of words
	string unique[total];
	for(i=0;i<total;++i){
		for(j=i+1;j<total;++j){
			if(list[i]==list[j]){
				list[j]=null;
			}

		}
	}
	k=0;
	for(i=0;i<total;++i){
		if(list[i]==null){}
		else{
			unique[k]=list[i];
			++k;
			printf("%d\n",k);
		}
	}
	int word_length=k-1;

	//print the sting for testing
	for(i=0;i<total;++i){
		cout << list[i];
		cout << '\n';
	}

	printf("Unique word list\n");
	for(i=0;i<total;++i){
		cout << unique[i];
		cout << '\n';
	}

	int mat[word_length][word_length];
	for(i=0;i<word_length;++i){
		for(j=0;j<word_length;++j)
			mat[i][j]=0;
	}
	int top_index=-1,left_index=-1;
	for(i=0;i<total-1;++i){
		j=i+1;
		// printf("%d %d \n",i,j);
		// cout << list[i] + " " + list[j];
		for(k=0;k<word_length;++k){
			if(initial[i]==unique[k]){
				left_index=k;
			}
			if(initial[j]==unique[k]){
				top_index=k;
			}
			// printf("%d %d\n", left_index, top_index );
		}
		mat[left_index][top_index]=1;
	}

	for(i=0;i<word_length;++i){
		for(j=0;j<word_length;++j){
			printf("%d \t ", mat[i][j]);
		}
		printf("\n");
	}

	for(i=0;i<word_length;++i){
		printf("%d ", i+1);
		cout << unique[i]+'\n';
	}
	int num;
	scanf("%d",&num);
	num=num-1;
	cout << unique[num];

	//print the paragraph
	printf("\n");
	string init_word = unique[num];
	for(i=0;i<total;++i){
		while(1){
			int x = rand()%word_length;
			if(mat[num][x]==1) {
				printf("%d\n",x);
				num = x;
				printf("\n");
				cout << unique[num];
				break;
			}
			else ;
		}
	}
	return 0;
}
