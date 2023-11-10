#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<sys/time.h>
#include<conio.h>
int size,i;
int capacity;
int profit[10],weight[10],selected[10];
clock_t t;


//BRUTEFORCE ALGORITHM
int bruteforce(int weight[],int profit[],int capacity,int size)
{

	printf("\nBRUTE FORCE ALGORITHM");
	int i,j,isSelected=1,maxWt,maxProfit;
	int iter=pow(2.0,size);
	int result=0;
	int temp[size];

	for(i =0;i<size;i++)
		temp[i]=0;

	for(i=0;i<iter;i++) {
		isSelected=1;
		maxProfit=0;
		maxWt=0;

		for(j=0;j<size;j++)
		{
			if(temp[j]==1)
			{
				maxWt+=weight[j];
				maxProfit+= profit[j];
			}
		}
		if( maxWt <= capacity && maxProfit>result)
		{
			/*Copies the selected item in array. */
			for(j=0;j<size;j++)
				selected[j]=temp[j];
			result=maxProfit;
		}

		/*Calculate the next subset */
		for(j=0;j<size;j++)
		{
			temp[j]=temp[j]+isSelected;
			isSelected = temp[j]/2;
			temp[j]=temp[j]%2;
		}
	}

	return result;




}



//GREEDY ALGORITHM 2
int greedy2(int weight[],int profit[],int capacity,int size)
{
	printf("\nGREEDY ALGORITHM");
	int i,j,temp;
	int result=0,greedyCap=capacity;
	int tempArr[size],tempWt[size],tempProfit[size];
	float val1,val2;

	for(i=0;i<size;i++) {
		tempArr[i]=i;
		tempWt[i]=weight[i];
		tempProfit[i]=profit[i];
		selected[i]=0;
	}

	for(i=0;i<size;i++) {
		for(j=0;j<size - i-1;j++) {
			val1 = ((float)tempProfit[j]/ (float)tempWt[j]);
			val2 = ((float)tempProfit[j+1]/(float) tempWt[j+1]);
			if( val1 < val2 ){
				//swap profit
				temp=tempProfit[j];
				tempProfit[j]=tempProfit[j+1];
				tempProfit[j+1]=temp;
				//swap weights
				temp=tempWt[j];
				tempWt[j]=tempWt[j+1];
				tempWt[j+1]=temp;
				//swap item number as well
				temp=tempArr[j];
				tempArr[j]=tempArr[j+1];
				tempArr[j+1]=temp;
			}
		}
	}

	for(i=0;i<size;i++) {
		if(tempWt[i] <= greedyCap && greedyCap > 0) {
			result+=tempProfit[i];
			greedyCap -=tempWt[i];
			selected[tempArr[i]]=1;
		}
	}

	return result;

}




//GREEDY ALGORITHM 1
int greedy1(int weight[],int profit[],int capacity,int size)
{
	int i,j,temp;
	int result=0,greedyCap=capacity;
	int tempArr[size],tempWt[size],tempProfit[size];
	for(i=0;i<size;i++) {
		tempArr[i]=i;
		tempWt[i]=weight[i];
		tempProfit[i]=profit[i];
		selected[i]=0;
	}

	for(i=0;i<size;i++) {
		for(j=0;j<size - i-1;j++) {
			if(tempProfit[j] < tempProfit[j+1]){
				//swap profit
				temp=tempProfit[j];
				tempProfit[j]=tempProfit[j+1];
				tempProfit[j+1]=temp;
				//swap weights
				temp=tempWt[j];
				tempWt[j]=tempWt[j+1];
				tempWt[j+1]=temp;
				//swap item number as well
				temp=tempArr[j];
				tempArr[j]=tempArr[j+1];
				tempArr[j+1]=temp;
			}
		}
	}
	//sorted
	for(i=0;i<size;i++) {
		if(tempWt[i] <= greedyCap && greedyCap > 0) {
			result+=tempProfit[i];
			greedyCap -=tempWt[i];
			selected[tempArr[i]]=1;
		}
	}

	return result;

}



int printResult(int totalProfit) {
	int i,totalWeight=0;

printf("\nSELECTED CHAPTERS: ");
	for(i=0;i<size;i++) {
		if(selected[i]==1) {
			totalWeight+=weight[i];
			printf(" (Chapter %d, %d hrs, %d marks),",i+1,weight[i],profit[i]);
		}
	}
	printf(" \n");
	printf("\nMAXIMUM MARKS THAT CAN BE OBTAINED IS: %d\n",totalProfit);
	printf("\nMINIMUM TIME THAT COULD BE SPENT IS: %d hrs\n\n",totalWeight);

	return 0;
}




//DYNAMIC ALGORITHM
int dynamicKnapsack(int weight[],int profit[],int capacity,int size)
{
	printf("\nDYNAMIC ALGORITHM");
	int i,w,result=0;
	int B[size+1][capacity+1];

	for(w=0;w<=capacity;w++)
		B[0][w]=0;
	for(i=0;i<=size;i++)
		B[i][0]=0;

	for(i=1;i<=size;i++){
		for(w=1;w<=capacity;w++)
		{
			if((weight[i-1] <= w) && ((B[i-1][w-weight[i-1]] + profit[i-1]) > B[i-1][w]))
			{
				B[i][w]=B[i-1][w-weight[i-1]] + profit[i-1];
			}
			else {
				B[i][w]=B[i-1][w];
			}
		}
	}
	//Get the selected elements
	for(i=0;i<size;i++)
		selected[i]=0;

	w=capacity;i=size;
	while(B[i][w]!=0) {
		if(B[i][w] == B[i-1][w]){
			i=i-1;
		}
		else{
			selected[i-1]=1;
			w=w-weight[i-1];
			i=i-1;
		}
	}

	return B[size][capacity];
}




int main()
{

	int i,totalProfit=0,totalWeight=0;
	printf("\nENTER THE NUMBER OF CHAPTERS: ");
	scanf("%d",&size);
	printf("\nENTER TIME REQUIRED FOR EACH CHAPTER (hrs): ");
	for(i=0;i<size;i++)
	{
		scanf("%d",&weight[i]);
	}
	printf("\nENTER THE WIGHTAGE OF EACH CHAPTER (correspondingly): ");
	for(i=0;i<size;i++)
	{
		scanf("%d",&profit[i]);
	}
	int capacity;
	printf("\nENTER TIME AVAILABLE: ");
	scanf("%d",&capacity);
    int choice;
    while(1)
	{
		system("cls");
		printf("\n\nTHE TIME TAKEN FOR EACH CHAPTER IS: \n");
    for(i=0;i<size;i++)
	{
		printf("%d ",weight[i]);
	}
	printf("\n\nTHE WEIGHTAGE OF EACH CHAPTER IS: \n");
	for(i=0;i<size;i++)
	{
		printf("%d ",profit[i]);
	}
    printf("\n\nWHICH ALGORITHM WOULD YOU PREFER? (ENTER 5 TO EXIT) ");
    printf("\n\t1.DYNAMIC PROGRAMMING ALGORITHM ");
    printf("\n\t2.GREEDY ALGORITHM (MAX MARKS FIRST) ");
    printf("\n\t3.GREEDY ALGORITHM (MAX MARKS PER UNIT TIME HOURS SPENT FIRST) ");
    printf("\n\t4.BRUTE FORCE ALGORITHM");
		printf("\n\t5.EXIT");
		printf("\n\nENTER CHOICE : ");
    scanf("%d",&choice);
if(choice==1)
{
	struct timeval start, end;
	gettimeofday(&start, NULL);
	totalProfit = dynamicKnapsack(weight,profit,capacity,size);
	gettimeofday(&end, NULL);
	printResult(totalProfit);
	long seconds = (end.tv_sec - start.tv_sec);
	long nanos = ((seconds * 1000000000) + end.tv_usec) - (start.tv_usec);
	printf("Time elpased is %d nanoseconds\n", nanos);
	 getch();
}
else if(choice==2)
{
	struct timeval start, end;
	gettimeofday(&start, NULL);
	totalProfit=greedy1(weight,profit,capacity,size);
	gettimeofday(&end, NULL);
	printResult(totalProfit);
	long seconds = (end.tv_sec - start.tv_sec);
	long nanos = ((seconds * 1000000000) + end.tv_usec) - (start.tv_usec);
	printf("Time elpased is %d nanoseconds\n", nanos);
	 getch();
}
else if(choice==3)
{
	struct timeval start, end;
	gettimeofday(&start, NULL);
	totalProfit=greedy2(weight,profit,capacity,size);
	gettimeofday(&end, NULL);
	printResult(totalProfit);
	long seconds = (end.tv_sec - start.tv_sec);
	long nanos = ((seconds * 1000000000) + end.tv_usec) - (start.tv_usec);
	printf("Time elpased is %d nanoseconds\n", nanos);
	 getch();
}
else if(choice==4)
{
	struct timeval start, end;
	gettimeofday(&start, NULL);
	totalProfit = bruteforce(weight,profit,capacity,size);
	gettimeofday(&end, NULL);
	printResult(totalProfit);
	long seconds = (end.tv_sec - start.tv_sec);
	long nanos = ((seconds * 1000000000) + end.tv_usec) - (start.tv_usec);
	printf("Time elpased is %d nanoseconds\n", nanos);
	//double time_taken = ((double)t)/CLOCKS_PER_SEC;
   //printf("The program took %f microseconds to execute", time_taken*1000000);
	 getch();
}
else if(choice==5) return 0;
}
}
