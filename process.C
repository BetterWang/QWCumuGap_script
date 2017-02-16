#include "label.h"
#include "noff.h"
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

	int NCent = NCent8TeV4;
	const int * pCent = CentNoffCutPA8TeV4;

	int gNoff;
	int gMult;

	double rQaabc[7] = {};
	double wQaabc[7] = {};

	double rQab[7] = {};
	double wQab[7] = {};

	double rQac[7] = {};
	double wQac[7] = {};

	chV->SetBranchAddress("Noff", &gNoff);
	chV->SetBranchAddress("Mult", &gMult);

	chV->SetBranchAddress("wQaabc", &wQaabc[2]);
	chV->SetBranchAddress("wQab", &wQab[2]);
	chV->SetBranchAddress("wQac", &wQac[2]);

	for ( int n = 2; n < 7; n++ ) {
		chV->SetBranchAddress(Form("rQaabc%i", n), &rQaabc[n]);
		chV->SetBranchAddress(Form("rQab%i", n), &rQab[n]);
		chV->SetBranchAddress(Form("rQac%i", n), &rQac[n]);
	}

	TH1D * hMult = new TH1D("hMult", "hMult", 1000, -0.5, 999.5);
	TH1D * hNoff = new TH1D("hNoff", "hNoff", 1000, -0.5, 999.5);

	TH1D * hQaabc[7] = {};
	TH1D * hQab[7] = {};
	TH1D * hQac[7] = {};

	TH1D * hWQaabc[7] = {};
	TH1D * hWQab[7] = {};
	TH1D * hWQac[7] = {};

	TH1D * hCn[7] = {};

	for ( int n = 2; n < 7; n++ ) {
		hQaabc[n] = new TH1D(Form("hQaabc%i", n), Form("hQaabc%i", n), 600, -0.5, 599.5);
		hQab[n] = new TH1D(Form("hQab%i", n), Form("hQab%i", n), 600, -0.5, 599.5);
		hQac[n] = new TH1D(Form("hQac%i", n), Form("hQac%i", n), 600, -0.5, 599.5);

		hWQaabc[n] = new TH1D(Form("hWQaabc%i", n), Form("hWQaabc%i", n), 600, -0.5, 599.5);
		hWQab[n] = new TH1D(Form("hWQab%i", n), Form("hWQab%i", n), 600, -0.5, 599.5);
		hWQac[n] = new TH1D(Form("hWQac%i", n), Form("hWQac%i", n), 600, -0.5, 599.5);

		hCn[n] = new TH1D(Form("hCn%i", n), Form("hCn%i", n), 600, -0.5, 599.5);
	}

	double dQaabc[7][600] = {};
	double dQab[7][600] = {};
	double dQac[7][600] = {};

	double yQaabc[7][600] = {};
	double yQab[7][600] = {};
	double yQac[7][600] = {};

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
		}
		for ( int n = 2; n < 7; n++ ) {
			if ( TMath::IsNaN( rQaabc[n] ) ) continue;
			dQaabc[n][gNoff] += rQaabc[n];
			yQaabc[n][gNoff] += wQaabc[n];

			dQab[n][gNoff] += rQab[n];
			yQab[n][gNoff] += wQab[n];

			dQac[n][gNoff] += rQac[n];
			yQac[n][gNoff] += wQac[n];
		}
		hNoff->Fill(gNoff);
		hMult->Fill(gMult);
	}

	for ( int n = 2; n < 7; n++ ) {
		for ( int c = 0; c < 600; c++ ) {
			hQaabc[n]->SetBinContent(c+1, dQaabc[n][c]);
			hQab[n]->SetBinContent(c+1, dQab[n][c]);
			hQac[n]->SetBinContent(c+1, dQac[n][c]);

			hWQaabc[n]->SetBinContent(c+1, yQaabc[n][c]);
			hWQab[n]->SetBinContent(c+1, yQab[n][c]);
			hWQac[n]->SetBinContent(c+1, yQac[n][c]);
		}
	}

	// calculate cn{4}
	double dCn[7][600] = {};
	for ( int n = 2; n < 7; n++ ) {
		for ( int c = 0; c < 600; c++ ) {
			dCn[n][c] = dQaabc[n][c]/yQaabc[n][c] - 2*dQab[n][c]*dQac[n][c]/yQab[n][c]/yQac[n][c];
			hCn[n]->SetBinContent(c+1, dCn[n][c]);
		}
	}

	// rebin
	double dCnR[7][20] = {};
	for ( int n = 2; n < 7; n++ ) {
		for ( int c = 0; c <  NCent; c++ ) {
			double sum = 0;
			double weight = 0;
			for ( int m = pCent[c]; m < pCent[c+1]; m++ ) {
				if ( m > 600 ) continue;
				sum += dCn[n][c] * yQaabc[n][c];
				weight += yQaabc[n][c];
			}
			if ( weight > 0 ) sum /= weight;
			else sum = 0;
			dCnR[n][c] = sum;
		}
	}
	TH1D * hNoffR = new TH1D("hNoffR", "hNoffR", 20, 0, 20);
	for ( int c = 0; c < 20; c++ ) {
		int nevt = 0;
		for ( int m = pCent[c]; m < pCent[c+1]; m++ ) {
			nevt += hNoff->GetBinContent(m+1);
		}
		hNoffR->SetBinContent(c+1, nevt);
	}

	TH1D * hCnR[7];
	for ( int n = 2; n < 7; n++ ) {
		hCnR[n] = new TH1D(Form("hCnR%i", n), Form("hCnR%i", n), 20, 0, 20);
		for ( int c = 0; c < NCent; c++ ) {
			hCnR[n]->SetBinContent( c+1, dCnR[n][c] );
		}
	}


	TFile * fwrite = new TFile(Form("%s/output_%i_%i.root", ftxt[s1], s2, s3), "recreate");
	for ( int n = 2; n < 7; n++ ) {
		hQaabc[n]->Write();
		hQab[n]->Write();
		hQac[n]->Write();

		hWQaabc[n]->Write();
		hWQab[n]->Write();
		hWQac[n]->Write();

		hCn[n]->Write();
		hCnR[n]->Write();
	}
	hNoff->Write();
	hMult->Write();
	hNoffR->Write();
}
