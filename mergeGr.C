#include "label.h"
#include "noff.h"
#include "tools.h"
#include "HIN-16-022.h"


const double * NoffX;
bool bPbPb;
/*
typedef struct
{
	TGraphErrors * grCn;
	TGraphErrors * grVn;
	TGraphErrors * grC4;
	TGraphErrors * grV4;
	TGraphErrors * grC6;
	TGraphErrors * grV6;
	TGraphErrors * grC8;
	TGraphErrors * grV8;
	TGraphErrors * grV64;
	TGraphErrors * grV86;
} VnGraph;

*/
void getGraphM(TFile * f, VnGraph &gr, int n)
{
	gr.grCn = (TGraphErrors*) f->Get(Form("grCn%i", n));
	gr.grVn = (TGraphErrors*) f->Get(Form("grVn%i", n));

	gr.grC2 = (TGraphErrors*) f->Get(Form("grC2%i", n));
	gr.grV2 = (TGraphErrors*) f->Get(Form("grV2%i", n));

	gr.grC4 = (TGraphErrors*) f->Get(Form("grC4%i", n));
	gr.grV4 = (TGraphErrors*) f->Get(Form("grV4%i", n));

	gr.grC6 = (TGraphErrors*) f->Get(Form("grC6%i", n));
	gr.grV6 = (TGraphErrors*) f->Get(Form("grV6%i", n));

	gr.grC8 = (TGraphErrors*) f->Get(Form("grC8%i", n));
	gr.grV8 = (TGraphErrors*) f->Get(Form("grV8%i", n));

	gr.grV64 = (TGraphErrors*) f->Get(Form("grV64%i", n));
	gr.grV86 = (TGraphErrors*) f->Get(Form("grV86%i", n));
}

TGraphErrors* combineGr(TGraphErrors* gMB0, TGraphErrors* gHM0, TGraphErrors* gHM1, TGraphErrors* gHM7)
{
	double y[14], ey[14];
	for ( int i = 0; i < 6; i++ ) {
		y[i]  = gMB0->GetY() [i];
		ey[i] = gMB0->GetEY()[i];
	}
	for ( int i = 6; i < 8; i++ ) {
		y[i]  = gHM0->GetY() [i];
		ey[i] = gHM0->GetEY()[i];
	}
	for ( int i = 8; i < 10; i++ ) {
		y[i]  = gHM1->GetY() [i];
		ey[i] = gHM1->GetEY()[i];
	}
	for ( int i = 10; i < 14; i++ ) {
		y[i]  = gHM7->GetY() [i];
		ey[i] = gHM7->GetEY()[i];
	}
	TGraphErrors * ret = new TGraphErrors(14, NoffX, y, 0, ey);
	ret->SetMarkerSize(2);
	ret->SetMarkerStyle(gMB0->GetMarkerStyle());
	ret->SetMarkerColor(gMB0->GetMarkerColor());
	ret->SetLineColor(gMB0->GetLineColor());
	return ret;
}


TGraphErrors * gr2gr(TGraphErrors * gr1, TGraphErrors * gr2)
{
	TGraphErrors * ret = (TGraphErrors*) gr1->Clone();
	for ( int i = 0; i < gr1->GetN(); i++ ) {
		double x1 = gr1->GetX()[i];
		double y1 = gr1->GetY()[i];
		double e1 = gr1->GetEY()[i];
		double y2 = -1;
		double e2 = -1;

		for ( int j = 0; j < gr2->GetN(); j++ ) {
			if ( fabs( gr2->GetX()[j] - x1 ) < 1.) {
				y2 = gr2->GetY()[j];
				e2 = gr2->GetEY()[j];
				break;
			}
		}

		ret->GetY()[i] = y1 / y2;
		ret->GetEY()[i] = sqrt( (e1/y1)*(e1/y1) + (e2/y2)/(e2/y2) ) * ret->GetY()[i];
	}

	return ret;
}

TGraphErrors * gr2func(TGraphErrors * gr, TF1 * func)
{
	TGraphErrors * ret = (TGraphErrors*) gr->Clone();
	for ( int i = 0; i < ret->GetN(); i++ ) {
		ret->GetY()[i] = gr->GetY()[i] / func->Eval(gr->GetX()[i]);
		ret->GetEY()[i] = gr->GetEY()[i] / func->Eval(gr->GetX()[i]);
	}
	return ret;
}

TGraphErrors * grRatio(TGraphErrors * gr1, TGraphErrors * gr2, TGraphErrors * gr3, TF1 * func)
{
	//  gr1/gr2 vs gr3/func; where gr1 has fewer points
	TGraphErrors * ret = (TGraphErrors *) gr1->Clone();
	for ( int i = 0; i < gr1->GetN(); i++ ) {
		double x1 = gr1->GetX()[i];
		double y1 = gr1->GetY()[i];
		double e1 = gr1->GetEY()[i];
		double y2 = -1;
		double e2 = -1;
		double y3 = -1;
		double e3 = -1;
		for ( int j = 0; j < gr2->GetN(); j++ ) {
			if ( fabs( gr2->GetX()[j] - x1 ) < 1.) {
				y2 = gr2->GetY()[j];
				e2 = gr2->GetEY()[j];
				break;
			}
		}

		for ( int j = 0; j < gr3->GetN(); j++ ) {
			if ( fabs( gr3->GetX()[j] - x1 ) < 1.) {
				y3 = gr3->GetY()[j];
				e3 = gr3->GetEY()[j];
				break;
			}
		}

		ret->GetX()[i] = y3 / func->Eval(x1);
		ret->GetEX()[i] = e3 / func->Eval(x1);

		ret->GetY()[i] = y1 / y2;
		ret->GetEY()[i] = sqrt((e1/y1)*(e1/y1) + (e2/y2)*(e2/y2)) * ret->GetY()[i];
	}
	return ret;
}

void mergeGr(int n = 2, int sMB = 9, int sHM0 = 1, int sHM1 = 2, int sHM7 = 8)
{
	TFile * fMB0 = new TFile(Form("%s/outGraph.root", ftxt[sMB]));
	TFile * fHM0 = new TFile(Form("%s/outGraph.root", ftxt[sHM0]));
	TFile * fHM1 = new TFile(Form("%s/outGraph.root", ftxt[sHM1]));
	TFile * fHM7 = new TFile(Form("%s/outGraph.root", ftxt[sHM7]));

	if ( sMB == sHM0 ) {
		NoffX = CentPbPbX4data;
		bPbPb = true;
	} else {
		NoffX = CentpPbX4data;
		bPbPb = false;
	}

	HIN_16_022();

	VnGraph grMB0;
	VnGraph grHM0;
	VnGraph grHM1;
	VnGraph grHM7;

	getGraphM(fMB0, grMB0, n);
	getGraphM(fHM0, grHM0, n);
	getGraphM(fHM1, grHM1, n);
	getGraphM(fHM7, grHM7, n);

	TGraphErrors * grCn = combineGr(grMB0.grCn, grHM0.grCn, grHM1.grCn, grHM7.grCn);
	TGraphErrors * grVn = combineGr(grMB0.grVn, grHM0.grVn, grHM1.grVn, grHM7.grVn);

	TGraphErrors * grC2 = combineGr(grMB0.grC2, grHM0.grC2, grHM1.grC2, grHM7.grC2);
	TGraphErrors * grV2 = combineGr(grMB0.grV2, grHM0.grV2, grHM1.grV2, grHM7.grV2);

	TGraphErrors * grC4 = combineGr(grMB0.grC4, grHM0.grC4, grHM1.grC4, grHM7.grC4);
	TGraphErrors * grV4 = combineGr(grMB0.grV4, grHM0.grV4, grHM1.grV4, grHM7.grV4);


	TGraphErrors * grC6 = combineGr(grMB0.grC6, grHM0.grC6, grHM1.grC6, grHM7.grC6);
	TGraphErrors * grV6 = combineGr(grMB0.grV6, grHM0.grV6, grHM1.grV6, grHM7.grV6);
	TGraphErrors * grV64= combineGr(grMB0.grV64,grHM0.grV64,grHM1.grV64,grHM7.grV64);

	TGraphErrors * grC8 = combineGr(grMB0.grC8, grHM0.grC8, grHM1.grC8, grHM7.grC8);
	TGraphErrors * grV8 = combineGr(grMB0.grV8, grHM0.grV8, grHM1.grV8, grHM7.grV8);
	TGraphErrors * grV86= combineGr(grMB0.grV86,grHM0.grV86,grHM1.grV86,grHM7.grV86);

	TGraphErrors * grV4V2 = nullptr;
	TGraphErrors * grV4V2sub = nullptr;
	TGraphErrors * grV64V42 = nullptr;
	TGraphErrors * grV86V42 = nullptr;

	TGraphErrors * grV6V4 = gr2gr(grV6, grV4);
	TGraphErrors * grV8V6 = gr2gr(grV8, grV6);

	if ( bPbPb ) {
		if ( n == 2 ) {
			trimC24AA(grC2);
			trimV24AA(grV2);
			trimC24AA(grC4);
			trimV24AA(grV4);
			trimC26AA(grC6);
			trimV26AA(grV6);
			trimV26AA(grV64);
			trimC28AA(grC8);
			trimV28AA(grV8);
			trimV28AA(grV86);
			grV4V2 = gr2func(grV4, fHIN16022PbPbV2);
			grV4V2sub = gr2func(grV4, fHIN16022PbPbV2sub);
			grV64V42 = grRatio(grV6, grV4, grV4, fHIN16022PbPbV2sub);
			grV86V42 = grRatio(grV8, grV6, grV4, fHIN16022PbPbV2sub);
		} else if ( n == 3 ) {
			trimC34AA(grC2);
			trimV34AA(grV2);
			trimC34AA(grC4);
			trimV34AA(grV4);
			grV4V2 = gr2func(grV4, fHIN16022PbPbV3);
			grV4V2sub = gr2func(grV4, fHIN16022PbPbV3sub);
			grV64V42 = grRatio(grV6, grV4, grV4, fHIN16022PbPbV3sub);
			grV86V42 = grRatio(grV8, grV6, grV4, fHIN16022PbPbV3sub);
		}
	} else {
		if ( n == 2 ) {
			trimC24PA(grC2);
			trimV24PA(grV2);
			trimC24PA(grC4);
			trimV24PA(grV4);
			trimC26PA(grC6);
			trimV26PA(grV6);
			trimV26PA(grV64);
			trimC28PA(grC8);
			trimV28PA(grV8);
			trimV28PA(grV86);
			grV4V2 = gr2func(grV4, fHIN16022pPbV2);
			grV4V2sub = gr2func(grV4, fHIN16022pPbV2sub);
			grV64V42 = grRatio(grV6, grV4, grV4, fHIN16022pPbV2sub);
			grV86V42 = grRatio(grV8, grV6, grV4, fHIN16022pPbV2sub);
		} else if ( n == 3 ) {
			trimC34PA(grC2);
			trimV34PA(grV2);
			trimC34PA(grC4);
			trimV34PA(grV4);
			grV4V2 = gr2func(grV4, fHIN16022pPbV3);
			grV4V2sub = gr2func(grV4, fHIN16022pPbV3sub);
			grV64V42 = grRatio(grV6, grV4, grV4, fHIN16022pPbV3sub);
			grV86V42 = grRatio(grV8, grV6, grV4, fHIN16022pPbV3sub);
		}
	}

	TFile * fsave = new TFile(Form("combined_%i_%i_%i_%i_%i.root", sMB, sHM0, sHM1, sHM7, n), "recreate");
	grCn->Write(Form("grC%in", n));
	grVn->Write(Form("grV%in", n));
	grC2->Write(Form("grC%i2", n));
	grV2->Write(Form("grV%i2", n));
	grC4->Write(Form("grC%i4", n));
	grV4->Write(Form("grV%i4", n));
	grC6->Write(Form("grC%i6", n));
	grV6->Write(Form("grV%i6", n));
	grC8->Write(Form("grC%i8", n));
	grV8->Write(Form("grV%i8", n));
	grV64->Write(Form("grV%i64", n));
	grV86->Write(Form("grV%i86", n));
	if ( n != 4 ) {
		grV4V2->Write(Form("grV4V2%i", n));
		grV4V2sub->Write(Form("grV4V2sub%i", n));
		grV64V42->Write(Form("grV64V42%i", n));
		grV86V42->Write(Form("grV86V42%i", n));
	}
	grV8V6->Write(Form("grV8V6%i", n));
	grV6V4->Write(Form("grV6V4%i", n));
}
