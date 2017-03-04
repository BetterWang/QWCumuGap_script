#include "label.h"
#include "noff.h"

#include <TFile.h>
#include <TH1.h>
using namespace std;
void bGet(int s1 = 0, int s2 = 10, int s3 = 10)
{
	cout << " s1 = " << s1 << " s2 = " << s2 << " s3 = " << s3 << endl;
	TH1::SetDefaultSumw2();
	int NCent = NCent8TeV4;
	const int * pCent = CentNoffCutPA8TeV4;

	TFile * f = new TFile(Form("%s/output_%i_%i.root", ftxt[s1], s2, s3));

	TH1D * hWQaabc[7]	= {};
	TH1D * hCn[7]		= {};

	TH1D * hC4n[7]		= {};
	TH1D * hC6n[7]		= {};
	TH1D * hC8n[7]		= {};

	TH1D * hWQ4[7]		= {};
	TH1D * hWQ6[7]		= {};
	TH1D * hWQ8[7]		= {};

	double dCn[7][600] = {};
	double yQaabc[7][600] = {};

	double dC4n[7][600] = {};
	double dC6n[7][600] = {};
	double dC8n[7][600] = {};

	double yQ4[7][600] = {};
	double yQ6[7][600] = {};
	double yQ8[7][600] = {};

	TH1D * hNoff = (TH1D*) f->Get("hNoff");

	for ( int n = 2; n < 7; n++ ) {
		hWQaabc[n] = (TH1D*) f->Get(Form("hWQaabc%i", n));
		hCn[n] = (TH1D*) f->Get(Form("hCn%i", n));

		hC4n[n] = (TH1D*) f->Get(Form("hC4n%i", n));
		hC6n[n] = (TH1D*) f->Get(Form("hC6n%i", n));
		hC8n[n] = (TH1D*) f->Get(Form("hC8n%i", n));

		hWQ4[n] = (TH1D*) f->Get(Form("hWQ4%i", n));
		hWQ6[n] = (TH1D*) f->Get(Form("hWQ6%i", n));
		hWQ8[n] = (TH1D*) f->Get(Form("hWQ8%i", n));
		for ( int c = 0; c < 600; c++ ) {
			dCn[n][c] = hCn[n]->GetBinContent(c+1);
			yQaabc[n][c] = hWQaabc[n]->GetBinContent(c+1);

			dC4n[n][c] = hC4n[n]->GetBinContent(c+1);
			dC6n[n][c] = hC6n[n]->GetBinContent(c+1);
			dC8n[n][c] = hC8n[n]->GetBinContent(c+1);

			yQ4[n][c] = hWQ4[n]->GetBinContent(c+1);
			yQ6[n][c] = hWQ6[n]->GetBinContent(c+1);
			yQ8[n][c] = hWQ8[n]->GetBinContent(c+1);
		}
	}

	//rebin
	double dCnR[7][20] = {};
	double dC4nR[7][20] = {};
	double dC6nR[7][20] = {};
	double dC8nR[7][20] = {};
	for ( int n = 2; n < 7; n++ ) {
		for ( int c = 0; c <  NCent; c++ ) {
			double sum = 0;
			double weight = 0;

			double sum4 = 0;
			double weight4 = 0;

			double sum6 = 0;
			double weight6 = 0;

			double sum8 = 0;
			double weight8 = 0;
			for ( int m = pCent[c]; m < pCent[c+1]; m++ ) {
				if ( m > 600 ) continue;
				sum += dCn[n][m] * yQaabc[n][m];
				weight += yQaabc[n][m];

				sum4 += dC4n[n][m] * yQ4[n][m];
				weight4 += yQ4[n][m];

				sum6 += dC6n[n][m] * yQ6[n][m];
				weight6 += yQ6[n][m];

				sum8 += dC8n[n][m] * yQ8[n][m];
				weight8 += yQ8[n][m];
			}
			if ( weight > 0 ) sum /= weight;
			else sum = 0;
			if ( weight4 > 0 ) sum4 /= weight4;
			else sum4 = 0;
			if ( weight6 > 0 ) sum6 /= weight6;
			else sum6 = 0;
			if ( weight8 > 0 ) sum8 /= weight8;
			else sum8 = 0;

			dCnR[n][c] = sum;
			dC4nR[n][c] = sum4;
			dC6nR[n][c] = sum6;
			dC8nR[n][c] = sum8;
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
	TH1D * hC4nR[7];
	TH1D * hC6nR[7];
	TH1D * hC8nR[7];
	for ( int n = 2; n < 7; n++ ) {
		hCnR[n] = new TH1D(Form("hCnR%i", n), Form("hCnR%i", n), 20, 0, 20);
		hC4nR[n] = new TH1D(Form("hC4nR%i", n), Form("hC4nR%i", n), 20, 0, 20);
		hC6nR[n] = new TH1D(Form("hC6nR%i", n), Form("hC6nR%i", n), 20, 0, 20);
		hC8nR[n] = new TH1D(Form("hC8nR%i", n), Form("hC8nR%i", n), 20, 0, 20);
		for ( int c = 0; c < NCent; c++ ) {
			hCnR[n]->SetBinContent( c+1, dCnR[n][c] );
			hC4nR[n]->SetBinContent( c+1, dC4nR[n][c] );
			hC6nR[n]->SetBinContent( c+1, dC6nR[n][c] );
			hC8nR[n]->SetBinContent( c+1, dC8nR[n][c] );
		}
	}

	TFile * fwrite = new TFile(Form("%s/outputC_%i_%i.root", ftxt[s1], s2, s3), "recreate");
	for ( int n = 2; n < 7; n++ ) {
		hCnR[n]->Write();
		hC4nR[n]->Write();
		hC6nR[n]->Write();
		hC8nR[n]->Write();
	}
	hNoffR->Write();
}
