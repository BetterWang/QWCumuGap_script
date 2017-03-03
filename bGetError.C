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
		fr[i] = new TFile(Form("%s/outputC_%i_%i.root", ftxt[s1], i, s3));
	}

	double dCnR[50][7][20];
	double dC4nR[50][7][20];
	double dC6nR[50][7][20];
	double dC8nR[50][7][20];

	// Get
	for ( int fn = 0; fn <= s3; fn++ ) {
		TFile * f = fr[fn];
		for ( int n = 2; n < 7; n++ ) {
			TH1D * h = (TH1D*) f->Get(Form("hCnR%i", n));
			TH1D * h4 = (TH1D*) f->Get(Form("hC4nR%i", n));
			TH1D * h6 = (TH1D*) f->Get(Form("hC6nR%i", n));
			TH1D * h8 = (TH1D*) f->Get(Form("hC8nR%i", n));
			for ( int i = 0; i < 20; i++ ) {
				dCnR[fn][n][i] = h->GetBinContent(i+1);
				dC4nR[fn][n][i] = h4->GetBinContent(i+1);
				dC6nR[fn][n][i] = h6->GetBinContent(i+1);
				dC8nR[fn][n][i] = h8->GetBinContent(i+1);
			}
		}
	}

	// Save
	TH1D * hCnR[7] = {};
	TH1D * hVnR[7] = {};
	TH1D * hC4nR[7] = {};
	TH1D * hV4nR[7] = {};
	TH1D * hC6nR[7] = {};
	TH1D * hV6nR[7] = {};
	TH1D * hC8nR[7] = {};
	TH1D * hV8nR[7] = {};

	for ( int n = 2; n < 7; n++ ) {
		hCnR[n] = (TH1D*) fr[s3]->Get(Form("hCnR%i", n));
		hC4nR[n] = (TH1D*) fr[s3]->Get(Form("hC4nR%i", n));
		hC6nR[n] = (TH1D*) fr[s3]->Get(Form("hC6nR%i", n));
		hC8nR[n] = (TH1D*) fr[s3]->Get(Form("hC8nR%i", n));
		hVnR[n] = new TH1D(Form("hVnR%i", n), Form("hVnR%i", n), 20, 0, 20);
		hV4nR[n] = new TH1D(Form("hV4nR%i", n), Form("hV4nR%i", n), 20, 0, 20);
		hV6nR[n] = new TH1D(Form("hV6nR%i", n), Form("hV6nR%i", n), 20, 0, 20);
		hV8nR[n] = new TH1D(Form("hV8nR%i", n), Form("hV8nR%i", n), 20, 0, 20);
		for ( int i = 0; i < 20; i++ ) {
			double sumC = 0;
			double sum4 = 0;
			double sum6 = 0;
			double sum8 = 0;
			for ( int fn = 0; fn < s3; fn++ ) {
				sumC += (dCnR[fn][n][i] - dCnR[s3][n][i]) * (dCnR[fn][n][i] - dCnR[s3][n][i]);
				sum4 += (dC4nR[fn][n][i] - dC4nR[s3][n][i]) * (dC4nR[fn][n][i] - dC4nR[s3][n][i]);
				sum6 += (dC6nR[fn][n][i] - dC6nR[s3][n][i]) * (dC6nR[fn][n][i] - dC6nR[s3][n][i]);
				sum8 += (dC8nR[fn][n][i] - dC8nR[s3][n][i]) * (dC8nR[fn][n][i] - dC8nR[s3][n][i]);
			}
			double errC = sqrt( sumC ) / s3;
			double err4 = sqrt( sum4 ) / s3;
			double err6 = sqrt( sum6 ) / s3;
			double err8 = sqrt( sum8 ) / s3;
			hCnR[n]->SetBinError(i+1, errC);
			hC4nR[n]->SetBinError(i+1, err4);
			hC6nR[n]->SetBinError(i+1, err6);
			hC8nR[n]->SetBinError(i+1, err8);

			double C = dCnR[s3][n][i];
			double V = 0;
			if ( C > 0 ) V = - pow(C, 1./4);
			else V = pow(-C, 1./4);
			double errV = fabs( errC*V/C/4.);
			hVnR[n]->SetBinContent(i+1, V);
			hVnR[n]->SetBinError(i+1, errV);

			double C4 = dC4nR[s3][n][i];
			double V4 = 0;
			if ( C4 > 0 ) V4 = - pow(C4, 1./4);
			else V4 = pow(-C4, 1./4);
			double errV4 = fabs( err4*V4/C4/4.);
			hV4nR[n]->SetBinContent(i+1, V4);
			hV4nR[n]->SetBinError(i+1, errV4);

			double C6 = dC6nR[s3][n][i];
			double V6 = 0;
			if ( C6 > 0 ) V6 = pow(C6/4., 1./6);
			else V6 = -pow(-C6/4., 1./6);
			double errV6 = fabs( err6*V6/C6/6.);
			hV6nR[n]->SetBinContent(i+1, V6);
			hV6nR[n]->SetBinError(i+1, errV6);

			double C8 = dC8nR[s3][n][i];
			double V8 = 0;
			if ( C8 > 0 ) V8 = -pow(C8/33., 1./8);
			else V8 = pow(-C8/33., 1./8);
			double errV8 = fabs( err8*V8/C8/8.);
			hV8nR[n]->SetBinContent(i+1, V8);
			hV8nR[n]->SetBinError(i+1, errV8);
		}
	}

	// Write
	TFile * fwrite = 0;
	fwrite = new TFile(Form("%s/outputE.root", ftxt[s1]), "recreate");
	for ( int n = 2; n < 7; n++ ) {
		hCnR[n]->Write();
		hVnR[n]->Write();
		hC4nR[n]->Write();
		hV4nR[n]->Write();

		hC6nR[n]->Write();
		hV6nR[n]->Write();

		hC8nR[n]->Write();
		hV8nR[n]->Write();
	}
	fwrite->Close();
}
