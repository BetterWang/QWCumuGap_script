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
	if ( s1 == 31 ) {
		NCent = NCentPP13TeV;
		pCent = CentNoffCutPP13TeV;
	} else if ( s1 == 99 ) {
		NCent = NCentAA5TeV4;
		pCent = CentNoffCutAA8TeV4;
	}

	TFile * f = new TFile(Form("%s/output_%i_%i.root", ftxt[s1], s2, s3));

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

	TH1D * hCn[7]		= {};
	TH1D * hC4n[7]		= {};
	TH1D * hC6n[7]		= {};
	TH1D * hC8n[7]		= {};




	double dCn[7][600] = {};
	double dC4n[7][600] = {};
	double dC6n[7][600] = {};
	double dC8n[7][600] = {};

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

	TH1D * hNoff = (TH1D*) f->Get("hNoff");

	for ( int n = 2; n < 7; n++ ) {
		hQaabc[n] = (TH1D*) f->Get(Form("hQaabc%i", n));
		hQab[n] =   (TH1D*) f->Get(Form("hQab%i", n));
		hQac[n] =   (TH1D*) f->Get(Form("hQac%i", n));

		hWQaabc[n] = (TH1D*) f->Get(Form("hWQaabc%i", n));
		hWQab[n] =   (TH1D*) f->Get(Form("hWQab%i", n));
		hWQac[n] =   (TH1D*) f->Get(Form("hWQac%i", n));

		hQ2[n] = (TH1D*) f->Get(Form("hQ2%i", n));
		hQ4[n] = (TH1D*) f->Get(Form("hQ4%i", n));
		hQ6[n] = (TH1D*) f->Get(Form("hQ6%i", n));
		hQ8[n] = (TH1D*) f->Get(Form("hQ8%i", n));

		hWQ2[n] = (TH1D*) f->Get(Form("hWQ2%i", n));
		hWQ4[n] = (TH1D*) f->Get(Form("hWQ4%i", n));
		hWQ6[n] = (TH1D*) f->Get(Form("hWQ6%i", n));
		hWQ8[n] = (TH1D*) f->Get(Form("hWQ8%i", n));

		hCn[n] = new TH1D(Form("hCn%i", n), Form("hCn%i", n), 600, -0.5, 599.5);
		hC4n[n] = new TH1D(Form("hC4n%i", n), Form("hC4n%i", n), 600, -0.5, 599.5);
		hC6n[n] = new TH1D(Form("hC6n%i", n), Form("hC6n%i", n), 600, -0.5, 599.5);
		hC8n[n] = new TH1D(Form("hC8n%i", n), Form("hC8n%i", n), 600, -0.5, 599.5);

		for ( int c = 0; c < 600; c++ ) {
			dQaabc[n][c] = hQaabc[n]->GetBinContent(c+1);
			dQab[n][c]   = hQab[n]->GetBinContent(c+1);
			dQac[n][c]   = hQac[n]->GetBinContent(c+1);

			yQaabc[n][c] = hWQaabc[n]->GetBinContent(c+1);
			yQab[n][c]   = hWQab[n]->GetBinContent(c+1);
			yQac[n][c]   = hWQac[n]->GetBinContent(c+1);

			dQ2[n][c] = hQ2[n]->GetBinContent(c+1);
			dQ4[n][c] = hQ4[n]->GetBinContent(c+1);
			dQ6[n][c] = hQ6[n]->GetBinContent(c+1);
			dQ8[n][c] = hQ8[n]->GetBinContent(c+1);

			yQ2[n][c] = hWQ2[n]->GetBinContent(c+1);
			yQ4[n][c] = hWQ4[n]->GetBinContent(c+1);
			yQ6[n][c] = hWQ6[n]->GetBinContent(c+1);
			yQ8[n][c] = hWQ8[n]->GetBinContent(c+1);

			if ( yQaabc[n][c] > 0. ) dQaabc[n][c] /= yQaabc[n][c];
			if ( yQac[n][c] > 0. ) dQac[n][c] /= yQac[n][c];
			if ( yQab[n][c] > 0. ) dQab[n][c] /= yQab[n][c];
			if ( yQ2[n][c] > 0. ) dQ2[n][c] /= yQ2[n][c];
			if ( yQ4[n][c] > 0. ) dQ4[n][c] /= yQ4[n][c];
			if ( yQ6[n][c] > 0. ) dQ6[n][c] /= yQ6[n][c];
			if ( yQ8[n][c] > 0. ) dQ8[n][c] /= yQ8[n][c];
		}
	}

	for ( int n = 2; n < 7; n++ ) {
		for ( int c = 0; c < 600; c++ ) {
			dCn[n][c] = dQaabc[n][c] - 2*dQab[n][c]*dQac[n][c];
			hCn[n]->SetBinContent(c+1, dCn[n][c]);

			dC4n[n][c] = dQ4[n][c] - 2*dQ2[n][c]*dQ2[n][c];
			hC4n[n]->SetBinContent(c+1, dC4n[n][c]);

			dC6n[n][c] = dQ6[n][c] - 9*dQ2[n][c]*dQ4[n][c] + 12*dQ2[n][c]*dQ2[n][c]*dQ2[n][c];
			hC6n[n]->SetBinContent(c+1, dC6n[n][c]);

			dC8n[n][c] = dQ8[n][c] - 16*dQ2[n][c]*dQ6[n][c] - 18*dQ4[n][c]*dQ4[n][c] + 144*dQ4[n][c]*dQ2[n][c]*dQ2[n][c] - 144*dQ2[n][c]*dQ2[n][c]*dQ2[n][c]*dQ2[n][c];
			hC8n[n]->SetBinContent(c+1, dC8n[n][c]);
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
