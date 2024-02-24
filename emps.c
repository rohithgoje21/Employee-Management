// C program for EMPLOYEE MANAGEMENT SOURCE CODE
//Headerfiles
#include<stdio.h>
#include<conio.h>
#include<string.h>
#define max 20
//Function Declarations
void showMenu();
void build();
void insert();
void deleteRecord();
void deleteIndex(int i);
void searchRecord();
void display();
void exitRecord();
// Structure of Employee
struct employee
{ 
char name[100]; 
char designation[100]; 
int id; 
int exp; 
int age; 
};
// Array of Employees to store the data in the form of the Structure of the Array
struct employee emp[max];
int num; 
FILE *fp;
// Main function
int main()
{
showMenu();
return 0;
}
// Function to show menu
void showMenu() 
{
printf("\n");
printf("Available Options :      \n"); 
printf("----------------------------\n");
printf("-> Build Table      (1)    -\n"); 
printf("-> Insert New Entry (2)    -\n"); 
printf("-> Delete Entry     (3)    -\n"); 
printf("-> Search a Record  (4)    -\n"); 
printf("-> Display Records  (5)    -\n");
printf("-> Exit             (6)    -\n"); 
printf("----------------------------\n");
int option; 
// Input Options 
printf("\n");
printf("Enter your option : ");
scanf("%d",&option);
// Call function on the bases of the above option
switch(option)
{
case 1 : build();
break;
case 2 : insert();
break;
case 3 : deleteRecord();
break;
case 4 : searchRecord();
break;
case 5 : display();
break;
case 6 : exitRecord();
break;
default : 
printf("Expected Options are 1/2/3/4/5/6\n");
showMenu();
}
}
// Function to build the given datatype
void build() 
{
printf("Build The Table Maximum Entries can be %d\n",max);
printf("Enter the number of Entries required: "); 
scanf("%d",&num);
if(num > max){ 
printf("Maximum number of Entries are %d\n",max); 
}else{
printf("Enter the following data...\n"); 
for(int i = 0; i < num; i++)
{ 
fp=fopen("details.txt","a");
fprintf(fp,"_______________________________\n");
printf("Name\n"); 
scanf("%s",emp[i].name); 
fprintf(fp,"NAME                : %s\n",emp[i].name);
printf("Employee ID\n"); 
scanf("%d",&emp[i].id); 
fprintf(fp,"EMPLOYEE ID  : %d\n",emp[i].id);        
printf("Designation\n"); 
scanf("%s",emp[i].designation); 
fprintf(fp,"DESIGNATION : %s\n",emp[i].designation);
printf("Experience\n"); 
scanf("%d",&emp[i].exp);
fprintf(fp,"EXPERIENCE   : %d\n",emp[i].exp);
printf("Age\n"); 
scanf("%d",&emp[i].age); 
fprintf(fp,"AGE                   : %d\n",emp[i].age); 
fclose(fp);
printf("Sucessfully saved the employee details\n");
printf("\n");
} 
}
showMenu(); 
}
// Function to insert the data into given data type
void insert() 
{
if(num < max)
{ 
int i = num; 
num++; 
fp=fopen("details.txt","a");    
fprintf(fp,"_______________________________\n"); 
printf("Enter the following data...\n");
printf("Name\n"); 
scanf("%s",emp[i].name); 
fprintf(fp,"NAME                : %s\n",emp[i].name);
printf("Employee ID\n"); 
scanf("%d",&emp[i].id); 
fprintf(fp,"EMPLOYEE ID  : %d\n",emp[i].id);       
printf("Designation\n"); 
scanf("%s",emp[i].designation); 
fprintf(fp,"DESIGNATION : %s\n",emp[i].designation);     
printf("Experience\n"); 
scanf("%d",&emp[i].exp); 
fprintf(fp,"EXPERIENCE   : %d\n",emp[i].exp);         
printf("Age\n"); 
scanf("%d",&emp[i].age); 
fprintf(fp,"AGE                   : %d\n",emp[i].age); 
fclose(fp); 
printf("Sucessfully saved the employee details\n");
printf("\n");
}else{ 
printf("Employee Table Full\n"); 
} 
showMenu(); 
}
// Function to delete record
void deleteRecord() 
{
int id; 
printf("Enter the Employee ID to Delete Record : "); 
scanf("%d",&id); 

for (int i = 0; i < num; i++)
{ 
if(emp[i].id == id)
{ 
deleteIndex(i); 
//deleteRecord(i); 
num--; 
break; 
} 
} 
printf("\nSuccessfully Deleted Record...\n");
showMenu(); 
}
// Function to delete record at index i
void deleteIndex(int i) 
{
for(int j = i; j < num - 1; j++)
{ 
strcpy(emp[j].name,emp[j + 1].name); 
emp[j].id = emp[j + 1].id; 
strcpy(emp[j].designation,emp[j+1].designation); 
emp[j].exp = emp[j + 1].exp; 
emp[j].age = emp[j + 1].age; 
} 
return; 
}
void searchRecord() 
{
fp= fopen("details.txt","r");
printf("Enter the Employee ID to Search Record : "); 
int id; 
scanf("%d",&id); 
for(int i = 0; i < num; i++)
{ 
// If the data is found 
if (emp[i].id == id)
{ 
printf("Name : %s \n",emp[i].name); 
fprintf(fp,"%s",emp[i].name);           
printf("Employee ID : %d \n",emp[i].id); 
fprintf(fp,"%d",emp[i].id);           
printf("Designation : %s \n",emp[i].designation); 
fprintf(fp,"%s",emp[i].designation);     
printf("Experience : %d\n",emp[i].exp); 
fprintf(fp,"%d",emp[i].exp);           
printf("Age : %d\n",emp[i].age); 
fprintf(fp,"%d",emp[i].age); 
fclose(fp);
break; 
}else{
if (emp[i].id != id)
{
printf("No record found\n");
printf("Please Enter correct ID\n");
printf("\n");
continue;
}

}    

} 
showMenu(); 
}
void display()
{
fp= fopen("details.txt","r"); 
for(int i = 0; i < num; i++)
{ 
//while(fread(&emp[max],sizeof(employee),1,fp))
//{
printf("Name : %s \n",emp[i].name);    printf("Employee ID : %d \n",emp[i].id);          
printf("Designation : %s \n",emp[i].designation); 
printf("Experience : %d\n",emp[i].exp);         
printf("Age : %d\n",emp[i].age); 
printf("\n");
//i++;
//} 
} 
fclose(fp);
showMenu();
}
void exitRecord()
{
return;
}

 
