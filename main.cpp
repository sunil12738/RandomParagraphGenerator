#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
#define total 10000
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
		printf("%d\n", i);
		// scanf("%s",word);
	}

	int total_word_count = i;
	printf("total word count: %d\n", total_word_count);
	printf("Please wait getting the unique word count and doing other important calculations\n");

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
			// printf("%d\n",k);
		}
	}
	int word_length=k-1;

	int unique_word_count = word_length;
	printf("total unique word count: %d\n", unique_word_count);

	//print the sting for testing
	// for(i=0;i<total;++i){
	// 	cout << list[i];
	// 	cout << '\n';
	// }

	// printf("Unique word list\n");
	// for(i=0;i<total;++i){
	// 	cout << unique[i];
	// 	cout << '\n';
	// }

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

	//print the table
	// for(i=0;i<word_length;++i){
	// 	for(j=0;j<word_length;++j){
	// 		printf("%d, \t ", mat[i][j]);
	// 	}
	// 	printf("\n");
	// }

	for(i=0;i<word_length-1;++i){
		printf("%d ", i+1);
		cout << unique[i]+'\n';
	}
	int final_words;
	printf("Enter the number of words in the result: ");
	scanf("%d",&final_words);

	printf("Enter the unique index from which you want to start the paragraph: ");
	int num;
	scanf("%d",&num);
	num=num-1;
	cout << unique[num] + " ";

	//print the paragraph
	string init_word = unique[num];
	int temp=0;
	for(i=0;i<final_words;++i){
		while(1){
			int x = rand()%word_length;
			// printf("%d %d %d\n",x,word_length,num);
			if(num == word_length-1 || num == word_length-2){
				num = rand()%word_length-2;
			}
			if(mat[num][x]==1) {
				num = x;
				cout << unique[num];
				printf(" ");
				++temp;
				break;
			}
			else ;
		}
	}
	return 0;
}
