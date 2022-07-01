// IMPORT LIBRARY
// =====================================================
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<math.h>

// STRUCT DATA RUMAH
// =====================================================
struct kpr{
	char type[20];
	int harga;
	int uang_muka;
	float luas;
	float panjang;
	float lebar; 
} rumah[10];

// DEKLARASI DATA RUMAH
// =====================================================
char house_type[5][30] = {"Type 36", "Type 45", "Type 54", "Type 60", "Type 70"};
int house_price[5] = {120000000, 320000000, 480000000, 720000000, 920000000};
//int down_payment[5] = {};
float house_area[5] = {36, 45, 54, 60, 70};
float house_lenght[5] = {6, 7.5, 6, 10, 10};
float house_width[5] = {6, 6, 9, 6, 7};

// VARIABEL GLOBAL
// =====================================================
int pilihan;
int index_data = 0;

// DEKLARASI FUNGSI
// =====================================================
void menu();
void close();

// MENU
void daftar_rumah();
void simulasi_kpr();
void buat_data();
void perbarui_data();
void urutkan_rumah();
void cari_rumah();
void syarat_dokumen();

// MAIN FUNCTION
// =====================================================
int main(){
	system("cls");
	
	char kembali;
	
	// Menu 
	// =================================================
	do {
		menu:
			system("cls");
			printf("===============================================================================================\n");
			printf("===============================================================================================\n");
			printf("== PROGRAM PERHITUNGAN KREDIT RUMAH (KPR) =====================================================\n");
			printf("== PEMROGRAMAN LANJUT =========================================================================\n");
			printf("== KELOMPOK 1 =================================================================================\n");
			printf("===============================================================================================\n");
			printf("===============================================================================================\n");
			
			printf("\n MAIN MENU:");
			printf("\n [1]. Daftar Type Rumah");
			printf("\n [2]. Simulasi KPR");
			printf("\n [3]. Buat Data Baru");
			printf("\n [4]. Perbarui Data");
			printf("\n [5]. Urutkan Tipe Rumah");
			printf("\n [6]. Cari Tipe Rumah");
			printf("\n [7]. Syarat-syarat dan Dokumen");
			printf("\n [8]. Keluar");
			printf("\n\n Input Pilihan Nomor Menu : ");
			scanf("%d", &pilihan);
			switch(pilihan){
				case 1:
					// MEMANGGIL FUNGSI daftar_rumah()
//					close();
					printf("\n");
				break;
				case 2:
					// MEMANGGIL FUNGSI simulasi_kpr()
//					close();
					printf("\n");
				break;
				case 3:
					// MEMANGGIL FUNGSI buat_data()
//					close();
					printf("\n");
				break;
				case 4:
					// MEMANGGIL FUNGSI perbarui_data()
//					close();
					printf("\n");
				break;
				case 5:
					// MEMANGGIL FUNGSI urutkan_rumah()
//					close();
					printf("\n");
				break;
				case 6:
					// MEMANGGIL FUNGSI cari_rumah()
//					close();
					printf("\n");
				break;
				case 7:
					// MEMANGGIL FUNGSI syarat_dokumen()
					syarat_dokumen();
					printf("\n");
				break;
				case 8:
					// MEMANGGIL FUNGSI close()
//					close();
					printf("\n");
				break;
				default:printf("\n Mohon Maaf Pilihan Anda Tidak Termasuk Dalam Menu!");
					getche();
					goto menu;
			}
			
			printf(" Ingin kembali ke menu pilihan? (Y/T): ");
			scanf("%c", &kembali); scanf("%c", &kembali);
			
	} while(kembali == 'y' || kembali == 'Y');
	
	return 0;
}

// CLOSE FUNCTION
// =====================================================
void close(){
	exit(0);
}

// =====================================================
// =====================================================
// =====================================================

// 1. DAFTAR TYPE RUMAH
// =====================================================
void daftar_rumah(){
	for(int i = 0; i < 10; i++) {
		strcpy(rumah[i].type, house_type[i]);
		rumah[i].harga = house_price[i];
//		rumah[i].uang_muka = down_payment[i];
		rumah[i].luas = house_area[i];
		rumah[i].panjang = house_lenght[i];
		rumah[i].lebar = house_width[i];
	
		printf("\n========= RUMAH KE-%d =========\n", i+1);
		printf("Tipe Rumah : %s \n", rumah[i].type);
		printf("Harga : %d \n", rumah[i].harga);
		printf("Luas : %f (%f * %f) \n", rumah[i].luas, rumah[i].panjang , rumah[i].lebar);
	}
}


// 2. SIMULASI KPR
// =====================================================
void simulasi_kpr(){
}


// 3. BUAT DATA BARU
// =====================================================
void buat_data(){
}


// 4. PERBARUI DATA
// =====================================================
void perbarui_data(){
}


// 5. URUTKAN TIPE RUMAH
// =====================================================
void urutkan_rumah(){
}


// 6. CARI TIPE RUMAH
// =====================================================
void cari_rumah(){
}


// 7. SYARAT-SYARAT DAN DOKUMEN
// =====================================================
void syarat_dokumen(){
	system("cls");
	
	printf("\n Ada beberapa persyaratan dasar dalam pengajuan KPR, yaitu :\n\n");
	printf(" [1]. Berusia minimal 21 tahun\n");
	printf(" [2]. Memiliki pekerjaan atau penghasilan tetap (pegawai/wiraswasta) minimal 1 tahun\n");
	printf(" [3]. Fotokopi KTP/Paspor/KITAS/KITAP\n");
	printf(" [4]. Slip gaji bulan terakhir/Surat Keterangan Gaji\n");
	printf(" [5]. Fotokopi Rekening Koran\n");
	printf(" [6]. Fotokopi Surat Izin Praktek\n");
	printf(" [7]. Fotokopi Akte Perusahaan dan atau SIUP dan NPWP\n");
	printf(" [8]. Fotokopi Tagihan Bulanan Kartu Kredit 1 Bulan Terakhir\n");
	printf(" [9]. Fotokopi Kartu kredit\n");
}

// CLOSE FUNCTION
// =====================================================


// CLOSE FUNCTION
// =====================================================
