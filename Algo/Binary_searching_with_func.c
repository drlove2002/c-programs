# include <stdio.h>
# define MAXSIZE 20


int search(int n,int item,int *arr)
{
	int mid,L=0,U=n-1;
	while(U>=L){
		mid = (U+L)/2;
		if (arr[mid] == item)
		return mid;
		else if (arr[mid] > item)
		U=mid-1;
		else
		L=mid+1;
	}
	return -1;
}

int main()
{
	int i, arr[MAXSIZE],n=25,flag=0,item,position;
	//Intup the array lenght
	printf("Enter the lenght of the array\nNOTE: lenght must be smaller than 20\n> ");
	while(n>20){
		scanf("%d",&n);
		if(n<20)
		break;
		printf("ERROR!\nYou entered the lenght greater than 20!\nEnter the lenght again or press ctrl+c to exit\n> ");
	}
	//Intup the array elements
	while(flag==0){
		printf("Enter %d elements of the array\nNOTE: Array insertion should be in ascending order\n",n);
		for(i=0;i<n;i++){
			printf("> ");
			scanf("%d",&arr[i]);
			if (arr[i-1]>arr[i]){
				printf("[ERROR!] Enter a number greater than %d",arr[i-1]);	
				i--;
			}		
		}
		printf("all elements of the given array:\n\t> ");
		for(i=0;i<n;i++){
			printf("%d, ",arr[i]);
		}
		printf("\n\n-->Enter 1 to confirm\n-->Enter 0 to re-enter all elements of the array\n-->Enter any other number to exit\n> ");
		scanf("%d",&flag);
		if(flag==1)
		break;
		if(flag!=0)
		return 1;
	}
	while(flag==1){
		printf("Enter the element to be searched:\n> ");
		scanf("%d",&item);
		//Searching the item
		position = search(n,item,arr);
		if(position == -1)
		printf("Item not found in the array!\n");
		else
		printf("[!] %d found in position %d\n",item,position+1);
		flag=1;
		printf("\n-->Enter 1 to search again\n-->Enter any other number to exit\n> ");
		scanf("%d",&flag);	
	}
}
