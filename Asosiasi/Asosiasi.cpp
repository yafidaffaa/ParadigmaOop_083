#include <iostream>
#include <vector>
using namespace std;

class dokter;
class pasien {
public:
	string nama;
	vector<dokter*> daftar_dokter;
	pasien(string pNama) :nama(pNama) {
		cout << "Pasien \"" << nama << "\" ada\n";
	}
	~pasien() {
		cout << "Pasien \"" << nama << "\" tidak ada\n";
	}
	void tembahDokter(dokter*);
	void cetakDokter();
};

class dokter {
public:
	string nama;
	vector<pasien*> daftar_pasien;

	dokter(string pNama) :nama(pNama) {
		cout << "Dokter \"" << nama << "\"ada\n";
	}
	~dokter() {
		cout << "Dokter \"" << nama << "\"tidak ada\n";
	}

	void tambahPasien(pasien*);
	void cetakPasien();
};

void pasien::tembahDokter(dokter* pDokter) {
	daftar_dokter.push_back(pDokter);
}
void pasien::cetakDokter() {
	cout << "Daftar Dokter yang menangani pasien \"" << this->nama << "\":\n";
	for (auto& a : daftar_dokter) {
		cout << a->nama << "\n";
	}
}
void dokter::tambahPasien(pasien* pPasien) {
	daftar_pasien.push_back(pPasien);
	pPasien->tembahDokter(this);
}