/*
-----------------------------------------------------
  @Author: Marek Bielik		xbieli05@stud.fit.vutbr.cz
  @Author: Filip Gulan		xgulan00@stud.fit.vutbr.cz
  @Author: Filip Ježovica	xjezov01@stud.fit.vutbr.cz
  @Author: Luboš Matuška	xmatus29@stud.fit.vutbr.cz
  @Author: Eduard Rybár		xrybar04@stud.fit.vutbr.cz
-----------------------------------------------------
*/

/* instruction list - hlavickovy subor  */


/* JEDNA INSTRUKCIA */
typedef struct{
    int AKCIA;        // ** 1 > AKCIA AKA SA MA VYKONAT {int konstanta} : JMP, +,-,*,/,aloc,....
    void *ADDR_KDE;   // ** 2 > ADDR_KDE   > KAM SA MA UKLADAT nieco, pri jednoadresovych instrukciach sa pouziva univerzalne ostatne budu NULL!
    void *ADDR_PRVA;  // ** 3 > ADDR_PRVA  > ODKIAL sa cita 1 adresa
    void *ADDR_DRUHA; // ** 4 > ADDR_DRUHA > ODKIAL sa cita 2 adresa
} tInstrukcia;      // ** ::: vsetky adresy su typu void * >> pri pouzivani pouzi PRETYPOVANIE :::


/* toto je jeden prvok instrukcnej pasky {1 instrukcia + ukazatel na dalsiu} */
typedef struct tPrvokListu{
    struct tPrvokListu *dalsiPtr; // ukazatel na dalsiu instrukciu na paske > posledny ukazuje na NULL
    tInstrukcia Instrukcia;       // tu je ulozena cela instrukcia (struktura vid hore)
} *tPrvokListuPtr;


/* toto je cela INSTRUKCNA PASKA, vieme pristupit na aktivnu instrukciu, prvu a poslednu */
typedef struct{
    tPrvokListuPtr Aktivna;
    tPrvokListuPtr Prva;
    tPrvokListuPtr Posledna;
} tListInstrukcii;


/* GLOBALNA INSTRUKCNA PASKA ...*/
extern tListInstrukcii listok;


/* Deklaracia funkcii nad INSTRUKCNOU PASKOU */
void InitInstrList (tListInstrukcii *I_List);
void DestroyInstrList (tListInstrukcii *I_List);
void InstrInsert (tListInstrukcii *I_List, tInstrukcia DataOfInstr);
void InstrStart(tListInstrukcii *I_List);
void InstrGoto(tListInstrukcii *I_List, void *gotoAddr);
void InstrDalsia(tListInstrukcii *I_List);
void *InstrDajPosledPoz(tListInstrukcii *I_List);
void *InstrDajPoz(tListInstrukcii *I_List);
tInstrukcia *DajInstr(tListInstrukcii *I_List);
void NaplnIntr(int AKCIA, void *ADDR_KDE, void *ADDR_PRVA, void *ADDR_DRUHA);