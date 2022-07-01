// IMPORT LIBRARY
// =====================================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// STRUCT DATA MAHASISWA
// =====================================================
struct data{
	char nim[20];
	char nama[50];
	char jurusan[20];
	float ipk;
} data_mahasiswa[100];

// VARIABEL GLOBAL
// =====================================================
int pilihan;
int index_data = 0;

// DEKLARASI FUNGSI
// =====================================================
void menu();
void mahasiswa();
void close();
void input_data(int index);
void delete_data();
int search_index();

// MENU UTAMA
void create_mahasiswa();
void read_mahasiswa();
void update_mahasiswa();
void delete_mahasiswa();
void sorting_mahasiswa();

// Deklarasi Sort
void bubble_sort();
void bubble_nama_ascending();
void bubble_nama_descending();
void bubble_nim_ascending();
void bubble_nim_descending();
void selection_sort();
void selection_nama_ascending();
void selection_nama_descending();
void selection_nim_ascending();
void selection_nim_descending();
void insertion_sort();
void insertion_nama_ascending();
void insertion_nama_descending();
void insertion_nim_ascending();
void insertion_nim_descending();

// Deklarasi Searching
void searching_mahasiswa();
void linear_search();
void binary_search();

// MENU UTAMA
// =====================================================
void menu(){
	char kembali;
	do {
		menu:
			system("cls");
			printf("===============================================================================================\n");
			printf("===============================================================================================\n");
			printf("== PROGRAM APLIKASI DATA MAHASISWA ============================================================\n");
			printf("== ABDUL WASI' AL-AFIF ========================================================================\n");
			printf("== 20081010165 ================================================================================\n");
			printf("===============================================================================================\n");
			printf("===============================================================================================\n");
			
			printf("\n");
			printf("Note:\n");
			printf("\n");
			
			printf("MAIN MENU:");
			printf("\n[1]. Create Mahasiswa");
			printf("\n[2]. Read Data Mahasiswa");
			printf("\n[3]. Update Data Mahasiswa");
			printf("\n[4]. Delete Data Mahasiswa");
			printf("\n[5]. Sorting Data Mahasiswa");
			printf("\n[6]. Searching data Mahasiswa");
			printf("\n[7]. Keluar");
			printf("\n\nInput Pilihan Nomor Menu : ");
			scanf("%d", &pilihan);
			switch(pilihan){
				case 1:
					create_mahasiswa();
				break;
				case 2:
					read_mahasiswa();
				break;
				case 3:
					update_mahasiswa();
				break;
				case 4:
					delete_mahasiswa();
				break;
				case 5:
					sorting_mahasiswa();
				break;
				case 6:
					searching_mahasiswa();
				break;
				case 7:
					close();
				break;
				default:printf("\nMohon Maaf Pilihan Anda Salah !");
					getche();
					goto menu;
			}
			
			printf("Ingin kembali ke menu pilihan? (Y/T): ");
			scanf("%c", &kembali); scanf("%c", &kembali);
			
	} while(kembali == 'y' || kembali == 'Y');
	
}

// MAIN FUNCTION
// =====================================================
int main(){
	system("cls");
	menu();
	return 0;
}

// Close Function
void close(){
	exit(0);
}

// Back Function
// Masih belum dipakai
void back(){
	back_menu:
	printf("\n\n\tEnter 1 untuk menu utama dan 0 untuk keluar : ");
	switch(getch()){
		case '1': 
			menu();
    	break;
    	case '0': 
			close();
    	break;
    	default:printf("\nMaaf Kesalahan Input !");
    		getche();
    		goto back_menu;
	}
}

// Input Data function
void input_data(int index){
	int i, banyak_input;
	
	printf("Banyak data mahasiswa yang diinput: ");
	fflush(stdin);
	scanf("%d", &banyak_input);
	
	printf("\n");
	
	for(i = 0; i < banyak_input; i++){
		printf("Masukkan nama mahasiswa: ");
		fflush(stdin);
		scanf("%[^\n]", &data_mahasiswa[index].nama);
	
		printf("Masukkan nim mahasiswa: ");
		fflush(stdin);
		scanf("%[^\n]", &data_mahasiswa[index].nim);
		
		printf("Masukkan jurusan mahasiswa: ");
		fflush(stdin);
		scanf("%[^\n]", &data_mahasiswa[index].jurusan);
	
		printf("Masukkan ipk mahasiswa: ");
		fflush(stdin);
		scanf("%f", &data_mahasiswa[index].ipk);
		
		printf("\n");
	}
	
	printf("\nData Mahasiswa Sudah Disimpan !");
	printf("\n\n");
	
}

// CREATE MAHASISWA
// =====================================================
void create_mahasiswa(){
	system("cls");
	printf("MENU: CREATE DATA MAHASISWA\n\n");
	
	input_data(index_data);
	index_data++;
	
}

// READ MAHASISWA
// =====================================================
void read_mahasiswa(){
	int i;
	
	system("cls");
	printf("MENU: DATA MAHASISWA\n\n");
	
	for(i = 0; i < index_data; i++) {
		printf("\n=== DATA MAHASISWA KE-%d ===\n", i+1);
		printf("Nama Mahasiswa : %s \n", data_mahasiswa[i].nama);
		printf("NIM Mahasiswa : %s \n", data_mahasiswa[i].nim);
		printf("Jurusan Mahasiswa : %s \n", data_mahasiswa[i].jurusan);
		printf("IPK Mahasiswa : %f \n", data_mahasiswa[i].ipk);
	}
	
	printf("\n\n");
}

// UPDATE MAHASISWA
// =====================================================
void update_mahasiswa() {
	system("cls");
	printf("MENU: UPDATE DATA MAHASISWA\n\n");
	
	char nim[20];

	printf("Masukkan NIM mahasiswa untuk mengubah datanya: ");
	scanf("%s", &nim);

	int index = search_index(nim);
	if (index < 0) {
		printf("Data tidak ditemukan\n");
	}
	else {
		input_data(index);
	}
}

// DELETE MAHASISWA
// =====================================================
void delete_data(int index) {
	int i, tempat = 0;

	for (i = 0; i < index_data; i++) {
		if (i != index) {
			data_mahasiswa[tempat] = data_mahasiswa[i];
			tempat++;
		}
	}
	index_data--;

	printf("\n=== Data mahasiswa setelah dihapus ===\n");
	
	for(i = 0; i < index_data; i++) {
		printf("\n=== DATA MAHASISWA KE-%d ===\n", i+1);
		printf("Nama Mahasiswa : %s \n", data_mahasiswa[i].nama);
		printf("NIM Mahasiswa : %s \n", data_mahasiswa[i].nim);
		printf("Jurusan Mahasiswa : %s \n", data_mahasiswa[i].jurusan);
		printf("IPK Mahasiswa : %f \n", data_mahasiswa[i].ipk);
	}
}

int search_index(char nim[20]) {
	int i;
	int index = -1;

	for (i = 0; i < index_data && index < 0; i++) {
		if (strcmp(data_mahasiswa[i].nim, nim) == 0) {
			index = i;
		}
	}
	return index;
}


void delete_mahasiswa(){
	system("cls");
	printf("MENU: DELETE DATA MAHASISWA\n\n");
	char nim[20];

	printf("Masukkan NIM mahasiswa untuk menghapus data mahasiswa: ");
	scanf("%s", &nim);

	int index = search_index(nim);
	if (index < 0) {
		printf("Data tidak ditemukan\n");
		delete_mahasiswa();
	}
	else {
		delete_data(index);
	}
}

// SORTING MAHASISWA
// =====================================================
void sorting_mahasiswa(){
	
	char kembali;
	
	do {
		menu:
			system("cls");
			printf("MENU: SORTING DATA MAHASISWA\n");
			printf("\n[1]. Bubble Sort");
			printf("\n[2]. Selection Sort");
			printf("\n[3]. Insertion Sort");
			printf("\n[4]. Keluar");
			printf("\n\nInput Pilihan Nomor Menu : ");
			scanf("%d", &pilihan);
			switch(pilihan){
				case 1:
					bubble_sort();
				break;
				case 2:
					selection_sort();
				break;
				case 3:
					bubble_sort();
				break;
				case 4:
					close();
				break;
				default:printf("\nMohon Maaf Pilihan Anda Salah !");
					getche();
					goto menu;
			}
			
			printf("Ingin kembali ke menu pilihan? (Y/T): ");
			scanf("%c", &kembali); scanf("%c", &kembali);
			
	} while(kembali == 'y' || kembali == 'Y');
	
}

void read_sorting_data() {
	int i;

	printf("NIM\tNAMA\n\n");

	for(i = 0; i < index_data; i++) {
		printf("%s\t%s\n", data_mahasiswa[i].nim, data_mahasiswa[i].nama);
	}
}

// BUBBLE SORT
// =====================================================
void bubble_sort(){
	
	menu:
		system("cls");
		printf("MENU: BUBBLE SORT\n");
		printf("\n[1]. Nama Ascending");
		printf("\n[2]. Nama Descending");
		printf("\n[3]. NIM Ascending");
		printf("\n[4]. NIM Descending");
		printf("\n[5]. Keluar");
		printf("\n\nInput Pilihan Nomor Menu : ");
		scanf("%d", &pilihan);
		switch(pilihan){
			case 1:
				bubble_nama_ascending();
				read_sorting_data();
			break;
			case 2:
				bubble_nama_descending();
				read_sorting_data();
			break;
			case 3:
				bubble_nim_ascending();
				read_sorting_data();
			break;
			case 4:
				bubble_nim_descending();
				read_sorting_data();
			break;
			case 5:
				close();
			break;
			default:printf("\nMohon Maaf Pilihan Anda Salah !");
				getche();
				goto menu;
		}
}


void bubble_nama_ascending() {
	system("cls");
	printf("MENU: Bubble Sort Nama Ascending\n\n");
	
	int i, j;
	char tukar[20];

	for (i = index_data- 1; i > 0; i--) {
		for (j = index_data - 1; j >= index_data - i; j--) {
			if (strcmp(data_mahasiswa[j].nama, data_mahasiswa[j-1].nama) < 0) {
				strcpy(tukar, data_mahasiswa[j].nama);
				strcpy(data_mahasiswa[j].nama, data_mahasiswa[j-1].nama);
				strcpy(data_mahasiswa[j-1].nama, tukar);
			}
		}
	}
}

void bubble_nama_descending() {
	system("cls");
	printf("MENU: Bubble Sort Nama Descending\n\n");
	
	int i, j;
	char tukar[20];

	for (i = index_data - 1; i > 0; i--) {
		for (j = index_data - 1; j >= index_data - i; j--) {
			if (strcmp(data_mahasiswa[j].nama, data_mahasiswa[j-1].nama) > 0) {
				strcpy(tukar, data_mahasiswa[j].nama); 
				strcpy(data_mahasiswa[j].nama, data_mahasiswa[j-1].nama);
				strcpy(data_mahasiswa[j-1].nama, tukar);
			}
		}
	}
}

void bubble_nim_ascending() {
	system("cls");
	printf("MENU: Bubble Sort NIM Ascending\n\n");
	
	int i, j;
	char tukar[20];

	for (i = index_data - 1; i > 0; i--) {
		for (j = index_data - 1; j >= index_data - i; j--) {
			if (strcmp(data_mahasiswa[j].nim, data_mahasiswa[j-1].nim) < 0) {
				strcpy(tukar, data_mahasiswa[j].nim);
				strcpy(data_mahasiswa[j].nim, data_mahasiswa[j-1].nim);
				strcpy(data_mahasiswa[j-1].nim, tukar);
			}
		}
	}
}

void bubble_nim_descending() {
	system("cls");
	printf("MENU: Bubble Sort NIM Descending\n\n");
	
	int i, j;
	char tukar[20];

	for (i = index_data - 1; i > 0; i--) {
		for (j = index_data - 1; j >= index_data - i; j--) {
			if (strcmp(data_mahasiswa[j].nim, data_mahasiswa[j-1].nim) > 0) {
				strcpy(tukar, data_mahasiswa[j].nim);
				strcpy(data_mahasiswa[j].nim, data_mahasiswa[j-1].nim);
				strcpy(data_mahasiswa[j-1].nim, tukar);
			}
		}
	}
}

// SELECTION SORT
// =====================================================
void selection_sort(){
	
	menu:
		system("cls");
		printf("MENU: SELECTION SORT\n");
		printf("\n[1]. Nama Ascending");
		printf("\n[2]. Nama Descending");
		printf("\n[3]. NIM Ascending");
		printf("\n[4]. NIM Descending");
		printf("\n[5]. Keluar");
		printf("\n\nInput Pilihan Nomor Menu : ");
		scanf("%d", &pilihan);
		switch(pilihan){
			case 1:
				selection_nama_ascending();
				read_sorting_data();
			break;
			case 2:
				selection_nama_descending();
				read_sorting_data();
			break;
			case 3:
				selection_nim_ascending();
				read_sorting_data();
			break;
			case 4:
				selection_nim_descending();
				read_sorting_data();
			break;
			case 5:
				close();
			break;
			default:printf("\nMohon Maaf Pilihan Anda Salah !");
				getche();
				goto menu;
		}
}

void selection_nama_ascending() {
	system("cls");
	printf("MENU: Selection Sort Nama Ascending\n\n");
	
	int i, j, minimum;
	char tukar[20];

	for (i = 0; i < (index_data-1); i++) {
		minimum = i;

		for (j = i+1; j < index_data; j++) {
			if (strcmp(data_mahasiswa[j].nama, data_mahasiswa[minimum].nama) < 0)
				minimum = j;
		}
		if (minimum != i) {
			strcpy(tukar, data_mahasiswa[minimum].nama);
            strcpy(data_mahasiswa[minimum].nama, data_mahasiswa[i].nama);
            strcpy(data_mahasiswa[i].nama, tukar);
		}
	}
}

void selection_nama_descending() {
	system("cls");
	printf("MENU: Selection Sort Nama Descending\n\n");
	
	int i, j, minimum;
	char tukar[20];

	for (i = 0; i < (index_data-1); i++) {
		minimum = i;

		for (j = i+1; j < index_data; j++) {
			if (strcmp(data_mahasiswa[j].nama, data_mahasiswa[minimum].nama) > 0)
				minimum = j;
		}
		if (minimum != i) {
			strcpy(tukar, data_mahasiswa[minimum].nama);
            strcpy(data_mahasiswa[minimum].nama, data_mahasiswa[i].nama);
            strcpy(data_mahasiswa[i].nama, tukar);
		}
	}
}

void selection_nim_ascending() {
	system("cls");
	printf("MENU: Selection Sort NIM Ascending\n\n");
	
	int i, j, minimum;
	char tukar[20];

	for (i = 0; i < (index_data-1); i++) {
		minimum = i;

		for (j = i+1; j < index_data; j++) {
			if (strcmp(data_mahasiswa[j].nim, data_mahasiswa[minimum].nim) < 0)
				minimum = j;
		}
		if (minimum != i) {
			strcpy(tukar, data_mahasiswa[minimum].nim);
            strcpy(data_mahasiswa[minimum].nim, data_mahasiswa[i].nim);
            strcpy(data_mahasiswa[i].nim, tukar);
		}
	}
}

void selection_nim_descending() {
	system("cls");
	printf("MENU: Selection Sort NIM Descending\n\n");
	
	int i, j, minimum;
	char tukar[20];

	for (i = 0; i < (index_data-1); i++) {
		minimum = i;

		for (j = i+1; j < index_data; j++) {
			if (strcmp(data_mahasiswa[j].nim, data_mahasiswa[minimum].nim) > 0)
				minimum = j;
		}
		if (minimum != i) {
			strcpy(tukar, data_mahasiswa[minimum].nim);
            strcpy(data_mahasiswa[minimum].nim, data_mahasiswa[i].nim);
            strcpy(data_mahasiswa[i].nim, tukar);
		}
	}
}

// INSERTION SORT
// =====================================================
void insertion_sort(){
	
	menu:
		system("cls");
		printf("MENU: INSERTION SORT\n");
		printf("\n[1]. Nama Ascending");
		printf("\n[2]. Nama Descending");
		printf("\n[3]. NIM Ascending");
		printf("\n[4]. NIM Descending");
		printf("\n[5]. Keluar");
		printf("\n\nInput Pilihan Nomor Menu : ");
		scanf("%d", &pilihan);
		switch(pilihan){
			case 1:
				insertion_nama_ascending();
				read_sorting_data();
			break;
			case 2:
				insertion_nama_descending();
				read_sorting_data();
			break;
			case 3:
				insertion_nim_ascending();
				read_sorting_data();
			break;
			case 4:
				insertion_nim_descending();
				read_sorting_data();
			break;
			case 5:
				close();
			break;
			default:printf("\nMohon Maaf Pilihan Anda Salah !");
				getche();
				goto menu;
		}
}

void insertion_nama_ascending() {
	system("cls");
	printf("MENU: Insertion Sort Nama Ascending\n\n");
	
	int i, j;
	char kunci[20];

	for (i = 1; i < index_data; i++) {
		strcpy(kunci, data_mahasiswa[i].nama);
		j = i - 1;

		while (j >= 0 && strcmp(data_mahasiswa[j].nama, kunci) > 0) {
			strcpy(data_mahasiswa[j + 1].nama, data_mahasiswa[j].nama);
			j = j - 1;
		}
		strcpy(data_mahasiswa[j + 1].nama, kunci);
	}
}

void insertion_nama_descending() {
	system("cls");
	printf("MENU: Insertion Sort Nama Descending\n\n");
	
	int i, j;
	char kunci[20];

	for (i = 1; i < index_data; i++) {
		strcpy(kunci, data_mahasiswa[i].nama);
		j = i - 1;

		while (j >= 0 && strcmp(data_mahasiswa[j].nama, kunci) < 0) {
			strcpy(data_mahasiswa[j + 1].nama, data_mahasiswa[j].nama);
			j = j - 1;
		}
		strcpy(data_mahasiswa[j + 1].nama, kunci);
	}
}

void insertion_nim_ascending() {
	system("cls");
	printf("MENU: Insertion Sort NIM Ascending\n\n");
	
	int i, j;
	char kunci[20];

	for (i = 1; i < index_data; i++) {
		strcpy(kunci, data_mahasiswa[i].nim);
		j = i - 1;

		while (j >= 0 && strcmp(data_mahasiswa[j].nim, kunci) > 0) {
			strcpy(data_mahasiswa[j + 1].nim, data_mahasiswa[j].nim);
			j = j - 1;
		}
		strcpy(data_mahasiswa[j + 1].nim, kunci);
	}
}

void insertion_nim_descending() {
	system("cls");
	printf("MENU: Insertion Sort NIM Descending\n\n");
	
	int i, j;
	char kunci[20];

	for (i = 1; i < index_data; i++) {
		strcpy(kunci, data_mahasiswa[i].nim);
		j = i - 1;

		while (j >= 0 && strcmp(data_mahasiswa[j].nim, kunci) < 0) {
			strcpy(data_mahasiswa[j + 1].nim, data_mahasiswa[j].nim);
			j = j - 1;
		}
		strcpy(data_mahasiswa[j + 1].nim, kunci);
	}
}

// SEARCHING MAHASISWA
// =====================================================
void searching_mahasiswa(){
	
	char kembali;
	
	do {
		menu:
			system("cls");
			printf("MENU: SEARCHING DATA MAHASISWA\n");
			printf("\n[1]. Linear Search");
			printf("\n[2]. Binary Search");
			printf("\n[3]. Keluar");
			printf("\n\nInput Pilihan Nomor Menu : ");
			scanf("%d", &pilihan);
			switch(pilihan){
				case 1:
					linear_search();
				break;
				case 2:
					binary_search();
				break;
				case 3:
					close();
				break;
				default:printf("\nMohon Maaf Pilihan Anda Salah !");
					getche();
					goto menu;
			}
			
			printf("Ingin kembali ke menu pilihan? (Y/T): ");
			scanf("%c", &kembali); scanf("%c", &kembali);
			
	} while(kembali == 'y' || kembali == 'Y');
	
}

// LINEAR SEARCH
// =====================================================
void linear_search(){
	system("cls");
	printf("MENU: Linear Search\n\n");
	
	int i,flag;
	char item[20]; 
	 
    printf("\nMasukkan NIM yang dicari: ");  
	fflush(stdin);
    scanf("%[^\n]", &item);  
    
	for (i = 0; i < index_data; i++){  
        if(strcmp(data_mahasiswa[i].nim, item) == 0){  
            flag = 1;  
            break; 
        } else   
        
		flag = 0;  
    }   
    
	if(flag == 1){
		printf("\nNIM Mahasiswa Ditemukan!");  
	} else {
		printf("\nNIM Mahasiswa Tidak Ditemukan!");
	}
}

// BINARY SEARCH
// =====================================================
void binary_search(){
	system("cls");
	printf("MENU: Binary Search\n\n");
	
	int i, location = -1;   
	char item[20]; 
	
    printf("\nMasukkan NIM yang dicari: ");  
	fflush(stdin);
    scanf("%[^\n]", &item); 
    
	int left, right, middle;
	left = 0;
	right = index_data - 1;
	int flag = 0;
	while (left <= right && flag == 0) {
		middle = (left + right)/2;
		if(strcmp(data_mahasiswa[middle].nim, item)){
			flag = 1;
            break;
		} else if (strcmp(item, data_mahasiswa[middle].nim)) {
			right = middle - 1;
		} else {
			left = middle + 1;
		}
	}
	
	if(flag == 1){
		printf("\nNIM Mahasiswa Ditemukan!");  
	} else {
		printf("\nNIM Mahasiswa Tidak Ditemukan!");
	}
}

