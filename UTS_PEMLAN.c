// IMPORT LIBRARY
// =====================================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// DATA
// =====================================================
char provinsi[10][20] = {"DKI Jakarta", "D.I. Yogyakarta", "Banten", "Jawa Barat", "Jawa Tengah", "Jawa TImur", "Bali", "NTB", "NTT", "Maluku"};
char kota[10][20] = {"Jakarta Pusat", "Sleman", "Serang", "Bandung", "Solo", "Jombang", "Denpasar", "Bima", "Belu", "Ambon"};
int jumlah_penduduk[10] = {244500, 452225, 330182, 739191, 1200324, 231212, 346454, 879873, 973947, 743975};
int jumlah_lansia[10] = {10202, 29323, 12434, 50534, 90242, 14044, 34321, 84752, 82324, 34223};
int total_vaksinasi[10] = {88, 60, 77, 44, 30, 76, 84, 67, 50, 46};
int total_vaksinasi_lansia[10] = {84, 72, 63, 42, 76, 39, 60, 85, 56, 74};

int npm_ganjil[10] = {1010105, 1010133, 1010111, 1010127, 1010077, 1010165, 1010193, 1010055, 1010099, 1010131};
int npm_genap[10] = {1010108, 1010134, 1010118, 1010122, 1010074, 1010160, 1010196, 1010052, 1010098, 1010132};


// VARIABEL GLOBAL
// =====================================================
int pilihan;

// DEKLARASI FUNGSI
// =====================================================
void menu();
void close();
int selection_sort(int arr[]);
void search_provinsi();
void search_kota();
void search_level_ppkm();
void search_level();

// MENU UTAMA
void level_ppkm();
void sort_ascending();
void sort_descending();
void sort_npm_ganjil();
void sort_npm_genap();
void search_data();


// MENU UTAMA
// =====================================================
void menu(){
	char kembali;
	do {
		menu:
			system("cls");
			printf("===============================================================================================\n");
			printf("===============================================================================================\n");
			printf("== UTS - PROGRAM DATA VAKSINASI ===============================================================\n");
			printf("== ABDUL WASI' AL-AFIF ========================================================================\n");
			printf("== 20081010165 ================================================================================\n");
			printf("===============================================================================================\n");
			printf("===============================================================================================\n");
			
			printf("\n");
			printf("Note:\n");
			printf("\n");
			printf("\n");
			
			printf("MAIN MENU:");
			printf("\n[1]. Level PPKM");
			printf("\n[2]. Sorting Data Ascending");
			printf("\n[3]. Sorting Data Descending");
			printf("\n[4]. Sorting NPM Ganjil");
			printf("\n[5]. Sorting NPM Genap");
			printf("\n[6]. Searching Data");
			printf("\n[7]. Keluar");
			printf("\n\nInput Pilihan Nomor Menu : ");
			scanf("%d", &pilihan);
			switch(pilihan){
				case 1:
					level_ppkm();
				break;
				case 2:
					sort_ascending();
//					close();
				break;
				case 3:
					sort_descending();
//					close();
				break;
				case 4:
					sort_npm_ganjil();
				break;
				case 5:
					sort_npm_genap();
				break;
				case 6:
					search_data();
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

// CLOSE FUNCTION
// =====================================================
void close(){
	exit(0);
}

// READ DATA
// =====================================================
void data(){
	int i, j;
	
//	system("cls");
	
//	for(i = 0; i < 10; i++) {
	printf("Provinsi : %s \n", provinsi[i]);
	printf("Kota : %s \n", kota[i]);
//	}
	
	printf("\n");
}

// LEVEL PPKM
// =====================================================
void level_ppkm(){
	int i = 0;
	
	printf("\n");
	
	for(i = 0; i < 10; i++){
		if(total_vaksinasi[i] >= 70 && total_vaksinasi_lansia[i] >= 60){
			printf("Data ke-%d - Level PPKM 1\n", i+1);
			printf("Provinsi : %s \n", provinsi[i]);
			printf("Kota : %s \n", kota[i]);
			printf("\n");
		} else if (total_vaksinasi[i] >= 50 && total_vaksinasi_lansia[i] >= 40){
			printf("Data ke-%d - Level PPKM 2\n", i+1);
			printf("Provinsi : %s \n", provinsi[i]);
			printf("Kota : %s \n", kota[i]);
			printf("\n");
		} else {
			printf("Data ke-%d - Level PPKM 3\n", i+1);
			printf("Provinsi : %s \n", provinsi[i]);
			printf("Kota : %s \n", kota[i]);
			printf("\n");
		}
	}
}

// SORTING ASCEDING
// =====================================================
char level[10][10] = {"1", "2", "1", "3", "3", "3", "1", "2", "2", "3"};

void ascending(){
  	int i, j;
	char tukar[20];
  
  	for (i = 10-1; i > 0; i--) {
		for (j = 10 - 1; j >= 10 - i; j--) {
			if (strcmp(level[i], level[j-1]) < 0) {
				strcpy(tukar, level[j]);
				strcpy(level[j], level[j-1]);
				strcpy(level[j-1], tukar);
			}
		}
	}
}

void sort_ascending(){
	int i, j;
	
	ascending(level);
	
  	for(i = 0; i < 10; i++){
    	printf("Level ke-%d = %s\n", i+1, level[i]);
		printf("\n");
  	}

}

void descending(){
  	int i, j;
	char tukar[20];
  	
  	for (i = 10-1; i > 0; i--) {
		for (j = 10 - 1; j >= 10 - i; j--) {
			if (strcmp(level[i], level[j-1]) > 0) {
				strcpy(tukar, level[j]);
				strcpy(level[j], level[j-1]);
				strcpy(level[j-1], tukar);
			}
		}
	}
}

void sort_descending(){
	int i, j;
	
	descending(level);
	
  	for(i = 0; i < 10; i++){
    	printf("Level ke-%d = %s\n", i+1, level[i]);
		printf("\n");
  	}

}

// SORTING NPM GANJIL
// =====================================================
int selection_sort(int array[]){
	int i, j, posisi, swap;
	for(i = 0; i < (9); i++){
	    posisi = i;
	    for (j = i + 1; j < 10; j++){
	      	if(array[posisi] > array[j]){
	        	posisi = j;
	      	}
	    }
	    if(posisi != i){
	      	swap = array[i];
	      	array[i] = array[posisi];
	      	array[posisi] = swap;
	    }
	}
}

void sort_npm_ganjil() {
	int i;
	
	selection_sort(npm_ganjil);
	
  	for(i = 0; i < 10; i++){
    	printf("NPM ke-%d = %d\n", i+1, npm_ganjil[i]);
  	}
  	
//  	printf("\n");
  	
	printf("\n");
}

// SORTING NPM GENAP
// =====================================================
void insertion_sort(int array[])
{
    int i, tmp, j;
    for (i = 1; i < 10; i++) {
        tmp = array[i];
        j = i - 1;
        
        while (j >= 0 && array[j] > tmp) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = tmp;
    }
}

void sort_npm_genap() {
	int i;
	
	insertion_sort(npm_genap);
	
  	for(i = 0; i < 10; i++){
    	printf("NPM ke-%d = %d\n", i+1, npm_genap[i]);
  	}
  	
	printf("\n");
}

// SEARCHING: LINEAR SEARCH
// =====================================================
void search_data(){
	
	char kembali;
	
	do {
		menu:
			system("cls");
			printf("Menu: Search Data\n");
			printf("\n[1]. Cari Provinsi");
			printf("\n[2]. Cari Kota");
			printf("\n[3]. Cari Level PPKM");
			printf("\n[4]. Keluar");
			printf("\n\nInput Pilihan Nomor Menu : ");
			scanf("%d", &pilihan);
			switch(pilihan){
				case 1:
					search_provinsi();
				break;
				case 2:
					search_kota();
//					close();
				break;
				case 3:
					search_level_ppkm();
//					close();
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

void search_provinsi(){
	
	int i;
	char item[20]; 
	 
    printf("\nProvinsi yang dicari: ");  
	fflush(stdin);
    scanf("%[^\n]", &item);  
    
	for (i = 0; i < 10; i++) {
    	if (provinsi[i] == item) {
    		printf("Provinsi %s berada di indeks ke-%d.\n", item, i+1);
      		break;
    	}
	}
	
  	if (i == 10){
    	printf("Provinsi %s tidak ada.\n", item);
  	}

}

void search_kota(){
	
	int i;
	char item[20]; 
	 
    printf("\nKota yang dicari: ");  
	fflush(stdin);
    scanf("%[^\n]", &item);  
    
	for (i = 0; i < 10; i++) {
    	if (kota[i] == item) {
    		printf("Kota %s berada di indeks ke-%d.\n", item, i+1);
      		break;
    	}
	}
	
  	if (i == 10){
    	printf("Kota %s tidak ada.\n", item);
  	}

}

void search_level_ppkm(){
	
	int i;
	char item[20]; 
	 
    printf("\nLevel yang dicari: ");  
	fflush(stdin);
    scanf("%[^\n]", &item);  
	
	for (i = 0; i < 10; i++) {
    	if (level[i] == item) {
    		printf("Level PPKM %s berada di indeks ke-%d.\n", item, i+1);
      		break;
    	}
	}
	
  	if (i == 10){
    	printf("Level PPKM %s tidak ada.\n", item);
  	}
}

//void search_level(){
//	int i = 0;
//	printf("\n");
//	
//	level[10] = {"Level 1", "Level 2", "Level 1", "Level 3", "Level 3", "Level 3", "Level 1", "Level 2", "Level 2", "Level 3"}
//}
