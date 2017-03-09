#include "label.h"
#include <TFile.h>
#include <TTree.h>
#include <TH1.h>
#include <TMath.h>
using namespace std;
void process(int s1 = 0, int s2 = 10, int s3 = 10)
{
	cout << " s1 = " << s1 << " s2 = " << s2 << " s3 = " << s3 << endl;
	TH1::SetDefaultSumw2();
	addchain(s1);


	int gNoff;
	int gMult;

	double rQaabc[7] = {};
	double wQaabc[7] = {};

	double rQab[7] = {};
	double wQab[7] = {};

	double rQac[7] = {};
	double wQac[7] = {};

	double rQ2[7] = {};
	double wQ2[7] = {};

	double rQ4[7] = {};
	double wQ4[7] = {};

	double rQ6[7] = {};
	double wQ6[7] = {};

	double rQ8[7] = {};
	double wQ8[7] = {};

	chV->SetBranchAddress("Noff", &gNoff);
	chV->SetBranchAddress("Mult", &gMult);

	chV->SetBranchAddress("wQaabc", &wQaabc[2]);
	chV->SetBranchAddress("wQab", &wQab[2]);
	chV->SetBranchAddress("wQac", &wQac[2]);

	chV->SetBranchAddress("wQ2", &wQ2[2]);
	chV->SetBranchAddress("wQ4", &wQ4[2]);
	chV->SetBranchAddress("wQ6", &wQ6[2]);
	chV->SetBranchAddress("wQ8", &wQ8[2]);

	for ( int n = 2; n < 7; n++ ) {
		chV->SetBranchAddress(Form("rQaabc%i", n), &rQaabc[n]);
		chV->SetBranchAddress(Form("rQab%i", n), &rQab[n]);
		chV->SetBranchAddress(Form("rQac%i", n), &rQac[n]);
		chV->SetBranchAddress(Form("rQ2%i", n), &rQ2[n]);
		chV->SetBranchAddress(Form("rQ4%i", n), &rQ4[n]);
		chV->SetBranchAddress(Form("rQ6%i", n), &rQ6[n]);
		chV->SetBranchAddress(Form("rQ8%i", n), &rQ8[n]);
	}

	TH1D * hMult = new TH1D("hMult", "hMult", 1000, -0.5, 999.5);
	TH1D * hNoff = new TH1D("hNoff", "hNoff", 1000, -0.5, 999.5);

	TH1D * hQaabc[7] = {};
	TH1D * hQab[7] = {};
	TH1D * hQac[7] = {};

	TH1D * hWQaabc[7] = {};
	TH1D * hWQab[7] = {};
	TH1D * hWQac[7] = {};

	TH1D * hQ2[7] = {};
	TH1D * hQ4[7] = {};
	TH1D * hQ6[7] = {};
	TH1D * hQ8[7] = {};
	TH1D * hWQ2[7] = {};
	TH1D * hWQ4[7] = {};
	TH1D * hWQ6[7] = {};
	TH1D * hWQ8[7] = {};

	for ( int n = 2; n < 7; n++ ) {
		hQaabc[n] = new TH1D(Form("hQaabc%i", n), Form("hQaabc%i", n), 600, -0.5, 599.5);
		hQab[n] = new TH1D(Form("hQab%i", n), Form("hQab%i", n), 600, -0.5, 599.5);
		hQac[n] = new TH1D(Form("hQac%i", n), Form("hQac%i", n), 600, -0.5, 599.5);

		hWQaabc[n] = new TH1D(Form("hWQaabc%i", n), Form("hWQaabc%i", n), 600, -0.5, 599.5);
		hWQab[n] = new TH1D(Form("hWQab%i", n), Form("hWQab%i", n), 600, -0.5, 599.5);
		hWQac[n] = new TH1D(Form("hWQac%i", n), Form("hWQac%i", n), 600, -0.5, 599.5);

		hQ2[n] = new TH1D(Form("hQ2%i", n), Form("hQ2%i", n), 600, -0.5, 599.5);
		hQ4[n] = new TH1D(Form("hQ4%i", n), Form("hQ4%i", n), 600, -0.5, 599.5);
		hQ6[n] = new TH1D(Form("hQ6%i", n), Form("hQ6%i", n), 600, -0.5, 599.5);
		hQ8[n] = new TH1D(Form("hQ8%i", n), Form("hQ8%i", n), 600, -0.5, 599.5);

		hWQ2[n] = new TH1D(Form("hWQ2%i", n), Form("hWQ2%i", n), 600, -0.5, 599.5);
		hWQ4[n] = new TH1D(Form("hWQ4%i", n), Form("hWQ4%i", n), 600, -0.5, 599.5);
		hWQ6[n] = new TH1D(Form("hWQ6%i", n), Form("hWQ6%i", n), 600, -0.5, 599.5);
		hWQ8[n] = new TH1D(Form("hWQ8%i", n), Form("hWQ8%i", n), 600, -0.5, 599.5);
	}

	double dQaabc[7][600] = {};
	double dQab[7][600] = {};
	double dQac[7][600] = {};

	double yQaabc[7][600] = {};
	double yQab[7][600] = {};
	double yQac[7][600] = {};

	double dQ2[7][600] = {};
	double dQ4[7][600] = {};
	double dQ6[7][600] = {};
	double dQ8[7][600] = {};
	double yQ2[7][600] = {};
	double yQ4[7][600] = {};
	double yQ6[7][600] = {};
	double yQ8[7][600] = {};

	unsigned int ievt = 0;
	if (s2!=s3) ievt = s2;

	while ( chV->GetEntry(ievt) ) {
		if ( !((ievt-s2)%100000) ) cout << "!! ievt = " << ievt << endl;
		if ( s2 == s3 ) ievt++;
		else ievt+= s3;
		if (gNoff >=600) continue;
		for ( int n = 3; n < 7; n++ ) {
			wQaabc[n] = wQaabc[2];
			wQab[n] = wQab[2];
			wQac[n] = wQac[2];
			wQ2[n] = wQ2[2];
			wQ4[n] = wQ4[2];
			wQ6[n] = wQ6[2];
			wQ8[n] = wQ8[2];
		}
		for ( int n = 2; n < 7; n++ ) {
			if ( TMath::IsNaN( rQaabc[n] ) ) continue;
			dQaabc[n][gNoff] += rQaabc[n];
			yQaabc[n][gNoff] += wQaabc[n];

			dQab[n][gNoff] += rQab[n];
			yQab[n][gNoff] += wQab[n];

			dQac[n][gNoff] += rQac[n];
			yQac[n][gNoff] += wQac[n];

			dQ2[n][gNoff] += rQ2[n];
			dQ4[n][gNoff] += rQ4[n];
			dQ6[n][gNoff] += rQ6[n];
			dQ8[n][gNoff] += rQ8[n];

			yQ2[n][gNoff] += wQ2[n];
			yQ4[n][gNoff] += wQ4[n];
			yQ6[n][gNoff] += wQ6[n];
			yQ8[n][gNoff] += wQ8[n];
		}
		hNoff->Fill(gNoff);
		hMult->Fill(gMult);
	}

	TFile * fwrite = new TFile(Form("%s/output_%i_%i.root", ftxt[s1], s2, s3), "recreate");
	for ( int n = 2; n < 7; n++ ) {
		hQaabc[n]->Write();
		hQab[n]->Write();
		hQac[n]->Write();

		hWQaabc[n]->Write();
		hWQab[n]->Write();
		hWQac[n]->Write();

		hQ2[n]->Write();
		hQ4[n]->Write();
		hQ6[n]->Write();
		hQ8[n]->Write();
		hWQ2[n]->Write();
		hWQ4[n]->Write();
		hWQ6[n]->Write();
		hWQ8[n]->Write();
	}
	hNoff->Write();
	hMult->Write();
}
