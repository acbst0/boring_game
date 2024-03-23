#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;

class team{
	
	public:
		team(string name)
		{
			isim = name;
			oyuncusay = 11;
			goliht = 7;
			sertlik = 3;
			gol = 0;
		}
		string isim;
		int oyuncusay;
		int goliht;
		int sertlik;
		int gol;
	private:
		int cons = 0;
};

void golihtimali(team *takim1, team *takim2)
{
	srand(static_cast<unsigned int>(time(nullptr)));
	int rastgeleSayi = rand() % 2 + 1;
	
	if (rastgeleSayi == 1)
	{
		int ihtimal = rand() % 101;
		if (ihtimal < takim1->goliht)
		{
			takim1->gol += 1;
			takim2->sertlik += 5;
			takim1->goliht = 5;
			cout << "	GOOOOLLLL, " << takim1->isim << " GOL ATTI" << endl;
			cout << "	Skor suan : " << takim1->gol << "-" << takim2->gol << endl;
		}
		else
		{
			cout << "	" << takim1->isim << " KACIRDI!" << endl;
		}
	}
	else if (rastgeleSayi == 2)
	{
		int ihtimal = rand() % 101;
		if (ihtimal < takim2->goliht)
		{
			takim2->gol = takim2->gol + 1;
			takim1->sertlik += 5;
			takim2->goliht = 5;
			cout << "	GOOOOLLLL, " << takim2->isim << " GOL ATTI" << endl;
			cout << "	Skor suan : " << takim1->gol << "-" << takim2->gol << endl;
		}
		else
		{
			cout << "	" << takim2->isim << " KACIRDI!" << endl;
		}
	}
}

void sertlik(team *takim1, team *takim2)
{
	srand(static_cast<unsigned int>(time(nullptr)));
	int rastgeleSayi = rand() % 2 + 1;
	
	if (rastgeleSayi == 1)
	{
		int ihtimal = rand() % 101;
		if (ihtimal < takim1->sertlik)
		{
			takim1->sertlik = 1;
			takim2->goliht += 6;
			takim1->goliht -= 5;
			takim1->oyuncusay -= 1;
			cout << "	OLAMAZ! " << takim1->isim << " " << takim1->oyuncusay << " kisi kaldi!" << endl;
		}
	}
	else if (rastgeleSayi == 2)
	{
		int ihtimal = rand() % 101;
		if (ihtimal < takim2->sertlik)
		{
			takim2->sertlik = 1;
			takim1->goliht += 6;
			takim2->goliht -= 5; 
			takim2->oyuncusay -= 1;
			cout << "	OLAMAZ! " << takim2->isim << " " << takim2->oyuncusay << " kisi kaldi!" << endl;
		}
	}
}

int main() {
	string name1, name2;
	cout << "1. Takim Adi : " << endl;
	cin >> name1;
	team takim1(name1);
	cout << "2. Takim Adi : " << endl;
	cin >> name2;
	team takim2(name2);
	for (int i = 0; i <= 90; i++)
	{
		if (i == 0)
		{
			cout << takim1.isim << " ve " << takim2.isim << " arasindaki mac basladi!" << endl;
			cout << "Her iki takimada basarilar" << endl << endl;
		}
		else if (i == 45)
		{
			cout << endl << "Ilk yari biti ve skor :" << endl;
			cout << takim1.isim << " " << takim1.gol << " - " << takim2.gol << " " << takim2.isim << endl << endl;
		}
		cout << "Dakika " << i << ":" << endl;
		golihtimali(&takim1, &takim2);
		sertlik(&takim1, &takim2);

		this_thread::sleep_for(chrono::seconds(1));
		if (i == 90)
		{
			cout << endl << "Mac biti ve skor :" << endl;
			cout << takim1.isim << " " << takim1.gol << " - " << takim2.gol << " " << takim2.isim << endl << endl;
			if (takim1.gol > takim2.gol)
				cout << "*** KAZANAN " << takim1.isim << " ***" << endl;
			else if (takim1.gol < takim2.gol)
				cout << "*** KAZANAN " << takim2.isim << " ***" << endl;
			else
				cout << "Bu macta kazanan yok, berabere bitiyor" << endl;
			
		}
	}
	return 0;
}
