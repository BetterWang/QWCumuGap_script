#include "label.h"
#include "noff.h"
#include <TFile.h>
#include <TTree.h>
#include <TH1.h>

void bGetError(int s1 = 0, int s3 = 10)
{
	std::cout << "s1 = " << s1 << "\ts3 = " << s3 << std::endl;

	TFile *fr[50];
	for ( int i = 0; i <= s3; i++ ) {
		fr[i] = new TFile(Form("%s/output_%i_%i.root", ftxt[s1], i, s3));
	}

	double dCnR[50][7][20];

	// Get
	for ( int fn = 0; fn <= s3; fn++ ) {
		TFile * f = fr[fn];
		for ( int n = 2; n < 7; n++ ) {
			TH1D * h = (TH1D*) f->Get(Form("hCnR%i", n));
			for ( int i = 0; i < 20; i++ ) {
				dCnR[fn][n][i] = h->GetBinContent(i+1);
			}
		}
	}

	// Save
	TH1D * hCnR[n] = {};
	TH1D * hVnR[n] = {};

	for ( int n = 2; n < 7; n++ ) {
		hCnR[n] = (TH1D*) fr[s3]->Get(Form("hCnR%i", n));
		hVnR[n] = new TH1D(Form("hVnR%i", n), Form("hVnR%i", n), 20, 0, 20);
		for ( int i = 0; i < 20; i++ ) {
			double sumC = 0;
			for ( int fn = 0; fn < s3; fn++ ) {
				sumC += (dCnR[fn][n][i] - dCnR[s3][n][i]) * (dCnR[fn][n][i] - dCnR[s3][n][i]);
			}
			double errC = sqrt( sumC ) / s3;
			hCnR[n]->SetBinError(i+1, errC);
			double C = dCnR[s3][n][i];
			double V = 0;
			if ( C > 0 ) V = - pow(C, 1./4);
			else V = pow(-C, 1./4);
			double errV = fabs( errC*V/C/4.);
			hVnR[n]->SetBinContent(i+1, V);
			hVnR[n]->SetBinError(i+1, errV);
		}
	}

	// Write
	TFile * fwrite = 0;
	fwrite = new TFile(Form("%s/outputE.root", ftxt[s1]), "recreate");
	for ( int n = 2; n < 7; n++ ) {
		hCnR[n]->Write();
		hVnR[n]->Write();
	}
	fwrite->Close();
}
