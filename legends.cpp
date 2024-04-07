//version X

//includes and defines section
#include <iostream>
#include <conio.h>
#include <dos.h>
#include <windows.h>
#include <time.h>

#define SCREEN_WIDTH 120
#define SCREEN_HEIGHT 30

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

//data section
int lvl = 0;
int op;
int hp;
int xp = 0;
int att;
int dif;
int cash = 10;
int ult = 1;
string nickname;

const char cHeart = 3;
const char cCash = 4;
const char cXP = 5;

string placeName[16] =
{"PRATO FIORITO", "BOSCO BLATERANTE", "SPONDE DEL SACCHEGGIO", "LANDE LETALI", "CONDOTTI CONFUSI","TERRITORI TERROSI","ROVINE di AA","APPRODO AVVENTURATO","LA TORRE","VULCANO VASTOSO","CASTELLO CORRETTO", "SABBIE SUDATE","COLLE COLLOSO", "LA GROTTA", "PASSO PISQUANO","REGNO dell'HERMETICO"};

string className[2][3] =
{
	{"MAGO", "BOSCAIOLO", "ELFO"},
	{"INCANTESIMO", "SPADATA", "FRECCIA MAGICA"}
};
int classData[3][3] = //HP - ATT -DIF
{
	{70,80,60},
	{60,50,90},
	{70,90,40}
};

string enemyName[3] = {"ZOMBI", "SCHELETRO", "STREGA"};
int enemyData[2][3] =
{
	{40,20,50},
	{60,50,70}
};

// func section
void gotoxy(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

void updateAll()
{
	//XP
	string exp = "";
	for(int i = 0; i < xp/15; i++)
	{
		exp.push_back(cXP);
	}
	gotoxy((SCREEN_WIDTH / 6) - (exp.size() / 2) - 1, SCREEN_HEIGHT - 1);
	cout<<exp;

	//HEART
	string cuori = "";
	for(int i = 0; i < hp/5; i++)
	{
		cuori.push_back(cHeart);
	}
	gotoxy((SCREEN_WIDTH / 2) - (cuori.size() / 2) - 1, SCREEN_HEIGHT - 1);
	cout<<cuori;

	//GEMME
	string gemma = "";
	for(int i = 0; i < cash/5; i++)
	{
		gemma.push_back(cCash);
	}
	gotoxy((5 * SCREEN_WIDTH / 6) - (gemma.size() / 2) - 1, SCREEN_HEIGHT - 1);
	cout<<gemma;

	//LEGEND
	gotoxy(SCREEN_WIDTH - 18, 1);
	cout<<"Vita: \t"<<hp<<"  ";
	gotoxy(SCREEN_WIDTH - 18, 2);
	cout<<"Attacco: \t"<<att<<"  ";
	gotoxy(SCREEN_WIDTH - 18, 3);
	cout<<"Difesa: \t"<<dif<<"  ";
	gotoxy(SCREEN_WIDTH - 18, 4);
	cout<<"Finali: \t"<<ult<<"  ";
	gotoxy(SCREEN_WIDTH - 18, 5);
	cout<<"Gemme: \t"<<cash<<"  ";
	gotoxy(SCREEN_WIDTH - 18, 6);
	cout<<"XP: \t"<<xp<<"  ";
}

void launcher()
{
	system("title L E G E N D S");
	//lato superiore
	gotoxy(40, 10);
	for (int i = 0; i < 40; i++)
	{
		cout << "-";
	}
	//lato inferiore
	gotoxy(40, 14);
	for (int i = 0; i < 40; i++)
	{
		cout << "-";
	}
	//bordo destro e sinistro
	for (int i = 0; i < 3; i++)
	{
		gotoxy(40, 11 + i);
		cout << "|";
		gotoxy(79, 11 + i);
		cout << "|";
	}
	//scrittura titolo
	gotoxy(51, 12);
	cout << (char)17<<" L E G E N D S "<< (char)16;
	//scrittura sottotitolo
	gotoxy(42,16);
	cout << "BENVENUTO! per iniziare premi SPAZIO";
	//scrittura crediti
	gotoxy(18, SCREEN_HEIGHT - 1);
	cout << "Camellini Alessandro - Chierici Thomas - Mora Rainer - Norcia Andrea - Tomasetti Samuele";
	//attesa pulsante spazio
	gotoxy(57, 21);
	while(1)
	{
		char ch = getch();
		if(ch == 32)
		{
			break;
		}
	}
	gotoxy(57, 21);
	for (int i = 0; i < 3; i++)
	{
		cout<<". ";
		_sleep(500);
	}
}

int classSelector()
{
	gotoxy(40, 3);
	for (int i = 0; i <= 40; i++)
	{
		cout << "-";
	}
	gotoxy(40, 7);
	for (int i = 0; i <= 40; i++)
	{
		cout << "-";
	}
	for (int i = 0; i < 3; i++)
	{
		gotoxy(40, 4 + i);
		cout << "|";
		gotoxy(80, 4 + i);
		cout << "|";
	}
	gotoxy(48, 5);
	cout << "SCEGLI IL TUO PERSONAGGIO";

	for(int i = 11; i < SCREEN_HEIGHT; i++)
	{
		gotoxy(41,i);
		cout<<"|";
		gotoxy(79,i);
		cout<<"|";
	}
	for(int i = 0; i < SCREEN_WIDTH; i++)
	{
		gotoxy(i,10);
		cout<<"-";
	}
	for(int i = 0; i < SCREEN_WIDTH; i++)
	{
		gotoxy(i,14);
		cout<<"-";
	}
	for(int i = 0; i < SCREEN_WIDTH; i++)
	{
		gotoxy(i,17);
		cout<<"-";
	}
	for(int i = 0; i < SCREEN_WIDTH; i++)
	{
		gotoxy(i,27);
		cout<<"-";
	}

	gotoxy(15,12);
	cout<<"1 = "<<className[0][0]<<endl;
	gotoxy(6,19);
	cout<<"HP:\t"<<classData[0][0]<<endl;
	gotoxy(6,21);
	cout<<"Attacco:\t"<<classData[0][1]<<endl;
	gotoxy(6,23);
	cout<<"Difesa:\t"<<classData[0][2]<<endl;
	gotoxy(6,25);
	cout<<"Super:\t"<<className[1][0];

	gotoxy(53,12);
	cout<<"2 = "<<className[0][1]<<endl;
	gotoxy(51,19);
	cout<<"HP:\t\t"<<classData[1][0]<<endl;
	gotoxy(51,21);
	cout<<"Attacco:\t"<<classData[1][1]<<endl;
	gotoxy(51,23);
	cout<<"Difesa:\t"<<classData[1][2]<<endl;
	gotoxy(51,25);
	cout<<"Super:\t"<<className[1][1];

	gotoxy(94,12);
	cout<<"3 = "<<className[0][2]<<endl;
	gotoxy(89,19);
	cout<<"HP:\t\t"<<classData[2][0]<<endl;
	gotoxy(89,21);
	cout<<"Attacco:\t"<<classData[2][1]<<endl;
	gotoxy(89,23);
	cout<<"Difesa:\t"<<classData[2][2]<<endl;
	gotoxy(89,25);
	cout<<"Super:\t"<<className[1][2];

	gotoxy(53,1);
	cout<<"F => INTERAGISCI";

	int player=0;
	int coordX[3] = {20,60,100};
	gotoxy(coordX[player],9);
	cout<<(char)31;
	gotoxy(0,0);
	while (1)
	{
		char key = getch();
		if(key == 'a')
		{
			if (player > 0)
			{
				gotoxy(coordX[player], 9);
				cout<<" ";
				player--;
				gotoxy(coordX[player], 9);
				cout<<(char)31;
			}
		}
		if(key == 'd')
		{
			if (player < 2)
			{
				gotoxy(coordX[player], 9);
				cout<<" ";
				player++;
				gotoxy(coordX[player], 9);
				cout<<(char)31;
			}
		}
		if(key == 'f')
		{
			break;
		}
		gotoxy(0,0);
	}

	gotoxy(53,1);
	cout<<"                   ";
	gotoxy(57,1);

	for (int i = 0; i < 3; i++)
	{
		cout<<". ";
		_sleep(500);
	}
	return player;
}

void nickMenu()
{
	gotoxy(40, 10);
	for (int i = 0; i < 40; i++)
	{
		cout << "-";
	}
	//lato inferiore
	gotoxy(40, 16);
	for (int i = 0; i < 40; i++)
	{
		cout << "-";
	}
	//bordo destro e sinistro
	for (int i = 0; i < 5; i++)
	{
		gotoxy(40, 11 + i);
		cout << "|";
		gotoxy(79, 11 + i);
		cout << "|";
	}
	gotoxy((SCREEN_WIDTH / 2) - (className[0][op].size() / 2) - 1, 8);
	cout << className[0][op];
	gotoxy((SCREEN_WIDTH / 2) - 14,12);
	cout<<"SCEGLI IL NOME DEL TUO EROE"<<endl;
	gotoxy(48,14);
	cout<<"--> ";
	getline(cin, nickname);
}

void writeTitle(string title)
{
	gotoxy((SCREEN_WIDTH / 2) - (title.size() / 2) - 1, 0);
	cout << title;
}

void writeActions(string a1, string a2, string a3)
{
	gotoxy(5,19);
	cout<<a1;
	gotoxy(5,21);
	cout<<a2;
	gotoxy(5,23);
	cout<<a3;
	gotoxy(0,0);
}

int action(int max)
{
	while(1)
	{
		char ch = getch();
		if(ch >= 49 && ch <= max + 48)
		{
			return ch - 48;
		}
	}
}

void cleanTextSpace()
{
	for (int i = 2; i < 18; i++)
	{
		gotoxy(0,i);
		for(int j = 0; j < 96; j++)
		{
			cout<<" ";
		}
	}
	gotoxy(0,2);
}

void cleanActions()
{
	gotoxy(5,19);
	cout<<"                                                       ";
	gotoxy(5,21);
	cout<<"                                                       ";
	gotoxy(5,23);
	cout<<"                                                       ";
	gotoxy(0,0);
}

void loading()
{
	gotoxy(57, 17);
	for (int i = 0; i < 3; i++)
	{
		cout<<". ";
		_sleep(500);
	}
}

void init()
{
	for (int i = 23; i > 0; i--)
	{
		gotoxy(SCREEN_WIDTH - i, 8);
		cout<<"=";
	}
	gotoxy(0,18);
	for (int i = 0; i < 3; i++)
	{
		cout<<"---"<<endl;
		cout<<i+1<<" >"<<endl;
	}
	cout<<"---"<<endl;
	updateAll();
	cleanActions();
	cleanTextSpace();
}

void trader()
{
	string items[6] ={"POZIONE DIFESA", "POZIONE SALUTE", "FORGIA", "ESPERIENZA", "MOSSA FINALE", "ESCI dal MERCATO"};
    int costi[6] = {35, 40, 30, 10, 60, 0};

    system("cls");
    gotoxy(57,1);
    cout<<"MERCANTE";
    gotoxy(56,2);
    cout<<"==========";

    for (int i = 0; i < 15;i+=7) //contorno items
    {
        gotoxy(SCREEN_WIDTH/4-10,7+i);
        cout<<"---------------------";
        gotoxy(SCREEN_WIDTH/4-10,8+i);
        cout<<"|                   |";
        gotoxy(SCREEN_WIDTH/4-10,9+i);
        cout<<"---------------------";

        gotoxy(3*SCREEN_WIDTH/4-10,7+i);
        cout<<"---------------------";
        gotoxy(3*SCREEN_WIDTH/4-10,8+i);
        cout<<"|                   |";
        gotoxy(3*SCREEN_WIDTH/4-10,9+i);
        cout<<"---------------------";
    }
    int c = 0;
    for (int i = 0; i < 6; i++) //scrittura items e costo
    {
        gotoxy(SCREEN_WIDTH/4-items[i].size()/2, 8+c);
        cout<<items[i];
        gotoxy(SCREEN_WIDTH/4-4,10+c);
        cout<<"Costo: "<<costi[i];
        i++;

        gotoxy(3*SCREEN_WIDTH/4-items[i].size()/2, 8+c);
        cout<<items[i];
        gotoxy(3*SCREEN_WIDTH/4-4,10+c);
        if(costi[i]!=0)
        {
            cout<<"Costo: "<<costi[i];
        }
        c+=7;
    }

	int selection = -1;	 //selected index
    int a = 0, b=0; //coordinate (0-1)(0-1-2)
    int coordX[2] = {30,90};
    int coordY[3] = {11,18,25};
    gotoxy(coordX[a], coordY[b]);
    cout<<(char)30;
    gotoxy(60,3);
    while(1)
    {
		gotoxy(SCREEN_WIDTH/2-6, 12); //stats
		cout<<"Vita: \t"<<hp<<"  ";
		gotoxy(SCREEN_WIDTH/2-6, 13);
		cout<<"Attacco: \t"<<att<<"  ";
		gotoxy(SCREEN_WIDTH/2-6, 14);
		cout<<"Difesa: \t"<<dif<<"  ";
		gotoxy(SCREEN_WIDTH/2-6, 15);
		cout<<"Finali: \t"<<ult<<"  ";
		gotoxy(SCREEN_WIDTH/2-6, 16);
		cout<<"Gemme: \t"<<cash<<"  ";
		gotoxy(SCREEN_WIDTH/2-6, 17);
		cout<<"XP: \t"<<xp<<"  ";
		gotoxy(SCREEN_WIDTH/2-8, 19);
		cout<<"---STATISTICHE---";
		gotoxy(SCREEN_WIDTH/2-8, 21);
		cout<<"F => INTERAGISCI";
		gotoxy(60,3);
        char key = getch();
        char arrow = 30;
        if(key == 'w')
        {
            if (b > 0)
            {
                gotoxy(coordX[a], coordY[b]);
                cout<<" ";
                b--;
                gotoxy(coordX[a], coordY[b]);
                cout<<arrow;
            }
        }
        if(key == 's')
        {
            if (b < 2)
            {
                gotoxy(coordX[a], coordY[b]);
                cout<<" ";
                b++;
                gotoxy(coordX[a], coordY[b]);
                cout<<arrow;
            }
        }
        if(key == 'a')
        {
            if (a > 0)
            {
                gotoxy(coordX[a], coordY[b]);
                cout<<" ";
                a--;
                gotoxy(coordX[a], coordY[b]);
                cout<<arrow;
            }
        }
        if(key == 'd')
        {
            if (a < 1)
            {
                gotoxy(coordX[a], coordY[b]);
                cout<<" ";
                a++;
                gotoxy(coordX[a], coordY[b]);
                cout<<arrow;
            }
        }
		if (key == 'f')
		{
			if(b == 0 && a == 0)
			{
				selection = 0;
			}
			if(b == 0 && a == 1)
			{
				selection = 1;
			}
			if(b == 1 && a == 0)
			{
				selection = 2;
			}
			if(b == 1 && a == 1)
			{
				selection = 3;
			}
			if(b == 2 && a == 0)
			{
				selection = 4;
			}
			if (b == 2 & a == 1)
			{
				selection == 5;
				break;
			}
		}
		switch (selection)
		{
			case 0:
				if (cash >= costi[selection])
				{
					dif += 15 + rand()%35;
					cash -= costi[selection];
				}
				break;
			case 1:
				if (cash >= costi[selection])
				{
					hp += 15 + rand()%35;
					if (hp >= 100)
					{
						hp = 100;
					}
					cash -= costi[selection];
				}
				break;
			case 2:
				if (cash >= costi[selection])
				{
					att += 15 + rand()%35;
					cash -= costi[selection];
				}
				break;
			case 3:
				if (cash >= costi[selection])
				{
					xp += 1 + rand()%20;
					cash -= costi[selection];
				}
				break;
			case 4:
				if (cash >= costi[selection])
				{
					ult++;
					cash -= costi[selection];
				}
				break;
		}
		selection = -1;
    }
	system("cls");
}

void chest()
{
	cleanActions();
	writeActions("APRI il FORZIERE","","");
	action(1);
	int e = rand()%8;
	cleanActions();
	cleanTextSpace();
	int gap;
	switch(e)
	{
		case 0:
			cout<<"hai trovato una pozione di SALUTE"<<endl;
			writeActions("BEVI","","");
			action(1);
			hp+= 15 + rand() % 30;
			if (hp > 100)
			{
				hp = 100;
			}
			updateAll();
			cleanTextSpace();
		break;
		case 1:
			cout<<"hai trovato una pozione di DIFESA"<<endl;
			writeActions("BEVI","","");
			action(1);
			dif += 15 + rand() % 25;
			updateAll();
			cleanTextSpace();
			break;

		case 2:
			cout<<"hai trovato una forgia, aumenta il tuo punteggio d'ATTACCO!"<<endl;
			writeActions("UTILIZZA","","");
			action(1);
			att += 15 + rand() % 25;

			updateAll();
			cleanTextSpace();
			break;
		case 3:
			cout<<"hai trovato una pozione MISTERIOSA, scopri di che cosa si tratta"<<endl;
			writeActions("BEVI","","");
			action(1);
			gap = rand()%15;
			if(att > gap)
			{
				att-= gap;
			}
			updateAll();
			cleanTextSpace();
			cout<<"sei stato molto sfortunato, hai perso "<<gap<<" punti attacco";
			break;
		case 4:
			cout<<"HAI TROVATO UNA MOSSA FINALE"<<endl;
			cout<<"sei stato molto fortunato"<<endl;
			writeActions("RISCATTA","","");
			action(1);
			ult++;
			updateAll();
			cleanTextSpace();
			break;
		default:
			cout<<"hai trovato delle GEMME"<<endl;
			cout<<"utilizzale per commerciare con i mercanti!"<<endl;
			writeActions("RISCATTA","","");
			action(1);
			cash += 5 + rand()%25;
			updateAll();
			cleanTextSpace();
			break;
	}
}

void randomExp()
{
	cleanActions();
	cleanTextSpace();
	cout<<"hai trovato dei punti ESPERIENZA, essi indicano il tuo prestigio nel mondo degli eroi"<<endl;
	writeActions("RISCATTA","","");
	action(1);
	xp += 15+rand()%25;
	updateAll();
}

void enemy(int e)
{
	writeActions("COMBATTI","","");
	action(1);
	int enemyHp = enemyData[0][e];
	int enemyAtt = enemyData[1][e];
	while (enemyHp > 0)
	{
		cout<<endl;
		cleanTextSpace();
		cout<<"il mostro davanti a te e' di tipo "<<enemyName[e]<<endl;
		cout<<"HP:"<<enemyHp<<"\t ATT:"<<enemyAtt<<endl;
		cleanActions();
		writeActions("ATTACCA", "SUBISICI","MOSSA FINALE");
		gotoxy(0,4);
		switch(action(3))
		{
			case 1:
				if(att > enemyHp)
				{
					att -= (enemyHp / 2);
					enemyHp = 0;
					cout<<"hai ucciso il mostro, verrai ricompensato con dei punti XP e un forziere            "<<endl;
					updateAll();
					chest();
					randomExp();
				}
				break;
			case 2:
				if(dif > enemyAtt)
				{
					dif -= enemyAtt;
				}
				else
				{
					dif-=enemyAtt;
					hp = hp - (0-dif);
					dif = 0;
				}
				att += (enemyAtt / 2);
				cout<<"hai subito un danno di "<<enemyAtt<<"hp, i tuoi punti attacco sono aumentati di"<<enemyAtt/2<<endl;
				updateAll();
				break;
			case 3:
				if(ult > 0)
				{
					cout<<"hai utilizzato la mossa finale! il mostro e' stato sconfitto e avrai una ricompensa"<<endl;
					enemyHp = 0;
					ult--;
					updateAll();
					chest();
					randomExp();
				}
				break;
		}
	}
}

int lvl0() //PRATO FIORITO
{
	gotoxy(0,2);
	cout<<"ciao "<<nickname<<", e benvenuto nell'isola. tanto tempo fa, in una delle scorse ere mitiche"<<endl;
	cout<<"uno strano sovrano governava il mondo con la sua magia. era un sovrano arrogante e solitario,"<<endl;
	cout<<"tanto che gli abitanti dell'isola gli diedero il nome di HERMETICO."<<endl;
	cout<<"gli abitanti disprezzavano l'hermetico, ci fu una guerra, una coalizione di tutte le specie"<<endl;
	cout<<"dell'isola contro il mostro. venne costruito un robot di nome AA che riusci' a ribaltarlo."<<endl;
	cout<<"con il corso del tempo, alcune voci si innalzarono sul fatto che il bufu fosse ancora vivo"<<endl;
	cout<<"\nla tua missione e' quella di partire per un viaggio, raggiungi i CONDOTTI CONFUSI per e cerca"<<endl;
	cout<<"la antica mappa: ti guidera' al tesoro dell'hermetico e finalmente scoprirai se e' vivo."<<endl;
	cout<<"\nti trovi in un prato, pieno di fiori. davanti a te hai qualche albero e hai 3 sentieri a"<<endl;
	cout<<"disposizione. il primo dall'aspetto sicuro porta in un bosco. il secondo prosegue a lungo,"<<endl;
	cout<<"mentre il terzo punta ad una landa desolata. quale scegli?"<<endl;
	writeActions("prendi il percorso a SINISTRA", "prendi il percorso DRITTO", "prendi il percorso a DESTRA");
	int scelta = action(3);

	cleanTextSpace();
	cleanActions();
	gotoxy(0,2);
	cout<<"complimenti per aver compiuto le tue prime mosse!"<<endl;
	cout<<"ecco a te 5XP di bonus!"<<endl;
	writeActions("RISCUOTI","","");
	action(1);
	xp += 5;
	return scelta;
}

void lvl1() //BOSCO BLATERANTE
{
	gotoxy(0,2);
	cout<<"hai percorso tutto il sentiero di sinistra e sei finito in un bosco, la vista si fa sempre"<<endl;
	cout<<"piu' difficile e l'atmosfera si fa cupa, e inizi ad intravedere un labirinto fatto di cespugli"<<endl;
	cout<<"in cui al centro c'e' una casa sull'albero, che sporge dalle siepi. "<<endl;
	cout<<"ricorda che devi raggiungere i condotti confusi per trovare la MAPPA del TESORO dell' HERMETICO"<<endl;
	cout<<"puoi decidere se OLTREPASSARE il labirinto di siepe oppure ESPLORARE al suo interno"<<endl;
	writeActions("ANDARE AVANTI e OLTREPASSARE la siepe", "ESPLORARE il LABIRINTO","");
	if (action(2) == 2)
	{
		cleanTextSpace();
		cleanActions();
		gotoxy(0,2);
		cout<<"complimenti, hai scelto la via piu' rischiosa. perdersi in un labirinto e' spaventoso ma"<<endl;
		cout<<"un avventuriero come te sa il fatto suo."<<endl;
		cout<<"il labirinto e' facile al suo interno e delle freccie indicano la direzione."<<endl;
		cout<<"\nhai trovaro l'ingresso della casa, sali la scala e in cima nella casetta trovi un forziere"<<endl;
		chest();
		cout<<"a questo punto non ci resta che uscire e proseguire per il sentiero"<<endl;
		writeActions("ESCI dal LABIRINTO","","");
		action(1);
	}
	cleanTextSpace();
	cleanActions();
	gotoxy(0,2);
	cout<<"proseguendo il cammino incontri un mostro, il primo mostro. "<<endl;
	cout<<"come puoi tu, eroe di quest'isola affrontare i mostri?"<<endl;
	cout<<"\npuoi affrontarli o con la L'ATTACCO SEMPLICE, utilizzando i propri punti ATTACCO e"<<endl;
	cout<<"DIFESA per sfidare i punti VITA del nemico, oppure puoi utilizzare le MOSSE FINALI."<<endl;
	cout<<"le MOSSE FINALI sono potenti incantesimi della quarta era in grado di annientare tutto"<<endl;
	cout<<"essendo tu un "<<className[0][op]<<" la FINALE della tua specie e' "<<className[1][op]<<endl;
	cout<<"RICORDA. non sprecare mosse finali, attualmente ne hai solo 1 e si trovano nei forzieri"<<endl;
	cout<<"\nil mostro davanti a noi e' un semplice zombi. essi hanno 40 punti VITA (hp)"<<endl;
	cout<<"se lo attacchi e i tuoi punti attacco sono maggiori dei suoi hp, allora ucciderai"<<endl;
	cout<<"il mostro ma perderai META' dei punti attacco utilizzati. se non ne hai abbastanza"<<endl;
	cout<<"sei costretto a subire un colpo, il quale si riflettera' sui tuoi punti DIFESA o VITA"<<endl;
	cout<<"nell'isola, ad ogni colpo subito i propri punti ATTACCO aumentano di meta' del danno',"<<endl;
	cout<<"permettendo di uccidere un mostro anche dopo aver subito qualche colpo"<<endl;
	enemy(0);
	cleanActions();
	cleanTextSpace();
	cout<<"uccidendo il primo mostro, la magia ti ha affidato la supervista."<<endl;
	cout<<"ora sei in grado di raggiungere i condotti confusi"<<endl;
	writeActions("RAGGIUNGI i CONDOTTI CONFUSTI","","");
	action(1);
}

void lvl2() //SPONDE
{
	gotoxy(0,2);
	cout<<"la strada che conduce alle sponde del saccheggio porta a un lago incantevole, dallo specchio"<<endl;
	cout<<"d'acqua limpido e sereno. al centro del lago sorge un'isola pittoresca, dominata da una casa"<<endl;
	cout<<"antica e misteriosa. l'isola e' circondata da fiori acquatici che si spandono come una coperta"<<endl;
	cout<<"colorata. l'acqua riluce al sole e riflette il cielo azzurro, creando un panorama mozzafiato."<<endl;
	cout<<"ll suono rilassante delle onde che lambiscono la riva invita a una pausa tranquilla per"<<endl;
	cout<<"ammirare la bellezza del luogo."<<endl;
	writeActions("NUOTARE verso il FONDO DEL LAGO", "VISITARE la CASA", "");
	switch (action(2))
	{
		case 1:
			cleanTextSpace();
			cleanActions();
			gotoxy(0,2);
			cout << "la tua curiosita' ti porta a visitare il fondo del lago, complimenti per il coraggio."<< endl;
			cout << "mentre stai nuotanto vedi una luce che attira la tua attenzione e decidi di controllare." << endl;
			cout << "CHE FORTUNA! hai trovato una chest. " << endl;
			chest();
			break;
		case 2:
			cleanTextSpace();
			cleanActions();
			gotoxy(0,2);
			cout << "decidi di andare a visitare la casa nel lago, in cerca di fortuna " << endl;
			cout << "OH NO! nella casa trovi una strega malvagia che decide di ingaggiarti. " << endl;
			enemy(2);
			break;
	}
	cleanTextSpace();
	cleanActions();
	gotoxy(0,2);
	cout << "complimenti, hai superato SPONDE del SACCHEGGIO, ora puoi proseguire il tuo percorso." << endl;
	writeActions("CONTINUA il CAMMINO","","");
	action(1);
}

void lvl3() //LANDE
{
    gotoxy(0,2);
    cout<<"la strada che si snoda attraverso le lande letali porta a una specie di fattoria"<<endl;
    cout<<"qui, i vasti campi sono coltivati con piante esotiche e insolite."<<endl;
    cout<<"i fiori sono di varie forme e dimensioni, alcuni emanano profumi inebrianti. "<<endl;
    cout<<"gli animali, si muovono liberamente, creando un'atmosfera allegra e vivace. "<<endl;
    cout<<"i contadini lavorano con passione, curando le colture e diffondendo l'amore per la terra."<<endl;
    cout<<"e' un luogo accogliente e invitante, dove il tempo sembra scorrere lentamente."<<endl;
    writeActions("ESPLORA la CASA", "ENTRA nei CAMPI di GRANO", "");
    switch (action(2))
    {
        case 1:
            cleanTextSpace();
            cleanActions();
            gotoxy(0,2);
            cout << ""<< endl;
            cout << "mentre ti avvicini, vedi una luce che provine dal tetto. entri e sali le scale..." << endl;
            cout << "vedi una creatura che sembra amichevole. ti avvicini...  " << endl;
            cout << "e' una chest, al suo interno troverai degli oggetti preziosi" << endl;
            chest();
			cout<<"uscendo dalla casa trovi tutti i contadini. c'e' anche un mercante"<<endl;
			writeActions("ACCEDI al MERCATO","PROSEGUI il CAMMINO","");
			if(action(2) == 1)
			{
				trader();
			}
			writeTitle(placeName[lvl]);
			init();
            break;
        case 2:
            cleanTextSpace();
            cleanActions();
            gotoxy(0,2);
            cout << "hai deciso di entrare nei campi di grano! " << endl;
            cout << "oh no! hai incontrato uno scheletro! decidi di affrontarlo..." << endl;
            enemy(1);
            break;
    }
    cleanTextSpace();
    cleanActions();
    gotoxy(0,2);
    cout << "complimenti, hai superato lande letali, ora puoi proseguire il tuo percorso." << endl;
	writeActions("CONTINUA il CAMMINO","","");
	action(1);
}

void lvl4() //CONDOTTI
{
	gotoxy(0,2);
	cout<<"dopo lunghe camminate e tante avventure sei finalmente giunto a CONDOTTI CONFUSI"<<endl;
	cout<<"davanti alla porta ci sono 2 mostri, probabilmente scagnozzi dell'hermetico"<<endl;
	enemy(1);
	cleanTextSpace();
	cout<<"ora arriva il secondo mostro. uccidi anche lui"<<endl;
	enemy(1);
	cleanTextSpace();
	cout<<"hai finalmente valicato il cancello, l'area si presenta come una vecchia miniera abbandonata"<<endl;
	cout<<"con alcune strutture in legno. qua a condotti c'e un mercante, di fianco alla casa principale"<<endl;
	cout<<"si narra che l'hermetico, tanto tempo fa, avesse colonizzato il territorio, creando un'avamposto"<<endl;
	cout<<"ora e' un' area inutilizzata ma nella casa principale, sono conservati ancora molti rottami e"<<endl;
	cout<<"potrebbe esserci la mappa."<<endl;
	cout<<"vuoi entrare direttamente a cercare la mappa, o preferisci trattare con il mercante?"<<endl;
	writeActions("CERCA la MAPPA", "MERCANTE","");
	if (action(2) == 2)
	{
		trader();
	}
	writeTitle(placeName[lvl]);
	init();
	cout<<"entrando nella casa si puo' subito notare il disordine, avrai bisogno di un po di tempo!"<<endl;
	writeActions("CERCA la MAPPA", "","");
	action(1);

	system("cls");
    gotoxy(52,1);
    cout<<"CASA ABBANDONATA";
    gotoxy(52,2);
    cout<<"================";

    for (int i = 0; i < 15;i+=7) //contorno items
    {
        gotoxy(SCREEN_WIDTH/4-10,7+i);
        cout<<"---------------------";
        gotoxy(SCREEN_WIDTH/4-10,8+i);
        cout<<"|                   |";
        gotoxy(SCREEN_WIDTH/4-10,9+i);
        cout<<"---------------------";

        gotoxy(3*SCREEN_WIDTH/4-10,7+i);
        cout<<"---------------------";
        gotoxy(3*SCREEN_WIDTH/4-10,8+i);
        cout<<"|                   |";
        gotoxy(3*SCREEN_WIDTH/4-10,9+i);
        cout<<"---------------------";
    }
	gotoxy(SCREEN_WIDTH/2-6, 20);
	cout<<"trova la mappa!"<<endl;
	gotoxy(SCREEN_WIDTH/2-8, 21);
	cout<<"F => INTERAGISCI";

	int selection = -1;	 //selected index
    int a = 0, b=0; //coordinate (0-1)(0-1-2)
    int coordX[2] = {30,90};
    int coordY[3] = {10,17,24};
    gotoxy(coordX[a], coordY[b]);
    cout<<(char)30;
	bool findMap = false;

	while(!findMap)
	{
		char key = getch();
        char arrow = 30;
        if(key == 'w')
        {
            if (b > 0)
            {
                gotoxy(coordX[a], coordY[b]);
                cout<<" ";
                b--;
                gotoxy(coordX[a], coordY[b]);
                cout<<arrow;
            }
        }
        if(key == 's')
        {
            if (b < 2)
            {
                gotoxy(coordX[a], coordY[b]);
                cout<<" ";
                b++;
                gotoxy(coordX[a], coordY[b]);
                cout<<arrow;
            }
        }
        if(key == 'a')
        {
            if (a > 0)
            {
                gotoxy(coordX[a], coordY[b]);
                cout<<" ";
                a--;
                gotoxy(coordX[a], coordY[b]);
                cout<<arrow;
            }
        }
        if(key == 'd')
        {
            if (a < 1)
            {
                gotoxy(coordX[a], coordY[b]);
                cout<<" ";
                a++;
                gotoxy(coordX[a], coordY[b]);
                cout<<arrow;
            }
        }
		if (key == 'f')
		{
			if(b == 0 && a == 0)
			{
				selection = 0;
			}
			if(b == 0 && a == 1)
			{
				selection = 1;
			}
			if(b == 1 && a == 0)
			{
				selection = 2;
			}
			if(b == 1 && a == 1)
			{
				selection = 3;
			}
			if(b == 2 && a == 0)
			{
				selection = 4;
			}
			if (b == 2 & a == 1)
			{
				selection = 5;
			}
		}
		switch (selection)
		{
			case -1:
				break;
			case 3:
				findMap = true;
				gotoxy(coordX[a]-4,coordY[b]-4);
				cout << "MAPPA!"<<endl;
				getch();
				break;
			default:
				gotoxy(coordX[a]-4,coordY[b]-4);
				cout << "rottami"<<endl;
				break;
		}
		selection = -1;
	}
	system("cls");
	writeTitle(placeName[lvl]);
	init();
	cout<<"ora che hai trovato la mappa, non ti resta che seguirla e cosi' giungerai"<<endl;
	cout<<"al tesoro dell'hermetico. c'e' un solo problema: la mappa si puo' leggere"<<endl;
	cout<<"solo nelle scaglie di quarzo. qua vicino dovrebbe esserci un luogo adatto"<<endl;
	cout<<"raggiungi quindi i boschi TERROSI, dove un'accogliente popolazione ti aiutera'"<<endl;
	cout<<endl<<"per terra trovi una collana, speriamo ti porti fortuna!"<<endl;
	writeActions("INDOSSA la COLLANA","GETTALA VIA","");
	if (action(2) == 1)
	{
		xp *= 2;
		updateAll();
		cleanActions();
		cleanTextSpace();
		cout<<"i tuoi punti esperienza si sono RADDOPPIATI!"<<endl;
		cout<<"deve essere una collana con qualche incantesimo elfico"<<endl;
	}
	else
	{
		cleanActions();
		cleanTextSpace();
	}
	cout<<endl;
	cout<<"ora non ti resta che arrivare ai boschi TERROSI, dove poi potrai visionare"<<endl;
	cout<<"la mappa sulle scaglie di quarzo dei terrosi"<<endl;
	writeActions("CONTINUA il CAMMINO","","");
	action(1);
	system("cls");
	loading();
	writeTitle("sottolivello: BOSCHI TERROSI");
	init();
	cout<<"nei boschi terrosi bisogna fare attenzione: l'aria scarseggia e le possibilita'"<<endl;
	cout<<"di perdersi sono molte. dopo un lungo cammino giungi al castello, dove la popolazione"<<endl;
	cout<<"terrosa e' molto accogliente. per usare la piastra di quarzo, devi dare loro 5 gemme e 40 xp"<<endl;
	cout<<"se non disponi di 5 gemme e 40 xp, devi sconfiggere i 2 scheletri che si aggirano, gli elfi"<<endl;
	cout<<"te ne saranno grati"<<endl;
	writeActions("PAGA e VISIONA la MAPPA","SCONFIGGI gli SCHELETRI","");
	switch(action(2))
	{
		case 1:
			if (cash >= 5 && xp >= 40)
			{
				cash-=5;
				xp-=40;
				updateAll();
				break;
			}
			else
			{
				cleanActions();
				cleanTextSpace();
				cout<<"non disponi della moneta richiesta, dovrai combattere"<<endl;
			}
		case 2:
			cleanActions();
			cleanTextSpace();
			enemy(1);
			cleanTextSpace();
			cout<<"ora arriva il secondo mostro. uccidi anche lui"<<endl;
			enemy(1);
			break;
	}
	cleanActions();
	cleanTextSpace();
	cout<<"visionando la mappa ti rendi conto che, per arrivare al tesoro dell'hermetico bisogna"<<endl;
	cout<<"costeggiare il FIUME FIUMOSO. innanzitutto dovrai uscire dal bosco e dirigerti ai territori terrosi"<<endl;
	cout<<"successivamente dovrai decidere se passare sul fianco SINISTRO del FIUME o sul fianco DESTRO"<<endl;
	cout<<endl<<"a sinistra troverai: ROVINE di AA, APPRODO AVVENTURATO e LA TORRE"<<endl;
	cout<<"a destra troverai: VULCANO VASTOSO, CASTELLO CORRETTO e SABBIE SUDATE"<<endl;
	cout<<endl<<"ora non ti resta che proseguire, la scelta avverra' piu tardi"<<endl;
	writeActions("CONTINUA il CAMMINO","","");
	action(1);
}

int lvl5() //TERRITORI
{
	gotoxy(0,2);
	cout<<"emergendo dai condotti confusi, si giunge ai territori terrosi, una vasta distesa di terre"<<endl;
	cout<<"selvagge e incontaminate. le colline scoscese e gli altipiani coperti di erba  alta creano"<<endl;
	cout<<"un paesaggio maestoso e imponente. qui, la natura selvaggia regna sovrana, con animali"<<endl;
	cout<<"imponenti che vagano liberamente. le rocce sporgenti e le gole profonde aggiungono un elemento"<<endl;
	cout<<"di sfida al paesaggio. e' un luogo di bellezza maestosa e selvaggia, che richiama l'avventura e"<<endl;
	cout<<"l'esplorazione."<<endl;
	writeActions("CACCIARE", "ESPLORA l'AMBIENTE", "");
	switch (action(2))
	{
		case 1:
			cleanTextSpace();
			cleanActions();
			gotoxy(0,2);
			cout << "ti rendi conto di essere affamamato, quindi decidi di andare a caccia. noti nel terreno una" << endl;
			cout << "rientranza, sicuramente la tana di un animale, cosi' decidi di addentrarti per cacciarlo." << endl;
			cout << "dall'oscurita' esce una strega cattiva. devi combattere " << endl;
			enemy (2);
			break;
		case 2:
			cleanActions();
			cleanTextSpace();
			cout << "rimasto senza fiato per il paesaggio stupendo decidi di esplorare la radura, trovi piante, fiori" << endl;
			cout << "sorgenti ed ogni tipo di bellezza naturale, ma ad incuriosirti e' una profonda gola dove sembra " << endl;
			cout << "esserci gia' passato qualcuno. ti addentri e trovi un piccolo rifugio abbandonato, probabilmente" << endl;
			cout << "quello di uno sventurato esploratore. quest'ultimo deve aver lasciato tutto quello che " << endl;
			cout << "possedeva, comprese due chest, CHE FORTUNA!" << endl;
			chest();
			chest();
			break;
	}
	cleanActions();
	cleanTextSpace();
	cout<<"qui trovi un terroso (abitante locale) che ti vende alcune pozioni"<<endl;
	writeActions("ACQUISTA POZIONI","","");
	if(action(1) == 1)
	{
		trader();
		system("cls");
		writeTitle(placeName[lvl]);
		init();
	}
	cleanActions();
	cleanTextSpace();
	cout << "finalmente sei riuscito ad uscire, ora puoi continuare il tuo cammino godendoti il paesaggio." << endl;
	cout << "l'ultima scelta che ti rimane da fare e' scegliere quale sentiero percorrere." << endl;
	writeActions("percorso di SINISTRA","percorso di DESTRA","");
	int selection = action(2) - 1;
	system("cls");
    gotoxy(51,1);
    cout<<"SCEGLI il PERCORSO";
    gotoxy(51,2);
    cout<<"==================";

	for(int i = 4; i < SCREEN_HEIGHT;i++)
	{
		gotoxy(58,i);
		cout<<"|  |";
	}

	gotoxy(50,28);
	cout<<"PREMI F PER SCEGLIERE"<<endl;

	for (int i = 0; i < 15;i+=7) //contorno items
    {
        gotoxy(SCREEN_WIDTH/4-10,7+i);
        cout<<"---------------------";
        gotoxy(SCREEN_WIDTH/4-10,8+i);
        cout<<"|                   |";
        gotoxy(SCREEN_WIDTH/4-10,9+i);
        cout<<"---------------------";

        gotoxy(3*SCREEN_WIDTH/4-10,7+i);
        cout<<"---------------------";
        gotoxy(3*SCREEN_WIDTH/4-10,8+i);
        cout<<"|                   |";
        gotoxy(3*SCREEN_WIDTH/4-10,9+i);
        cout<<"---------------------";
    }
	int c = 0;
    for (int i = 0; i < 3; i++) //scrittura items e costo
    {
        gotoxy(SCREEN_WIDTH/4-placeName[i+6].size()/2, 8+c);
        cout<<placeName[i+6];

        gotoxy(3*SCREEN_WIDTH/4-placeName[i+9].size()/2, 8+c);
        cout<<placeName[i+9];
        c+=7;
    }

	int coordX[2] = {30,90};
	gotoxy(coordX[selection],28);
	cout<<(char)30;
	while(1)
	{
		char key = getch();
		if(key == 'a')
        {
            if (selection > 0)
            {
                gotoxy(coordX[selection], 28);
                cout<<" ";
                selection--;
                gotoxy(coordX[selection], 28);
                cout<<(char)30;
            }
        }
        if(key == 'd')
        {
            if (selection < 1)
            {
                gotoxy(coordX[selection], 28);
                cout<<" ";
                selection++;
                gotoxy(coordX[selection], 28);
                cout<<(char)30;
            }
        }
		if(key == 'f')
		{
			break;
		}
		gotoxy(0,0);
	}
	return selection+1;
}

void lvl6() //ROVINE DI AA
{
	gotoxy(0,2);
	cout<<"ti ritrovi in un'antica citta'� in rovina, ricoperta da edifici collassati"<<endl;
	cout<<"e colonne decrepite. qui, la storia si fonde con la natura che avanza, muschi e piante"<<endl;
	cout<<"insinuano tra le crepe delle mura. l'acqua riluce al sole e riflette il cielo azzurro,"<<endl;
	cout<<"creando un panorama mozzafiato."<<endl;
	cout<<"\nesplorare le sovine di AA significa immergersi in "<<endl;
	cout<<"un mondo dimenticato e svelare segreti sepolti nel tempo."<<endl;
	cout<<endl<<"questo robot uccise l'hermetico tanto tempo fa, adesso lui e' in silezio"<<endl;
	writeActions("PERCORRI la STRADA", "VISITA le ROVINE", "");
	switch (action(2))
	{
		case 1:
			cleanActions();
			cleanTextSpace();
			cout << "continuando per la strada, una struttura altissima ti appare davanti..."<< endl;
			cout << "e' un robot! fortunatamente, è spento. ti avvicini all'immensa struttura "<<endl;
			cout<<"e vedi due lettere scritte sul piede: 'AA' . girando intorno al robot..." << endl;
			cout << "\n...trovi una chest!" << endl;
			chest();
			break;
		case 2:
			cleanActions();
			cleanTextSpace();
			cout << "decidi di andare a visitare le rovine, in cerca di fortuna " << endl;
			cout << "OH NO! nella casa trovi uno zombie che ti vuole mangiare il cervello. "<<endl;
			cout<<"e' il momento di mettere in campo quello che hai imparato! " << endl;
			break;
	}
	cleanActions();
	cleanTextSpace();
	cout << "complimenti, hai superato le rovine "<<endl;
	writeActions("PROSEGUI","","");
	action(1);
}

void lvl7() //APPRODO
{
	gotoxy(0,2);
	cout<<"approdo avventurato e' un vivace porto situato lungo una costa affascinante,"<<endl;
	cout<<"abbracciato dalle acque cristalline dell'oceano. "<<endl;
	cout<<"Le barche a vela colorate e i pescherecci dondolano dolcemente sulle onde mentre i marinai, "<<endl;
	cout<<"equipaggiati con le loro armature ,si preparano per le avventure che li attendono."<<endl;
	cout<<"\ni profumi salmastri e l'aria fresca del mare avvolgono il molo "<<endl;
	cout<<"mentre i gabbiani volteggiano nell'azzurro cielo sopra di esso."<<endl;
	cout<<"qui puoi trovare armi e armature, cibo prelibato e strumenti magici. "<<endl;
	cout<<"\nl'atmosfera e' frizzante e festosa, animata dal chiacchiericcio degli avventurieri che "<<endl;
	cout<<"scambiano storie mozzafiato  econsigli su come affrontare le prossime sfide."<<endl;
	writeActions("VISITA le BANCARELLE", "ENTRA nel TEMPIO CINESE", "");
	switch (action(2))
	{
		case 1:
			cleanTextSpace();
			cleanActions();
			gotoxy(0,2);
			cout << "le persone in questa citta' sono buone e disponibili,"<< endl;
			cout << "visto che da poco c'e' stato il capodanno cinese, ti regalano due casse!" << endl;
			chest();
			cleanTextSpace();
			cout<<"apri la seconda chest"<<endl;
			chest();
			break;
		case 2:
			cleanTextSpace();
			cleanActions();
			gotoxy(0,2);
			cout << "entri nel tempio, dentro non c'e' luce.'" << endl;
			cout << "OH NO! Hai incontrato una strega malvagia che ti attacca!" << endl;
			enemy (2);
			break;
	}
	cleanActions();
	cleanTextSpace();
	cout<<"dalle bancarelle trovi anche il mercante cinese, ti va di dare un'occhiata a quello che vende?"<<endl;
	writeActions("SI","NO","");
	if (action(2) == 1)
	{
		trader();
		system("cls");
		writeTitle(placeName[lvl]);
		init();
	}
	else
	{
		cleanActions();
		cleanTextSpace();
	}
	cout << "complimenti, hai superato approdo avventurato, ora puoi proseguire il tuo percorso."<<endl;
	cout <<"non ti resta altro che raggiunere LA TORRE dove un potente STREGONE ti aspetta"<<endl;
	writeActions("RAGGIUNGI la TORRE","","");
	action(1);
	lvl = 8;
}

void miniBoss(string title)
{
	bool game;
	do
	{
		game = false;
		int shot = 25;
		int pos = SCREEN_HEIGHT/2 -1;
		system("cls");
		writeTitle(title);
		updateAll();
		for (int i = 23; i > 0; i--)
		{
			gotoxy(SCREEN_WIDTH - i, 8);
			cout<<"=";
		}
		char you[4][4] ={
		{' ','(',')',' '},
		{'/','|','|',92},
		{' ','|','|',' '},
		{'-','-','-','-'}};

		bool changedPos = false;
		int ball1X = 0, ball1Y = 0, ball2X = 0, ball2Y = 0;

		for(int i=0; i<4; i++)
		{
			for(int j = 0; j < 4;j++)
			{
				gotoxy(16+j, pos+i);
				cout<<you[i][j];
			}
		}

		while(shot > 0)
		{
			if(kbhit())
			{
				char key = getch();
				if(key=='w')
				{
					if(pos > 3 )
					{
						for(int i=0; i<4; i++)
						{
							for(int j = 0; j < 4;j++)
							{
								gotoxy(16+j, pos+i);
								cout<<' ';
							}
						}
						pos-=4;
						changedPos = true;
					}
				}
				if(key=='s')
				{
					if(pos < SCREEN_HEIGHT-8 )
					{
						for(int i=0; i<4; i++)
						{
							for(int j = 0; j < 4;j++)
							{
								gotoxy(16+j, pos+i);
								cout<<' ';
							}
						}
						pos+=4;
						changedPos = true;
					}
				}
			}

			_sleep(15);
			ball1X--;
			if(ball1X == -1)
			{
				gotoxy(0,ball1Y);
				cout<<"   ";
				ball1X = 80;
				ball1Y = 5+rand()%20;
				shot--;
			}
			else
			{
				gotoxy(ball1X+1,ball1Y);
				cout<<"   ";
			}
			gotoxy(ball1X,ball1Y);
			cout<<"[--"<<endl;

			ball2X--;
			if(ball2X == -1)
			{
				gotoxy(0,ball2Y);
				cout<<"   ";
				ball2X = 50;
				ball2Y = 5+rand()%20;
				shot--;
			}
			else
			{
				gotoxy(ball2X+1,ball2Y);
				cout<<"   ";
			}
			gotoxy(ball2X,ball2Y);
			cout<<"[--"<<endl;


			if (ball1X == 20 &&  (ball1Y == pos || ball1Y == pos +1|| ball1Y == pos +2|| ball1Y == pos +3))
			{
				game = true;
			}

			if (ball2X == 20 &&  (ball2Y == pos || ball2Y == pos +1|| ball2Y == pos +2|| ball2Y == pos +3))
			{
				game = true;
			}


			gotoxy(SCREEN_WIDTH-22,10);
			cout<<"Colpi Mancanti: "<<shot<<" "<<endl;

			if(changedPos)
			{
				for(int i=0; i<4; i++)
				{
					for(int j = 0; j < 4;j++)
					{
						gotoxy(16+j, pos+i);
						cout<<you[i][j];
					}
				}
			}
			if (game)
			{
				system("cls");
				gotoxy(0,0);
				cout<<"HAI PERSO, RITENTA!";
				getch();
				loading();
				break;
			}
		}
	 }while(game);

}

void lvl8() //LA TORRE
{
	gotoxy(0,2);
	cout<<"finalmente sei riuscito giungere ai piedi della grande torre. "<<endl;
	cout<<"la maestosita' di questa torre mette ansia e all'interno si cela un malvagio stregone."<<endl;
	writeActions("ENTRA nella TORRE","","");
	action(1);
	cleanActions();
	cleanTextSpace();
	cout<<"all'ingresso della torre trovi uno zombie che tenta di fermarti"<<endl;
	enemy(0);
	cout<<endl;
	cout<<"ora devi salire le scale, ma aspetta, c'e' un trader, potrebbe tornarti utile"<<endl;
	writeActions("SALI le SCALE","ACQUISTA con il MERCANTE","");
	if (action(2)==2)
	{
		trader();
		system("cls");
		writeTitle(placeName[lvl]);
		init();
	}
	cleanActions();
	cleanTextSpace();
	cout<<"piano piano riesci a salire tutte le scale, arrivando in cima"<<endl;
	cout<<endl<<"lo stregone era girato di spalle, era vestito di una tonaca blu ed aveva in mano "<<endl;
	cout<<"una bottiglia di benzina. poi lo stregone si gira e ti guarda negli occhi"<<endl;
	cout<<endl<<"-SO PERCHE' SEI QUI"<<endl;
	writeActions("NO, NON LO SAI","TI PREGO NON FARMI DEL MALE","");
	action(2);
	cleanActions();
	cleanTextSpace();
	cout<<"-SEI QUI PERCHE' HAI BISOGNO DI RUBARE L'INCANTESIMO PER APRIRE IL REGNO"<<endl;
	_sleep(1000);
	cout<<"-TU CREDI CHE L'HERMETICO SIA MORTO, MA MOLTE FORZE SI MUOVONO ATTUALMENTE"<<endl;
	_sleep(1000);
	cout<<"-E SE CREDI CHE IO TI DARO' QUELLA PERGAMENA, TI SBAGLI, DOVRAI PRENDERTELA"<<endl;
	cout<<endl<<endl<<"lo stregone tentera' di colpirti lanciando delle pietre, cerca di fuggire"<<endl;
	writeActions("COMBATTI lo STREGONE","","");
	action(1);
	miniBoss("boss: lo STREGONE");
	system("cls");
	writeTitle(placeName[lvl]);
	init();
	cout<<"sconfiggendo il boss hai ottenuto la pergamena."<<endl;
	writeActions("CONSERVA la PERGAMENA e vai AVANTI","","");
	action(1);
}

void lvl9() //vulcano vastoso
{
	gotoxy(0,2);
	cout << "la strada che si dirige verso vulcano vastoso porta a un vulcano attivo e imponente, con fiumi" << endl;
	cout << "di lava che si riversano lungo le sue pendici. il suolo e' caldo e tremante, emanando un calore" << endl;
	cout << "intenso. i bagliori rossi e arancioni si riflettono sulle rocce circostanti, creando" << endl;
	cout << "un'atmosfera incandescente. sono presenti fumarole e geysers che eruttano vapore e gas, rendendo" << endl;
	cout << "il paesaggio ancora piu' surreale. vulcano vastoso e' un luogo pericoloso ma affascinante, che" << endl;
	cout << "richiama l'energia primordiale della Terra." << endl;
	writeActions("ADDENTRARTI verso il centro del VULCANO", "ATTRAVERSARE il lago di LAVA", "");
	switch (action(2))
	{
		case 1:
			cleanActions();
			cleanTextSpace();
			cout << "scegli di visitare il centro del vulcano, scelta davvero coraggiosa. comici ad addentrarti "<< endl;
			cout << "seguendo un antico percorso, ormai distrutto dalle continue eruzioni. la luce comincia a " << endl;
			cout << "scarseggiare e il caldo si fa incessante ma finalmente noti una luce alla fine del tunnel." << endl;
			cout << "dinalmente sei giunto al centro del vulcano, un immensa distesa di magma con temperature" << endl;
			cout << "altissime ma il tuo occhio scorge una piccola rientranza sulla parete." << endl;
			cout << "e' un antico tesoro abbandonato, la lava ha distrutto la maggior parte di esso ma fortunatamente" << endl;
			cout << "una chest si e' salvata. meglio aprirla velocemente prima di morire per il calore!"<<endl;
			chest();
			break;
		case 2:
			cleanActions();
			cleanTextSpace();
			cout << "il vulcano sembra molto pericoloso e decidi di circumnavigarlo, scelta saggia." << endl;
			cout << "durante il percorso pero' trovi un enorme distesa di lava situata dove sorgeva un' antica citta':" << endl;
			cout << "NAPOLI. l'unica opzione e' fare oltrepassarlo tra i rimasugli galleggianti ma e' molto pericoloso." << endl;
			cout << "con qualche graffio e bruciatura riesci a superarlo e nell'altra sponda trovi uno dei pochissimi" << endl;
			cout << "sopravvissuti della catastrofe. e' un mercante, ora puoi commerciare con quest'ultimo ma attento!" << endl;
			cout << "le truffe in questo luogo erano all' ordine del giorno." << endl;
			writeActions("CONTRATTA con il MERCANTE", "", "");
			action(1);
			trader();
			system("cls");
			writeTitle(placeName[lvl]);
			init();
			cout<<"cosa succede? si sentono rumori strani, potrebe essere un nemico"<<endl;
			enemy(0);
			break;
	}
	cleanTextSpace();
	cleanActions();
	gotoxy(0,2);
	cout << "complimenti, hai superato il vulcano ora puoi proseguire il tuo percorso." << endl;
	writeActions("PROSEGUI","","");
	action(1);
}

void lvl10() //castello corretto
{
	gotoxy(0,2);
	cout<<"dopo aver superato il vulcano vastoso, si giunge a castello corretto:"<<endl;
	cout<<"una fortezza imponente. le mura di pietra grigia si ergono maestose, con torri slanciate"<<endl;
	cout<<"e merlature affilate. il castello e' avvolto da un'atmosfera di grandezza e intrighi"<<endl;
	cout<<"esplorare il castello significa immergersi nella storia e nella nobilta' di un tempo passato."<<endl;
	cout<<endl<<"si narra che l'hermetico usasse questo castello per le sue attivita'"<<endl;
	cout<<"decidi di entrare nel castello."<<endl;
	writeActions("ESPLORA il CASTELLO", "", "");
	action(1);
	cleanActions();
	cleanTextSpace();
	cout<<"al suo interno il castello e' molto buio e dall'aspetto tenebroso"<<endl;
	cout<<"si sentono rumori strani, potrebbe essere una strega"<<endl;
	writeActions("AVANZA LENTAMENTE", "", "");
	action(1);
	cleanActions();
	cleanTextSpace();
	cout<<"le supposizioni erano corrette, devi combattere la strega"<<endl;
	enemy(2);
	cleanActions();
	cleanTextSpace();
	cout<<"percorrendo le stanze del castello, hai trovato un passaggio segreto"<<endl;
	cout<<"esso porta dall'altra parte del FIUME FIUMOSO, passando per un ponte che"<<endl;
	cout<<"l'hermetico fece costruire secoli fa"<<endl;
	cout<<endl<<"cosa vuoi fare: andare verso LA TORRE (PERCORSO di SINSTRA), o proseguire nel PERCORSO di DESTRA"<<endl;
	writeActions("PASSAGGIO SEGRETO per LA TORRE", "CONTINUA il CAMMINO passando per il CASTELLO","");
	switch (action(2))
	{
		case 1:
			system("cls");
			writeTitle("sottolivello: FIUME FIUMOSO");
			init();
			cout << "hai scelto il passaggio segreto: esso consiste in un sottile ponte di legno" << endl;
			cout << "lo percorri tutto cautamente e trovi dall'altra parte un mercante" << endl;
			writeActions("INTERAGISCI con il MERCANTE","","");
			action(1);
			trader();
			writeTitle("sottolivello: FIUME FIUMOSO");
			init();
			cout<<"il mercante ti regala una cassa gratuita"<<endl;
			chest();
			cout<<"sei finalmente arrivato a LA TORRE, dove dovrai sconfiggere il potente STREGONE"<<endl;
			writeActions("ACCEDI alla TORRE","","");
			action(1);
			lvl = 8;
			break;
		case 2:
			cleanActions();
			cleanTextSpace();
			cout << "passando per il castello arrivi al mercante del castello" << endl;
			cout << "vuoi comprare qualcosa?" << endl;
			writeActions("SI","NO","");
			if (action(2) == 1)
			{
				trader();
				system("cls");
				writeTitle(placeName[lvl]);
				init();
			}
			else
			{
				cleanActions();
				cleanTextSpace();
			}
			cout<<"uscendo dal castello trovi una chest"<<endl;
			chest();
			cout<<"ora non ti resta altro che uscire dal castello ed arrivare a SABBIE SUDATE, dove dovrai sconfiggere"<<endl;
			cout<<"il MOSTRO DELLE ACQUE"<<endl;
			writeActions("AVANZA","","");
			action(1);
			lvl = 11;
			break;
	}

}

void lvl11() //SABBIE SUDATE
{
	gotoxy(0,2);
	cout<<"finalmente sei riuscito raggiungere le spiaggie. la localita' e' di tipo paradisiaco"<<endl;
	cout<<"e tutto e' avvolto da un fantastico oceano."<<endl;
	cout<<"quella che sembra un luogo carino e' pero' turbato dal MOSTRO delle ACQUE"<<endl;
	writeActions("DIRIGITI verso LA SPIAGGIA","","");
	action(1);
	cleanActions();
	cleanTextSpace();
	cout<<"sulla sabbia trovi uno zombie africano che tenta di fermarti"<<endl;
	enemy(0);
	cout<<"ora devi andare a cercare ma aspetta, c'e' un trader, potrebbe tornarti utile"<<endl;
	writeActions("CERCA il MOSTRO","ACQUISTA con il MERCANTE","");
	if (action(2)==2)
	{
		trader();
		system("cls");
		writeTitle(placeName[lvl]);
		init();
	}
	cleanActions();
	cleanTextSpace();
	cout<<"quello di cui abbiamo bisogno e' la formula dell'incantesimo per aprire il regno dell'hermetico"<<endl;
	cout<<"e solo i piu' potenti mostri o stregoni la possiedono"<<endl;
	cout<<endl<<"dopo un po' di cammino finalmente giungi davanti a lui"<<endl;
	cout<<"si presenta come un grosso polipo con tentacoli"<<endl;
	cout<<endl<<"-SO PERCHE' SEI QUI"<<endl;
	writeActions("NO, NON LO SAI","TI PREGO NON FARMI DEL MALE","");
	action(2);
	cleanActions();
	cleanTextSpace();
	cout<<"-SEI QUI PERCHE' HAI BISOGNO DI RUBARE L'INCANTESIMO PER APRIRE IL REGNO"<<endl;
	_sleep(1000);
	cout<<"-TU CREDI CHE L'HERMETICO SIA MORTO, MA MOLTE FORZE SI MUOVONO ATTUALMENTE"<<endl;
	_sleep(1000);
	cout<<"-E SE CREDI CHE IO TI DARO' QUELLA PERGAMENA, TI SBAGLI, DOVRAI PRENDERTELA"<<endl;
	cout<<endl<<endl<<"il mostro tentacolo tentera' di colpirti lanciando delle pietre, cerca di fuggire"<<endl;
	writeActions("COMBATTI il MOSTRO TENTACOLO","","");
	action(1);
	miniBoss("boss: il MOSTRO DELLE ACQUE");
	system("cls");
	writeTitle(placeName[lvl]);
	init();
	cout<<"sconfiggendo il boss hai ottenuto la pergamena."<<endl;
	writeActions("CONSERVA la PERGAMENA e vai AVANTI","","");
	action(1);
}

int lvl12()  //COLLE COLLOSO
{
	gotoxy(0,2);
	cout<<"tutte le strade si ricongiungono a COLLE COLLOSO, una montagna imponente e maestosa"<<endl;
	cout<<"di un vasto panorama. i picchi innevati brillano sotto il sole, mentre la flora "<<endl;
	cout<<"e la fauna uniche si adattano all''ambiente montano. sentieri tortuosi "<<endl;
	cout<<"e ponti sospesi conducono attraverso gole profonde e foreste lussureggianti."<<endl;
	cout<<endl<<"colle colloso e' il punto di incontro delle avventure, dove eroi provenienti da ogni parte si"<<endl;
	cout<<"ritrovano per condividere le loro storie e prepararsi alla prossima grande sfida."<<endl;
	writeActions("SCALA la MONTAGNA", "ENTRA nella FORESTA", "CERCA un VILLAGGIO");
	switch (action(3)) {
		case 1:
			cleanActions();
			cleanTextSpace();
			cout << "dopo diverse ore, riesci ad arrivare sopra la montagna. da qui riesci a vedere le altre " << endl;
			cout << "strade che si ricongiungono tutte qui." << endl;
			cout << "si sta facendo notte e davanti a te c'e' una casa abbandonata, meglio entrare e riposare un po'" << endl;
			writeActions("RIPOSA","","");
			action(1);
			cleanActions();
			cleanTextSpace();
			_sleep(1000);
			cout << "ti addormenti..." << endl;
			for (int i = 0; i < 10; i++)
			{
				int nota = rand() % 7; // Valore casuale tra 0 e 6
				switch (nota) {
					case 0:
						Beep(261, 500); // C4
						break;
					case 1:
						Beep(293, 500); // D4
						break;
					case 2:
						Beep(329, 500); // E4
						break;
					case 3:
						Beep(349, 500); // F4
						break;
					case 4:
						Beep(392, 500); // G4
						break;
					case 5:
						Beep(440, 500); // A4
						break;
					case 6:
						Beep(493, 500); // B4
						break;
				}
		    }
			_sleep(1000);
			cout << "e' notte fonda e un rumore ti ha svegliato. senti che non sei solo in casa..." << endl;
			cout << "qualcuno sta salendo le scale. sei pronto a combattere." << endl;
			cout << "e' un mercante, anche lui come te, stava cercando un riparo per la notte." << endl;
			cout<< "vuoi contrattare con lui?"<<endl;
			writeActions("SI","NO","");
			if (action(2) == 1)
			{
				trader();
				system("cls");
				writeTitle(placeName[lvl]);
				init();
			}
			else
			{
				cleanActions();
				cleanTextSpace();
			}
			cout<<"nel frattempo, uno zombie e uno scheletro si avvicinano"<<endl;
			enemy(0);
			cleanTextSpace();
			cout<<"ora arriva lo scheletro"<<endl;
			enemy(1);
			break;
		case 2:
			cleanActions();
			cleanTextSpace();
			cout << "entri nella foresta in cerca di cibo dato che sei affamato." << endl;
			cout << "meglio muoversi perche' la notte si avvicina..." << endl;
			cout << "e' scesa l'oscurita' e non hai trovato niente da mangiare e" << endl;
			cout << "con dei legni, costruisci una capanna che ti ospitera' per la notte..." << endl;
			cout << "mentre raccogli i legni, una creatura ti attacca! sei pronto per affrontarla?" << endl;
            enemy (0);
		break;
		case 3:
			cleanActions();
			cleanTextSpace();
			cout << "decidi di cercare un villaggio per la notte." << endl;
			cout << "incontri un mercante che sta cercando un posto per dormire, prosegui la tua ricerca con lui." << endl;
			cout << "trovi una casa abbandonata." << endl;
			writeActions("ENTRA", "", "");
			action(1);
			cleanActions();
			cleanTextSpace();
			cout << "CHE FORTUNA! hai trovato due chest!" << endl;
			chest();
			chest();
			cleanTextSpace();
			cout<<"il mercante ti chiede se vuoi comprare qualcosa da lui"<<endl;
			writeActions("ACCETTA l'AFFARE","RISPONDI di NO RINGRAZIANDO","");
			if (action(2) == 1)
			{
				trader();
				system("cls");
				writeTitle(placeName[lvl]);
				init();
			}
        break;
	}
	cleanActions();
	cleanTextSpace();
	cout << "dopo esserti riposato, riesci ad uscire da colle colloso. l'avventura ti aspetta" << endl;
	cout << "l'ultima scelta che ti rimane da fare e' scegliere quale sentiero percorrere." << endl;
	cout << "la strada si divide nuovamente a destra e a sinistra, fortunatamente incotri un tizio"<<endl;
	cout<<"potrebbe darti indicazioni sul percorso migliore"<<endl;
	writeActions("PARLA","SCEGLI da SOLO","");
	if (action(2)==1)
	{
		cleanActions();
		cleanTextSpace();
		cout<<"-ciao, mi chiamo steve, cosa ci fai qua?"<<endl;
		writeActions("STO CERCANDO il REGNO DELL'HERMETICO", "MI TROVO QUA PER CASO", "MI SONO PERSO");
		action(3);
		cleanActions();
		cleanTextSpace();
		cout<<"-ho capito, deve essere stato duro arrivare fino a qui"<<endl;
		cout<<endl<<"-questa zona e' particolare, vige ancore l'influenza dell'hermetico: le persone sono"<<endl;
		cout<<" stupide e cattive"<<endl;
		cout<<endl<<"-per quanto riguarda la strada, io ti consiglio di passare per la grotta, non ci sono mostri"<<endl;
		writeActions("VA BENE","","");
		action(1);
	}
	cleanActions();
	cleanTextSpace();
	cout<<"devi scegliere il percorso."<<endl;
	writeActions("SINISTRA => GROTTA","DESTRA => PASSO PISQUANO","");
	return(action(2));
}

void lvl13() //LA GROTTA
{
	gotoxy(0,2);
	cout<<"la strada che conduce alla grotta porta a un sistema di caverne intricate e misteriose."<<endl;
	cout<<"Le pareti di roccia sono illuminate da cristalli lucenti e pozze d'acqua"<<endl;
	cout<<"cristallina riflettono la luce. gli echi delle gocce d'acqua che cadono creano una melodia "<<endl;
	cout<<"rilassante mentre si esplorano le profondità sotterranee."<<endl;
	writeActions("VISITA le CAVERNE", "ENTRA nel VILLAGGIO", "");
	switch (action(2))
	{
		case 1:
			cleanActions();
			cleanTextSpace();
			cout << "decidi di esplorare le caverne, la musica ti accompagna per tutta la tua esplorazione"<< endl;
			cout << "CHE FORTUNA! hai trovato 3 Chest!" << endl;
			chest();
			chest();
			chest();
			break;
		case 2:
			cleanActions();
			cleanTextSpace();
			cout << "decidi di visitare il villaggio che dista qualche chilometro..." << endl;
			cout << "OH NO! nel tuo cammino hai incontrato una strega malvagia che ti attacca!" << endl;
			enemy (2);
			break;
	}
	cleanActions();
	cleanTextSpace();
	cout<<"hai raggiunto il villaggio vicino alla grotta, c'e' un mercante. ti serve qualcosa?"<<endl;
	writeActions("SI","NO","");
	if (action(2) == 1)
	{
		trader();
		system("cls");
		writeTitle(placeName[lvl]);
		init();
	}
	else
	{
		cleanActions();
		cleanTextSpace();
	}
	cout << "congratulazioni eroe, hai completato tantissime sfide, ora non ti resta altro che entrare nel"<<endl;
	cout<<"regno dell'hermetico"<<endl;
	writeActions("ANDIAMO","","");
	action(1);
}

void lvl14() //Pisquano
{
    gotoxy(0,2);
    cout<<"benvenuto a passo pisquano,"<<endl;
    cout<<"un sentiero che si snoda tra dirupi rocciosi e gole profonde."<<endl;
    cout<<"il passaggio e' angusto e rischioso, richiedendo agilità e destrezza per"<<endl;
    cout<<"superare gli ostacoli naturali. "<<endl;
    cout<<"ora devi fare la tua scelta."<<endl;
    writeActions("SCALA la MONTAGNA", "CERCA una VIA SICURA", "");
    switch (action(2))
    {
        case 1:
			cleanActions();
            cleanTextSpace();
            cout << "hai raggiunto la cima della montagna"<< endl;
            cout << "davanti a te ci sono due mostri. preparati al combattimento" << endl;
            enemy (1);
			cleanActions();
			cleanTextSpace();
			cout<<"ora che hai distrutto il primo, tocca al secondo"<<endl;
            enemy (2);
            break;
        case 2:
			cleanActions();
            cleanTextSpace();
            cout << "hai scelto la strada piu' sicura e tranquilla." << endl;
            cout << "CHE FORTUNA! hai trovato due chest!" << endl;
            chest();
			chest();
            break;
    }
    cleanActions();
    cleanTextSpace();
    cout<<"nel cammino trovi un mercante, ti va di dare un'occhiata a quello che vende?"<<endl;
    writeActions("SI","NO","");
    if (action(2) == 1)
    {
        trader();
        system("cls");
        writeTitle(placeName[lvl]);
        init();
    }
	cleanActions();
    cleanTextSpace();
    cout << "congratulazioni eroe, hai completato tantissime sfide, ora non ti resta altro che entrare nel"<<endl;
	cout<<"regno dell'hermetico"<<endl;
	writeActions("ANDIAMO","","");
	action(1);
}

void boss(string title)
{
	int hpBase = hp, difBase = dif;
	bool game;
	do
	{
		hp = hpBase;
		dif = difBase;
		game = false;
		system("cls");
		writeTitle("PREMI UN TASTO PER INIZIARE");
		getch();
		loading();
		system("cls");
		for (int i = 4; i <= 93; i++)
		{
			gotoxy(i,2);
			cout<<"-"<<endl;
		}

		for (int i = 4; i <= 93; i++)
		{
			gotoxy(i,27);
			cout<<"-"<<endl;
		}
		for (int i = 3;i < 27; i++)
		{
			gotoxy(4,i);
			cout<<"|";
			gotoxy(93,i);
			cout<<"|";
		}
		game = false;
		writeTitle(title);
		updateAll();
		for (int i = 23; i > 0; i--)
		{
			gotoxy(SCREEN_WIDTH - i, 8);
			cout<<"=";
		}
		char you[4][4] ={
		{' ','(',')',' '},
		{'/','|','|',92},
		{' ','|','|',' '},
		{'-','-','-','-'}};

		int posX = SCREEN_WIDTH/2-3;
		int posY = SCREEN_HEIGHT/2;

		for(int i=0; i<4; i++)
		{
			for(int j = 0; j < 4;j++)
			{
				gotoxy(posX+j, posY+i);
				cout<<you[i][j];
			}
		}

		int shot =  500;
		int ball1X[4] = {0,0,0,0}, ball1Y[4] = {4,4,4,4}, ball2X[3] = {6,6,6} ,ball2Y[3] = {0,0,0};
		int delay = 25;
		string rabbia;
		bool given = false;
		while(shot > 0)
		{
			if(kbhit())
			{
				char key = getch();
				if (key == 'w')
				{
					if(posY > 4 )
					{
						for(int i=0; i<4; i++)
						{
							for(int j = 0; j < 4;j++)
							{
								gotoxy(posX+j, posY+i);
								cout<<' ';
							}
						}
						posY-=4;
					}
				}
				if (key == 's')
				{
					if(posY < 20)
					{
						for(int i=0; i<4; i++)
						{
							for(int j = 0; j < 4;j++)
							{
								gotoxy(posX+j, posY+i);
								cout<<' ';
							}
						}
						posY+=4;
					}
				}
				if (key =='a')
				{
					if(posX > 7 )
					{
						for(int i=0; i<4; i++)
						{
							for(int j = 0; j < 4;j++)
							{
								gotoxy(posX+j, posY+i);
								cout<<' ';
							}
						}
						posX-=4;
					}
				}
				if (key == 'd')
				{
					if(posX < 87 )
					{
						for(int i=0; i<4; i++)
						{
							for(int j = 0; j < 4;j++)
							{
								gotoxy(posX+j, posY+i);
								cout<<' ';
							}
						}
						posX+=4;
					}
				}
				for(int i = 0; i < 4; i++)
				{
					for(int j = 0; j < 4;j++)
					{
						gotoxy(posX+j, posY+i);
						cout<<you[i][j];
					}
				}
			}

			if(shot <= 300 && shot > 200)
			{
				delay = 16;
			}
			if(shot <= 200 && shot > 100)
			{
				delay = 14;
			}
			else if (shot <= 100)
			{
				delay = 12;
			}
			_sleep(delay);

			if(shot == 150 && !given)
			{
				given = true;
				dif += 50;
			}

			for (int i = 0; i < 4; i++) //For da basso a alto
			{
				ball1Y[i]--;
				if (ball1Y[i] == 3)
				{
					gotoxy(ball1X[i],4);
					cout<<" ";
					ball1X[i] = 5 + rand()%88;
					ball1Y[i] = 26;
					shot--;
				}
				else
				{
					gotoxy(ball1X[i],ball1Y[i]+1);
					cout<<" ";
				}
				gotoxy(ball1X[i],ball1Y[i]);
				cout<<(char)30<<endl;

				if((ball1X[i] >= posX && ball1X[i] <= posX+3) && (ball1Y[i] >= posY && ball1Y[i] <= posY+3))
				{
					if(dif >= 10)
					{
						dif-=5;
					}
					else if (dif > 0 && dif < 10)
					{
						dif = 0;
					}
					else
					{
						hp-= 5;
						if (hp <= 0)
						{
							game = true;
						}
					}

					ball1Y[i] = 4;

					for(int z=0; z<4; z++)
					{
						for(int j = 0; j < 4;j++)
						{
							gotoxy(posX+j, posY+z);
							cout<<you[z][j];
						}
					}
				}
			}

			for(int i = 0; i < 3; i++) //for da destra a sinistra
			{
				ball2X[i]--;
				if(ball2X[i] == 5)
				{
					gotoxy(6,ball2Y[i]);
					cout<<" ";
					ball2Y[i] = 3 + rand()%24;
					ball2X[i] = 92;
					shot--;
				}
				else
				{
					gotoxy(ball2X[i]+1,ball2Y[i]);
					cout<<" ";
				}
				gotoxy(ball2X[i],ball2Y[i]);
				cout<<(char)17<<endl;

				if((ball2X[i] >= posX && ball2X[i] <= posX+3) &&(ball2Y[i] >= posY && ball2Y[i] <= posY+3))
				{
					if(dif >= 10)
					{
						dif-=5;
					}
					else if (dif > 0 && dif < 10)
					{
						dif = 0;
					}
					else
					{
						hp-= 5;
						if (hp <= 0)
						{
							game = true;
						}
					}

					ball2X[i] = 92;

					for(int z=0; z<4; z++)
					{
						for(int j = 0; j < 4;j++)
						{
							gotoxy(posX+j, posY+z);
							cout<<you[z][j];
						}
					}
				}
			}

			if (game)
			{
				system("cls");
				gotoxy(0,0);
				cout<<"HAI PERSO, RITENTA!";
				getch();
				loading();
				break;
			}

			updateAll();
			gotoxy(SCREEN_WIDTH-22,10);
			cout<<"Colpi Mancanti: "<<shot<<" "<<endl;

			switch(delay)
			{
				case 25:
					rabbia = "I  ";
					break;
				case 16:
					rabbia = "II ";
					break;
				case 14:
					rabbia = "III";
					break;
				case 12:
					rabbia = "IV " ;
					break;
				default:
					break;
			}
			gotoxy(SCREEN_WIDTH-22,11);
			cout<<"Livello Rabbia: "<<rabbia<<endl;
		}
	} while (game);
	getch();
}

void lvl15() //HERMETICO
{
	gotoxy(0,2);
    cout<<"carissimo "<<nickname<<", hai compiuto imprese folli arrivando fino qua"<<endl;
	cout<<"inidipendetemente dal percorso che hai scelto e le minaccie che hai incontrato"<<endl;
	cout<<"il tuo livello di prestigio su questa terra e' aumentato."<<endl<<endl;
	cout<<"sei in possesso dell'incantesimo per aprire il regno, non ti resta altro che diventare ricco"<<endl;
	writeActions("PRONUNCIA la FORMULA davanti alla porta del REGNO","","");
	action(1);
	cleanActions();
	cleanTextSpace();
	cout<<"ottos eiretam ert olos;"<<endl;
	_sleep(1000);
	cout<<"ossomorp ognev;"<<endl;
	_sleep(1000);
	cout<<"ebbav e;"<<endl;
	_sleep(1000);
	cout<<endl;
	cout<<"fu cosi' che il portone si apri'..."<<endl;
	cout<<"\nl'hermetico era li addormentato, indossava una felpa nera e un cappellino verde"<<endl;
	cout<<"rubagli il tesoro senza che si svegli"<<endl;
	writeActions("RUBA il TESORO","","");
	action(1);
	cleanActions();
	cleanTextSpace();
	cout<<"fai piano. l'hermetico si e' svegliato!"<<endl;
	_sleep(1000);
	cout<<"-CHI OSA INTERROMPERMI MENTRE STUDIO?"<<endl;
	_sleep(1000);
	cout<<"-SAPPI CHE NON SONO TONTO"<<endl;
	writeActions("SCUSA non lo SAPEVO","TRANQUILLO","ME ne VADO");
	action(3);
	cleanActions();
	cleanTextSpace();
	cout<<"-ADESSO TI PICCHIO"<<endl;
	_sleep(1000);
	cout<<"-VIENI A FARE IL DURO CON ME"<<endl;
	cout<<endl<<"vuoi sfidare l'hermetico?"<<endl;
	writeActions("ACCETTA","ACCETTA","ACCETTA");
	action(3);
	cleanActions();
	cleanTextSpace();
	cout<<"gli dei ti regalano 10 punti di difesa, ti serviranno per sopravviere all'hermetico"<<endl;
	writeActions("RISCATTA e VAI AVANTI","","");
	action(1);
	dif += 10;
	string title = "final boss: " + nickname + " vs HERMETICO";
	boss(title);
	ult++;
	system("cls");
	loading();
	writeTitle(placeName[lvl]);
	init();
	cout<<"sei riuscito a non farti sconfiggere e hai ottenuto una super. adesso l'hermetico e' tuo amico"<<endl;
	cout<<"e condivide con te il tesoro. sei stato un coraggioso eroe"<<endl;
	writeActions("FINISCI il GIOCO","","");
	action(1);
	cleanActions();
	cleanTextSpace();
	cout<<"non e' questo il finale che vuoi, beh allora uccidi l'heremtico e salva"<<endl;
	cout<<"l'intero villaggio. utilizza la mossa finale ottenuta sconfiggendolo"<<endl;
	writeActions("UCCIDI", "LASCIA in VITA","");
	if(action(2) == 1)
	{
		ult--;
		updateAll();
	}
	cleanActions();
	cleanTextSpace();
	cout<<"indipendentemente da quello che hai fatto, la terra di LEGENDS ora e' tua"<<endl;
	cout<<nickname<<" grazie a te oggi, quest'isola e' un posto migliore"<<endl;
	cout<<endl<<"e' tempo di concludere l'avventura facendo un riposino"<<endl;
	writeActions("DORMI","","");
	action(1);
}

void play()
{
	int next;
	nickname = "";
	launcher();
	system("cls");
	op = classSelector();
	system("cls");
	nickMenu();
	system("cls");
	loading();

	xp = 0;
	hp = classData[op][0];
	att = classData[op][1];
	dif = classData [op][2];
	ult = 1;
	cash = 10;
	lvl = 0;

	init();
	writeTitle(placeName[lvl]);
	next = lvl0();

	system("cls");
	loading();
	init();
	switch (next)
	{
		case 1:
			lvl = 1;
			writeTitle(placeName[lvl]);
			lvl1();
			break;
		case 2:
			lvl = 2;
			writeTitle(placeName[lvl]);
			lvl2();
			break;
		case 3:
			lvl = 3;
			writeTitle(placeName[lvl]);
			lvl3();
			break;
	}

	system("cls");
	loading();
	init();

	lvl = 4;
	writeTitle(placeName[lvl]);
	lvl4();

	system("cls");
	loading();
	init();

	lvl = 5;
	writeTitle(placeName[lvl]);
	next = lvl5();

	system("cls");
	loading();
	init();

	switch(next)
	{
		case 1:
			lvl = 6;
			writeTitle(placeName[lvl]);
			lvl6();

			system("cls");
			loading();
			init();

			lvl = 7;
			writeTitle(placeName[lvl]);
			lvl7();
			lvl = 8;
			break;
		case 2:
			lvl = 9;
			writeTitle(placeName[lvl]);
			lvl9();

			system("cls");
			loading();
			init();

			lvl = 10;
			writeTitle(placeName[lvl]);
			lvl10();
			break;
	}

	system("cls");
	loading();
	init();


	switch (lvl) //scelta tra 8 e 11
	{
		case 8:
			writeTitle(placeName[lvl]);
			lvl8();
			break;
		case 11:
			writeTitle(placeName[lvl]);
			lvl11();
			break;
	}

	system("cls");
	loading();
	init();

	lvl = 12;
	writeTitle(placeName[lvl]);
	next = lvl12();

	system("cls");
	loading();
	init();

	switch (next)
	{
		case 1:
			lvl = 13;
			writeTitle(placeName[lvl]);
			lvl13();
			break;
		case 2:
			lvl = 14;
			writeTitle(placeName[lvl]);
			lvl14();
			break;
	}

	system("cls");
	loading();
	init();

	lvl = 15;
	writeTitle(placeName[lvl]);
	lvl15();
}



int main()
{
	srand(unsigned(time(NULL)));
	int choice;
	do
	{
		play();
		system("cls");
		writeTitle("MENU FINALE");
		cleanTextSpace();
		cout<<"ciao, spero che il gioco ti sia piaciuto."<<endl;
		cout<<"puoi sempre rigiocarlo, oppure puoi giocare al minigioco finale"<<endl;
		cout<<endl<<"1. RIGIOCA"<<endl;
		cout<<"2. MINIGIOCO FINALE"<<endl;
		cout<<"3. ESCI"<<endl;
		cout<<endl<<"preoridina il capitolo successivo > L E G E N D S: le avventure con l'hemetico"<<endl;
		choice = action(3);
		if(choice == 2)
		{
			hp = 100;
			dif = 60;
			boss("MINIGIOCO FINALE");
		}
	} while(choice == 1);

	system("pause>nul");
}
