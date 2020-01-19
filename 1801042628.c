#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct records{
	char ID[78];
	char name[78];
	char surname[78];
	char mail[78];
}record;

int readDataFromFile(struct records record, FILE* fp, struct records record_arr[]);
void sort_and_write_arr(struct records record_arr[], int arr_size, char metric, FILE* writepointer);

int main(){
	struct records record_arr[200];
    struct records record_;
	int arr_size;
    char kolon;
    
	FILE* rp= fopen("hw4_disordered_people.txt", "r");
	if (rp == NULL)
        exit(0);
	
	FILE* writepointer= fopen("orderedFile.txt", "w");
		
	printf("Select the first colon of the list (I N M S): ");
	scanf("%c", &kolon);
	if(kolon =='I'||kolon =='N'||kolon =='M'||kolon =='S'){
	
	arr_size = readDataFromFile(record_, rp, record_arr);
	sort_and_write_arr(record_arr, arr_size, kolon, writepointer);
	
	fclose(rp);
	fclose(writepointer);
	}
	else
		printf("Wrong choice boy try it again\n");	
	return 0;
}

int readDataFromFile(struct records record, FILE* fp, struct records record_arr[]){
	char line[150];
		char frkn1[78], frkn2[78], frkn3[78], frkn4[78];
	
	int i =0;
	
	while(fgets (line, 150, fp) != NULL){
		sscanf( line, "%s %s %s  %s", frkn1, frkn2, frkn3, frkn4);
		
		if(strchr(frkn1, '.'))            /*burda mail olduðunu kontrol etmek için . karakterinin bulunma þartýný kullandýk*/
			strcpy(record.mail, frkn1);
		else if(strpbrk(frkn1, "0123456789")) /*burda numara olduðunu kontrol etmek için sayý karakterinin bulunma þartýný kullandýk*/
			strcpy(record.ID, frkn1);
		else if(strpbrk(frkn1, "aeuýiouöü"))
			strcpy(record.name, frkn1);
		else
			strcpy(record.surname, frkn1);
		
		if(strchr(frkn2, '.'))
			strcpy(record.mail, frkn2);
		else if(strpbrk(frkn2, "0123456789"))
			strcpy(record.ID, frkn2);
		else if(strpbrk(frkn2, "aeuýiouöü"))
			strcpy(record.name, frkn2);
			else
			strcpy(record.surname, frkn2);
		
		if(strchr(frkn3, '.'))
			strcpy(record.mail, frkn3);	
		else if(strpbrk(frkn3, "0123456789"))
			strcpy(record.ID, frkn3);
		else if(strpbrk(frkn3, "aeuýiouöü"))
			strcpy(record.name, frkn3);
		else
			strcpy(record.surname, frkn3);
		
		if(strchr(frkn4, '.'))
			strcpy(record.mail, frkn4);
			else if(strpbrk(frkn4, "0123456789"))
			strcpy(record.ID, frkn4);
		else if(strpbrk(frkn4, "aeuýiouöü"))
			strcpy(record.name, frkn4);
		else
			strcpy(record.surname, frkn4);
		
		strcpy(record_arr[i].ID, record.ID);
		strcpy(record_arr[i].mail, record.mail);
		strcpy(record_arr[i].name, record.name);
		strcpy(record_arr[i].surname, record.surname);

		i++;
	}
	
	return i;
}

void sort_and_write_arr(struct records record_arr[], int arr_size, char metric, FILE* writepointer){
	int i, j;
	char temp[78];
	switch(metric){
		case 'I':
		case 'i':
			for(i=0; i<arr_size; i++){
				for(j=i+1; j<arr_size; j++){
					if(strcmp(record_arr[i].ID, record_arr[j].ID) > 0 ){
						strcpy(temp, record_arr[i].ID);
						strcpy(record_arr[i].ID, record_arr[j].ID);
						strcpy(record_arr[j].ID, temp);
						
						strcpy(temp, record_arr[i].mail);
						strcpy(record_arr[i].mail, record_arr[j].mail);
						strcpy(record_arr[j].mail, temp);
						
						strcpy(temp, record_arr[i].name);
						strcpy(record_arr[i].name, record_arr[j].name);
						strcpy(record_arr[j].name, temp);
						
						strcpy(temp, record_arr[i].surname);
						strcpy(record_arr[i].surname, record_arr[j].surname);
						strcpy(record_arr[j].surname, temp);
					}
				}
			}
			fprintf(writepointer, " ID  - Name - Surname - Mail\n-----------------------------\n");
			for(i=0; i<arr_size; i++){
				fprintf(writepointer, "%s %s %s %s\n", record_arr[i].ID, record_arr[i].name, record_arr[i].surname, record_arr[i].mail);
			}
			break;
		
		case 'M':
		case 'm':
			for(i=0; i<arr_size; i++){
				for(j=i+1; j<arr_size; j++){
					if(strcmp(record_arr[i].mail, record_arr[j].mail) > 0 ){
						strcpy(temp, record_arr[i].ID);
						strcpy(record_arr[i].ID, record_arr[j].ID);
						strcpy(record_arr[j].ID, temp);
						
						strcpy(temp, record_arr[i].mail);
						strcpy(record_arr[i].mail, record_arr[j].mail);
						strcpy(record_arr[j].mail, temp);
						
						strcpy(temp, record_arr[i].name);
						strcpy(record_arr[i].name, record_arr[j].name);
						strcpy(record_arr[j].name, temp);
						
						strcpy(temp, record_arr[i].surname);
						strcpy(record_arr[i].surname, record_arr[j].surname);
						strcpy(record_arr[j].surname, temp);
					}
				}
			}
			fprintf(writepointer, " Mail - ID  - Name - Surname\n-----------------------------\n");
			for(i=0; i<arr_size; i++){
				fprintf(writepointer, "%s %s %s %s\n", record_arr[i].mail, record_arr[i].ID, record_arr[i].name, record_arr[i].surname);
			}
			break;
		
		case 'N':
		case 'n':
			for(i=0; i<arr_size; i++){
				for(j=i+1; j<arr_size; j++){
					if(strcmp(record_arr[i].name, record_arr[j].name) > 0 ){
						strcpy(temp, record_arr[i].ID);
						strcpy(record_arr[i].ID, record_arr[j].ID);
						strcpy(record_arr[j].ID, temp);
						
						strcpy(temp, record_arr[i].mail);
						strcpy(record_arr[i].mail, record_arr[j].mail);
						strcpy(record_arr[j].mail, temp);
						
						strcpy(temp, record_arr[i].name);
						strcpy(record_arr[i].name, record_arr[j].name);
						strcpy(record_arr[j].name, temp);
						
						strcpy(temp, record_arr[i].surname);
						strcpy(record_arr[i].surname, record_arr[j].surname);
						strcpy(record_arr[j].surname, temp);
					}
				}
			}
			fprintf(writepointer, " Name - ID - Surname - Mail\n-----------------------------\n");
			for(i=0; i<arr_size; i++){
				fprintf(writepointer, "%s %s %s %s\n", record_arr[i].name, record_arr[i].ID, record_arr[i].surname, record_arr[i].mail);
			}
			break;
		
		case 'S':
		case 's':
			for(i=0; i<arr_size; i++){
				for(j=i+1; j<arr_size; j++){
					if(strcmp(record_arr[i].surname, record_arr[j].surname) > 0 ){
						strcpy(temp, record_arr[i].ID);
						strcpy(record_arr[i].ID, record_arr[j].ID);
						strcpy(record_arr[j].ID, temp);
						
						strcpy(temp, record_arr[i].mail);
						strcpy(record_arr[i].mail, record_arr[j].mail);
						strcpy(record_arr[j].mail, temp);
						
						strcpy(temp, record_arr[i].name);
						strcpy(record_arr[i].name, record_arr[j].name);
						strcpy(record_arr[j].name, temp);
						
						strcpy(temp, record_arr[i].surname);
						strcpy(record_arr[i].surname, record_arr[j].surname);
						strcpy(record_arr[j].surname, temp);
					}
				}
			}
			fprintf(writepointer, " Surname - ID  - Name - Mail\n-----------------------------\n");
			for(i=0; i<arr_size; i++){
				fprintf(writepointer, "%s %s %s %s\n", record_arr[i].surname, record_arr[i].ID, record_arr[i].name, record_arr[i].mail);
			}
			break;
	}
	
}

