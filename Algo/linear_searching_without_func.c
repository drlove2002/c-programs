# include <stdio.h>
# define MAXSIZE 20
int main()
{
	int i, arr[MAXSIZE],n=25,flag=0,item;
	//Intup the array lenght
	printf("Enter the lenght of the array\nNOTE: lenght much be smaller than 20\n> ");
	while(n>20){
		scanf("%d",&n);
		if(n<20)
		break;
		printf("ERROR!\nYou entered the lenght greater than 20!\nEnter the lenght again or press ctrl+c to exit\n> ");
	}
	//Intup the array elements
	while(flag==0){
		printf("Enter %d elements of the array\n",n);
		for(i=0;i<n;i++){
			printf("> ");
			scanf("%d",&arr[i]);
		}
		printf("all elements of the given array:\n\t> ");
		for(i=0;i<n;i++){
			printf("%d, ",arr[i]);
		}
		printf("\n\n-->Enter 1 to confirm\n-->Enter 0 or just press Enter-key to re-enter all elements of the array\n-->Enter other number to exit\n> ");
		scanf("%d",&flag);
		if(flag==1)
		break;
		if(flag!=0)
		return 1;
	}
	while(flag==1){
		printf("Enter the elements to be searched:\n> ");
		scanf("%d",&item);
		//Searching the item
		for(i=0;i<n;i++){
			if(item==arr[i]){
				printf("[!] %d found in position %d\n",item,i+1);
				flag=0;
			}
		}
		if(flag==1){
			printf("Item not found in the array!\n");
		}
		flag=1;
		printf("\n-->Enter 1 or just press Enter-key to search again\n-->Enter any other number to exit\n> ");
		scanf("%d",&flag);
		printf("%d",flag);
		if(flag!= 1){
			return 1;
		}
	}
}
